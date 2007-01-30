module da_buoy 

   use da_control, only : obs_qc_pointer,max_ob_levels,missing_r, &
      check_max_iv_print, check_max_iv_unit, v_interp_p, v_interp_h, &
      check_max_iv, missing, max_error_uv, max_error_t, rootproc, &
      num_buoy_tot, max_error_p,max_error_q,  &
      max_stheight_diff,missing_data,max_error_bq,max_error_slp, &
      max_error_bt, max_error_buv,sfc_assi_options
   use da_define_structures, only : maxmin_type, ob_type, y_type, jo_type, &
      bad_data_type, x_type, number_type, bad_data_type, &
      synop_type
   use module_domain, only : xpose_type, xb_type
   use da_interpolation, only : da_to_zk, &
      da_interp_obs_lin_2d,da_interp_obs_lin_2d_adj, &
      da_interp_lin_2d, da_interp_lin_2d_adj
   use da_statistics, only : da_stats_calculate
   use da_tools, only : da_max_error_qc, da_residual, da_obs_sfc_correction
   use da_par_util1, only : da_proc_sum_int
   use da_par_util, only : da_proc_stats_combine
   use da_physics, only : da_sfc_pre, da_transform_xtopsfc, &
      da_transform_xtopsfc_adj

   ! The "stats_buoy_type" is ONLY used locally in da_buoy:

   type residual_buoy1_type
      real          :: u                        ! u-wind.
      real          :: v                        ! v-wind.
      real          :: t                        ! temperature
      real          :: p                        ! pressure
      real          :: q                        ! specific humidity
   end type residual_buoy1_type

   type maxmin_buoy_stats_type
      type (maxmin_type)         :: u, v, t, p, q
   end type maxmin_buoy_stats_type

   type stats_buoy_type
      type (maxmin_buoy_stats_type)  :: maximum, minimum
      type (residual_buoy1_type)     :: average, rms_err
   end type stats_buoy_type

contains

#include "da_ao_stats_buoy.inc"
#include "da_jo_and_grady_buoy.inc"
#include "da_residual_buoy.inc"
#include "da_oi_stats_buoy.inc"
#include "da_print_stats_buoy.inc"
#include "da_transform_xtoy_buoy.inc"
#include "da_transform_xtoy_buoy_adj.inc"
#include "da_check_max_iv_buoy.inc"
#include "da_get_innov_vector_buoy.inc"
#include "da_calculate_grady_buoy.inc"


end module da_buoy 

