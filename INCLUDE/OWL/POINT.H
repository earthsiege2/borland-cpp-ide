//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   include\owl\point.h
//   Definition of mathematical TPoint, TSize, TRect classes.
//   Also, other simple, inline windows classes: TDropInfo
//   Also, TPointer classes for exception safe pointer management
//----------------------------------------------------------------------------
#if !defined(__OWL_POINT_H)
#define __OWL_POINT_H

#if !defined(__OWL_OWLDEFS_H)
  #include <owl\owldefs.h>
#endif
#if !defined(__CLASSLIB_OBJSTRM_H)
  #include <classlib\objstrm.h>
#endif

//
// Misc support functions
//
inline void Swap(BYTE far& a, BYTE far& b) {a^=b; b^=a; a^=b;}
inline void Swap(int far& a, int far& b) {a^=b; b^=a; a^=b;}
inline void Swap(LONG far& a, LONG far& b) {a^=b; b^=a; a^=b;}
inline int Min(int a, int b) {return a<b ? a : b;}
inline int Max(int a, int b) {return a>b ? a : b;}
int    _OWLFUNC Sqrt(long val);

//
// Inline versions of common RTL functions, overloaded for far ptrs for use
// when in a small data model.
//
#if defined(__SMALL__) || defined(__MEDIUM__)
  inline void far* memccpy(void far* d, const void far* s, int c, size_t n)
                     {return _fmemccpy(d, s, c, n);}
  inline void far* memchr(const void far* s, int c, size_t n)
                     {return _fmemchr(s, c, n);}
  inline int       memcmp(const void far* s1, const void far* s2, size_t n)
                     {return _fmemcmp(s1, s2, n);}
  inline void far* memcpy(void far* d, const void far* s, size_t n)
                     {return _fmemcpy(d, s, n);}
  inline int       memicmp(const void far* s1, const void far* s2, size_t n)
                     {return _fmemicmp(s1, s2, n);}
  inline void far* memset(void far* s, int c, size_t n)
                     {return _fmemset(s, c, n);}
  inline void far* memmove(void far* d, const void far* s, size_t n)
                     {return _fmemmove(d, s, n);}

  inline char far* strcat(char far* d, const char far* s)
                     {return _fstrcat(d, s);}
  inline char far* strchr(const char far* s, int c) {return _fstrchr(s, c);}
  inline int       strcmp(const char far* s1, const char far* s2)
                     {return _fstrcmp(s1, s2);}
  inline char far* strcpy(char far* d, const char far* s)
                     {return _fstrcpy(d, s);}
  inline int       stricmp(const char far* s1, const char far* s2)
                     {return _fstricmp(s1, s2);}
  inline size_t    strlen(const char far* s) {return _fstrlen(s);}
  inline char far* strlwr(char far* s) {return _fstrlwr(s);}
  inline char far* strncat(char far* d, const char far* s, size_t maxlen)
                     {return _fstrncat(d, s, maxlen);}
  inline int       strncmp(const char far* s1, const char far* s2, size_t maxlen)
                     {return _fstrncmp(s1, s2, maxlen);}
  inline char far* strncpy(char far* d, const char far* s, size_t maxlen)
                     {return _fstrncpy(d, s, maxlen);}
  inline int       strnicmp(const char far* s1, const char far* s2, size_t maxlen)
                     {return _fstrnicmp(s1, s2, maxlen);}
  inline char far* strrchr(const char far* s, int c) {return _fstrrchr(s, c);}
  inline char far* strtok(char far* s1, const char far* s2)
                     {return _fstrtok(s1, s2);}
  inline char far* strupr(char far* s) {return _fstrupr(s);}
#endif

//
// type overloaded version of Window's huge mem copy (hmemcpy) for flat models
//
#if defined(__FLAT__)
  inline void      hmemcpy(void* d, const void* s, long n) {memcpy(d, s, n);}
#endif

//
// strnewdup() uses new char[], to allow duplicated strings to be deleted
//
char*  _OWLFUNC strnewdup(const char* s);
#if defined(__SMALL__) || defined(__MEDIUM__)
  char far*  _OWLFUNC strnewdup(const char far* s);
  long atol(const char far* s);
