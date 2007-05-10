  integer, parameter  :: WRF_NO_ERR                      =  0
  integer, parameter  :: WRF_ERR_WARN_FILE_NF            = -1
  integer, parameter  :: WRF_ERR_WARN_MD_NF              = -2
  integer, parameter  :: WRF_ERR_WARN_TIME_NF            = -3
  integer, parameter  :: WRF_ERR_WARN_TIME_EOF           = -4
  integer, parameter  :: WRF_ERR_WARN_VAR_NF             = -5
  integer, parameter  :: WRF_ERR_WARN_VAR_EOF            = -6
  integer, parameter  :: WRF_ERR_WARN_MORE_DATA_IN_FILE  = -7
  integer, parameter  :: WRF_ERR_WARN_DATE_LT_LAST_DATE  = -8
  integer, parameter  :: WRF_ERR_WARN_TOO_MANY_FILES     = -9
  integer, parameter  :: WRF_ERR_WARN_TYPE_MISMATCH      = -10
  integer, parameter  :: WRF_ERR_WARN_LENGTH_LESS_THAN_1 = -11
  integer, parameter  :: WRF_ERR_WARN_WRITE_RONLY_FILE   = -12
  integer, parameter  :: WRF_ERR_WARN_READ_WONLY_FILE    = -13
  integer, parameter  :: WRF_ERR_WARN_NETCDF             = -14 
  integer, parameter  :: WRF_ERR_WARN_FILE_NOT_OPENED    = -15
  integer, parameter  :: WRF_ERR_WARN_DATESTR_ERROR      = -16
  integer, parameter  :: WRF_ERR_WARN_DRYRUN_READ        = -17
  integer, parameter  :: WRF_ERR_WARN_ZERO_LENGTH_GET    = -18
  integer, parameter  :: WRF_ERR_WARN_ZERO_LENGTH_PUT    = -19
  integer, parameter  :: WRF_ERR_WARN_2DRYRUNS_1VARIABLE = -20
  integer, parameter  :: WRF_ERR_WARN_DATA_TYPE_NOTFOUND = -21
  integer, parameter  :: WRF_ERR_WARN_READ_PAST_EOF      = -22
  integer, parameter  :: WRF_ERR_WARN_BAD_DATA_HANDLE    = -23
  integer, parameter  :: WRF_ERR_WARN_WRTLEN_NE_DRRUNLEN = -24
  integer, parameter  :: WRF_ERR_WARN_DRYRUN_CLOSE       = -25
  integer, parameter  :: WRF_ERR_WARN_DATESTR_BAD_LENGTH = -26
  integer, parameter  :: WRF_ERR_WARN_ZERO_LENGTH_READ   = -27
  integer, parameter  :: WRF_ERR_WARN_TOO_MANY_DIMS      = -28
  integer, parameter  :: WRF_ERR_WARN_TOO_MANY_VARIABLES = -29
  integer, parameter  :: WRF_ERR_WARN_COUNT_TOO_LONG     = -30
  integer, parameter  :: WRF_ERR_WARN_DIMENSION_ERROR    = -31
  integer, parameter  :: WRF_ERR_WARN_BAD_MEMORYORDER    = -32
  integer, parameter  :: WRF_ERR_WARN_DIMNAME_REDEFINED  = -33
  integer, parameter  :: WRF_ERR_WARN_MD_AFTER_OPEN      = -34
  integer, parameter  :: WRF_ERR_WARN_CHARSTR_GT_LENDATA = -35
  integer, parameter  :: WRF_ERR_WARN_BAD_DATA_TYPE      = -36
  integer, parameter  :: WRF_ERR_WARN_FILE_NOT_COMMITTED = -37

  integer, parameter  :: WRF_ERR_FATAL_ALLOCATION_ERROR  = -1001
  integer, parameter  :: WRF_ERR_FATAL_DEALLOCATION_ERR  = -1002
  integer, parameter  :: WRF_ERR_FATAL_BAD_FILE_STATUS   = -1003
  integer, parameter  :: WRF_ERR_FATAL_BAD_VARIABLE_DIM  = -1004
  integer, parameter  :: WRF_ERR_FATAL_MDVAR_DIM_NOT_1D  = -1005
  integer, parameter  :: WRF_ERR_FATAL_TOO_MANY_TIMES    = -1006