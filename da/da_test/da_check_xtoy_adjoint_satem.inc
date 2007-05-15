subroutine da_check_xtoy_adjoint_satem(oi, y, adjtest_lhs, pertile_lhs)

   !-----------------------------------------------------------------------
   ! Purpose: TBD
   !-----------------------------------------------------------------------

   implicit none

   type (ob_type), intent(in)     :: oi            ! obs. inc. vector (o-b).
   type (y_type) , intent(inout)  :: y             ! y = h (xa)
   real          , intent(inout)  :: adjtest_lhs, pertile_lhs   

   integer                        :: n, k          ! Loop counter.

   if (oi%num_Satem > 0) then
      do n=1, oi%num_Satem
         if (oi%satem(n)%loc%proc_domain) then
            do k=1, oi%satem(n)%info%levels
               adjtest_lhs = adjtest_lhs + &
                  (y%Satem(n)%thickness(k)/typical_thickness_rms)**2
            end do
         end if

         do k=1, oi%satem(n)%info%levels
            pertile_lhs = pertile_lhs + &
                        (y%Satem(n)%thickness(k)/typical_thickness_rms)**2

            y%satem(n)%thickness(k) = y%satem(n)%thickness(k) /      &
                                      typical_thickness_rms ** 2

         end do
      end do
   end if

end subroutine da_check_xtoy_adjoint_satem

