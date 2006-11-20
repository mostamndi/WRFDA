#!/bin/ksh
#########################################################################
# Script: da_run_suite_wrapper.ksh
#
# Purpose: Provide user-modifiable interface to da_run_suite.ksh script.
#
# Description:
#
# Here are a few examples of environment variables you may want to 
# change in da_run_suite_wrapper.ksh:
#
# 1) "export RUN_WRFVAR=true" runs WRFVAR).
# 2) "export REL_DIR=$HOME/trunk" points to directory
# containing all code (I always include all components as subdirectories
# e.g. $REL_DIR/wrfvar contains the WRFVAR code.
# 3) "export INITIAL_DATE=2003010100" begins the experiment at 00 UTC
# 1 January 2003.

# You will see the full list of environment variables, and their default
# values in da_run_suite.ksh. If one is hard-wired (i.e. not an environment
# variable then email wrfhelp@ucar.edu and we will add it for the next
# release.
#########################################################################

#Decide which stages to run (run if true):
#export RUN_RESTORE_DATA_NCEP=true
#export RUN_RESTORE_DATA_RTOBS=true
#export RUN_WRFSI=true
#export RUN_WPS=true
export RUN_REAL=true
#export RUN_OBSPROC=true
#export RUN_WRFVAR=true
#export RUN_UPDATE_BC=true
export RUN_WRF=true

#Experiment details:
#export DUMMY=${DUMMY:-true}
export REGION=amps1
export EXPT=noda
export RUN_CMD=" "
#export CLEAN=${CLEAN:-true}
#export CYCLING=${CYCLING:-true}
#export CYCLE_PERIOD=6
#export NUM_PROCS=4
#export FIRST=false

#Time info:
export INITIAL_DATE=2006100100
export FINAL_DATE=2006100100
export LONG_FCST_TIME_1=00
export LONG_FCST_RANGE_1=72
export LONG_FCST_TIME_2=12
export LONG_FCST_RANGE_2=72

#Directories:
export REL_DIR=/data1/$USER/code/trunk
#export WRF_BC_DIR=/data1/dmbarker/code/WRF_BC
export DAT_DIR=/data3/$USER/data
export WRFVAR_DIR=$REL_DIR/wrfvar
#export EXP_DIR=$HOME/data/con200/noda

#From WPS (namelist.wps):
export RUN_GEOGRID=false
export WPS_GEOG_DIR=/data1/dmbarker/data/geog
export NL_E_WE=165
export NL_E_SN=217 
export MAP_PROJ=polar
export REF_LAT=-87.4
export REF_LON=180.0
export TRUELAT1=-71.0
export TRUELAT2=-91.0
export STAND_LON=180.0
export NL_DX=60000
export NL_DY=60000

#WRF:
export NL_TIME_STEP=240
export NL_ETA_LEVELS=${NL_ETA_LEVELS:-" 1.000, 0.993, 0.980, 0.966, 0.950, "\ 
                                      " 0.933, 0.913, 0.892, 0.869, 0.844, "\
                                      " 0.816, 0.786, 0.753, 0.718, 0.680, "\
                                      " 0.639, 0.596, 0.550, 0.501, 0.451, "\
                                      " 0.398, 0.345, 0.290, 0.236, 0.188, "\
                                      " 0.145, 0.108, 0.075, 0.046, 0.021, 0.000 "}
export NL_E_VERT=31
export NL_SMOOTH_OPTION=0
export NL_MP_PHYSICS=4
export NL_RADT=10
export NL_SF_SFCLAY_PHYSICS=1
export NL_SF_SURFACE_PHYSICS=2
export NL_NUM_SOIL_LAYERS=4
export NL_BL_PBL_PHYSICS=1
export NL_W_DAMPING=1
export NL_DIFF_OPT=1
export NL_KM_OPT=4
export NL_BASE_TEMP=268.0
export NL_DAMPCOEF=0.01
export NL_TIME_STEP_SOUND=4

#WRF-Var:
#export NL_CHECK_MAX_IV=.false.

${WRFVAR_DIR}/scripts/new/da_run_suite.ksh

exit 0

