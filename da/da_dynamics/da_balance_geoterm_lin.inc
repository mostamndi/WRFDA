subroutine da_balance_geoterm_lin( cori, rho, u, v, term_x, term_y)

   !---------------------------------------------------------------------------
   !  Purpose: calculates linearised geostrophic term in balance equation.
   !
   !  method:  term is k x rho f u on a single level.
   !
   !  assumptions: Various (see documentation).
   !---------------------------------------------------------------------------

   implicit none
   
   real, dimension(ims:ime,jms:jme), intent(in)  :: cori, &  ! Coriolis factor.
                                                    rho, &   ! Density
                                                    u, &     ! u wind increment
                                                    v        ! v wind increment

   real, dimension(ims:ime,jms:jme), intent(inout) :: &
      term_x, & ! x component of term.
      term_y    ! y component of term.

   integer              :: is, js              ! i,j lower loop limits
   integer              :: ie, je              ! i,j upper loop limits

   ! Set loop limits

   is = its-1
   ie = ite+1
   js = jts-1
   je = jte+1
   if (its == ids ) is = ids
   if (ite == ide ) ie = ide
   if (jts == jds ) js = jds
   if (jte == jde ) je = jde

   !---------------------------------------------------------------------------
   ! [1.0] Calculate term_x = -f rho v~:
   !---------------------------------------------------------------------------

   term_x(is:ie,js:je) = term_x(is:ie,js:je) - &
                         rho(is:ie,js:je) * cori(is:ie,js:je) * v(is:ie,js:je)

   !---------------------------------------------------------------------------
   ! [2.0] Calculate term_y = f rho u~:
   !---------------------------------------------------------------------------

   term_y(is:ie,js:je) = term_y(is:ie,js:je) + &
                         rho(is:ie,js:je) * cori(is:ie,js:je) * u(is:ie,js:je)

end subroutine da_balance_geoterm_lin

