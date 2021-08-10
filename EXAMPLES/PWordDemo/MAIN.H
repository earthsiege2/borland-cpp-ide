//---------------------------------------------------------------------------
#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Db.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <OleServer.hpp>
#include "Word_2K_SRVR.h"
#include <DB.hpp>
//---------------------------------------------------------------------------
class TPWordForm : public TForm
{
__published:	// IDE-managed Components
        TDBGrid *DBGrid;
        TDBNavigator *DBNavigator;
        TDBImage *DBImgFishImg;
        TButton *BtnInsertRecord;
        TCheckBox *ChkBoxNewDoc;
        TGroupBox *GroupBox;
        TLabel *lblFont;
        TLabel *lblFontSize;
        TListBox *Fonttype;
        TCheckBox *ChkBoxEmboss;
        TCheckBox *ChkBoxItalic;
        TCheckBox *ChkBoxBold;
        TCheckBox *ChkBoxUnderline;
        TCheckBox *ChkBoxEngrave;
        TCheckBox *ChkBoxShadow;
        TCheckBox *ChkBoxDoublestrike;
        TCheckBox *ChkBoxStrike;
        TEdit *Size;
        TButton *btnCloseWord;
        TButton *btnPrint;
        TButton *btnPreview;
        TGroupBox *GroupBox2;
        TListBox *lbDocs;
        TDataSource *DataSource;
        TWordDocument *WordDocument;
        TTable *Table;
        TWordApplication *WordApplication;
        TWordFont *WordFont;
        void __fastcall btnCloseWordClick(TObject *Sender);
        void __fastcall btnPrintClick(TObject *Sender);
        void __fastcall btnPreviewClick(TObject *Sender);
        void __fastcall BtnInsertRecordClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall WordApplicationDocumentChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TPWordForm(TComponent* Owner);
        void SetFont();        
};
//---------------------------------------------------------------------------
extern PACKAGE TPWordForm *PWordForm;
//---------------------------------------------------------------------------
#endif
