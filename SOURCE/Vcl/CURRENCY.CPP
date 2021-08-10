#include  <system.hpp>
#include  <sysutils.hpp>

//#pragma inline

#ifdef near
#undef near
#endif

namespace System
{
  __fastcall Currency::Currency(const AnsiString& src)
  {
    *this = Sysutils::StrToCurr(src);
  }

  __fastcall Currency::operator AnsiString() const
  {
    return CurrToStr(*this);
  }

#ifdef USE_VCLHLPR_PAS
  #pragma argsused
  void __fastcall VarClear(Variant& v)
  {
    asm
    {
      extrn   @System@@VarClear$qqrr14System@Variant:near
      call    @System@@VarClear$qqrr14System@Variant
    }
  }

  #pragma argsused
  void __fastcall VarCast(Variant &dest, const Variant& source, int type)
  {
    // XXX 97.05.01: what about a cast where lhs is OleVariant? Do we support OleVariant?
    asm
    {
      extrn   @System@@VarCast$qqrr14System@Variantrx14System@Varianti:near
      call    @System@@VarCast$qqrr14System@Variantrx14System@Varianti
    }
  }

  #pragma argsused
  void __fastcall VarArrayRedim(Variant& a, int high)
  {
    asm
    {
      extrn   @System@@VarArrayRedim$qqrr14System@Varianti:near
      call    @System@@VarArrayRedim$qqrr14System@Varianti
    }
  }
#endif // USE_VCLHLPR_PAS
}
