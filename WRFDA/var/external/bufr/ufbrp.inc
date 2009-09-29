      SUBROUTINE UFBRP(LUN,USR,I1,I2,IO,IRET)

!$$$  SUBPROGRAM DOCUMENTATION BLOCK
!
! SUBPROGRAM:    UFBRP
!   PRGMMR: WOOLLEN          ORG: NP20       DATE: 1994-01-06
!
! ABSTRACT: THIS SUBROUTINE WRITES OR READS SPECIFIED VALUES TO OR
!   FROM THE CURRENT BUFR DATA SUBSET WITHIN INTERNAL ARRAYS, WITH THE
!   DIRECTION OF THE DATA TRANSFER DETERMINED BY THE CONTEXT OF IO
!   (I.E., IF IO INDICATES LUN POINTS TO A BUFR FILE THAT IS OPEN FOR
!   INPUT, THEN DATA VALUES ARE READ FROM THE INTERNAL DATA SUBSET;
!   OTHERWISE, DATA VALUES ARE WRITTEN TO THE INTERNAL DATA SUBSET.
!   THE DATA VALUES CORRESPOND TO INTERNAL ARRAYS REPRESENTING PARSED
!   STRINGS OF MNEMONICS WHICH ARE PART OF A REGULAR (I.E., NON-
!   DELAYED) REPLICATION SEQUENCE OR FOR THOSE WHICH ARE REPLICATED
!   VIA BEING DIRECTLY LISTED MORE THAN ONCE WITHIN AN OVERALL SUBSET
!   DEFINITION RATHER THAN BY BEING INCLUDED WITHIN A REPLICATION
!   SEQUENCE.  THIS ROUTINE IS ONLY CALLED BY BUFR ARCHIVE LIBRARY
!   SUBROUTINE UFBREP AND SHOULD NEVER BE CALLED BY ANY APPLICATION
!   PROGRAM (APPLICATION PROGRAMS SHOULD ALWAYS CALL UFBREP TO PERFORM
!   THESE FUNCTIONS).
!
! PROGRAM HISTORY LOG:
! 1994-01-06  J. WOOLLEN -- ORIGINAL AUTHOR
! 1998-07-08  J. WOOLLEN -- IMPROVED MACHINE PORTABILITY
! 1999-11-18  J. WOOLLEN -- THE NUMBER OF BUFR FILES WHICH CAN BE
!                           OPENED AT ONE TIME INCREASED FROM 10 TO 32
!                           (NECESSARY IN ORDER TO PROCESS MULTIPLE
!                           BUFR FILES UNDER THE MPI)
! 2003-11-04  S. BENDER  -- ADDED REMARKS/BUFRLIB ROUTINE
!                           INTERDEPENDENCIES
! 2003-11-04  D. KEYSER  -- MAXJL (MAXIMUM NUMBER OF JUMP/LINK ENTRIES)
!                           INCREASED FROM 15000 TO 16000 (WAS IN
!                           VERIFICATION VERSION); UNIFIED/PORTABLE FOR
!                           WRF; ADDED DOCUMENTATION (INCLUDING
!                           HISTORY)
!
! USAGE:    CALL UFBRP (LUN, USR, I1, I2, IO, IRET)
!   INPUT ARGUMENT LIST:
!     LUN      - INTEGER: I/O STREAM INDEX INTO INTERNAL MEMORY ARRAYS
!     USR      - ONLY IF BUFR FILE OPEN FOR OUTPUT:
!                   REAL*8: (I1,I2) STARTING ADDRESS OF DATA VALUES
!                   WRITTEN TO DATA SUBSET
!     I1       - INTEGER: LENGTH OF FIRST DIMENSION OF USR
!     I2       - INTEGER: LENGTH OF SECOND DIMENSION OF USR
!     IO       - INTEGER: STATUS INDICATOR FOR BUFR FILE ASSOCIATED
!                WITH LUN:
!                       0 = input file
!                       1 = output file
!
!   OUTPUT ARGUMENT LIST:
!     USR      - ONLY IF BUFR FILE OPEN FOR INPUT:
!                   REAL*8: (I1,I2) STARTING ADDRESS OF DATA VALUES
!                   READ FROM DATA SUBSET
!     IRET     - INTEGER:
!                  - IF BUFR FILE OPEN FOR INPUT: NUMBER OF "LEVELS" OF
!                    DATA VALUES READ FROM DATA SUBSET (MUST BE NO
!                    LARGER THAN I2)
!                  - IF BUFR FILE OPEN FOR OUTPUT: NUMBER OF "LEVELS"
!                    OF DATA VALUES WRITTEN TO DATA SUBSET (SHOULD BE
!                    SAME AS I2)
!
! REMARKS:
!    THIS ROUTINE CALLS:        INVTAG
!    THIS ROUTINE IS CALLED BY: UFBREP
!                               Normally not called by any application
!                               programs (they should call UFBREP).
!
! ATTRIBUTES:
!   LANGUAGE: FORTRAN 77
!   MACHINE:  PORTABLE TO ALL PLATFORMS
!
!$$$

      INCLUDE 'bufrlib.prm'

!     COMMON /USRINT/ NVAL(NFILES),INV(MAXJL,NFILES),VAL(MAXJL,NFILES)
      COMMON /USRSTR/ NNOD,NCON,NODS(20),NODC(10),IVLS(10),KONS(10)

      REAL*8 USR(I1,I2)!,VAL

!----------------------------------------------------------------------
!----------------------------------------------------------------------

      IRET = 0
      INS1 = 0
      INS2 = 0

!  FIND FIRST NON-ZERO NODE IN STRING
!  ----------------------------------

      DO NZ=1,NNOD
      IF(NODS(NZ).GT.0) GOTO 1
      ENDDO
      GOTO 100

!  FRAME A SECTION OF THE BUFFER - RETURN WHEN NO FRAME
!  ----------------------------------------------------

1     IF(INS1+1.GT.NVAL(LUN)) GOTO 100
      IF(IO.EQ.1 .AND. IRET.EQ.I2) GOTO 100
      INS1 = INVTAG(NODS(NZ),LUN,INS1+1,NVAL(LUN))
      IF(INS1.EQ.0) GOTO 100

      INS2 = INVTAG(NODS(NZ),LUN,INS1+1,NVAL(LUN))
      IF(INS2.EQ.0) INS2 = NVAL(LUN)
      IRET = IRET+1

!  READ USER VALUES
!  ----------------

      IF(IO.EQ.0 .AND. IRET.LE.I2) THEN
         DO I=1,NNOD
         IF(NODS(I).GT.0) THEN
            INVN = INVTAG(NODS(I),LUN,INS1,INS2)
            IF(INVN.GT.0) USR(I,IRET) = VAL(INVN,LUN)
         ENDIF
         ENDDO
      ENDIF

!  WRITE USER VALUES
!  -----------------

      IF(IO.EQ.1 .AND. IRET.LE.I2) THEN
         DO I=1,NNOD
         IF(NODS(I).GT.0) THEN
            INVN = INVTAG(NODS(I),LUN,INS1,INS2)
            IF(INVN.GT.0) VAL(INVN,LUN) = USR(I,IRET)
         ENDIF
         ENDDO
      ENDIF

!  GO FOR NEXT FRAME
!  -----------------

      GOTO 1

!  EXIT
!  ----

100   RETURN
      END SUBROUTINE UFBRP