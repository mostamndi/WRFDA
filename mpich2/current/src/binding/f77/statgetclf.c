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
extern FORT_DLL_SPEC void FORT_CALL MPI_STATUS_SET_CANCELLED( MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_status_set_cancelled__( MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_status_set_cancelled( MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_status_set_cancelled_( MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL pmpi_status_set_cancelled_( MPI_Fint *, MPI_Fint *, MPI_Fint * );

#pragma weak MPI_STATUS_SET_CANCELLED = pmpi_status_set_cancelled__
#pragma weak mpi_status_set_cancelled__ = pmpi_status_set_cancelled__
#pragma weak mpi_status_set_cancelled_ = pmpi_status_set_cancelled__
#pragma weak mpi_status_set_cancelled = pmpi_status_set_cancelled__
#pragma weak pmpi_status_set_cancelled_ = pmpi_status_set_cancelled__


#elif defined(HAVE_PRAGMA_WEAK)

#if defined(F77_NAME_UPPER)
extern FORT_DLL_SPEC void FORT_CALL MPI_STATUS_SET_CANCELLED( MPI_Fint *, MPI_Fint *, MPI_Fint * );

#pragma weak MPI_STATUS_SET_CANCELLED = PMPI_STATUS_SET_CANCELLED
#elif defined(F77_NAME_LOWER_2USCORE)
extern FORT_DLL_SPEC void FORT_CALL mpi_status_set_cancelled__( MPI_Fint *, MPI_Fint *, MPI_Fint * );

#pragma weak mpi_status_set_cancelled__ = pmpi_status_set_cancelled__
#elif !defined(F77_NAME_LOWER_USCORE)
extern FORT_DLL_SPEC void FORT_CALL mpi_status_set_cancelled( MPI_Fint *, MPI_Fint *, MPI_Fint * );

#pragma weak mpi_status_set_cancelled = pmpi_status_set_cancelled
#else
extern FORT_DLL_SPEC void FORT_CALL mpi_status_set_cancelled_( MPI_Fint *, MPI_Fint *, MPI_Fint * );

#pragma weak mpi_status_set_cancelled_ = pmpi_status_set_cancelled_
#endif

#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#if defined(F77_NAME_UPPER)
#pragma _HP_SECONDARY_DEF PMPI_STATUS_SET_CANCELLED  MPI_STATUS_SET_CANCELLED
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma _HP_SECONDARY_DEF pmpi_status_set_cancelled__  mpi_status_set_cancelled__
#elif !defined(F77_NAME_LOWER_USCORE)
#pragma _HP_SECONDARY_DEF pmpi_status_set_cancelled  mpi_status_set_cancelled
#else
#pragma _HP_SECONDARY_DEF pmpi_status_set_cancelled_  mpi_status_set_cancelled_
#endif

#elif defined(HAVE_PRAGMA_CRI_DUP)
#if defined(F77_NAME_UPPER)
#pragma _CRI duplicate MPI_STATUS_SET_CANCELLED as PMPI_STATUS_SET_CANCELLED
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma _CRI duplicate mpi_status_set_cancelled__ as pmpi_status_set_cancelled__
#elif !defined(F77_NAME_LOWER_USCORE)
#pragma _CRI duplicate mpi_status_set_cancelled as pmpi_status_set_cancelled
#else
#pragma _CRI duplicate mpi_status_set_cancelled_ as pmpi_status_set_cancelled_
#endif
#endif /* HAVE_PRAGMA_WEAK */
#endif /* USE_WEAK_SYMBOLS */
/* End MPI profiling block */


/* These definitions are used only for generating the Fortran wrappers */
#if defined(USE_WEAK_SYBMOLS) && defined(HAVE_MULTIPLE_PRAGMA_WEAK) && \
    defined(USE_ONLY_MPI_NAMES)
extern FORT_DLL_SPEC void FORT_CALL MPI_STATUS_SET_CANCELLED( MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_status_set_cancelled__( MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_status_set_cancelled( MPI_Fint *, MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_status_set_cancelled_( MPI_Fint *, MPI_Fint *, MPI_Fint * );

#pragma weak MPI_STATUS_SET_CANCELLED = mpi_status_set_cancelled__
#pragma weak mpi_status_set_cancelled_ = mpi_status_set_cancelled__
#pragma weak mpi_status_set_cancelled = mpi_status_set_cancelled__
#endif

/* Map the name to the correct form */
#ifndef MPICH_MPI_FROM_PMPI
#ifdef F77_NAME_UPPER
#define mpi_status_set_cancelled_ PMPI_STATUS_SET_CANCELLED
#elif defined(F77_NAME_LOWER_2USCORE)
#define mpi_status_set_cancelled_ pmpi_status_set_cancelled__
#elif !defined(F77_NAME_LOWER_USCORE)
#define mpi_status_set_cancelled_ pmpi_status_set_cancelled
#else
#define mpi_status_set_cancelled_ pmpi_status_set_cancelled_
#endif
/* This defines the routine that we call, which must be the PMPI version
   since we're renaming the Fortran entry as the pmpi version.  The MPI name
   must be undefined first to prevent any conflicts with previous renamings,
   such as those put in place by the globus device when it is building on
   top of a vendor MPI. */
#undef MPI_Status_set_cancelled
#define MPI_Status_set_cancelled PMPI_Status_set_cancelled 

#else

#ifdef F77_NAME_UPPER
#define mpi_status_set_cancelled_ MPI_STATUS_SET_CANCELLED
#elif defined(F77_NAME_LOWER_2USCORE)
#define mpi_status_set_cancelled_ mpi_status_set_cancelled__
#elif !defined(F77_NAME_LOWER_USCORE)
#define mpi_status_set_cancelled_ mpi_status_set_cancelled
/* Else leave name alone */
#endif


#endif /* MPICH_MPI_FROM_PMPI */

/* Prototypes for the Fortran interfaces */
#include "fproto.h"
FORT_DLL_SPEC void FORT_CALL mpi_status_set_cancelled_ ( MPI_Fint *v1, MPI_Fint *v2, MPI_Fint *ierr ){
    *ierr = MPI_Status_set_cancelled( (MPI_Status *)(v1), *v2 );
}
