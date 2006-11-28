subroutine da_wrfvar_interface ( grid, config_flags ) 

   implicit none

#ifndef DEREF_KLUDGE
   interface
      subroutine da_solve ( grid , config_flags , &
#include "em_dummy_new_args.inc"
      )

      ! Driver layer modules
      use module_domain
      use module_configure
      use module_machine
      use module_tiles
      use module_dm
      ! Mediation layer modules
      ! Model layer modules
      use module_model_constants

      use da_control
      use da_define_structures
      use da_setup_structures
      use da_test
      use da_minimisation

      !--Input data.

      type(domain),                intent(inout) :: grid
      type (grid_config_rec_type), intent(inout) :: config_flags

#include "em_dummy_new_decl.inc"

      end subroutine da_solve
   end interface
#endif

   type(domain),                intent(inout) :: grid
   type (grid_config_rec_type), intent(inout) :: config_flags
   integer :: idum1, idum2

#ifdef DEREF_KLUDGE
   integer     :: sm31 , em31 , sm32 , em32 , sm33 , em33
#endif

   call da_trace_entry("da_wrfvar_interface")

   ! call mediation_setup_step ( grid , config_flags , 1 , 1 , 1 )

   call set_scalar_indices_from_config ( grid%id , idum1 , idum2 )

   call model_to_grid_config_rec ( grid%id , model_config_rec , config_flags )

   grid%itimestep = 1

#ifdef DEREF_KLUDGE
   sm31             = grid%sm31
   em31             = grid%em31
   sm32             = grid%sm32
   em32             = grid%em32
   sm33             = grid%sm33
   em33             = grid%em33
#endif

   call da_solve ( grid , config_flags , &
#include "em_actual_new_args.inc"
    )

   call da_trace_exit("da_wrfvar_interface")

end subroutine da_wrfvar_interface