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
extern FORT_DLL_SPEC void FORT_CALL MPI_GET_PROCESSOR_NAME( char * FORT_MIXED_LEN_DECL, MPI_Fint *, MPI_Fint * FORT_END_LEN_DECL );
extern FORT_DLL_SPEC void FORT_CALL mpi_get_processor_name__( char * FORT_MIXED_LEN_DECL, MPI_Fint *, MPI_Fint * FORT_END_LEN_DECL );
extern FORT_DLL_SPEC void FORT_CALL mpi_get_processor_name( char * FORT_MIXED_LEN_DECL, MPI_Fint *, MPI_Fint * FORT_END_LEN_DECL );
extern FORT_DLL_SPEC void FORT_CALL mpi_get_processor_name_( char * FORT_MIXED_LEN_DECL, MPI_Fint *, MPI_Fint * FORT_END_LEN_DECL );
extern FORT_DLL_SPEC void FORT_CALL pmpi_get_processor_name_( char * FORT_MIXED_LEN_DECL, MPI_Fint *, MPI_Fint * FORT_END_LEN_DECL );

#pragma weak MPI_GET_PROCESSOR_NAME = pmpi_get_processor_name__
#pragma weak mpi_get_processor_name__ = pmpi_get_processor_name__
#pragma weak mpi_get_processor_name_ = pmpi_get_processor_name__
#pragma weak mpi_get_processor_name = pmpi_get_processor_name__
#pragma weak pmpi_get_processor_name_ = pmpi_get_processor_name__


#elif defined(HAVE_PRAGMA_WEAK)

#if defined(F77_NAME_UPPER)
extern FORT_DLL_SPEC void FORT_CALL MPI_GET_PROCESSOR_NAME( char * FORT_MIXED_LEN_DECL, MPI_Fint *, MPI_Fint * FORT_END_LEN_DECL );

#pragma weak MPI_GET_PROCESSOR_NAME = PMPI_GET_PROCESSOR_NAME
#elif defined(F77_NAME_LOWER_2USCORE)
extern FORT_DLL_SPEC void FORT_CALL mpi_get_processor_name__( char * FORT_MIXED_LEN_DECL, MPI_Fint *, MPI_Fint * FORT_END_LEN_DECL );

#pragma weak mpi_get_processor_name__ = pmpi_get_processor_name__
#elif !defined(F77_NAME_LOWER_USCORE)
extern FORT_DLL_SPEC void FORT_CALL mpi_get_processor_name( char * FORT_MIXED_LEN_DECL, MPI_Fint *, MPI_Fint * FORT_END_LEN_DECL );

#pragma weak mpi_get_processor_name = pmpi_get_processor_name
#else
extern FORT_DLL_SPEC void FORT_CALL mpi_get_processor_name_( char * FORT_MIXED_LEN_DECL, MPI_Fint *, MPI_Fint * FORT_END_LEN_DECL );

#pragma weak mpi_get_processor_name_ = pmpi_get_processor_name_
#endif

#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#if defined(F77_NAME_UPPER)
#pragma _HP_SECONDARY_DEF PMPI_GET_PROCESSOR_NAME  MPI_GET_PROCESSOR_NAME
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma _HP_SECONDARY_DEF pmpi_get_processor_name__  mpi_get_processor_name__
#elif !defined(F77_NAME_LOWER_USCORE)
#pragma _HP_SECONDARY_DEF pmpi_get_processor_name  mpi_get_processor_name
#else
#pragma _HP_SECONDARY_DEF pmpi_get_processor_name_  mpi_get_processor_name_
#endif

