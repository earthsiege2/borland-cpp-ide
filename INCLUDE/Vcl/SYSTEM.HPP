// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'System.pas' rev: 5.00

#ifndef SystemHPP
#define SystemHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <sysmac.H>	// system macros

//-- user supplied -----------------------------------------------------------

namespace System
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
static const bool False = false;
static const bool True = true;
static const int MaxInt = 0x7fffffff;
static const int MaxLongint = 0x7fffffff;
static const Shortint varEmpty = 0x0;
static const Shortint varNull = 0x1;
static const Shortint varSmallint = 0x2;
static const Shortint varInteger = 0x3;
static const Shortint varSingle = 0x4;
static const Shortint varDouble = 0x5;
static const Shortint varCurrency = 0x6;
static const Shortint varDate = 0x7;
static const Shortint varOleStr = 0x8;
static const Shortint varDispatch = 0x9;
static const Shortint varError = 0xa;
static const Shortint varBoolean = 0xb;
static const Shortint varVariant = 0xc;
static const Shortint varUnknown = 0xd;
static const Shortint varByte = 0x11;
static const Shortint varStrArg = 0x48;
static const Word varString = 0x100;
static const Word varAny = 0x101;
static const Word varTypeMask = 0xfff;
static const Word varArray = 0x2000;
static const Word varByRef = 0x4000;
static const Shortint vtInteger = 0x0;
static const Shortint vtBoolean = 0x1;
static const Shortint vtChar = 0x2;
static const Shortint vtExtended = 0x3;
static const Shortint vtString = 0x4;
static const Shortint vtPointer = 0x5;
static const Shortint vtPChar = 0x6;
static const Shortint vtObject = 0x7;
static const Shortint vtClass = 0x8;
static const Shortint vtWideChar = 0x9;
static const Shortint vtPWideChar = 0xa;
static const Shortint vtAnsiString = 0xb;
static const Shortint vtCurrency = 0xc;
static const Shortint vtVariant = 0xd;
static const Shortint vtInterface = 0xe;
static const Shortint vtWideString = 0xf;
static const Shortint vtInt64 = 0x10;
static const Shortint vmtSelfPtr = 0xffffffb4;
static const Shortint vmtIntfTable = 0xffffffb8;
static const Shortint vmtAutoTable = 0xffffffbc;
static const Shortint vmtInitTable = 0xffffffc0;
static const Shortint vmtTypeInfo = 0xffffffc4;
static const Shortint vmtFieldTable = 0xffffffc8;
static const Shortint vmtMethodTable = 0xffffffcc;
static const Shortint vmtDynamicTable = 0xffffffd0;
static const Shortint vmtClassName = 0xffffffd4;
static const Shortint vmtInstanceSize = 0xffffffd8;
static const Shortint vmtParent = 0xffffffdc;
static const Shortint vmtSafeCallException = 0xffffffe0;
static const Shortint vmtAfterConstruction = 0xffffffe4;
static const Shortint vmtBeforeDestruction = 0xffffffe8;
static const Shortint vmtDispatch = 0xffffffec;
static const Shortint vmtDefaultHandler = 0xfffffff0;
static const Shortint vmtNewInstance = 0xfffffff4;
static const Shortint vmtFreeInstance = 0xfffffff8;
static const Shortint vmtDestroy = 0xfffffffc;
static const Shortint vmtQueryInterface = 0x0;
static const Shortint vmtAddRef = 0x4;
static const Shortint vmtRelease = 0x8;
static const Shortint vmtCreateObject = 0xc;
extern PACKAGE void *ExceptProc;
extern PACKAGE void *ErrorProc;
extern PACKAGE void *ExceptClsProc;
extern PACKAGE void *ExceptObjProc;
extern PACKAGE TMetaClass*ExceptionClass;
extern PACKAGE void *SafeCallErrorProc;
extern PACKAGE void *AssertErrorProc;
extern PACKAGE void *AbstractErrorProc;
extern PACKAGE unsigned HPrevInst;
extern PACKAGE HINSTANCE MainInstance;
extern PACKAGE unsigned MainThreadID;
extern PACKAGE bool IsLibrary;
extern PACKAGE int CmdShow;
extern PACKAGE char *CmdLine;
extern PACKAGE void *InitProc;
extern PACKAGE int ExitCode;
extern PACKAGE void *ExitProc;
extern PACKAGE void *ErrorAddr;
extern PACKAGE int RandSeed;
extern PACKAGE bool IsConsole;
extern PACKAGE bool IsMultiThread;
extern PACKAGE Byte FileMode;
extern PACKAGE Byte Test8086;
extern PACKAGE Byte Test8087;
extern PACKAGE Shortint TestFDIV;
extern PACKAGE TextFile Input;
extern PACKAGE TextFile Output;
extern PACKAGE void *ClearAnyProc;
extern PACKAGE void *ChangeAnyProc;
extern PACKAGE void *RefAnyProc;
extern PACKAGE Word Default8087CW;
extern PACKAGE Word HeapAllocFlags;
extern PACKAGE Byte DebugHook;
extern PACKAGE Byte JITEnable;
extern PACKAGE bool NoErrMsg;
extern PACKAGE Variant Unassigned;
extern PACKAGE Variant Null;
extern PACKAGE OleVariant EmptyParam;
extern PACKAGE int AllocMemCount;
extern PACKAGE int AllocMemSize;
extern PACKAGE void *VarDispProc;
extern PACKAGE void *DispCallByIDProc;
extern PACKAGE TLibModule *LibModuleList;
extern PACKAGE TModuleUnloadRec *ModuleUnloadList;
extern PACKAGE void __fastcall TextStart(void);
extern PACKAGE void * __fastcall SysGetMem(int Size);
extern PACKAGE int __fastcall SysFreeMem(void * P);
extern PACKAGE void * __fastcall SysReallocMem(void * P, int Size);
extern PACKAGE THeapStatus __fastcall GetHeapStatus();
extern PACKAGE void __fastcall GetMemoryManager(TMemoryManager &MemMgr);
extern PACKAGE void __fastcall SetMemoryManager(const TMemoryManager &MemMgr);
extern PACKAGE bool __fastcall IsMemoryManagerSet(void);
extern PACKAGE void * __fastcall RaiseList(void);
extern PACKAGE void * __fastcall SetRaiseList(void * NewPtr);
extern PACKAGE void __fastcall SetInOutRes(int NewValue);
extern PACKAGE int __fastcall IOResult(void);
extern PACKAGE void __fastcall Move(const void *Source, void *Dest, int Count);
extern PACKAGE int __fastcall ParamCount(void);
extern PACKAGE AnsiString __fastcall ParamStr(int Index);
extern PACKAGE void __fastcall Randomize(void);
extern PACKAGE char __fastcall UpCase(char Ch);
extern PACKAGE void __fastcall Set8087CW(Word NewCW);
extern PACKAGE int __fastcall BeginThread(void * SecurityAttributes, unsigned StackSize, TThreadFunc 
	ThreadFunc, void * Parameter, unsigned CreationFlags, unsigned &ThreadId);
