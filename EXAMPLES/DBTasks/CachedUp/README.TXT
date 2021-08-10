//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1998-2002 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------

TITLE:
  CACHEDUP

DESCRIPTION:
  Cached Updates.

DEMONSTRATES:
  Demonstrates cached updates on a database.

  TImage, TMemo, TButton, TPanel, TGroupBox,
  TDBGrid, TDBNavigator, TDataSource, TDatabase, TQuery, TStringField
  TUpdateSQL, TUpdateAction, EDatabaseError, TDataModule
  
COMMENTS:
  Be sure to run Interbase Server before loading this program 
  into the C++Builder IDE.  Otherwise the Connected property of the
  CacheDB TDatabase will revert to False, and the Active property of 
  the CacheQuery TQuery will revert to False.
 
