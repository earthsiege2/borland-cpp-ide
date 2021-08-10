#ifndef _VCLHLPR2_H_
#define _VCLHLPR2_H_

//
// class Vclhlpr contains static methods that are (generally) aliases to
// the helper routines in the pascal system unit that are not directly
// callable due to their symbol name.  A class with explicit friends was
// used instead of a namespace so that the users of these routines can
// be easily found.  The naming convention is to use the same name as in
// the system unit, without the leading _.
//
class Vclhlpr {
  friend class Variant;
  static void __fastcall VarCopy(System::Variant& dst, const System::Variant& src);
  static void __fastcall VarAdd(System::Variant& dst, const System::Variant& src);
  static void __fastcall VarSub(System::Variant& dst, const System::Variant& src);
  static void __fastcall VarMul(System::Variant& dst, const System::Variant& src);
  static void __fastcall VarDiv(System::Variant& dst, const System::Variant& src);
  static void __fastcall VarMod(System::Variant& dst, const System::Variant& src);
  static void __fastcall VarShl(System::Variant& dst, const System::Variant& src);
  static void __fastcall VarShr(System::Variant& dst, const System::Variant& src);
  static void __fastcall VarAnd(System::Variant& dst, const System::Variant& src);
  static void __fastcall VarOr(System::Variant& dst, const System::Variant& src);
  static void __fastcall VarXor(System::Variant& dst, const System::Variant& src);
  static int __fastcall VarCmp(const System::Variant&, const System::Variant &);
  static void __fastcall VarCmpSys(const System::Variant&, const System::Variant &);
  static void __fastcall VarNot(System::Variant&);
  static void __fastcall VarNeg(System::Variant&);
  static System::Variant __cdecl VarArrayGet(const System::Variant& src, int IndexCount, ...);
  static void __cdecl VarArrayPut(System::Variant& dst, System::Variant const &src, int IndexCount, ...);
};

namespace System {
  // for backwards compatibility, these are accessible to everyone.
  extern void __fastcall VarClear(System::Variant&);
  extern void __fastcall VarCast(System::Variant&, const System::Variant&, int);
  extern void __fastcall VarArrayRedim(System::Variant&, int);
};

#endif
