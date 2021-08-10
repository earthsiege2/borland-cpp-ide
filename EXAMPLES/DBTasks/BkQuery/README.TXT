//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1998 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------

TITLE:
  BKQUERY

DESCRIPTION:
  Demonstrates a background query on a database.

DEMONSTRATES:
  Multi-threaded SQL queries, thread synchronization using 
  Interlocked increment, user-defined resources and string 
  resources.  

  TComboBox, TEdit, TButton, TIniFile, TMemo, TThread
  TDataSource, TQuery, TSession, TDatabase, TDBGrid
  TIniFile

COMMENTS:
  Demostrates how to execute a query in a background thread. 
 
  BkQuery contains the main user interface for this program.  
  The background query code is in ResltFrm.

  There are two SQL queries which operate on the examples databases
  which come with Borland C++Builder.  They are kept in the .SQL
  files in this directory and pulled into the .RC file to create 
  a user-defined resource. 

  The first time the app is run, the BKQUERY.INI file is created.
  It contains the text for the SQL queries which are in the .EXE's 
  resources as mentioned above.  

  Any subsequent queries you save are also placed in the BKQUERY.INI
  file.

  BKQuery is your one-stop application for creating, storing and 
  submitting SQL queries on any BDE database.
 
