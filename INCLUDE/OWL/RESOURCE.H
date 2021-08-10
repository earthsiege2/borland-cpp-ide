//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.3  $
//
// Defines classes handling Windows resources
//----------------------------------------------------------------------------
#if !defined(OWL_RESOURCE_H)
# define OWL_RESOURCE_H

#if !defined(OWL_DEFS_H)
# include <owl/defs.h>
#endif
#if !defined(OWL_GDIBASE_H)
# include <owl/gdibase.h>
#endif
#if !defined(SERVICES_WSYSINC_H)
# include <services/wsysinc.h>
#endif
#if !defined(WINSYS_WSYSCLS_H)
# include <winsys/wsyscls.h>
#endif

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

//
// Predefined resource types
//
#if !defined(RT_TOOLBAR) && defined(BI_PLAT_WIN32)
# define RT_TOOLBAR  MAKEINTRESOURCE(241)
#endif
#if !defined(RT_NEWDIALOG) && defined(BI_PLAT_WIN32)
# define RT_NEWDIALOG MAKEINTRESOURCE(0x2000|0x0005)
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

// Forward ref.
//
class _OWLCLASS TBitmap;
class _OWLCLASS TGadgetWindow;

//
// The DLGTEMPLATE structure, documented in the Windows Programmer's
// is defined only in the 32-bit system headers.
//
#if defined(BI_PLAT_WIN16)
# if !defined(DLGTEMPLATE_DEFINED)
    struct  DLGTEMPLATE {  
      DWORD   style;
      BYTE    cdit;
      int     x;
      int     y;
      int     cx;
      int     cy;
      // char MenuName[];
      // char ClassName[];
      // char CaptionText[];
    };
#   define DLGTEMPLATE_DEFINED
# endif  
#endif    

//
//
//
#if defined(BI_PLAT_WIN32)
# if !defined(DLGTEMPLATEEX_DEFINED)
    struct  DLGTEMPLATEEX {
      ushort  version;
      ushort  signature;
      uint32  helpId;
      uint32  exStyle;
      uint32  style;
      ushort  itemCount;
      short   x;
      short   y;
      short   cx;
      short   cy;
      // wchar_t MenuName[];          // Name or ordinal
      // wchar_t ClassName[];         // Name or ordinal
      // wchar_t CaptionText[];
    };
#   define  DLGTEMPLATEEX_DEFINED
# endif  
#endif

//
// Structure describing the binary layout of toolbar resources
// NOTE: Toolbar resource is only available in 32-bit
//
#if defined(BI_PLAT_WIN32)
# if !defined(TOOLBARTEMPLATE_DEFINED)
    struct TOOLBARTEMPLATE {
      ushort    version;          // Resource version
      ushort    width;            // Width of each bitmap glyph
      ushort    height;           // Height of each bitmap glyph
      ushort    count;            // Number of glyphs
      ushort    ids[1];           // Array of ids of glyphs+separators
    };
#   define TOOLBARTEMPLATE_DEFINED    
# endif
#endif


//
// class TToolbarRes
// ~~~~~ ~~~~~~~~~~~
//
#if defined(BI_PLAT_WIN32)
class _OWLCLASS TToolbarRes : public TResource<TOOLBARTEMPLATE, RT_TOOLBAR> {
  public:
    TToolbarRes(HINSTANCE hInst, TResId id, TAutoDelete = AutoDelete);
   ~TToolbarRes();

    TBitmap&    GetBitmap();
    int         GetCount() const;
    ushort*     GetIds() const;
    int         GetWidth() const;
    int         GetHeight() const;

  protected:
    TBitmap*    ToolbarBitmap;
    bool        ShouldDelete;
    TOOLBARTEMPLATE& TBInfo() const;
};

//
// class TToolbarBldr
// ~~~~~ ~~~~~~~~~~~~
class _OWLCLASS TToolbarBldr {
  public:
    TToolbarBldr(TGadgetWindow& win, TResId id, HINSTANCE hinst = 0);
   ~TToolbarBldr();
    void            Build();

  protected:
    TGadgetWindow&  Win;
    TToolbarRes*    TbarRes;
    TResId          Id;
    HINSTANCE       Hinst;
};
#endif  //  BI_PLAT_WIN32

//
// class TDialogRes
// ~~~~~ ~~~~~~~~~~
//
class _OWLCLASS TDialogRes {
  public:
    TDialogRes(HINSTANCE hInstance, TResId id);
#if defined(BI_PLAT_WIN32)
    TDialogRes(HINSTANCE hInstance, TResId id, LANGID langid);
#endif
   ~TDialogRes();

    // Validate resource was found, loaded & locked
    //
    bool            IsOK() const;
    
    // Retrieve information about the underlying binary template
    //
#if defined(BI_PLAT_WIN32)
    bool            IsDialogEx() const;
    DLGTEMPLATEEX*  GetTemplateEx() const;
#endif
    DLGTEMPLATE*    GetTemplate() const;

    // Querry about info. stored in template
    //
    void      GetRect(TRect& rect) const;

    //
    // Enumeration of various strings stored with a dialog resource
    //
    enum TDlgResText {
      drtMenuName,              // String of menu resource used by dialog
      drtClassName,             // Class name of dialog
      drtCaption                // Caption of dialog
    };

    //
    // Retrieve a particular string from the resource
    //
    int       GetText(char far* buffer, int size, 
                      TDlgResText which = drtCaption) const;

  protected:
    TResource<DLGTEMPLATE, RT_DIALOG>*      OldResource;
#if defined(BI_PLAT_WIN32)
    TResource<DLGTEMPLATEEX, RT_NEWDIALOG>* NewResource;
#endif
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

#endif  //  OWL_RESOURCE_H
