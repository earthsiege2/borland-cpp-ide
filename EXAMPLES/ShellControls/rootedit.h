//---------------------------------------------------------------------------

#ifndef RootEditH
#define RootEditH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <DesignEditors.hpp>
#include <DesignIntf.hpp>
//---------------------------------------------------------------------------
class TRootPathEditDlg : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TComboBox *cbFolderType;
        TRadioButton *rbUseFolder;
        TGroupBox *GroupBox2;
        TEdit *ePath;
        TRadioButton *rbUsePath;
        TButton *btnBrowse;
        TOpenDialog *OpenDialog1;
        TButton *Button1;
        TButton *Button2;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall rbUseFolderClick(TObject *Sender);
        void __fastcall rbUsePathClick(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall btnBrowseClick(TObject *Sender);
private:	// User declarations

public:		// User declarations
        void __fastcall UpdateState(void);
        __fastcall TRootPathEditDlg(TComponent* Owner);
};

class TRootProperty: public Designeditors::TStringProperty
{
public:
    void __fastcall Edit(void);
    TPropertyAttributes __fastcall GetAttributes(void);
};

class TRootEditor: public TComponentEditor
{
public:
    void __fastcall ExecuteVerb(int Index);
    String __fastcall GetVerb(int Index);
    int __fastcall GetVerbCount(void);
};

//---------------------------------------------------------------------------
extern PACKAGE TRootPathEditDlg *RootPathEditDlg;
//---------------------------------------------------------------------------
#endif
