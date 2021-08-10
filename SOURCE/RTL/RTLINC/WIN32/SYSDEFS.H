//---------------------------------------------------------------------------
//    sysdefs.h - support for properties & vcl intrinsic types
//---------------------------------------------------------------------------
// $Revision:   8.5  $
//-------------------------------------------------------------------------
//    copyright (c) 1996 Borland International
//----------------------------------------------------------------------------
#ifndef SYSDEFS_H
#define SYSDEFS_H
#if __BORLANDC__ < 0x500
#error BCW 5.0 or greater required
#endif

//---------------------------------------------------------------------------
// VCL files must be built with namespace option enabled to eliminate
//     ambiguities such as Graphics and Windows TBitmap.
//---------------------------------------------------------------------------
#if !defined(BCB_NAMESPACES)
#define BCB_NAMESPACES
#endif

//---------------------------------------------------------------------------
#pragma option -w-lvc       // turn off "temp used for param" warnings
#pragma option -w-inl       // turn off "cannot expand inline..." warnings

#pragma anon_struct on      // support anonymous structs (within unions)
//---------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#ifdef SEEK_SET
#undef SEEK_SET
#undef SEEK_CUR
#undef SEEK_END
#endif
#include <string.h>
#include <dstring.h>
//---------------------------------------------------------------------------
#define DYNAMIC
#define MESSAGE

//---------------------------------------------------------------------------
//forward declarations
//
#if defined(BCB_NAMESPACES)
namespace Ole2
{
#endif

  class IUnknown;
  class IDispatch;

#if defined(BCB_NAMESPACES)
}
#endif

#if defined(BCB_NAMESPACES)
namespace Classes
{
#endif

  class TPersistent;

#if defined(BCB_NAMESPACES)
}
using namespace Classes;
#endif

#if defined(BCB_NAMESPACES)
namespace System
{
#endif

class __declspec(delphireturn) Variant;

//---------------------------------------------------------------------------
class TMetaClass;
//---------------------------------------------------------------------------
typedef TMetaClass* TClass;
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class __declspec(delphireturn) CurrencyBase
{
  public:
    __int64 Val;
};
//---------------------------------------------------------------------------
class __declspec(delphireturn) Currency : public CurrencyBase
{
  friend Currency __fastcall operator +(int lhs, const Currency& rhs);
  friend Currency __fastcall operator -(int lhs, const Currency& rhs);
  friend Currency __fastcall operator *(int lhs, const Currency& rhs);
  friend Currency __fastcall operator /(int lhs, const Currency& rhs);
  friend Currency __fastcall operator +(double lhs, const Currency& rhs);
  friend Currency __fastcall operator -(double lhs, const Currency& rhs);
  friend Currency __fastcall operator *(double lhs, const Currency& rhs);
  friend Currency __fastcall operator /(double lhs, const Currency& rhs);
  public:
    __fastcall Currency()                        {Val = 0;}
    __fastcall Currency(double val)        {Val = 10000*(long double)val;}
    __fastcall Currency(int val)           {Val = 10000*(__int64)val;}
    __fastcall Currency(const CurrencyBase& src) {Val = src.Val;}
    __fastcall Currency(const Currency& src)     {Val = src.Val;}
    __fastcall Currency(const AnsiString& src);

    Currency& __fastcall operator =(double rhs)
      {Val = 10000*(long double)rhs; return *this;}
    Currency& __fastcall operator =(int rhs)
      {Val = 10000*(__int64)rhs; return *this;}
    Currency& __fastcall operator =(const CurrencyBase& rhs)
      {Val=rhs.Val;return *this;}
    Currency& __fastcall operator =(const Currency& rhs)
      {Val = rhs.Val; return *this;}

    Currency& __fastcall operator +=(const Currency& rhs)
      {Val += rhs.Val; return *this;}
    Currency& __fastcall operator -=(const Currency& rhs)
      {Val -= rhs.Val; return *this;}
    Currency& __fastcall operator *=(const Currency& rhs)
      {Val *= rhs.Val; Val /= 10000; return *this;}
    Currency& __fastcall operator /=(const Currency& rhs)
      {Val *= 10000; Val /= rhs.Val; return *this;}
    Currency& __fastcall operator %=(int rhs)
      {Val %= 10000 * (__int64)rhs; return *this;}

    Currency& operator ++() {Val += 10000; return *this;}
    Currency operator ++(int) {Currency tmp(*this); Val += 10000; return tmp;}
    Currency& operator --() {Val -= 10000; return *this;}
    Currency operator --(int) {Currency tmp(*this); Val -= 10000; return tmp;}

    Currency __fastcall operator +(const Currency& rhs) const
      {Currency tmp(*this); return tmp += rhs;}
    Currency __fastcall operator -(const Currency& rhs) const
      {Currency tmp(*this); return tmp -= rhs;}
    Currency __fastcall operator *(const Currency& rhs) const
      {Currency tmp(*this); return tmp *= rhs;}
    Currency __fastcall operator /(const Currency& rhs) const
      {Currency tmp(*this); return tmp /= rhs;}

    Currency __fastcall operator +(int rhs) const
      {Currency tmp(*this); return tmp += Currency(rhs);}
    Currency __fastcall operator -(int rhs) const
      {Currency tmp(*this); return tmp -= Currency(rhs);}
    Currency __fastcall operator *(int rhs) const
      {Currency tmp(*this); return tmp *= Currency(rhs);}
    Currency __fastcall operator /(int rhs) const
      {Currency tmp(*this); return tmp /= Currency(rhs);}
    Currency __fastcall operator %(int rhs) const
      {return Currency(static_cast<int>(Val % (10000 * (__int64)rhs))) / 10000;}

    Currency __fastcall operator +(double rhs) const
      {Currency tmp(*this); return tmp += Currency(rhs);}
    Currency __fastcall operator -(double rhs) const
      {Currency tmp(*this); return tmp -= Currency(rhs);}
    Currency __fastcall operator *(double rhs) const
      {Currency tmp(*this); return tmp *= Currency(rhs);}
    Currency __fastcall operator /(double rhs) const
      {Currency tmp(*this); return tmp /= Currency(rhs);}

    Currency __fastcall operator -() const
      {Currency tmp(*this); tmp.Val = -(tmp.Val); return tmp;}

    Currency __fastcall operator !() const
      {Currency tmp(*this); tmp.Val = !(tmp.Val); return tmp;}

    // comparisons (Currency rhs)
    bool __fastcall operator ==(const Currency& rhs) const
      {return Val == rhs.Val;}
    bool __fastcall operator !=(const Currency& rhs) const
      {return Val != rhs.Val;}
    bool __fastcall operator >(const Currency& rhs) const
      {return Val > rhs.Val;}
    bool __fastcall operator <(const Currency& rhs) const
      {return Val < rhs.Val;}
    bool __fastcall operator >=(const Currency& rhs) const
      {return Val >= rhs.Val;}
    bool __fastcall operator <=(const Currency& rhs) const
      {return Val <= rhs.Val;}

    // comparisons (int rhs)
    bool __fastcall operator ==(int rhs) const
      {return Val == 10000 * (__int64)rhs;}
    bool __fastcall operator !=(int rhs) const
      {return Val != 10000 * (__int64)rhs;}
    bool __fastcall operator >(int rhs) const
      {return Val > 10000 * (__int64)rhs;}
    bool __fastcall operator <(int rhs) const
      {return Val < 10000 * (__int64)rhs;}
    bool __fastcall operator >=(int rhs) const
      {return Val >= 10000 * (__int64)rhs;}
    bool __fastcall operator <=(int rhs) const
      {return Val <= 10000 * (__int64)rhs;}

    // comparisons (double rhs)
    bool __fastcall operator ==(double rhs) const
      {return Val == 10000 * (long double)rhs;}
    bool __fastcall operator !=(double rhs) const
      {return Val != 10000 * (long double)rhs;}
    bool __fastcall operator >(double rhs) const
      {return Val > 10000 * (long double)rhs;}
    bool __fastcall operator <(double rhs) const
      {return Val < 10000 * (long double)rhs;}
    bool __fastcall operator >=(double rhs) const
      {return Val >= 10000 * (long double)rhs;}
    bool __fastcall operator <=(double rhs) const
      {return Val <= 10000 * (long double)rhs;}

    __fastcall operator double() const {return ((double)Val) / 10000;}
    __fastcall operator int() const    {return (int) (Val / 10000);}
    __fastcall operator AnsiString() const;
};
//Currency friends
inline Currency __fastcall operator +(int lhs, const Currency& rhs)
  {Currency tmp(lhs); return tmp += rhs;}
inline Currency __fastcall operator -(int lhs, const Currency& rhs)
  {Currency tmp(lhs); return tmp -= rhs;}
inline Currency __fastcall operator *(int lhs, const Currency& rhs)
  {Currency tmp(lhs); return tmp *= rhs;}
inline Currency __fastcall operator /(int lhs, const Currency& rhs)
  {Currency tmp(lhs); return tmp /= rhs;}
inline Currency __fastcall operator +(double lhs, const Currency& rhs)
  {Currency tmp(lhs); return tmp += rhs;}
inline Currency __fastcall operator -(double lhs, const Currency& rhs)
  {Currency tmp(lhs); return tmp -= rhs;}
inline Currency __fastcall operator *(double lhs, const Currency& rhs)
  {Currency tmp(lhs); return tmp *= rhs;}
inline Currency __fastcall operator /(double lhs, const Currency& rhs)
  {Currency tmp(lhs); return tmp /= rhs;}
//---------------------------------------------------------------------------
inline ostream& operator <<(ostream& os, const Currency& arg)
    {os << AnsiString(arg); return os;}
inline istream& operator >>(istream& is, Currency& arg)
    {AnsiString s; is >> s; arg = s; return is;}
//---------------------------------------------------------------------------
class __declspec(delphireturn) TDateTimeBase
{
  public:
    double Val;
};
//---------------------------------------------------------------------------
class __declspec(delphireturn) TDateTime : public TDateTimeBase
{
  public:
    // Used by TDateTime(const AnsiString& src)
    enum TDateTimeFlag {Date, Time, DateTime};

