//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.10  $
//
// Definition of class TStatic, the class for static controls and base for
// any control that manages simple text.
//----------------------------------------------------------------------------
#if !defined(OWL_STATIC_H)
#define OWL_STATIC_H

#if !defined(OWL_CONTROL_H)
# include <owl/control.h>
#endif

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TStatic
// ~~~~~ ~~~~~~~
class _OWLCLASS TStatic : public TControl {
  public:
#if defined(BI_PLAT_WIN32)
    // For use with G\SetImage 
    enum TImageType { Bitmap=IMAGE_BITMAP, Icon=IMAGE_ICON, 
                      Cursor=IMAGE_CURSOR, EnhMetaFile=IMAGE_ENHMETAFILE 
                    };
#endif

    TStatic(TWindow*        parent,
            int             id,
            const char far* title,
            int x, int y, int w, int h,
            uint            textLen = 0,
            TModule*        module = 0);

    TStatic(TWindow*   parent,
            int        resourceId,
            uint       textLen = 0,
            TModule*   module = 0);

    // Returns the length of the control's text
    //
    int   GetTextLen() const;

    // Fills the given string with the text of the control.  Returns the
    // number of characters copied.
    // Sets the contents of the associated static text control to the given
    // string
    //
    int   GetText(char far* str, int maxChars) const;
    void  SetText(const char far* str);

    // Clears the text of the associated static text control
    //
    virtual void Clear();

    // Returns / sets the length limit of the control's text
    //
    uint  GetTextLimit() const;
    void  SetTextLimit(uint textlimit);

    // Set and Get icon for Statics with the SS_ICON style
    //
    HICON GetIcon() const;
    HICON SetIcon(HICON);

    // Override TWindow virtual member functions
    //
    uint  Transfer(void* buffer, TTransferDirection direction);

#if defined(BI_PLAT_WIN32)
    // Set\Get image associated with static control
    //
    HANDLE GetImage(TImageType imageType = Bitmap) const;
    HANDLE SetImage(HANDLE image, TImageType imageType = Bitmap );
#endif

  protected:
    // Override TWindow virtual member functions
    //
    char far* GetClassName();

    // Make sure that control is re-painted when resized
    //
    void EvSize(uint sizeType, TSize& size);

  public_data:
    union {
#if defined(OWL2_COMPAT)
      uint  TextLen;    // obsolete name
#endif
      uint  TextLimit;  // Maximum length of text in edit control
    };

  private:
    // Hidden to prevent accidental copying or assignment
    //
    TStatic(const TStatic&);
    TStatic& operator =(const TStatic&);

  DECLARE_STREAMABLE(_OWLCLASS, TStatic, 1);
  DECLARE_RESPONSE_TABLE(TStatic);
};

//
// Static control notifications (Win32 only). Methods are: void Method()
//
// EV_STN_CLICKED(id, method)
// EV_STN_DBLCLK(id, method)
// EV_STN_ENABLE(id, method)
// EV_STN_DISABLE(id, method)
//


// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

//----------------------------------------------------------------------------
// Inline implementations
//

//
// Return the handle of the icon used for this static control.
//
inline HICON TStatic::GetIcon() const {
  PRECONDITION(GetHandle());
  return (HICON)CONST_CAST(TStatic*,this)->SendMessage(STM_GETICON);
}

//
// Set the handle of the icon.
//
inline HICON TStatic::SetIcon(HICON icon) {
  PRECONDITION(GetHandle());
  return (HICON)SendMessage(STM_SETICON, TParam1(icon));
}

#if defined(BI_PLAT_WIN32)
//
// Return handle of image used for static control
//
inline HANDLE TStatic::GetImage(TImageType imageType) const
{
  PRECONDITION(GetHandle());
  return (HANDLE)CONST_CAST(TStatic*,this)->SendMessage(STM_GETIMAGE,(TParam2)imageType);
}

//
// Set handle of image.
//
inline HANDLE TStatic::SetImage(HANDLE image, TImageType imageType)
{
  PRECONDITION(GetHandle());
  return (HANDLE)SendMessage(STM_SETIMAGE, (TParam1)imageType, (TParam2)image);
}
#endif

//
// Return the current length of the text in the control.
//
inline int TStatic::GetTextLen() const {
  PRECONDITION(GetHandle());
  return ::GetWindowTextLength(GetHandle());
}

//
// Retrieve the current text in the control.
//
inline int TStatic::GetText(char far* str, int maxChars) const {
  PRECONDITION(GetHandle());
  return ::GetWindowText(GetHandle(), str, maxChars);
}

//
// Set the text in the control.
//
inline void TStatic::SetText(const char far* str) {
  PRECONDITION(GetHandle());
  ::SetWindowText(GetHandle(), str);
}

//
// Return the maximum number of characters that can be displayed in the control.
//
inline uint TStatic::GetTextLimit() const {
  return TextLimit;
}

//
// Set the maximum number of characters to display in the control.
//
inline void TStatic::SetTextLimit(uint textlimit) {
  TextLimit = textlimit;
}

#endif  // OWL_STATIC_H
