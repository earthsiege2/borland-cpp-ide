// SYSOPEN.H: Pascal open array parameter support
// Copyright (c) 1997, 2002 Borland Software Corporation

#if !defined(SYSOPEN_H)	// open arrays
#define SYSOPEN_H

#if !defined(SystemHPP)
#error Do not include this file directly.  Include 'system.hpp'.
#endif

#pragma option push -w-inl -w-lvc

namespace System
{
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

	template<class T>
	OpenArray<T>& __fastcall
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

  // Used with OPENARRAY macro (immediately following this template declaration)
#pragma option push -w-par
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
#pragma option pop

  // OPENARRAY: construct an OpenArray<type> on the fly
  #define OPENARRAY(type, values) \
	OpenArray<type>values, OpenArrayCount<type>values.GetHigh()

  // ARRAYOFCONST: construct an OpenArray<TVarRec> on the fly
  #define ARRAYOFCONST(values) \
	OpenArray<TVarRec>values, OpenArrayCount<TVarRec>values.GetHigh()

  #define ARRAYSIZE(a) (sizeof(a)/sizeof(a[0]))

  // EXISTINGARRAY: pass an existing array where an open array is expected
  #define EXISTINGARRAY(a) (a), ((sizeof(a)/sizeof(a[0]))-1)

  // SLICE: pass part of an existing array where an open array is expected
  #define SLICE(a, n) (a), (n - 1)
}

#pragma option pop

#endif
