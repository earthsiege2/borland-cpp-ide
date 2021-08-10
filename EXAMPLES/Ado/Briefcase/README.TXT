//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1999 Inprise Corporation. All Rights Reserved.
//---------------------------------------------------------------------------

TITLE:
Briefcase

DESCRIPTION:
This program demonstrates how to do disconnected briefcase applications
with ADO.  When the Connected checkbox is unchecked the application is
switched into offline mode.  If the application is exited at that point
then the data is persisted to a file on disk (along with any edits to the
data).  When the application is restarted it will load the persisted data
if present, otherwise it will fetch the data from the database.

DEMONSTRATES:

-TADOConnection
-TADODataSet


