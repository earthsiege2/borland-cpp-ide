//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1997 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------
#ifndef diroutlnH
#define diroutlnH
//---------------------------------------------------------------------------
#include <sysutils.hpp>
#include <controls.hpp>
#include <classes.hpp>
#include <forms.hpp>
#include <Outline.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------

namespace Diroutln {
enum TTextCase { tcLowerCase, tcUpperCase, tcAsIs };

class PACKAGE TDirectoryOutline : public TCustomOutline
{
private:
    typedef AnsiString (__fastcall *TCaseFunction)(const AnsiString AString);
    static int __fastcall DriveToInt(char);
    static char __fastcall IntToDrive(int);
    long __fastcall GetChildNamed(const AnsiString& Name, long Item);
    
    static const InvalidIndex;
    static const RootIndex;
    static void* APointer;

    char FDrive;
    TFileName FDirectory;
    TNotifyEvent FOnChange;
    TTextCase FTextCase;
    TCaseFunction FCaseFunction;
    
    
protected:
    void __fastcall SetDrive(char NewDrive);
    void __fastcall SetDirectory(TFileName NewDirectory);
    void __fastcall SetTextCase(TTextCase NewTextCase);
    void __fastcall AssignCaseProc();
    void __fastcall WalkTree(const AnsiString& Dest);
    
    virtual void __fastcall BuildOneLevel(long RootItem);
    virtual void __fastcall BuildTree();
    virtual void __fastcall BuildSubTree(long RootItem);
    virtual void __fastcall Change();

    // virtual overrides from base
    DYNAMIC void __fastcall Click();
    virtual void __fastcall CreateWnd();
    DYNAMIC void __fastcall Expand(int Index);
    virtual void __fastcall Loaded();

    // helper statics
    static AnsiString CurDir();
    

public:
    virtual __fastcall TDirectoryOutline(TComponent* Owner);

    AnsiString __fastcall ForceCase(const AnsiString& AString);

    __property char Drive = { read = FDrive, write = SetDrive };
    __property TFileName Directory =
            { read = FDirectory, write = SetDirectory };

    // from base class
    __property Lines = { stored = false };

__published:
    // new properties
    __property TNotifyEvent OnChange = { read = FOnChange, write = FOnChange };
    __property TTextCase TextCase = { read = FTextCase, write = SetTextCase };

    // properties from base classes
    __property Align;
    __property BorderStyle;
    __property Color;
    __property Ctl3D;
    __property DragCursor;
    __property DragMode;
    __property Enabled;
    __property Font;
    __property ItemHeight;
    __property OnClick;
    __property OnCollapse;
    __property OnDblClick;
    __property OnDragDrop;
    __property OnDragOver;
    __property OnDrawItem;
    __property OnEndDrag;
    __property OnEnter;
    __property OnExit;
    __property OnExpand;
    __property OnKeyDown;
    __property OnKeyPress;
    __property OnKeyUp;
    __property OnMouseDown;
    __property OnMouseMove;
    __property OnMouseUp;
    __property Options;
    __property ParentColor;
    __property ParentCtl3D;
    __property ParentFont;
    __property ParentShowHint;
    __property PictureClosed;
    __property PictureLeaf;
    __property PictureOpen;
    __property PopupMenu;
    __property ScrollBars;
    __property Style;
    __property ShowHint;
    __property TabOrder;
    __property TabStop;
    __property Visible;
};
} //end namespace
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Diroutln;
#endif
//---------------------------------------------------------------------------
#endif
