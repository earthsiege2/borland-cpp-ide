//---------------------------------------------------------------------------
#ifndef SingleInstanceSampleUnitH
#define SingleInstanceSampleUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "SingleInstance.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TSingleAppInstance *SingleAppInstance1;
        TMemo *mCommandLines;
        TButton *btClose;
        TButton *btTest;
        TButton *btLaunchInstance;
	void __fastcall SingleAppInstance1ReceiveCommandLine(TObject *Sender,
          char *CommandLine);
	void __fastcall SingleAppInstance1SecondInstance(TObject *Sender,
          bool &ShutDown);
        void __fastcall btCloseClick(TObject *Sender);
        void __fastcall btTestClick(TObject *Sender);
        void __fastcall btLaunchInstanceClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
   __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
