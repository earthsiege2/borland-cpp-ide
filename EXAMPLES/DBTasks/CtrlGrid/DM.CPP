//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "DM.h"
#include "CtrlForm.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TDM1 *DM1;
//---------------------------------------------------------------------------
__fastcall TDM1::TDM1(TComponent* Owner)
  : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDM1::tblHoldingsAfterOpen(TDataSet *DataSet)
{
  dsMaster->OnDataChange = CalculateTotals;
}
//---------------------------------------------------------------------
void __fastcall TDM1::tblHoldingsAfterPost(TDataSet *DataSet)
{
//	TBookmark bmCurrent;

//	bmCurrent = tblHoldings->getBookmark();       { save position }
//    try
//    	{
      	CalculateTotals(0, 0);  /* recalc totals */
//      	tblHoldings->gotoBookmark(bmCurrent);     { restore position }
//       }
//    finally;
//    	{
//      	tblHoldings->freeBookmark(bmCurrent);     { free memory }
 //     }

}
//---------------------------------------------------------------------
void __fastcall TDM1::tblHoldingsCalcFields(TDataSet *DataSet)
{
	tblHoldingsPUR_COST->AsFloat =
    tblHoldingsPUR_PRICE->AsFloat * tblHoldingsSHARES->AsFloat;
}
//---------------------------------------------------------------------

#pragma warn -aus
void __fastcall TDM1::CalculateTotals(TObject * Sender, TField * Field)
	{
   float flTotalCost = 0;            /* Holds total share cost */
  	float flTotalShares = 0;          /* Holds total share count */
  	float flTotalValue = 0;           /* Holds total share value */
  	float flDifference = 0;     		/* Holds difference between cost and value */
  	AnsiString strFormatSpec;	/* The Display Format specification */

  /* Update the count of stock transactions */
  	FmCtrlGrid->lPurchase->Caption = IntToStr( tblHoldings->RecordCount );

  /* See whether or not its necessary to total the holdings and
    (if so) do so and update the result displays; otherwise,
    clear the result displays. */
  	if (tblHoldings->RecordCount == 0)
  		{
    /* Clear the result displays */
    	FmCtrlGrid->lTotalCost->Caption   = "";
    	FmCtrlGrid->lTotalShares->Caption = "";
    	FmCtrlGrid->lDifference->Caption  = "";
  		}
  	else
  		{
    /* let the user know something's going on */
//    	Screen->Cursor = crHourglass;

    /* Initialize the holder variables */
    /*
    	flTotalCost = 0.0;
    	flTotalShares = 0.0;
    	flTotalValue = 0.0;
    	flDifference = 0.0;
    */

    /* Calculate the total cost of these holdings. */
    	tblHoldings->DisableControls();  /* hide this process from the user */
    	tblHoldings->First();
    	while (!tblHoldings->Eof)
       	{
      		flTotalCost = flTotalCost + tblHoldingsPUR_COST->AsFloat;
      		flTotalShares = flTotalShares + tblHoldingsSHARES->AsFloat;
      		tblHoldings->Next();
    		};
    	tblHoldings->First();
    	tblHoldings->EnableControls();  /* restore the display of holdings */

    /* Calculate the current value of the shares (by multiplying
      the current holdings by the current share price) and the
      difference between the cost and the value. */

    	flTotalValue = flTotalShares * tblMasterCUR_PRICE->AsFloat;
    	flDifference = flTotalValue - flTotalCost;

    /* Use the same format specification as that being used to
      display the Current Price field value so it can be used
      to display the results */

    	strFormatSpec = tblMasterCUR_PRICE->DisplayFormat;

    /* Update the result displays */

    	FmCtrlGrid->lTotalCost->Caption =
       	FormatFloat( strFormatSpec, flTotalCost );
    	FmCtrlGrid->lTotalShares->Caption =
       	FormatFloat( strFormatSpec, flTotalValue );
    	FmCtrlGrid->lDifference->Caption =
       	FormatFloat( strFormatSpec, flDifference );

    /* Update the Font Color of the Diference to
      indicate the quality of the investment */
    	if (flDifference > 0)
    		{
      		FmCtrlGrid->lDifference->Font->Color = clGreen;
       	}
    	else
    		{
      		FmCtrlGrid->lDifference->Font->Color = clRed;
       	}
    	FmCtrlGrid->lDifference->Update();

    /* let the user know that we're finished */
//    	Screen->Cursor = crDefault;
  		}
	}
#pragma warn .aus
//---------------------------------------------------------------------