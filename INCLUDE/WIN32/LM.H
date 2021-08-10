/*++ BUILD Version: 0001    // Increment this if a change has global effects

Copyright (c) 1991-1996  Microsoft Corporation

Module Name:

    lm.h

Abstract:

    This is the top level include file that includes all the files
    necessary for writing Lan Manager Application.

--*/

/* $Copyright: 1994$ */

#ifndef _LM_
#define _LM_
#define __LM_H
#pragma option -b

#pragma option -b.
#include <lmcons.h>     // LAN Manager common definitions
#pragma option -b
#pragma option -b.
#include <lmerr.h>      // LAN Manager network error definitions
#pragma option -b

#pragma option -b.
#include <lmaccess.h>   // Access, Domain, Group and User classes
#pragma option -b
#pragma option -b.
#include <lmalert.h>    // Alerter
#pragma option -b
#pragma option -b.
#include <lmchdev.h>    // Character Device and Handle classes
#pragma option -b
#pragma option -b.
#include <lmshare.h>    // Connection, File, Session and Share classes
#pragma option -b
#pragma option -b.
#include <lmmsg.h>      // Message class
#pragma option -b
#pragma option -b.
#include <lmremutl.h>   // Remote Utility class
#pragma option -b
#pragma option -b.
#include <lmrepl.h>     // Replicator class
#pragma option -b
#pragma option -b.
#include <lmserver.h>   // Server class
#pragma option -b
#pragma option -b.
#include <lmsvc.h>      // Service class
#pragma option -b
#pragma option -b.
#include <lmuse.h>      // Use class
#pragma option -b
#pragma option -b.
#include <lmwksta.h>    // Workstation class
#pragma option -b
#pragma option -b.
#include <lmapibuf.h>   // NetApiBuffer class
#pragma option -b
#pragma option -b.
#include <lmerrlog.h>   // NetErrorLog class
#pragma option -b
#pragma option -b.
#include <lmconfig.h>   // NetConfig class
#pragma option -b
#pragma option -b.
#include <lmstats.h>    // NetStats class
#pragma option -b
#pragma option -b.
#include <lmaudit.h>    // NetAudit class
#pragma option -b

#pragma option -b.
#endif // _LM_
