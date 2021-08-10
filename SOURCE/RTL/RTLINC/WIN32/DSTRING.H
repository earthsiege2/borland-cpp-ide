//---------------------------------------------------------------------------
//    dstring.h - support for delphi strings in c++
//                (AnsiString and template<sz> SmallString)
//---------------------------------------------------------------------------
// $Revision:   8.4  $
//-------------------------------------------------------------------------
//    copyright (c) 1996 Borland International
//----------------------------------------------------------------------------
#ifndef DSTRING_H
#define DSTRING_H

//---------------------------------------------------------------------------
// VCL files must be built with namespace option enabled to eliminate
//     ambiguities such as Graphics and Windows TBitmap.
//---------------------------------------------------------------------------
#if !defined(BCB_NAMESPACES)
#define BCB_NAMESPACES
#endif

#include <iostream.h>

//---------------------------------------------------------------------------
extern void __fastcall InitExe();
//---------------------------------------------------------------------------
// forward declarations
#if defined(BCB_NAMESPACES)
namespace System
{
#endif

class TVarRec;
class __declspec(delphireturn) Currency;
//---------------------------------------------------------------------------
class __declspec(delphireturn) AnsiString
{
  friend AnsiString __fastcall operator +(const char*, const AnsiString& rhs);
  public:
    // the TStringFloatFormat enum is used by FloatToStrF
    enum TStringFloatFormat
      { sffGeneral, sffExponent, sffFixed, sffNumber, sffCurrency };
    static AnsiString __fastcall StringOfChar(char ch, int count);
    static AnsiString __fastcall LoadStr(int ident);
    static AnsiString __fastcall FmtLoadStr(int ident, const TVarRec *args,
      int size);
    static AnsiString __fastcall Format(const AnsiString& format,
      const TVarRec *args, int size);
    static AnsiString __fastcall FormatFloat(const AnsiString& format,
      const long double& value);
    static AnsiString __fastcall FloatToStrF(long double value,
      TStringFloatFormat format, int precision, int digits);
    static AnsiString __fastcall IntToHex(int value, int digits);
    static AnsiString __fastcall CurrToStr(Currency value);
    static AnsiString __fastcall CurrToStrF(Currency value,
      TStringFloatFormat format, int digits);

    // Constructors
    __fastcall AnsiString(): Data(0) {}
    __fastcall AnsiString(const char* src);
    __fastcall AnsiString(const AnsiString& src);
    __fastcall AnsiString(const char* src, unsigned char len);
    __fastcall AnsiString(const wchar_t* src);
    __fastcall AnsiString(char src);
    __fastcall AnsiString(int src);
    __fastcall AnsiString(double src);

    // Destructor
    __fastcall ~AnsiString();

    // Assignments
    AnsiString& __fastcall operator =(const AnsiString& rhs);
    AnsiString& __fastcall operator +=(const AnsiString& rhs);

    //Comparisons
    bool __fastcall operator ==(const AnsiString& rhs) const;
    bool __fastcall operator !=(const AnsiString& rhs) const;
    bool __fastcall operator <(const AnsiString& rhs) const;
    bool __fastcall operator >(const AnsiString& rhs) const;
    bool __fastcall operator <=(const AnsiString& rhs) const;
    bool __fastcall operator >=(const AnsiString& rhs) const;
    int __fastcall AnsiCompare(const AnsiString& rhs) const;
    int __fastcall AnsiCompareIC(const AnsiString& rhs) const; //ignorecase

    // Index
    char& __fastcall operator [](const int idx) {return Data[idx];}

    // Concatenation
    AnsiString __fastcall operator +(const AnsiString& rhs) const;

    // C string operator
    char* __fastcall c_str() const
      {return (Data)? Data: "";}

    int __fastcall Length() const; //!JK is this same as RTL's Length?
    bool __fastcall IsEmpty() const;

    // make string unique (refcnt == 1)
    void __fastcall Unique();

