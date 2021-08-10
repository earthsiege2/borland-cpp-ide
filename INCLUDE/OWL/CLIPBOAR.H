//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   include\owl\clipboar.h
//   OWL clipboard Encapsulation
//----------------------------------------------------------------------------
#if !defined(__OWL_CLIPBOAR_H)
#define __OWL_CLIPBOAR_H

#if !defined(__OWL_OWLDEFS_H)
  #include <owl\owldefs.h>
#endif
#if defined(_INC_OLE)
  #include <ole.h>
#endif

class _OWLCLASS TClipboard {
 public:
    ~TClipboard() {if (IsOpen) ::CloseClipboard();}

    static TClipboard& GetClipboard() {return TheClipboard;}

    BOOL        OpenClipboard(HWND hWnd)
                    {return IsOpen = ::OpenClipboard(hWnd);}
    void        CloseClipboard() {if (IsOpen) {::CloseClipboard(); IsOpen = FALSE;}}

    operator    BOOL() const {return IsOpen;}
    HANDLE      GetClipboardData(UINT format) const;
    HWND        GetOpenClipboardWindow() const;
    HWND        GetClipboardOwner() const;
    HWND        GetClipboardViewer() const;
    int         GetClipboardFormatName(UINT format, char far* formatName, int maxCount) const;
    int         GetPriorityClipboardFormat(UINT far* priorityList, int count) const;
    int         CountClipboardFormats() const;
    BOOL        IsClipboardFormatAvailable(UINT format) const;
    BOOL        EmptyClipboard();
    UINT        RegisterClipboardFormat(const char far* formatName) const;
    HANDLE      SetClipboardData(UINT format, HANDLE handle);
    HWND        SetClipboardViewer(HWND hWnd) const;

  #if defined(__OLE_H) || defined(_INC_OLE)
    static const char* DefaultProtocol;

    BOOL        QueryCreate(const char far* protocol = DefaultProtocol,
                            OLEOPT_RENDER   renderopt= olerender_draw,
                            OLECLIPFORMAT   format   = 0);
    BOOL        QueryLink(const char far* protocol = DefaultProtocol,
                          OLEOPT_RENDER   renderopt= olerender_draw,
                          OLECLIPFORMAT   format   = 0);
  #endif

  protected:
    static TClipboard TheClipboard;
    BOOL              IsOpen;

    // Constructors / destructor
    TClipboard() {IsOpen = FALSE;}
};

class _OWLCLASS TClipboardFormatIterator {
  public:
    TClipboardFormatIterator();

    UINT          current();
                  operator int();
    UINT          operator ++();
    UINT          operator ++(int);
    void          restart();

  private:
    UINT          _Current;
};

//----------------------------------------------------------------------------
// Inline
//----------------------------------------------------------------------------

inline HANDLE TClipboard::GetClipboardData(UINT Format) const {
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

inline int TClipboard::GetClipboardFormatName(UINT Format, char far* FormatName, int MaxCount) const {
  return ::GetClipboardFormatName(Format, FormatName, MaxCount);
}

inline int TClipboard::GetPriorityClipboardFormat(UINT far* priorityList, int count) const {
  return ::GetPriorityClipboardFormat(priorityList, count);
}

inline int TClipboard::CountClipboardFormats() const {
  return ::CountClipboardFormats();
}

inline BOOL TClipboard::IsClipboardFormatAvailable(UINT format) const {
  return ::IsClipboardFormatAvailable(format);
}

inline BOOL TClipboard::EmptyClipboard() {
  return ::EmptyClipboard();
}

inline UINT TClipboard::RegisterClipboardFormat(const char far* formatName) const {
  return ::RegisterClipboardFormat(formatName);
}

inline HANDLE TClipboard::SetClipboardData(UINT Format, HANDLE Handle) {
  return ::SetClipboardData(Format,Handle);
}

inline HWND TClipboard::SetClipboardViewer(HWND Wnd) const {
  return ::SetClipboardViewer(Wnd);
}

#if defined(__OLE_H) || defined(_INC_OLE)
inline BOOL TClipboard::QueryCreate(
                LPCSTR        protocol,
                OLEOPT_RENDER renderopt,
                OLECLIPFORMAT format
              )
{
  return ::OleQueryCreateFromClip(protocol, renderopt, format) == OLE_OK;
}

inline BOOL TClipboard::QueryLink(
                LPCSTR        protocol,
                OLEOPT_RENDER renderopt,
                OLECLIPFORMAT format
              )
{
  return ::OleQueryLinkFromClip(protocol, renderopt, format) == OLE_OK;
}
#endif

#endif  // __OWL_CLIPBOAR_H
