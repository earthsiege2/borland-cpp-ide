#include <vcl.h>
#include "vclhlpr2.h"

//
// This file contains the implementations of the static members of
// Vclhlpr.  There are three parts to this header:
//
// 1) dummy definitions.  when VCLHLPR_GENSYMS is defined, there are
// "no-op" definitions for the static members that will be mapped
// directly into the pascal rtl.  after compiling, "tdump -m -oicomdef: vclhlpr2.obj"
// will dump out the mangled versions of each of these functions.
//
// 2) alias records that map the members of Vclhlpr to routines in the
// pascal rtl.  the pascal manglings are maintained by hand.  this
// section is the "#else" part of the above "#ifdef VCLHLPR_GENSYMS"
//
// 3) methods that are implemented in C++.
//


#ifdef VCLHLPR_GENSYMS
void __fastcall Vclhlpr::VarCopy(System::Variant& dst, const System::Variant& src) {} 
void __fastcall Vclhlpr::VarAdd(System::Variant& dst, const System::Variant& src) {}
void __fastcall Vclhlpr::VarSub(System::Variant& dst, const System::Variant& src) {}
void __fastcall Vclhlpr::VarMul(System::Variant& dst, const System::Variant& src) {}
void __fastcall Vclhlpr::VarDiv(System::Variant& dst, const System::Variant& src) {}
void __fastcall Vclhlpr::VarMod(System::Variant& dst, const System::Variant& src) {}
void __fastcall Vclhlpr::VarShl(System::Variant& dst, const System::Variant& src) {}
void __fastcall Vclhlpr::VarShr(System::Variant& dst, const System::Variant& src) {}
void __fastcall Vclhlpr::VarAnd(System::Variant& dst, const System::Variant& src) {}
void __fastcall Vclhlpr::VarOr(System::Variant& dst, const System::Variant& src) {}
void __fastcall Vclhlpr::VarXor(System::Variant& dst, const System::Variant& src) {}
void __fastcall VarCmpSys(const System::Variant&, const System::Variant &) { }
void __fastcall Vclhlpr::VarNot(System::Variant&) {}
void __fastcall Vclhlpr::VarNeg(System::Variant&) {}
System::Variant __cdecl Vclhlpr::VarArrayGet(const System::Variant&, int IndexCount, ...) {}
void __cdecl Vclhlpr::VarArrayPut(System::Variant&, const System::Variant &, int IndexCount, ...) {}
void __fastcall Vclhlpr::VarClear(System::Variant&) {}
void __fastcall Vclhlpr::VarCast(System::Variant&, const System::Variant&, int) {}
void __fastcall Vclhlpr::VarArrayRedim(System::Variant&, int) {}

#else

#pragma alias "@Vclhlpr@VarCopy$qqrr14System@Variantrx14System@Variant" \
        = "@System@@VarCopy$qqrr14System@Variantrx14System@Variant"

#pragma alias "@Vclhlpr@VarAdd$qqrr14System@Variantrx14System@Variant"  \
        = "@System@@VarAdd$qqrv"

#pragma alias "@Vclhlpr@VarSub$qqrr14System@Variantrx14System@Variant" \
        = "@System@@VarSub$qqrv"

#pragma alias "@Vclhlpr@VarMul$qqrr14System@Variantrx14System@Variant" \
        = "@System@@VarMul$qqrv"

#pragma alias "@Vclhlpr@VarDiv$qqrr14System@Variantrx14System@Variant" \
        = "@System@@VarDiv$qqrv"

#pragma alias "@Vclhlpr@VarMod$qqrr14System@Variantrx14System@Variant" \
        = "@System@@VarMod$qqrv"

#pragma alias "@Vclhlpr@VarShl$qqrr14System@Variantrx14System@Variant" \
        = "@System@@VarShl$qqrv"

#pragma alias "@Vclhlpr@VarShr$qqrr14System@Variantrx14System@Variant" \
        = "@System@@VarShr$qqrv"

#pragma alias "@Vclhlpr@VarAnd$qqrr14System@Variantrx14System@Variant" \
        = "@System@@VarAnd$qqrv"

#pragma alias "@Vclhlpr@VarOr$qqrr14System@Variantrx14System@Variant" \
        = "@System@@VarOr$qqrv"

#pragma alias "@Vclhlpr@VarXor$qqrr14System@Variantrx14System@Variant" \
        = "@System@@VarXor$qqrv"

#pragma alias "@Vclhlpr@VarCmpSys$qqrrx14System@Variantt1" \
        = "@System@@VarCmp$qqrv"

#pragma alias "@Vclhlpr@VarNot$qqrr14System@Variant" \
        = "@System@@VarNot$qqrv"

#pragma alias "@Vclhlpr@VarNeg$qqrr14System@Variant" \
        = "@System@@VarNeg$qqrv"

#pragma alias "@Vclhlpr@VarArrayGet$qrx14System@Variantie" \
        = "@System@@VarArrayGet$qr14System@Variantii"

#pragma alias "@Vclhlpr@VarArrayPut$qr14System@Variantrx14System@Variantie" \
        = "@System@@VarArrayPut$qr14System@Variantrx14System@Variantii"

#pragma alias "@System@VarClear$qqrr14System@Variant" \
        = "@System@@VarClear$qqrr14System@Variant"

#pragma alias "@System@VarCast$qqrr14System@Variantrx14System@Varianti" \
        = "@System@@VarCast$qqrr14System@Variantrx14System@Varianti"

#pragma alias "@System@VarArrayRedim$qqrr14System@Varianti" \
        = "@System@@VarArrayRedim$qqrr14System@Varianti"

#endif // VCLHLPR_GENSYMS


int __fastcall
Vclhlpr::VarCmp(const System::Variant &x, const System::Variant &y)
{
  const EFL_ZERO     = 1UL << 6;
  const EFL_SIGN     = 1UL << 7;
  const EFL_OVERFLOW = 1UL << 11;

  // VarCmpSys sets EFLAGS after the compare, so we'll convert things to
  // the more normal [-1, 0, 1]
  // careful! mustn't be silly and corrupt EFLAGS whilst testing it.
  VarCmpSys(x, y);
  unsigned flags = _FLAGS;
  if (flags & EFL_ZERO)
    return 0;
  else if (!!(flags & EFL_SIGN) != !!(flags & EFL_OVERFLOW))
    return -1;
  else
    return 1;
}
