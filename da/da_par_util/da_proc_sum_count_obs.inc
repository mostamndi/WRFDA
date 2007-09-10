subroutine da_proc_sum_count_obs (count_obs)

   !---------------------------------------------------------------------------
   !  Purpose: Do MPI sum operation across processors to get the global sum of
   !           count_obs. The sum is returned only on the root processor,
   !           i.e., processor 0. (In this way, we do not have to do all-to-all 
   !           communication.)
   !----------------------------------------------------------------------------

   implicit none
   
   integer, parameter:: numvals = num_ob_indexes*4

   type (count_obs_type), intent(inout)     :: count_obs

   integer           :: sumval(1:numvals)     ! Sum across processors.
   integer           :: procval(1:numvals)    ! Partial values on processor to sum.
   integer           :: offset                ! Index into procval and sumval arrays.

#ifdef DM_PARALLEL

   offset = 1
   call da_pack_count_obs(count_obs % num_synop, offset, procval)
   call da_pack_count_obs(count_obs % num_sound, offset, procval)
   call da_pack_count_obs(count_obs % num_sound, offset, procval)
   call da_pack_count_obs(count_obs % num_satem, offset, procval)
   call da_pack_count_obs(count_obs % num_geoamv, offset, procval)
   call da_pack_count_obs(count_obs % num_polaramv, offset, procval)
   call da_pack_count_obs(count_obs % num_metar, offset, procval)
   call da_pack_count_obs(count_obs % num_airep, offset, procval)
   call da_pack_count_obs(count_obs % num_ships, offset, procval)
   call da_pack_count_obs(count_obs % num_pilot, offset, procval)
   call da_pack_count_obs(count_obs % num_gpspw, offset, procval)
   call da_pack_count_obs(count_obs % num_ssmi_retrieval, offset, procval)
   call da_pack_count_obs(count_obs % num_ssmi_tb, offset, procval)
   call da_pack_count_obs(count_obs % num_ssmt1, offset, procval)
   call da_pack_count_obs(count_obs % num_ssmt2, offset, procval)
   call da_pack_count_obs(count_obs % num_qscat, offset, procval)
   call da_pack_count_obs(count_obs % num_profiler, offset, procval)
   call da_pack_count_obs(count_obs % num_bogus, offset, procval)
   call da_pack_count_obs(count_obs % num_buoy, offset, procval)

   call mpi_reduce(procval, sumval, numvals, mpi_integer, mpi_sum, root, comm, ierr)
   
   if (myproc == root) then
      offset = 1
      call da_unpack_count_obs(count_obs % num_synop, offset, sumval)
      call da_unpack_count_obs(count_obs % num_sound, offset, sumval)
      call da_unpack_count_obs(count_obs % num_sound, offset, sumval)
      call da_unpack_count_obs(count_obs % num_satem, offset, sumval)
      call da_unpack_count_obs(count_obs % num_geoamv, offset, sumval)
      call da_unpack_count_obs(count_obs % num_polaramv, offset, sumval)
      call da_unpack_count_obs(count_obs % num_metar, offset, sumval)
      call da_unpack_count_obs(count_obs % num_airep, offset, sumval)
      call da_unpack_count_obs(count_obs % num_ships, offset, sumval)
      call da_unpack_count_obs(count_obs % num_pilot, offset, sumval)
      call da_unpack_count_obs(count_obs % num_gpspw, offset, sumval)
      call da_unpack_count_obs(count_obs % num_ssmi_retrieval, offset, procval)
      call da_unpack_count_obs(count_obs % num_ssmi_tb, offset, procval)
      call da_unpack_count_obs(count_obs % num_ssmt1, offset, sumval)
      call da_unpack_count_obs(count_obs % num_ssmt2, offset, sumval)
      call da_unpack_count_obs(count_obs % num_qscat, offset, sumval)
      call da_unpack_count_obs(count_obs % num_profiler, offset, sumval)
      call da_unpack_count_obs(count_obs % num_bogus, offset, sumval)
      call da_unpack_count_obs(count_obs % num_buoy, offset, sumval)
   end if
#endif

end subroutine da_proc_sum_count_obs

