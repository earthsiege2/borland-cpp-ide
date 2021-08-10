
//---------------------------------------------------------------------------

#ifndef SecondPgH
#define SecondPgH
//---------------------------------------------------------------------------
#include <WebInit.h>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <WebModu.hpp>
#include <HTTPProd.hpp>
#include <HTTPApp.hpp>

//---------------------------------------------------------------------------
class TSecondPage : public TWebPageModule
{
__published:	// IDE-managed Components
	TPageProducer *PageProducer;
private:	// User declarations
public:		// User declarations
};

TSecondPage *SecondPage();

//---------------------------------------------------------------------------
extern PACKAGE TSecondPage *SecondPage();
//---------------------------------------------------------------------------
#endif

