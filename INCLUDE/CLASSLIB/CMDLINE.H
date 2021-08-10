//----------------------------------------------------------------------------
// Borland Class Library
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   5.4  $
//
// Command line parsing class
//----------------------------------------------------------------------------
#if !defined(CLASSLIB_CMDLINE_H)
#define CLASSLIB_CMDLINE_H

#if !defined(CLASSLIB_DEFS_H)
# include <classlib/defs.h>
#endif

#if defined(BI_NAMESPACE)
namespace ClassLib {
#endif

//
// class TCmdLine
// ~~~~~ ~~~~~~~~
// Command line argument processing class, processes in the form:
//
//  <Name> | {-/}<Option>[{:=}<Value>] ...
//
class _BIDSCLASS TCmdLine {
  public:
    enum TKind {
      Start,   // No tokens have been parsed yet
      Name,    // Name type token, has no leading / or -
      Option,  // Option type token. Leading / or - skipped by Token
      Value,   // Value for name or option. Leading : or = skipped by Token
      Done     // No more tokens
    };
    TCmdLine(const _TCHAR far* cmdLine);
   ~TCmdLine();

    TKind NextToken(bool removeCurrent=false);
    const _TCHAR* GetLine() const {return Buffer;}
    void Reset();

    TKind Kind;       // Kind of current token
    _TCHAR* Token;      // Ptr to current token. (Not 0-terminated, use TokenLen)
    int   TokenLen;   // Length of current token

  private:
    _TCHAR* Buffer;     // Command line buffer
    _TCHAR* TokenStart; // Actual start of current token
};

#if defined(BI_NAMESPACE)
}   // namespace ClassLib
#endif

#endif  // CLASSLIB_CMDLINE_H
