subroutine da_check_max_iv_gpspw(it, gpspw, ittpw,ittpwf)

  !-------------------------------------------------------------------------
  ! Purpose: TBD
  !-------------------------------------------------------------------------

  implicit none

  integer,           intent (in)         :: it      ! Outer iteration
  type (gpspw_type), intent(inout)       :: gpspw
  integer, intent(inout) :: ittpw,ittpwf
  logical                                :: failed 

  if (rootproc .and. check_max_iv_print) then
    write (check_max_iv_unit,'(A)')  &
      '----------------------------------------------------------------'
    write (unit = check_max_iv_unit, fmt = '(A,/)') 'MAX ERROR TEST QC:'
    write (unit = check_max_iv_unit, fmt = '(/,9(A,F3.0,/))')  &
     'Error max test ratio for gps_tpw = ',max_error_pw
  end if

  !---------------------------------------------------------------------------
  ! [2.0] Perform maximum innovation vector check:
  !---------------------------------------------------------------------------

  failed = .false.

  ! TPW:
  call da_max_error_qc(it, gpspw % info, gpspw % tpw, max_error_pw, ittpw, &
    ittpwf, check_max_iv_unit, 'TPW  ', failed, check_max_iv_print)

end subroutine da_check_max_iv_gpspw

