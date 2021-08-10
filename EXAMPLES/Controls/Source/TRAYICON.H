//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 2000 Inprise Corporation. All Rights Reserved.
//---------------------------------------------------------------------------
#ifndef TRAYICON_H
#define TRAYICON_H
//---------------------------------------------------------------------------
#include <System.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Forms.hpp>
#include <ShellAPI.hpp>
#include <StdLib.h>

//---------------------------------------------------------------------------
#define WM_SYSTEM_TRAY_NOTIFY (WM_USER + 1)

enum TTrayIconMessage {imClick, imDoubleClick, imMouseDown,
                       imMouseUp, imLeftClickUp, imLeftDoubleClick,
                       imRightClickUp, imRightDoubleClick, imNone};

//---------------------------------------------------------------------------
class PACKAGE TTrayIcon : public TComponent
{
private:
   TNotifyIconData FData;
   bool FIsClicked;
   TIcon *FIcon;
   TImageList* FIconList;
   TPopupMenu* FPopupMenu;
   TTimer *FTimer;
   String FHint;
   int FIconIndex;
   bool FVisible;
   bool FHide;
   bool FAnimate;
   TTrayIconMessage FAppRestore;
   TTrayIconMessage FPopupMenuShow;
   TWindowHook FApplicationHook;

   TNotifyEvent FOnMinimize;
   TNotifyEvent FOnRestore;
   TMouseMoveEvent FOnMouseMove;
   TMouseMoveEvent FOnMouseExit;
   TMouseMoveEvent FOnMouseEnter;
   TNotifyEvent FOnClick;
   TNotifyEvent FOnDblClick;
   TMouseEvent FOnMouseDown;
   TMouseEvent FOnMouseUp;
   TNotifyEvent FOnAnimate;
   TNotifyEvent FOnCreate;
   TNotifyEvent FOnDestroy;
   TNotifyEvent FOnActivate;
   TNotifyEvent FOnDeactivate;

   void __fastcall SetHint(String Hint);
   void __fastcall SetHide(bool Value);
   int __fastcall GetAnimateInterval();
   void __fastcall SetAnimateInterval(int Value);
   bool __fastcall GetAnimate();
   void __fastcall SetAnimate(bool Value);
   void __fastcall EndSession();

   TShiftState ShiftState();

protected:
   virtual void __fastcall SetVisible(bool Value);

   virtual void __fastcall DoMessage(TMessage &Message);
   virtual void __fastcall DoClick();
   virtual void __fastcall DoDblClick();
   virtual void __fastcall DoMouseMove(TShiftState Shift, int X, int Y);
   virtual void __fastcall DoMouseDown(TMouseButton Button, TShiftState Shift, int X, int Y);
   virtual void __fastcall DoMouseUp(TMouseButton Button, TShiftState Shift, int X, int Y);
   virtual void __fastcall DoOnAnimate(TObject *Sender);
   virtual void __fastcall Notification(TComponent *AComponent, TOperation Operation);

   bool __fastcall ApplicationHookProc(TMessage &Message);

   virtual void __fastcall Loaded();
   __property TNotifyIconData Data = {read=FData};

public:
   __fastcall TTrayIcon(TComponent* Owner);
   __fastcall ~TTrayIcon();

   virtual void __fastcall Minimize();
   virtual void __fastcall Restore();
   virtual void __fastcall Update();
   virtual void __fastcall ShowMenu();
   virtual void __fastcall SetIconIndex(int Value);
   virtual void __fastcall SetDefaultIcon();
   HWND __fastcall GetHandle();

__published:
   // Properties
   __property bool Visible = {read=FVisible,write=SetVisible,default=false};
   __property String Hint = {read=FHint,write=SetHint};
   __property TPopupMenu* PopupMenu = {read=FPopupMenu,write=FPopupMenu};
   __property bool Hide = {read=FHide,write=SetHide};
   __property TTrayIconMessage RestoreOn = {read=FAppRestore,write=FAppRestore};
   __property TTrayIconMessage PopupMenuOn = {read=FPopupMenuShow,write=FPopupMenuShow};
   __property TImageList* Icons = {read=FIconList,write=FIconList};
   __property int IconIndex = {read=FIconIndex,write=SetIconIndex,default=0};
   __property int AnimateInterval = {read=GetAnimateInterval,write=SetAnimateInterval,default=1000};
   __property bool Animate = {read=GetAnimate,write=SetAnimate,default=false};
   __property bool Handle = {read=GetHandle};

   // Events
    __property TNotifyEvent OnMinimize = {read=FOnMinimize,write=FOnMinimize};
    __property TNotifyEvent OnRestore = {read=FOnRestore,write=FOnRestore};
    __property TNotifyEvent OnClick = {read=FOnClick,write=FOnClick};
    __property TMouseMoveEvent OnMouseEnter = {read=FOnMouseEnter,write=FOnMouseEnter};
    __property TMouseMoveEvent OnMouseExit = {read=FOnMouseExit,write=FOnMouseExit};
    __property TMouseMoveEvent OnMouseMove = {read=FOnMouseMove,write=FOnMouseMove};
    __property TMouseEvent OnMouseUp = {read=FOnMouseUp,write=FOnMouseUp};
    __property TMouseEvent OnMouseDown = {read=FOnMouseDown,write=FOnMouseDown};
    __property TNotifyEvent OnAnimate = {read=FOnAnimate,write=FOnAnimate};
    __property TNotifyEvent OnCreate = {read=FOnCreate,write=FOnCreate};
    __property TNotifyEvent OnDestroy = {read=FOnDestroy,write=FOnDestroy};
    __property TNotifyEvent OnActivate = {read=FOnActivate,write=FOnActivate};
    __property TNotifyEvent OnDeactivate = {read=FOnDeactivate,write=FOnDeactivate};
};
//---------------------------------------------------------------------------
#endif
