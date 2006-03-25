#! /bin/csh -f
#-----------------------------------------------------------------------

#set echo

#T4B:
setenv DATA_DISK /ocotillo1
setenv DOMAIN t4b.afwa
setenv START_DATE 2006020412
setenv END_DATE 2006020700
setenv EXPT 2006-02.T44test
setenv BIN_TYPE 5

setenv WRFVAR_DIR ${HOME}/code_development/WRF_V2.1.2/wrfvar.devel.eotd

if ( ! $?START_DATE )    setenv START_DATE    2004030312 # Starting time of period.
if ( ! $?END_DATE )      setenv END_DATE      2004033112 # Ending time of period.
if ( ! $?INTERVAL )      setenv INTERVAL      12         # Period between files (hours).
if ( ! $?BE_METHOD )     setenv BE_METHOD     NMC        # NMC (NMC-method), ENS (Ensemble-Method).
if ( ! $?NE )            setenv NE 1                     # Number of ensemble members (for ENS).
if ( ! $?BIN_TYPE )      setenv BIN_TYPE      1          # 0=None, 1=1:ni, 2=latitude, ....
if ( ! $?LAT_MIN )       setenv LAT_MIN       -90.0      # Used if BIN_TYPE = 2.
if ( ! $?LAT_MAX )       setenv LAT_MAX       90.0       # Used if BIN_TYPE = 2.
if ( ! $?BINWIDTH_LAT )  setenv BINWIDTH_LAT  10.0       # Used if BIN_TYPE = 2.
if ( ! $?HGT_MIN )       setenv HGT_MIN       0.0        # Used if BIN_TYPE = 2.
if ( ! $?HGT_MAX )       setenv HGT_MAX       20000.0    # Used if BIN_TYPE = 2.
if ( ! $?BINWIDTH_HGT )  setenv BINWIDTH_HGT  1000.0     # Used if BIN_TYPE = 2.
if ( ! $?VARIABLE1 )     setenv VARIABLE1     ps_u       # Experiment ID
if ( ! $?VARIABLE2 )     setenv VARIABLE2     ps         # Experiment ID (normalizing field)
if ( ! $?EXPT )          setenv EXPT 2004-03.T63         # Experiment ID

if ( ! $?ID )            setenv ID ${BE_METHOD}.bin_type${BIN_TYPE}
if ( ! $?SRC_DIR )       setenv SRC_DIR ${HOME}/code_development/WRF_V2.1.2
if ( ! $?WRFVAR_DIR )    setenv WRFVAR_DIR ${SRC_DIR}/wrfvar
if ( ! $?DATA_DISK )     setenv DATA_DISK /tara
if ( ! $?DOMAIN )        setenv DOMAIN katrina.12km
if ( ! $?DAT_DIR )       setenv DAT_DIR ${DATA_DISK}/${user}/data/${DOMAIN}/noobs/gen_be
if ( ! $?RUN_DIR )       setenv RUN_DIR ${DAT_DIR}/${ID}

cd ${RUN_DIR}

echo "---------------------------------------------------------------"
echo "Run gen_be_cov2d."
echo "---------------------------------------------------------------"

ln -sf ${WRFVAR_DIR}/gen_be/gen_be_cov2d.exe .

cat >! gen_be_cov2d_nl.nl << EOF
  &gen_be_cov2d_nl
    start_date = '${START_DATE}',
    end_date = '${END_DATE}',
    interval = ${INTERVAL},
    be_method = '${BE_METHOD}',
    ne = ${NE},
    bin_type = ${BIN_TYPE},
    lat_min = ${LAT_MIN},
    lat_max = ${LAT_MAX},
    binwidth_lat = ${BINWIDTH_LAT}, 
    hgt_min = ${HGT_MIN},
    hgt_max = ${HGT_MAX},
    binwidth_hgt = ${BINWIDTH_HGT},
    variable1 = '${VARIABLE1}',
    variable2 = '${VARIABLE2}',
    expt = '${EXPT}',
    dat_dir = '${DAT_DIR}' /
EOF

./gen_be_cov2d.exe
#   rm -rf gen_be_stage1.exe

exit(0)
