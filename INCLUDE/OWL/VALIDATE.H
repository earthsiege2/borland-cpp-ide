//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1993, 1994 by Borland International, All Rights Reserved
//
//----------------------------------------------------------------------------
#if !defined(OWL_VALIDATE_H)
#define OWL_VALIDATE_H

#if !defined(OWL_WINDOW_H)
# include <owl/window.h>
#endif
#if !defined(CLASSLIB_ARRAYS_H)
# include <classlib/arrays.h>
#endif
#if !defined(OWL_BITSET_H)
# include <owl/bitset.h>
#endif
#include <owl/validate.rh>

//
// Validator option flags
//
enum TValidatorOptions {
  voFill     =  0x0001,   // option to fill in chars on IsValidInput checks
  voTransfer =  0x0002,   // option to perform conversion & transfer
  voOnAppend =  0x0004,   // option to only validate input on appending
  voReserved =  0x00F8    // reserved for future use
};

//
// class TValidator
// ----- ----------
//
class _OWLCLASS TValidator : public TStreamableBase {
  public:
    class _OWLCLASS_RTL TXValidator : public TXOwl {
      public:
        TXValidator(uint resId = IDS_VALIDATORSYNTAX);
    };

    TValidator();
    virtual ~TValidator();

    virtual void Error();
    virtual bool IsValidInput(char far* str, bool suppressFill);
    virtual bool IsValid(const char far* str);
    virtual uint Transfer(char far* str, void* buffer, TTransferDirection direction);

    // Checks input against validator for completeness. Never modifies input.
    // Calls error if not valid.
    //
    bool         Valid(const char far* str)
                  {if (!IsValid(str)) {Error(); return false;} return true;}

    bool         HasOption(int option) {return Options & option;}
    void         SetOption(int option) {Options |= uint16(option);}
    void         UnsetOption(int option) {Options &= uint16(~option);}

  protected:
    uint16   Options;
    
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
    TPXPictureValidator(const char far* pic, bool autoFill=false);

    //
    // override TValidator's virtuals
    //
    void         Error();
    bool         IsValidInput(char far* str, bool suppressFill);
    bool         IsValid(const char far* str);

    virtual TPicResult Picture(char far* input, bool autoFill=false);

  protected:
    string       Pic;

  private:
    bool         IsComplete(TPicResult rslt);
    bool         IsIncomplete(TPicResult rslt);
    void         ToGroupEnd(uint termCh, uint& i);
    bool         SkipToComma(uint termCh, uint& i);
    uint         CalcTerm(uint termCh, uint i);
    TPicResult   Iteration(char far* input, uint termCh, uint& i, uint& j);
    TPicResult   Group(char far* input, uint termCh, uint& i, uint& j);
    TPicResult   CheckComplete(uint termCh, uint& i, TPicResult rslt);

    TPicResult   Scan(char far* input, uint termCh, uint& i, uint& j);
    TPicResult   Process(char far* input, uint termCh, uint& i, uint& j);
    bool         SyntaxCheck();

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
    bool         IsValid(const char far* str);
    bool         IsValidInput(char far* str, bool suppressFill);

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
    bool         IsValid(const char far* str);
    uint         Transfer(char far* str, void* buffer, TTransferDirection direction);

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
    bool         IsValid(const char far* str);

    // virtual lookup of a string
    virtual bool Lookup(const char far* str);

  DECLARE_STREAMABLE(_OWLCLASS, TLookupValidator, 1);
};

//
// class TSortedStringArray
// ----- ------------------
//
class _OWLCLASS TSortedStringArray
{
  public:
    typedef void (*IterFunc)(string&, void*);
    typedef int  (*CondFunc)(const string&, void*);

    TSortedStringArray(int upper, int lower, int delta);
    int LowerBound() const;
    int UpperBound() const;
    unsigned ArraySize() const;
    int IsFull() const;
    int IsEmpty() const;
    unsigned GetItemsInContainer() const;
    int Add(const string& t);
    int Detach(const string& t);
    int Detach(int loc);
    int Destroy(const string& t);
    int Destroy(int loc);
    int HasMember(const string& t) const;
    int Find(const string& t) const;
    string& operator [](int loc);
    string& operator [](int loc) const;
    void ForEach(IterFunc iter, void* args);
    string* FirstThat(CondFunc cond, void* args) const;
    string* LastThat(CondFunc cond, void* args) const;
    void Flush();

  private:
    TSArrayAsVector<string> Data;

  friend class TSortedStringArrayIterator;
};

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
    bool         Lookup(const char far* str);

    void         NewStringList(TSortedStringArray* strings);

  protected:
    TSortedStringArray* Strings;

  DECLARE_STREAMABLE(_OWLCLASS, TStringLookupValidator, 1);
};

#endif  // OWL_VALIDATE_H
