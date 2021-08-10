//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <memory>     //for std::auto_ptr
#include "QBFForm.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TQueryForm *QueryForm;
//---------------------------------------------------------------------------
__fastcall TQueryForm::TQueryForm(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TQueryForm::FormCreate(TObject *Sender)
{
  Screen->Cursor = Controls::TCursor(crHourGlass);

  // Populate the alias list
  ListBox1->Items->Clear();
  Session->GetAliasNames(ListBox1->Items);

  // Make sure there are aliases defined
  Screen->Cursor = Controls::TCursor(crDefault);
  if (ListBox1->Items->Count < 1)
    MessageDlg( "There are no database aliases currently defined.  You " \
		"need at least one alias to use this demonstration.",
		 mtError, TMsgDlgButtons() << mbOK, 0 );

  // Default the drop-down list to the first value in the list
  ComboBox1->ItemIndex = 0;

}
//---------------------------------------------------------------------
void __fastcall TQueryForm::BitBtn2Click(TObject *Sender)
{
  AnsiString
    strAlias,            // Alias name selected by the user
    strTable,            // Table name selected by the user
    strField,            // Field name selected by the user
    strValue,            // Field Value entered by the user
    strWhere,            // WHERE clause for the user's query
    strQuote,            // Holds quotes is the query field is text
    strQuery;                    // String used to construct the query
  std::auto_ptr<TResultForm> frmQuery; // The Results form
  char szTemp[1024];

  /*
	The following type is used with the Type drop-down
	list.  The text values corresponding with each item is
	described in comments, along with the relevant SQL operators.
	*/

  typedef enum {
	      soNoCondition,  // not field conditions: no WHERE clause
	    soEqual,        // equals: =
	    soNotEqual,     // is not equal to: <>
	    soLessThan,     // is less than: <
	    soLessEqual,    // is less than or equal to: <=
	    soMoreThan,     // is greater than: >
	    soMoreEqual,    // is greater than or equal to: >=
	    soStartsWith,   // starts with: LIKE xx%
	    soNoStartsWith, // doesn't start with: NOT LIKE xx%
	    soEndsWith,     // ends with: LIKE %xx
	    soNoEndsWith,   // doesn't end with: NOT LIKE %xx
	    soContains,     // contains: LIKE %xx%
	    soNoContains,   // doesn't contain: NOT LIKE %xx%
	    soBlank,        // is blank:
	    soNotBlank,     // is not blank:
	    soInside,       // contains only: IN ( xx, yy, zz )
	    soOutside       // doesn't contain: NOT IN (xx, yy, zz)
	    } etSQLOps;

	// Initialize the variables needed to run the query
  if (ListBox1->ItemIndex == -1)
	throw Exception("Can't Run Query: No Alias Selected");
  else
	strAlias = ListBox1->Items->Strings[ListBox1->ItemIndex];

  if (ListBox2->ItemIndex == -1)
    throw Exception("Can't Run Query: No Table Selected");
  else
    strTable = ListBox2->Items->Strings[ListBox2->ItemIndex];

  if (ListBox3->ItemIndex == -1)
  {
    if (ComboBox1->ItemIndex > soNoCondition)
      throw Exception("Can't Run Query: No Field Selected");
    else
      strField = "";
  }
  else
    strField = ListBox3->Items->Strings[ListBox3->ItemIndex];

  if ((Edit1->Text.Length() == 0) && (ComboBox1->ItemIndex > soNoCondition) &&
    (ComboBox1->ItemIndex < soBlank))
    throw Exception("Can't Run Query: No Search Value Entered");
  else
    strValue = Edit1->Text;

  /*
	See if the field being search is a string field.  If so, then pad the
	quote string with quotation marks; otherwise, set it to a null value.
	*/
  if (strField.Length() != 0)
  {
	if ((Table1->FieldByName(strField)->DataType == ftString) ||
	(Table1->FieldByName(strField)->DataType == ftMemo))
	strQuote = "\"";
     else
	strQuote = " ";
  }

  /*
	Construct the WHERE clause of the query based on the user's choice
	in Type.
  */

  szTemp[0] = '\0';
  switch (etSQLOps(ComboBox1->ItemIndex))
  {
    case soNoCondition:
	szTemp[0] = '\0';
	break;
    case soEqual:
	wsprintf(szTemp, "%s = %s%s%s", strField.c_str(), strQuote.c_str(), strValue.c_str(), strQuote.c_str());
	break;
    case soNotEqual:
	wsprintf(szTemp, "%s <> %s%s%s", strField.c_str(), strQuote.c_str(), strValue.c_str(), strQuote.c_str());
	break;
    case soLessThan:
	wsprintf(szTemp, "%s < %s%s%s", strField.c_str(), strQuote.c_str(), strValue.c_str(), strQuote.c_str());
	break;
     case soLessEqual:
	wsprintf(szTemp, "%s <= %s%s%s", strField.c_str(), strQuote.c_str(), strValue.c_str(), strQuote.c_str());
	break;
     case soMoreThan:
	wsprintf(szTemp, "%s > %s%s%s", strField.c_str(), strQuote.c_str(), strValue.c_str(), strQuote.c_str());
	break;
     case soMoreEqual:
	wsprintf(szTemp, "%s >= %s%s%s", strField.c_str(), strQuote.c_str(), strValue.c_str(), strQuote.c_str());
	break;
     case soStartsWith:
	wsprintf(szTemp, "%s LIKE %s%s%%%s", strField.c_str(), strQuote.c_str(), strValue.c_str(), strQuote.c_str());
	break;
     case soNoStartsWith:
	wsprintf(szTemp, "%s NOT LIKE %s%s%%%s", strField.c_str(), strQuote.c_str(), strValue.c_str(), strQuote.c_str());
	break;
     case soEndsWith:
	wsprintf(szTemp, "%s LIKE %s%%%s%s", strField.c_str(), strQuote.c_str(), strValue.c_str(), strQuote.c_str());
	break;
     case soNoEndsWith:
	wsprintf(szTemp, "%s NOT LIKE %s%%%s%s", strField.c_str(), strQuote.c_str(), strValue.c_str(), strQuote.c_str());
	break;
     case soContains:
	wsprintf(szTemp, "%s LIKE %s%%%s%%%s", strField.c_str(), strQuote.c_str(), strValue.c_str(), strQuote.c_str());
	break;
     case soNoContains:
	wsprintf(szTemp, "%s NOT LIKE %s%%%s%%%s", strField.c_str(), strQuote.c_str(), strValue.c_str(), strQuote.c_str());
	break;
     case soBlank:
	wsprintf(szTemp, "%s IS NULL", strField.c_str());
	break;
     case soNotBlank:
	wsprintf(szTemp, "%s IS NOT NULL", strField.c_str());
	break;
     default:
	szTemp[0] = '\0';
  }
  strWhere = szTemp;

	szTemp[0] = '\0';
  if (ComboBox1->ItemIndex == soNoCondition)
	wsprintf(szTemp, "SELECT * FROM \"%s\"", strTable.c_str());
  else if (Table1->FieldByName(strField)->DataType == ftString)
	wsprintf(szTemp, "SELECT * FROM \"%s\" t WHERE t.%s", strTable.c_str(), strWhere.c_str());
  else
	wsprintf(szTemp, "SELECT * FROM \"%s\" t WHERE t.%s", strTable.c_str(), strWhere.c_str());
  strQuery = szTemp;

  // Create an instance of the browser form.
  //frmQuery.reset(new TResultForm(Application));
  // New auto_ptr<> behavior
  std::auto_ptr<TResultForm> tmp (new TResultForm(Application));
  frmQuery = tmp;
  tmp.release();

  szTemp[0] = '\0';

  Screen->Cursor = Controls::TCursor(crHourGlass);
  if (frmQuery->Query1->Active)
    frmQuery->Query1->Close();
  frmQuery->Query1->DatabaseName = strAlias; // set the alias the query poitns to
  frmQuery->Query1->SQL->Clear();            // empty existing SQL in the query
  frmQuery->Query1->SQL->Add(strQuery);      // add query string to query object
  try{
      frmQuery->Query1->Active = True;           // try to run the query
     }
  catch(Exception &e)
  {
      Screen->Cursor = Controls::TCursor(crDefault);
      throw;
  }
  Screen->Cursor = Controls::TCursor(crDefault);

  if (frmQuery->Query1->Active){
    /* If the query didn't return any records, there's no point in
       displaying the form.  In that event, raise an exception. */
    if (frmQuery->Query1->RecordCount < 1)
      throw Exception("No records matched your criteria.  " \
		      "Please try again.");

    // write a message to the browse form's status line
    if (strField.Length() == 0){
       wsprintf(szTemp, "Now showing all records from %s ...", strTable.c_str());
       frmQuery->Panel3->Caption = szTemp;
    }
    else {
       wsprintf(szTemp, "Now showing %s where %s contains values equal to ..."
	  , strTable.c_str(), strField.c_str(), strValue.c_str());
       frmQuery->Panel3->Caption = szTemp;
    }
    // show the form
    frmQuery->ShowModal();
  }
}
//---------------------------------------------------------------------
void __fastcall TQueryForm::ListBox1Click(TObject *Sender)
{
  AnsiString strValue;       // Holds the alias selected by the user

  // Determine the alias name selected by the user }
  strValue = ListBox1->Items->Strings[ListBox1->ItemIndex];

  /*
	Get the names of the tables in the alias and put them in the
	appropriate list box, making sure the user's choices are reflected
	in the list.
  */
  ListBox2->Items->Clear();
  Session->GetTableNames(strValue,          // alias to enumerate
			"",                 // pattern to match
			CheckBox1->Checked, // show extensions flag
			CheckBox2->Checked, // show system tables flag
			ListBox2->Items);   // target for table list

  /*
	Make sure there are tables defined in the alias.  If not, show an
	error; otherwise, clear the list box.
  */
  Screen->Cursor = Controls::TCursor(crDefault);
  if (ListBox2->Items->Count < 1)
    MessageDlg("There are no tables in the alias you selected.  Please " \
	       "choose another", mtError, TMsgDlgButtons() << mbOK, 0 );

  ListBox3->Items->Clear();
}
//---------------------------------------------------------------------
void __fastcall TQueryForm::ListBox2Click(TObject *Sender)
{
  Screen->Cursor = Controls::TCursor(crHourGlass);
  try
  {
    // First, disable the TTable object.
    if (Table1->Active) Table1->Close();

    // Open the selected table
    Table1->DatabaseName = ListBox1->Items->Strings[ListBox1->ItemIndex];
    Table1->TableName = ListBox2->Items->Strings[ListBox2->ItemIndex];

    // Open the table and put a list of the field names in the Fields list box. }
    Table1->Open();
    if (Table1->Active) Table1->GetFieldNames(ListBox3->Items);
  }
  catch (...) {}
  Screen->Cursor = Controls::TCursor(crDefault);
}
//---------------------------------------------------------------------
