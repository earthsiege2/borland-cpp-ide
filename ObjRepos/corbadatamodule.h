//---------------------------------------------------------------------------
[!outputon] // $Revision:   1.2.1.0.1.0  $
#ifndef [!ModuleName]H
#define [!ModuleName]H
//---------------------------------------------------------------------------
#include <Classes.hpp>
[!if=(CLX, "TRUE")]
#include <QControls.hpp>
#include <QStdCtrls.hpp>
#include <QForms.hpp>
[!else]
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
[!endif]
//---------------------------------------------------------------------------
class T[!ImplClassName] : public TDataModule /* [!SkeletonClassName] [!IdlInterfaceToken] */
{
__published:	// IDE-managed Components
private:	// User declarations
public:		// User declarations
	__fastcall T[!ImplClassName](TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE T[!ImplClassName] *[!ImplClassName];
//---------------------------------------------------------------------------
#endif

