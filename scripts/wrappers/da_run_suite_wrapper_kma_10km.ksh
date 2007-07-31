#!/bin/ksh
#########################################################################

#Decide which stages to run (run if true):
export RUN_WPS=true
#export RUN_REAL=true
#export RUN_WRF=true

#Experiment details:
export REGION=kma_10km
export RUN_UNGRIB_METGRID_KMA=true
export FG_TYPE=GDAPS
export EXPT=noda
#export CYCLE_PERIOD=6
#export CYCLING=true
#export FIRST=false

#Scheduling:
export PROJECT_ID=25000026        # JNT GAUs (1200/month).
#export PROJECT_ID=48500053       # JNT GAUs (1200/month).
#export PROJECT_ID=48503001       # DATC GAUs.
export QUEUE=premium
#export QUEUE=share
export NUM_PROCS=64
export RUN_CMD=mpirun.lsf
export LSF_MAX_RUNTIME=60
export LSF_EXCLUSIVE=" "
export LL_PTILE=16

#Time info:
export INITIAL_DATE=2007070300
export FINAL_DATE=2007070300
#export LONG_FCST_TIME_1=00
#export LONG_FCST_RANGE_1=72
#export LONG_FCST_TIME_2=12
#export LONG_FCST_RANGE_2=72
#export LBC_FREQ=3

#Directories:
export MACHINE=bluevista
export REL_DIR=/rap/datc/code
export DAT_DIR=/rap/datc/data
export GRIB_DIR=$DAT_DIR/$FG_TYPE
export WPS_GEOG_DIR=/mmm/users/wrfhelp/WPS_GEOG   # bluevista 

export OBSPROC_DIR=$REL_DIR/3DVAR_OBSPROC         # Which version?
#export WRFVAR_DIR=$REL_DIR/wrfvar_r2522           # r2522.
export WRFVAR_DIR=/mmm/users/dmbarker/code/trunk/wrfvar_afwa_2.2 # AFWA branch.
#export WPS_DIR=$REL_DIR/wps_r237                  # r237 AFWA release.
export WPS_DIR=/mmm/users/dmbarker/code/trunk/wps_r237                  # r237 AFWA release.
export WRF_BC_DIR=$REL_DIR/WRF_BC                 # Which version?
export WRF_DIR=$REL_DIR/wrf_r2234                 # 
export REG_DIR=$DAT_DIR/$REGION
export EXP_DIR=$REG_DIR/$EXPT
export OB_DIR=$REG_DIR/ob

#WPS (namelist.wps):
export RUN_GEOGRID=false
export NL_E_WE=574
export NL_E_SN=514
export REF_LAT=38.00
export REF_LON=126.0
export STAND_LON=126.0
export NL_DX=10000
export NL_DY=$NL_DX

#WRF real (not already covered above):
export NL_HISTORY_INTERVAL=60
export NL_TIME_STEP=60
export NL_ETA_LEVELS=${NL_ETA_LEVELS:-" 1.000, 0.993, 0.980, 0.966, 0.950, "\
                                      " 0.933, 0.913, 0.892, 0.869, 0.844, "\
                                      " 0.816, 0.786, 0.753, 0.718, 0.680, "\
                                      " 0.639, 0.596, 0.550, 0.501, 0.451, "\
                                      " 0.398, 0.345, 0.290, 0.236, 0.188, "\
                                      " 0.145, 0.108, 0.075, 0.046, 0.021, "\
                                      " 0.000 "}

export NL_E_VERT=31
export NL_SMOOTH_OPTION=0
export NL_MP_PHYSICS=6
export NL_RADT=10
export NL_SF_SURFACE_PHYSICS=2
export NL_NUM_SOIL_LAYERS=4
export NL_CUDT=0
export NL_MP_ZERO_OUT=0
export NL_DAMPCOEF=0.01
export NL_TIME_STEP_SOUND=0

#WRF (not already covered above):
export NL_NUM_METGRID_LEVELS=24
export NL_INPUTOUT_BEGIN_H=6   #our previous setting: 3       # Output input format start.
export NL_INPUTOUT_END_H=6     #our previous setting: 9       # Output input format end.#
export NL_FORCE_SFC_IN_VINTERP=6  # AFWA'S original is 6,     (recommend switch to 0, Dave 31 May 2007)

#export NL_ADJUST_HEIGHTS=true   # Not in 2234?
#export NL_NIO_TASKS_PER_GROUP=0 # Not in 2234?
#export NL_NIO_GROUPS=1          # Not in 2234?

#OBSPROC (not covered above):

#WRF-Var:

#Continuous job 
#export CONTJOB=n
export SCRIPT=$WRFVAR_DIR/scripts/da_run_suite.ksh
export MACHINE=bluevista
$WRFVAR_DIR/scripts/da_run_job.${MACHINE}.ksh

exit 0

