[!outputon] // $Revision:   1.1.1.0.1.0  $
//---------------------------------------------------------------------------
[!if=(CLX, "TRUE")]
#include <clx.h>
[!else]
#include <vcl.h>
[!endif]
#pragma hdrstop

#include "[!ModuleName].h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
[!if=(CLX, "TRUE")]
#pragma resource "*.xfm"
[!else]
#pragma resource "*.dfm"
[!endif]
T[!ImplClassName] *[!ImplClassName];
//---------------------------------------------------------------------------
__fastcall T[!ImplClassName]::T[!ImplClassName](TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

