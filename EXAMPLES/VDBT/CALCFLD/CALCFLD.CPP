// (C) Copyright 1996, Borland International
//
// Calc.cpp - Calculated fields example in C++
//
/*********************************************************************
This program demonstrates the creation and use of calculated fields that
are supported by Borland's Visual Database Tools.  In order to make the
example as straight forward as possible there is practically no UI coded
and no data-aware controls are used.

The values of each of the calculated fields, profit.Value and
profitPercent.Value in this example, are defined in the OnCalcFields function 
but the actual code that defines these two fields as being calculated fields is
in WinMain.  To define a field as being a calculated field the following steps
must be performed before an OnCalcField event is triggered:

1.  A new field must be created and attached to its COM object (table in this
	 example.

2.  The field must be assigned a field name.

3.  The Calculated flag for the field must be set to true.

4.  The DataSet the field is attached to must be set.


The files needed to build this program are:

calcfld.cpp					Source file for application.
calc32.def/calc16.def	DEF file for 32 bit target and 16 bit target
								respectively.
calcfld.ide					BCW 5.0 project file for this example (if using
								the BC 5.0 IDE.
makefile						Make file to build this example in a DOS box.

*****************************************************************************/

// Use ObjectWindows Library (OWL) Style Classes
#include <vdbt\bdto.h>


/****************************************************************************
  EVENT HANDLER: OnCalcFields( TDataSetNotifySink&, TDataSet&)
   This event handler is hooked up to the event sink in WinMain.
	This event handler defines all of the calculated field values for record
		referenced in DataSet.
****************************************************************************/
void OnCalcFields( TDataSetNotifySink&, TDataSet& DataSet )
{
	TCurrencyField cost = DataSet.FieldByName(string("Cost"));
	TCurrencyField salePrice = DataSet.FieldByName(string("Sale Price"));
	TCurrencyField profit = DataSet.FieldByName(string("Calculated Profit"));
	TFloatField profitPercent = DataSet.FieldByName(string("Calculated Profit Percent"));

   // The following 2 lines define how the calculated fields are calculated.
	profit.Value = salePrice.Value - cost.Value;
	profitPercent.Value = 100 * profit.Value / salePrice.Value;
}

int PASCAL WinMain( HINSTANCE, HINSTANCE, LPSTR, int )
{
	// Create a database table object.
	PTTable table = new TTable;

/**************************************************************
	SETTING UP TO USE AN EVENT HANDLER

	Visual Database Tools uses event sources and event sinks ( or handlers)
	to encapsulate everything necessary for repsonding to event.  The general
	steps are:
	1.  Define the event source (this is done when you create a VDBT
		 component), in this particular example, TTable. See the line above
		 this comment.
	2.  Define the event sink to handle the event.
	3.  Connect the event sink to the event handler (OnCalcFields in this
		 example)
	4.  Connect the event source to the event sink.
**************************************************************/

	//The line below defines the event sink, OnCalcFieldsSink, and then
	// connects it to the event handler OnCalcFields.

	TDataSetNotifySink OnCalcFieldsSink(TDataSetNotify_FUNCTOR( OnCalcFields ));

	// The line below connects the event source to the event sink.

	table->OnCalcFieldsSource += OnCalcFieldsSink;

	// Using a temporary TTable variable, get the TFieldDefs for the table.
	TTable temptable;
	temptable.DatabaseName = string( "DivePlan" );
	temptable.TableName = string( "divestok.db" );
	TFieldDefs fielddefs = temptable.FieldDefs;
	fielddefs.Update();

	// For each item in the TFieldDefs, create a field and set its
	// DataSet property.
	int count = fielddefs.Count;
	PTField nonCalcFields = new TField [ count ];
	int i;
	for (i = 0; i < count; i++)
	{
		nonCalcFields[i] = fielddefs[i]->CreateField( *table );
		nonCalcFields[i].DataSet = table;
	}

	// To add the each calculated field, create a field object and set the
	// FieldName, Calculated, and DataSet properties.

	// Add the "Calculated Profit" field.
	PTCurrencyField profit = new TCurrencyField( table );
	profit->FieldName = string( "Calculated Profit" );
	profit->Calculated = true;
	profit->DataSet = table;

	// Add the "Calculated Profit Percent" field.
	PTFloatField profitPercent = new TFloatField( table );
	profitPercent->FieldName = string( "Calculated Profit Percent" );
	profitPercent->Calculated = true;
	profitPercent->DataSet = table;

	// Assign the database (a BDE alais in this example)
	// and table name properties, open the table.
	table->DatabaseName = string( "DivePlan" );
	table->TableName = string( "divestok.db" );
	table->Open();

	// Put the table in SetKey state (search mode)
	table->SetKey();

	// Go to the record for Item No 90057 (Power Inflator).
	table->FieldByName( string("Item No") )->AsString = string("90057");

	// If Item 90057 was found...
	if (table->GotoKey())
	{
		//If the description matches our expectation...
		if (table->FieldByName( string("Description") )->AsString == 
      																string("Power Inflator") )
		{
			int count = table->FieldCount;
			int i;
			// Print out each of the non calculated and calculated fields in
			//	their own separate message box.
			for (i = 0; i < count; i++)
			{
				MessageBox( 0, table->Fields[i]->AsString->c_str(),
            				table->Fields[i]->FieldName->c_str(), MB_OK );
			}
		}
		else
		{
			MessageBox( 0, "Unexpected Description field value.", "Error", MB_OK );
		}
	}
	else
	{
		MessageBox( 0, "Could not find Item No 90057.", "Error", MB_OK );
	}

	// Clean up
	if (profit)
		delete profit;
	if (profitPercent)
		delete profitPercent;
	if (nonCalcFields)
		delete [] nonCalcFields;
	if (table)
		delete table;

	return 0;
}

/******************************************************************************/

