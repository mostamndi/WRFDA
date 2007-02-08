program da_wrfvar_main

   !-----------------------------------------------------------------------
   ! Purpose: Main program of WRF-Var.  Responsible for starting up, reading 
   ! in (and broadcasting for distributed memory) configuration data, defining 
   ! and initializing the top-level domain, either from initial or restart
   ! data, setting up time-keeping, and then calling the da_solve
   ! routine assimilation. After the assimilation is completed, 
   ! the model is properly shut down.
   !-----------------------------------------------------------------------

   use module_symbols_util, only : wrfu_finalize

   use da_control, only : trace_use
   use da_tracing, only : da_trace_init, da_trace_report, da_trace_entry, &
      da_trace_exit
   use da_wrf_interfaces, only : wrf_shutdown, wrf_message
   use da_wrfvar_top, only : da_wrfvar_init1,da_wrfvar_init2,da_wrfvar_run

   implicit none

   interface
      subroutine da_wrfvar_finalize
      end subroutine da_wrfvar_finalize
   end interface

   ! Split initialisation into 2 parts so we can start and stop trace here

   call disable_quilting

   call da_wrfvar_init1

   if (trace_use) call da_trace_init
   if (trace_use) call da_trace_entry("da_wrfvar_main")

   call da_wrfvar_init2

   call da_wrfvar_run

   call da_wrfvar_finalize

   call wrf_message("*** WRF-Var completed successfully ***")

   if (trace_use) call da_trace_exit("da_wrfvar_main")
   if (trace_use) call da_trace_report

   call wrfu_finalize
   call wrf_shutdown

end program da_wrfvar_main