extern PACKAGE void __fastcall EndThread(int ExitCode);
extern PACKAGE void __fastcall UniqueString(AnsiString &str);
extern PACKAGE AnsiString __fastcall WideCharToString(wchar_t * Source);
extern PACKAGE AnsiString __fastcall WideCharLenToString(wchar_t * Source, int SourceLen);
extern PACKAGE void __fastcall WideCharToStrVar(wchar_t * Source, AnsiString &Dest);
extern PACKAGE void __fastcall WideCharLenToStrVar(wchar_t * Source, int SourceLen, AnsiString &Dest
	);
extern PACKAGE wchar_t * __fastcall StringToWideChar(const AnsiString Source, wchar_t * Dest, int DestSize
	);
extern PACKAGE AnsiString __fastcall OleStrToString(wchar_t * Source);
extern PACKAGE void __fastcall OleStrToStrVar(wchar_t * Source, AnsiString &Dest);
extern PACKAGE wchar_t * __fastcall StringToOleStr(const AnsiString Source);
extern PACKAGE void __fastcall VarCopyNoInd(Variant &Dest, const Variant &Source);
extern PACKAGE int __fastcall VarType(const Variant &V);
extern PACKAGE Variant __fastcall VarAsType(const Variant &V, int VarType);
extern PACKAGE bool __fastcall VarIsEmpty(const Variant &V);
extern PACKAGE bool __fastcall VarIsNull(const Variant &V);
extern PACKAGE AnsiString __fastcall VarToStr(const Variant &V);
extern PACKAGE Variant __fastcall VarFromDateTime(TDateTime DateTime);
extern PACKAGE TDateTime __fastcall VarToDateTime(const Variant &V);
extern PACKAGE Variant __fastcall VarArrayCreate(const int * Bounds, const int Bounds_Size, int VarType
	);