    static TDateTime __fastcall CurrentDate();
    static TDateTime __fastcall CurrentTime();
    static TDateTime __fastcall CurrentDateTime();
    static TDateTime __fastcall FileDateToDateTime(int fileDate);

    __fastcall TDateTime()                                  {Val = 0;}
    __fastcall TDateTime(const TDateTimeBase& src)          {Val = src.Val;}
    __fastcall TDateTime(const TDateTime& src)              {Val = src.Val;}
    __fastcall TDateTime(const double src)                  {Val = src;}
    __fastcall TDateTime(const int src)                     {Val = src;}
    __fastcall TDateTime(const AnsiString& src, TDateTimeFlag flag = DateTime);
    __fastcall TDateTime(unsigned short year, unsigned short month,
                         unsigned short day);
    __fastcall TDateTime(unsigned short hour, unsigned short min,
                         unsigned short sec, unsigned short msec);

    TDateTime& __fastcall operator =(const TDateTimeBase& rhs)
      {Val = rhs.Val;return *this;}
    TDateTime& __fastcall operator =(const TDateTime& rhs)
      {Val = rhs.Val;  return *this;}
    TDateTime& __fastcall operator =(const double rhs)
      {Val = rhs; return *this;}
    TDateTime& __fastcall operator =(const int rhs)
      {Val = rhs; return *this;}

    TDateTime& __fastcall operator +=(const TDateTimeBase& rhs)
      {Val+=rhs.Val;return *this;}
    TDateTime& __fastcall operator +=(const TDateTime& rhs)
      {Val += rhs.Val; return *this;}
    TDateTime& __fastcall operator +=(const double rhs)
      {Val += rhs; return *this;}
    TDateTime& __fastcall operator +=(const int rhs)
      {Val += rhs; return *this;}

    TDateTime& __fastcall operator -=(const TDateTimeBase& rhs)
      {Val-=rhs.Val;return *this;}
    TDateTime& __fastcall operator -=(const TDateTime& rhs)
      {Val -= rhs.Val; return *this;}
    TDateTime& __fastcall operator -=(const double rhs)
      {Val -= rhs; return *this;}
    TDateTime& __fastcall operator -=(const int rhs)
      {Val -= rhs; return *this;}

    TDateTime& operator ++() {Val++; return *this;}
    TDateTime operator ++(int) {TDateTime tmp(*this); Val++; return tmp;}
    TDateTime& operator --() {Val--; return *this;}
    TDateTime operator --(int) {TDateTime tmp(*this); Val--; return tmp;}

    TDateTime __fastcall operator +(const TDateTimeBase& rhs) const
      {return Val+rhs.Val;}
    TDateTime __fastcall operator +(const TDateTime& rhs) const
      {return Val+rhs.Val;}
    TDateTime __fastcall operator +(const double rhs) const {return Val+rhs;}
    TDateTime __fastcall operator +(const int rhs) const {return Val+rhs;}

    TDateTime __fastcall operator -(const TDateTimeBase& rhs) const
      {return Val-rhs.Val;}
    TDateTime __fastcall operator -(const TDateTime& rhs) const
      {return Val-rhs.Val;}
    TDateTime __fastcall operator -(const double rhs) const {return Val-rhs;}
    TDateTime __fastcall operator -(const int rhs) const {return Val-rhs;}

    // comparisons
    bool __fastcall operator ==(const TDateTime& rhs) const
      {return Val == rhs.Val;}
    bool __fastcall operator !=(const TDateTime& rhs) const
      {return Val != rhs.Val;}
    bool __fastcall operator >(const TDateTime& rhs) const
      {return Val > rhs.Val;}
    bool __fastcall operator <(const TDateTime& rhs) const
      {return Val < rhs.Val;}
    bool __fastcall operator >=(const TDateTime& rhs) const
      {return Val >= rhs.Val;}
    bool __fastcall operator <=(const TDateTime& rhs) const
      {return Val <= rhs.Val;}

    __fastcall operator AnsiString() const;//<Date||Time||DateTime>String(smart)
    AnsiString __fastcall FormatString(const AnsiString& format);
    AnsiString __fastcall DateString() const;
    AnsiString __fastcall TimeString() const;
    AnsiString __fastcall DateTimeString() const;
    __fastcall operator double() const {return Val;}
    __fastcall operator int() const    {return (int)Val;}

    int __fastcall DayOfWeek() const;
    int __fastcall FileDate() const;
    void __fastcall DecodeDate(unsigned short* year, unsigned short*
      month, unsigned short* day) const;
    void __fastcall DecodeTime(unsigned short* hour, unsigned short*
      min, unsigned short* sec, unsigned short* msec) const;
};
//---------------------------------------------------------------------------
inline ostream& operator <<(ostream& os, const TDateTime& arg)
    {os << AnsiString(arg); return os;}
inline istream& operator >>(istream& is, TDateTime& arg)
    {AnsiString s; is >> s; arg = s; return is;}
//---------------------------------------------------------------------------
//class TObject {};
typedef SmallString<255> ShortString;
class   __declspec(delphiclass) TObject
{
  public:
    __fastcall TObject() {}
    __fastcall Free();
    TClass __fastcall ClassType();
    void __fastcall CleanupInstance();
    void * __fastcall FieldAddress(const ShortString &Name);

    static TObject * __fastcall InitInstance(TClass cls, void *instance);
    static ShortString __fastcall ClassName(TClass cls);
    static bool __fastcall ClassNameIs(TClass cls, const AnsiString string);
    static TClass __fastcall ClassParent(TClass cls);
    static void * __fastcall ClassInfo(TClass cls);
    static long __fastcall InstanceSize(TClass cls);
    static bool __fastcall InheritsFrom(TClass cls, TClass aClass);
    static void * __fastcall MethodAddress(TClass cls, const ShortString &Name);
    static ShortString __fastcall MethodName(TClass cls, void *Address);

    ShortString __fastcall ClassName()
    {
      return ClassName(ClassType());
    }

    bool __fastcall ClassNameIs(const AnsiString string)
    {
      return ClassNameIs(ClassType(), string);
    }

    TClass __fastcall ClassParent()
    {
      return ClassParent(ClassType());
    }

    void * __fastcall ClassInfo()
    {
      return ClassInfo(ClassType());
    }

    long __fastcall InstanceSize()
    {
      return InstanceSize(ClassType());
    }

    bool __fastcall InheritsFrom(TClass aClass)
    {
      return InheritsFrom(ClassType(), aClass);
    }

    void * __fastcall MethodAddress(const ShortString &Name)
    {
      return MethodAddress(ClassType(), Name);
    }

    ShortString __fastcall MethodName(void *Address)
    {
      return MethodName(ClassType(), Address);
    }

    virtual void __fastcall AfterConstruction();
    virtual void __fastcall BeforeDestruction();
    virtual void __fastcall Dispatch(void *Message);
    virtual void __fastcall DefaultHandler(void* Message);

  private:
    virtual TObject* __fastcall NewInstance(TClass cls);

  public:
    virtual void __fastcall FreeInstance();
    virtual __fastcall ~TObject() {}
};

class   TMetaClass
{
  public:
    TObject * __fastcall InitInstance(void *instance)
    {
      TObject::InitInstance(this, instance);
    }

    ShortString __fastcall ClassName()
    {
      return TObject::ClassName(this);
    }

    bool __fastcall ClassNameIs(const AnsiString &string)
    {
      return    TObject::ClassNameIs(this,string);
    }

    TClass __fastcall ClassParent()
    {
      return TObject::ClassParent(this);
    }

    void * __fastcall ClassInfo()
    {
      return TObject::ClassInfo(this);
    }

    long __fastcall InstanceSize()
    {
      return TObject::InstanceSize(this);
    }

    bool __fastcall InheritsFrom(TClass aClass)
    {
      return TObject::InheritsFrom(this, aClass);
    }

    void * __fastcall MethodAddress(const ShortString &Name)
    {
      return TObject::MethodAddress(this, Name);
    }

