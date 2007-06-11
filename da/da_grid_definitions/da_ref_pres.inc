subroutine da_ref_pres(height, ref_pres)

   !---------------------------------------------------------------------------
   ! Purpose: To calculate the reference pressure from the height.
   !---------------------------------------------------------------------------

   implicit none

   real, intent(in)  :: height
   real, intent(out) :: ref_pres

   real, parameter :: rovg = gas_constant/gravity

   real :: aa, bb, cc, hh, htop, ziso, p0iso

   call da_ref_height(ptop, htop)

   bb = rovg * t0
   aa = rovg * base_lapse * 0.5

   hh = min(htop, height)
   cc = (-bb + sqrt(bb * bb - 4.0 * aa * hh))/(2.0*aa)
   ref_pres = base_pres * exp(cc)

   if (base_temp > 0.0) then
      p0iso=base_pres*exp((base_temp-t0)/base_lapse)
      cc=log(p0iso/base_pres)
      ziso=-(aa*cc+bb)*cc

      if (height > ziso) then
         ref_pres = p0iso/exp((height-ziso)/(rovg*base_temp))
      end if
   end if

end subroutine da_ref_pres

