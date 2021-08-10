//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
#ifndef AboutHPP
#define AboutHPP
//----------------------------------------------------------------------------
#ifndef ExtCtrlsHPP
#include <ExtCtrls.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Graphics.hpp>
#endif

#ifndef StdCtrlsHPP
#include <StdCtrls.hpp>
#endif

#ifndef DialogsHPP
#include <Dialogs.hpp>
#endif

#ifndef FormsHPP
#include <Forms.hpp>
#endif

#ifndef ControlsHPP
#include <Controls.hpp>
#endif

#ifndef GraphicsHPP
#include <Graphics.hpp>
#endif

#ifndef ClassesHPP
#include <Classes.hpp>
#endif

#ifndef SysUtilsHPP
#include <SysUtils.hpp>
#endif

#ifndef MessagesHPP
#include <Messages.hpp>
#endif

#ifndef WindowsHPP
#include <Windows.hpp>
#endif

#ifndef SystemHPP
#include <System.hpp>
#endif

//-- type declarations -------------------------------------------------------
class __declspec(delphiclass) TfmAboutBox;
class TfmAboutBox : public TForm
{
	typedef TfmAboutBox ThisClass;
	typedef TForm inherited;
	
__published:
	TPanel *Panel1;
	TImage *ProgramIcon;
	TLabel *ProductName;
	TLabel *Version;
	TMemo *Memo1;
	TButton *OKButton;

public:
	__fastcall virtual TfmAboutBox(TComponent*);
};

//-- var, const, procedure ---------------------------------------------------
extern TfmAboutBox *fmAboutBox;
//-- end unit ----------------------------------------------------------------
#endif	// About
