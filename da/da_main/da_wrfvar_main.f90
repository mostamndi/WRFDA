!WRFVAR:DRIVER_LAYER:MAIN
!

PROGRAM da_wrfvar_main

  USE da_wrfvar_top

!<DESCRIPTION>
! Main program of WRFVAR.  Responsible for starting up, reading in (and
! broadcasting for distributed memory) configuration data, defining and 
! initializing the top-level domain, either from initial or restart data, 
! setting up time-keeping, and then calling the 
! <a href=da_v3d_solve.html>da_v3d_solve</a> routine assimilation. After
! the assimilation is completed, the model is properly shut down.
!
!</DESCRIPTION>

  IMPLICIT NONE

   ! Split initialisation into 2 parts so we can start and stop trace here

   CALL da_wrfvar_init1

   IF (trace_use) call da_trace_init
   IF (trace_use) call da_trace_entry("da_wrfvar_main")

   CALL da_wrfvar_init2

   CALL da_wrfvar_run

   CALL da_wrfvar_finalize

   call wrf_message("*** WRF-Var completed successfully ***")

   IF (trace_use) call da_trace_exit("da_wrfvar_main")
   IF (trace_use) call da_trace_report

   call WRFU_Finalize
   call wrf_shutdown

END PROGRAM da_wrfvar_main
