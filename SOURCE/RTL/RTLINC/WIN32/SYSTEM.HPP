//----------------------------------------------------------------------------
// System.hpp - bcbdcc32 generated hdr (DO NOT EDIT) rev: 0
// From: System.pas
//----------------------------------------------------------------------------
#ifndef SystemHPP
#define SystemHPP
//----------------------------------------------------------------------------
#include <sysdefs.h>
#pragma warn -par
#pragma warn -hid 
#pragma warn -inl

namespace System
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
#define False (bool)(0)
#define True (bool)(1)
#define MaxInt (int)(2147483647)
#define MaxLongint (int)(2147483647)
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
extern __declspec(thread) void *RaiseList;
extern __declspec(thread) int InOutRes;
extern void *ExceptProc;
extern void *ErrorProc;
extern void *ExceptClsProc;
extern void *ExceptObjProc;
extern TMetaClass*ExceptionClass;
extern long HPrevInst;
extern long HInstance;
extern int CmdShow;
extern char *CmdLine;
extern void *InitProc;
extern int ExitCode;
extern void *ExitProc;
extern void *ErrorAddr;
extern void *DllProc;
extern long RandSeed;
extern bool IsLibrary;
extern bool IsConsole;
extern bool IsMultiThread;
extern unsigned char FileMode;
extern unsigned char Test8086;
extern unsigned char Test8087;
extern signed char TestFDIV;
extern TextFile Input;
extern TextFile Output;
extern int TlsIndex;
extern int TlsIndex4;
extern unsigned char TlsLast;
extern unsigned short HeapAllocFlags;
extern unsigned char DebugHook;
extern Variant Unassigned;
extern Variant Null;
extern int AllocMemCount;
extern int AllocMemSize;
extern void *VarDispProc;
extern void __fastcall TextStart(void);
extern void * __fastcall SysGetMem(int Size);
extern int __fastcall SysFreeMem(void * P);
extern void * __fastcall SysReallocMem(void * P, int Size);
extern THeapStatus __fastcall GetHeapStatus(void);
extern void __fastcall GetMemoryManager(TMemoryManager &MemMgr);
extern void __fastcall SetMemoryManager(const TMemoryManager &MemMgr);
extern int __fastcall IOResult(void);
extern void __fastcall Move(const void *Source, void *Dest, int Count);
extern int __fastcall ParamCount(void);
extern AnsiString __fastcall ParamStr(int Index);
extern void __fastcall Randomize(void);
extern char __fastcall UpCase(char Ch);
extern int __fastcall BeginThread(void * SecurityAttributes, int StackSize, TThreadFunc ThreadFunc, 
	void * Parameter, int CreationFlags, int &ThreadId);
extern void __fastcall EndThread(int ExitCode);
extern void __fastcall UniqueString( AnsiString &str);
extern AnsiString __fastcall WideCharToString(wchar_t * Source);
extern AnsiString __fastcall WideCharLenToString(wchar_t * Source, int SourceLen);
extern void __fastcall WideCharToStrVar(wchar_t * Source,  AnsiString &Dest);
extern void __fastcall WideCharLenToStrVar(wchar_t * Source, int SourceLen,  AnsiString &Dest);
extern wchar_t * __fastcall StringToWideChar(const AnsiString Source, wchar_t * Dest, int DestSize);
	
extern AnsiString __fastcall OleStrToString(wchar_t * Source);
extern void __fastcall OleStrToStrVar(wchar_t * Source,  AnsiString &Dest);
extern wchar_t * __fastcall StringToOleStr(const AnsiString Source);
extern void __fastcall VarClear(Variant &V);
extern void __fastcall VarCopy(Variant &Dest, const Variant &Source);
extern void __fastcall VarCopyNoInd(Variant &Dest, const Variant &Source);
extern void __fastcall VarCast(Variant &Dest, const Variant &Source, int VarType);
extern int __fastcall VarType(const Variant &V);
extern Variant __fastcall VarAsType(const Variant &V, int VarType);
extern bool __fastcall VarIsEmpty(const Variant &V);
extern bool __fastcall VarIsNull(const Variant &V);
extern AnsiString __fastcall VarToStr(const Variant &V);
extern Variant __fastcall VarFromDateTime(TDateTime DateTime);
extern TDateTime __fastcall VarToDateTime(const Variant &V);
extern Variant __fastcall VarArrayCreate(const int *Bounds, const int Bounds_Size, int VarType);
extern Variant __fastcall VarArrayOf(const Variant *Values, const int Values_Size);
extern void __fastcall VarArrayRedim(Variant &A, int HighBound);
extern int __fastcall VarArrayDimCount(const Variant &A);
extern int __fastcall VarArrayLowBound(const Variant &A, int Dim);
extern int __fastcall VarArrayHighBound(const Variant &A, int Dim);
extern void * __fastcall VarArrayLock(const Variant &A);
extern void __fastcall VarArrayUnlock(const Variant &A);
extern Variant __fastcall VarArrayRef(const Variant &A);
extern bool __fastcall VarIsArray(const Variant &A);
extern void __cdecl VclInit(bool isDLL, long hInst, bool isGui);
extern void __cdecl VclExit(void);
extern double __cdecl CompToDouble(Comp acomp);
extern void __cdecl DoubleToComp(double adouble, Comp &result);
extern Currency __cdecl CompToCurrency(Comp acomp);
extern void __cdecl CurrencyToComp(Currency acurrency, Comp &result);
extern void __cdecl ProcessAttachTLS(void);
extern void __cdecl ProcessDetachTLS(void);
extern void __cdecl ThreadAttachTLS(void);
extern void __cdecl ThreadDetachTLS(void);
extern void * __cdecl GetMemory(int Size);
extern int __cdecl FreeMemory(void * P);
extern void * __cdecl ReallocMemory(void * P, int Size);
extern void __fastcall FPower10(void);

}	/* namespace System */

#pragma warn .par
#pragma warn .hid 
#pragma warn .inl

#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace System;
#endif
//-- end unit ----------------------------------------------------------------
#endif	// System
