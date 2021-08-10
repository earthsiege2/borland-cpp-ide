#pragma option push -b -a8 -pc -A- /*P_O_Push*/
/**************************************************************************
 *
 *  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
 *  KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
 *  PURPOSE.
 *
 *  Copyright 1993 - 1998 Microsoft Corporation.  All Rights Reserved.
 * 
 **************************************************************************/


#define APPVERSION            4
#define APPREVISION           0
#define APPRELEASE            0

#define VERSIONPRODUCTNAME    "Microsoft Windows\0"
#define VERSIONCOPYRIGHT      "Copyright 1991 - 1998 Microsoft Corporation.\0"

#define VERSIONSTR            "4.00\0"

#define VERSIONCOMPANYNAME    "Microsoft Corporation\0"

#ifndef OFFICIAL
#define VER_PRIVATEBUILD      VS_FF_PRIVATEBUILD
#else
#define VER_PRIVATEBUILD      0
#endif

#ifndef FINAL
#define VER_PRERELEASE        VS_FF_PRERELEASE
#else
#define VER_PRERELEASE        0
#endif

#if defined(DEBUG_RETAIL)
#define VER_DEBUG             VS_FF_DEBUG
#elif defined(DEBUG)
#define VER_DEBUG             VS_FF_DEBUG
#else
#define VER_DEBUG             0
#endif

#define VERSIONFLAGS          (VER_PRIVATEBUILD|VER_PRERELEASE|VER_DEBUG)
#define VERSIONFILEFLAGSMASK  0x0030003FL
#pragma option pop /*P_O_Pop*/
