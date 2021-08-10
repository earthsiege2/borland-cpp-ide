//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//----------------------------------------------------------------------------

// Because we are called from toolhelp on another task data segment, it is
// critical to overide the default entry code settings here in order to
// force it to: ds!=ss and explicit export:
//
#pragma option  -WE

#include <owl\owlpch.h>
#include  "diagxprt.h"

//
// Callback is just used for correctly adjusting the data segment - this
// function being MakeProcInstance'd by SetupWindow(). This is critical
// because TOOLHELP calls this function on the other task data segment.
// Then it calls TDiagClient::NotifyCallback thru the static "this" pointer.
//
BOOL FAR PASCAL __export
Callback(WORD id, DWORD data) {
  // Now that the data segment is correctly set to our task's, call it:
  //
  switch (id) {

#if 0  // This seems to be redundant
    case NFY_LOGPARAMERROR: {
      NFYLOGPARAMERROR FAR *param = (NFYLOGPARAMERROR FAR *)data;
      TDispData* d = new TDispData;

      strcpy(d->ProcName, TDiagClient::pThis->GetProcName(param->lpfnErrorAddr));

      strcpy(d->ModuleName, TDiagClient::pThis->GetTaskName());

      d->ErrorCode = ((NFYLOGPARAMERROR FAR*)data)->wErrCode;
      d->Param = ((NFYLOGPARAMERROR FAR*)data)->lpBadParam;

      TDiagClient::pThis->PostMessage(CM_LOGPARAMERROR,0,(LPARAM)d);
      break;
    }
#endif

    case NFY_LOGERROR: {
      TDispData *d = new TDispData;

      strcpy(d->ModuleName, TDiagClient::pThis->GetTaskName());
      
      d->ErrorCode = ((NFYLOGERROR FAR*)data)->wErrCode;
      d->Data = (DWORD)((NFYLOGERROR FAR*)data)->lpInfo;
      TDiagClient::pThis->PostMessage(CM_LOGERROR, 0, (LPARAM)d);
      break;
    }

    case NFY_OUTSTR: {
      TDispData *d=new TDispData;

      char far *dStr = (LPSTR)data;
      strcpy( d->ProcName, dStr);
      TDiagClient::pThis->PostMessage(CM_OUTSTR, 0, (LPARAM)d);
      break;
    }

    default:
      // Other toolhelp notifications can be handled.
      // Make sure that diagxprt.cpp is updated to match
      // TDiagClient::pThis->PostMessage(CM_DEFAULT, id, 0);
      break;
  }
  return FALSE;
}
