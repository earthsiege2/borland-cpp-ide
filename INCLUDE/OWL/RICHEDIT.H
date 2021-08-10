//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.14  $
//
// Definition of class TRichEdit.
//----------------------------------------------------------------------------
#if !defined(OWL_RICHEDIT_H)
#define OWL_RICHEDIT_H

#if !defined(BI_PLAT_WIN32)
# error OWL: The Rich Edit encapsulation can only be used for WIN32 targets
#endif

#if !defined(OWL_EDITFILE_H)
# include <owl/editfile.h>
#endif
#if !defined(OWL_COMMCTRL_H)
# include <owl/commctrl.h>
#endif
#if !defined(__RICHEDIT_H)
# include <richedit.h>
#endif
#if !defined(__RICHOLE_H)
# include <richole.h>
#endif

//
// Macro representing all CHARFORMAT flags
//
#if !defined(CFM_ALL)
#define CFM_ALL   (CFM_BOLD | CFM_ITALIC | CFM_UNDERLINE | CFM_STRIKEOUT |\
                   CFM_PROTECTED | CFM_SIZE | CFM_COLOR | CFM_FACE | \
                   CFM_OFFSET | CFM_CHARSET)
#endif

//
// Macro representing all the PARAFORMAT flags
//
#if !defined(PFM_ALL)
#define PFM_ALL (PFM_ALIGNMENT|PFM_NUMBERING|PFM_OFFSET|PFM_OFFSETINDENT|\
                 PFM_RIGHTINDENT|PFM_STARTINDENT|PFM_TABSTOPS)
#endif

//
// Forward References
//
class _OWLCLASS TRichEdit;


// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TCharFormat
// ~~~~~ ~~~~~~~~~~~
// TCharFormat encapsulates the CHARFORMAT structure which contains
// information about character formatting in a rich edit control.
//
class _OWLCLASS TCharFormat : public CHARFORMAT {
  public:
    TCharFormat(ulong mask = 0);
    TCharFormat(const TRichEdit&, bool selection = true,
                ulong mask = CFM_ALL);

    void    ToggleEffectsBit(ulong flag);
    void    ToggleMaskBit(ulong flag);

    void    EnableBold(bool = true);
    void    EnableItalic(bool = true);
    void    EnableUnderline(bool = true);
    void    EnableStrikeOut(bool = true);
    void    EnableProtected(bool = true);

    void    SetHeight(long);
    void    SetOffset(long);
    void    SetTextColor(const TColor& = TColor::None);
    void    SetCharSet(uint8);
    void    SetPitchAndFamily(uint8);
    void    SetFaceName(const char far*);

    TColor  GetTextColor() const;

    void    SetFontInfo(LOGFONT& lf) const;
    void    GetFontInfo(const LOGFONT& lf);
};

//
// class TCharRange
// ~~~~~ ~~~~~~~~~~
// TCharRange encapsulates the CHARRANGE structure which specifies a range
// of characters in a rich edit control.
//
class _OWLCLASS TCharRange : public CHARRANGE {
  public:
    TCharRange(long min = 0, long max = -1);
};

//
// class TParaFormat
// ~~~~~ ~~~~~~~~~~~
// TParaFormat encapsulates the PARAFORMAT structure which contains
// information about paragraph formatting attributes of a rich edit control.
//
class _OWLCLASS TParaFormat : public PARAFORMAT {
  public:
    TParaFormat(ulong mask = 0);
    TParaFormat(const TRichEdit&, ulong mask = CFM_ALL);

    void  ToggleMaskBit(ulong flag);

    void  SetNumbering(uint16);
    void  SetStartIndent(long, bool relative = false);
    void  SetRightIndent(long);
    void  SetOffset(long);
    void  SetAlignment(uint16);
    void  SetTabCount(short, long*);
};

//
// class TFormatRange
// ~~~~~ ~~~~~~~~~~~~
// TFormatRange encapsulates the FORMATRANGE structure which contains
// information that a rich edit control uses to format its output for a
// particular device.
//
class _OWLCLASS TFormatRange : public FORMATRANGE {
  public:
    TFormatRange();
    TFormatRange(HDC renderDC, HDC targetDC,
                 const TRect& renderArea, const TRect& entireArea,
                 const TCharRange& txtRange);

    TFormatRange(HDC renderDC, HDC targetDC,
                 const TRect& renderArea, const TRect& entireArea,
                 long firstChar, long lastChar);

    void  SetRenderDC(HDC);
    void  SetTargetDC(HDC);
    void  SetRenderRect(const TRect&);
    void  SetPageRect(const TRect&);
    void  SetRange(const TCharRange&);
    void  SetRange(long, long);
};

