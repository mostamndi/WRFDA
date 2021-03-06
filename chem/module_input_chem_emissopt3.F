

MODULE module_input_chem_emissopt3

    USE module_io_domain
    USE module_domain
    USE module_driver_constants
    USE module_state_description
    USE module_configure
    USE module_date_time
    USE module_wrf_error
    USE module_timing
    USE module_data_radm2
!   USE module_aerosols_sorgam
!   USE module_data_sorgam
    USE module_utility
    USE module_get_file_names


   IMPLICIT NONE

CONTAINS

SUBROUTINE med_read_bin_chem_emissopt3 ( grid , config_flags )
   USE module_bc_time_utilities
#ifdef DM_PARALLEL
   USE module_dm
#endif


   IMPLICIT NONE

  ! Arguments
   TYPE(domain)                               :: grid
   TYPE (grid_config_rec_type) , INTENT(IN)   :: config_flags
  !INTEGER , INTENT(IN)                       :: start_step , step , end_step
!  Type (ESMF_Time )                          :: start_time, stop_time, CurrTime
!   TYPE(WRFU_TimeInterval) :: time_interval


  ! Local data
   LOGICAL, EXTERNAL                      :: wrf_dm_on_monitor
   LOGICAL                                :: emiss_opened
   INTEGER                                :: ierr , open_status , fid
   REAL                                   :: time, btime, bfrq
   REAL, ALLOCATABLE :: dumc0(:,:,:)
   REAL, ALLOCATABLE :: dumc1(:,:)
   CHARACTER (LEN=256)                    :: message
   CHARACTER (LEN=80)                     :: bdyname

   CHARACTER (LEN=9 ),DIMENSION(30)       :: ename
   CHARACTER (LEN=20)       :: dname
   INTEGER :: nv,i , j , k, itime, &
              ids, ide, jds, jde, kds, kde,    &
              ims, ime, jms, jme, kms, kme,    &
              ips, ipe, jps, jpe, kps, kpe


#include <wrf_io_flags.h>

   write(message, '(A,I9)') 'call read emissions opt3'
   call wrf_message( TRIM( message ) )

     CALL construct_filename1 ( bdyname , '../../run/emissopt3' , grid%id , 2 )

     IF (wrf_dm_on_monitor()) THEN
        open (92,file=bdyname,form='unformatted')
     ENDIf
   write(message, '(A,A)') ' OPENED FILE: ',bdyname
   call wrf_message( TRIM( message ) )
   CALL wrf_debug( 100 , 'med_read_bin_chem_emissopt3: calling emissions for opt 3' )

   CALL get_ijk_from_grid (  grid ,                        &
                             ids, ide, jds, jde, kds, kde,    &
                             ims, ime, jms, jme, kms, kme,    &
                             ips, ipe, jps, jpe, kps, kpe    )

   ALLOCATE (dumc0(ids:ide,kds:grid%kemit,jds:jde))
   ALLOCATE (dumc1(ids:ide,jds:jde))

     write(message, '(A,4I6)') ' I am reading fire emissions, dims: =',ids, ide-1, jds, jde-1
     call wrf_message( TRIM( message ) )

     read(92)nv
      print *,'nv = ',nv
     read(92)dname
     read(92)itime
     call wrf_message( TRIM( message ) )