#endif


class TSize;
class _OWLCLASS TRect;

//
// class TPoint
// ----- ------
//
class  TPoint : public tagPOINT {
  public:
    // Constructors
    TPoint() {}
    TPoint(int _x, int _y) {x = _x; y = _y;}
    TPoint(const POINT& point) {x = point.x; y = point.y;}
    TPoint(const SIZE& size) {x = size.cx; y = size.cy;}
    TPoint(DWORD dw) {x = int16(LOWORD(dw)); y = int16(HIWORD(dw));}

    // Information functions/operators
    BOOL        operator ==(const TPoint& other) const;
    BOOL        operator !=(const TPoint& other) const;

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

    friend inline ipstream& operator >>(ipstream& is, TPoint& p)
      { return is >> p.x >> p.y; }
    friend inline opstream& operator <<(opstream& os, const TPoint& p)
      { return os << p.x << p.y; }
    friend inline ostream& operator <<(ostream& os, const TPoint& p)
      { return os << '(' << p.x << ',' << p.y << ')'; }
    friend inline istream& operator >>(istream& is, TPoint& p)
      { char c; return is >> c >> p.x >> c >> p.y >> c; }
};

//
// class TSize
// ----- -----
//
class  TSize : public tagSIZE {
  public:
    // Constructors
    TSize() {}
    TSize(int dx, int dy) {cx = dx; cy = dy;}
    TSize(const POINT& point) {cx = point.x; cy = point.y;}
    TSize(const SIZE& size) {cx = size.cx; cy = size.cy;}
    TSize(DWORD dw) {cx = LOWORD(dw); cy = HIWORD(dw);}

    // Information functions/operators
    BOOL        operator ==(const TSize& other) const;
    BOOL        operator !=(const TSize& other) const;
    int         Magnitude() const;

    // Functions/binary-operators that return sizes
    TSize      operator +(const TSize& size) const;
    TSize      operator -(const TSize& size) const;
    TSize      operator -() const {return TSize(-cx, -cy);}

    // Functions/assignement-operators that modify this size
    TSize&     operator +=(const TSize& size);
    TSize&     operator -=(const TSize& size);

    friend inline ipstream& operator >>(ipstream& is, TSize& s)
        { return is >> s.cx >> s.cy; }
    friend inline opstream& operator <<(opstream& os, const TSize& s)
        { return os << s.cx << s.cy; }
    friend inline ostream& operator <<(ostream& os, const TSize& s)
      { return os << '(' << s.cx << 'x' << s.cy << ')'; }
};

//
// class TRect
// ----- -----
//
class _OWLCLASS TRect : public tagRECT {
  public:
    // Constructors
    TRect() {}
    TRect(const RECT far& rect);
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
    BOOL        IsEmpty() const;
    BOOL        IsNull() const;
    BOOL        operator ==(const TRect& other) const;
    BOOL        operator !=(const TRect& other) const;

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

    BOOL        Contains(const TPoint& point) const;
    BOOL        Contains(const TRect& other) const;
    BOOL        Touches(const TRect& other) const;
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

    friend ipstream& _OWLFUNC operator >>(ipstream& is, TRect& r);
    friend opstream& _OWLFUNC operator <<(opstream& os, const TRect& r);
    friend ostream& _OWLFUNC operator <<(ostream& os, const TRect& r);
};

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
    TResId(LPCSTR resString) : Id(resString) {}
    TResId(int resNum) : Id(MAKEINTRESOURCE(resNum)) {}
    operator LPSTR() {return (LPSTR)Id;}
    BOOL IsString() const {return HIWORD(Id);}

    friend ipstream& _OWLFUNC operator >>(ipstream& is, TResId& id);
    friend opstream& _OWLFUNC operator <<(opstream& os, const TResId& id);
    friend ostream& _OWLFUNC  operator <<(ostream& os, const TResId& id);
    
  private:
    LPCSTR  Id;
};
#define TResID           TResId     // Short-term backward compatibility

//
// class TDropInfo
// ----- ---------
//
class TDropInfo {
  public:
    TDropInfo(HDROP handle) : Handle(handle) {}

    operator HDROP() {return Handle;}

