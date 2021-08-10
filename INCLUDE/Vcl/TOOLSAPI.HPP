// Borland C++ Builder
// Copyright (c) 1995, 2002 Borland Software Corporation
// All rights reserved

//Used to redefine the PASCALIMPLEMENTATION and DELPHICLASS after ToolApi.Hpp
// undefines then.

#include <ToolApi.Hpp>

#undef DELPHICLASS
#undef PASCALIMPLEMENTATION

#define PASCALIMPLEMENTATION __declspec(pascalimplementation, package) // Implemented in Delphi - no code should be generated
#define DELPHICLASS          __declspec(delphiclass, package)   // Implemented in Delphi (C++ does not generate RTTI)