    void __fastcall Insert(const AnsiString& str, int index);
    void __fastcall Delete(int index, int count);
    void __fastcall SetLength(int newLength);

    int __fastcall Pos(const AnsiString& subStr) const;
    AnsiString __fastcall LowerCase() const;
    AnsiString __fastcall UpperCase() const;
    AnsiString __fastcall Trim() const;
    AnsiString __fastcall TrimLeft() const;
    AnsiString __fastcall TrimRight() const;
    AnsiString __fastcall SubString(int index, int count) const;

    int __fastcall ToInt() const;
    int __fastcall ToIntDef(int defaultValue) const;
    double __fastcall ToDouble() const;

    //Convert to Unicode
    int __fastcall WideCharBufSize() const;
    wchar_t* __fastcall WideChar(wchar_t* dest, int destSize) const;

    // mbcs support
    enum TStringMbcsByteType { mbSingleByte, mbLeadByte, mbTrailByte };

    TStringMbcsByteType __fastcall ByteType(int index) const;
    bool __fastcall IsLeadByte(int index) const;
    bool __fastcall IsTrailByte(int index) const;
    bool __fastcall IsDelimiter(const AnsiString& delimiters, int index) const;
    bool __fastcall IsPathDelimiter(int index) const;
    int __fastcall LastDelimiter(const AnsiString& delimiters) const;
    int __fastcall AnsiPos(const AnsiString& subStr) const;
    char* __fastcall AnsiLastChar() const;

  private:
    char *Data;
};
//---------------------------------------------------------------------------
AnsiString __fastcall operator +(const char*, const AnsiString& rhs);
inline ostream& operator <<(ostream& os, const AnsiString& arg)
  {os << arg.c_str(); return os;}
istream& operator >>(istream& is, AnsiString& arg);
//---------------------------------------------------------------------------
template <unsigned char sz> class SmallString
{
  friend ostream& operator <<(ostream& os, const SmallString& arg)
    {os << AnsiString(arg).c_str(); return os;}
  friend istream& operator >>(istream& is, SmallString& arg)
    {AnsiString s; is >> s; arg = s; return is;}
  public:
    // Constrctors
    __fastcall SmallString(): Len(0) {}

    // Note: these constructors have been moved into the class delcaration
    //       because the compiler doesn not like __fastcall on this syntax
    //       when implemented outside the class delcaration (bug reported)
    __fastcall SmallString(const char* src)
    {
    long len = strlen(src);
      Len = (unsigned char)((len > sz)? sz: len);
      strncpy(Data, src, Len);
    }
    __fastcall SmallString(const SmallString& src)
    {
      Len = src.Len;
      for (int i = 0; i < Len; i++)
        Data[i] = src.Data[i];
    }
    __fastcall SmallString(const AnsiString& src)
    {
      long len = src.Length();
      Len = (unsigned char)((len > sz)? sz: len);
      strncpy(Data, src.c_str(), Len);
    }

    char& __fastcall operator [](const unsigned char idx)
      {return Data[idx];}

    SmallString& __fastcall operator =(const SmallString& rhs);

    __fastcall operator AnsiString() const;

  protected:
    unsigned char Len;
    char Data[sz];
};
//---------------------------------------------------------------------------
// used when SmallStrings are in unions (can't have a ctor)
// must cast DummySmallString to SmallString to do anything useful

template <unsigned char sz> class DummySmallString
{
    protected:
        unsigned char Len;
        char Data[sz];
};
//---------------------------------------------------------------------------
template<unsigned char sz> inline
SmallString& __fastcall SmallString<sz>::operator =(const SmallString& rhs)
{
    if (this != &rhs)
    {
        Len = rhs.Len;
        for (int i = 0; i < Len; i++)
            Data[i] = rhs.Data[i];
    }
    return *this;
}
//---------------------------------------------------------------------------
template<unsigned char sz> inline
__fastcall SmallString<sz>::operator AnsiString() const
{
  return AnsiString(Data, Len);
}

#if defined(BCB_NAMESPACES)
}
using namespace System;
#endif

#endif

