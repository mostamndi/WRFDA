subroutine da_check_max_iv_sonde_sfc(iv,ob, it, num_qcstat_conv)                                 

   !-----------------------------------------------------------------------
   ! Purpose: TBD
   !-----------------------------------------------------------------------

   implicit none

   type(iv_type), intent(inout) :: iv
   integer,       intent(in)    :: it      ! Outer iteration
   integer,       intent(inout) :: num_qcstat_conv(:,:,:,:)
   type(y_type),  intent(in)    :: ob      ! Observation structure.


   logical :: failed
   integer :: n

   if (trace_use_dull) call da_trace_entry("da_check_max_iv_sonde_sfc")


   !---------------------------------------------------------------------------
   ! [1.0] Perform maximum innovation vector check:
   !---------------------------------------------------------------------------

   do n=iv%info(sonde_sfc)%n1,iv%info(sonde_sfc)%n2
    if( iv%info(sonde_sfc)%proc_domain(1,n) ) then
      if( iv%sonde_sfc(n)%u%qc == fails_error_max )iv%sonde_sfc(n)%u%qc =0
      if( iv%sonde_sfc(n)%u%qc >= obs_qc_pointer ) then
      call da_max_error_qc (it, iv%info(sonde_sfc), n, iv%sonde_sfc(n)%u, max_error_uv, failed)
      num_qcstat_conv(1,sonde_sfc,1,1)= num_qcstat_conv(1,sonde_sfc,1,1) + 1
      if(failed) then
      num_qcstat_conv(2,sonde_sfc,1,1)= num_qcstat_conv(2,sonde_sfc,1,1) + 1
      write(qcstat_conv_unit,'(2x,a10,2x,a4,3f12.2)')&
           'sonde_sfc',ob_vars(1),iv%info(sonde_sfc)%lat(1,n),iv%info(sonde_sfc)%lon(1,n),0.01*ob%sonde_sfc(n)%p
      end if
      end if

      if( iv%sonde_sfc(n)%v%qc == fails_error_max )iv%sonde_sfc(n)%v%qc =0
      if( iv%sonde_sfc(n)%v%qc >= obs_qc_pointer ) then
      call da_max_error_qc (it, iv%info(sonde_sfc), n, iv%sonde_sfc(n)%v, max_error_uv, failed)             
      num_qcstat_conv(1,sonde_sfc,2,1)= num_qcstat_conv(1,sonde_sfc,2,1) + 1
      if(failed) then
      num_qcstat_conv(2,sonde_sfc,2,1)= num_qcstat_conv(2,sonde_sfc,2,1) + 1
      write(qcstat_conv_unit,'(2x,a10,2x,a4,3f12.2)')&
           'sonde_sfc',ob_vars(2),iv%info(sonde_sfc)%lat(1,n),iv%info(sonde_sfc)%lon(1,n),0.01*ob%sonde_sfc(n)%p
      end if
      end if

      if( iv%sonde_sfc(n)%t%qc == fails_error_max )iv%sonde_sfc(n)%t%qc =0
      if( iv%sonde_sfc(n)%t%qc >= obs_qc_pointer ) then
      call da_max_error_qc (it, iv%info(sonde_sfc), n, iv%sonde_sfc(n)%t, max_error_t , failed)
      num_qcstat_conv(1,sonde_sfc,3,1)= num_qcstat_conv(1,sonde_sfc,3,1) + 1
      if(failed) then
      num_qcstat_conv(2,sonde_sfc,3,1)= num_qcstat_conv(2,sonde_sfc,3,1) + 1
      write(qcstat_conv_unit,'(2x,a10,2x,a4,3f12.2)')&
           'sonde_sfc',ob_vars(3),iv%info(sonde_sfc)%lat(1,n),iv%info(sonde_sfc)%lon(1,n),0.01*ob%sonde_sfc(n)%p
      end if
      end if

      if( iv%sonde_sfc(n)%q%qc == fails_error_max )iv%sonde_sfc(n)%q%qc =0
      if( iv%sonde_sfc(n)%q%qc >= obs_qc_pointer ) then
      call da_max_error_qc (it, iv%info(sonde_sfc), n, iv%sonde_sfc(n)%q, max_error_q , failed)
      num_qcstat_conv(1,sonde_sfc,4,1)= num_qcstat_conv(1,sonde_sfc,4,1) + 1
      if(failed) then
      num_qcstat_conv(2,sonde_sfc,4,1)= num_qcstat_conv(2,sonde_sfc,4,1) + 1
      write(qcstat_conv_unit,'(2x,a10,2x,a4,3f12.2)')&
           'sonde_sfc',ob_vars(4),iv%info(sonde_sfc)%lat(1,n),iv%info(sonde_sfc)%lon(1,n),0.01*ob%sonde_sfc(n)%p
      end if
      end if

      if( iv%sonde_sfc(n)%p%qc == fails_error_max )iv%sonde_sfc(n)%p%qc =0
      if( iv%sonde_sfc(n)%p%qc >= obs_qc_pointer ) then
      call da_max_error_qc (it, iv%info(sonde_sfc), n, iv%sonde_sfc(n)%p, max_error_p , failed)         
      num_qcstat_conv(1,sonde_sfc,5,1)= num_qcstat_conv(1,sonde_sfc,5,1) + 1
      if(failed) then
      num_qcstat_conv(2,sonde_sfc,5,1)= num_qcstat_conv(2,sonde_sfc,5,1) + 1
      write(qcstat_conv_unit,'(2x,a10,2x,a4,3f12.2)')&
           'sonde_sfc',ob_vars(5),iv%info(sonde_sfc)%lat(1,n),iv%info(sonde_sfc)%lon(1,n),0.01*ob%sonde_sfc(n)%p
      end if
      end if
    end if 
   end do

   if (trace_use_dull) call da_trace_exit("da_check_max_iv_sonde_sfc")

end subroutine da_check_max_iv_sonde_sfc


