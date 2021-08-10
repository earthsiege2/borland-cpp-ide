//--------------------------------------------------------
// DBACC.H
// Copyrights (C) 1996 Borland International
// All Rights Reserved
//--------------------------------------------------------

#ifndef _DBACC_H_
#define _DBACC_H_

#include <owl/pch.h>
#include <owl/applicat.h>
#include <vdbt/bdto.h>
#include <bivbx.h>
#include <owl/vbxctl.h>
#include <vdbt/dbpme.h>


//
// Mangle the class and function names so we can have mulitpale versions of the
// same classes and functions in one .LIB file.
//
#if defined( __DLL__ ) && ! defined( __FLAT__ )
#  if defined( _RTLDLL )
#    define TDBBatchMove   dTDBBatchMove
#    define TDBDatabase    dTDBDatabase
#    define TDBDataSource  dTDBDataSource
#    define TDBQuery       dTDBQuery
#    define TDBStoredProc  dTDBStoredProc
#    define TDBTable       dTDBTable
#  else _RTLDLL
#    define TDBBatchMove   uTDBBatchMove
#    define TDBDatabase    uTDBDatabase
#    define TDBDataSource  uTDBDataSource
#    define TDBQuery       uTDBQuery
#    define TDBStoredProc  uTDBStoredProc
#    define TDBTable       uTDBTable
#  endif _RTLDLL
#elif defined( _RTLDLL )
#  define TDBBatchMove   iTDBBatchMove
#  define TDBDatabase    iTDBDatabase
#  define TDBDataSource  iTDBDataSource
#  define TDBQuery       iTDBQuery
#  define TDBStoredProc  iTDBStoredProc
#  define TDBTable       iTDBTable
#endif

class _DBAWARECLASS TDBDataSource : public TVbxControl, public TDataSource {
  private: // Don't let anyone use these
    TDBDataSource& operator=(TDBDataSource&);
    TBDDataSource(TDBDataSource&);

  public:
    TDBDataSource( TWindow *parent, int id, LPCSTR title
             , int x=0, int y=0, TModule *module=0 )
             : TVbxControl( parent, id, "BDT52ACC.VBX", "TDataSource"
                          , title, x, y, 0, 0, 0, 0, module ) {}

    TDBDataSource( TWindow *parent, int resourceId, TModule *module=0 )
                 : TVbxControl( parent, resourceId, module ) {}

    bool Create();
};

class _DBAWARECLASS TDBTable : public TVbxControl, public TTable {
  private: // Don't let anyone use these
    TDBTable& operator=(TDBTable&);
    TBDTable(TDBTable&);

  public:
    TDBTable( TWindow *parent, int id, LPCSTR title
            , int x=0, int y=0, TModule *module=0 )
            : TVbxControl( parent, id, "BDT52ACC.VBX", "TTable"
                         , title, x, y, 0, 0, 0, 0, module ) {}

    TDBTable( TWindow *parent, int resourceId, TModule *module=0 )
            : TVbxControl( parent, resourceId, module ) {}

    bool Create();
};

class _DBAWARECLASS TDBQuery : public TVbxControl, public TQuery {
  private: // Don't let anyone use these
    TDBQuery& operator=(TDBQuery&);
    TBDQuery(TDBQuery&);

  public:
    TDBQuery( TWindow *parent, int id, LPCSTR title
            , int x=0, int y=0, TModule *module=0 )
            : TVbxControl( parent, id, "BDT52ACC.VBX", "TQuery"
                         , title, x, y, 0, 0, 0, 0, module ) {}

    TDBQuery( TWindow *parent, int resourceId, TModule *module=0 )
            : TVbxControl( parent, resourceId, module ) {}

    bool Create();
};

class _DBAWARECLASS TDBBatchMove : public TVbxControl, public TBatchMove {
  private: // Don't let anyone use these
    TDBBatchMove& operator=(TDBBatchMove&);
    TBDBatchMove(TDBBatchMove&);

  public:
    TDBBatchMove( TWindow *parent, int id, LPCSTR title
                , int x=0, int y=0, TModule *module=0 )
                : TVbxControl( parent, id, "BDT52ACC.VBX", "TBatchMove"
                             , title, x, y, 0, 0, 0, 0, module ) {}

    TDBBatchMove( TWindow *parent, int resourceId, TModule *module=0 )
                : TVbxControl( parent, resourceId, module ) {}

    bool Create();
};

class _DBAWARECLASS TDBDatabase : public TVbxControl, public TDatabase {
  private: // Don't let anyone use these
    TDBDatabase& operator=(TDBDatabase&);
    TBDDatabase(TDBDatabase&);

  public:
    TDBDatabase( TWindow *parent, int id, LPCSTR title
                , int x=0, int y=0, TModule *module=0 )
                : TVbxControl( parent, id, "BDT52ACC.VBX", "TDatabase"
                             , title, x, y, 0, 0, 0, 0, module ) {}

    TDBDatabase( TWindow *parent, int resourceId, TModule *module=0 )
                : TVbxControl( parent, resourceId, module ) {}

    bool Create();
};

class _DBAWARECLASS TDBStoredProc : public TVbxControl, public TStoredProc {
  private: // Don't let anyone use these
    TDBStoredProc& operator=(TDBStoredProc&);
    TBDStoredProc(TDBStoredProc&);

  public:
    TDBStoredProc( TWindow *parent, int id, LPCSTR title
                 , int x=0, int y=0, TModule *module=0 )
                 : TVbxControl( parent, id, "BDT52ACC.VBX", "TStoredProc"
                              , title, x, y, 0, 0, 0, 0, module ) {}

    TDBStoredProc( TWindow *parent, int resourceId, TModule *module=0 )
                 : TVbxControl( parent, resourceId, module ) {}

    bool Create();
};

#endif _DBACC_H_
