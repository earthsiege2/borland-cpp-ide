//---------------------------------------------------------------------------

#ifndef bufferlistformH
#define bufferlistformH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TBufferListFrm : public TForm
{
__published:	// IDE-managed Components
        TButton *CancelButton;
        TButton *OKButton;
        TListBox *BufferListBox;
        void __fastcall BufferListBoxDblClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TBufferListFrm(TComponent* Owner);
};
//---------------------------------------------------------------------------
#endif
