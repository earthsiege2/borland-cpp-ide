//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
#ifndef IPCThrdHPP
#define IPCThrdHPP
//----------------------------------------------------------------------------
#include <vcl.h>
#include <Windows.hpp>
#include <Classes.hpp>
#include <SysUtils.hpp>
#include <System.hpp>

//-- type declarations -------------------------------------------------------

#define IPCDEBUG

// Win32 Helper Classes

//THandledObject
class THandledObject : public TObject
{
protected:
   HANDLE FHandle;
public:
   __fastcall virtual ~THandledObject();
   __property HANDLE Handle = {read=FHandle, nodefault};
__published:
   __fastcall THandledObject::THandledObject(void) : TObject() { }
};

//TEvent
class TEvent : public THandledObject
{
public:
   void __fastcall Signal(void);
   void __fastcall Reset(void);
   bool __fastcall Wait(Integer TimeOut);
   __fastcall TEvent::TEvent(const AnsiString Name, bool Manual);
};

//TMutex
class TMutex : public THandledObject
{
public:
   __fastcall TMutex(const AnsiString Name);
   bool __fastcall Get(Integer TimeOut);
   bool __fastcall Release(void);
};

//TSharedMem
class TSharedMem : public THandledObject
{
private:
   AnsiString FName;
   int FSize;
   bool FCreated;
   void *FFileView;
public:
   __fastcall TSharedMem(const AnsiString Name, int Size);
   __fastcall virtual ~TSharedMem(void);
   __property AnsiString Name = {read=FName, nodefault};
   __property int Size = {read=FSize, nodefault};
   __property Pointer Buffer = {read=FFileView, nodefault};
   __property bool Created = {read=FCreated, nodefault};
};

//Debug Tracing
#if defined(IPCDEBUG)

#define TRACE_BUF_SIZE Integer(204800)
#define TRACE_BUFFER "TRACE_BUFFER"
#define TRACE_MUTEX "TRACE_MUTEX"

typedef struct _TTraceEntry
{
   int Size;
   int Time;
   Char Msg[1];
} TTraceEntry, * PTraceEntry;

class TIPCTracer : public TObject
{

private:
   char FIDName[10];
   TSharedMem *FSharedMem;
   TMutex *FMutex;
   PTraceEntry __fastcall MakePtr(int Ofs);
   PTraceEntry __fastcall FirstEntry(void);
   PTraceEntry __fastcall NextEntry(void);

public:
   __fastcall TIPCTracer(AnsiString ID);
   __fastcall virtual ~TIPCTracer(void);
   void __fastcall Add(PChar AMsg);
   void __fastcall GetList(TStrings *List);
   void __fastcall Clear(void);
};

#endif  // IPCDEBUG

//IPC Classes

#define MAX_CLIENTS Byte(6)
#define TIMEOUT Smallint(2000)
#define BUFFER_NAME "BUFFER_NAME"
#define BUFFER_MUTEX_NAME "BUFFER_MUTEX"
#define MONITOR_EVENT_NAME "MONITOR_EVENT"
#define CLIENT_EVENT_NAME "CLIENT_EVENT"
#define CONNECT_EVENT_NAME "CONNECT_EVENT"
#define CLIENT_DIR_NAME "CLIENT_DIRECTORY"
#define CLIENT_DIR_MUTEX "DIRECTORY_MUTEX"

class TIPCThread;

class EMonitorActive : public Exception
{
public:
   __fastcall EMonitorActive::EMonitorActive(const AnsiString p0) : Exception(p0) { }
   __fastcall EMonitorActive::EMonitorActive(const AnsiString p0, const TVarRec *p1, const
   	int p1_Size) : Exception(p0, p1, p1_Size) { }
   __fastcall EMonitorActive::EMonitorActive(Integer p0) : Exception(p0) { }
   __fastcall EMonitorActive::EMonitorActive(Integer p0, const TVarRec *p1, const int
   	p1_Size) : Exception(p0, p1, p1_Size) { }
   __fastcall EMonitorActive::EMonitorActive(const AnsiString p0, int p1) : Exception(
   	p0, p1) { }
   __fastcall EMonitorActive::EMonitorActive(const AnsiString p0, const TVarRec *p1,
   	const int p1_Size, int p3) : Exception(p0, p1, p1_Size, p3) { }
   __fastcall EMonitorActive::EMonitorActive(int p0, int p1) : Exception(p0,
   	p1) { }
   __fastcall EMonitorActive::EMonitorActive(int p0, const TVarRec *p1, const
   	int p1_Size, int p3) : Exception(p0, p1, p1_Size, p3) { }
};

