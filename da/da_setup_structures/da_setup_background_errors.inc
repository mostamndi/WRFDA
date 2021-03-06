subroutine da_setup_background_errors(xb, be)

   !---------------------------------------------------------------------------
   ! Purpose: Define and allocate components of background errors.
   !          Wrapper subroutine.
   !---------------------------------------------------------------------------

   implicit none

   type (xb_type), intent(in)  :: xb       ! First guess structure.
   type (be_type), intent(out) :: be       ! Back. errors structure.

   if (trace_use) call da_trace_entry("da_setup_background_errors")

   be % ne = ensdim_alpha                          ! Size of ensemble.

   be % v1 % mz = 0
   be % v2 % mz = 0
   be % v3 % mz = 0
   be % v4 % mz = 0
   be % v5 % mz = 0

   if (global) then
      call da_setup_be_global (be)
   else
      call da_setup_be_regional (xb, be)
   end if

   call da_setup_cv (be)

   if (trace_use) call da_trace_exit("da_setup_background_errors")

end subroutine da_setup_background_errors


