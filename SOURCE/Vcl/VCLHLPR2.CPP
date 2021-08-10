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
void __fastcall Vclhlpr::VarDiv(System::Variant& dst,  System::Variant src) {}
void __fastcall Vclhlpr::VarMod(System::Variant& dst, const System::Variant& src) {}
void __fastcall Vclhlpr::VarShl(System::Variant& dst, const System::Variant& src) {}
void __fastcall Vclhlpr::VarShr(System::Variant& dst, const System::Variant& src) {}
void __fastcall Vclhlpr::VarAnd(System::Variant& dst, const System::Variant& src) {}
void __fastcall Vclhlpr::VarOr(System::Variant& dst, const System::Variant& src) {}
void __fastcall Vclhlpr::VarXor(System::Variant& dst, const System::Variant& src) {}
void __fastcall VarCmpSysEQ(const System::Variant&, const System::Variant &) { }
void __fastcall VarCmpSysLT(const System::Variant&, const System::Variant &) { }
void __fastcall VarCmpSysGT(const System::Variant&, const System::Variant &) { }
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
        = "@System@@VarAdd$qqrr14System@Variantrx14System@Variant"

#pragma alias "@Vclhlpr@VarSub$qqrr14System@Variantrx14System@Variant" \
        = "@System@@VarSub$qqrr14System@Variantrx14System@Variant"

#pragma alias "@Vclhlpr@VarMul$qqrr14System@Variantrx14System@Variant" \
        = "@System@@VarMul$qqrr14System@Variantrx14System@Variant"

#pragma alias "@Vclhlpr@VarDiv$qqrr14System@Variantrx14System@Variant" \
        = "@System@@VarDiv$qqrr14System@Variantrx14System@Variant"

#pragma alias "@Vclhlpr@VarMod$qqrr14System@Variantrx14System@Variant" \
        = "@System@@VarMod$qqrr14System@Variantrx14System@Variant"

#pragma alias "@Vclhlpr@VarShl$qqrr14System@Variantrx14System@Variant" \
        = "@System@@VarShl$qqrr14System@Variantrx14System@Variant"

#pragma alias "@Vclhlpr@VarShr$qqrr14System@Variantrx14System@Variant" \
        = "@System@@VarShr$qqrr14System@Variantrx14System@Variant"

#pragma alias "@Vclhlpr@VarAnd$qqrr14System@Variantrx14System@Variant" \
        = "@System@@VarAnd$qqrr14System@Variantrx14System@Variant"

#pragma alias "@Vclhlpr@VarOr$qqrr14System@Variantrx14System@Variant" \
        = "@System@@VarOr$qqrr14System@Variantrx14System@Variant"

#pragma alias "@Vclhlpr@VarXor$qqrr14System@Variantrx14System@Variant" \
        = "@System@@VarXor$qqrr14System@Variantrx14System@Variant"

#pragma alias "@Vclhlpr@VarCmpSysEQ$qqrrx14System@Variantt1" \
        = "@System@@VarCmpEQ$qqrrx14System@Variantt1"

#pragma alias "@Vclhlpr@VarCmpSysLT$qqrrx14System@Variantt1" \
        = "@System@@VarCmpLT$qqrrx14System@Variantt1"

#pragma alias "@Vclhlpr@VarCmpSysGT$qqrrx14System@Variantt1" \
        = "@System@@VarCmpGT$qqrrx14System@Variantt1"

#pragma alias "@Vclhlpr@VarNot$qqrr14System@Variant" \
        = "@System@@VarNot$qqrr14System@Variant"

#pragma alias "@Vclhlpr@VarNeg$qqrr14System@Variant" \
        = "@System@@VarNeg$qqrr14System@Variant"

#pragma alias "@Vclhlpr@VarArrayGet$qrx14System@Variantie" \
        = "@System@@VarArrayGet$qr14System@Variantii"

#pragma alias "@Vclhlpr@VarArrayPut$qr14System@Variantrx14System@Variantie" \
        = "@System@@VarArrayPut$qr14System@Variantrx14System@Variantii"

#pragma alias "@System@VarClear$qqrr14System@Variant" \
        = "@System@@VarClear$qqrr14System@Variant"

#pragma alias "@Variants@VarCast$qqrr14System@Variantrx14System@Varianti" \
        = "@System@@VarCast$qqrr14System@Variantrx14System@Varianti"

#pragma alias "@System@VarArrayRedim$qqrr14System@Varianti" \
        = "@System@@VarArrayRedim$qqrr14System@Varianti"

#pragma alias "@Variants@VarArrayRedim$qqrr14System@Varianti" \
        = "@System@@VarArrayRedim$qqrr14System@Varianti"

#endif // VCLHLPR_GENSYMS


int __fastcall
Vclhlpr::VarCmp(const System::Variant &x, const System::Variant &y, int Op)
{
  // VarCmpSysnn sets EFLAGS after the compare, so we'll convert things to
  // the more normal [-1, 0, 1]
  if (Op == 0)
    VarCmpSysEQ(x, y);
  else if (Op > 0)
    VarCmpSysGT(x, y);
  else
    VarCmpSysLT(x, y);

  const EFL_CARRY = 1UL << 0;
  const EFL_ZERO  = 1UL << 6;

  if (_FLAGS & EFL_ZERO)
    return 0;
  else if (_FLAGS & EFL_CARRY)
    return -1;
  else
    return 1;
}
