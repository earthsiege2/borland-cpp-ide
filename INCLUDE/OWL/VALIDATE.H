//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1993, 1993 by Borland International
//   source\owl\validate.h
//----------------------------------------------------------------------------
#if !defined(__OWL_VALIDATE_H)
#define __OWL_VALIDATE_H

#if !defined(__OWL_WINDOW_H)
  #include <owl\window.h>
#endif
#if !defined(__CLASSLIB_ARRAYS_H)
  #include <classlib\arrays.h>
#endif
#if !defined(__OWL_BITSET_H)
  #include <owl\bitset.h>
#endif
#include <owl\validate.rh>

//
// Validator option flags
//
enum TValidatorOptions {
  voFill     =  0x0001,
  voTransfer =  0x0002,
  voOnAppend =  0x0004,
  voReserved =  0x00F8
};

//
// class TValidator
// ----- ----------
//
class _OWLCLASS TValidator : public TStreamableBase {
  public:
    class _OWLCLASS_RTL TXValidator : TXOwl {
      public:
        TXValidator(UINT resId = IDS_VALIDATORSYNTAX);
    };

    TValidator();
    virtual ~TValidator();

    virtual void Error();
    virtual BOOL IsValidInput(char far* str, BOOL suppressFill);
    virtual BOOL IsValid(const char far* str);
    virtual UINT Transfer(char far* str, void* buffer, TTransferDirection direction);

    // Checks input against validator for completeness. Never modifies input.
    // Calls error if not valid.
    //
    BOOL         Valid(const char far* str)
                  {if (!IsValid(str)) {Error(); return FALSE;} return TRUE;}

    BOOL         HasOption(int option) {return Options & option;}
    void         SetOption(int option) {Options |= WORD(option);}
    void         UnsetOption(int option) {Options &= WORD(~option);}

  protected:
    WORD   Options;
    
  DECLARE_STREAMABLE(_OWLCLASS, TValidator, 1);
};

//
// TPXPictureValidator result type
//
enum TPicResult {
  prComplete,
  prIncomplete,
  prEmpty,
  prError,
  prSyntax,
  prAmbiguous,
  prIncompNoFill
};

//
// class TPXPictureValidator
// ----- -------------------
//
class _OWLCLASS TPXPictureValidator : public TValidator {
  public:
    TPXPictureValidator(const char far* pic, BOOL autoFill=FALSE);

    //
    // override TValidator's virtuals
    //
    void         Error();
    BOOL         IsValidInput(char far* str, BOOL suppressFill);
    BOOL         IsValid(const char far* str);

    virtual TPicResult Picture(char far* input, BOOL autoFill=FALSE);

  protected:
    string       Pic;

  private:
    BOOL         IsComplete(TPicResult rslt);
    BOOL         IsIncomplete(TPicResult rslt);
    void         ToGroupEnd(UINT termCh, UINT& i);
    BOOL         SkipToComma(UINT termCh, UINT& i);
    UINT         CalcTerm(UINT termCh, UINT i);
    TPicResult   Iteration(char far* input, UINT termCh, UINT& i, UINT& j);
    TPicResult   Group(char far* input, UINT termCh, UINT& i, UINT& j);
    TPicResult   CheckComplete(UINT termCh, UINT& i, TPicResult rslt);

    TPicResult   Scan(char far* input, UINT termCh, UINT& i, UINT& j);
    TPicResult   Process(char far* input, UINT termCh, UINT& i, UINT& j);
    BOOL         SyntaxCheck();

  DECLARE_STREAMABLE(_OWLCLASS, TPXPictureValidator, 1);
};

//
// class TFilterValidator
// ----- ----------------
//
class _OWLCLASS TFilterValidator : public TValidator {
  public:
    TFilterValidator(const TCharSet& validChars);

    //
    // override TValidator's virtuals
    //
    void         Error();
    BOOL         IsValid(const char far* str);
    BOOL         IsValidInput(char far* str, BOOL suppressFill);

  protected:
    TCharSet     ValidChars;

  DECLARE_STREAMABLE(_OWLCLASS, TFilterValidator, 1);
};

//
// class TRangeValidator
// ----- ---------------
//
class _OWLCLASS TRangeValidator : public TFilterValidator {
  public:
    TRangeValidator(long min, long max);

    //
    // override TValidator's virtuals
    //
    void         Error();
    BOOL         IsValid(const char far* str);
    UINT         Transfer(char far* str, void* buffer, TTransferDirection direction);

  protected:
    long   Min;
    long   Max;

  DECLARE_STREAMABLE(_OWLCLASS, TRangeValidator, 1);
};

//
// class TLookupValidator
// ----- ----------------
//
class _OWLCLASS TLookupValidator : public TValidator {
  public:
    TLookupValidator();

    //
    // override TValidator's virtuals
    //
    BOOL         IsValid(const char far* str);

    // virtual lookup of a string
    virtual BOOL Lookup(const char far* str);

  DECLARE_STREAMABLE(_OWLCLASS, TLookupValidator, 1);
};

//
// type TSortedStringArray
// ---- ------------------
//
typedef TSArrayAsVector<string> TSortedStringArray;

//
// class TStringLookupValidator
// ----- ----------------------
//
class _OWLCLASS TStringLookupValidator : public TLookupValidator {
  public:
    TStringLookupValidator(TSortedStringArray* strings);
   ~TStringLookupValidator();

    //
    // override TValidator's virtuals
    //
    void         Error();

    //
    // override TLookupValidator's virtuals
    //
    BOOL         Lookup(const char far* str);

    void         NewStringList(TSortedStringArray* strings);

  protected:
    TSortedStringArray* Strings;

  DECLARE_STREAMABLE(_OWLCLASS, TStringLookupValidator, 1);
};


#endif  // __OWL_VALIDATE_H