//TIPCEvent

enum TEventKind { evMonitorAttach,
                  evMonitorDetach,
                  evMonitorSignal,
                  evMonitorExit,
                  evClientStart,
                  evClientStop,
                  evClientAttach,
                  evClientDetach,
                  evClientSwitch,
                  evClientSignal,
                  evClientExit
};

enum TClientFlag {cfError, cfMouseMove, cfMouseDown, cfResize, cfAttach};

typedef Set<TClientFlag, cfError, cfAttach>  TClientFlags;

typedef struct _TEventData
{
   short X;
   short Y;
   TClientFlag Flag;
   TClientFlags Flags;
}TEventData, * PEventData;

typedef void __fastcall (__closure *TConnectEvent)(TIPCThread* Sender,
                                                   bool Connecting);

typedef void __fastcall (__closure *TDirUpdateEvent)(TIPCThread* Sender);

typedef void __fastcall (__closure *TIPCNotifyEvent)(TIPCThread *Sender,
                                                     const TEventData &Data);

typedef struct _TIPCEventInfo
{
   int FID;
   TEventKind FKind;
   TEventData FData;
}TIPCEventInfo, * PIPCEventInfo;

class TIPCEvent : public TEvent
{
private:
   TIPCThread *FOwner;
   int FOwnerID;
   TSharedMem *FSharedMem;
   TIPCEventInfo *FEventInfo;
   int __fastcall GetID(void);
   void __fastcall SetID(int Value);
   TEventKind __fastcall GetKind(void);
   void __fastcall SetKind(TEventKind Value);
   TEventData __fastcall GetData(void);
   void __fastcall SetData(const TEventData& Value);
public:
   __fastcall TIPCEvent::TIPCEvent(TIPCThread *AOwner,
                                        const AnsiString Name,
                                        bool Manual);
   __fastcall virtual ~TIPCEvent(void);
   void __fastcall Signal(TEventKind Kind);
   void __fastcall SignalID(TEventKind Kind, int ID);
   void __fastcall SignalData(TEventKind Kind, int ID, const TEventData &Data);
   bool __fastcall WaitFor(int TimeOut, int ID, TEventKind Kind);
   __property int ID = {read=GetID, write=SetID, nodefault};
   __property TEventKind Kind = {read=GetKind, write=SetKind, nodefault};
   __property TEventData Data = {read=GetData, write=SetData};
   __property int OwnerID = {read=FOwnerID, write=FOwnerID, nodefault};
   __property TIPCEventInfo* EventInfo = {read=FEventInfo, write=FEventInfo};
};

//TClientDirectory

struct TClientDirEntry
{
   int ID;
   Char Name[59];
};

typedef TClientDirEntry TClientDirRecords[MAX_CLIENTS];
typedef TClientDirRecords* PClientDirRecords;

class TClientDirectory : public TObject
{
private:
   int *FClientCount;
   int *FMonitorID;
   int FMaxClients;
   TMutex *FMutex;
   TSharedMem *FSharedMem;
   TClientDirRecords *FDirBuffer;
   int __fastcall GetCount(void);
   AnsiString __fastcall GetClientName(int ClientID);
   TClientDirEntry __fastcall GetClientRec(int Index);
   int __fastcall IndexOf(int ClientID);
   int __fastcall GetMonitorID(void);
   void __fastcall SetMonitorID(int MonitorID);
public:
   __fastcall TClientDirectory::TClientDirectory(int MaxClients);
   __fastcall virtual ~TClientDirectory(void);
   int __fastcall AddClient(int ClientID, const AnsiString AName);
   int __fastcall Last(void);
   bool __fastcall RemoveClient(int ClientID);
   __property int Count = {read=GetCount, nodefault};
   __property TClientDirEntry ClientRec[int Index] = {read=GetClientRec};
   __property int MonitorID = {read=GetMonitorID, write=SetMonitorID, nodefault};
   __property AnsiString Name[int ClientID] = {read=GetClientName};
};

