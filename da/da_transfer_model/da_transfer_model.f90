module da_transfer_model

   !---------------------------------------------------------------------------
   ! Purpose: Transfer model states between different models
   !---------------------------------------------------------------------------

   use module_configure, only : grid_config_rec_type,nl_set_dyn_opt, &
      nl_get_stand_lon,nl_get_moad_cen_lat,nl_get_cen_lon,nl_get_cen_lat, &
      nl_get_dx,nl_get_truelat2,nl_get_truelat1, nl_get_map_proj
   use module_domain, only : domain
   use module_state_description, only : dyn_em_ad, dyn_em, p_qv,dyn_em_tl, &
      p_qr, p_qi,p_qs,p_qg,p_qc,num_moist, p_a_qv, p_g_qv
   use module_dm, only : wrf_dm_sum_real, wrf_dm_sum_reals
#ifdef DM_PARALLEL
   use module_dm, only : local_communicator, &
      ntasks_x, ntasks_y, data_order_xyz, mytask, &
      ntasks, data_order_xy
   use module_comm_dm, only : halo_xa_sub, halo_init_sub, halo_psichi_uv_adj_sub
      
   use da_control, only : ips,ipe,jps,jpe,kps,kpe
#endif

   use da_control, only : cos_xls, sin_xls, cos_xle, sin_xle, trace_use, &
      coarse_jy, coarse_ix, cone_factor, delt_lon, delt_lat, gas_constant, &
      map_projection,earth_omega,mix,pi,phic,mkz,start_lon,start_lat, &
      start_x,xlonc,start_y,mjy, global, deg_to_rad, earth_radius, &
      var4d,analysis_date,coarse_ds,analysis_accu,dsm,pole, fg_format_kma_global, &
      print_detail_map,stdout,truelat1_3dv, fg_format_wrf, fg_format, base_pres, &
      truelat2_3dv, periodic_x,write_increments,max_ext_its, gravity, &
      kappa, print_detail_xa,rd_over_rv,t0, print_detail_xa, check_rh, &
      print_detail_xb,test_dm_exact,base_lapse,base_temp,vertical_ip,ptop, &
      use_ssmitbobs, dt_cloud_model, cp, use_ssmiretrievalobs,ids,ide, &
      jds,jde,kds,kde,ims,ime,jms,jme,kms,kme,its,ite,jts,jte,kts,kte, &
      vertical_ip_sqrt_delta_p, vertical_ip_delta_p,check_rh_simple, check_rh_tpw, &
      t_kelvin, num_fgat_time, num_pseudo
   use da_define_structures, only : xbx_type
   use da_grid_definitions, only : da_set_map_para
   use da_par_util, only : da_patch_to_global
   use da_physics, only : da_check_rh_simple,da_roughness_from_lanu, &
      da_sfc_wtq,da_tpq_to_rh,da_trh_to_td,da_wrf_tpq_2_slp,da_integrat_dz, &
      da_tpq_to_rh, da_check_rh,da_transform_xtogpsref
   use da_reporting, only : da_error,message, da_message, da_warning
   use da_setup_structures, only : da_setup_runconstants,da_write_increments, &
      da_write_kma_increments,da_cloud_model
   use da_ssmi, only : da_transform_xtotb
   use da_tools, only : map_info, proj_merc, proj_ps,proj_lc,proj_latlon, &
      da_llxy_default,da_llxy_wrf,da_xyll,da_diff_seconds,da_map_set, &
      da_set_boundary_xb
   use da_tracing, only : da_trace_entry, da_trace_exit, da_trace
   use da_vtox_transforms, only : da_get_vpoles
   use da_wrfvar_io, only : da_med_initialdata_output,da_med_initialdata_input
   ! Do not use line below, because it shows that we are passing a scalar to 
   ! an array
   ! use da_wrf_interfaces, only : wrf_dm_bcast_real
   use da_wrf_interfaces, only : wrf_debug

   implicit none

   contains

#include "da_transfer_wrftoxb.inc"
#include "da_transfer_kmatoxb.inc"
#include "da_transfer_xatowrf.inc"
#include "da_transfer_xatokma.inc"
#include "da_transfer_wrftltoxa.inc"
#include "da_transfer_wrftltoxa_adj.inc"
#include "da_transfer_xatowrftl.inc"
#include "da_transfer_xatowrftl_adj.inc"
#include "da_transfer_xatoanalysis.inc"
#include "da_setup_firstguess.inc"
#include "da_setup_firstguess_wrf.inc"
#include "da_setup_firstguess_kma.inc"

end module da_transfer_model