    ShortString __fastcall MethodName(void *Address)
    {
      return TObject::MethodName(this,Address);
    }
};

#define BEGIN_MESSAGE_MAP       virtual void __fastcall Dispatch(void *Message) \
                                {                                               \
                                        switch  (((PMessage)Message)->Msg)      \
                                        {
#define MESSAGE_HANDLER(msg,type,meth)                                          \
                                        case    msg:                            \
                                                meth(*((type *)Message));       \
                                                break;
#define END_MESSAGE_MAP(base)           default:                                \
                                                                base::Dispatch(Message);        \
                                                        break;                          \
                                        }                                                                                       \
                                }
//---------------------------------------------------------------------------
typedef DummySmallString<255> DummyShortString;
typedef bool Boolean;                   //
typedef int Integer;                    // -2147483648..2147484647
typedef char Char;             // 0..255
typedef wchar_t WideChar;               //
typedef signed char Shortint;           // -128..127
typedef short Smallint;                 // -32768..32767
typedef unsigned char Byte;             // 0..255
typedef unsigned short Word;            // 0..65535
typedef void* Pointer;                  //
typedef Char AnsiChar;                  //
typedef signed long Longint;            // -2147483648..2147484647
typedef unsigned int Cardinal;         // 0..2147484647
typedef long double Extended;           // 10 byte real
typedef float Single;                   // 4 byte real
typedef double Double;                  // 8 byte real
typedef Char* const Openstring;         // D16 string/D32 shortstring formalparm
typedef void* file;                     //
typedef void* Text;                     //
typedef Text TextFile;                  //
typedef Char* PChar;                    //
typedef PChar PAnsiChar;                //
typedef WideChar* PWideChar;            //
typedef Byte ByteBool;                  //
typedef Word WordBool;                  //
typedef Cardinal LongBool;              //
typedef AnsiString String;              //
typedef ShortString* PShortString;      //
typedef AnsiString* PAnsiString;        //
typedef PAnsiString PString;            //
typedef Extended* PExtended;            //
typedef Currency* PCurrency;            //
typedef Variant* PVariant;              //
typedef __int64 LONG64;                 //

// Comp
// Range: -263+1 .. 263-1, Significant digits: 19-20, Size: 8
// The Comp (computational) type holds only integral values within -263+1
// to 263-1, which is approximately -9.2 * 1018 to 9.2 * 1018.
//
struct Comp {
    Comp();
    Comp(double d);
    Comp(Currency d);
    operator =(double d);
    operator =(Currency d);
    operator double();
    operator Currency();
  private:
    char __data[8];
};

extern double   __cdecl CompToDouble(Comp acomp);
extern void     __cdecl DoubleToComp(double adouble, Comp &result);
extern Currency __cdecl CompToCurrency(Comp acomp);
extern void     __cdecl CurrencyToComp(Currency acurrency, Comp &result);


inline Comp::Comp() {
  DoubleToComp(0.0, *this);
}

inline Comp::Comp(double d) {
  *this = d;
}

inline Comp::operator = (double d) {
  DoubleToComp(d, *this);
}

inline Comp::operator double() {
  return CompToDouble(*this);
}

inline Comp::Comp(Currency d) {
  *this = d;
}

inline Comp::operator = (Currency d) {
  CurrencyToComp(d, *this);
}

inline Comp::operator Currency() {
  return CompToCurrency(*this);
}

//---------------------------------------------------------------------------
// Set template implements Delphi sets
//---------------------------------------------------------------------------
template<class T, unsigned char minEl, unsigned char maxEl>
class __declspec(delphireturn) Set
{
  friend ostream& operator <<(ostream& os, const Set& arg)
  {
    for (int i = minEl; i <= maxEl; i++)
      if (arg.Contains(static_cast<T>(i)))
        os << '1';
      else
        os << '0';
    return os;
  }

  friend istream& operator >>(istream& is, Set& arg)
  {
    unsigned char el;
    for (int i = minEl; i <= maxEl; i++)
    {
      is >> el;
      if (el == '1')
        arg << static_cast<T>(i);
    }
    return is;
  }
  public:
    __fastcall Set() {memset(Data, 0, sizeof (Data));}
    __fastcall Set(const Set& src)
    {
      for (int i = 0; i < sizeof (Data); i++)
        Data[i] = src.Data[i];
    }

    Set& __fastcall operator =(const Set& rhs)
    {
      if (this != &rhs)
      {
        for (int i = 0; i < sizeof (Data); i++)
          Data[i] = rhs.Data[i];
      }
      return *this;
    }
    Set& __fastcall operator +=(const Set& rhs) //Union
    {
      for (int i = 0; i < sizeof (Data); i++)
        Data[i] |= rhs.Data[i];
      return *this;
    }
    Set& __fastcall operator -=(const Set& rhs) //Difference
    {
      for (int i = 0; i < sizeof (Data); i++)
        Data[i] ^= (Data[i] & rhs.Data[i]);
      return *this;
    }
    Set& __fastcall operator *=(const Set& rhs) //Intersection
    {
      for (int i = 0; i < sizeof (Data); i++)
        Data[i] &= rhs.Data[i];
      return *this;
    }

    Set __fastcall operator +(const Set& rhs) const //Union
    {
      Set<T, minEl, maxEl> s;
      for (int i = 0; i < sizeof (Data); i++)
        s.Data[i] = Data[i] | rhs.Data[i];
      return s;
    }
    Set __fastcall operator -(const Set& rhs) const //Difference
    {
      Set<T, minEl, maxEl> s;
      for (int i = 0; i < sizeof (Data); i++)
        s.Data[i] = Data[i] ^ (Data[i] & rhs.Data[i]);
      return s;
    }
    Set __fastcall operator *(const Set& rhs) const //Intersection
    {
      Set<T, minEl, maxEl> s;
      for (int i = 0; i < sizeof (Data); i++)
        s.Data[i] = Data[i] & rhs.Data[i];
      return s;
    }

    Set& __fastcall operator <<(const T el) //Add element
    {
#pragma option -w-ccc
      if (el >= minEl && el <= maxEl)
#pragma option -w+ccc
        Data[(int)(el/8) - (int)(minEl/8)] |=
          (unsigned char)((unsigned short)1 << (el % 8));
      return *this;
    }
    Set& __fastcall operator >>(const T el) //Remove element
    {
#pragma option -w-ccc
      if (el >= minEl && el <= maxEl)
#pragma option -w+ccc
        Data[(int)(el/8) - (int)(minEl/8)] &=
          (unsigned char)~((unsigned short)1 << (el % 8));
      return *this;
    }

    bool __fastcall Contains(const T el) const
    {
#pragma option -w-ccc
      return (el >= minEl && el <= maxEl)?
#pragma option -w+ccc
        (Data[(int)(el/8) - (int)(minEl/8)] &
          (unsigned char)((unsigned short)1 << (el % 8))): false;
    }

    Set& __fastcall Clear()
    {
      for (int i = 0; i < sizeof (Data); i++)
        Data[i] = 0;
      return *this;
    }

    bool __fastcall operator ==(const Set& rhs) const
    {
      for (int i = 0; i < sizeof (Data); i++)
        if (Data[i] != rhs.Data[i])
          // Not so fast, if first or last byte, make sure that
          // the compare does not include unused bits (mask them)
          if (i == 0)
          {
            if(((0xFF >> (8-(minEl%8))) ^ Data[i]) !=
               ((0xFF >> (8-(minEl%8))) ^ rhs.Data[i]))
              return false;
          }
          else if (sizeof (Data) > 1 && i == sizeof (Data) - 1)
          {
            if(((0xFF << (1+(maxEl%8))) ^ Data[i]) !=
               ((0xFF << (1+(maxEl%8))) ^ rhs.Data[i]))
              return false;
          }
          else
            return false;
      return true;
    }
    bool __fastcall operator !=(const Set& rhs) const {return !operator==(rhs);}
  protected:
    unsigned char Data[((((int)(maxEl/8))-((int)(minEl/8))+1) != 3)?
      (((int)(maxEl/8))-((int)(minEl/8))+1): 4];
};
//---------------------------------------------------------------------------
template<class T, unsigned char minEl, unsigned char maxEl> class DummySet
{
  protected:
    unsigned char Data[((((int)(maxEl/8))-((int)(minEl/8))+1) != 3)?
      (((int)(maxEl/8))-((int)(minEl/8))+1): 4];
};
//---------------------------------------------------------------------------

class TVarArrayBound {
  public:
    Integer ElementCount;
    Integer LowBound;
};

typedef class TVarArray *PVarArray;

class TVarArray {
  public:
    Word DimCount;
    Word Flags;
    Integer ElementSize;
    Integer LockCount;
    Pointer Data;
    TVarArrayBound Bounds[256] /* [0..255] */;
};
//---------------------------------------------------------------------------
#define varEmpty (unsigned char)(0)
#define varNull (unsigned char)(1)
#define varSmallint (unsigned char)(2)
#define varInteger (unsigned char)(3)
#define varSingle (unsigned char)(4)
#define varDouble (unsigned char)(5)
#define varCurrency (unsigned char)(6)
#define varDate (unsigned char)(7)
#define varOleStr (unsigned char)(8)
#define varDispatch (unsigned char)(9)
#define varError (unsigned char)(10)
#define varBoolean (unsigned char)(11)
#define varVariant (unsigned char)(12)
#define varUnknown (unsigned char)(13)
#define varByte (unsigned char)(17)
#define varString (unsigned short)(256)
#define varTypeMask (unsigned short)(4095)
#define varArray (unsigned short)(8192)
#define varByRef (unsigned short)(16384)
#define varStrArg (unsigned char)(72)
//---------------------------------------------------------------------------
#define vtInteger (unsigned char)(0)
#define vtBoolean (unsigned char)(1)
#define vtChar (unsigned char)(2)
#define vtExtended (unsigned char)(3)
#define vtString (unsigned char)(4)
#define vtPointer (unsigned char)(5)
#define vtPChar (unsigned char)(6)
#define vtObject (unsigned char)(7)
#define vtClass (unsigned char)(8)
#define vtWideChar (unsigned char)(9)
#define vtPWideChar (unsigned char)(10)
#define vtAnsiString (unsigned char)(11)
#define vtCurrency (unsigned char)(12)
#define vtVariant (unsigned char)(13)
//---------------------------------------------------------------------------
typedef class TVarData *PVarData;

class TVarData {
  public: //!JK protected:
    Word VType;
    Word Reserved1;
    Word Reserved2;
    Word Reserved3;
    union {
      Smallint VSmallint;
      Integer VInteger;
      Single VSingle;
      Double VDouble;
      CurrencyBase VCurrency;
      TDateTimeBase VDate;
      PWideChar VOleStr;
      Ole2::IDispatch* VDispatch;
      Integer VError;
      WordBool VBoolean;
      Ole2::IUnknown* VUnknown;
      Byte VByte;
      Pointer VString;
      PVarArray VArray;
      Pointer VPointer;
    };
};
//-----------------------------------------------------------------------
class TVarRec;
typedef TVarRec* PVarRec;
class TVarRec
{
  public:
    union
    {
      Integer      VInteger;
      Boolean      VBoolean;
      Char         VChar;
      PExtended    VExtended;
      PShortString VString;
      Pointer      VPointer;
      PChar        VPChar;
      TObject*     VObject;
      TClass       VClass;
      WideChar     VWideChar;
      PWideChar    VPWideChar;
      Pointer      VAnsiString;
      PCurrency    VCurrency;
      PVariant     VVariant;
    };
    union
    {
      Byte VType;
      long ForceAlignment; //!JK should be removed, if alignment set to 4
                           //!JK we don't need this
    };

