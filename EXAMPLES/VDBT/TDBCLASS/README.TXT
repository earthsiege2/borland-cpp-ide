----------------------------------------------------------------------------
 Borland C++
 Copyright (c) 1996 Borland International Inc.  All Rights Reserved.
----------------------------------------------------------------------------

TITLE:
   TDBCLASS - TDB-Access classes Application

PURPOSE:
   This program demonstrates a few of the new TDB-data access classes.
   The new classes are TDBTable, TDBDataSource, TDBQueary, TDBBatchMove,
   TDBDatabase and TDBStoredProc.  To see these new classes look in the
   include\vdbt\dbacc.h file.  These classes are to be used when you are
   using the VDBT controls in a window instead of a dialog and you want
   to connect the data aware controls to the data access controls.  This
   program uses the TDBTable and TDBDataSource to connect to a very
   simple database.  It has a TDBEdit and TDBNavigator that are
   contected to the TDBDataSource and used to scroll through the
   database displaying one of the fields in it.  In this program since
   the C++ classes are created in the constructor, the controls are
   listed on the child list of the TWindow class so it is not neccassay
   to call the Create member function of these classes.  If they were
   created outside of the constructor, it would be neccassary to call
   the Create functions.

COMMENTS:


