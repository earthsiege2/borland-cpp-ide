//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1998-2002 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------

TITLE:
   DBERRORS

DESCRIPTION:
   This example shows:

     - The use of Data Modules to centralize coding
     - A one-to-many-to-many form
     - Trapping and Controlling Database Errors

DEMONSTRATES:
   TDataModule, TDataSet, EDatabaseError, TDataAction, TForm, TDBNavigator

COMMENTS:

   * Creation Order

      The proper functioning of any form with a one-to-many 
      relationship depends on the creation order of TTables and 
      TDatasources at runtime. In this example, the MasterSource 
      property of the Orders table point to CustomerSource. For the 
      one-to-many link to properly synch up, the Customer table must 
      be active. The creation order is determined at design
      time by right-clicking on the form and choosing Creation Order.

   * Database Error Trapping

      C++Builder displays errors that arise from user interaction with
      database tables as application level exceptions. The
      OnPostError, OnEditError and OnDeleteError events of
      the TTable and TQuery objects allow you to trap these
      errors closer to their origin.

   To trigger these errors, run this application, and try to modify,
   add, or delete records.

   You may encounter several different database engine
   errors: key violations, missing  required fields, referential
   integrity errors, incorrect foreign keys (most notably from
   the 'parts.db' table, which is not explicitly in this application),
   and so on.

   General Notes:

      The code in this example for the OnDeleteError on the Orders
      table allows you to delete the current Orders record even if it
      has dependent details. If this error occurs, a dialog box
      asks you if you want to remove the Orders record and all
      of its details. If this is action confirmed,  the code deletes all
      of the related Items records and then completes the action
      by retrying the deletion for the current record.

      The OnPostError, OnEditError and OnDeleteError pass to you
      an exception (e) of the EDatabaseError class. To get
      engine-level errorcodes, you must cast this as an error of
      type EDBEngineError.  See the code in DM1.CPP for details.

      The CustNo *Tfield* has min and max values. These are
      NOT database engine-level Min and Max Valchecks and so
      errors that arise from invalid entries are not caught by the
      engine errors trapped for here.