    //---- constructors ----
    __fastcall TVarRec(): VType(vtInteger), VInteger(0) {} //default int 0
    __fastcall TVarRec(Integer src): VType(vtInteger), VInteger(src) {}
    __fastcall TVarRec(Boolean src): VType(vtBoolean), VBoolean(src) {}
    __fastcall TVarRec(char src): VType(vtChar), VChar(src) {}
    __fastcall TVarRec(const Extended& src): VType(vtExtended),
      VExtended(const_cast<Extended*>(&src)) {}
    __fastcall TVarRec(const ShortString& src): VType(vtString),
      VString(const_cast<PShortString>(&src)) {}
    __fastcall TVarRec(const Pointer src): VType(vtPointer), VPointer(src) {}
    __fastcall TVarRec(const PChar src): VType(vtPChar), VPChar(src) {}
    __fastcall TVarRec(const char* src): VType(vtPChar),
      VPChar(reinterpret_cast<PChar>(const_cast<char*>(src))) {}
    __fastcall TVarRec(const TObject& src): VType(vtObject),
      VObject(const_cast<TObject*>(&src)) {}
    __fastcall TVarRec(const TClass src): VType(vtClass), VClass(src) {}
    __fastcall TVarRec(WideChar src): VType(vtWideChar), VWideChar(src) {}
    __fastcall TVarRec(const PWideChar src): VType(vtPWideChar),
      VPWideChar(src) {}
    __fastcall TVarRec(const AnsiString src): VType(vtAnsiString),
      VAnsiString(src.c_str()) {}
    __fastcall TVarRec(const Currency& src): VType(vtCurrency),
      VCurrency(const_cast<PCurrency>(&src)) {}
    __fastcall TVarRec(const Variant& src): VType(vtVariant),
      VVariant(const_cast<PVariant>(&src)) {}

