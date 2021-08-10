//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ShellCtrls.h"
#include "ShellReg.h"
#include "ShellConsts.h"
#include "RootEdit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
// This is where the functions go
//---------------------------------------------------------------------------
namespace Shellreg
{
    void __fastcall PACKAGE Register()
    {
        //GroupDescendentsWith(__classid(TShellChangeNotifier), __classid(Controls::TControl));

        TComponentClass classes[4] = {
                                    __classid(TShellTreeView)
                                    ,__classid(TShellComboBox)
                                    ,__classid(TShellListView)
                                    ,__classid(TShellChangeNotifier)
                                    };

        RegisterComponents(SPalletePage, classes, (sizeof(classes)/sizeof(TComponentClass))-1);

        // This is now to register property editors for AnsiString's.
        PPropInfo PropInfo = GetPropInfo(__typeinfo(TShellTreeView), SPropertyName);
        RegisterPropertyEditor(*(PropInfo->PropType),
            __classid(TShellTreeView), SPropertyName, __classid(TRootProperty));
            
        PropInfo = GetPropInfo(__typeinfo(TShellComboBox), SPropertyName);
        RegisterPropertyEditor(*(PropInfo->PropType),
            __classid(TShellComboBox), SPropertyName, __classid(TRootProperty));

        PropInfo = GetPropInfo(__typeinfo(TShellListView), SPropertyName);
        RegisterPropertyEditor(*(PropInfo->PropType),
            __classid(TShellListView), SPropertyName, __classid(TRootProperty));


        PropInfo = GetPropInfo(__typeinfo(TShellChangeNotifier), SPropertyName);
        RegisterPropertyEditor(*(PropInfo->PropType),
            __classid(TShellChangeNotifier), SPropertyName, __classid(TRootProperty));

        RegisterComponentEditor(__classid(TShellTreeView), __classid(TRootEditor));
        RegisterComponentEditor(__classid(TShellListView), __classid(TRootEditor));
        RegisterComponentEditor(__classid(TShellComboBox), __classid(TRootEditor));
        RegisterComponentEditor(__classid(TShellChangeNotifier), __classid(TRootEditor));
    }
}