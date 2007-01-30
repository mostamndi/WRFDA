module da_gpspw

   use module_dm, only : wrf_dm_sum_real
   use module_domain, only : xpose_type, xb_type

   use da_control, only : obs_qc_pointer,max_ob_levels,missing_r, &
      v_interp_p, v_interp_h, check_max_iv_print, &
      missing, max_error_uv, max_error_t, rootproc, &
      max_error_p,max_error_q, check_max_iv_unit,check_max_iv,  &
      max_stheight_diff,missing_data,max_error_bq,max_error_slp, &
      max_error_bt, max_error_buv, num_gpspw_tot,max_error_thickness, &
      pseudo_var, num_pseudo, Use_GpspwObs, max_error_pw, &
      fails_error_max,pseudo_err,pseudo_x, pseudo_y, stdout, &
      pseudo_z,pseudo_val,max_error_ref
   use da_define_structures, only : maxmin_type, ob_type, y_type, jo_type, &
      bad_data_type, x_type, number_type, bad_data_type, &
      gpspw_type, maxmin_type
   use da_par_util, only : da_proc_stats_combine
   use da_par_util1, only : da_proc_sum_int
   use da_reporting, only : da_error
   use da_statistics, only : da_stats_calculate
   use da_tools, only : da_max_error_qc, da_residual

   ! The "stats_gpspw_type" is ONLY used locally in da_gpspw:

   type residual_gpspw1_type
      real          :: tpw                      ! Precipitable water
   end type residual_gpspw1_type

   type maxmin_gpspw_stats_type
      type (maxmin_type)         :: tpw
   end type maxmin_gpspw_stats_type

   type stats_gpspw_type
      type (maxmin_gpspw_stats_type)  :: maximum, minimum
      type (residual_gpspw1_type)     :: average, rms_err
   end type stats_gpspw_type

contains

#include "da_ao_stats_gpspw.inc"
#include "da_jo_and_grady_gpspw.inc"
#include "da_residual_gpspw.inc"
#include "da_oi_stats_gpspw.inc"
#include "da_print_stats_gpspw.inc"
#include "da_transform_xtoy_gpspw.inc"
#include "da_transform_xtoy_gpspw_adj.inc"
#include "da_check_max_iv_gpspw.inc"
#include "da_get_innov_vector_gpspw.inc"
#include "da_calculate_grady_gpspw.inc"


end module da_gpspw