    //---- assignments ----
    __fastcall operator =(Integer src) {VType = vtInteger; VInteger = src;}
    __fastcall operator =(Boolean src) {VType = vtBoolean; VBoolean = src;}
    __fastcall operator =(char src) {VType = vtChar; VChar = src;}
    __fastcall operator =(const Extended& src) {VType = vtExtended;
      VExtended = const_cast<PExtended>(&src);}
    __fastcall operator =(const ShortString& src) {VType = vtString;
      VString = const_cast<PShortString>(&src);}
    __fastcall operator =(const Pointer src) {VType = vtPointer;VPointer = src;}
    __fastcall operator =(const PChar src) {VType = vtPChar; VPChar = src;}
    __fastcall operator =(const char* src) {VType = vtPChar;
      VPChar = reinterpret_cast<PChar>(const_cast<char*>(src));}
    __fastcall operator =(const TObject& src) {VType = vtObject;
      VObject = const_cast<TObject*>(&src);}
    __fastcall operator =(const TClass src) {VType = vtClass; VClass = src;}
    __fastcall operator =(WideChar src) {VType = vtWideChar; VWideChar = src;}
    __fastcall operator =(const PWideChar src) {VType = vtPWideChar;
      VPWideChar = src;}
    __fastcall operator =(const AnsiString src) {VType = vtAnsiString;
      VAnsiString = src.c_str();}
    __fastcall operator =(const Currency& src) {VType = vtCurrency;
      VCurrency = const_cast<PCurrency>(&src);}
    __fastcall operator =(const Variant& src) {VType = vtVariant;
      VVariant = const_cast<PVariant>(&src);}
};
//-----------------------------------------------------------------------
template<class T> class OpenArray
{
  public:
    __fastcall OpenArray(T arg0)
    {
      Array = new T[Count = 1];
      Array[0] = arg0;
    }
    __fastcall OpenArray(T arg0, T arg1)
    {
      Array = new T[Count = 2];
      Array[0] = arg0;
      Array[1] = arg1;
    }
    __fastcall OpenArray(T arg0, T arg1, T arg2)
    {
      Array = new T[Count = 3];
      Array[0] = arg0;
      Array[1] = arg1;
      Array[2] = arg2;
    }
    __fastcall OpenArray(T arg0, T arg1, T arg2, T arg3)
    {
      Array = new T[Count = 4];
      Array[0] = arg0;
      Array[1] = arg1;
      Array[2] = arg2;
      Array[3] = arg3;
    }
    __fastcall OpenArray(T arg0, T arg1, T arg2, T arg3, T arg4)
    {
      Array = new T[Count = 5];
      Array[0] = arg0;
      Array[1] = arg1;
      Array[2] = arg2;
      Array[3] = arg3;
      Array[4] = arg4;
    }
    __fastcall OpenArray(T arg0, T arg1, T arg2, T arg3, T arg4, T arg5)
    {
      Array = new T[Count = 6];
      Array[0] = arg0;
      Array[1] = arg1;
      Array[2] = arg2;
      Array[3] = arg3;
      Array[4] = arg4;
      Array[5] = arg5;
    }
    __fastcall OpenArray(T arg0, T arg1, T arg2, T arg3, T arg4, T arg5, T arg6)
    {
      Array = new T[Count = 7];
      Array[0] = arg0;
      Array[1] = arg1;
      Array[2] = arg2;
      Array[3] = arg3;
      Array[4] = arg4;
      Array[5] = arg5;
      Array[6] = arg6;
    }
    __fastcall OpenArray(T arg0, T arg1, T arg2, T arg3, T arg4, T arg5, T arg6,
                         T arg7)
    {
      Array = new T[Count = 8];
      Array[0] = arg0;
      Array[1] = arg1;
      Array[2] = arg2;
      Array[3] = arg3;
      Array[4] = arg4;
      Array[5] = arg5;
      Array[6] = arg6;
      Array[7] = arg7;
    }
    __fastcall OpenArray(T arg0, T arg1, T arg2, T arg3, T arg4, T arg5, T arg6,
                         T arg7, T arg8)
    {
      Array = new T[Count = 9];
      Array[0] = arg0;
      Array[1] = arg1;
      Array[2] = arg2;
      Array[3] = arg3;
      Array[4] = arg4;
      Array[5] = arg5;
      Array[6] = arg6;
      Array[7] = arg7;
      Array[8] = arg8;
    }
    __fastcall OpenArray(T arg0, T arg1, T arg2, T arg3, T arg4, T arg5, T arg6,
                         T arg7, T arg8, T arg9)
    {
      Array = new T[Count = 10];
      Array[0] = arg0;
      Array[1] = arg1;
      Array[2] = arg2;
      Array[3] = arg3;
      Array[4] = arg4;
      Array[5] = arg5;
      Array[6] = arg6;
      Array[7] = arg7;
      Array[8] = arg8;
      Array[9] = arg9;
    }
    __fastcall OpenArray(T arg0, T arg1, T arg2, T arg3, T arg4, T arg5, T arg6,
                         T arg7, T arg8, T arg9, T arg10)
    {
      Array = new T[Count = 11];
      Array[0] = arg0;
      Array[1] = arg1;
      Array[2] = arg2;
      Array[3] = arg3;
      Array[4] = arg4;
      Array[5] = arg5;
      Array[6] = arg6;
      Array[7] = arg7;
      Array[8] = arg8;
      Array[9] = arg9;
      Array[10] = arg10;
    }
    __fastcall OpenArray(T arg0, T arg1, T arg2, T arg3, T arg4, T arg5, T arg6,
                         T arg7, T arg8, T arg9, T arg10, T arg11)
    {
      Array = new T[Count = 12];
      Array[0] = arg0;
      Array[1] = arg1;
      Array[2] = arg2;
      Array[3] = arg3;
      Array[4] = arg4;
      Array[5] = arg5;
      Array[6] = arg6;
      Array[7] = arg7;
      Array[8] = arg8;
      Array[9] = arg9;
      Array[10] = arg10;
      Array[11] = arg11;
    }
    __fastcall OpenArray(T arg0, T arg1, T arg2, T arg3, T arg4, T arg5, T arg6,
                         T arg7, T arg8, T arg9, T arg10, T arg11, T arg12)
    {
      Array = new T[Count = 13];
      Array[0] = arg0;
      Array[1] = arg1;
      Array[2] = arg2;
      Array[3] = arg3;
      Array[4] = arg4;
      Array[5] = arg5;
      Array[6] = arg6;
      Array[7] = arg7;
      Array[8] = arg8;
      Array[9] = arg9;
      Array[10] = arg10;
      Array[11] = arg11;
      Array[12] = arg12;
    }
    __fastcall OpenArray(T arg0, T arg1, T arg2, T arg3, T arg4, T arg5, T arg6,
                         T arg7, T arg8, T arg9, T arg10, T arg11, T arg12,
                         T arg13)
    {
      Array = new T[Count = 14];
      Array[0] = arg0;
      Array[1] = arg1;
      Array[2] = arg2;
      Array[3] = arg3;
      Array[4] = arg4;
      Array[5] = arg5;
      Array[6] = arg6;
      Array[7] = arg7;
      Array[8] = arg8;
      Array[9] = arg9;
      Array[10] = arg10;
      Array[11] = arg11;
      Array[12] = arg12;
      Array[13] = arg13;
    }
    __fastcall OpenArray(T arg0, T arg1, T arg2, T arg3, T arg4, T arg5, T arg6,
                         T arg7, T arg8, T arg9, T arg10, T arg11, T arg12,
                         T arg13, T arg14)
    {
      Array = new T[Count = 15];
      Array[0] = arg0;
      Array[1] = arg1;
      Array[2] = arg2;
      Array[3] = arg3;
      Array[4] = arg4;
      Array[5] = arg5;
      Array[6] = arg6;
      Array[7] = arg7;
      Array[8] = arg8;
      Array[9] = arg9;
      Array[10] = arg10;
      Array[11] = arg11;
      Array[12] = arg12;
      Array[13] = arg13;
      Array[14] = arg14;
    }
    __fastcall OpenArray(T arg0, T arg1, T arg2, T arg3, T arg4, T arg5, T arg6,
                         T arg7, T arg8, T arg9, T arg10, T arg11, T arg12,
                         T arg13, T arg14, T arg15)
    {
      Array = new T[Count = 16];
      Array[0] = arg0;
      Array[1] = arg1;
      Array[2] = arg2;
      Array[3] = arg3;
      Array[4] = arg4;
      Array[5] = arg5;
      Array[6] = arg6;
      Array[7] = arg7;
      Array[8] = arg8;
      Array[9] = arg9;
      Array[10] = arg10;
      Array[11] = arg11;
      Array[12] = arg12;
      Array[13] = arg13;
      Array[14] = arg14;
      Array[15] = arg15;
    }
    __fastcall OpenArray(T arg0, T arg1, T arg2, T arg3, T arg4, T arg5, T arg6,
                         T arg7, T arg8, T arg9, T arg10, T arg11, T arg12,
                         T arg13, T arg14, T arg15, T arg16)
    {
      Array = new T[Count = 17];
      Array[0] = arg0;
      Array[1] = arg1;
      Array[2] = arg2;
      Array[3] = arg3;
      Array[4] = arg4;
      Array[5] = arg5;
      Array[6] = arg6;
      Array[7] = arg7;
      Array[8] = arg8;
      Array[9] = arg9;
      Array[10] = arg10;
      Array[11] = arg11;
      Array[12] = arg12;
      Array[13] = arg13;
      Array[14] = arg14;
      Array[15] = arg15;
      Array[16] = arg16;
    }
    __fastcall OpenArray(T arg0, T arg1, T arg2, T arg3, T arg4, T arg5, T arg6,
                         T arg7, T arg8, T arg9, T arg10, T arg11, T arg12,
                         T arg13, T arg14, T arg15, T arg16, T arg17)
    {
      Array = new T[Count = 18];
      Array[0] = arg0;
      Array[1] = arg1;
      Array[2] = arg2;
      Array[3] = arg3;
      Array[4] = arg4;
      Array[5] = arg5;
      Array[6] = arg6;
      Array[7] = arg7;
      Array[8] = arg8;
      Array[9] = arg9;
      Array[10] = arg10;
      Array[11] = arg11;
      Array[12] = arg12;
      Array[13] = arg13;
      Array[14] = arg14;
      Array[15] = arg15;
      Array[16] = arg16;
      Array[17] = arg17;
    }
    __fastcall OpenArray(T arg0, T arg1, T arg2, T arg3, T arg4, T arg5, T arg6,
                         T arg7, T arg8, T arg9, T arg10, T arg11, T arg12,
                         T arg13, T arg14, T arg15, T arg16, T arg17, T arg18)
    {
      Array = new T[Count = 19];
      Array[0] = arg0;
      Array[1] = arg1;
      Array[2] = arg2;
      Array[3] = arg3;
      Array[4] = arg4;
      Array[5] = arg5;
      Array[6] = arg6;
      Array[7] = arg7;
      Array[8] = arg8;
      Array[9] = arg9;
      Array[10] = arg10;
      Array[11] = arg11;
      Array[12] = arg12;
      Array[13] = arg13;
      Array[14] = arg14;
      Array[15] = arg15;
      Array[16] = arg16;
      Array[17] = arg17;
      Array[18] = arg18;
    }
    __fastcall OpenArray(const OpenArray& src)
    {
      Array = new T[Count = src.Count];
      for (int i = 0; i < Count; i++)
        Array[i] = src.Array[i];
    }
    __fastcall ~OpenArray() {delete [] Array;}
    OpenArray& __fastcall operator =(const OpenArray& rhs);
    __fastcall operator T*() {return Array;}
    int __fastcall GetHigh() {return Count - 1;}

  private:
    T* Array;
    long Count;
};
//-----------------------------------------------------------------------
template<class T>
OpenArray& __fastcall
OpenArray<T>::operator =(const OpenArray& rhs)
{
  if (this != &rhs)
  {
    Array = new T[Count = rhs.Count];
    for (int i = 0; i < Count; i++)
      Array[i] = rhs.Array[i];
  }
  return *this;
}
//-----------------------------------------------------------------------
// Used with OPENARRAY macro (immediately following this template declaration)
template<class T> class OpenArrayCount
{
  public:
    __fastcall OpenArrayCount(T arg0): Count(1) {}
    __fastcall OpenArrayCount(T arg0,T arg1): Count(2) {}
    __fastcall OpenArrayCount(T arg0,T arg1,T arg2): Count(3) {}
    __fastcall OpenArrayCount(T arg0,T arg1,T arg2,T arg3): Count(4) {}
    __fastcall OpenArrayCount(T arg0,T arg1,T arg2,T arg3,T arg4): Count(5) {}
    __fastcall OpenArrayCount(T arg0,T arg1,T arg2,T arg3,T arg4, T arg5)
      : Count(6) {}
    __fastcall OpenArrayCount(T arg0, T arg1, T arg2, T arg3, T arg4, T arg5,
      T arg6): Count(7) {}
    __fastcall OpenArrayCount(T arg0, T arg1, T arg2, T arg3, T arg4, T arg5,
      T arg6, T arg7): Count(8) {}
    __fastcall OpenArrayCount(T arg0, T arg1, T arg2, T arg3, T arg4, T arg5,
      T arg6, T arg7, T arg8): Count(9) {}
    __fastcall OpenArrayCount(T arg0, T arg1, T arg2, T arg3, T arg4, T arg5,
      T arg6, T arg7, T arg8, T arg9): Count(10) {}
    __fastcall OpenArrayCount(T arg0, T arg1, T arg2, T arg3, T arg4, T arg5,
      T arg6, T arg7, T arg8, T arg9, T arg10): Count(11) {}
    __fastcall OpenArrayCount(T arg0, T arg1, T arg2, T arg3, T arg4, T arg5,
      T arg6, T arg7, T arg8, T arg9, T arg10, T arg11): Count(12) {}
    __fastcall OpenArrayCount(T arg0, T arg1, T arg2, T arg3, T arg4, T arg5,
      T arg6, T arg7, T arg8, T arg9, T arg10, T arg11, T arg12): Count(13) {}
    __fastcall OpenArrayCount(T arg0, T arg1, T arg2, T arg3, T arg4, T arg5,
      T arg6, T arg7, T arg8, T arg9, T arg10, T arg11, T arg12, T arg13)
      : Count(14) {}
    __fastcall OpenArrayCount(T arg0, T arg1, T arg2, T arg3, T arg4, T arg5,
      T arg6, T arg7, T arg8, T arg9, T arg10, T arg11, T arg12, T arg13,
      T arg14): Count(15) {}
    __fastcall OpenArrayCount(T arg0, T arg1, T arg2, T arg3, T arg4, T arg5,
      T arg6, T arg7, T arg8, T arg9, T arg10, T arg11, T arg12, T arg13,
      T arg14, T arg15): Count(16) {}
    __fastcall OpenArrayCount(T arg0, T arg1, T arg2, T arg3, T arg4, T arg5,
      T arg6, T arg7, T arg8, T arg9, T arg10, T arg11, T arg12, T arg13,
      T arg14, T arg15, T arg16): Count(17) {}
    __fastcall OpenArrayCount(T arg0, T arg1, T arg2, T arg3, T arg4, T arg5,
      T arg6, T arg7, T arg8, T arg9, T arg10, T arg11, T arg12, T arg13,
      T arg14, T arg15, T arg16, T arg17): Count(18) {}
    __fastcall OpenArrayCount(T arg0, T arg1, T arg2, T arg3, T arg4, T arg5,
      T arg6, T arg7, T arg8, T arg9, T arg10, T arg11, T arg12, T arg13,
      T arg14, T arg15, T arg16, T arg17, T arg18): Count(19) {}
    int __fastcall GetHigh() {return Count - 1;}
  private:
    long Count;
};
//-----------------------------------------------------------------------
// OPENARRAY: construct an OpenArray<type> on the fly
//
#define OPENARRAY(type, values) \
        OpenArray<type>values, OpenArrayCount<type>values.GetHigh()
//-----------------------------------------------------------------------
// ARRAYOFCONST: construct an OpenArray<TVarRec> on the fly
//
#define ARRAYOFCONST(values) \
        OpenArray<TVarRec>values, OpenArrayCount<TVarRec>values.GetHigh()
//---------------------------------------------------------------------
#define ARRAYSIZE(a) (sizeof(a)/sizeof(a[0]))
//-----------------------------------------------------------------------
// EXISTINGARRAY: pass an existing array where an open array is expected
#define EXISTINGARRAY(a) (a), ((sizeof(a)/sizeof(a[0]))-1)
//-----------------------------------------------------------------------
// SLICE: pass part of an existing array where an open array is expected
#define SLICE(a, n) (a), (n - 1)
//-----------------------------------------------------------------------
//forward declare AutoCmd - used by Variant's Exec function
class AutoCmd;
//-----------------------------------------------------------------------

// Required for windows.hpp
//
#if !defined(LOCALE_SYSTEM_DEFAULT)
// !JW  We don't want to undefine this if it came from winnt.h!
# define NOW_UNDEF_LOCALE_SYSTEM_DEFAULT TRUE
# if !defined(BCB_NAMESPACES)
#   define LOCALE_SYSTEM_DEFAULT Smallint(2048)
# else
#   define LOCALE_SYSTEM_DEFAULT System::Smallint(2048)
# endif
#endif

//-----------------------------------------------------------------------
class __declspec(delphireturn) Variant: public TVarData
{
  friend class AutoCmd;
  friend ostream& operator <<(ostream& os, const Variant& arg);
  public:
    static Variant __fastcall CreateObject(const String& ProgID);
    static Variant __fastcall GetActiveObject(const String& ProgID);
    //ctors
    __fastcall Variant();
    __fastcall Variant(const Variant& src);

