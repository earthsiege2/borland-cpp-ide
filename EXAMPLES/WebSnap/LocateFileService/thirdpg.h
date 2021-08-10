
//---------------------------------------------------------------------------

#ifndef ThirdPgH
#define ThirdPgH
//---------------------------------------------------------------------------
#include <WebInit.h>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <WebModu.hpp>
#include <HTTPProd.hpp>
#include <HTTPApp.hpp>

//---------------------------------------------------------------------------
class TThirdPage : public TWebPageModule
{
__published:	// IDE-managed Components
	TPageProducer *PageProducer;
private:	// User declarations
public:		// User declarations
};

TThirdPage *ThirdPage();

//---------------------------------------------------------------------------
extern PACKAGE TThirdPage *ThirdPage();
//---------------------------------------------------------------------------
#endif

