[!outputon] // $Revision:   1.2  $
[!if=(Requesting, "ConsoleProject_Includes")]
#include <corbapch.h>
#pragma hdrstop
#include <corba.h>
#include <condefs.h>
[!else]
[!if=(Requesting, "ConsoleVclProject_Includes")]
#include <vcl.h>
#pragma hdrstop
#include <corba.h>
[!else]
[!if=(Requesting, "WindowsProject_Includes")]
#pragma hdrstop
#include <corba.h>
[!else]
[!if=(Requesting, "UnitNoVcl_Includes")]
#include <corbapch.h>
#pragma hdrstop
#include <corba.h>
[!else]
[!if=(Requesting, "Unit_Includes")]
#pragma hdrstop
#include <corba.h>
[!endif]
[!endif]
[!endif]
[!endif]
[!endif]

