
//---------------------------------------------------------------------------

#ifndef DumpModulesPgH
#define DumpModulesPgH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <WebModu.hpp>
#include <HTTPProd.hpp>
#include <HTTPApp.hpp>

//---------------------------------------------------------------------------
class TDumpModulesPage : public TWebPageModule
{
__published:	// IDE-managed Components
	TPageProducer *PageProducer;
private:	// User declarations
public:		// User declarations
};

TDumpModulesPage *DumpModulesPage();

//---------------------------------------------------------------------------
extern PACKAGE TDumpModulesPage *DumpModulesPage();
//---------------------------------------------------------------------------
#endif

