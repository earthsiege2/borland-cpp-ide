//---------------------------------------------------------------------------

#ifndef DataModH
#define DataModH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <WebModu.hpp>
#include <DB.hpp>
#include <DBAdapt.hpp>
#include <DBAdaptImg.hpp>
#include <DBTables.hpp>
#include <WebAdapt.hpp>
#include <WebComp.hpp>


//---------------------------------------------------------------------------
class TBioDataModule : public TWebDataModule
{
__published:	// IDE-managed Components
  TTable *Table1;
  TFloatField *Table1SpeciesNo;
  TStringField *Table1Category;
  TStringField *Table1Common_Name;
  TStringField *Table1SpeciesName;
  TFloatField *Table1Lengthcm;
  TFloatField *Table1Length_In;
  TMemoField *Table1Notes;
  TGraphicField *Table1Graphic;
  TSession *Session1;
  TDataSetAdapter *DataSetAdapter1;
  TDataSetAdapterDeleteRowAction *ActionDeleteRow;
  TDataSetAdapterFirstRowAction *ActionFirstRow;
  TDataSetAdapterPrevRowAction *ActionPrevRow;
  TDataSetAdapterNextRowAction *ActionNextRow;
  TDataSetAdapterLastRowAction *ActionLastRow;
  TDataSetAdapterNewRowAction *ActionNewRow;
  TDataSetAdapterEditRowAction *ActionEditRow;
  TDataSetAdapterCancelRowAction *ActionCancel;
  TDataSetAdapterApplyRowAction *ActionApply;
  TDataSetAdapterRefreshRowAction *ActionRefreshRow;
  TDataSetAdapterField *AdaptSpeciesNo;
  TDataSetAdapterField *AdaptCategory;
  TDataSetAdapterField *AdaptCommon_Name;
  TDataSetAdapterField *AdaptSpeciesName;
  TDataSetAdapterField *AdaptLengthcm;
  TDataSetAdapterField *AdaptLength_In;
  TDataSetAdapterMemoField *AdaptNotes;
  TDataSetAdapterImageField *AdaptGraphic;
private:	// User declarations
public:		// User declarations
};

TBioDataModule *BioDataModule();

//---------------------------------------------------------------------------
extern PACKAGE TWebDataModule *WebDataModule;
//---------------------------------------------------------------------------
#endif

