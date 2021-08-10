//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1998-2002 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------

TITLE:
  FILTER

DESCRIPTION:
  A simple app which displays filtered records from a database.

DEMONSTRATES:
  The use of a Data Module with a Query linked through its Datasource
  property for displaying detail records.
  Switching Between Query  and Table Based datasets.
  Filtering Records dynamically, by setting the Filter property of a Dataset.
  Filtering Records more statically, by providing a value to a
  variable hooked to the OnFilterRecord event.

  TDBGrid, TRadioGroup, TDBNavigator, TSpeedButton, TCheckBox
  TDataSource, TTable, TQuery, TFloatField, TIntegerField, TCurrencyField

COMMENTS:
  At runtime, the Data Module's only master datasource can be connected
  to either the Customer TQuery or the Customer TTable.  This Dataset is
  linked to a single Datasource which serves as the link to another dataset,
  defined by a dynamic query of the Orders table.

  Filtering is done on the Customer records dynamically, with the user
  providing an arbitrary expression. In contrast, the Filter button for the
  Orders table is done in a more static, code-based fashion, with the
  user simply providing a threshold for the Total Order Amount. An
  exception is raised when user entries are inappropriate.


