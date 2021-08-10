//---------------------------------------------------------------------------
[!outputon] // $Revision:   1.2  $
#ifndef [!ModuleName]H
#define [!ModuleName]H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
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

