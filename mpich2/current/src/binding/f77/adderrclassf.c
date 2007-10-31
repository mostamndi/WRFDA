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
extern FORT_DLL_SPEC void FORT_CALL MPI_ADD_ERROR_CLASS( MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_add_error_class__( MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_add_error_class( MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_add_error_class_( MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL pmpi_add_error_class_( MPI_Fint *, MPI_Fint * );

#pragma weak MPI_ADD_ERROR_CLASS = pmpi_add_error_class__
#pragma weak mpi_add_error_class__ = pmpi_add_error_class__
#pragma weak mpi_add_error_class_ = pmpi_add_error_class__
#pragma weak mpi_add_error_class = pmpi_add_error_class__
#pragma weak pmpi_add_error_class_ = pmpi_add_error_class__


#elif defined(HAVE_PRAGMA_WEAK)

#if defined(F77_NAME_UPPER)
extern FORT_DLL_SPEC void FORT_CALL MPI_ADD_ERROR_CLASS( MPI_Fint *, MPI_Fint * );

#pragma weak MPI_ADD_ERROR_CLASS = PMPI_ADD_ERROR_CLASS
#elif defined(F77_NAME_LOWER_2USCORE)
extern FORT_DLL_SPEC void FORT_CALL mpi_add_error_class__( MPI_Fint *, MPI_Fint * );

#pragma weak mpi_add_error_class__ = pmpi_add_error_class__
#elif !defined(F77_NAME_LOWER_USCORE)
extern FORT_DLL_SPEC void FORT_CALL mpi_add_error_class( MPI_Fint *, MPI_Fint * );

#pragma weak mpi_add_error_class = pmpi_add_error_class
#else
extern FORT_DLL_SPEC void FORT_CALL mpi_add_error_class_( MPI_Fint *, MPI_Fint * );

#pragma weak mpi_add_error_class_ = pmpi_add_error_class_
#endif

#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#if defined(F77_NAME_UPPER)
#pragma _HP_SECONDARY_DEF PMPI_ADD_ERROR_CLASS  MPI_ADD_ERROR_CLASS
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma _HP_SECONDARY_DEF pmpi_add_error_class__  mpi_add_error_class__
#elif !defined(F77_NAME_LOWER_USCORE)
#pragma _HP_SECONDARY_DEF pmpi_add_error_class  mpi_add_error_class
#else
#pragma _HP_SECONDARY_DEF pmpi_add_error_class_  mpi_add_error_class_
#endif

#elif defined(HAVE_PRAGMA_CRI_DUP)
#if defined(F77_NAME_UPPER)
#pragma _CRI duplicate MPI_ADD_ERROR_CLASS as PMPI_ADD_ERROR_CLASS
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma _CRI duplicate mpi_add_error_class__ as pmpi_add_error_class__
#elif !defined(F77_NAME_LOWER_USCORE)
#pragma _CRI duplicate mpi_add_error_class as pmpi_add_error_class
#else
#pragma _CRI duplicate mpi_add_error_class_ as pmpi_add_error_class_
#endif
#endif /* HAVE_PRAGMA_WEAK */
#endif /* USE_WEAK_SYMBOLS */
/* End MPI profiling block */


/* These definitions are used only for generating the Fortran wrappers */
#if defined(USE_WEAK_SYBMOLS) && defined(HAVE_MULTIPLE_PRAGMA_WEAK) && \
    defined(USE_ONLY_MPI_NAMES)
extern FORT_DLL_SPEC void FORT_CALL MPI_ADD_ERROR_CLASS( MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_add_error_class__( MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_add_error_class( MPI_Fint *, MPI_Fint * );
extern FORT_DLL_SPEC void FORT_CALL mpi_add_error_class_( MPI_Fint *, MPI_Fint * );

#pragma weak MPI_ADD_ERROR_CLASS = mpi_add_error_class__
#pragma weak mpi_add_error_class_ = mpi_add_error_class__
#pragma weak mpi_add_error_class = mpi_add_error_class__
#endif

/* Map the name to the correct form */
#ifndef MPICH_MPI_FROM_PMPI
#ifdef F77_NAME_UPPER
#define mpi_add_error_class_ PMPI_ADD_ERROR_CLASS
#elif defined(F77_NAME_LOWER_2USCORE)
#define mpi_add_error_class_ pmpi_add_error_class__
#elif !defined(F77_NAME_LOWER_USCORE)
#define mpi_add_error_class_ pmpi_add_error_class
#else
#define mpi_add_error_class_ pmpi_add_error_class_
#endif
/* This defines the routine that we call, which must be the PMPI version
   since we're renaming the Fortran entry as the pmpi version.  The MPI name
   must be undefined first to prevent any conflicts with previous renamings,
   such as those put in place by the globus device when it is building on
   top of a vendor MPI. */
#undef MPI_Add_error_class
#define MPI_Add_error_class PMPI_Add_error_class 

#else

#ifdef F77_NAME_UPPER
#define mpi_add_error_class_ MPI_ADD_ERROR_CLASS
#elif defined(F77_NAME_LOWER_2USCORE)
#define mpi_add_error_class_ mpi_add_error_class__
#elif !defined(F77_NAME_LOWER_USCORE)
#define mpi_add_error_class_ mpi_add_error_class
/* Else leave name alone */
#endif


#endif /* MPICH_MPI_FROM_PMPI */

/* Prototypes for the Fortran interfaces */
#include "fproto.h"
FORT_DLL_SPEC void FORT_CALL mpi_add_error_class_ ( MPI_Fint *v1, MPI_Fint *ierr ){
    *ierr = MPI_Add_error_class( v1 );
}
