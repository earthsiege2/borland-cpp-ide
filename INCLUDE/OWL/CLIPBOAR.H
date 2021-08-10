//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   OWL clipboard Encapsulation
//----------------------------------------------------------------------------
#if !defined(OWL_CLIPBOAR_H)
#define OWL_CLIPBOAR_H

#if !defined(OWL_OWLDEFS_H)
# include <owl/owldefs.h>
#endif
#if !defined(INC_OLE2) && !defined(__OLE_H) && !defined(_INC_OLE)
//# include <ole.h>
#endif

class _OWLCLASS TClipboard {
 public:
    // Constructors / destructor
    TClipboard(HWND hWnd) {OpenClipboard(hWnd);}  // aquire & open the clipboard
    ~TClipboard() {if (IsOpen) ::CloseClipboard();}

    bool        OpenClipboard(HWND hWnd)
                    {return IsOpen = (bool)::OpenClipboard(hWnd);}
    void        CloseClipboard()
                    {if (IsOpen) {::CloseClipboard(); IsOpen = false;}}

    operator    bool() const {return IsOpen;}
    HANDLE      GetClipboardData(uint format) const;
    HWND        GetOpenClipboardWindow() const;
    HWND        GetClipboardOwner() const;
    HWND        GetClipboardViewer() const;
    int         GetClipboardFormatName(uint format, char far* formatName, int maxCount) const;
    int         GetPriorityClipboardFormat(uint far* priorityList, int count) const;
    int         CountClipboardFormats() const;
    bool        IsClipboardFormatAvailable(uint format) const;
    bool        EmptyClipboard();
    uint        RegisterClipboardFormat(const char far* formatName) const;
    HANDLE      SetClipboardData(uint format, HANDLE handle);
    HWND        SetClipboardViewer(HWND hWnd) const;

    static const char* DefaultProtocol;

  #if defined(__OLE_H) || defined(_INC_OLE)
    bool        QueryCreate(const char far* protocol = DefaultProtocol,
                            OLEOPT_RENDER   renderopt= olerender_draw,
                            OLECLIPFORMAT   format   = 0);
    bool        QueryLink(const char far* protocol = DefaultProtocol,
                          OLEOPT_RENDER   renderopt= olerender_draw,
                          OLECLIPFORMAT   format   = 0);
  #endif

    //
    // obsolete way to retrieve the global clipboard object. The recomended
    // way is to construct a TClipboard object using the TClipboard(HWND) ctor
    //
    static TClipboard& GetClipboard() {return TheClipboard;}

  protected:
    static TClipboard TheClipboard;
    bool              IsOpen;

    TClipboard() {IsOpen = false;}  // used by the global object
};

class _OWLCLASS TClipboardFormatIterator {
  public:
    TClipboardFormatIterator();

    uint          current();
                  operator int();
    uint          operator ++();
    uint          operator ++(int);
    void          restart();

  private:
    uint          _Current;
};

//----------------------------------------------------------------------------
// Inline
//----------------------------------------------------------------------------

inline HANDLE TClipboard::GetClipboardData(uint Format) const {
  return ::GetClipboardData(Format);
}

inline HWND TClipboard::GetOpenClipboardWindow() const {
  return ::GetOpenClipboardWindow();
}

inline HWND TClipboard::GetClipboardOwner() const {
  return ::GetClipboardOwner();
}

inline HWND TClipboard::GetClipboardViewer() const {
  return ::GetClipboardViewer();
}

inline int TClipboard::GetClipboardFormatName(uint Format, char far* FormatName, int MaxCount) const {
  return ::GetClipboardFormatName(Format, FormatName, MaxCount);
}

inline int TClipboard::GetPriorityClipboardFormat(uint far* priorityList, int count) const {
  return ::GetPriorityClipboardFormat(priorityList, count);
}

inline int TClipboard::CountClipboardFormats() const {
  return ::CountClipboardFormats();
}

inline bool TClipboard::IsClipboardFormatAvailable(uint format) const {
  return ::IsClipboardFormatAvailable(format);
}

inline bool TClipboard::EmptyClipboard() {
  return ::EmptyClipboard();
}

inline uint TClipboard::RegisterClipboardFormat(const char far* formatName) const {
  return ::RegisterClipboardFormat(formatName);
}

inline HANDLE TClipboard::SetClipboardData(uint Format, HANDLE Handle) {
  return ::SetClipboardData(Format,Handle);
}

inline HWND TClipboard::SetClipboardViewer(HWND Wnd) const {
  return ::SetClipboardViewer(Wnd);
}

#if defined(__OLE_H) || defined(_INC_OLE)
inline bool TClipboard::QueryCreate(
                const char far* protocol,
                OLEOPT_RENDER   renderopt,
                OLECLIPFORMAT   format
              )
{
  return ::OleQueryCreateFromClip(protocol, renderopt, format) == OLE_OK;
}

inline bool TClipboard::QueryLink(
                const char far* protocol,
                OLEOPT_RENDER   renderopt,
                OLECLIPFORMAT   format
              )
{
  return ::OleQueryLinkFromClip(protocol, renderopt, format) == OLE_OK;
}
#endif

#endif  // OWL_CLIPBOAR_H
