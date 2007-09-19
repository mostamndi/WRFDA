subroutine da_allocate_rad_iv (i, nchan, iv, xp)

   !---------------------------------------------------------------------------
   !  Purpose: allocate radiance innovation structure
   !---------------------------------------------------------------------------

   use da_control

   implicit none

   integer           ,  intent (in)    :: i, nchan
   type (xpose_type) ,  intent (in)    :: xp
   type (iv_type)    ,  intent (inout) :: iv

   call da_trace_entry("da_allocate_rad_iv")

      allocate (iv%instid(i)%info(iv%instid(i)%num_rad))
      allocate (iv%instid(i)%loc(iv%instid(i)%num_rad))
      allocate (iv%instid(i)%loc_i(iv%instid(i)%num_rad))
      allocate (iv%instid(i)%loc_j(iv%instid(i)%num_rad))
      allocate (iv%instid(i)%loc_k(iv%instid(i)%nlevels,iv%instid(i)%num_rad))
      allocate (iv%instid(i)%loc_dz(iv%instid(i)%nlevels,iv%instid(i)%num_rad))
      allocate (iv%instid(i)%loc_dzm(iv%instid(i)%nlevels,iv%instid(i)%num_rad))
      allocate (iv%instid(i)%zk(iv%instid(i)%nlevels,iv%instid(i)%num_rad))
      allocate (iv%instid(i)%t(iv%instid(i)%nlevels,iv%instid(i)%num_rad))
      allocate (iv%instid(i)%mr(iv%instid(i)%nlevels,iv%instid(i)%num_rad))
      allocate (iv%instid(i)%loc_dx(iv%instid(i)%num_rad))
      allocate (iv%instid(i)%loc_dy(iv%instid(i)%num_rad))
      allocate (iv%instid(i)%loc_dxm(iv%instid(i)%num_rad))
      allocate (iv%instid(i)%loc_dym(iv%instid(i)%num_rad))
      allocate (iv%instid(i)%tm(xp%kms:xp%kme,iv%instid(i)%num_rad))
      allocate (iv%instid(i)%qm(xp%kms:xp%kme,iv%instid(i)%num_rad))
      allocate (iv%instid(i)%qrn(xp%kms:xp%kme,iv%instid(i)%num_rad))
      allocate (iv%instid(i)%qcw(xp%kms:xp%kme,iv%instid(i)%num_rad))
      allocate (iv%instid(i)%qci(xp%kms:xp%kme,iv%instid(i)%num_rad))
      allocate (iv%instid(i)%qsn(xp%kms:xp%kme,iv%instid(i)%num_rad))
      allocate (iv%instid(i)%qgr(xp%kms:xp%kme,iv%instid(i)%num_rad))
      allocate (iv%instid(i)%qhl(xp%kms:xp%kme,iv%instid(i)%num_rad))
      allocate (iv%instid(i)%pm(xp%kms:xp%kme,iv%instid(i)%num_rad))
      allocate (iv%instid(i)%rcw(xp%kms:xp%kme,iv%instid(i)%num_rad))
      allocate (iv%instid(i)%rci(xp%kms:xp%kme,iv%instid(i)%num_rad))
      allocate (iv%instid(i)%rrn(xp%kms:xp%kme,iv%instid(i)%num_rad))
      allocate (iv%instid(i)%rsn(xp%kms:xp%kme,iv%instid(i)%num_rad))
      allocate (iv%instid(i)%rgr(xp%kms:xp%kme,iv%instid(i)%num_rad))
      allocate (iv%instid(i)%rhl(xp%kms:xp%kme,iv%instid(i)%num_rad))
      allocate (iv%instid(i)%pf(0:xp%kme,iv%instid(i)%num_rad))
      allocate (iv%instid(i)%u10(iv%instid(i)%num_rad))
      allocate (iv%instid(i)%v10(iv%instid(i)%num_rad))
      allocate (iv%instid(i)%t2m(iv%instid(i)%num_rad))
      allocate (iv%instid(i)%q2m(iv%instid(i)%num_rad))
      allocate (iv%instid(i)%mr2m(iv%instid(i)%num_rad))
      allocate (iv%instid(i)%psfc(iv%instid(i)%num_rad))
      allocate (iv%instid(i)%ts(iv%instid(i)%num_rad))
      allocate (iv%instid(i)%smois(iv%instid(i)%num_rad))
      allocate (iv%instid(i)%tslb(iv%instid(i)%num_rad))
      allocate (iv%instid(i)%snowh(iv%instid(i)%num_rad))
      allocate (iv%instid(i)%isflg(iv%instid(i)%num_rad))
      allocate (iv%instid(i)%landsea_mask(iv%instid(i)%num_rad))
      allocate (iv%instid(i)%elevation(iv%instid(i)%num_rad))
      allocate (iv%instid(i)%vegfra(iv%instid(i)%num_rad))
      allocate (iv%instid(i)%vegtyp(iv%instid(i)%num_rad))
      allocate (iv%instid(i)%soiltyp(iv%instid(i)%num_rad))
      allocate (iv%instid(i)%clwp(iv%instid(i)%num_rad))
      allocate (iv%instid(i)%ps(iv%instid(i)%num_rad))
      allocate (iv%instid(i)%tb_xb(nchan,iv%instid(i)%num_rad))
      allocate (iv%instid(i)%tb_qc(nchan,iv%instid(i)%num_rad))
      allocate (iv%instid(i)%tb_inv(nchan,iv%instid(i)%num_rad))
      allocate (iv%instid(i)%tb_error(nchan,iv%instid(i)%num_rad))
      allocate (iv%instid(i)%emiss(iv%instid(i)%nchannels,iv%instid(i)%num_rad))
      allocate (iv%instid(i)%scanpos(iv%instid(i)%num_rad))
      allocate (iv%instid(i)%scanline(iv%instid(i)%num_rad))
      allocate (iv%instid(i)%ifgat(iv%instid(i)%num_rad))
      allocate (iv%instid(i)%cloud_flag(nchan,iv%instid(i)%num_rad))
      allocate (iv%instid(i)%satzen(iv%instid(i)%num_rad))
      allocate (iv%instid(i)%satazi(iv%instid(i)%num_rad))
      allocate (iv%instid(i)%solzen(iv%instid(i)%num_rad))
      allocate (iv%instid(i)%solazi(iv%instid(i)%num_rad))
      allocate (iv%instid(i)%proc_domain(iv%instid(i)%num_rad))
      if (rtm_option == rtm_option_crtm) then
         allocate(iv%instid(i)%water_coverage(iv%instid(i)%num_rad))
         allocate(iv%instid(i)%land_coverage(iv%instid(i)%num_rad))
         allocate(iv%instid(i)%ice_coverage(iv%instid(i)%num_rad))
         allocate(iv%instid(i)%snow_coverage(iv%instid(i)%num_rad))
         if (use_crtm_kmatrix) then
         !  allocate(iv%instid(i)%ts_jacobian(nchan,iv%instid(i)%num_rad))
         !  allocate(iv%instid(i)%windspeed_jacobian(nchan,iv%instid(i)%num_rad))
         !  allocate(iv%instid(i)%emiss_jacobian(nchan,iv%instid(i)%num_rad))
         !  allocate(iv%instid(i)%t_jacobian(nchan,xp%kte,iv%instid(i)%num_rad))
         !  allocate(iv%instid(i)%q_jacobian(nchan,xp%kte,iv%instid(i)%num_rad))
         !  allocate(iv%instid(i)%water_jacobian(nchan,xp%kte,iv%instid(i)%num_rad))
         !  allocate(iv%instid(i)%ice_jacobian(nchan,xp%kte,iv%instid(i)%num_rad))
         !  allocate(iv%instid(i)%rain_jacobian(nchan,xp%kte,iv%instid(i)%num_rad))
         !  allocate(iv%instid(i)%snow_jacobian(nchan,xp%kte,iv%instid(i)%num_rad))
         !  allocate(iv%instid(i)%graupel_jacobian(nchan,xp%kte,iv%instid(i)%num_rad))
         !  allocate(iv%instid(i)%hail_jacobian(nchan,xp%kte,iv%instid(i)%num_rad))
         !  allocate(iv%instid(i)%water_r_jacobian(nchan,xp%kte,iv%instid(i)%num_rad))
         !  allocate(iv%instid(i)%ice_r_jacobian(nchan,xp%kte,iv%instid(i)%num_rad))
         !  allocate(iv%instid(i)%rain_r_jacobian(nchan,xp%kte,iv%instid(i)%num_rad))
         !  allocate(iv%instid(i)%snow_r_jacobian(nchan,xp%kte,iv%instid(i)%num_rad))
         !  allocate(iv%instid(i)%graupel_r_jacobian(nchan,xp%kte,iv%instid(i)%num_rad))
         !  allocate(iv%instid(i)%hail_r_jacobian(nchan,xp%kte,iv%instid(i)%num_rad))
         end if
      end if

      call da_trace_exit("da_allocate_rad_iv")

end subroutine da_allocate_rad_iv
