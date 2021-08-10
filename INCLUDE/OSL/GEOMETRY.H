//----------------------------------------------------------------------------
// ObjectSupport
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Classes for geometric encapsulation
//----------------------------------------------------------------------------
#if !defined(OSL_GEOMETRY_H)
#define OSL_GEOMETRY_H

#if !defined(OSL_DEFS_H)
# include <osl/defs.h>
#endif
#if !defined(OSL_INLINES_H)
# include <osl/inlines.h>
#endif

#if !defined(CLASSLIB_OBJSTRM_H)  //!CQ move this to osl/streaming
# include <classlib/objstrm.h>
#endif

class TSize;
class _BIDSCLASS TRect;

//
// Geometry C-structs compatible with MSW
//
#if !defined(BI_PLAT_MSW)
struct tagPOINT {
  int x;
  int y;
};
typedef struct tagPOINT POINT;

struct tagSIZE {
  int cx;
  int cy;
};
typedef struct tagSIZE SIZE;

struct tagRECT {
  int left;
  int top;
  int right;
  int bottom;
};
typedef struct tagRECT RECT;
#endif

//
// class TPoint
// ----- ------
//
class  TPoint : public tagPOINT {
  public:
    // Constructors
    TPoint() {}
    TPoint(int _x, int _y) {x = _x; y = _y;}
    TPoint(const POINT far& point) {x = point.x; y = point.y;}
    TPoint(const TPoint far& point) {x = point.x; y = point.y;}
    TPoint(const SIZE far& size) {x = size.cx; y = size.cy;}
    TPoint(uint32 dw) {x = int16(LOWORD(dw)); y = int16(HIWORD(dw));}

    // Information functions/operators
    bool        operator ==(const TPoint& other) const;
    bool        operator !=(const TPoint& other) const;

    // Functions/binary-operators that return points or sizes
    TPoint      OffsetBy(int dx, int dy) const {return TPoint(x+dx, y+dy);}
    TPoint      operator +(const TSize& size) const;
    TSize       operator -(const TPoint& point) const;
    TPoint      operator -(const TSize& size) const;
    TPoint      operator -() const {return TPoint(-x, -y);}

    // Functions/assignement-operators that modify this point
    TPoint&     Offset(int dx, int dy);
    TPoint&     operator +=(const TSize& size);
    TPoint&     operator -=(const TSize& size);
};
inline ipstream& operator >>(ipstream& is, TPoint& p)
  { return is >> p.x >> p.y; }
inline opstream& operator <<(opstream& os, const TPoint& p)
  { return os << p.x << p.y; }
inline ostream& operator <<(ostream& os, const TPoint& p)
  { return os << '(' << p.x << ',' << p.y << ')'; }
inline istream& operator >>(istream& is, TPoint& p)
  { char c; return is >> c >> p.x >> c >> p.y >> c; }

//
// class TSize
// ----- -----
//
class  TSize : public tagSIZE {
  public:
    // Constructors
    TSize() {}
    TSize(int dx, int dy) {cx = dx; cy = dy;}
    TSize(const POINT far& point) {cx = point.x; cy = point.y;}
    TSize(const SIZE far& size) {cx = size.cx; cy = size.cy;}
    TSize(const TSize far& size) {cx = size.cx; cy = size.cy;}
    TSize(uint32 dw) {cx = LOWORD(dw); cy = HIWORD(dw);}

    // Information functions/operators
    bool        operator ==(const TSize& other) const;
    bool        operator !=(const TSize& other) const;
    int         Magnitude() const;

    // Functions/binary-operators that return sizes
    TSize      operator +(const TSize& size) const;
    TSize      operator -(const TSize& size) const;
    TSize      operator -() const {return TSize(-cx, -cy);}

    // Functions/assignement-operators that modify this size
    TSize&     operator +=(const TSize& size);
    TSize&     operator -=(const TSize& size);
};
inline ipstream& operator >>(ipstream& is, TSize& s)
  { return is >> s.cx >> s.cy; }
inline opstream& operator <<(opstream& os, const TSize& s)
  { return os << s.cx << s.cy; }
inline ostream& operator <<(ostream& os, const TSize& s)
  { return os << '(' << s.cx << 'x' << s.cy << ')'; }

