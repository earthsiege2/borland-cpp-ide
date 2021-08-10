//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 2000-2002 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------

TITLE:
    adhcsrvr

DESCRIPTION:
    This program represents the "Application Server" portion of the
    distributed datasets demo.  The remote data module in this example
    contains a TDataSetProvider component that has an OnDataRequest event
    which is used for dynamically assigning a SQL string.

DEMONSTRATES:
    + Remote Data Module
    + Exporting a TQuery control
    + TDataSetProvider
    + TSession
    + TDatabase

COMMENTS:
    Use the adhcclnt example to access the data provided by this server.
    This example requires Interbase Server.

