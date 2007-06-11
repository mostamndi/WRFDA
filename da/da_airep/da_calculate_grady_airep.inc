subroutine da_calculate_grady_airep(iv, re, jo_grad_y)

   !-------------------------------------------------------------------------
   ! Purpose: Applies obs inverse on re-vector
   !-------------------------------------------------------------------------

   implicit none


   type (ob_type), intent(in)     :: iv          ! Innovation vector.
   type (y_type),  intent(inout)  :: re          ! Residual vector.
   type (y_type),  intent(inout)  :: jo_grad_y   ! Grad_y(Jo)

   integer                      :: n, k

   if (iv%num_airep > 0) then
      do n=1, iv%num_airep
         do k=1, iv%airep(n)%info%levels
            if (iv%airep(n)%u(k)%qc < obs_qc_pointer) re%airep(n)%u(k) = 0.0
            if (iv%airep(n)%v(k)%qc < obs_qc_pointer) re%airep(n)%v(k) = 0.0
            if (iv%airep(n)%t(k)%qc < obs_qc_pointer) re%airep(n)%t(k) = 0.0

            jo_grad_y%airep(n)%u(k) = -re%airep(n)%u(k) / &
                                   (iv%airep(n)%u(k)%error * &
                                     iv%airep(n)%u(k)%error)
            jo_grad_y%airep(n)%v(k) = -re%airep(n)%v(k) / &
                                   (iv%airep(n)%v(k)%error * &
                                     iv%airep(n)%v(k)%error)
            jo_grad_y%airep(n)%t(k) = -re%airep(n)%t(k) / &
                                   (iv%airep(n)%t(k)%error * &
                                     iv%airep(n)%t(k)%error)
         end do
      end do
   end if

end subroutine da_calculate_grady_airep

