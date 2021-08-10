//----------------------------------------------------------------------------
#ifndef ChildWinH
#define ChildWinH
//----------------------------------------------------------------------------
#include <vcl\Controls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\Classes.hpp>
#include <vcl\Windows.hpp>
#include <vcl\System.hpp>
#include <StdCtrls.hpp>
//----------------------------------------------------------------------------
class TMDIChild : public TForm
{
__published:
	TMemo *Memo1;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:
public:
	virtual __fastcall TMDIChild(TComponent *Owner);
};
//----------------------------------------------------------------------------
#endif	
