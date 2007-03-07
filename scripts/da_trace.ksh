#!/bin/ksh

#  Purpose: Trace script usage

typeset NAME=$1
typeset DIR=$2

if test ! -z $DIR; then
   shift 2
   typeset REST="$@"
   if test -d $DIR; then
      echo `date +'%D %T'` "<A HREF=\"$DIR/index.html\">$NAME</a> $REST"
   else
      echo `date +'%D %T'` "$NAME"
   fi
else
   shift 1
   typeset REST="$@"
   echo `date +'%D %T'` "$INIT $NAME" $REST
fi
