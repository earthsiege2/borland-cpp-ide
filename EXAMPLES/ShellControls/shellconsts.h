// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

#ifndef ShellConstsH
#define ShellConstsH

#include <SysInit.hpp>
#include <System.hpp>

//-- user supplied -----------------------------------------------------------

namespace Shellconsts
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
#define SShellDefaultNameStr "Name"
#define SShellDefaultSizeStr "Size"
#define SShellDefaultTypeStr "Type"
#define SShellDefaultModifiedStr "Modified"
#define SShellNoDetails "Unable to retrieve folder details for \"%s\". Error code $%x"
#define SCallLoadDetails "%s: Missing call to LoadColumnDetails"
#define SPalletePage "Samples"
#define SPropertyName "Root"
#define SRenamedFailedError "Rename to %s failed"

#define SRFDesktop "rfDesktop"
#define SCmdVerbOpen "open"
#define SCmdVerbRename "rename"
#define SCmdVerbDelete "delete"
#define SCmdVerbPaste "paste"

}	/* namespace Shellconsts */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Shellconsts;
#endif

//-- end unit ----------------------------------------------------------------
#endif	// ShellConsts
