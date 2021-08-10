/*******************************************************************************
  Monetary conversion units

  The constants, names and monetary logic in this unit follow the various EU
  standards layed out in documents 397R1103, 398R2866 and 300R1478.

  WARNING: In order for the rounding rules to exactly match the EU dictates
           this unit will adjust your application's rounding mode to rmUp.
           This will affect how rounding happens globally and may cause
           unforeseen side effects in your application.

  At the time of the writing of this document those documents where at
    http://europa.eu.int/eur-lex/en/lif/dat/1997/en_397R1103.html
    http://europa.eu.int/eur-lex/en/lif/dat/1998/en_398R2866.html
    http://europa.eu.int/eur-lex/en/lif/dat/2000/en_300R1478.html

  If not found there you can search for them on http://europa.eu.int/eur-lex

  The conversion rates for US dollar, British pound and Japanese yen are
  accurate as of 12/12/2000 at 18:35 EST and were as reported by
  CNNfn (http://cnnfn.cnn.com/markets/currency)

  Great monetary exchange rate sites
    http://pacific.commerce.ubc.ca/xr/rates.html
    http://www.imf.org/external/np/tre/sdr/drates/8101.htm
    http://www.belgraver.demon.nl/currconv2/

  ____________________________________________________________________________
  References:
  [1] Article 1 in http://europa.eu.int/eur-lex/en/lif/dat/1998/en_398R2866.html
  [2] Article 1 in http://europa.eu.int/eur-lex/en/lif/dat/2000/en_300R1478.html
  [3] Article 4.4 in http://europa.eu.int/eur-lex/en/lif/dat/1997/en_397R1103.html

*******************************************************************************/

//----------------------------------------------------------------------------
#ifndef EuroConvH
#define EuroConvH
//----------------------------------------------------------------------------

namespace Euroconv
{
// Euro Conversion Units
// basic unit of measurement is euro
// Fixed conversion Euro rates [1]

static const Extended EURToEURO = 1.00000;
static const Extended BEFToEURO = 40.3399;
static const Extended DEMToEURO = 1.95583;
static const Extended GRDToEURO = 340.750; // [2] effective 1/1/2001
static const Extended ESPToEURO = 166.386;
static const Extended FFRToEURO = 6.55957;
static const Extended IEPToEURO = 0.787564;
static const Extended ITLToEURO = 1936.27;
static const Extended LUFToEURO = 40.3399;
static const Extended NLGToEURO = 2.20371;
static const Extended ATSToEURO = 13.7603;
static const Extended PTEToEURO = 200.482;
static const Extended FIMToEURO = 5.94573;

// Subunit rounding for Euro conversion and expressed as powers of ten [3]
static const Shortint EURSubUnit = -2;
static const Shortint BEFSubUnit =  0;
static const Shortint DEMSubUnit = -2;
static const Shortint GRDSubUnit =  0; // [2] effective 1/1/2001
static const Shortint ESPSubUnit =  0;
static const Shortint FFRSubUnit = -2;
static const Shortint IEPSubUnit = -2;
static const Shortint ITLSubUnit =  0;
static const Shortint LUFSubUnit = -2;
static const Shortint NLGSubUnit = -2;
static const Shortint ATSSubUnit = -2;
static const Shortint PTESubUnit = -2;
static const Shortint FIMSubUnit =  0;

// Accurate as of 12/12/2000 at 16:42 PST but almost certainly isn't anymore
// Remember if you are changing these values in realtime you might, depending
//  on your application's structure, have to deal with threading issues.
static double USDToEUR = 1.1369;
static double GBPToEUR = 1.6462;
static double JPYToEUR = 0.0102;

// Subunit rounding for Euro conversion and expressed as powers of ten
static int USDSubUnit = -2;
static int GBPSubUnit = -2;
static int JPYSubUnit = -2;

// Various strings used in this unit
static const String SEuroDescription = "Euro";
static const String SEURDescription = "EUEuro";
static const String SBEFDescription = "BelgianFrancs";
static const String SDEMDescription = "GermanMarks";
static const String SGRDDescription = "GreekDrachmas";
static const String SESPDescription = "SpanishPesetas";
static const String SFFRDescription = "FrenchFrancs";
static const String SIEPDescription = "IrishPounds";
static const String SITLDescription = "ItalianLire";
static const String SLUFDescription = "LuxembourgFrancs";
static const String SNLGDescription = "DutchGuilders";
static const String SATSDescription = "AustrianSchillings";
static const String SPTEDescription = "PortugueseEscudos";
static const String SFIMDescription = "FinnishMarks";
static const String SUSDDescription = "USDollars";
static const String SGBPDescription = "BritishPounds";
static const String SJPYDescription = "JapaneseYens";

static TConvFamily cbEuro;

static TConvType euEUR;    // EU euro
static TConvType euBEF;    // Belgian francs
static TConvType euDEM;    // German marks
static TConvType euGRD;    // Greek drachmas
static TConvType euESP;    // Spanish pesetas
static TConvType euFFR;    // French francs
static TConvType euIEP;    // Irish pounds
static TConvType euITL;    // Italian lire
static TConvType euLUF;    // Luxembourg francs
static TConvType euNLG;    // Dutch guilders
static TConvType euATS;    // Austrian schillings
static TConvType euPTE;    // Portuguese escudos
static TConvType euFIM;    // Finnish marks

static TConvType euUSD;    // US dollars
static TConvType euGBP;    // British pounds
static TConvType euJPY;    // Japanese yens

void InitializeUnit();
void FinalizeUnit();

class DELPHICLASS Convutils::TConvTypeFactor;
class TConvTypeEuroFactor : public Convutils::TConvTypeFactor
{
private:
  Math::TRoundToRange FRound;
public:
  __fastcall TConvTypeEuroFactor(const Convutils::TConvFamily AConvFamily,
    const AnsiString ADescription,
    const double AFactor,
    const Math::TRoundToRange ARound);

  virtual double __fastcall ToCommon(const double AValue);
  virtual double __fastcall FromCommon(const double AValue);
};

} /* namespace Euroconv */

#endif