//
// class TEditStream
// ~~~~~ ~~~~~~~~~~~
// TEditStream encapsulates the EDITSTREAM structure which contains
// information about a data stream used with a rich edit control.
//
class _OWLCLASS TEditStream : public EDITSTREAM {
  public:
    TEditStream();
    TEditStream(ulong cookie, EDITSTREAMCALLBACK);
};

//
// class TTextRange
// ~~~~~ ~~~~~~~~~~
// TTextRange encapsulates the TEXTRANGE structure which contains information
// about a range of text in a rich edit control.
//
class _OWLCLASS TTextRange : public TEXTRANGE {
  public:
    TTextRange();
    TTextRange(const TCharRange&, char far* buffer);
    TTextRange(long beg, long end, char far* buffer);
};

//
// class TFindText
// ~~~~~ ~~~~~~~~~
// TFindText encapsulates the FINDTEXT structure which contains information
// about text to search for in a rich edit control.
//
class _OWLCLASS TFindText : public FINDTEXT {
  public:
    TFindText(const TCharRange& range, const char far* text);
    TFindText(long beg, long end, const char far* text);
};

//----------------------------------------------------------------------------

//
// class TRichEditModule
// ~~~~~ ~~~~~~~~~~~~~~~
// Wrapper object which loads the DLL providing the implementation of 
// the RichEdit control
//
class _OWLCLASS TRichEditModule : public TModule {
  public:
    TRichEditModule();
};

//
// class TRichEditDll
// ~~~~~~~~~~~~~~~~~~
// TRichEditDll is a simple object which takes advantages of OWL's 
// TDllLoader to ensure that only one copy of an object [theoretically
// representing a DLL] is created.
// TRichEditDll provides the 'IsAvailable' method which returns true if the
// DLL is available and loaded. TRichEditDll is used internally by OWL's
// TRichEdit class to ensure that the DLL is available and loaded. You may
// consider using TRichEditDll if your application creates rich edit controls
// without instantiating a TRichEdit object. (For example, if the control
// is part of a dialog resource). The following snippet illustrates:
//
//    if (!TRichEditDll::IsAvailable()) {
//      Error("Unable to load Rich Edit DLL");
//    }
//
typedef TDllLoader<TRichEditModule> TRichEditDll;

#if  defined(BI_COMP_BORLANDC)
# if defined(_OWLDLL) || defined(BI_APP_DLL)
  //
  // Export template of TDllLoader<TRichEditModule> when building ObjectWindows
  // DLL and provide import declaration of DLL instance for users of the class.
  //
  template class _OWLCLASS TDllLoader<TRichEditModule>;
# endif   
#endif   


//
// class TRichEdit
// ~~~~~ ~~~~~~~~~
// TRichEdit encapsulates a rich edit control, a window in which a user can
// enter, edit and format text.
//
class _OWLCLASS TRichEdit : public TEditFile {
  public:
    TRichEdit(TWindow*        parent,
              int             id,
              const char far* text,
              int x, int y, int w, int h,
              const char far* fileName = 0,
              TModule*        module = 0);
    TRichEdit(TWindow*   parent,
              int        resourceId,
              TModule*   module = 0);

    // Generic Formatting Methods
    //
    ulong   GetCharFormat(TCharFormat far&, bool selection = false) const;
    ulong   GetParaFormat(TParaFormat far&) const;
    bool    SetCharFormat(const TCharFormat far&, uint flags= SCF_SELECTION);
    bool    SetParaFormat(const TParaFormat far&);
    TColor  SetBkgndColor(const TColor& = TColor::None);

    // Enumeration of flags returned when querrying a RichEdit about
    // a particular character attribute for a chunk of selected text.
    //
    enum TFmtStatus {
      No,               // The whole selection has the attribute
      Yes,              // The attribute is absent from the selection
      Partly            // Part of the selection has the attribute
    };

    // More specialized character formatting or querrying methods
    //
    uint    HasCharAttribute(ulong mask, ulong effects);
    bool    ToggleCharAttribute(ulong mask, ulong effects);
    bool    ChangeCharPointSize(int pointSizeDelta);


    // Selection and Hit Testing
    //
    bool    HasSelection() const;
    void    GetSelection(uint& startPos, uint& endPos) const;
    void    GetSelRange(TCharRange far&) const;
    bool    SetSelection(uint startPos, uint endPos);
    int     SetSelRange(const TCharRange far&);
    void    HideSelection(bool hide, bool changeStyle);
    ulong   GetSelectionType() const;

