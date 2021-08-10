// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'System.pas' rev: 6.00

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
#define RTLVersion  (1.420000E+01)
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
static const Shortint varShortInt = 0x10;
static const Shortint varByte = 0x11;
static const Shortint varWord = 0x12;
static const Shortint varLongWord = 0x13;
static const Shortint varInt64 = 0x14;
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
static const Shortint opAdd = 0x0;
static const Shortint opSubtract = 0x1;
static const Shortint opMultiply = 0x2;
static const Shortint opDivide = 0x3;
static const Shortint opIntDivide = 0x4;
static const Shortint opModulus = 0x5;
static const Shortint opShiftLeft = 0x6;
static const Shortint opShiftRight = 0x7;
static const Shortint opAnd = 0x8;
static const Shortint opOr = 0x9;
static const Shortint opXor = 0xa;
static const Shortint opCompare = 0xb;
static const Shortint opNegate = 0xc;
static const Shortint opNot = 0xd;
static const Shortint opCmpEQ = 0xe;
static const Shortint opCmpNE = 0xf;
static const Shortint opCmpLT = 0x10;
static const Shortint opCmpLE = 0x11;
static const Shortint opCmpGT = 0x12;
static const Shortint opCmpGE = 0x13;
extern PACKAGE void *DispCallByIDProc;
extern PACKAGE void *ExceptProc;
extern PACKAGE void __fastcall (*ErrorProc)(Byte ErrorCode, void * ErrorAddr);
extern PACKAGE void *ExceptClsProc;
extern PACKAGE void *ExceptObjProc;
extern PACKAGE void *RaiseExceptionProc;
extern PACKAGE void *RTLUnwindProc;
extern PACKAGE TMetaClass*ExceptionClass;
extern PACKAGE TSafeCallErrorProc SafeCallErrorProc;
extern PACKAGE TAssertErrorProc AssertErrorProc;
extern PACKAGE void __fastcall (*ExitProcessProc)(void);
extern PACKAGE void __fastcall (*AbstractErrorProc)(void);
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
extern PACKAGE TextFile ErrOutput;
extern PACKAGE char * *envp;
static const Shortint CPUi386 = 0x2;
static const Shortint CPUi486 = 0x3;
static const Shortint CPUPentium = 0x4;
extern PACKAGE Word Default8087CW;
extern PACKAGE Word HeapAllocFlags;
extern PACKAGE Byte DebugHook;
extern PACKAGE Byte JITEnable;
extern PACKAGE bool NoErrMsg;
extern PACKAGE TTextLineBreakStyle DefaultTextLineBreakStyle;
#define sLineBreak "\r\n"
extern PACKAGE int AllocMemCount;
extern PACKAGE int AllocMemSize;
static const Word fmClosed = 0xd7b0;
static const Word fmInput = 0xd7b1;
static const Word fmOutput = 0xd7b2;
static const Word fmInOut = 0xd7b3;
static const Shortint tfCRLF = 0x1;
extern PACKAGE TLibModule *LibModuleList;
extern PACKAGE TModuleUnloadRec *ModuleUnloadList;
extern PACKAGE void __fastcall TextStart(void);
extern "C" void __stdcall SetLastError(int ErrorCode);
extern PACKAGE void * __fastcall SysGetMem(int Size);
extern PACKAGE int __fastcall SysFreeMem(void * P);
extern PACKAGE void * __fastcall SysReallocMem(void * P, int Size);
extern PACKAGE THeapStatus __fastcall GetHeapStatus();
extern PACKAGE void __fastcall GetMemoryManager(TMemoryManager &MemMgr);
extern PACKAGE void __fastcall SetMemoryManager(const TMemoryManager &MemMgr);
extern PACKAGE bool __fastcall IsMemoryManagerSet(void);
extern PACKAGE TObject* __fastcall ExceptObject(void);
extern PACKAGE void * __fastcall ExceptAddr(void);
extern PACKAGE void * __fastcall AcquireExceptionObject(void);
extern PACKAGE void __fastcall ReleaseExceptionObject(void);
extern PACKAGE void * __fastcall RaiseList(void);
extern PACKAGE void * __fastcall SetRaiseList(void * NewPtr);
extern PACKAGE void __fastcall SetInOutRes(int NewValue);
extern PACKAGE void __fastcall ChDir(const AnsiString S)/* overload */;
extern PACKAGE void __fastcall ChDir(char * P)/* overload */;
extern PACKAGE int __fastcall IOResult(void);
extern PACKAGE void __fastcall MkDir(const AnsiString S)/* overload */;
extern PACKAGE void __fastcall MkDir(char * P)/* overload */;
extern PACKAGE void __fastcall Move(const void *Source, void *Dest, int Count);
extern PACKAGE int __fastcall ParamCount(void);
extern PACKAGE AnsiString __fastcall ParamStr(int Index);
extern PACKAGE void __fastcall Randomize(void);
extern PACKAGE void __fastcall RmDir(const AnsiString S)/* overload */;
extern PACKAGE void __fastcall RmDir(char * P)/* overload */;
extern PACKAGE char __fastcall UpCase(char Ch);
extern PACKAGE void __fastcall Set8087CW(Word NewCW);
extern PACKAGE Word __fastcall Get8087CW(void);
extern PACKAGE int __fastcall Flush(TextFile &t);
extern PACKAGE void __fastcall Mark(void);
extern PACKAGE void __fastcall Release(void);
extern PACKAGE void __fastcall FPower10(void);
extern PACKAGE int __fastcall BeginThread(void * SecurityAttributes, unsigned StackSize, TThreadFunc ThreadFunc, void * Parameter, unsigned CreationFlags, unsigned &ThreadId);
extern PACKAGE void __fastcall EndThread(int ExitCode);
extern PACKAGE void __fastcall UniqueString(AnsiString &str)/* overload */;
extern PACKAGE void __fastcall UniqueString(WideString &str)/* overload */;
extern PACKAGE AnsiString __fastcall WideCharToString(wchar_t * Source);
extern PACKAGE AnsiString __fastcall WideCharLenToString(wchar_t * Source, int SourceLen);
extern PACKAGE void __fastcall WideCharToStrVar(wchar_t * Source, AnsiString &Dest);
extern PACKAGE void __fastcall WideCharLenToStrVar(wchar_t * Source, int SourceLen, AnsiString &Dest);
extern PACKAGE wchar_t * __fastcall StringToWideChar(const AnsiString Source, wchar_t * Dest, int DestSize);
extern PACKAGE AnsiString __fastcall OleStrToString(wchar_t * Source);
extern PACKAGE void __fastcall OleStrToStrVar(wchar_t * Source, AnsiString &Dest);
extern PACKAGE wchar_t * __fastcall StringToOleStr(const AnsiString Source);
extern PACKAGE void __fastcall GetVariantManager(TVariantManager &VarMgr);
extern PACKAGE void __fastcall SetVariantManager(const TVariantManager &VarMgr);
extern PACKAGE bool __fastcall IsVariantManagerSet(void);
extern PACKAGE void __fastcall DynArrayClear(void * &a, void * typeInfo);
extern PACKAGE void __fastcall DynArraySetLength(void * &a, void * typeInfo, int dimCnt, PLongint lengthVec);
extern PACKAGE unsigned __fastcall FindHInstance(void * Address);
extern PACKAGE unsigned __fastcall FindClassHInstance(TMetaClass* ClassType);
extern PACKAGE unsigned __fastcall FindResourceHInstance(unsigned Instance);
extern PACKAGE unsigned __fastcall LoadResourceModule(char * ModuleName, bool CheckOwner = true);
extern PACKAGE void __fastcall EnumModules(TEnumModuleFunc Func, void * Data)/* overload */;
extern PACKAGE void __fastcall EnumResourceModules(TEnumModuleFunc Func, void * Data)/* overload */;
extern PACKAGE void __fastcall EnumModules(TEnumModuleFuncLW Func, void * Data)/* overload */;
extern PACKAGE void __fastcall EnumResourceModules(TEnumModuleFuncLW Func, void * Data)/* overload */;
extern PACKAGE void __fastcall AddModuleUnloadProc(TModuleUnloadProc Proc)/* overload */;
extern PACKAGE void __fastcall RemoveModuleUnloadProc(TModuleUnloadProc Proc)/* overload */;
extern PACKAGE void __fastcall AddModuleUnloadProc(TModuleUnloadProcLW Proc)/* overload */;
extern PACKAGE void __fastcall RemoveModuleUnloadProc(TModuleUnloadProcLW Proc)/* overload */;
extern PACKAGE void __fastcall RegisterModule(PLibModule LibModule);
extern PACKAGE void __fastcall UnregisterModule(PLibModule LibModule);
extern PACKAGE double __cdecl CompToDouble(Comp Value);
extern PACKAGE void __cdecl DoubleToComp(double Value, Comp &Result);
extern PACKAGE Currency __cdecl CompToCurrency(Comp Value);
extern PACKAGE void __cdecl CurrencyToComp(Currency Value, Comp &Result);
extern PACKAGE void * __cdecl GetMemory(int Size);
extern PACKAGE int __cdecl FreeMemory(void * P);
extern PACKAGE void * __cdecl ReallocMemory(void * P, int Size);
extern PACKAGE void __fastcall SetLineBreakStyle(TextFile &T, TTextLineBreakStyle Style);
extern PACKAGE int __fastcall UnicodeToUtf8(char * Dest, wchar_t * Source, int MaxBytes)/* overload */;
extern PACKAGE unsigned __fastcall UnicodeToUtf8(char * Dest, unsigned MaxDestBytes, wchar_t * Source, unsigned SourceChars)/* overload */;
extern PACKAGE int __fastcall Utf8ToUnicode(wchar_t * Dest, char * Source, int MaxChars)/* overload */;
extern PACKAGE unsigned __fastcall Utf8ToUnicode(wchar_t * Dest, unsigned MaxDestChars, char * Source, unsigned SourceBytes)/* overload */;
extern PACKAGE AnsiString __fastcall UTF8Encode(const WideString WS);
extern PACKAGE WideString __fastcall UTF8Decode(const AnsiString S);
extern PACKAGE AnsiString __fastcall AnsiToUtf8(const AnsiString S);
extern PACKAGE AnsiString __fastcall Utf8ToAnsi(const AnsiString S);
extern PACKAGE AnsiString __fastcall LoadResString(PResStringRec ResStringRec);
extern PACKAGE PUCS4Char __fastcall PUCS4Chars(const UCS4String S);
extern PACKAGE UCS4String __fastcall WideStringToUCS4String(const WideString S);
extern PACKAGE WideString __fastcall UCS4StringToWideString(const UCS4String S);

}	/* namespace System */
using namespace System;
#include <sysclass.H>	// system class definitions
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// System
