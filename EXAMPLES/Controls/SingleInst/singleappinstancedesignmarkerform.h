
#ifndef SingleAppInstanceDesignMarkerFormH
#define SingleAppInstanceDesignMarkerFormH

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

class TfrmMarkerPropertyEditor : public TForm
{
__published:	// IDE-managed Components
	TButton *btOK;
	TButton *btCancel;
	TButton *btHelp;
        TComboBox *cbMarkerText;
        TLabel *lMarkerText;
	void __fastcall btOKClick(TObject *Sender);
        void __fastcall cbMarkerTextKeyPress(TObject *Sender, char &Key);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall btHelpClick(TObject *Sender);
private:	// User declarations
  AnsiString FMarkerText;
  void __fastcall SetMarkerText(const String& Value);
protected:
  virtual void __fastcall FillMarkerComboWithValues(void);
public:		// User declarations
	__fastcall TfrmMarkerPropertyEditor(TComponent* Owner);
        __property String MarkerText = { read = FMarkerText, write = SetMarkerText };
};

#endif
