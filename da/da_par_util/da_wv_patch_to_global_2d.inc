subroutine da_wv_patch_to_global_2d(vlocal, vglobal,    &
                                  domdesc,            &
                                  ids, ide, jds, jde, &
                                  ims, ime, jms, jme, &
                                  ips, ipe, jps, jpe)

   !---------------------------------------------------------------------
   ! Purpose: Gathers local 2D array vlocal into global array vglobal.  
   ! Assumes that "k" is not 
   ! decomposed.  End indicies in the "k" dimension are inferred from 
   ! mz, which can be less than kde.  
   !
   ! Must be called by all MPI tasks.
   !---------------------------------------------------------------------  

   implicit none

   real,              intent(in)  :: vlocal(:,:)
   real,              intent(out) :: vglobal(:,:)
   integer,           intent(in)  :: domdesc
   integer,           intent(in)  :: ids, ide, jds, jde, &
                                      ims, ime, jms, jme, &
                                      ips, ipe, jps, jpe
#ifdef DM_PARALLEL
   ! Local declarations
   integer :: kds, kms, kps, mz
   real, allocatable :: vlocal3d(:,:,:), vglobal3d(:,:,:)

   kds=1; kms=1; kps=1; mz=1
   allocate(vlocal3d (ims:ime, jms:jme, 1), &
            vglobal3d(ids:ide, jds:jde, 1))
   ! get rid of copies later
   vlocal3d(:,:,1) = vlocal(:,:)
   call da_wv_patch_to_global_3d(vlocal3d, vglobal3d,     &
                              domdesc, mz,             &
                              ids, ide, jds, jde, kds, &
                              ims, ime, jms, jme, kms, &
                              ips, ipe, jps, jpe, kps)
   if (rootproc) then
      vglobal(:,:) = vglobal3d(:,:,1)
   end if
   deallocate(vlocal3d, vglobal3d)
#endif

end subroutine da_wv_patch_to_global_2d

