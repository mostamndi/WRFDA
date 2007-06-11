subroutine da_filter_adj(grid, var, xp)

   !-----------------------------------------------------------------------
   ! Purpose: TBD
   !-----------------------------------------------------------------------

   implicit none

   type(domain), intent(inout)               :: grid
   
   type (xpose_type), intent(inout) :: xp      ! Transpose variables.

   real, dimension(xp%ims:xp%ime,xp%jms:xp%jme,xp%kms:xp%kme), &
                      intent(inout) :: var

   integer :: i, j, k

   real, dimension (3) :: w

   data  w/0.25,0.5,0.25/

   ! Copy var for transpose.

   xp%v1z(xp%its:xp%ite,xp%jts:xp%jte,xp%kts:xp%kte) = &
      var(xp%its:xp%ite,xp%jts:xp%jte,xp%kts:xp%kte)


   ! Apply (i',j',k -> i',j,k') transpose (v1z -> v1y).

   call da_transpose_z2y (grid)


   ! Perform y-direction filter:

   do k=xp%ktsy, xp%ktey
      do i=xp%itey, xp%itsy, -1
         ! Backward
         do j=xp%jds+1, xp%jde-1
            xp%v1y(i,j-1,k) = xp%v1y(i,j-1,k) + w(1)*xp%v1y(i,j,k)
            xp%v1y(i,j+1,k) = xp%v1y(i,j+1,k) + w(3)*xp%v1y(i,j,k)
            xp%v1y(i,j  ,k) = w(2)*xp%v1y(i,j,k)
         end do

         ! Forward
         do j=xp%jde-1,xp%jds+1,-1
            xp%v1y(i,j-1,k) = xp%v1y(i,j-1,k) + w(1)*xp%v1y(i,j,k)
            xp%v1y(i,j+1,k) = xp%v1y(i,j+1,k) + w(3)*xp%v1y(i,j,k)
            xp%v1y(i,j  ,k) = w(2)*xp%v1y(i,j,k)
         end do
      end do
   end do

   ! Apply (i',j,k' -> i,j',k') transpose (v1y -> v1x).

   call da_transpose_y2x (grid)

   ! Perform x-direction filter:

   do k=xp%ktsx, xp%ktex
      do j=xp%jtex, xp%jtsx, -1
         ! Backward
         do i=xp%ids+1, xp%ide-1
            xp%v1x(i-1,j,k) = xp%v1x(i-1,j,k) + w(1)*xp%v1x(i,j,k)
            xp%v1x(i+1,j,k) = xp%v1x(i+1,j,k) + w(3)*xp%v1x(i,j,k)
            xp%v1x(i,j  ,k) = w(2)*xp%v1x(i,j,k)
         end do

         ! Forward 
         do i=xp%ide-1,xp%ids+1,-1
            xp%v1x(i-1,j,k) = xp%v1x(i-1,j,k) + w(1)*xp%v1x(i,j,k)
            xp%v1x(i+1,j,k) = xp%v1x(i+1,j,k) + w(3)*xp%v1x(i,j,k)
            xp%v1x(i,j  ,k) = w(2)*xp%v1x(i,j,k)
         end do
      end do
   end do

   ! Apply (i,j',k' -> i',j',k) transpose (v1x -> v1z).

   call da_transpose_x2z (grid)

   var(xp%its:xp%ite,xp%jts:xp%jte,xp%kts:xp%kte) = &
      xp%v1z(xp%its:xp%ite,xp%jts:xp%jte,xp%kts:xp%kte)

end subroutine da_filter_adj

