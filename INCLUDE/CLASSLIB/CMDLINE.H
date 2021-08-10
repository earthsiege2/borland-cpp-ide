//----------------------------------------------------------------------------
// Borland Class Library
// Copyright (c) 1992, 1996 by Borland International, All Rights Reserved
//
//$Revision:   5.1  $
//
// Command line parsing class
//----------------------------------------------------------------------------
#if !defined(CLASSLIB_CMDLINE_H)
#define CLASSLIB_CMDLINE_H

#if !defined(CLASSLIB_DEFS_H)
# include <classlib/defs.h>
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
    TCmdLine(const char far* cmdLine);
   ~TCmdLine();

    TKind NextToken(bool removeCurrent=false);
    const char* GetLine() const {return Buffer;}
    void Reset();

    TKind Kind;       // Kind of current token
    char* Token;      // Ptr to current token. (Not 0-terminated, use TokenLen)
    int   TokenLen;   // Length of current token

  private:
    char* Buffer;     // Command line buffer
    char* TokenStart; // Actual start of current token
};

#endif  // CLASSLIB_CMDLINE_H