    //By value constructors
    __fastcall Variant(const short src);
    __fastcall Variant(const int src);
    __fastcall Variant(const float src);
    __fastcall Variant(const double src);
    __fastcall Variant(const Currency src);
    __fastcall Variant(const TDateTime src);
    __fastcall Variant(const bool src);
    __fastcall Variant(const WordBool src);
    __fastcall Variant(const Byte src);
    __fastcall Variant(const AnsiString& src);
    __fastcall Variant(const char* src); // treat as asciiz pointer
    __fastcall Variant(wchar_t* const src);
    __fastcall Variant(Ole2::IDispatch* const src);
    __fastcall Variant(Ole2::IUnknown* const src);

    //By ref constructors
    __fastcall Variant(short* src);
    __fastcall Variant(int* src);
    __fastcall Variant(float* src);
    __fastcall Variant(double* src);
    __fastcall Variant(Currency* src);
    __fastcall Variant(TDateTime* src);
    __fastcall Variant(WordBool* src);
    __fastcall Variant(Byte* src);
    __fastcall Variant(wchar_t** src);

    // constructor for array of variants of type varType
    __fastcall Variant(const int* bounds, const int boundsSize, Word varType);

    // constructor for one dimensional array of type Variant
    __fastcall Variant(const Variant* values, const int valuesSize);

    __fastcall ~Variant();

    //assignments
    Variant& __fastcall operator =(const Variant& rhs);
    Variant& __fastcall operator +=(const Variant& rhs);
    Variant& __fastcall operator -=(const Variant& rhs);
    Variant& __fastcall operator *=(const Variant& rhs);
    Variant& __fastcall operator /=(const Variant& rhs);
    Variant& __fastcall operator %=(const Variant& rhs);
    Variant& __fastcall operator &=(const Variant& rhs);
    Variant& __fastcall operator |=(const Variant& rhs);
    Variant& __fastcall operator ^=(const Variant& rhs);
    Variant& __fastcall operator <<=(const Variant& rhs);
    Variant& __fastcall operator >>=(const Variant& rhs);

    // comparisons (Variant on right)
    bool __fastcall operator ==(const Variant& rhs) const;
    bool __fastcall operator !=(const Variant& rhs) const;
    bool __fastcall operator <(const Variant& rhs) const;
    bool __fastcall operator >(const Variant& rhs) const;
    bool __fastcall operator <=(const Variant& rhs) const;
    bool __fastcall operator >=(const Variant& rhs) const;

    // comparisons (int on right)
    bool __fastcall operator ==(int rhs) const
      {return operator ==(Variant(rhs));}
    bool __fastcall operator !=(int rhs) const
      {return operator !=(Variant(rhs));}
    bool __fastcall operator < (int rhs) const
      {return operator < (Variant(rhs));}
    bool __fastcall operator > (int rhs) const
      {return operator > (Variant(rhs));}
    bool __fastcall operator <=(int rhs) const
      {return operator <=(Variant(rhs));}
    bool __fastcall operator >=(int rhs) const
      {return operator >=(Variant(rhs));}

    // comparisons (double on right)
    bool __fastcall operator ==(double rhs) const
      {return operator ==(Variant(rhs));}
    bool __fastcall operator !=(double rhs) const
      {return operator !=(Variant(rhs));}
    bool __fastcall operator < (double rhs) const
      {return operator <(Variant(rhs));}
    bool __fastcall operator > (double rhs) const
      {return operator >(Variant(rhs));}
    bool __fastcall operator <=(double rhs) const
      {return operator <=(Variant(rhs));}
    bool __fastcall operator >=(double rhs) const
      {return operator >=(Variant(rhs));}

    // binary operators (Variant on right)
    Variant __fastcall operator +(const Variant& rhs) const;
    Variant __fastcall operator -(const Variant& rhs) const;
    Variant __fastcall operator *(const Variant& rhs) const;
    Variant __fastcall operator /(const Variant& rhs) const;
    Variant __fastcall operator %(const Variant& rhs) const;
    Variant __fastcall operator &(const Variant& rhs) const;
    Variant __fastcall operator |(const Variant& rhs) const;
    Variant __fastcall operator ^(const Variant& rhs) const;
    Variant __fastcall operator <<(const Variant& rhs) const;
    Variant __fastcall operator >>(const Variant& rhs) const;

    // binary operators (AnsiString on right)
    Variant __fastcall operator -(const AnsiString& rhs) const
      {return operator -(Variant(rhs));}
    Variant __fastcall operator *(const AnsiString& rhs) const
      {return operator *(Variant(rhs));}
    Variant __fastcall operator /(const AnsiString& rhs) const
      {return operator /(Variant(rhs));}
    Variant __fastcall operator %(const AnsiString& rhs) const
      {return operator %(Variant(rhs));}
    Variant __fastcall operator &(const AnsiString& rhs) const
      {return operator &(Variant(rhs));}
    Variant __fastcall operator |(const AnsiString& rhs) const
      {return operator |(Variant(rhs));}
    Variant __fastcall operator ^(const AnsiString& rhs) const
      {return operator ^(Variant(rhs));}
    Variant __fastcall operator <<(const AnsiString& rhs) const
      {return operator <<(Variant(rhs));}
    Variant __fastcall operator >>(const AnsiString& rhs) const
      {return operator >>(Variant(rhs));}

    // binary operators (int on right)
    Variant __fastcall operator +(int rhs) const
      {return operator +(Variant(rhs));}
    Variant __fastcall operator -(int rhs) const
      {return operator -(Variant(rhs));}
    Variant __fastcall operator *(int rhs) const
      {return operator *(Variant(rhs));}
    Variant __fastcall operator /(int rhs) const
      {return operator /(Variant(rhs));}
    Variant __fastcall operator %(int rhs) const
      {return operator %(Variant(rhs));}
    Variant __fastcall operator &(int rhs) const
      {return operator &(Variant(rhs));}
    Variant __fastcall operator |(int rhs) const
      {return operator |(Variant(rhs));}
    Variant __fastcall operator ^(int rhs) const
      {return operator ^(Variant(rhs));}
    Variant __fastcall operator <<(int rhs) const
      {return operator <<(Variant(rhs));}
    Variant __fastcall operator >>(int rhs) const
      {return operator >>(Variant(rhs));}

    // binary operators (double on right)
    Variant __fastcall operator +(double rhs) const
      {return operator +(Variant(rhs));}
    Variant __fastcall operator -(double rhs) const
      {return operator -(Variant(rhs));}
    Variant __fastcall operator *(double rhs) const
      {return operator *(Variant(rhs));}
    Variant __fastcall operator /(double rhs) const
      {return operator /(Variant(rhs));}
    Variant __fastcall operator %(double rhs) const
      {return operator %(Variant(rhs));}
    Variant __fastcall operator &(double rhs) const
      {return operator &(Variant(rhs));}
    Variant __fastcall operator |(double rhs) const
      {return operator |(Variant(rhs));}
    Variant __fastcall operator ^(double rhs) const
      {return operator ^(Variant(rhs));}
    Variant __fastcall operator <<(double rhs) const
      {return operator <<(Variant(rhs));}
    Variant __fastcall operator >>(double rhs) const
      {return operator >>(Variant(rhs));}

    // unary operators
    Variant __fastcall operator -() const;
    Variant __fastcall operator !() const;

    // conversion operators
    __fastcall operator short() const;
    __fastcall operator int() const;
    __fastcall operator float() const;
    __fastcall operator double() const;
    __fastcall operator Currency() const;
    __fastcall operator TDateTime() const;
    __fastcall operator bool() const;
    __fastcall operator WordBool() const;
    __fastcall operator Byte() const;
    __fastcall operator AnsiString() const;
    __fastcall operator Ole2::IDispatch*();
    __fastcall operator Ole2::IUnknown*();

    // by ref conversion operators
    __fastcall operator short*();
    __fastcall operator int*();
    __fastcall operator float*();
    __fastcall operator double*();
    __fastcall operator Currency*();
    __fastcall operator TDateTime*();
    __fastcall operator WordBool*();
    __fastcall operator Byte*();
    __fastcall operator wchar_t**();

    // HRESULT methods
    void __fastcall SetError(const Integer err);
    Integer __fastcall GetError() const;

    void __fastcall Clear();
    Variant& __fastcall ChangeType(int VarType);
    Variant __fastcall AsType(int VarType) const;

    int __fastcall Type() const;
    bool __fastcall IsNull() const;
    bool __fastcall IsEmpty() const;

    // variant array stuff
    bool    __fastcall IsArray() const;
    Variant __fastcall GetElement(const int i1) const;
    Variant __fastcall GetElement(const int i1, const int i2) const;
    Variant __fastcall GetElement(const int i1, const int i2, const int i3)
      const;
    Variant __fastcall GetElement(const int i1, const int i2, const int i3,
      const int i4) const;
    Variant __fastcall GetElement(const int i1, const int i2, const int i3,
      const int i4, const int i5) const;
    void __fastcall PutElement(const Variant& data, const int i1);
    void __fastcall PutElement(const Variant& data, const int i1, const int i2);
    void __fastcall PutElement(const Variant& data, const int i1, const int i2,
      const int i3);
    void __fastcall PutElement(const Variant& data, const int i1, const int i2,
      const int i3, const int i4);
    void __fastcall PutElement(const Variant& data, const int i1, const int i2,
      const int i3, const int i4, const int i5);
    int __fastcall ArrayDimCount() const;
    int __fastcall ArrayLowBound(const int dim = 1) const;
    int __fastcall ArrayHighBound(const int dim = 1) const;
    void __fastcall ArrayRedim(int highBound);
    Pointer __fastcall ArrayLock();
    void    __fastcall ArrayUnlock();

    // Automation Goodies
    Variant __fastcall Exec(AutoCmd& cmd, Integer lcid = LOCALE_SYSTEM_DEFAULT);

