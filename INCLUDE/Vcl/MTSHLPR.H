////////////////////////////////////////////////////////////////////////////
// MTSHLPR.H - MTS wrapper class
//
// MTS and COM+ expose functions with similar signatures that are implemented
// in different DLLs. For an object to work correctly under both, it needs
// to dynamically load the appropriate DLL and call the underlying function.
//
// This class wraps those functions, hiding the work, and presenting an
// interface which will work against either platform.
//
// $Revision:   1.0.1.2  $
// $Date:   16 Dec 1999 18:44:22  $
//
// Copyright (c) 1999, 2000 Borland International
///////////////////////////////////////////////////////////////////////////

#ifndef _MTSHLPR_H
#define _MTSHLPR_H

#include <comsvcs.h>  // IObjectContext
#include <utilcls.h>

/* Wrapper class for the loading of MTS or COM+ */

class TMtsDll
{
    private:
       TDll* Library;
       int Type;
       bool init_com();
       bool init_mts();
    public:
       TMtsDll();
       ~TMtsDll();
       HRESULT Get_ObjectContext(IObjectContext** pIntanceContext);

       void* SafeRef(REFIID rid, IUnknown* pUnknown);
};

/* Static instantiations of enumerative values passed to MTS-related
 * methods. These methods require long pointers to these values,
 * which are defined in enumerations in mtxspm.h (in previous
 * versions of the Windows header files) or comsvcs.h (now)*/

extern "C" long LockMode_SetGet;
extern "C" long LockMode_LockMethod;
extern "C" long ReleaseMode_Standard;
extern "C" long ReleaseMode_Process;

#endif