//
// class TRect
// ----- -----
//
class _BIDSCLASS TRect : public tagRECT {
  public:
    // Constructors
    TRect() {}
    TRect(const RECT far& rect);
    TRect(const TRect far& rect);
    TRect(int _left, int _top, int _right, int _bottom);
    TRect(const TPoint& upLeft, const TPoint& loRight);
    TRect(const TPoint& origin, const TSize& extent);

    // (re)Initializers
    void        SetNull();
    void        SetEmpty() {SetNull();}
    void        Set(int _left, int _top, int _right, int _bottom);

    // Type Conversion operators
    operator    const TPoint*() const {return (const TPoint*)this;}
    operator    TPoint*() {return (TPoint*)this;}

    // Testing functions
    bool        IsEmpty() const;
    bool        IsNull() const;
    bool        operator ==(const TRect& other) const;
    bool        operator !=(const TRect& other) const;

    // Information/access functions(const and non-const)
    const TPoint& TopLeft() const {return *(TPoint*)&left;}
    TPoint&     TopLeft() {return *(TPoint*)&left;}
    TPoint      TopRight() const {return TPoint(right, top);}
    TPoint      BottomLeft() const {return TPoint(left, bottom);}
    const TPoint& BottomRight() const {return *(TPoint*)&right;}
    TPoint&     BottomRight() {return *(TPoint*)&right;}
    int         Width() const {return right-left;}
    int         Height() const {return bottom-top;}
    TSize       Size() const {return TSize(Width(), Height());}
    long        Area() const {return long(Width())*long(Height());}

    bool        Contains(const TPoint& point) const;
    bool        Contains(const TRect& other) const;
    bool        Touches(const TRect& other) const;
    TRect       OffsetBy(int dx, int dy) const;
    TRect       operator +(const TSize& size) const;
    TRect       operator -(const TSize& size) const;
    TRect       InflatedBy(int dx, int dy) const;
    TRect       InflatedBy(const TSize& size) const;
    TRect       Normalized() const;
    TRect       operator &(const TRect& other) const;
    TRect       operator |(const TRect& other) const;

    // Manipulation functions/operators
    TRect&      Normalize();
    TRect&      Offset(int dx, int dy);
    TRect&      operator +=(const TSize& delta);
    TRect&      operator -=(const TSize& delta);
    TRect&      Inflate(int dx, int dy);
    TRect&      Inflate(const TSize& delta);
    TRect&      operator &=(const TRect& other);
    TRect&      operator |=(const TRect& other);

};
ipstream& _BIDSFUNC operator >>(ipstream& is, TRect& r);
opstream& _BIDSFUNC operator <<(opstream& os, const TRect& r);
ostream& _BIDSFUNC operator <<(ostream& os, const TRect& r);

//
// class TResId
// ----- ------
//
// Resource Id class that can be constructed from a integer or string resource
// identifier.
//
class TResId {
  public:
    TResId() : Id(0) {}
    TResId(const char far* resString) : Id(resString) {}
    TResId(int resNum) : Id((const char far*)uint32(unsigned(resNum))) {}
    operator char far*() {return (char far*)Id;}
    bool IsString() const {return ToBool(HIWORD(Id));}

  private:
    const char far*  Id;

  friend ipstream& _BIDSFUNC operator >>(ipstream& is, TResId& id);
  friend opstream& _BIDSFUNC operator <<(opstream& os, const TResId& id);
  friend ostream& _BIDSFUNC  operator <<(ostream& os, const TResId& id);
};

#if defined(BI_PLAT_MSW)

//
// class TDropInfo
// ----- ---------
//
class TDropInfo {
  public:
    TDropInfo(HDROP handle) : Handle(handle) {}

    operator HDROP() {return Handle;}

    uint DragQueryFile(uint index, char far* name, uint nameLen)
           {return ::DragQueryFile(Handle, index, name, nameLen);}
    uint DragQueryFileCount() {return ::DragQueryFile(Handle, -1, 0, 0);}
    uint DragQueryFileNameLen(uint index)
           {return ::DragQueryFile(Handle, index, 0, 0);}
    bool DragQueryPoint(TPoint& point)
           {return ::DragQueryPoint(Handle, &point);}
    void DragFinish() {::DragFinish(Handle);}

