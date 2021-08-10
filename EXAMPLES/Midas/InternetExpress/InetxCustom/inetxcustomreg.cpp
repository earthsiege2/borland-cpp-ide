//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "inetxcustomreg.h"


//---------------------------------------------------------------------------

#pragma package(smart_init)

bool __fastcall TImgButtonsEditorHelper::ImplCanAddClassHelper(Classes::TComponent* AEditor, Classes::TComponent* AParent, TMetaClass* AClass)
{
  long I;
  _di_IGetWebComponentList Intf;
  bool Result = False;
  if (AEditor->InheritsFrom(__classid(TImgDataNavigator)))
  {
    Result = True;
    AParent->GetInterface(__uuidof(IGetWebComponentList), &Intf);
    TWebComponentList * List;
    List = (TWebComponentList*)(Intf->GetComponentList());
    // Don't allow duplicates
    for (I = 0; I < List->Count; I++)
      if (List->WebComponents[I]->ClassType() == AClass)
      {
        Result = False;
        break;
      }
  }
  return Result;
}



TImgButtonsEditorHelper * ImgButtonsEditorHelper;

namespace Inetxcustomreg
{
        void __fastcall PACKAGE Register()
        {
                 {
                 TComponentClass classes[1] = {__classid(TReconcilePageProducer)};
                 RegisterComponents("InternetExpress", classes, 0);
                 }

                 {
                 ImgButtonsEditorHelper = new TImgButtonsEditorHelper;
                 TComponentClass classes[11] = {
                   __classid(TImgFirstButton),
                   __classid(TImgPriorPageButton),
                   __classid(TImgPriorButton),
                    __classid(TImgNextButton),
                    __classid(TImgNextPageButton),
                    __classid(TImgLastButton),
                    __classid(TImgInsertButton),
                    __classid(TImgDeleteButton),
                    __classid(TImgUndoButton),
                    __classid(TImgPostButton),
                    __classid(TImgApplyUpdatesButton)
                   };
                 RegisterWebComponents(classes, 10, ImgButtonsEditorHelper);
                 }

                 {
                 TComponentClass classes[1] = {__classid(TImgDataNavigator)};
                 RegisterWebComponents(classes, 0,
                   NULL);
                 }

                 {
                 TComponentClass classes[2] = {__classid(TShowXMLButton),
                   __classid(TShowDeltaButton)};
                 RegisterWebComponents(classes, 1, NULL);
                 }
        }
}

void Unregister()
{
   {
   TComponentClass classes[11] = {
     __classid(TImgFirstButton),
     __classid(TImgPriorPageButton),
     __classid(TImgPriorButton),
      __classid(TImgNextButton),
      __classid(TImgNextPageButton),
      __classid(TImgLastButton),
      __classid(TImgInsertButton),
      __classid(TImgDeleteButton),
      __classid(TImgUndoButton),
      __classid(TImgPostButton),
      __classid(TImgApplyUpdatesButton)
     };
   UnRegisterWebComponents(classes, 10);
   }

   {
   TComponentClass classes[1] = {__classid(TImgDataNavigator)};
   UnRegisterWebComponents(classes, 0);
   }

   {
   TComponentClass classes[2] = {__classid(TShowXMLButton),
   __classid(TShowDeltaButton)};
   UnRegisterWebComponents(classes, 1);
   }

   if (ImgButtonsEditorHelper)
   {
     delete ImgButtonsEditorHelper;
   }
}

#pragma exit Unregister

