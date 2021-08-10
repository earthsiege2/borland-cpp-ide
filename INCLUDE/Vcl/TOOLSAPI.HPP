// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

//Used to redefine the PASCALIMPLEMENTATION and DELPHICLASS after ToolApi.Hpp
// undefines then.

#include <ToolApi.Hpp>

#undef DELPHICLASS
#undef PASCALIMPLEMENTATION

#define PASCALIMPLEMENTATION __declspec(pascalimplementation, package) // Implemented in Delphi - no code should be generated
#define DELPHICLASS          __declspec(delphiclass, package)   // Implemented in Delphi (C++ does not generate RTTI)


