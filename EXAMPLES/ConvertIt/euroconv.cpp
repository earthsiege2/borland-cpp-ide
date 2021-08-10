//----------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <ConvUtils.hpp> // Pascal unit
#include "EuroConv.h"
//---------------------------------------------------------------------------

using namespace Euroconv;

// Registration methods
Convutils::TConvType __fastcall RegisterEuroConversionType(
  const Convutils::TConvFamily AFamily,
  const AnsiString ADescription,
  const double AFactor,
  const Math::TRoundToRange ARound) /* overload */
{

  TConvTypeEuroFactor* LInfo =  new TConvTypeEuroFactor(AFamily, ADescription, AFactor, ARound);
  TConvType Result;
  if ( !RegisterConversionType(LInfo, Result) )
  {
    delete LInfo;
    RaiseConversionRegError(AFamily, ADescription);
  }
  return Result;
}

Convutils::TConvType __fastcall RegisterEuroConversionType(
  const Convutils::TConvFamily AFamily,
  const AnsiString ADescription,
  const Convutils::TConversionProc AToCommonProc,
  const Convutils::TConversionProc AFromCommonProc)/* overload */
{
  return RegisterConversionType(AFamily, ADescription, AToCommonProc, AFromCommonProc);
}

// TConvTypeEuroFactor
__fastcall TConvTypeEuroFactor::TConvTypeEuroFactor(
  const Convutils::TConvFamily AConvFamily,
  const AnsiString ADescription,
  const double AFactor,
  const Math::TRoundToRange ARound) : Convutils::TConvTypeFactor(AConvFamily, ADescription, AFactor)
{
  FRound = ARound;
}

double __fastcall TConvTypeEuroFactor::FromCommon(const double AValue)
{
  return SimpleRoundTo(AValue*Factor, FRound);
}

double __fastcall TConvTypeEuroFactor::ToCommon(const double AValue)
{
  return AValue/Factor;
}

// Internal conversion utilities
double __fastcall ConvertUSDToEUR(const double AValue)
{
  return AValue*USDToEUR;
}

double __fastcall ConvertEURToUSD(const double AValue)
{
  return SimpleRoundTo(AValue/USDToEUR, USDSubUnit);
}

double __fastcall ConvertGBPToEUR(const double AValue)
{
  return  AValue*GBPToEUR;
}

double __fastcall ConvertEURToGBP(const double AValue)
{
  return SimpleRoundTo(AValue/GBPToEUR, GBPSubUnit);
}

double __fastcall ConvertJPYToEUR(const double AValue)
{
  return AValue*JPYToEUR;
}

double __fastcall ConvertEURToJPY(const double AValue)
{
  return SimpleRoundTo(AValue/JPYToEUR, JPYSubUnit);
}

void InitializeUnit(void)
{
  // Register all the conversion types.
  // Euro's family type
  cbEuro = RegisterConversionFamily(SEuroDescription);
  // Euro's various conversion types
  euEUR = RegisterEuroConversionType(cbEuro, SEURDescription, EURToEURO, EURSubUnit);
  euBEF = RegisterEuroConversionType(cbEuro, SBEFDescription, BEFToEURO, BEFSubUnit);
  euDEM = RegisterEuroConversionType(cbEuro, SDEMDescription, DEMToEURO, DEMSubUnit);
  euGRD = RegisterEuroConversionType(cbEuro, SGRDDescription, GRDToEURO, GRDSubUnit);
  euESP = RegisterEuroConversionType(cbEuro, SESPDescription, ESPToEURO, ESPSubUnit);
  euFFR = RegisterEuroConversionType(cbEuro, SFFRDescription, FFRToEURO, FFRSubUnit);
  euIEP = RegisterEuroConversionType(cbEuro, SIEPDescription, IEPToEURO, IEPSubUnit);
  euITL = RegisterEuroConversionType(cbEuro, SITLDescription, ITLToEURO, ITLSubUnit);
  euLUF = RegisterEuroConversionType(cbEuro, SLUFDescription, LUFToEURO, LUFSubUnit);
  euNLG = RegisterEuroConversionType(cbEuro, SNLGDescription, NLGToEURO, NLGSubUnit);
  euATS = RegisterEuroConversionType(cbEuro, SATSDescription, ATSToEURO, ATSSubUnit);
  euPTE = RegisterEuroConversionType(cbEuro, SPTEDescription, PTEToEURO, PTESubUnit);
  euFIM = RegisterEuroConversionType(cbEuro, SFIMDescription, FIMToEURO, FIMSubUnit);
  euUSD = RegisterEuroConversionType(cbEuro, SUSDDescription,*ConvertUSDToEUR, *ConvertEURToUSD);
  euGBP = RegisterEuroConversionType(cbEuro, SGBPDescription,*ConvertGBPToEUR, *ConvertEURToGBP);
  euJPY = RegisterEuroConversionType(cbEuro, SJPYDescription,*ConvertJPYToEUR, *ConvertEURToJPY);
}

void FinalizeUnit(void)
{
  // Unregister all the conversion types we are responsible for.
  UnregisterConversionFamily(cbEuro);
}

#pragma Startup InitializeUnit 64
#pragma Exit FinalizeUnit 64
