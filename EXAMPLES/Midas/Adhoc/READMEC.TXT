//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 2000-2002 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------

TITLE:
    adhcclnt

DESCRIPTION:
    This program demonstrates dynamically passing SQL to the servers COM
    interface.

DEMONSTRATES:
    + TClientDataSet
    + TRemoteServer
    + Ole Automation Methods

COMMENTS:
    This example requires Interbase Server.
    Be sure to build and run the adhcsrvr application first, or this example
    won't run correctly.  Once the adhcsrvr application is registered, you need
    to connect the TDCOMConnection control to the server.  To do this, set the
    DCOMConnection1's ServerName property to adhcsrvr.AdHcDM.


