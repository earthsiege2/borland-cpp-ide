//Converting header file...
//----------------------------------------------------------------------------
#ifndef AboutHPP
#define AboutHPP
//----------------------------------------------------------------------------
#include <Windows.hpp>
#include <Classes.hpp>
#include <Graphics.hpp>
#include <Forms.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <SysUtils.hpp>

//-- type declarations -------------------------------------------------------
class TAboutBox : public TForm
{

__published:
	TButton *OKButton;
	TPanel *Panel1;
	TImage *ProgramIcon;
	TLabel *ProgramName;
	TLabel *Copyright;
	void __fastcall FormCreate(TObject *Sender);


public:
	__fastcall  virtual TAboutBox::TAboutBox(TComponent *Owner);
};

//-- var, const, procedure ---------------------------------------------------
extern void __fastcall ShowAboutBox(void);
//-- end unit ----------------------------------------------------------------
#endif	// About

