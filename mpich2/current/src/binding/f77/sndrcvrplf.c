/* -*- Mode: C; c-basic-offset:4 ; -*- */
/*  
 *  (C) 2001 by Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 *
 * This file is automatically generated by buildiface 
 * DO NOT EDIT
 */
#include "mpi_fortimpl.h"


/* Begin MPI profiling block */
#if defined(USE_WEAK_SYMBOLS) && !defined(USE_ONLY_MPI_NAMES) 
#if defined(HAVE_MULTIPLE_PRAGMA_WEAK) && defined(F77_NAME_LOWER_2USCORE)
extern FORT_DLL_SPEC void FORT_CALL MPI_SENDRECV_REPLACE( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_sendrecv_replace__( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_sendrecv_replace( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_sendrecv_replace_( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL pmpi_sendrecv_replace_( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#pragma weak MPI_SENDRECV_REPLACE = pmpi_sendrecv_replace__
#pragma weak mpi_sendrecv_replace__ = pmpi_sendrecv_replace__
#pragma weak mpi_sendrecv_replace_ = pmpi_sendrecv_replace__
#pragma weak mpi_sendrecv_replace = pmpi_sendrecv_replace__
#pragma weak pmpi_sendrecv_replace_ = pmpi_sendrecv_replace__


#elif defined(HAVE_PRAGMA_WEAK)

#if defined(F77_NAME_UPPER)
extern FORT_DLL_SPEC void FORT_CALL MPI_SENDRECV_REPLACE( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#pragma weak MPI_SENDRECV_REPLACE = PMPI_SENDRECV_REPLACE
#elif defined(F77_NAME_LOWER_2USCORE)
extern FORT_DLL_SPEC void FORT_CALL mpi_sendrecv_replace__( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#pragma weak mpi_sendrecv_replace__ = pmpi_sendrecv_replace__
#elif !defined(F77_NAME_LOWER_USCORE)
extern FORT_DLL_SPEC void FORT_CALL mpi_sendrecv_replace( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#pragma weak mpi_sendrecv_replace = pmpi_sendrecv_replace
#else
extern FORT_DLL_SPEC void FORT_CALL mpi_sendrecv_replace_( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#pragma weak mpi_sendrecv_replace_ = pmpi_sendrecv_replace_
#endif

#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#if defined(F77_NAME_UPPER)
#pragma _HP_SECONDARY_DEF PMPI_SENDRECV_REPLACE  MPI_SENDRECV_REPLACE
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma _HP_SECONDARY_DEF pmpi_sendrecv_replace__  mpi_sendrecv_replace__
#elif !defined(F77_NAME_LOWER_USCORE)
#pragma _HP_SECONDARY_DEF pmpi_sendrecv_replace  mpi_sendrecv_replace
#else
#pragma _HP_SECONDARY_DEF pmpi_sendrecv_replace_  mpi_sendrecv_replace_
#endif

#elif defined(HAVE_PRAGMA_CRI_DUP)
#if defined(F77_NAME_UPPER)
#pragma _CRI duplicate MPI_SENDRECV_REPLACE as PMPI_SENDRECV_REPLACE
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma _CRI duplicate mpi_sendrecv_replace__ as pmpi_sendrecv_replace__
#elif !defined(F77_NAME_LOWER_USCORE)
#pragma _CRI duplicate mpi_sendrecv_replace as pmpi_sendrecv_replace
#else
#pragma _CRI duplicate mpi_sendrecv_replace_ as pmpi_sendrecv_replace_
#endif
#endif /* HAVE_PRAGMA_WEAK */
#endif /* USE_WEAK_SYMBOLS */
/* End MPI profiling block */


/* These definitions are used only for generating the Fortran wrappers */
#if defined(USE_WEAK_SYBMOLS) && defined(HAVE_MULTIPLE_PRAGMA_WEAK) && \
    defined(USE_ONLY_MPI_NAMES)
extern FORT_DLL_SPEC void FORT_CALL MPI_SENDRECV_REPLACE( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_sendrecv_replace__( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_sendrecv_replace( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_sendrecv_replace_( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );

#pragma weak MPI_SENDRECV_REPLACE = mpi_sendrecv_replace__
#pragma weak mpi_sendrecv_replace_ = mpi_sendrecv_replace__
#pragma weak mpi_sendrecv_replace = mpi_sendrecv_replace__
#endif

/* Map the name to the correct form */
#ifndef MPICH_MPI_FROM_PMPI
#ifdef F77_NAME_UPPER
#define mpi_sendrecv_replace_ PMPI_SENDRECV_REPLACE
#elif defined(F77_NAME_LOWER_2USCORE)
#define mpi_sendrecv_replace_ pmpi_sendrecv_replace__
#elif !defined(F77_NAME_LOWER_USCORE)
#define mpi_sendrecv_replace_ pmpi_sendrecv_replace
#else
#define mpi_sendrecv_replace_ pmpi_sendrecv_replace_
#endif
/* This defines the routine that we call, which must be the PMPI version
   since we're renaming the Fortran entry as the pmpi version.  The MPI name
   must be undefined first to prevent any conflicts with previous renamings,
   such as those put in place by the globus device when it is building on
   top of a vendor MPI. */
#undef MPI_Sendrecv_replace
#define MPI_Sendrecv_replace PMPI_Sendrecv_replace 

#else

#ifdef F77_NAME_UPPER
#define mpi_sendrecv_replace_ MPI_SENDRECV_REPLACE
#elif defined(F77_NAME_LOWER_2USCORE)
#define mpi_sendrecv_replace_ mpi_sendrecv_replace__
#elif !defined(F77_NAME_LOWER_USCORE)
#define mpi_sendrecv_replace_ mpi_sendrecv_replace
/* Else leave name alone */
#endif


#endif /* MPICH_MPI_FROM_PMPI */

/* Prototypes for the Fortran interfaces */
#include "fproto.h"
FORT_DLL_SPEC void FORT_CALL mpi_sendrecv_replace_ ( void*v1, MPI_Fint *v2, MPI_Fint *v3, MPI_Fint *v4, MPI_Fint *v5, MPI_Fint *v6, MPI_Fint *v7, MPI_Fint *v8, MPI_Fint *v9, MPI_Fint *ierr ){

    if (MPIR_F_NeedInit){ mpirinitf_(); MPIR_F_NeedInit = 0; }

    if (v9 == MPI_F_STATUS_IGNORE) { v9 = (MPI_Fint*)MPI_STATUS_IGNORE; }
    *ierr = MPI_Sendrecv_replace( v1, *v2, (MPI_Datatype)(*v3), *v4, *v5, *v6, *v7, (MPI_Comm)(*v8), (MPI_Status *)v9 );
}
