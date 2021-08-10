//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1993, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.4  $
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

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

class _OWLCLASS_RTL TXValidator;

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
// ~~~~~ ~~~~~~~~~~
class _OWLCLASS TValidator : public TStreamableBase {
  public:
    TValidator();
    virtual ~TValidator();

    virtual void Error(TWindow* owner);  
    virtual bool IsValidInput(char far* input, bool suppressFill);
    virtual bool IsValid(const char far* input);
    virtual uint Transfer(char far* text, void* buffer, TTransferDirection direction);
    virtual int  Adjust(string& text, uint& begPos, uint& endPos, int amount); 

    // Checks input against validator for completeness. Never modifies input.
    // Calls error if not valid.
    //
    bool         Valid(const char far* str, TWindow* owner = 0);
    bool         HasOption(int option);
    void         SetOption(int option);
    void         UnsetOption(int option);

#if defined(OWL2_COMPAT)
    typedef ::TXValidator TXValidator;  // Exception classes moved to global scope
#endif

  protected:
    uint16   Options;

  DECLARE_STREAMABLE(_OWLCLASS, TValidator, 1);
};

//
// class TXValidator
// ~~~~~ ~~~~~~~~~~~
class _OWLCLASS_RTL TXValidator : public TXOwl {
  public:
    TXValidator(uint resId = IDS_VALIDATORSYNTAX);

#if defined(BI_NO_COVAR_RET)
    TXBase* Clone();
#else
    TXValidator* Clone();
#endif
    void Throw();

    static void Raise();
};

//
// enum TPXPictureValidator
// ~~~~ ~~~~~~~~~~~~~~~~~~~
// Validation result type
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
// ~~~~~ ~~~~~~~~~~~~~~~~~~~
class _OWLCLASS TPXPictureValidator : public TValidator {
  public:
    TPXPictureValidator(const char far* pic, bool autoFill=false);

    // Override TValidator's virtuals
    //
    void         Error(TWindow* owner);
    bool         IsValidInput(char far* str, bool suppressFill);
    bool         IsValid(const char far* str);
    int          Adjust(string& text, uint& begPos, uint& endPos, int amount); 

    virtual TPicResult Picture(char far* input, bool autoFill=false);

  protected:
    const string& GetPic() const;
    void          SetPic(const string& pic);

  protected_data:
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
// ~~~~~ ~~~~~~~~~~~~~~~~
class _OWLCLASS TFilterValidator : public TValidator {
  public:
    TFilterValidator(const TCharSet& validChars);

    // Override TValidator's virtuals
    //
    void         Error(TWindow* owner);
    bool         IsValid(const char far* str);
    bool         IsValidInput(char far* str, bool suppressFill);

  protected:
    const TCharSet&  GetValidChars();
    void             SetValidChars(const TCharSet& vc);

  protected_data:
    TCharSet     ValidChars;

  DECLARE_STREAMABLE(_OWLCLASS, TFilterValidator, 1);
};

//
// class TRangeValidator
// ~~~~~ ~~~~~~~~~~~~~~~
class _OWLCLASS TRangeValidator : public TFilterValidator {
  public:
    TRangeValidator(long min, long max);

    // Override TValidator's virtuals
    //
    void         Error(TWindow* owner);
    bool         IsValid(const char far* str);
    uint         Transfer(char far* str, void* buffer, TTransferDirection direction);
    int          Adjust(string& text, uint& begPos, uint& endPos, int amount); 

  protected:
    long   GetMin();
    void   SetMin(long min);
    long   GetMax();
    void   SetMax(long max);

  protected_data:
    long   Min;
    long   Max;

  DECLARE_STREAMABLE(_OWLCLASS, TRangeValidator, 1);
};

//
// class TLookupValidator
// ~~~~~ ~~~~~~~~~~~~~~~~
class _OWLCLASS TLookupValidator : public TValidator {
  public:
    TLookupValidator();

    // Override TValidator's virtuals
    //
    bool         IsValid(const char far* str);

    // Virtual lookup of a string
    //
    virtual bool Lookup(const char far* str);

  DECLARE_STREAMABLE(_OWLCLASS, TLookupValidator, 1);
};

//
// class TSortedStringArray
// ~~~~~ ~~~~~~~~~~~~~~~~~~
class _OWLCLASS TSortedStringArray {
  public:
    typedef void (*IterFunc)(string&, void*);
    typedef int  (*CondFunc)(const string&, void*);

    TSortedStringArray(int upper, int lower, int delta);
    int LowerBound() const;
    int UpperBound() const;
    uint ArraySize() const;
    int IsFull() const;
    int IsEmpty() const;
    uint GetItemsInContainer() const;
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
// ~~~~~ ~~~~~~~~~~~~~~~~~~~~~~
class _OWLCLASS TStringLookupValidator : public TLookupValidator {
  public:
    TStringLookupValidator(TSortedStringArray* strings);
   ~TStringLookupValidator();

    // Override TValidator's virtuals
    //
    void         Error(TWindow* owner);
    int          Adjust(string& text, uint& begPos, uint& endPos, int amount); 

    // Override TLookupValidator's virtuals
    //
    bool         Lookup(const char far* str);

    void         NewStringList(TSortedStringArray* strings);

  protected:
    const TSortedStringArray* GetStrings() const;
    void                      SetStrings(TSortedStringArray* strings);

  protected_data:
    TSortedStringArray* Strings;

  DECLARE_STREAMABLE(_OWLCLASS, TStringLookupValidator, 1);
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

//----------------------------------------------------------------------------
// Inline Implementation
//

//
// Return true if the entry for the validator is valid.
//
inline bool TValidator::Valid(const char far* str, TWindow* owner)
{
  if (!IsValid(str)) {
    Error(owner);
    return false;
  }
  return true;
}

//
// Return true if the validator has a particular option.
//
inline bool TValidator::HasOption(int option)
{
  return Options & option;
}

//
// Turn on a validator option.
//
inline void TValidator::SetOption(int option)
{
  Options |= uint16(option);
}

//
// Turn off a validator option.
//
inline void TValidator::UnsetOption(int option)
{
  Options &= uint16(~option);
}

//
// Return the picture mask used by the validator.
//
inline const string& TPXPictureValidator::GetPic() const
{
  return Pic;
}

//
// Set the picture mask for the validator.
//
inline void TPXPictureValidator::SetPic(const string& pic)
{
  Pic = pic;
}

//
// Return the valid character set for the validator.
//
inline const TCharSet& TFilterValidator::GetValidChars()
{
  return ValidChars;
}

//
// Set the valid character set for the validator.
//
inline void TFilterValidator::SetValidChars(const TCharSet& vc)
{
  ValidChars = vc;
}

//
// Return the minimum number the validator can accept.
//
inline long TRangeValidator::GetMin()
{
  return Min;
}

//
// Set the minimum number the validator can accept.
//
inline void TRangeValidator::SetMin(long min)
{
  Min = min;
}

//
// Return the maximum number the validator can accept.
//
inline long TRangeValidator::GetMax()
{
  return Max;
}

//
// Set the maximum number the validator can accept.
//
inline void TRangeValidator::SetMax(long max)
{
  Max = max;
}

//
// Return the set of valid strings used by the validator.
//
inline const TSortedStringArray* TStringLookupValidator::GetStrings() const
{
  return Strings;
}

//
// Set the valid strings used by the validator.
//
inline void TStringLookupValidator::SetStrings(TSortedStringArray* strings)
{
  delete Strings;
  Strings = strings;
}

#endif  // OWL_VALIDATE_H
