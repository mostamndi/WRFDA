subroutine da_uvprho_to_w_lin(xb, xa, xp)

   !------------------------------------------------------------------------------
   !  Purpose: Calculates vertical velocity increments from Richardson's Eq.
   !
   !  Method: Richardson's Eq., which
   !          combines continuity Eq., thermodynamic Eq. and hrdrostatic Eq.
   !------------------------------------------------------------------------------

   implicit none

   type (xb_type), intent(in)       :: xb        ! First guess structure.
   type (x_type), intent(inout)     :: xa        ! increment structure.
   type (xpose_type), intent(inout) :: xp        ! domain decomposition vars.

   integer                       :: is, ie       ! 1st dim. end points.
   integer                       :: js, je       ! 2nd dim. end points.

   integer                       :: I,J,K

   real, dimension(ims:ime,jms:jme,kms:kme) :: URHO, VRHO
   real, dimension(ims:ime,jms:jme,kms:kme) :: DIV, WZ
   real                                     :: TERM3

   
   ! Computation to check for edge of domain:
   is = its
   ie = ite
   js = jts
   je = jte
   if (its == ids) is = ids+1
   if (ite == ide) ie = ide-1
   if (jts == jds) js = jds+1
   if (jte == jde) je = jde-1

   WZ(:,:,:) = 0.0
   ! Term 1.1: perturbed pressure advection along the basic wind
   do K=kts,kte
      do J=js,je
         do I=is,ie
            WZ(I,J,K)=WZ(I,J,K)-xb%u(I,J,K)*(xa%p(I+1,J,K)-xa%p(I-1,J,K))* &
               xb%coefx(I,J)
            WZ(I,J,K)=WZ(I,J,K)-xb%v(I,J,K)*(xa%p(I,J+1,K)-xa%p(I,J-1,K))* &
               xb%coefy(I,J)
         end do
      end do
   end do

   ! Term 1.2: Basic pressure advection along the perturbed wind

   do K=kts,kte
      do J=js,je
         do I=is,ie
            WZ(I,J,K)=WZ(I,J,K)-xa%u(I,J,K)*(xb%p(I+1,J,K)-xb%p(I-1,J,K))* &
               xb%coefx(I,J)
            WZ(I,J,K)=WZ(I,J,K)-xa%v(I,J,K)*(xb%p(I,J+1,K)-xb%p(I,J-1,K))* &
               xb%coefy(I,J)
         end do
      end do
   end do

   ! Dealing the laterial boundary because of the advection.
   ! boundary too simple? (It is the same as fill in interpf, fill can be used)

   if (its == ids) then
      i = its
      do K=kts,kte
         do J=js,je
            WZ(I,J,K)=WZ(I+1,J,K)
         end do
      end do
   end if

   if (ite == ide) then
      i = ite
      do K=kts,kte
         do J=js,je
            WZ(I,J,K)=WZ(I-1,J,K)
         end do
      end do
   end if

   if (jts == jds) then
      j = jts
      do K=kts,kte
         do I=its, ite
            WZ(I,J,K)=WZ(I,J+1,K)       
         end do
      end do
   end if

   if (jte == jde) then
      j = jte
      do K=kts,kte
         do I=its, ite
            WZ(I,J,K)=WZ(I,J-1,K)
         end do
      end do
   end if

   ! Term 2.1: Divergence term from perturbed wind

   call da_uv_to_divergence(xb, xa%u, xa%v, DIV)

   do K=kts,kte  
      do J=jts,jte
         do I=its,ite
            WZ(I,J,K)=WZ(I,J,K)-GAMMA*xb%p(I,J,K)*DIV(I,J,K)
         end do
      end do
   end do

   ! Term 2.2: Divergence term from basic wind

   call da_uv_to_divergence(xb, xb%u, xb%v, DIV)

   do K=kts,kte
      do J=jts,jte
         do I=its,ite
            WZ(I,J,K)=WZ(I,J,K)-GAMMA*xa%p(I,J,K)*DIV(I,J,K)
      end do
   end do
   end do

   ! Computation to check for edge of domain:
   is = its-1; ie = ite+1; js = jts-1; je = jte+1
   if (its == ids) is = ids; if (ite == ide) ie = ide
   if (jts == jds) js = jds; if (jte == jde) je = jde

   ! Term 3.1: Vertical integration of the perturbed mass divergence

   do K=kts,kte
      do J=js,je
         do I=is,ie
            URHO(I,J,K)=xb%rho(I,J,K)*xa%u(I,J,K)
            VRHO(I,J,K)=xb%rho(I,J,K)*xa%v(I,J,K)
         end do
      end do
   end do

   call da_uv_to_divergence(xb, URHO, VRHO, DIV)

   do J=jts,jte
      do I=its,ite
         TERM3=0.0

         do K=kte-1,kts,-1
            TERM3=TERM3+GRAVITY*(DIV(I,J,K+1)+DIV(I,J,K))*0.5  &
                *(xb%h(I,J,K+1)-xb%h(I,J,K))
            WZ(I,J,K)=WZ(I,J,K)+TERM3
         end do
      end do
   end do

   ! Term 3.2: Vertical integration of the basic mass divergence

   do K=kts,kte
      do J=js,je
         do I=is,ie
            URHO(I,J,K)=xa%rho(I,J,K)*xb%u(I,J,K)
            VRHO(I,J,K)=xa%rho(I,J,K)*xb%v(I,J,K)
         end do
      end do
   end do

   call da_uv_to_divergence(xb, URHO, VRHO, DIV)

   do J=jts,jte
      do I=its,ite
         TERM3=0.0

         do K=kte-1,kts,-1
            TERM3=TERM3+GRAVITY*(DIV(I,J,K+1)+DIV(I,J,K))*0.5  &
               *(xb%h(I,J,K+1)-xb%h(I,J,K))
            WZ(I,J,K)=WZ(I,J,K)+TERM3
         end do
      end do
   end do

   ! Term 4: Derivative of basic vertical velocity with respect to z.

   do J=jts,jte
      do I=its,ite
         do K=kts,kte
            WZ(I,J,K)=WZ(I,J,K)-GAMMA*xa%p(I,J,K)*(xb%w(I,J,K+1)-xb%w(I,J,K))/  &
                      (xb%hf(I,J,K+1)-xb%hf(I,J,K))
         end do
      end do
   end do

   ! Divided by constant

   do K=kts,kte
      do J=jts,jte
         do I=its,ite
            WZ(I,J,K)=WZ(I,J,K)/(GAMMA*xb%p(I,J,K))
         end do
      end do
   end do

   ! integration to calculate the vertical velocity 

   call da_w_adjustment_lin(xb,xa%w,WZ)

   do J=jts,jte
      do I=its,ite
         xa%w(I,J,kte+1)=0.0
         do K=kte,kts,-1
            xa%w(I,J,K)=xa%w(I,J,K+1)+   &
                     WZ(I,J,K)*(xb%hf(I,J,K)-xb%hf(I,J,K+1))
         end do
      end do
   end do

end subroutine da_uvprho_to_w_lin