!        read(92)dumc0
!        grid%e_so2(ids:ide-1,kds:grid%kemit,jds:jde-1)=dumc0(ids:ide-1,kds:grid%kemit,jds:jde-1)
!        read(92)dumc0
!        grid%e_no(ids:ide-1,kds:grid%kemit,jds:jde-1)=dumc0(ids:ide-1,kds:grid%kemit,jds:jde-1)
!        read(92)dumc0
!        grid%e_ald(ids:ide-1,kds:grid%kemit,jds:jde-1)=dumc0(ids:ide-1,kds:grid%kemit,jds:jde-1)
!        read(92)dumc0
!        grid%e_hcho(ids:ide-1,kds:grid%kemit,jds:jde-1)=dumc0(ids:ide-1,kds:grid%kemit,jds:jde-1)
!        read(92)dumc0
!        grid%e_ora2(ids:ide-1,kds:grid%kemit,jds:jde-1)=dumc0(ids:ide-1,kds:grid%kemit,jds:jde-1)
!        read(92)dumc0
!        grid%e_nh3(ids:ide-1,kds:grid%kemit,jds:jde-1)=dumc0(ids:ide-1,kds:grid%kemit,jds:jde-1)
!        read(92)dumc0
!        grid%e_hc3(ids:ide-1,kds:grid%kemit,jds:jde-1)=dumc0(ids:ide-1,kds:grid%kemit,jds:jde-1)
!        read(92)dumc0
!        grid%e_hc5(ids:ide-1,kds:grid%kemit,jds:jde-1)=dumc0(ids:ide-1,kds:grid%kemit,jds:jde-1)
!        read(92)dumc0
!        grid%e_hc8(ids:ide-1,kds:grid%kemit,jds:jde-1)=dumc0(ids:ide-1,kds:grid%kemit,jds:jde-1)
!        read(92)dumc0
!        grid%e_eth(ids:ide-1,kds:grid%kemit,jds:jde-1)=dumc0(ids:ide-1,kds:grid%kemit,jds:jde-1)
!        read(92)dumc0
!        grid%e_co(ids:ide-1,kds:grid%kemit,jds:jde-1)=dumc0(ids:ide-1,kds:grid%kemit,jds:jde-1)
!        read(92)dumc0
!        grid%e_ol2(ids:ide-1,kds:grid%kemit,jds:jde-1)=dumc0(ids:ide-1,kds:grid%kemit,jds:jde-1)
!        read(92)dumc0
!        grid%e_olt(ids:ide-1,kds:grid%kemit,jds:jde-1)=dumc0(ids:ide-1,kds:grid%kemit,jds:jde-1)
!        read(92)dumc0
!        grid%e_oli(ids:ide-1,kds:grid%kemit,jds:jde-1)=dumc0(ids:ide-1,kds:grid%kemit,jds:jde-1)
!        read(92)dumc0
!        grid%e_tol(ids:ide-1,kds:grid%kemit,jds:jde-1)=dumc0(ids:ide-1,kds:grid%kemit,jds:jde-1)
!        read(92)dumc0
!        grid%e_xyl(ids:ide-1,kds:grid%kemit,jds:jde-1)=dumc0(ids:ide-1,kds:grid%kemit,jds:jde-1)
!        read(92)dumc0
!        grid%e_ket(ids:ide-1,kds:grid%kemit,jds:jde-1)=dumc0(ids:ide-1,kds:grid%kemit,jds:jde-1)
!        read(92)dumc0
!        grid%e_csl(ids:ide-1,kds:grid%kemit,jds:jde-1)=dumc0(ids:ide-1,kds:grid%kemit,jds:jde-1)
!        read(92)dumc0
!        grid%e_iso(ids:ide-1,kds:grid%kemit,jds:jde-1)=dumc0(ids:ide-1,kds:grid%kemit,jds:jde-1)
!        read(92)dumc0
!        grid%e_pm25(ids:ide-1,kds:grid%kemit,jds:jde-1)=dumc0(ids:ide-1,kds:grid%kemit,jds:jde-1)
!        read(92)dumc0
!        grid%e_pm10(ids:ide-1,kds:grid%kemit,jds:jde-1)=dumc0(ids:ide-1,kds:grid%kemit,jds:jde-1)


         read(92)dumc1
         grid%e_so2(ids:ide-1,kds,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(92)dumc1
         grid%e_no(ids:ide-1,kds,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(92)dumc1
         grid%e_ald(ids:ide-1,kds,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(92)dumc1
         grid%e_hcho(ids:ide-1,kds,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(92)dumc1
         grid%e_ora2(ids:ide-1,kds,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(92)dumc1
         grid%e_nh3(ids:ide-1,kds,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(92)dumc1
         grid%e_hc3(ids:ide-1,kds,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(92)dumc1
         grid%e_hc5(ids:ide-1,kds,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(92)dumc1
         grid%e_hc8(ids:ide-1,kds,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(92)dumc1
         grid%e_eth(ids:ide-1,kds,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(92)dumc1
         grid%e_co(ids:ide-1,kds,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(92)dumc1
         grid%e_ol2(ids:ide-1,kds,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(92)dumc1
         grid%e_olt(ids:ide-1,kds,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(92)dumc1
         grid%e_oli(ids:ide-1,kds,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(92)dumc1
         grid%e_tol(ids:ide-1,kds,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(92)dumc1
         grid%e_xyl(ids:ide-1,kds,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(92)dumc1
         grid%e_ket(ids:ide-1,kds,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(92)dumc1
         grid%e_csl(ids:ide-1,kds,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(92)dumc1
         grid%e_iso(ids:ide-1,kds,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(92)dumc1
         grid%e_pm25(ids:ide-1,kds,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(92)dumc1
         grid%e_pm10(ids:ide-1,kds,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)

     CALL construct_filename1 ( bdyname , '../../run/emissfire' , grid%id , 2 )

     IF (wrf_dm_on_monitor()) THEN
        open (93,file=bdyname,form='unformatted')
     ENDIf
   write(message, '(A,A)') ' OPENED FILE: ',bdyname
   call wrf_message( TRIM( message ) )
   CALL wrf_debug( 100 , 'med_read_bin_chem_emissopt3: calling fire emissions for opt 3' )
         read(93)nv
         read(93)dname
         read(93)itime

         read(93)dumc1
!        grid%ebu_so2(ids:ide-1,kds,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(93)dumc1
         grid%ebu_no(ids:ide-1,kds,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(93)dumc1
         grid%ebu_ald(ids:ide-1,kds,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(93)dumc1
         grid%ebu_hcho(ids:ide-1,kds,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(93)dumc1
         grid%ebu_ora2(ids:ide-1,kds,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(93)dumc1
!        grid%ebu_nh3(ids:ide-1,kds,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(93)dumc1
         grid%ebu_hc3(ids:ide-1,kds,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(93)dumc1
         grid%ebu_hc5(ids:ide-1,kds,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(93)dumc1
         grid%ebu_hc8(ids:ide-1,kds,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(93)dumc1
         grid%ebu_eth(ids:ide-1,kds,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(93)dumc1
         grid%ebu_co(ids:ide-1,kds,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(93)dumc1
!        grid%ebu_ol2(ids:ide-1,kds,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(93)dumc1
         grid%ebu_olt(ids:ide-1,kds,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(93)dumc1
         grid%ebu_oli(ids:ide-1,kds,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(93)dumc1
         grid%ebu_tol(ids:ide-1,kds,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(93)dumc1
         grid%ebu_xyl(ids:ide-1,kds,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(93)dumc1
         grid%ebu_ket(ids:ide-1,kds,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(93)dumc1
         grid%ebu_csl(ids:ide-1,kds,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(93)dumc1
         grid%ebu_iso(ids:ide-1,kds,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(93)dumc1
         grid%ebu_pm25(ids:ide-1,kds,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(93)dumc1
         grid%ebu_pm10(ids:ide-1,kds,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(93)dumc1
         grid%mean_fct_agtf(ids:ide-1,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(93)dumc1
         grid%mean_fct_agef(ids:ide-1,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(93)dumc1
         grid%mean_fct_agsv(ids:ide-1,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(93)dumc1
         grid%mean_fct_aggr(ids:ide-1,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(93)dumc1
         grid%firesize_agtf(ids:ide-1,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(93)dumc1
         grid%firesize_agef(ids:ide-1,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(93)dumc1
         grid%firesize_agsv(ids:ide-1,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)
         read(93)dumc1
         grid%firesize_aggr(ids:ide-1,jds:jde-1)=dumc1(ids:ide-1,jds:jde-1)


    DEALLOCATE ( dumc0 )
    DEALLOCATE ( dumc1 )
   RETURN
END SUBROUTINE  med_read_bin_chem_emissopt3

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
END MODULE module_input_chem_emissopt3

