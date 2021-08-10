//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 2000 Inprise Corporation. All Rights Reserved.
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "trayicon.h"
#include "samp.h"
#include "trayicon.rh"
#pragma package(smart_init)
#pragma resource "*.res"
//---------------------------------------------------------------------------
__fastcall TTrayIcon::TTrayIcon(TComponent* Owner)
   : TComponent(Owner)
{
   FIcon = new TIcon();
   FTimer = new TTimer(NULL);

   FIconIndex = 0;
   FIcon->Assign(Application->Icon);
   FAppRestore = imDoubleClick;
   FOnAnimate = DoOnAnimate;
   FPopupMenuShow = imNone;
   FVisible = false;
   FHide = true;
   FTimer->Enabled = false;
   FTimer->OnTimer = OnAnimate;
   FTimer->Interval = 1000;

   if (!ComponentState.Contains(csDesigning))
   {
      memset(&FData, 0, sizeof(TNotifyIconData));
      FData.cbSize = sizeof(TNotifyIconData);
      FData.hWnd = AllocateHWnd(DoMessage);
      FData.uID = (UINT)this;
      FData.hIcon = FIcon->Handle;
      FData.uFlags = NIF_ICON | NIF_MESSAGE;
      FData.uCallbackMessage = WM_SYSTEM_TRAY_NOTIFY;

      FApplicationHook = ApplicationHookProc;
      Update();
   }
}
//---------------------------------------------------------------------------
__fastcall TTrayIcon::~TTrayIcon()
{
   if (!ComponentState.Contains(csDesigning))
   {
      Shell_NotifyIcon(NIM_DELETE, &FData);
      DeallocateHWnd(FData.hWnd);
   }

   if (FIcon)
      delete FIcon;

   if (FTimer)
      delete FTimer;
}
//---------------------------------------------------------------------------
void __fastcall TTrayIcon::Notification(TComponent *AComponent, TOperation Operation)
{
  TComponent::Notification(AComponent, Operation);

  if (Operation == opRemove)
  {
     if (AComponent == FIconList)
       FIconList = NULL;
     else if (AComponent == FPopupMenu)
       FPopupMenu = NULL;
  }
}
//---------------------------------------------------------------------------
void __fastcall TTrayIcon::Loaded()
{
   TComponent::Loaded();

   if (!FIconList)
   {
      FAnimate = false;
      FIcon->Assign(Application->Icon);
   }
   else
   {
      FTimer->Enabled = FAnimate;
      FIconList->GetIcon(FIconIndex, FIcon);
   }

   Update();
}
//---------------------------------------------------------------------------
void __fastcall TTrayIcon::SetVisible(bool Value)
{
   FVisible = Value;

   if (!ComponentState.Contains(csDesigning))
   {
      if (FVisible)
      {
         if (!Shell_NotifyIcon(NIM_ADD, &FData))
            throw EOutOfResources(LoadStr(sCannotCreate));

         Hide = true;
         Application->HookMainWindow(FApplicationHook);
      }
      else
      {
         if (!Shell_NotifyIcon(NIM_DELETE, &FData))
            throw EOutOfResources(LoadStr(sCannotRemove));

         Hide = false;
         Application->UnhookMainWindow(FApplicationHook);
      }
   }
}
//---------------------------------------------------------------------------
void __fastcall TTrayIcon::SetHint(String Hint)
{
   // The new hint must be different than the previous hint and less than
   // 64 characters to be modified. 64 is an operating system limit.
   if ((FHint != Hint) && (Hint.Length() < 64))
   {
      FHint = Hint;
      StrPLCopy(FData.szTip, Hint, sizeof(FData.szTip) - 1);

      // If there is no hint then there is no tool tip.
      if (Hint.Length())
         FData.uFlags = FData.uFlags | NIF_TIP;
      else
         FData.uFlags = FData.uFlags & !NIF_TIP;

      Update();
   }
}
//---------------------------------------------------------------------------
void __fastcall TTrayIcon::SetHide(bool Value)
{
   FHide = Value;
}
//---------------------------------------------------------------------------
int __fastcall TTrayIcon::GetAnimateInterval()
{
   return FTimer->Interval;
}
//---------------------------------------------------------------------------
void __fastcall TTrayIcon::SetAnimateInterval(int Value)
{
   FTimer->Interval = Value;
}
//---------------------------------------------------------------------------
bool __fastcall TTrayIcon::GetAnimate()
{
   return FAnimate;
}
//---------------------------------------------------------------------------
void __fastcall TTrayIcon::SetAnimate(bool Value)
{
   if (FIconList || ComponentState.Contains(csLoading))
      FAnimate = Value;

   if (FIconList && !ComponentState.Contains(csDesigning))
      FTimer->Enabled = Value;
}
//---------------------------------------------------------------------------
void __fastcall TTrayIcon::EndSession()
{
   Shell_NotifyIcon(NIM_DELETE, &FData);
}
//---------------------------------------------------------------------------
TShiftState TTrayIcon::ShiftState()
{
   TShiftState result;

   if (GetKeyState(VK_SHIFT) < 0)
      result << ssShift;
   if (GetKeyState(VK_CONTROL) < 0)
      result << ssCtrl;
   if (GetKeyState(VK_MENU) < 0)
      result << ssAlt;

   return result;
}
//---------------------------------------------------------------------------
void __fastcall TTrayIcon::DoMessage(TMessage &Message)
{
   TPoint point;
   TShiftState shift;

   switch(Message.Msg)
   {
      case WM_QUERYENDSESSION:
         Message.Result = 1;
         break;

      case WM_ENDSESSION:
         EndSession();
         break;

      case WM_SYSTEM_TRAY_NOTIFY:
         switch(Message.LParam)
         {
            case WM_MOUSEMOVE:
               if (FOnClick)
               {
                  shift = ShiftState();
                  GetCursorPos(&point);
                  DoMouseMove(shift, point.x, point.y);
               }
               break;

            case WM_LBUTTONDOWN:
               shift = ShiftState();
               shift << ssLeft;
               GetCursorPos(&point);
               DoMouseDown(mbLeft, shift, point.x, point.y);
               FIsClicked = true;
               break;

            case WM_LBUTTONUP:
               shift = ShiftState();
               shift << ssLeft;
               GetCursorPos(&point);

               if (FOnClick)
                  DoClick();

               DoMouseUp(mbLeft, shift, point.x, point.y);

               if (FAppRestore == imLeftClickUp)
                  Restore();
               if (FPopupMenuShow == imLeftClickUp)
                  ShowMenu();
               break;

            case WM_LBUTTONDBLCLK:
               DoDblClick();

               if (FAppRestore == imLeftDoubleClick)
                  Restore();
               if (FPopupMenuShow == imLeftDoubleClick)
                  ShowMenu();
               break;

            case WM_RBUTTONDOWN:
               shift = ShiftState();
               shift << ssRight;
               GetCursorPos(&point);
               DoMouseDown(mbRight, shift, point.x, point.y);
               break;

            case WM_RBUTTONUP:
               shift = ShiftState();
               shift << ssRight;
               GetCursorPos(&point);

               DoMouseUp(mbRight, shift, point.x, point.y);

               if (FAppRestore == imRightClickUp)
                  Restore();
               if (FPopupMenuShow == imRightClickUp)
                  ShowMenu();
               break;

            case WM_RBUTTONDBLCLK:
               DoDblClick();

               if (FAppRestore == imRightDoubleClick)
                  Restore();
               if (FPopupMenuShow == imRightDoubleClick)
                  ShowMenu();
               break;

            case WM_MBUTTONDOWN:
               shift = ShiftState();
               shift << ssMiddle;
               GetCursorPos(&point);

               DoMouseDown(mbMiddle, shift, point.x, point.y);
               break;

            case WM_MBUTTONUP:
               shift = ShiftState();
               shift << ssMiddle;
               GetCursorPos(&point);
               DoMouseUp(mbMiddle, shift, point.x, point.y);
               break;

            case WM_MBUTTONDBLCLK:
               DoDblClick();
               break;
         }
   }

   TComponent::Dispatch(&Message);
}
//---------------------------------------------------------------------------
void __fastcall TTrayIcon::ShowMenu()
{
   TPoint *point = new TPoint;

   GetCursorPos((tagPOINT*)point);

   try
   {
      if (Screen->ActiveForm->Handle != NULL)
         SetForegroundWindow(Screen->ActiveForm->Handle);
   }
   catch (...)
   {
   }

   FPopupMenu->Popup(point->x, point->y);

   delete point;
}
//---------------------------------------------------------------------------
void __fastcall TTrayIcon::DoClick()
{
   if (FAppRestore == imClick)
      Restore();
   if (FPopupMenuShow == imClick)
      ShowMenu();

   if (FOnClick)
      FOnClick(this);
}
//---------------------------------------------------------------------------
void __fastcall TTrayIcon::DoDblClick()
{
   if (FAppRestore == imDoubleClick)
      Restore();
   if (FPopupMenuShow == imDoubleClick)
      ShowMenu();

   if (FOnDblClick)
      FOnDblClick(this);
}
//---------------------------------------------------------------------------
void __fastcall TTrayIcon::DoMouseMove(TShiftState Shift, int X, int Y)
{
   if (FOnMouseMove)
      FOnMouseMove(this, Shift, X, Y); 
}
//---------------------------------------------------------------------------
void __fastcall TTrayIcon::DoMouseDown(TMouseButton Button, TShiftState Shift,
                                       int X, int Y)
{
   if (FAppRestore == imMouseDown)
      Restore();
   if (FPopupMenuShow == imMouseDown)
      ShowMenu();

   if (FOnMouseDown)
      FOnMouseDown(this, Button, Shift, X, Y);
}
//---------------------------------------------------------------------------
void __fastcall TTrayIcon::DoMouseUp(TMouseButton Button, TShiftState Shift,
                                     int X, int Y)
{
   if (FAppRestore == imMouseDown)
      Restore();
   if (FPopupMenuShow == imMouseDown)
      ShowMenu();

   if (FOnMouseUp)
      FOnMouseUp(this, Button, Shift, X, Y);
}
//---------------------------------------------------------------------------
void __fastcall TTrayIcon::DoOnAnimate(TObject *Sender)
{
   if (IconIndex < FIconList->Count)
      FIconIndex++;
   else
      FIconIndex = 0;

   SetIconIndex(FIconIndex);
   Update();
}
//---------------------------------------------------------------------------
// When the application minimizes, hide it, so only the icon in the system
// tray is visible.
//---------------------------------------------------------------------------
void __fastcall TTrayIcon::Minimize()
{
   Application->Minimize();
   ShowWindow(Application->Handle, SW_HIDE);

   if (FOnMinimize)
      FOnMinimize(this);
}
//---------------------------------------------------------------------------
// Restore the application by making its window visible again, which is a
// little weird since its window is invisible, having no height or width, but
// that's what determines whether the button appears on the taskbar.
//---------------------------------------------------------------------------
void __fastcall TTrayIcon::Restore()
{
   Application->Restore();
   ShowWindow(Application->Handle, SW_RESTORE);
   SetForegroundWindow(Application->Handle);

   if (FOnRestore)
      FOnRestore(this);
}
//---------------------------------------------------------------------------
void __fastcall TTrayIcon::Update()
{
   if (!ComponentState.Contains(csDesigning))
   {
      FData.hIcon = FIcon->Handle;

      if (Visible == true)
         Shell_NotifyIcon(NIM_MODIFY, &FData);
   }
}
//---------------------------------------------------------------------------
void __fastcall TTrayIcon::SetIconIndex(int Value)
{
   FIconIndex = Value;

   if (FIconList)
      FIconList->GetIcon(FIconIndex, FIcon);

   Update();
}
//---------------------------------------------------------------------------
bool __fastcall TTrayIcon::ApplicationHookProc(TMessage &Message)
{
   if (Message.Msg == WM_SYSCOMMAND)
   {
      if (Message.WParam == SC_MINIMIZE)
         Minimize();
      if (Message.WParam == SC_RESTORE)
         Restore();
   }

   return false;
}
//---------------------------------------------------------------------------
void __fastcall TTrayIcon::SetDefaultIcon()
{
  FIcon->Assign(Application->Icon);
  Update();
}
//---------------------------------------------------------------------------
HWND __fastcall TTrayIcon::GetHandle()
{
   return FData.hWnd;
}
//---------------------------------------------------------------------------


// Register and ValidCtrCheck need to be removed and placed in another package.


//---------------------------------------------------------------------------
// ValidCtrCheck is used to assure that the components created do not have
// any pure virtual functions.
//

static inline void ValidCtrCheck(TTrayIcon *)
{
   new TTrayIcon(NULL);
}
namespace Trayicon
{
   void __fastcall PACKAGE Register()
   {
       TComponentClass classes[1] = {__classid(TTrayIcon)};
       RegisterComponents(LoadStr(Tab_101), classes, 0);
   }
}
//---------------------------------------------------------------------------

