#!/bin/ksh

export WRF_DIR=$1

# Allow namelist_script to be automatically generated
# Remove -DNO_NAMELIST_PRINT, as we want them printed
cp arch/configure.defaults       $WRF_DIR/arch