#elif defined(HAVE_PRAGMA_CRI_DUP)
#if defined(F77_NAME_UPPER)
#pragma _CRI duplicate MPI_GET_PROCESSOR_NAME as PMPI_GET_PROCESSOR_NAME
#elif defined(F77_NAME_LOWER_2USCORE)
#pragma _CRI duplicate mpi_get_processor_name__ as pmpi_get_processor_name__
#elif !defined(F77_NAME_LOWER_USCORE)
#pragma _CRI duplicate mpi_get_processor_name as pmpi_get_processor_name
#else
#pragma _CRI duplicate mpi_get_processor_name_ as pmpi_get_processor_name_
#endif
#endif /* HAVE_PRAGMA_WEAK */
#endif /* USE_WEAK_SYMBOLS */
/* End MPI profiling block */


/* These definitions are used only for generating the Fortran wrappers */
#if defined(USE_WEAK_SYBMOLS) && defined(HAVE_MULTIPLE_PRAGMA_WEAK) && \
    defined(USE_ONLY_MPI_NAMES)
extern FORT_DLL_SPEC void FORT_CALL MPI_GET_PROCESSOR_NAME( char * FORT_MIXED_LEN_DECL, MPI_Fint *, MPI_Fint * FORT_END_LEN_DECL );
extern FORT_DLL_SPEC void FORT_CALL mpi_get_processor_name__( char * FORT_MIXED_LEN_DECL, MPI_Fint *, MPI_Fint * FORT_END_LEN_DECL );
extern FORT_DLL_SPEC void FORT_CALL mpi_get_processor_name( char * FORT_MIXED_LEN_DECL, MPI_Fint *, MPI_Fint * FORT_END_LEN_DECL );
extern FORT_DLL_SPEC void FORT_CALL mpi_get_processor_name_( char * FORT_MIXED_LEN_DECL, MPI_Fint *, MPI_Fint * FORT_END_LEN_DECL );

#pragma weak MPI_GET_PROCESSOR_NAME = mpi_get_processor_name__
#pragma weak mpi_get_processor_name_ = mpi_get_processor_name__
#pragma weak mpi_get_processor_name = mpi_get_processor_name__
#endif

/* Map the name to the correct form */
#ifndef MPICH_MPI_FROM_PMPI
#ifdef F77_NAME_UPPER
#define mpi_get_processor_name_ PMPI_GET_PROCESSOR_NAME
#elif defined(F77_NAME_LOWER_2USCORE)
#define mpi_get_processor_name_ pmpi_get_processor_name__
#elif !defined(F77_NAME_LOWER_USCORE)
#define mpi_get_processor_name_ pmpi_get_processor_name
#else
#define mpi_get_processor_name_ pmpi_get_processor_name_
#endif
/* This defines the routine that we call, which must be the PMPI version
   since we're renaming the Fortran entry as the pmpi version.  The MPI name
   must be undefined first to prevent any conflicts with previous renamings,
   such as those put in place by the globus device when it is building on
   top of a vendor MPI. */
#undef MPI_Get_processor_name
#define MPI_Get_processor_name PMPI_Get_processor_name 

#else

#ifdef F77_NAME_UPPER
#define mpi_get_processor_name_ MPI_GET_PROCESSOR_NAME
#elif defined(F77_NAME_LOWER_2USCORE)
#define mpi_get_processor_name_ mpi_get_processor_name__
#elif !defined(F77_NAME_LOWER_USCORE)
#define mpi_get_processor_name_ mpi_get_processor_name
/* Else leave name alone */
#endif


#endif /* MPICH_MPI_FROM_PMPI */

/* Prototypes for the Fortran interfaces */
#include "fproto.h"
FORT_DLL_SPEC void FORT_CALL mpi_get_processor_name_ ( char *v1 FORT_MIXED_LEN(d1), MPI_Fint *v2, MPI_Fint *ierr FORT_END_LEN(d1) ){
    char *p1;
    p1 = (char *)MPIU_Malloc( d1 + 1 );
    *ierr = MPI_Get_processor_name( p1, v2 );

    {char *p = v1, *pc=p1;
        while (*pc) {*p++ = *pc++;}
        while ((p-v1) < d1) { *p++ = ' '; }
    }
    MPIU_Free( p1 );
}