//TIPThread

enum TState { stInActive, stDisconnected, stConnected };

class TIPCThread : public TThread
{
protected:
#if defined(IPCDEBUG)
   TIPCTracer *FTracer;
#endif
   int FID;
   AnsiString FName;
   TState FState;
   TClientDirectory *FClientDirectory;
   TIPCEvent *FClientEvent;
   TIPCNotifyEvent FOnSignal;
   TConnectEvent FOnConnect;
public:
   TIPCEvent *FConnectEvent;
   TIPCEvent *FMonitorEvent;
   __fastcall TIPCThread::TIPCThread(int AID, const AnsiString AName);
   __fastcall virtual ~TIPCThread(void);
   virtual void __fastcall Activate(void) = 0;
   virtual void __fastcall DeActivate(void) = 0;
   void __fastcall DbgStr(const AnsiString S);
   __property TState State = {read=FState, nodefault};
__published:
   __property TConnectEvent OnConnect = {read=FOnConnect, write=FOnConnect};
   __property TIPCNotifyEvent OnSignal = {read=FOnSignal, write=FOnSignal};
};

//TIPCMonitor

class TIPCMonitor : public TIPCThread
{
private:
   int FClientID;
   bool FAutoSwitch;
   TDirUpdateEvent FOnDirUpdate;
protected:
   void __fastcall ConnectToClient(int ID);
   void __fastcall DisconnectFromClient(bool Wait);
   void __fastcall DoOnSignal(void);
   AnsiString __fastcall GetClientName(void);
   virtual void __fastcall Execute(void);
   void __fastcall SetCurrentClient(int ID);
   void __fastcall DoOnDirUpdate(void);
public:
   __fastcall TIPCMonitor::TIPCMonitor(int AID, const AnsiString AName);
   virtual void __fastcall Activate(void);
   virtual void __fastcall DeActivate();
   void __fastcall SignalClient(const TClientFlags Value);
   void __fastcall GetClientNames(TStringList* List);
   void __fastcall GetDebugInfo(TStrings *List);
   void __fastcall SaveDebugInfo(const AnsiString FileName);
   void __fastcall ClearDebugInfo(void);
   __property bool AutoSwitch = {read=FAutoSwitch, write=FAutoSwitch, nodefault};
   __property AnsiString ClientName = {read=GetClientName, nodefault};
   __property int ClientID = {read=FClientID, write=SetCurrentClient, nodefault};
   __property TDirUpdateEvent OnDirectoryUpdate = {read=FOnDirUpdate, write=FOnDirUpdate};
};

//TIPCClient

class TIPCClient : public TIPCThread
{

private:
   TIPCEvent *FWaitEvent;
   void __fastcall ConnectToMonitor(void);
   void __fastcall DisconnectFromMonitor(bool Wait);
protected:
   virtual void __fastcall Execute(void);
public:
   virtual void __fastcall Activate(void);
   virtual void __fastcall DeActivate(void);
   int __fastcall ClientCount(void);
   void __fastcall SignalMonitor(const TEventData &Data);
   void __fastcall MakeCurrent(void);
   __fastcall TIPCClient::TIPCClient(int AID, const AnsiString AName)
                             : TIPCThread(AID, AName) { }
};

//-- var, const, procedure ---------------------------------------------------
extern bool __fastcall IsMonitorRunning(THandle& Hndl);
//-- end unit ----------------------------------------------------------------
#endif	// IPCThrd

