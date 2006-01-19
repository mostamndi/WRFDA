!
! WRFVAR generic type macro file
!
! This file is used to generate a series of simple boiler-plate calls 
! to support residual generic types for bitwise-exact testing.  
! It contains M4 macros and then
! a series of invocations of the macros to generate the subroutine
! definitions, which are then included in another source file.  
!

! $1 = specific ob namme, $2 = specific ob type, $3 = ob counter


define( macro_y_type_extract, 
`!--- $1 $2 $3

SUBROUTINE y_type_extract_$1( iv, re, slice )

!------------------------------------------------------------------------------
! PURPOSE:  Eliminate redundant code for many obs types.  
!
! METHOD:   Extract all $1 obs from y and place them in generic 
!           object slice.  
!           Call y_facade_free() to deallocate memory allocated here.  
!
!  HISTORY:
!           10/03/2005 - Creation.                          Tom Henderson
!
! PARENT_MODULE: par_util
!------------------------------------------------------------------------------
   IMPLICIT NONE

   TYPE (ob_type),       INTENT(IN   ) :: iv     ! Innovation vector
   TYPE (y_type),        INTENT(IN   ) :: re     ! all residual obs
   TYPE (y_facade_type), INTENT(INOUT) :: slice  ! selected residual obs
   ! Local declarations
   INTEGER :: n

   CALL y_facade_create( slice, iv%$3, iv%$3_glo )
   DO n=1, slice%num_obs
     CALL residual_generic_set_info( slice%obs(n),                     &
                                     iv%$1(n)%loc%proc_domain,      &
                                     iv%$1(n)%loc%obs_global_index )
     CALL residual_$2_to_generic( re%$1(n), iv%$1(n)%info%levels, &
                                     slice%obs(n) )
   ENDDO

END SUBROUTINE y_type_extract_$1 ' )




define( macro_y_type_insert_global, 
`!--- $1 $2 $3

SUBROUTINE y_type_insert_$1_global( slice_glob, re_glob )

!------------------------------------------------------------------------------
! PURPOSE:  Eliminate redundant code for many obs types.  
!
! METHOD:   Insert obs from generic object slice_glob into 
!           globally-scoped y_type re_glob.  re_glob is 
!           allocated minimally.  Caller must deallocate.  
!           Memory for global object slice_glob is deallocated here.  
!           Do not use slice_glob after this call.
!
!  HISTORY:
!           10/03/2005 - Creation.                          Tom Henderson
!
! PARENT_MODULE: par_util
!------------------------------------------------------------------------------
   IMPLICIT NONE

   TYPE (y_facade_type), INTENT(INOUT) :: slice_glob ! generic
   TYPE (y_type),        INTENT(INOUT) :: re_glob    ! selected residual obs
   ! Local declarations
   INTEGER :: n

   ! allocate and initialize obs
   ! deallocation is done in free_global_$1()
   ALLOCATE( re_glob%$1(slice_glob%num_obs) )
   DO n=1, slice_glob%num_obs
     CALL residual_$2_from_generic( slice_glob%obs(n), re_glob%$1(n) )
   ENDDO
   re_glob%$3 = slice_glob%num_obs  ! duplication!
   CALL y_facade_free( slice_glob )

END SUBROUTINE y_type_insert_$1_global ')




define( macro_iv_type_insert_global, 
`!--- $1 $2 $3

SUBROUTINE iv_type_insert_$1_global( slice_glob, iv_glob )

!------------------------------------------------------------------------------
! PURPOSE:  Eliminate redundant code for many obs types.  
!
! METHOD:   Insert meta-data from generic object slice_glob into 
!           globally-scoped ob_type iv_glob.  iv_glob is 
!           allocated minimally.  Caller must deallocate.  
!
!  HISTORY:
!           10/03/2005 - Creation.                          Tom Henderson
!
! PARENT_MODULE: par_util
!------------------------------------------------------------------------------
   IMPLICIT NONE

   TYPE (y_facade_type), INTENT(IN   ) :: slice_glob ! selected residual obs
   TYPE (ob_type),       INTENT(INOUT) :: iv_glob    ! partial Innovation vector
   ! Local declarations
   INTEGER :: n

   ! allocate and initialize needed bits of iv_glob (ugly)
   iv_glob%$3 = slice_glob%num_obs
   iv_glob%$3_glo = slice_glob%num_obs_glo
   ! deallocation is done in free_global_$1()
   ALLOCATE( iv_glob%$1(iv_glob%$3) )
   DO n=1, iv_glob%$3
     iv_glob%$1(n)%loc%proc_domain = slice_glob%obs(n)%proc_domain
     iv_glob%$1(n)%loc%obs_global_index = &
                                        slice_glob%obs(n)%obs_global_index
     IF ( residual_generic_has_vector( slice_glob%obs(n) ) ) THEN
       iv_glob%$1(n)%info%levels = SIZE(slice_glob%obs(n)%values(1)%ptr)
     ENDIF
   ENDDO

END SUBROUTINE iv_type_insert_$1_global ' )


define( macro_to_global, 
`!--- $1 $2 $3

!------------------------------------------------------------------------------
! PURPOSE:  Collect local arrays of residual_$2_type objects into 
!           global arrays in serial-code storage order.  This is used to 
!           perform bitwise-exact floating-point summations in 
!           serial-code-order during bitwise-exact testing of 
!           distributed-memory parallel configurations.  
!
! METHOD:   Indices stowed away during Read_Obs() are used to restore serial 
!           storage order.  Memory for global objects is allocated here.  
!           Global objects are minimally allocated to save memory.  
!           Memory is deallocated in free_global_$1().  
!
! HISTORY:
!           10/10/2005 - Creation.                          Tom Henderson
!
! PARENT_MODULE: par_util
!------------------------------------------------------------------------------
  SUBROUTINE to_global_$1( iv,      re,      jo_grad_y, &
                                  iv_glob, re_glob, jo_grad_y_glob )

    IMPLICIT NONE

    ! task-local objects
    TYPE (ob_type), INTENT( IN) :: iv             ! Innovation vector
    TYPE (y_type),  INTENT( IN) :: re             ! residual vector
    TYPE (y_type),  INTENT( IN) :: jo_grad_y      ! Grad_y(Jo)
    ! task-global objects
    TYPE (ob_type), INTENT(OUT) :: iv_glob        ! Innovation vector
    TYPE (y_type),  INTENT(OUT) :: re_glob        ! residual vector
    TYPE (y_type),  INTENT(OUT) :: jo_grad_y_glob ! Grad_y(Jo)

    ! Local declarations
    TYPE (y_facade_type) :: re_slice, re_glob_slice
    TYPE (y_facade_type) :: jo_grad_y_slice, jo_grad_y_glob_slice
    TYPE (residual_template_type) :: template  ! allocation info

    ! create process-local generic objects from specific objects
    CALL y_type_extract_$1( iv, re,        re_slice )
    CALL y_type_extract_$1( iv, jo_grad_y, jo_grad_y_slice )

    ! create global versions of generic objects from process-local objects
    ! and destroy process-local generic objects
    CALL residual_$2_create_template( template )  ! use template in case 
                                                     ! some tasks have no obs
    CALL y_facade_to_global( re_slice,        template, re_glob_slice )
    CALL y_facade_to_global( jo_grad_y_slice, template, jo_grad_y_glob_slice )

    ! create global versions of specific objects
    ! and destroy global versions of generic objects
    ! iv first
    CALL iv_type_insert_$1_global( re_glob_slice, iv_glob )
    ! then y_types
    CALL y_type_insert_$1_global( re_glob_slice,        re_glob )
    CALL y_type_insert_$1_global( jo_grad_y_glob_slice, jo_grad_y_glob )
    ! global versions of specific objects are destroyed in 
    ! free_global_$1()

    RETURN

  END SUBROUTINE to_global_$1 ' )



macro_y_type_extract(sound,sound,num_sound)


macro_y_type_insert_global(sound,sound,num_sound)


macro_iv_type_insert_global(sound,sound,num_sound)


macro_to_global(sound,sound,num_sound)


macro_y_type_extract(sonde_sfc,synop,num_sound)


macro_y_type_insert_global(sonde_sfc,synop,num_sound)


macro_iv_type_insert_global(sonde_sfc,synop,num_sound)


macro_to_global(sonde_sfc,synop,num_sound)


macro_y_type_extract(synop,synop,num_synop)


macro_y_type_insert_global(synop,synop,num_synop)


macro_iv_type_insert_global(synop,synop,num_synop)


macro_to_global(synop,synop,num_synop)