  private:
    HDROP  Handle;
};

//
// class TProcInstance
// ----- -------------
//
class TProcInstance {
  public:
    #if defined(BI_PLAT_WIN16)
      TProcInstance(FARPROC p) {Instance = ::MakeProcInstance(p, _hInstance);}
     ~TProcInstance() {::FreeProcInstance(Instance);}
    #else
      TProcInstance(FARPROC p) {Instance = FARPROC(p);}
    #endif
   
    operator FARPROC() {return Instance;}

  private:
    FARPROC Instance;
};
#endif  // BI_PLAT_MSW

//
// class TPointer
// ----- --------
//
template<class T> class TPointerBase {
  public:
    T&   operator  *() {return *P;}
         operator T*() {return P;}
         operator T&() {return *P;}
    int  operator  !() {return P==0;}
    void operator  ~() {P = 0;}

  protected:
    TPointerBase(T* pointer) : P(pointer) {}
   ~TPointerBase() {delete P;}
    TPointerBase() : P(0){}
    T* P;

  private:
    void* operator new(size_t) {return 0;}  // prohibit use of new
    void operator delete(void* p) {((TPointerBase<T>*)p)->P=0;}
};

template<class T> class TPointer : public TPointerBase<T> {
  public:
    TPointer() : TPointerBase<T>(){}
    TPointer(T* pointer) : TPointerBase<T>(pointer) {}
    T* operator =(T* src) {delete P; return P = src;}
    T* operator =(const TPointer<T>& src)
                          {delete P; return P = src.P;}
    T* operator->() {return P;} // should throw exception if P==0
};

class TPointer<char> : public TPointerBase<char> {
  public:
    TPointer() : TPointerBase<char>(){}
    TPointer(char* pointer) : TPointerBase<char>(pointer) {}
    char* operator =(char* src) {delete P; return P = src;}
    char* operator =(const TPointer<char>& src)
                                {delete P; return P = src.P;}
    char& operator[](int i) {return P[i];}
};

//
// class TCmdLine
// ----- --------
// Command line argument processing class, processes in the form:
//  <Name> | {-/}<Option>[{:=}<Value>] ...
//
class _BIDSCLASS TCmdLine {
  public:
    enum TKind {
      Start,   // no tokens have been parsed yet
      Name,    // name type token, has no leading / or -
      Option,  // option type token. leading / or - skipped by Token
      Value,   // value for name or option. leading : or = skipped by Token
      Done     // no more tokens
    };
    TCmdLine(const char far* cmdLine);
   ~TCmdLine();

    TKind NextToken(bool removeCurrent=false);
    const char* GetLine() const {return Buffer;}
    void Reset();

    TKind Kind;       // Kind of current token
    char* Token;      // ptr to current token. (Not 0-terminated)
    int   TokenLen;   // length of current token

  private:
    char* Buffer;     // command line buffer
    char* TokenStart; // actual start of current token
};

//----------------------------------------------------------------------------
// Inlines
//----------------------------------------------------------------------------

inline bool TPoint::operator ==(const TPoint& other) const {
  return ToBool(other.x==x && other.y==y);
}

inline bool TPoint::operator !=(const TPoint& other) const {
  return ToBool(other.x!=x || other.y!=y);
}

inline TPoint TPoint::operator +(const TSize& size) const {
  return TPoint(x+size.cx, y+size.cy);
}

inline TSize TPoint::operator -(const TPoint& point) const {
  return TSize(x-point.x, y-point.y);
}

inline TPoint TPoint::operator -(const TSize& size) const {
  return TPoint(x-size.cx, y-size.cy);
}

inline TPoint& TPoint::Offset(int dx, int dy) {
  x += dx;
  y += dy;
  return *this;
}

inline TPoint& TPoint::operator +=(const TSize& size) {
  x += size.cx;
  y += size.cy;
  return *this;
}

inline TPoint& TPoint::operator -=(const TSize& size) {
  x -= size.cx;
  y -= size.cy;
  return *this;
}


inline bool TSize::operator ==(const TSize& other) const {
  return ToBool(other.cx==cx && other.cy==cy);
}