    // Text Operations
    //
    int     GetTextRange(TTextRange far&) const;
    int     GetTextRange(const TCharRange far&, char far* buffer) const;
    virtual void GetSubText(char far* str, uint startPos, uint endPos) const;
    int     GetSelectedText(char far* buffer) const;
    void    LimitText(long max);        
    int     FindText(uint flags, const TFindText far&);
    int     FindText(uint flags, const TCharRange far&, const char far* text);
    int     Search(uint startPos, const char far* text,
                   bool caseSensitive=false, bool wholeWord=false,
                   bool up=false);

    // Word and Line Breaks
    //
    int     FindWordBreak(uint code, long start);
    int     GetLineFromPos(uint charPos) const;       // EM_EXLINEFROMCHAR

    // Lines and Scrolling
    //

    // Editing Operations
    //
    bool    CanPaste(uint format) const;
    void    Paste();  // {HandleMessage(WM_PASTE);}
    void    PasteSpecial(uint format);

    // Streams
    //
    ulong   StreamIn(uint format, TEditStream far&);
    ulong   StreamOut(uint format, TEditStream far&);

    // Printing
    //
    bool    DisplayBand(TRect far&);
    int     FormatRange(const TFormatRange far& range, bool render = true);
    int     FormatRange();
    bool    SetTargetDevice(HDC, int lineWidth);

    // Bottomless Rich Edit Controls
    //
    void    RequestResize();

    // OLE Interfaces
    //
    bool    GetOleInterface(IRichEditOle far* &) const;
    bool    SetOleInterface(IRichEditOleCallback far*);

    // Querry/Set control's data format
    //
    uint    GetFormat() const;
    void    SetFormat(uint fmt);
    bool    IsRTF() const;

    // Misc
    //
    ulong   GetEventMask() const;
    ulong   SetEventMask(ulong msk);

    // Override to use RichEdit streaming capabilities
    //
    uint    Transfer(void* buffer, TTransferDirection direction);

    // Override TEditFile's I/O
    //
    bool    Read(const char far* fileName=0);
    bool    Write(const char far* fileName=0);

    bool    ReadFromStream(istream&, uint format = SF_RTF);
    bool    WriteToStream(ostream&, uint format = SF_RTF);

  protected:

    // Data format of control
    //
    uint    Format;

    // Command response functions
    //
    void    CmEditCut();       // CM_EDITCUT
    void    CmEditCopy();      // CM_EDITCOPY
    void    CmEditPaste();     // CM_EDITPASTE
    void    CmEditDelete();    // CM_EDITDELETE
    void    CmEditClear();     // CM_EDITCLEAR
    void    CmEditUndo();      // CM_EDITUNDO

    // Command enabler functions
    //
    void    CeHasSelect(TCommandEnabler& commandHandler);
    void    CeEditPaste(TCommandEnabler& commandHandler);
    void    CeEditClear(TCommandEnabler& commandHandler);
    void    CeEditUndo(TCommandEnabler& commandHandler);

    // Child id notification handled at the child
    //
    void    ENErrSpace();  // EN_ERRSPACE

    // Override TWindow virtual member functions
    //
    char far* GetClassName();
    void      SetupWindow();

    // Event handlers to override TEdit's handlers
    //
    void         EvChar(uint key, uint repeatCount, uint flags);
    void         EvKeyDown(uint key, uint repeatCount, uint flags);
    uint         EvGetDlgCode(MSG far*);
    void         EvSetFocus(HWND hWndLostFocus);
    void         EvKillFocus(HWND hWndGetFocus);
    void         EvChildInvalid(HWND);

  private:
    // Hidden to prevent accidental copying or assignment
    //
    TRichEdit(const TRichEdit&);
    TRichEdit& operator =(const TRichEdit&);

    // The following are TEdit methods which encapsulates messages/API
    // which are *NOT* supported by the RICHEDIT class.
    //
    void    FormatLines(bool addEOL);
    char far* LockBuffer(uint newSize = 0);
    void    UnlockBuffer(const char far*, bool = false);
    void    SetTabStops(int numTabs, const int far*);
    HLOCAL  GetHandle() const;
    void    SetHandle(HLOCAL localMem);
    uint    GetPasswordChar() const;
    void    SetPasswordChar(uint ch);
    void    SetRectNP(const TRect& frmtRect);

    // Validators are not applicable to RichEdit where the text
    // is not plain ASCII...
    //
    bool    IsValid(bool reportErr = false);
    void    SetValidator(TValidator* validator);
    void    ValidatorError();

