//---------------------------------------------------------------------------
#ifndef ClxRecErrorH
#define ClxRecErrorH
//---------------------------------------------------------------------------

#include <SysUtils.hpp>
#include <Windows.hpp>
#include <Messages.hpp>
#include <Classes.hpp>
#include <QGraphics.hpp>
#include <QForms.hpp>
#include <QControls.hpp>
#include <QStdCtrls.hpp>
#include <QButtons.hpp>
#include <QExtCtrls.hpp>
#include <QDialogs.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
#include <DBClient.hpp>

//---------------------------------------------------------------------------
class TFieldData {
  public:
    TField     *Field;
    AnsiString  NewValue;
    AnsiString  OldValue;
    AnsiString  CurValue;
    AnsiString  EditValue;
    bool Edited;
};

//---------------------------------------------------------------------------
class TReconcileErrorForm : public TForm {
  __published:  // IDE-managed Components
    TLabel *Label1;
    TLabel *UpdateType;
    TLabel *Label3;
    TImage *IconImage;
    TStringGrid *UpdateData;
    TRadioGroup *ActionGroup;
    TButton *CancelBtn;
    TButton *OKBtn;
    TCheckBox *ConflictsOnly;
    TMemo *ErrorMsg;
    TCheckBox *ChangedOnly;
    void __fastcall DisplayFieldValues(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall UpdateDataSetEditText (TObject *Sender,
      int ACol, int ARow, const AnsiString Value);
    void __fastcall UpdateDataSelectCell(TObject *Sender, int Col, int Row,
      bool &CanSelect);
  private:  // User declarations
    int FCurColIdx, FNewColIdx, FOldColIdx;
    TList *FDataFields;
    TDataSet *FDataSet;
    TUpdateKind FUpdateKind;
    EReconcileError *FError;
    void __fastcall AdjustColumnWidths();
    void __fastcall InitDataFields();
    void __fastcall InitUpdateData(bool HasCurValues);
    void __fastcall AddAction(TReconcileAction Action);
    void __fastcall InitReconcileActions();
  public: // User declarations
    void __fastcall SetFieldValues(TDataSet *DataSet);
    __fastcall TReconcileErrorForm(TComponent* Owner);
    __fastcall TReconcileErrorForm(TComponent* Owner, TDataSet *DataSet,
      TUpdateKind UpdateKind, EReconcileError *Error);
};

//---------------------------------------------------------------------------
extern PACKAGE TReconcileErrorForm *ReconcileErrorForm;
extern PACKAGE TFieldData *PFieldData;

TReconcileAction HandleReconcileError(TComponent* Owner, TDataSet *DataSet,
  TUpdateKind UpdateKind, EReconcileError *ReconcileError);

#endif
