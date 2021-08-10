//--------------------------------------------------------
// DBCONTRL.CPP
// Copyrights (C) 1996 Borland International
// All rights reserved.
//--------------------------------------------------------

#include <vdbt/dbcontrl.h>


//--------------------------------------------------------
// Events Response Table
//--------------------------------------------------------
DEFINE_DB_RESPONSE_TABLE1( TDBControl, TVbxControl )
END_RESPONSE_TABLE;

TDBControl::TDBControl( TWindow *parent, int id, LPCSTR lpClass, LPCSTR title
                      , int x, int y, int w, int h, TModule *module )
           : TVbxControl( parent, id, "BDT52CTL.VBX", lpClass, title
                        , x, y, w, h, 0, 0, module )
{
}

TDBControl::TDBControl( TWindow *parent, int resourceId, TModule *module )
           : TVbxControl( parent, resourceId, module )
{
}
