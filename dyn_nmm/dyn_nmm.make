DYN_MODULES =                 		\
        module_ADVECTION.o         	\
        module_BC_NMM.o         	\
        module_BNDRY_COND.o         	\
        module_CTLBLK.o         	\
        module_DIFFUSION_NMM.o         	\
        module_IGWAVE_ADJUST.o         	\
        module_NONHY_DYNAM.o         	\
        module_PHYSICS_CALLS.o       	\
        module_MPP.o                    \
        module_MPPINIT.o        	\
        module_TIMERS.o                 \
        module_ZEROX.o                  \
        module_si_io_nmm.o              \
        module_initialize_real.o        \
	$(CASE_MODULE)

#        module_INDX.o                   \

# possible CASE_MODULE settings
#	module_initialize_nmm.o        

DYN_OBJS    = 		          	\
	read_nmm.o			\
	init_modules_nmm.o  		\
	start_domain_nmm.o  		\
	solve_nmm.o         		\
	RDTEMP.o    			\
	BUCKETS.o 			\
	CLTEND.o

# DEPENDENCIES : only dependencies after this line (don't remove the word DEPENDENCIES)

solve_nmm.o:   module_BC_NMM.o \
               module_IGWAVE_ADJUST.o module_ADVECTION.o  \
               module_NONHY_DYNAM.o module_DIFFUSION_NMM.o    \
               module_BNDRY_COND.o module_PHYSICS_CALLS.o \
               module_CTLBLK.o

module_ADVECTION.o: module_MPP.o module_INDX.o

module_MPPINIT.o: module_MPP.o 

module_DIFFUSION_NMM.o: module_MPP.o module_INDX.o

module_IGWAVE_ADJUST.o: module_MPP.o module_INDX.o module_ZEROX.o module_TIMERS.o

module_PHYSICS_CALLS.o: \
		../frame/module_domain.o		\
		../frame/module_dm.o		\
		../frame/module_configure.o		\
		../frame/module_tiles.o		\
		../frame/module_state_description.o		\
		../share/module_model_constants.o		\
		../phys/module_ra_gfdleta.o  \
		../phys/module_radiation_driver.o  \
		../phys/module_sf_myjsfc.o  \
		../phys/module_surface_driver.o  \
		../phys/module_pbl_driver.o  \
		../phys/module_cu_bmj.o  \
		../phys/module_cumulus_driver.o  \
		../phys/module_mp_etanew.o  \
		../phys/module_microphysics_driver.o

# DO NOT DELETE
