subroutine da_check_max_iv_ssmi_tb(it, ssmi_tb, &
                                   itb19v, itb19vf, itb19h, itb19hf, &
                                   itb22v, itb22vf,                  &
                                   itb37v, itb37vf, itb37h, itb37hf, &
                                   itb85v, itb85vf, itb85h, itb85hf)

   !-----------------------------------------------------------------------
   ! Purpose: TBD
   !-----------------------------------------------------------------------

   implicit none

   integer,             intent(in)        :: it
   type (ssmi_tb_type), intent(inout)     :: ssmi_tb

   integer,    intent (inout)             :: itb19h, itb19v, itb22v
   integer,    intent (inout)             :: itb37h, itb37v, itb85h, itb85v
   integer,    intent (inout)             :: itb19hf, itb19vf, itb22vf 
   integer,    intent (inout)             :: itb37hf, itb37vf, itb85hf, itb85vf

   logical                                :: failed

   !-----------------------------------------------------------------------------!
   ! [1.0] Open diagnostic file:
   !-----------------------------------------------------------------------------!

   if (rootproc .and. check_max_iv_print) then
      write (check_max_iv_unit,'(A)')  &
         '----------------------------------------------------------------'
      write (unit = check_max_iv_unit, fmt = '(A,/)') 'MAX ERROR TEST QC:'
      write (unit = check_max_iv_unit, fmt = '(/,9(A,F3.0,/))')  &
         'Error max test ratio for SSMI_tb_TB19h = ',max_error_tb, &
         'Error max test ratio for SSMI_tb_TB19v = ',max_error_tb, &
         'Error max test ratio for SSMI_tb_TB22v = ',max_error_tb, &
         'Error max test ratio for SSMI_tb_TB37h = ',max_error_tb, &
         'Error max test ratio for SSMI_tb_TB37v = ',max_error_tb, &
         'Error max test ratio for SSMI_tb_TB85h = ',max_error_tb, &
         'Error max test ratio for SSMI_tb_TB85v = ',max_error_tb
   end if

   !  itb19h  = 0; itb19v  = 0; itb22v  = 0; 
   !  itb37h  = 0; itb37v  = 0; itb85h  = 0; itb85v  = 0
   !  itb19hf = 0; itb19vf = 0; itb22vf = 0;
   !  itb37hf = 0; itb37vf = 0; itb85hf = 0; itb85vf = 0

   !---------------------------------------------------------------------------
   ! [2.0] Perform maximum innovation vector check:
   !---------------------------------------------------------------------------

   ! failed=.false. is defined inside the da_max_error_qc 
   ! failed = .false.

   ! Tb19h

   call da_max_error_qc(it, ssmi_tb % info, ssmi_tb % tb19h,                  &
                            max_error_tb, itb19h, itb19hf, check_max_iv_unit, 'TB19h', &
                            failed, check_max_iv_print)

   ! Tb19v

   call da_max_error_qc(it, ssmi_tb % info, ssmi_tb % tb19v,                  &
                            max_error_tb, itb19v, itb19vf, check_max_iv_unit, 'TB19v', &
                            failed, check_max_iv_print)

   ! Tb22v

   call da_max_error_qc(it, ssmi_tb % info, ssmi_tb % tb22v,                  &
                            max_error_tb, itb22v, itb22vf, check_max_iv_unit, 'TB22v', &
                            failed, check_max_iv_print)

   ! Tb37h

   call da_max_error_qc(it, ssmi_tb % info, ssmi_tb % tb37h,                  &
                            max_error_tb, itb37h, itb37hf, check_max_iv_unit, 'TB37h', &
                            failed, check_max_iv_print)

   ! Tb37v

   call da_max_error_qc(it, ssmi_tb % info, ssmi_tb % tb37v,                  &
                            max_error_tb, itb37v, itb37vf, check_max_iv_unit, 'TB37v', &
                            failed, check_max_iv_print)

   ! Tb85h

   call da_max_error_qc(it, ssmi_tb % info, ssmi_tb % tb85h,                  &
                            max_error_tb, itb85h, itb85hf, check_max_iv_unit, 'TB85h', &
                            failed, check_max_iv_print)

   ! Tb85v

   call da_max_error_qc(it, ssmi_tb % info, ssmi_tb % tb85v,                  &
                            max_error_tb, itb85v, itb85vf, check_max_iv_unit, 'TB85v', &
                            failed, check_max_iv_print)



   !---------------------------------------------------------------------------
   ! [3.0] Output test failed results:
   !---------------------------------------------------------------------------

   ! if (rootproc .and. check_max_iv_print .and. failed) then
   !    write (unit = check_max_iv_unit, fmt = '(/,10(2(A,I6),/))') &
   !       'Number of failed ssmi tb19h observations:  ',itb19hf,' on ',itb19h, &
   !       'Number of failed ssmi tb19v observations:  ',itb19vf,' on ',itb19v, &
   !       'Number of failed ssmi tb22v observations:  ',itb22vf,' on ',itb22v, &
   !       'Number of failed ssmi tb37h observations:  ',itb37hf,' on ',itb37h, &
   !       'Number of failed ssmi tb37v observations:  ',itb37vf,' on ',itb37v, &
   !       'Number of failed ssmi tb85h observations:  ',itb85hf,' on ',itb85h, &
   !       'Number of failed ssmi tb85v observations:  ',itb85vf,' on ',itb85v
   ! end if

end subroutine da_check_max_iv_ssmi_tb

