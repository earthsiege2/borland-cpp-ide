//Converting header file...
//----------------------------------------------------------------------------
#ifndef TrcViewHPP
#define TrcViewHPP
//----------------------------------------------------------------------------
#include <StdCtrls.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Dialogs.hpp>
#include <Forms.hpp>
#include <Controls.hpp>
#include <Graphics.hpp>
#include <Classes.hpp>
#include <SysUtils.hpp>
#include <Messages.hpp>
#include <Windows.hpp>
#include <System.hpp>

//-- type declarations -------------------------------------------------------
class TTraceForm : public TForm
{
	
__published:
	TListBox *TraceData;
	void __fastcall TraceDataKeyPress(TObject *Sender, Char &Key);

		
	
public:
	__fastcall  virtual TTraceForm::TTraceForm(TComponent *Owner) ;

};

//-- var, const, procedure ---------------------------------------------------
extern TTraceForm *TraceForm;
//-- end unit ----------------------------------------------------------------
#endif	// TrcView
//end conversion....