    // Alternate Syntax for Automation
    // (Doesn't support Named Parameters for now)
    void OleProcedure(const String& name, Variant& v0 = Variant(),
      Variant& v1 = Variant(),Variant& v2 = Variant(),Variant& v3 = Variant(),
      Variant& v4 = Variant(),Variant& v5 = Variant(),Variant& v6 = Variant(),
      Variant& v7 = Variant(),Variant& v8 = Variant(),Variant& v9 = Variant());
    Variant OleFunction(const String& name, Variant& v0 = Variant(),
      Variant& v1 = Variant(),Variant& v2 = Variant(),Variant& v3 = Variant(),
      Variant& v4 = Variant(),Variant& v5 = Variant(),Variant& v6 = Variant(),
      Variant& v7 = Variant(),Variant& v8 = Variant(),Variant& v9 = Variant());
    Variant OlePropertyGet(const String& name, Variant& v0 = Variant(),
      Variant& v1 = Variant(),Variant& v2 = Variant(),Variant& v3 = Variant(),
      Variant& v4 = Variant(),Variant& v5 = Variant(),Variant& v6 = Variant(),
      Variant& v7 = Variant(),Variant& v8 = Variant(),Variant& v9 = Variant());
    void OlePropertySet(const String& name, Variant& v0 = Variant(),
      Variant& v1 = Variant(),Variant& v2 = Variant(),Variant& v3 = Variant(),
      Variant& v4 = Variant(),Variant& v5 = Variant(),Variant& v6 = Variant(),
      Variant& v7 = Variant(),Variant& v8 = Variant(),Variant& v9 = Variant());
    // End of Alternate Syntax for Automation
  private:
    // AutoCmd::GetParm & GetNamedParm uses operator [] (AutoCmd is a friend)
    // operator[] can only be used for arrays of type Variant
    Variant& __fastcall operator [](const int idx);
};

#ifdef NOW_UNDEF_LOCALE_SYSTEM_DEFAULT
#undef LOCALE_SYSTEM_DEFAULT
#endif
//-----------------------------------------------------------------------
//ostream& operator <<(ostream& os, const Variant& arg);
//-----------------------------------------------------------------------
// Variant global scope comparisons (int on left)
inline bool __fastcall operator ==(int lhs, const Variant& rhs)
  {return Variant(lhs).operator ==(rhs);}
inline bool __fastcall operator !=(int lhs, const Variant& rhs)
  {return Variant(lhs).operator !=(rhs);}
inline bool __fastcall operator < (int lhs, const Variant& rhs)
  {return Variant(lhs).operator < (rhs);}
inline bool __fastcall operator > (int lhs, const Variant& rhs)
  {return Variant(lhs).operator > (rhs);}
inline bool __fastcall operator <=(int lhs, const Variant& rhs)
  {return Variant(lhs).operator <=(rhs);}
inline bool __fastcall operator >=(int lhs, const Variant& rhs)
  {return Variant(lhs).operator >=(rhs);}

// Variant global scope comparisons (double on left)
inline bool __fastcall operator ==(double lhs, const Variant& rhs)
  {return Variant(lhs).operator ==(rhs);}
inline bool __fastcall operator !=(double lhs, const Variant& rhs)
  {return Variant(lhs).operator !=(rhs);}
inline bool __fastcall operator < (double lhs, const Variant& rhs)
  {return Variant(lhs).operator < (rhs);}
inline bool __fastcall operator > (double lhs, const Variant& rhs)
  {return Variant(lhs).operator > (rhs);}
inline bool __fastcall operator <=(double lhs, const Variant& rhs)
  {return Variant(lhs).operator <=(rhs);}
inline bool __fastcall operator >=(double lhs, const Variant& rhs)
  {return Variant(lhs).operator >=(rhs);}

// Variant binary global scope operators (AnsiString on left)
inline Variant __fastcall operator - (const AnsiString& lhs, const Variant& rhs)
  {return Variant(lhs).operator -(rhs);}
inline Variant __fastcall operator * (const AnsiString& lhs, const Variant& rhs)
  {return Variant(lhs).operator *(rhs);}
inline Variant __fastcall operator / (const AnsiString& lhs, const Variant& rhs)
  {return Variant(lhs).operator /(rhs);}
inline Variant __fastcall operator % (const AnsiString& lhs, const Variant& rhs)
  {return Variant(lhs).operator %(rhs);}
inline Variant __fastcall operator & (const AnsiString& lhs, const Variant& rhs)
  {return Variant(lhs).operator &(rhs);}
inline Variant __fastcall operator | (const AnsiString& lhs, const Variant& rhs)
  {return Variant(lhs).operator |(rhs);}
inline Variant __fastcall operator ^ (const AnsiString& lhs, const Variant& rhs)
  {return Variant(lhs).operator ^(rhs);}
inline Variant __fastcall operator <<(const AnsiString& lhs, const Variant& rhs)
  {return Variant(lhs).operator <<(rhs);}
inline Variant __fastcall operator >>(const AnsiString& lhs, const Variant& rhs)
  {return Variant(lhs).operator >>(rhs);}

// Variant binary global scope operators (int on left)
inline Variant __fastcall operator +(int lhs, const Variant& rhs)
  {return Variant(lhs).operator +(rhs);}
inline Variant __fastcall operator -(int lhs, const Variant& rhs)
  {return Variant(lhs).operator -(rhs);}
inline Variant __fastcall operator *(int lhs, const Variant& rhs)
  {return Variant(lhs).operator *(rhs);}
inline Variant __fastcall operator /(int lhs, const Variant& rhs)
  {return Variant(lhs).operator /(rhs);}
inline Variant __fastcall operator %(int lhs, const Variant& rhs)
  {return Variant(lhs).operator %(rhs);}
inline Variant __fastcall operator &(int lhs, const Variant& rhs)
  {return Variant(lhs).operator &(rhs);}
inline Variant __fastcall operator |(int lhs, const Variant& rhs)
  {return Variant(lhs).operator |(rhs);}
inline Variant __fastcall operator ^(int lhs, const Variant& rhs)
  {return Variant(lhs).operator ^(rhs);}
inline Variant __fastcall operator <<(int lhs, const Variant& rhs)
  {return Variant(lhs).operator <<(rhs);}
inline Variant __fastcall operator >>(int lhs, const Variant& rhs)
  {return Variant(lhs).operator >>(rhs);}

// Variant binary global scope operators (double on left)
inline Variant __fastcall operator +(double lhs, const Variant& rhs)
  {return Variant(lhs).operator +(rhs);}
inline Variant __fastcall operator -(double lhs, const Variant& rhs)
  {return Variant(lhs).operator -(rhs);}
inline Variant __fastcall operator *(double lhs, const Variant& rhs)
  {return Variant(lhs).operator *(rhs);}
inline Variant __fastcall operator /(double lhs, const Variant& rhs)
  {return Variant(lhs).operator /(rhs);}
inline Variant __fastcall operator %(double lhs, const Variant& rhs)
  {return Variant(lhs).operator %(rhs);}
inline Variant __fastcall operator &(double lhs, const Variant& rhs)
  {return Variant(lhs).operator &(rhs);}
inline Variant __fastcall operator |(double lhs, const Variant& rhs)
  {return Variant(lhs).operator |(rhs);}
inline Variant __fastcall operator ^(double lhs, const Variant& rhs)
  {return Variant(lhs).operator ^(rhs);}
inline Variant __fastcall operator <<(double lhs, const Variant& rhs)
  {return Variant(lhs).operator <<(rhs);}
inline Variant __fastcall operator >>(double lhs, const Variant& rhs)
  {return Variant(lhs).operator >>(rhs);}

//-----------------------------------------------------------------------
//forward declare NamedParm - used by AutoArg's operator << function
class NamedParm;
//-----------------------------------------------------------------------
class AutoCmd
{
  public:
    AutoCmd(const String& name): Name(name) {}
    AutoCmd(const AutoCmd& src);
    virtual AutoCmd& SetName(const String& name);

    //Named arg
    virtual AutoCmd& operator <<(const NamedParm& np);
    //By value args
    virtual AutoCmd& operator <<(const Variant& arg);
    virtual AutoCmd& operator <<(const short arg);
    virtual AutoCmd& operator <<(const int arg);
    virtual AutoCmd& operator <<(const float arg);
    virtual AutoCmd& operator <<(const double arg);
    virtual AutoCmd& operator <<(const Currency arg);
    virtual AutoCmd& operator <<(const TDateTime arg);
    virtual AutoCmd& operator <<(const bool arg);
    virtual AutoCmd& operator <<(const WordBool arg);
    virtual AutoCmd& operator <<(const Byte arg);
    virtual AutoCmd& operator <<(const AnsiString& arg);
    virtual AutoCmd& operator <<(const char* arg) // treat as asciiz pointer
      {return operator <<(AnsiString(arg));}
    //!JK not allowed    virtual AutoCmd& operator <<(wchar_t* const arg);
    virtual AutoCmd& operator <<(Ole2::IDispatch* const arg);
    virtual AutoCmd& operator <<(Ole2::IUnknown* const arg);
    //By ref args
    virtual AutoCmd& operator <<(Variant* arg);
    virtual AutoCmd& operator <<(short* arg);
    virtual AutoCmd& operator <<(int* arg);
    virtual AutoCmd& operator <<(float* arg);
    virtual AutoCmd& operator <<(double* arg);
    virtual AutoCmd& operator <<(Currency* arg);
    virtual AutoCmd& operator <<(TDateTime* arg);
    virtual AutoCmd& operator <<(WordBool* arg);
    virtual AutoCmd& operator <<(Byte* arg);
    //!JK not allowed    virtual AutoCmd& operator <<(wchar_t** arg);
    virtual AutoCmd& operator <<(AnsiString* arg);

    virtual AutoCmd& Clear();       // ClearName() + ClearArgs()
    virtual AutoCmd& ClearName();   // SetName("")
    virtual AutoCmd& ClearArgs();   // Clear Parms and NamedParms