    UINT DragQueryFile(UINT index, char far* name, UINT nameLen)
           {return ::DragQueryFile(Handle, index, name, nameLen);}
    UINT DragQueryFileCount() {return ::DragQueryFile(Handle, -1, 0, 0);}
    UINT DragQueryFileNameLen(UINT index)
           {return ::DragQueryFile(Handle, index, 0, 0);}
    BOOL DragQueryPoint(TPoint& point)
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
    #if defined(__WIN32__)
      TProcInstance(FARPROC p) {Instance = FARPROC(p);}
    #else
      TProcInstance(FARPROC p) {Instance = ::MakeProcInstance(p, _hInstance);}
     ~TProcInstance() {::FreeProcInstance(Instance);}
    #endif
   
    operator FARPROC() {return Instance;}

  private:
    FARPROC Instance;
};

//
// class TPointer
// ----- --------
//
template<class T> class TPointerBase {
  public:
    T&   operator  *() {return *P;} // should throw exception if P==0
         operator T*() {return P;}
    int  operator  !() {return P==0;}
    void operator  ~() {P = 0;}
    void operator delete(void* p) {((TPointerBase<T>*)p)->P=0;}
  protected:
    TPointerBase(T* pointer) : P(pointer){}
   ~TPointerBase() {delete P;}
    TPointerBase() : P(0){}
    T* P;
  private:
    void* operator new(size_t){return 0;}  // prohibit use of new
};

template<class T> class TPointer : public TPointerBase<T> {
  public:
    TPointer() : TPointerBase<T>(){}
    TPointer(T* pointer) : TPointerBase<T>(pointer){}
    T* operator =(T* src) {delete P; return P = src;}
    T* operator =(const TPointer<T>& src)
                          {delete P; return P = src.P;}
    T* operator->() {return P;} // should throw exception if P==0
};

class TPointer<char> : public TPointerBase<char> {
  public:
    TPointer() : TPointerBase<char>(){}
    TPointer(char* pointer) : TPointerBase<char>(pointer){}
    char* operator =(char* src) {delete P; return P = src;}
    char* operator =(const TPointer<char>& src)
                                {delete P; return P = src.P;}
    char& operator[](int i) {return P[i];}
};


//----------------------------------------------------------------------------
// Inlines
//----------------------------------------------------------------------------

inline BOOL TPoint::operator ==(const TPoint& other) const {
  return other.x==x && other.y==y;
}

inline BOOL TPoint::operator !=(const TPoint& other) const {
  return other.x!=x || other.y!=y;
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


inline BOOL TSize::operator ==(const TSize& other) const {
  return other.cx==cx && other.cy==cy;
}

inline BOOL TSize::operator !=(const TSize& other) const {
  return other.cx!=cx || other.cy!=cy;
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

inline TRect::TRect(int _left, int _top, int _right, int _bottom) {
  Set(_left, _top, _right, _bottom);
}

inline TRect::TRect(const TPoint& topLeft, const TPoint& bottomRight) {
  Set(topLeft.x, topLeft.y, bottomRight.x, bottomRight.y);
}

inline TRect::TRect(const TPoint& origin, const TSize& extent) {
  Set(origin.x, origin.y, origin.x+extent.cx, origin.y+extent.cy);
}

inline BOOL TRect::IsEmpty() const {
  return left>=right || top>=bottom;
}

inline BOOL TRect::IsNull() const {
  return !left && !right && !top && !bottom;
}

inline BOOL TRect::operator ==(const TRect& other) const {
  return other.left==left && other.top==top
       && other.right==right && other.bottom==bottom;
}

inline BOOL TRect::operator !=(const TRect& other) const {
  return !(other==*this);
}

inline BOOL TRect::Contains(const TPoint& point) const {
  return point.x >= left && point.x < right
       && point.y >= top && point.y < bottom;
}

inline BOOL TRect::Contains(const TRect& other) const {
  return other.left >= left && other.right <= right
       && other.top >= top && other.bottom <= bottom;
}

inline BOOL TRect::Touches(const TRect& other) const {
  return other.right > left && other.left < right
       && other.bottom > top && other.top < bottom;
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

#endif  // __OWL_POINT_H
