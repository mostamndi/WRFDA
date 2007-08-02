#!/bin/ksh
#########################################################################
# Script: da_run_ideal.ksh
#
# Purpose: Run WRF's ideal utility.
#########################################################################

#########################################################################
# Ideally, you should not need to change the code below, but if you 
# think it necessary then please email wrfhelp@ucar.edu with details.
#########################################################################

export DATE=${DATE:-2003010100}
export FCST_RANGE=${FCST_RANGE:-6}
export LBC_FREQ=${LBC_FREQ:-06}
export DUMMY=${DUMMY:-false}
export REGION=${REGION:-con200}
export DOMAIN=${DOMAIN:-01}
export EXPT=${EXPT:-test}
export SOLVER=${SOLVER:-em}
export NUM_PROCS=${NUM_PROCS:-1}
export HOSTS=${HOSTS:-$HOME/hosts}
if [[ -f $HOSTS ]]; then
   export RUN_CMD=${RUN_CMD:-mpirun -machinefile $HOSTS -np $NUM_PROCS}
else
   export RUN_CMD=${RUN_CMD:-mpirun -np $NUM_PROCS}
fi
export CLEAN=${CLEAN:-false}

# Directories:
export REL_DIR=${REL_DIR:-$HOME/trunk}
export WRFVAR_DIR=${WRFVAR_DIR:-$REL_DIR/wrfvar}
export DAT_DIR=${DAT_DIR:-$HOME/data}
export REG_DIR=${REG_DIR:-$DAT_DIR/$REGION}
export EXP_DIR=${EXP_DIR:-$REG_DIR/$EXPT}
export IDEAL_OUTPUT_DIR=${IDEAL_OUTPUT_DIR:-$RC_DIR}

export WRF_DIR=${WRF_DIR:-$REL_DIR/wrf}
export RUN_DIR=${RUN_DIR:-$EXP_DIR/run/$DATE/ideal}
export WORK_DIR=$RUN_DIR/working

#From WPS:
export NL_E_WE=${NL_E_WE:-45}                          #
export NL_E_SN=${NL_E_SN:-45}                          #
export NL_DX=${NL_DX:-200000}                # Resolution (m).
export NL_DY=${NL_DY:-200000}                # Resolution (m).

#First seen in ideal:
export NL_NUM_METGRID_LEVELS=${NL_NUM_METGRID_LEVELS:-27}
export NL_P_TOP_REQUESTED=${NL_P_TOP_REQUESTED:-5000}
export NL_RUN_HOURS=${NL_RUN_HOURS:-$FCST_RANGE}
export NL_FRAMES_PER_OUTFILE=${NL_FRAMES_PER_OUTFILE:-1}
export NL_HISTORY_INTERVAL=${NL_HISTORY_INTERVAL:-360}          # (minutes)
export NL_TIME_STEP=${NL_TIME_STEP:-360}                # Timestep (s) (dt=4-6*dx(km) recommended).
export NL_ETA_LEVELS=${NL_ETA_LEVELS:-" 1.000, 0.990, 0.978, 0.964, 0.946, "\
                                        " 0.922, 0.894, 0.860, 0.817, 0.766, "\
                                        " 0.707, 0.644, 0.576, 0.507, 0.444, 0.380,"\
                                        " 0.324, 0.273, 0.228, 0.188, 0.152,"\
                                        " 0.121, 0.093, 0.069, 0.048, 0.029, 0.014, 0.000"}
export NL_E_VERT=${NL_E_VERT:-28}                   #
export NL_SMOOTH_OPTION=${NL_SMOOTH_OPTION:-1}           # ?
export NL_MP_PHYSICS=${NL_MP_PHYSICS:-3}           #
export NL_RADT=${NL_RADT:-30}                #
export NL_SF_SFCLAY_PHYSICS=${NL_SF_SFCLAY_PHYSICS:-1}
export NL_SF_SURFACE_PHYSICS=${NL_SF_SURFACE_PHYSICS:-1} #(1=Thermal diffusion, 2=Noah LSM).
export NL_NUM_SOIL_LAYERS=${NL_NUM_SOIL_LAYERS:-5}
export NL_BL_PBL_PHYSICS=${NL_BL_PBL_PHYSICS:-1} #(1=Thermal diffusion, 2=Noah LSM).
export NL_CU_PHYSICS=${NL_CU_PHYSICS:-1}           #(1=, 2=,3=).
export NL_CUDT=${NL_CUDT:-5}           #(1=, 2=,3=).
export NL_W_DAMPING=${NL_W_DAMPING:-0}            #
export NL_DIFF_OPT=${NL_DIFF_OPT:-0}             #
export NL_DAMPCOEF=${NL_DAMPCOEF:-0.2}
export NL_TIME_STEP_SOUND=${NL_TIME_STEP_SOUND:-6}    #
export NL_SPECIFIED=${NL_SPECIFIED:-.true.}          #

