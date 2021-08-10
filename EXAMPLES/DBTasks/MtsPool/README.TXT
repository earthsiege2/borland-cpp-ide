//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1999 Inprise Corp.  All Rights Reserved.
//---------------------------------------------------------------------------

TITLE:
MTSPool

DESCRIPTION:
This example is a simple application that demonstrates the use of object pooling. 
The application measures the amount of time needed to open and close a database 
connection a number of times. The "MTS Pooling checkbox" enables and disables the 
pooling of the database objects. You should see a signifcant difference in elapsed 
time when running the test with and without MTS Pooling enabled. When pooling is 
enabled, the system caches the connection objects rather than freeing them allowing 
other clients to use the idle connection objects instead of creating their own. 
Consult the help files for further information.

DEMONSTRATES:

COMMENTS:
