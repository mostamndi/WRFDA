/* -*- Mode: C; c-basic-offset:4 ; -*- */

/*
 *  (C) 2001 by Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */

/* FIXME: The usual missing documentation (what are these routines for?
   preconditions?  who calls? post conditions? */
#undef FUNCNAME
#define FUNCNAME MPIDU_Sock_init
#undef FCNAME
#define FCNAME MPIU_QUOTE(FUNCNAME)
int MPIDU_Sock_init(void)
{
    char * env;
    MPIDI_STATE_DECL(MPID_STATE_MPIDU_SOCK_INIT);

    MPIDI_FUNC_ENTER(MPID_STATE_MPIDU_SOCK_INIT);

    if (MPIDU_Socki_initialized == 0)
    { 
	/* FIXME: where is this documented?  Also, this should use
	   the general parameter interface (environment variables
	   might not be available) */
	env = getenv("MPICH_SOCKET_BUFFER_SIZE");
	if (env)
	{
	    int tmp;
	    
	    /* FIXME: atoi doesn't detect errors (e.g., non-digits) */
	    tmp = atoi(env);
	    if (tmp > 0)
	    {
		MPIDU_Socki_socket_bufsz = tmp;
	    }
	}
    }
    
    MPIDU_Socki_initialized++;

    MPIDI_FUNC_EXIT(MPID_STATE_MPIDU_SOCK_INIT);
    return MPI_SUCCESS;
}

/* FIXME: Who calls?  When?  Should this be a finalize handler instead? */
#undef FUNCNAME
#define FUNCNAME MPIDU_Sock_finalize
#undef FCNAME
#define FCNAME MPIU_QUOTE(FUNCNAME)
int MPIDU_Sock_finalize(void)
{
    int mpi_errno = MPI_SUCCESS;
    MPIDI_STATE_DECL(MPID_STATE_MPIDU_SOCK_FINALIZE);

    MPIDU_SOCKI_VERIFY_INIT(mpi_errno, fn_exit);
    
    MPIDI_FUNC_ENTER(MPID_STATE_MPIDU_SOCK_FINALIZE);

    MPIDU_Socki_initialized--;

    if (MPIDU_Socki_initialized == 0)
    {
	MPIDU_Socki_free_eventq_mem();
    }

#ifdef USE_SOCK_VERIFY
  fn_exit:
#endif
    MPIDI_FUNC_EXIT(MPID_STATE_MPIDU_SOCK_FINALIZE);
    return mpi_errno;
}