if [[ ! -d $IDEAL_OUTPUT_DIR/$DATE ]]; then mkdir -p $IDEAL_OUTPUT_DIR/$DATE; fi

rm -rf $WORK_DIR
mkdir -p $RUN_DIR $WORK_DIR
cd $WORK_DIR

#Get extra namelist variables:
. ${WRFVAR_DIR}/scripts/da_get_date_range.ksh

echo "<HTML><HEAD><TITLE>$EXPT ideal</TITLE></HEAD><BODY>"
echo "<H1>$EXPT ideal</H1><PRE>"

date    

echo 'REL_DIR           <A HREF="file:'$REL_DIR'">'$REL_DIR'</a>'
echo 'WRF_DIR           <A HREF="file:'$WRF_DIR'">'$WRF_DIR'</a>' $WRF_VN
echo 'RUN_DIR           <A HREF="file:'$RUN_DIR'">'$RUN_DIR'</a>'
echo 'WORK_DIR          <A HREF="file:'$WORK_DIR'">'$WORK_DIR'</a>'
echo 'IDEAL_OUTPUT_DIR  <A HREF="file:'$IDEAL_OUTPUT_DIR'">'$IDEAL_OUTPUT_DIR'</a>'
echo "SCENARIO          $SCENARIO"
echo "DATE              $DATE"
echo "END_DATE          $END_DATE"

let NL_INTERVAL_SECONDS=$LBC_FREQ*3600

export NL_AUXINPUT1_INNAME="met_em.d<domain>.<date>"

if [[ $WRF_NAMELIST'.' != '.' ]]; then
   ln -fs $WRF_NAMELIST namelist.input
elif [[ -f $WRF_DIR/inc/namelist_script.inc ]]; then
   . $WRF_DIR/inc/namelist_script.inc
else
   ln -fs $WRF_DIR/test/$SCENARIO/namelist.input .
fi

cp namelist.input $RUN_DIR

ln -fs $WRF_DIR/test/$SCENARIO/input* .

echo '<A HREF="namelist.input">Namelist input</a>'

if $DUMMY; then
   echo "Dummy ideal"
   echo Dummy ideal > wrfinput_d${DOMAIN}
   echo Dummy ideal > wrfbdy_d${DOMAIN}
   # echo Dummy ideal > wrflowinp_d${DOMAIN}
else
   ln -fs ${WRF_DIR}/main/ideal_${SCENARIO}.exe .
   $RUN_CMD ./ideal_${SCENARIO}.exe
   RC=$?

   if [[ -f namelist.output ]]; then
     cp namelist.output $RUN_DIR/namelist.output
   fi

   rm -rf $RUN_DIR/rsl
   mkdir -p $RUN_DIR/rsl
   mv rsl* $RUN_DIR/rsl
   cd $RUN_DIR/rsl
   for FILE in rsl*; do
      echo "<HTML><HEAD><TITLE>$FILE</TITLE></HEAD>" > $FILE.html
      echo "<H1>$FILE</H1><PRE>" >> $FILE.html
      cat $FILE >> $FILE.html
      echo "</PRE></BODY></HTML>" >> $FILE.html
      rm $FILE
   done
   cd $RUN_DIR

   echo '<A HREF="namelist.output">Namelist output</a>'
   echo '<A HREF="rsl/rsl.out.0000.html">rsl.out.0000</a>'
   echo '<A HREF="rsl/rsl.error.0000.html">rsl.error.0000</a>'
   echo '<A HREF="rsl">Other RSL output</a>'

   echo $(date +'%D %T') "Ended $RC"
fi

if [[ -f $WORK_DIR/wrfinput_d${DOMAIN} ]]; then
   mv $WORK_DIR/wrfinput_d${DOMAIN} $IDEAL_OUTPUT_DIR/$DATE
fi

if [[ -f $WORK_DIR/wrfbdy_d${DOMAIN} ]]; then
   mv $WORK_DIR/wrfbdy_d${DOMAIN} $IDEAL_OUTPUT_DIR/$DATE
fi

#   mv $WORK_DIR/wrflowinp_d${DOMAIN} $IDEAL_OUTPUT_DIR/$DATE

date

echo "</BODY></HTML>"

exit 0