extern PACKAGE Variant __fastcall VarArrayOf(const Variant * Values, const int Values_Size);
extern PACKAGE int __fastcall VarArrayDimCount(const Variant &A);
extern PACKAGE int __fastcall VarArrayLowBound(const Variant &A, int Dim);
extern PACKAGE int __fastcall VarArrayHighBound(const Variant &A, int Dim);
extern PACKAGE void * __fastcall VarArrayLock(const Variant &A);
extern PACKAGE void __fastcall VarArrayUnlock(const Variant &A);
extern PACKAGE Variant __fastcall VarArrayRef(const Variant &A);
extern PACKAGE bool __fastcall VarIsArray(const Variant &A);
extern PACKAGE void __fastcall DynArrayToVariant(Variant &V, const void * DynArray, void * TypeInfo)
	;
extern PACKAGE void __fastcall DynArrayFromVariant(void * &DynArray, const Variant &V, void * TypeInfo
	);
extern PACKAGE unsigned __fastcall FindHInstance(void * Address);
extern PACKAGE unsigned __fastcall FindClassHInstance(TMetaClass* ClassType);
extern PACKAGE unsigned __fastcall FindResourceHInstance(unsigned Instance);
extern PACKAGE unsigned __fastcall LoadResourceModule(char * ModuleName);
extern PACKAGE void __fastcall EnumModules(TEnumModuleFunc Func, void * Data)/* overload */;
extern PACKAGE void __fastcall EnumResourceModules(TEnumModuleFunc Func, void * Data)/* overload */;
	
extern PACKAGE void __fastcall EnumModules(TEnumModuleFuncLW Func, void * Data)/* overload */;
extern PACKAGE void __fastcall EnumResourceModules(TEnumModuleFuncLW Func, void * Data)/* overload */
	;
extern PACKAGE void __fastcall AddModuleUnloadProc(TModuleUnloadProc Proc)/* overload */;
extern PACKAGE void __fastcall RemoveModuleUnloadProc(TModuleUnloadProc Proc)/* overload */;
extern PACKAGE void __fastcall AddModuleUnloadProc(TModuleUnloadProcLW Proc)/* overload */;
extern PACKAGE void __fastcall RemoveModuleUnloadProc(TModuleUnloadProcLW Proc)/* overload */;
extern PACKAGE void __fastcall RegisterModule(PLibModule LibModule);
extern PACKAGE void __fastcall UnregisterModule(PLibModule LibModule);
extern PACKAGE AnsiString __fastcall LoadResString(PResStringRec ResStringRec);
extern PACKAGE double __cdecl CompToDouble(Comp acomp);
extern PACKAGE void __cdecl DoubleToComp(double adouble, Comp &result);
extern PACKAGE Currency __cdecl CompToCurrency(Comp acomp);
extern PACKAGE void __cdecl CurrencyToComp(Currency acurrency, Comp &result);
extern PACKAGE void * __cdecl GetMemory(int Size);
extern PACKAGE int __cdecl FreeMemory(void * P);
extern PACKAGE void * __cdecl ReallocMemory(void * P, int Size);
extern PACKAGE void __fastcall FPower10(void);

}	/* namespace System */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace System;
#endif
#include <sysclass.H>	// system class definitions
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// System