  DECLARE_RESPONSE_TABLE(TRichEdit);
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

//----------------------------------------------------------------------------
// Inline implementation
//

//
// Handler of the CM_EDITCUT command - Invokes the 'Cut' method.
//
inline void TRichEdit::CmEditCut()
{
  Cut();
}

//
// Handler of the CM_EDITCOPY command - invokes the'Copy' method
//
inline void TRichEdit::CmEditCopy()
{
  Copy();
}

//
// Handler of the CM_EDITPASTE command - invokes the 'Paste' method
//
inline void TRichEdit::CmEditPaste()
{
  Paste();
}

//
// Handler of the CM_EDITDELETE command - invokes the 'DeleteSelection' 
// method
//
inline void TRichEdit::CmEditDelete()
{
  DeleteSelection();
}

//
// Handler of the CM_EDITCLEAR command - invokes the 'Clear' method
//
inline void TRichEdit::CmEditClear()
{
  Clear();
}

//
// Handler of the CM_EDITUNDO command - invokes the 'Undo' method
//
inline void TRichEdit::CmEditUndo()
{
  Undo();
}

//
// Constructor of a 'TCharFormat' structure initialized with the specified
// mask. NOTE: This constructor is typically used for constructing an
// object which will be filled with the appropriate character format
// information by a rich edit control. The 'mask' specifies which field
// should be filled.
//
inline TCharFormat::TCharFormat(ulong mask)
{
  cbSize = sizeof(CHARFORMAT);
  dwMask = mask;
}

//
// Toggle the effect bits specified in the 'flag' parameter
//
inline void TCharFormat::ToggleEffectsBit(ulong flag)
{
  dwEffects ^= flag;
}

//
// Toggle the mask bits specified in the 'flag' parameter
//
inline void TCharFormat::ToggleMaskBit(ulong flag)
{
  dwMask ^= flag;
}

//
// Construct a TCharRange structure initialized with the specified 'min' and
// 'max' parameters.
//
inline TCharRange::TCharRange(long min, long max)
{
  cpMin = min;
  cpMax = max;
}

//
// Construct a default 'TEditStream' object. The members of the base
// 'EDITSTREAM' object are initialized to zero.
//
inline TEditStream::TEditStream()
{
  dwCookie = 0;
  dwError  = 0;
  pfnCallback = 0;
}

//
// Construct a 'TEditStream' object initializing the members with the
// specified parameter.
//
inline TEditStream::TEditStream(ulong cookie, EDITSTREAMCALLBACK callback)
{
  dwCookie = cookie;
  dwError  = 0;
  pfnCallback = callback;
}

//
// Construct a 'TFindText' describing the text to search for and the range
// of the search using the 'text' and 'range' parameters respectively.
//
inline TFindText::TFindText(const TCharRange& range, const char far* text)
{
  chrg = range;
  lpstrText = CONST_CAST(char far*, text);
}

//
// Construct a 'TFindText' describing the text to search for via the 'text'
// parameter, and the range to search for via the 'beg' and 'end' parameters
// respectively.
//
inline TFindText::TFindText(long beg, long end, const char far* text)
{
  chrg.cpMin = beg;
  chrg.cpMax = end;
  lpstrText = CONST_CAST(char far*, text);
}

//
// Construct a default 'TFormatRange' object with all members initialized
// to zero.
//
inline TFormatRange::TFormatRange()
{
  memset((FORMATRANGE*)this, 0, sizeof(FORMATRANGE));
}

//
// Construct a default 'TTextRange' structure with the data members 
// describing the range and text initialized to zero.
//
inline TTextRange::TTextRange()
{
  chrg.cpMin = 0;
  chrg.cpMax = 0;
  lpstrText  = 0;
}

//
// Construct a 'TTextRange' structure by initializing the range and text
// members with the 'rng' and 'buffer' parameters respectively.
//
inline TTextRange::TTextRange(const TCharRange& rng, char far* buffer)
{
  chrg = rng;
  lpstrText = buffer;
}

//
// Construct a 'TTextRange' structure by initializing the text with the 
// 'buffer' parameter, and the range using 'beg' and 'end'.
//
inline TTextRange::TTextRange(long beg, long end, char far* buffer)
{
  chrg.cpMin = beg;
  chrg.cpMax = end;
  lpstrText = buffer;
}

//
//
//
inline uint    
TRichEdit::GetFormat() const {
  return Format;
}

//
//
//
inline void    
TRichEdit::SetFormat(uint fmt) {
  Format = fmt;
}

//
//
//
inline bool    
TRichEdit::IsRTF() const {
  return Format == SF_RTF;
}

#endif  // OWL_RICHEDIT_H
