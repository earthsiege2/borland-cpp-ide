//----------------------------------------------------------------------------
#ifndef DCDemoH
#define DCDemoH
//----------------------------------------------------------------------------
#include <vcl\Classes.hpp>
#include <vcl\Controls.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Forms.hpp>
//----------------------------------------------------------------------------
class TDCDemoForm : public TForm
{
__published:
    TPanel *Panel1;
    TDecisionPivot *DecisionPivot1;
    TDecisionCube *DecisionCube1;
    TDecisionQuery *DecisionQuery1;
    TDecisionSource *DecisionSource1;
    TDecisionGrid *DecisionGrid1;
private:
public:
	virtual __fastcall TDCDemoForm(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TDCDemoForm *DCDemoForm;
//----------------------------------------------------------------------------
#endif