inline bool TSize::operator !=(const TSize& other) const {
  return ToBool(other.cx!=cx || other.cy!=cy);
}

inline int TSize::Magnitude() const {
  return Sqrt(long(cx)*long(cx)+long(cy)*long(cy));
}

inline TSize TSize::operator +(const TSize& size) const {
  return TSize(cx+size.cx, cy+size.cy);
}

inline TSize TSize::operator -(const TSize& size) const {
  return TSize(cx-size.cx, cy-size.cy);
}

inline TSize& TSize::operator +=(const TSize& size) {
  cx += size.cx;
  cy += size.cy;
  return *this;
}

inline TSize& TSize::operator -=(const TSize& size) {
  cx -= size.cx;
  cy -= size.cy;
  return *this;
}


inline void TRect::SetNull() {
  left = top = right = bottom = 0;
}

inline void TRect::Set(int _left, int _top, int _right, int _bottom) {
  left = _left;
  top = _top;
  right = _right;
  bottom = _bottom;
}

inline TRect::TRect(const RECT far& rect) {
  *(RECT far*)this = rect;
}

inline TRect::TRect(const TRect far& rect) {
  *(RECT far*)this = *(RECT far*)&rect;
}

inline TRect::TRect(int _left, int _top, int _right, int _bottom) {
  Set(_left, _top, _right, _bottom);
}

inline TRect::TRect(const TPoint& topLeft, const TPoint& bottomRight) {
  Set(topLeft.x, topLeft.y, bottomRight.x, bottomRight.y);
}

inline TRect::TRect(const TPoint& origin, const TSize& extent) {
  Set(origin.x, origin.y, origin.x+extent.cx, origin.y+extent.cy);
}

inline bool TRect::IsEmpty() const {
  return ToBool(left>=right || top>=bottom);
}

inline bool TRect::IsNull() const {
  return ToBool(!left && !right && !top && !bottom);
}

inline bool TRect::operator ==(const TRect& other) const {
  return ToBool(other.left==left   && other.top==top
             && other.right==right && other.bottom==bottom);
}

inline bool TRect::operator !=(const TRect& other) const {
  return ToBool(!(other==*this));
}

inline bool TRect::Contains(const TPoint& point) const {
  return ToBool(point.x >= left && point.x < right
             && point.y >= top  && point.y < bottom);
}

inline bool TRect::Contains(const TRect& other) const {
  return ToBool(other.left >= left && other.right <= right
             && other.top >= top   && other.bottom <= bottom);
}

inline bool TRect::Touches(const TRect& other) const {
  return ToBool(other.right > left && other.left < right
             && other.bottom > top && other.top < bottom);
}

inline TRect TRect::OffsetBy(int dx, int dy) const {
  return TRect(left+dx, top+dy, right+dx, bottom+dy);
}

inline TRect TRect::operator +(const TSize& size) const {
  return OffsetBy(size.cx, size.cy);
}

inline TRect TRect::operator -(const TSize& size) const {
  return OffsetBy(-size.cx, -size.cy);
}

inline TRect TRect::InflatedBy(int dx, int dy) const {
  return TRect(left-dx, top-dy, right+dx, bottom+dy);
}

inline TRect TRect::InflatedBy(const TSize& size) const {
  return InflatedBy(size.cx, size.cy);
}

inline TRect TRect::Normalized() const {
  return TRect(Min(left, right), Min(top, bottom),
               Max(left, right), Max(top, bottom));
}

inline TRect TRect::operator &(const TRect& other) const {
  return TRect(Max(left, other.left), Max(top, other.top),
               Min(right, other.right), Min(bottom, other.bottom));
}

inline TRect TRect::operator |(const TRect& other) const {
  return TRect(Min(left, other.left), Min(top, other.top),
               Max(right, other.right), Max(bottom, other.bottom));
}

inline TRect& TRect::operator +=(const TSize& delta) {
  Offset(delta.cx, delta.cy);
  return *this;
}

inline TRect& TRect::operator -=(const TSize& delta) {
  return *this += -delta;
}

inline TRect& TRect::Inflate(const TSize& delta) {
  return Inflate(delta.cx, delta.cy);
}

#endif  // OSL_GEOMETRY_H
