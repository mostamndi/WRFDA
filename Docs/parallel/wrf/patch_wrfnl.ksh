#!/bin/ksh

export WRFNL_DIR=$1

# Allow marker files to be produced for running wrfnl in parallel with wrfvar
cp Registry/Registry.EM.r2285    $WRFNL_DIR/Registry/Registry.EM
cp external/RSL/module_dm.F      $WRFNL_DIR/external/RSL
cp external/RSL_LITE/module_dm.F $WRFNL_DIR/external/RSL_LITE
cp main/wrf.F                    $WRFNL_DIR/main/wrf.F

# Allow namelist_script to be automatically generated
# Remove -DNO_NAMELIST_PRINT, as we want them printed
cp arch/configure.defaults       $WRFNL_DIR/arch
cp tools/*                       $WRFNL_DIR/tools
cp frame/module_configure.F      $WRFNL_DIR/frame
