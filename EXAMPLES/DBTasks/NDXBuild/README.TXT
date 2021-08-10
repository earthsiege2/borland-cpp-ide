//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1998-2002 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------

TITLE:
  NDXBUILD

DESCRIPTION:
  A simple demonstration of building indices for database tables.

DEMONSTRATES:
  TTable, TStatusBar TBitBtn, TComboBox,
  DbiRegenIndexes

COMMENTS:
  The Index Rebuilder is designed to fix 'Index Out Of
  Date' error encountered while running applications
  using Paradox tables.  It lets you rebuild any or all
  tables in a given alias.

  To use the Index Rebuilder:

  1)  Start by choosing the alias containing the tables
      you want to fix.  When you do this, the Table list
      updates to reflect the tables in that directory.

  2)  Choose the table you want to fix or choose <All
      Tables> to fix them all.

  3)  Choose 'Build Indexes' to rebuild the indexes for
      the table(s) you've selected.

  As tables are fixed, messages appear in the status line to
  indicate the progress of the process. If you choose to fix all
  tables a given alias, a counter appears in the right-hand corner
  of the status line during the process. This indicates the number
  of tables that remain to be fixed.

  Note:  The Index Rebuilder needs exclusive access to
         the table(s) being fixed.  This means NO other
         program can have the table(s) open; otherwise,
         errors will appear.

TROUBLESHOOTING:
  Certain errors may appear during the process. The following table
  shows what these mean and indicates how to resolve the problem,
  if possible.

  Table is busy:

     The table(s) you're trying to rebuild are being
     used by another user or application.  You need to
     either exit and close the application or have the
     other user stop using the table(s).

  Table is open in Shared Mode:

     The table was not opened exclusively.  If you're
     building a new C++Builder application, set the TTable's
     Exclusive property to True.

  Invalid Table Handle:

     This is an Engine level error indicating that the
     handle passed to the Engine doesn't point to an
     open table.  This should not appear in the context
     of the Rebuilder; however, it's documented for
     completeness.

  Remote Indexes cannot be rebuilt:

     You have tried to rebuild indexes on a table stored
     on a remote (SQL) server.  This is not supported.
     You need to contact the database administrator and
     arrange to have the index repaired through that
     individual.

  Unexpected Error returned by BDE:

     The Database Engine has return an unknown and
     unexpected error, one that was not been documented
     when this utility was written.  At the time the
     utility was written, there are no known cases of
     this happening; however, the utility takes the
     possibility into account.



