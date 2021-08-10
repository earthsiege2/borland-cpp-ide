
//---------------------------------------------------------------------------

#ifndef OrderGridPgH
#define OrderGridPgH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <WebModu.hpp>
#include <HTTPProd.hpp>
#include <HTTPApp.hpp>
#include <CompProd.hpp>
#include <MidItems.hpp>
#include <PagItems.hpp>
#include <SiteProd.hpp>
#include <WebComp.hpp>
#include <WebForm.hpp>

//---------------------------------------------------------------------------
class TOrderGridPage : public TWebPageModule
{
__published:	// IDE-managed Components
  TPageProducer *PageProducer;
private:	// User declarations
public:		// User declarations
};

TOrderGridPage *OrderGridPage();

//---------------------------------------------------------------------------
extern PACKAGE TOrderGridPage *OrderGridPage();
//---------------------------------------------------------------------------
#endif

