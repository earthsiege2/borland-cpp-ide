//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   source\owl\clipboard.cpp
//   Owl Encapsulated clipboards
//----------------------------------------------------------------------------
#define _INC_OLE
#include <owl\clipboar.h>

TClipboard TClipboard::TheClipboard;

const char* TClipboard::DefaultProtocol = "StdFileEditing";