    virtual Byte GetCallType() const = 0;
    virtual bool RequestResult() const = 0;
    virtual int GetArgType(const Byte idx) const;
    virtual int GetNamedArgType(const Byte idx) const;
    virtual String GetName() const { return Name; }
    virtual Byte GetArgCount() const;
    virtual Byte GetNamedArgCount() const;
    virtual Variant& GetParm(const Byte idx);
    virtual Variant& GetNamedParm(const Byte idx);
    virtual String GetNamedParmName(const Byte idx) const;
    virtual String GetStringArg(const Byte idx) {return StringArgs[idx];}
    virtual String* GetStringPtr(const Byte idx) {return StringPtrs[idx];}
    virtual String GetNamedStringArg(const Byte idx) {return NamedStringArgs[idx];}
    virtual String* GetNamedStringPtr(const Byte idx) {return NamedStringPtrs[idx];}

  protected:
    void AddElement();
    String Name;            // name of command
    Variant Parms;          // positional arguments
    Variant ParmTypes;      // types of positional arguments
    Variant NamedParms;     // named arguments
    Variant NamedParmTypes; // types of named arguments
    Variant NamedParmNames; // names of named arguments
    AnsiString StringArgs[32];       // MaxDispArgs = 32 in oleauto.hpp
    AnsiString* StringPtrs[32];      // MaxDispArgs = 32 in oleauto.hpp
    AnsiString NamedStringArgs[32];  // MaxDispArgs = 32 in oleauto.hpp
    AnsiString* NamedStringPtrs[32]; // MaxDispArgs = 32 in oleauto.hpp
};
//-----------------------------------------------------------------------
class NamedParm
{
  public:
//    NamedParm(const String& name, Variant& parm): Name(name), Parm(parm) {}
    //By value ctors
    NamedParm(const String& name, const Variant& arg):
      Name(name), Type(varVariant), Parm(arg) {}
    NamedParm(const String& name, const short arg):
      Name(name), Type(varSmallint), Parm(arg) {}
    NamedParm(const String& name, const int arg):
      Name(name), Type(varInteger), Parm(arg) {}
    NamedParm(const String& name, const float arg):
      Name(name), Type(varSingle), Parm(arg) {}
    NamedParm(const String& name, const double arg):
      Name(name), Type(varDouble), Parm(arg) {}
    NamedParm(const String& name, const Currency arg):
      Name(name), Type(varCurrency), Parm(arg) {}
    NamedParm(const String& name, const TDateTime arg):
      Name(name), Type(varDate), Parm(arg) {}
    NamedParm(const String& name, const bool arg):
      Name(name), Type(varBoolean), Parm(arg) {}
    NamedParm(const String& name, const WordBool arg):
      Name(name), Type(varBoolean), Parm(arg) {}
    NamedParm(const String& name, const Byte arg):
      Name(name), Type(varByte), Parm(arg) {}
    NamedParm(const String& name, const AnsiString& arg):
      Name(name), Type(varString), StringParm(arg) {}
    NamedParm(const String& name, const char* arg): // treat as asciiz pointer
      Name(name), Type(varString), StringParm(arg) {}
    //!JK not allowed NamedParm(const String& name, wchar_t* const arg):
    //!JK not allowed   Name(name), Type(varOleStr), Parm(arg) {}
    NamedParm(const String& name, Ole2::IDispatch* const arg):
      Name(name), Type(varDispatch), Parm(arg) {}
    NamedParm(const String& name, Ole2::IUnknown* const arg):
      Name(name), Type(varUnknown), Parm(arg) {}
    //By ref ctors
    NamedParm(const String& name, Variant* arg);
    NamedParm(const String& name, short* arg):
      Name(name), Type(varSmallint | varByRef), Parm(arg) {}
    NamedParm(const String& name, int* arg):
      Name(name), Type(varInteger | varByRef), Parm(arg) {}
    NamedParm(const String& name, float* arg):
      Name(name), Type(varSingle | varByRef), Parm(arg) {}
    NamedParm(const String& name, double* arg):
      Name(name), Type(varDouble | varByRef), Parm(arg) {}
    NamedParm(const String& name, Currency* arg):
      Name(name), Type(varCurrency | varByRef), Parm(arg) {}
    NamedParm(const String& name, TDateTime* arg):
      Name(name), Type(varDate | varByRef), Parm(arg) {}
    NamedParm(const String& name, WordBool* arg):
      Name(name), Type(varBoolean | varByRef), Parm(arg) {}
    NamedParm(const String& name, Byte* arg):
      Name(name), Type(varByte | varByRef), Parm(arg) {}
    //!JK not allowed NamedParm(const String& name, wchar_t** arg):
    //!JK not allowed   Name(name), Type(varOleStr | varByRef), Parm(arg) {}
    NamedParm(const String& name, String* arg):
      Name(name), Type(varString | varByRef), StringPtr(arg) {}

    virtual Variant GetParm() const { return Parm; }
    virtual AnsiString GetStringParm() const { return StringParm; }
    virtual AnsiString* GetStringPtr() const { return StringPtr; }
    virtual int GetType() const { return Type; }
    virtual String GetParmName() const { return Name; }
  protected:
    void AddElement();
    String Name;
    Variant Parm;
    AnsiString StringParm;
    AnsiString* StringPtr;
    int Type;
};
//-----------------------------------------------------------------------
class Procedure: public AutoCmd
{
  public:
    Procedure(const String& name): AutoCmd(name) {}
    Procedure(const AutoCmd& src): AutoCmd(src) {dynamic_cast<const Procedure*>(&src);}
    virtual Byte GetCallType() const;
    virtual bool RequestResult() const { return false; }
};
//-----------------------------------------------------------------------
class Function: public AutoCmd
{
  public:
    Function(const String& name): AutoCmd(name) {}
    Function(const AutoCmd& src): AutoCmd(src) {dynamic_cast<const Function*>(&src);}
    virtual Byte GetCallType() const;
    virtual bool RequestResult() const { return true; }
};
//-----------------------------------------------------------------------
class PropertySet: public AutoCmd
{
  public:
    PropertySet(const String& name): AutoCmd(name) {}
    PropertySet(const AutoCmd& src): AutoCmd(src) {dynamic_cast<const PropertySet*>(&src);}
    virtual Byte GetCallType() const;
    virtual bool RequestResult() const { return false; }
};
//-----------------------------------------------------------------------
class PropertyGet: public AutoCmd
{
  public:
    PropertyGet(const String& name): AutoCmd(name) {}
    PropertyGet(const AutoCmd& src): AutoCmd(src) {dynamic_cast<const PropertyGet*>(&src);}
    virtual Byte GetCallType() const;
    virtual bool RequestResult() const { return true; }
};
//-----------------------------------------------------------------------
typedef class TMemoryManager *PMemoryManager;

class TMemoryManager {
  public:
        Pointer __fastcall (*GetMem)(Integer Size);
        Integer __fastcall (*FreeMem)(Pointer P);
        Pointer __fastcall (*ReallocMem)(Pointer P, Integer Size);
} ;

class THeapStatus {
  public:
    Cardinal TotalAddrSpace;
    Cardinal TotalUncommitted;
    Cardinal TotalCommitted;
    Cardinal TotalAllocated;
    Cardinal TotalFree;
    Cardinal FreeSmall;
    Cardinal FreeBig;
    Cardinal Unused;
    Cardinal Overhead;
    Cardinal HeapErrorCode;
} ;

typedef Integer __fastcall (*TThreadFunc)(Pointer Parameter);

#if 0
//---------------------------------------------------------------------------
typedef void* HINSTANCE;
#if (_MSC_VER >= 800) || defined(_STDCALL_SUPPORTED) || defined(__BORLANDC__)
#define CALLBACK    __stdcall
#define WINAPI      __stdcall
#define WINAPIV     __cdecl
#define APIENTRY    WINAPI
#define APIPRIVATE  __stdcall
#define PASCAL      __stdcall
#else
#define CALLBACK
#define WINAPI
#define WINAPIV
#define APIENTRY    WINAPI
#define APIPRIVATE
#define PASCAL      pascal
#endif
#endif

//---------------------------------------------------------------------
#define USEDATAMODULE(FileName, DataModuleName)  \
   class __declspec(delphiclass) T##DataModuleName;       \
   extern T##DataModuleName *DataModuleName;
//---------------------------------------------------------------------
#define USEDATAMODULENS(FileName, UnitName, DataModuleName)  \
   namespace UnitName {         \
   class __declspec(delphiclass) T##DataModuleName;       \
   extern T##DataModuleName *DataModuleName;              \
   };               \
   using namespace UnitName
//---------------------------------------------------------------------
#define USEFORM(FileName, FormName) \
   class __declspec(delphiclass) T##FormName;       \
   extern T##FormName *FormName;
//---------------------------------------------------------------------
#define USEFORMNS(FileName, UnitName, FormName) \
   namespace UnitName {         \
   class __declspec(delphiclass) T##FormName;       \
   extern T##FormName *FormName;          \
   };               \
   using namespace UnitName
//---------------------------------------------------------------------
#define USEUNIT(ModName) \
   extern DummyThatIsNeverReferenced
//---------------------------------------------------------------------------
#define USEOBJ(FileName) \
   extern DummyThatIsNeverReferenced
//-----------------------------------------------------------------------
#define USERC(FileName) \
   extern DummyThatIsNeverReferenced
//-----------------------------------------------------------------------
#define USERES(FileName) \
   extern DummyThatIsNeverReferenced
//-----------------------------------------------------------------------
#define USELIB(FileName) \
   extern DummyThatIsNeverReferenced
//-----------------------------------------------------------------------
#define USEFILE(FileName) \
   extern DummyThatIsNeverReferenced
//-----------------------------------------------------------------------

#if defined(BCB_NAMESPACES)
}
using namespace System;
using System::TClass;

namespace Typinfo {
  struct  TTypeInfo;
  typedef TTypeInfo *PTypeInfo;
}

#if !defined(__typeinfo)
# define __typeinfo(type)  (PTypeInfo)TObject::ClassInfo(__classid(type))
#endif

#endif  //  BCB_NAMESPACES
#endif  //  SYSDEFS_H

