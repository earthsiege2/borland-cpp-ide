//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1996 by Borland International
//   calldemo.cpp
//
//----------------------------------------------------------------------------

#include <owl/applicat.h>
#include <owl/framewin.h>
#include <owl/dialog.h>
#include <owl/radiobut.h>
#include <owl/groupbox.h>
#include <owl/combobox.h>
#include "calldemo.h"
#pragma hdrstop
#include "intldemo.cxx"

#define ExeProgId "Locale.Application"
TPointer<TLocaleApplication> intldemo;          // smart pointer to object representing the server application

typedef void (TLocaleWindow::*ClassFunction)(); // define pointer to member function of proxy class

const int MAX_CLASSIFICATION_NAME = 20;         // length of buffer used to load names of
																// classification functions, e.g. "isalpha()"
//
// class TIntlDemoGroup
// ----- --------------
//
// Associated with group boxes which control the UI language and the
// locale used by intldemo.
// 
class TIntlDemoGroup : public TGroupBox
{
	 TLocaleFrame* LocaleFrame;

  public:
	 TIntlDemoGroup(TWindow* parent, int resourceId, TLocaleFrame* localeFrame) 
						: TGroupBox(parent, resourceId) 
	 {
		LocaleFrame = localeFrame;
	 }

	 void SelectionChanged(int controlId);
};

void TIntlDemoGroup::SelectionChanged(int controlId)
{
  switch (controlId) {
	 case IDC_ENGLISH:
		LocaleFrame->EnglishLanguage();
		break;
		
	 case IDC_GERMAN:
		LocaleFrame->GermanLanguage();
		break;
		
	 case IDC_FRENCH:
		LocaleFrame->FrenchLanguage();
		break;
	 case IDC_CLOCALE:
		LocaleFrame->CLocale();
		break;
		
	 case IDC_USLOCALE:
		LocaleFrame->USLocale();
		break;
		
	 case IDC_UKLOCALE:
		LocaleFrame->UKLocale();
		break;
		
	 case IDC_FRALOCALE:
		LocaleFrame->FrenchLocale();
		break;
		
	 case IDC_GERLOCALE:
		LocaleFrame->GermanLocale();
		break;
  }
}
//
// class TCallDemoDlg
// ----- ------------
//
// Defines the dialog box which is used as the main window of the
// controller application.
//
class TCallDemoDlg : public TDialog
{
  public:
	 TCallDemoDlg(TWindow*, TResId);

  protected:
  
	 TIntlDemoGroup *Language;
	 TIntlDemoGroup *Locale;
	 
	 TRadioButton *English, *French, *German;
	 TRadioButton *CLocale, *USLocale, *UKLocale;
	 TRadioButton *FraLocale, *GerLocale;
	 TComboBox* Classification;

	 TLocaleFrame LocaleFrame;
	 TLocaleWindow LocaleWindow;

	 void SetupWindow();
	 void ClassificationChange();
	 static const ClassFunction ClassificationFunctions[];
	 
	 DECLARE_RESPONSE_TABLE(TCallDemoDlg);
};

DEFINE_RESPONSE_TABLE1(TCallDemoDlg, TDialog)
  EV_CBN_SELCHANGE(IDC_CLASSIFICATION, ClassificationChange),
END_RESPONSE_TABLE;

const ClassFunction TCallDemoDlg::ClassificationFunctions[] =
  { TLocaleWindow::IsAlnum, TLocaleWindow::IsAlpha, TLocaleWindow::IsAscii, TLocaleWindow::IsCntrl,
	 TLocaleWindow::IsDigit, TLocaleWindow::IsGraph, TLocaleWindow::IsLower, TLocaleWindow::IsPrint, 
	 TLocaleWindow::IsPunct, TLocaleWindow::IsSpace, TLocaleWindow::IsUpper, TLocaleWindow::IsXDigit };

void TCallDemoDlg::SetupWindow()
{

  TDialog::SetupWindow();
  
  char buf[MAX_CLASSIFICATION_NAME];
  for (int i=IDS_ISALNUM; i<=IDS_ISXDIGIT; i++) {
	 GetApplication()->LoadString(i, buf, sizeof(buf));
	 Classification->AddString(buf);
  }
  
  English->Check();                // select English UI
  CLocale->Check();                // select C Locale
  Classification->SetSelIndex(1);  // select isalpha()
}

TCallDemoDlg::TCallDemoDlg(TWindow* parent, TResId resId)
				: TDialog(parent, resId), TWindow(parent)
{
  intldemo->GetWindow(LocaleFrame);
	 
  LocaleFrame.EnglishLanguage();   // set to English UI
  LocaleFrame.CLocale();           // set to C Locale 
  LocaleFrame.GetWindow(LocaleWindow);
  LocaleWindow.IsAlpha();          // set to isalpha()

  Language = new TIntlDemoGroup(this, IDC_LANGUAGE, &LocaleFrame);
  English = new TRadioButton(this, IDC_ENGLISH, Language);
  French = new TRadioButton(this, IDC_FRENCH, Language);
  German = new TRadioButton(this, IDC_GERMAN, Language);

  Locale = new TIntlDemoGroup(this, IDC_LOCALE, &LocaleFrame);
  CLocale = new TRadioButton(this, IDC_CLOCALE, Locale);
  USLocale = new TRadioButton(this, IDC_USLOCALE, Locale);
  UKLocale = new TRadioButton(this, IDC_UKLOCALE, Locale);
  FraLocale = new TRadioButton(this, IDC_FRALOCALE, Locale);
  GerLocale = new TRadioButton(this, IDC_GERLOCALE, Locale);

  Classification = new TComboBox(this, IDC_CLASSIFICATION);
}

void TCallDemoDlg::ClassificationChange()
{
  int sel = Classification->GetSelIndex();
  if (sel>=0)
	 (LocaleWindow.*ClassificationFunctions[sel])();
}

//
// class TCallDemoApp
// ----- ------------
//
// Application class.
//
class TCallDemoApp : public TApplication
{
  private:
	 TLocaleApplication* IntlDemo;

  public:
	 TCallDemoApp() : TApplication() { }

	 void InitMainWindow()
	 {
		TFrameWindow* frame = new TFrameWindow(0, "Call IntlDemo Program",
									 new TCallDemoDlg(0, CALLDEMODLG), true );

		SetMainWindow(frame);
		MainWindow->SetIcon(this, TResId("CONTROL"));
		MainWindow->Attr.Style &= ~(WS_MAXIMIZEBOX | WS_THICKFRAME);
	 }
};

int OwlMain(int /* argc */, char* /* argv */ [])
{
  TOleAllocator OleAloc(0);

  intldemo = new TLocaleApplication;

  try {
	 intldemo->Bind(ExeProgId);
	 TCallDemoApp().Run();
	 intldemo->Quit();
	 return 0;
  }
  catch (TXBase& x) {
	 MessageBox(0, x.why().c_str(), "Reason", MB_OK);
  }
  return -1; 
}
