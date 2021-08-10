//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "IPCThrd.h"
#include <stdio.h>
//-----------------------------------------------------------------------------
/* Inter-Process Communication Thread Classes */

// Utility Routines

void __fastcall Error(const AnsiString Msg)
{
  ShowMessage(Msg);
  throw(Msg);
}

AnsiString __fastcall EventName(TEventKind Event)
{
  switch (Event){
    case evMonitorAttach: return "evMonitorAttach";
    case evMonitorDetach: return "evMonitorDetach";
    case evMonitorSignal: return "evMonitorSignal";
    case evMonitorExit:   return "evMonitorExit";
    case evClientStart:   return "evClientStart";
    case evClientStop:    return "evClientStop";
    case evClientAttach:  return "evClientAttach";
    case evClientDetach:  return "evClientDetach";
    case evClientSwitch:  return "evClientSwitch";
    case evClientSignal:  return "evClientSignal";
    case evClientExit:    return "evClientExit";
    default:              return "";
  }
}

/* Utility function used by the monitor to determine if another monitor is
  already running.  This is needed to make the monitor a single instance .EXE.
  This function relies on the fact that the first 4 bytes of the client
  directory always contain the Application handle of the monitor, or zero if
  no monitor is running.  This function is used in Monitor.cpp. */

bool __fastcall IsMonitorRunning(THandle& Hndl)
{
   TSharedMem*  SharedMem;
   bool      Result;

   SharedMem = new TSharedMem(CLIENT_DIR_NAME, 4);
   Hndl = *((THandle*)(SharedMem->Buffer));
   Result = (Hndl != 0);
   delete SharedMem;
   return Result;
}

/* THandledObject */

/* This is a generic class for all encapsulated WinAPI's which need to call
  CloseHandle when no longer needed.  This code eliminates the need for
  3 identical destructors in the TEvent, TMutex, and TSharedMem classes
  which are descended from this class. */

__fastcall  THandledObject::~THandledObject()
{
   if (FHandle != 0)
      CloseHandle(FHandle);
}

/* TEvent */

/* This class encapsulates the concept of a Win32 event (not to be
  confused with Delphi events), see "CreateEvent" in the Win32
  reference for more information */
__fastcall TEvent::TEvent(const AnsiString Name, bool Manual)
{
   AnsiString buf;

   buf = Name + ".Data";
   FHandle = CreateEvent(NULL, Manual, false, buf.c_str());
   if (FHandle == 0) Abort();
}

void __fastcall TEvent::Reset()
{
   ResetEvent(FHandle);
}

void __fastcall TEvent::Signal()
{
   SetEvent(FHandle);
}

bool __fastcall TEvent::Wait(int TimeOut)
{
   return WaitForSingleObject(FHandle, TimeOut) == WAIT_OBJECT_0;
}

/* TMutex */

/* This class encapsulates the concept of a Win32 mutex.  See "CreateMutex"
  in the Win32 reference for more information */

__fastcall TMutex::TMutex(const AnsiString Name)
{
   FHandle = CreateMutex(NULL, false, Name.c_str());
   if (FHandle == 0) Abort();
}

bool __fastcall TMutex::Get(int TimeOut)
{
   return WaitForSingleObject(FHandle, TimeOut) == WAIT_OBJECT_0;
}

bool __fastcall TMutex::Release(void)
{
   return ReleaseMutex(FHandle);
}

/* TSharedMem */

/* This class simplifies the process of creating a region of shared memory.
  In Win32, this is accomplished by using the CreateFileMapping and
  MapViewOfFile functions. */

__fastcall TSharedMem::TSharedMem(const AnsiString Name, int Size)
{

   try{

    FName = Name;
    FSize = Size;

    /* CreateFileMapping, when called with $FFFFFFFF for the handle value,
      creates a region of shared memory. If an object with same name already
      exists, then a Handle to that object will be returned. */
    FHandle = CreateFileMapping((HANDLE)0xFFFFFFFF,
                                NULL,
                                PAGE_READWRITE,
                                0,
                                Size,
                                Name.c_str());
    if (FHandle == 0) Abort();
    FCreated = (GetLastError == 0);
    /* We still need to map a pointer to the handle of the shared memory region */
    FFileView = MapViewOfFile(FHandle,
                              FILE_MAP_WRITE,
                              0, 0, Size);
    if (FFileView == NULL) Abort();
  }
  catch(...) {
    Error(Format("Error creating shared memory %s (%d)",
                 (TVarRec*)Name.c_str(), GetLastError()));
  }
}

__fastcall TSharedMem::~TSharedMem()
{
   if (FFileView != NULL)
     UnmapViewOfFile(FFileView);
}

/* Debug Tracing */

#if defined(IPCDEBUG)

/* Debug Tracing */

/* The IPCTracer class was used to create and debug the IPC classes which
  follow.  When developing a multi-process, multi-threaded application, it
  is difficult to debug effectively using ordinary debuggers.  The trace
  data is displayed in a Window when you click on a speed button in the
  monitor program. */

  /* TIPCTracer */

__fastcall TIPCTracer::TIPCTracer(AnsiString ID)
{
   strcpy(FIDName, ID.c_str());
   FSharedMem = new TSharedMem(TRACE_BUFFER, TRACE_BUF_SIZE);
   FMutex = new TMutex(TRACE_MUTEX);

   //The first four bytes of the buffer contain the number of meaningful
   //bytes in the buffer at any given time.
   if (*((int*)(FSharedMem->Buffer)) == 0)
     *(int*)FSharedMem->Buffer = sizeof(PTraceEntry);
}

__fastcall TIPCTracer::~TIPCTracer()
{
   delete FMutex;
   delete FSharedMem;
}

PTraceEntry __fastcall TIPCTracer::MakePtr(int Ofs)
{
   return PTraceEntry(int(FSharedMem->Buffer) + Ofs);
}

PTraceEntry __fastcall TIPCTracer::FirstEntry()
{
   return MakePtr(sizeof(PTraceEntry));
}

PTraceEntry __fastcall TIPCTracer::NextEntry(void)
{
   return MakePtr(*(int*)(FSharedMem->Buffer));
}

void __fastcall TIPCTracer::Add(PChar AMsg)
{
   PTraceEntry    TraceEntry;
   int            EntrySize;
   TLargeInteger  TempTime;

   FMutex->Get(INFINITE);
   TraceEntry = NextEntry();
   EntrySize = sizeof(AMsg) + sizeof(TTraceEntry) + 16;

  /* If we hit the end of the buffer, just wrap around */
   if ((EntrySize + *(int*)(FSharedMem->Buffer))  >  FSharedMem->Size)
      TraceEntry = FirstEntry();

   QueryPerformanceCounter(&TempTime);
//  TraceEntry->Time = TempTime.LowPart;
   TraceEntry->Time = (int) TempTime.QuadPart;
   TraceEntry->Size = EntrySize;
   sprintf(TraceEntry->Msg,
          "%s: %s", FIDName, AMsg);
   *(int*)(FSharedMem->Buffer) = *(int*)(FSharedMem->Buffer) + TraceEntry->Size;
   FMutex->Release();
}

void __fastcall TIPCTracer::GetList(TStrings *List)
{
   PTraceEntry  LastEntry;
   PTraceEntry TraceEntry;
   int  Dif;
   int  LastTime;

   List->BeginUpdate();
   try{
    LastEntry = NextEntry();
    TraceEntry = FirstEntry();
    LastTime = TraceEntry->Time;
    List->Clear();
    while (TraceEntry != LastEntry){
      Dif = TraceEntry->Time - LastTime;
      List->Add(Format("%x %10d %s",
                       ARRAYOFCONST((TraceEntry->Time,
                                     Dif,
                                     TraceEntry->Msg))));
      LastTime = TraceEntry->Time;
      (int)TraceEntry = (int)TraceEntry + TraceEntry->Size;
    }
   }
   catch(...){
    List->EndUpdate();
    throw;
   }
   List->EndUpdate();
}

void __fastcall TIPCTracer::Clear()
{
   FMutex->Get(INFINITE);
   *(int*)FSharedMem->Buffer = sizeof(PTraceEntry);
   FMutex->Release();
}

#endif

/* TIPCEvent */

/* Win32 events are very basic.  They are either signaled or non-signaled.
  The TIPCEvent class creates a "typed" TEvent, by using a block of shared
  memory to hold an "EventKind" property.  The shared memory is also used
  to hold an ID, which is important when running multiple clients, and
  a Data area for communicating data along with the event */

__fastcall TIPCEvent::TIPCEvent(TIPCThread *AOwner,
                                const AnsiString Name,
                                bool Manual)
                    :TEvent(Name, Manual)
{
   FOwner = AOwner;
   FSharedMem = new TSharedMem(Name, sizeof(TIPCEventInfo));
   FEventInfo = (TIPCEventInfo*) FSharedMem->Buffer;
}

__fastcall TIPCEvent::~TIPCEvent()
{
   delete FSharedMem;
}

int __fastcall TIPCEvent::GetID()
{
   return FEventInfo->FID;
}

void __fastcall TIPCEvent::SetID(int Value)
{
   FEventInfo->FID = Value;
}

TEventKind __fastcall TIPCEvent::GetKind()
{
   return FEventInfo->FKind;
}

void __fastcall TIPCEvent::SetKind(TEventKind Value)
{
   FEventInfo->FKind = Value;
}

TEventData __fastcall TIPCEvent::GetData()
{
   return FEventInfo->FData;
}

void __fastcall TIPCEvent::SetData(const TEventData& Value)
{
   FEventInfo->FData = Value;
}

void __fastcall TIPCEvent::Signal(TEventKind Kind)
{
   SetID(OwnerID);
   FEventInfo->FKind = Kind;
   TEvent::Signal();
}

void __fastcall TIPCEvent::SignalID(TEventKind Kind, int ID)
{
   FEventInfo->FID = ID;
   FEventInfo->FKind = Kind;
   TEvent::Signal();
}

void __fastcall TIPCEvent::SignalData(TEventKind Kind,
                                      int ID,
                                      const TEventData& Data)
{
   FEventInfo->FID = ID;
   FEventInfo->FData = Data;
   FEventInfo->FKind = Kind;
   TEvent::Signal();
}

bool __fastcall TIPCEvent::WaitFor(int TimeOut,
                                      int ID,
                                      TEventKind Kind)
{
   bool returnval = Wait(TimeOut);
   if (returnval)
      returnval = (ID == FEventInfo->FID) && (Kind == FEventInfo->FKind);
   else
      FOwner->DbgStr(Format("Wait Failed %s Kind: %s ID: %x" ,
                            ARRAYOFCONST((FOwner->ClassName(),
                                          EventName(Kind),
                                          ID))));
   return returnval;
}

/* TClientDirectory */

/* The client directory is a block of shared memory where the list of all
  active clients is maintained */

__fastcall TClientDirectory::TClientDirectory(int MaxClients)
{
   FMaxClients = MaxClients;
   FMutex = new TMutex(CLIENT_DIR_MUTEX);
   FSharedMem = new TSharedMem(CLIENT_DIR_NAME,
                              FMaxClients * sizeof(TClientDirEntry) + 8);
   FMonitorID = (int*) FSharedMem->Buffer;
   (int)FClientCount = (int)FMonitorID + sizeof(FMonitorID);
   (int)FDirBuffer = (int)FClientCount + sizeof(FClientCount);
}

__fastcall TClientDirectory::~TClientDirectory()
{
   delete FSharedMem;
}

int __fastcall TClientDirectory::AddClient(int ClientID, const AnsiString AName)
{
   int Result = -1;
   if (Count == FMaxClients)
      {
      String EString("Maximun of ");
      EString += (int)FMaxClients;
      EString += " clients allowed.";
      Error(EString);
      }
   if (IndexOf(ClientID) > -1)
      Error("Duplicate client ID");
   if (FMutex->Get(TIMEOUT)){
    try{
        FDirBuffer[Count]->ID = ClientID;
        lstrcpy(FDirBuffer[Count]->Name,
                AName.c_str());
        (*FClientCount)++;
        Result = Count-1;
    }
    catch(...){
      FMutex->Release();
      throw;
    } //end catch
   }   //end if (FMutex..
   FMutex->Release();
   return Result;
}

int __fastcall TClientDirectory::GetCount()
{
   return (*FClientCount);
}

TClientDirEntry __fastcall TClientDirectory::GetClientRec(int Index)
{
   if ((Index < 0) || (Index >= Count))
     Error("Invalid client list index");
   return *FDirBuffer[Index];
}

AnsiString __fastcall TClientDirectory::GetClientName(int ClientID)
{
   int  Index;

   Index = IndexOf(ClientID);
   if (Index >= 0)
     return FDirBuffer[Index]->Name;
   else
     return "";
}

int __fastcall TClientDirectory::IndexOf(int ClientID)
{
   int  I;

   for(I=0; I < Count; I++)
   if (FDirBuffer[I]->ID == ClientID){
        return I;
   }
   return -1;
}

int __fastcall TClientDirectory::Last()
{
   if (Count > 0)
     return FDirBuffer[Count-1]->ID;
   else
     return 0;
}

bool __fastcall TClientDirectory::RemoveClient(int ClientID)
{
   int  Index;
   bool  Result;
   Index = IndexOf(ClientID);
   if ((Index > -1) && FMutex->Get(TIMEOUT)){
     try{
       if ((Index > 0) && (Index < Count))
         Move(FDirBuffer[Index+1],
              FDirBuffer[Index],
             (Count - Index) * sizeof(TClientDirEntry));
       (*FClientCount)--;    //Decrement client count
       Result = true;
     }
    catch(...){
       FMutex->Release();
       throw;
     }
     FMutex->Release();
   } //end if
   else
      Result = false;
   return Result;
}

int __fastcall TClientDirectory::GetMonitorID()
{
   return *FMonitorID;
}

void __fastcall TClientDirectory::SetMonitorID(int MonitorID)
{
   *FMonitorID = MonitorID;
}

/* TIPCThread */

/* The TIPCThread class implements the functionality which is common between
  the monitor and client thread classes. */

__fastcall TIPCThread::TIPCThread(int AID, const AnsiString AName)
                      :TThread(true)
{
   FID = AID;
   FName = AName;
#if defined(IPCDEBUG)
   if (dynamic_cast<TIPCMonitor*>(this) != 0)
      FTracer = new TIPCTracer(FName);
   else
      FTracer = new TIPCTracer(IntToHex(FID, 8));
#endif
   FMonitorEvent = new TIPCEvent(this, MONITOR_EVENT_NAME, false);
   FClientEvent = new TIPCEvent(this, CLIENT_EVENT_NAME, false);
   FConnectEvent = new TIPCEvent(this, CONNECT_EVENT_NAME, false);
   FClientDirectory = new TClientDirectory(MAX_CLIENTS);
}

__fastcall TIPCThread::~TIPCThread()
{
   DeActivate();
   delete FClientDirectory;
   delete FClientEvent;
   delete FMonitorEvent;
   FState = stInActive;
#if defined(IPCDEBUG)
   delete FTracer;
#endif
}

/* This procedure is called all over the place to keep track of what is
  going on */

void __fastcall TIPCThread::DbgStr(const AnsiString S)
{
#if defined(IPCDEBUG)
   FTracer->Add(S.c_str());
#endif
}

/* TIPCMonitor */

__fastcall TIPCMonitor::TIPCMonitor(int AID, const AnsiString AName)
                      : TIPCThread(AID, AName),
                        FAutoSwitch(true)

{
}

void __fastcall TIPCMonitor::Activate()
{
   if (FState == stInActive) {
    // Put the monitor handle into the client directory so we can use it to
    //  prevent multiple monitors from running
    if (FClientDirectory->MonitorID == 0)
      FClientDirectory->MonitorID = FID;
    else
        throw EMonitorActive("Monitor is already active.");
    FState = stDisconnected;
    Resume();
   }
}

void __fastcall TIPCMonitor::DeActivate()
{
   if ((State != stInActive) && !(Suspended)){
    FClientDirectory->MonitorID = 0;
    FMonitorEvent->Signal(evMonitorExit);
    if (WaitForSingleObject((void *)Handle, TIMEOUT) != WAIT_OBJECT_0)
        TerminateThread((void *)Handle, 0);
   }
}

/* This method, and the TIPCClient.Execute method represent the meat of this
  program.  These two thread handlers are responsible for communcation with
  each other through the IPC event classes */

void __fastcall TIPCMonitor::Execute()
{
   int WaitResult;
   bool bContinueThread = true;
   DbgStr(FName + " Activated");

   if (FClientDirectory->Count > 0)
     FMonitorEvent->SignalID(evClientStart, FClientDirectory->Last());
   while (bContinueThread == true){
    try {
      WaitResult = WaitForSingleObject(FMonitorEvent->Handle, INFINITE);
      if (WaitResult >= WAIT_ABANDONED)
            DisconnectFromClient(false);
      else{
        if (WaitResult == WAIT_OBJECT_0)
        {
          DbgStr("Event Signaled: " + EventName(FMonitorEvent->Kind));
          switch (FMonitorEvent->Kind){
            case evClientSignal:
              DoOnSignal();
              break;
            case evClientStart:
              if ((AutoSwitch == true) || (FClientID == 0))
                ConnectToClient(FMonitorEvent->ID);
              DoOnDirUpdate();
              break;
            case evClientStop:
              DoOnDirUpdate();
              break;
            case evClientDetach:
              DisconnectFromClient(false);
              Sleep(100);
              if (AutoSwitch != false)
                ConnectToClient(FClientDirectory->Last());
              break;
            case evClientSwitch:
              ConnectToClient(FMonitorEvent->ID);
              break;
            case evMonitorExit:
              DisconnectFromClient(false);
              bContinueThread = false;
              break;
            default:
              break;
          } //end switch
        } //end if
        else {
          DbgStr(Format("Unexpected Wait Return Code: %d",
                        ARRAYOFCONST((WaitResult))));
        } //end else
      } //end else
    } //end try
    catch(Exception& E){
      DbgStr(Format("Exception raised in Thread Handler: %s at %X",
                    ARRAYOFCONST((E.Message, ExceptAddr))));
    } //end catch
   }//end while
   FState = stInActive;
   DbgStr("Thread Handler Exited");
}

void __fastcall TIPCMonitor::ConnectToClient(int ID)
{
   if (ID == FClientID) return;
   if (FState == stConnected)
      DisconnectFromClient(true);
   if (ID == 0) return;
   DbgStr(Format("Sending evMonitorAttach: %X",
                ARRAYOFCONST((ID))));

   /* Tell a client we want to attach to them */
   FConnectEvent->SignalID(evMonitorAttach, ID);

   /* Wait for the client to say "OK" */
   if ((FMonitorEvent->WaitFor(TIMEOUT, ID, evClientAttach) != false) &&
     (FMonitorEvent->Data.Flag == cfAttach)) {
      FClientID = ID;
      FState = stConnected;
      if (FOnConnect != NULL)
        OnConnect(this, true);
      DbgStr("ConnectToClient Successful");
  }
  else
      DbgStr("ConnectToClient Failed: " + EventName(FMonitorEvent->Kind));
}

/* If Wait is true ... */

void __fastcall TIPCMonitor::DisconnectFromClient(bool Wait)
{
   if (FState == stConnected){
    DbgStr(Format("Sending evMonitorDetach: %x",
                  ARRAYOFCONST((FClientID))));

    /* Tell the client we are detaching */
    FClientEvent->SignalID(evMonitorDetach, FClientID);

    /* If we (the monitor) initiated the detach process, then wait around
      for the client to acknowledge the detach, otherwise, just continue on */
    if (Wait)
      if (FMonitorEvent->WaitFor(TIMEOUT, FClientID, evClientDetach) == 0){
        DbgStr(Format("Error waiting for client to detach: %x",
                      ARRAYOFCONST((FClientID))));
        FClientDirectory->RemoveClient(FClientID);
      }
    FClientID = 0;
    FState = stDisconnected;
    if (FOnConnect != 0)
      FOnConnect(this, false);

    if ((! Wait) && (FOnDirUpdate != NULL))
      DoOnDirUpdate();
    }
}

/* This method is called when the client has new data for us */

void __fastcall TIPCMonitor::DoOnSignal(void)
{
   if ((FOnSignal != NULL) && (FMonitorEvent->ID == FClientID))
     FOnSignal(this, FMonitorEvent->Data);
}

/* Tell the client we have new flags for it */

void __fastcall TIPCMonitor::SignalClient(const TClientFlags Value)
{
   if (FState == stConnected){
      FClientEvent->EventInfo->FData.Flags = Value;
      DbgStr("Signaling Client");
      FClientEvent->SignalData(evMonitorSignal, FClientID, FClientEvent->Data);
   }
}

AnsiString __fastcall TIPCMonitor::GetClientName()
{
   return FClientDirectory->Name[FClientID];
}

void __fastcall TIPCMonitor::GetClientNames(TStringList* List)
{
   int  I;
   AnsiString  S;
   int  DupCnt;

   List->BeginUpdate();
   try{
    List->Clear();
    for(I=0; I < FClientDirectory->Count; I++){
      S = FClientDirectory->ClientRec[I].Name;
      DupCnt = 1;

      /* Number duplicate names so we can distinguish them in the client menu */
      while(List->IndexOf(S) > -1){
           DupCnt++;
           S = Format("%s (%d)",
                      ARRAYOFCONST((FClientDirectory->ClientRec[I].Name,
                                    DupCnt)));
      }
      List->AddObject(S, (TObject*)FClientDirectory->ClientRec[I].ID);
    }
   }
   catch(...){
    List->EndUpdate();
    throw;
   }
   List->EndUpdate();
}

void __fastcall TIPCMonitor::SetCurrentClient(int ID)
{
   if (ID == 0)
     ID = FClientDirectory->Last();
   if (ID !=0)
     FMonitorEvent->SignalID(evClientSwitch, ID);
}

void __fastcall TIPCMonitor::ClearDebugInfo()
{
#ifdef IPCDEBUG
   FTracer->Clear();
#endif
}

void __fastcall TIPCMonitor::GetDebugInfo(TStrings *List)
{
#ifdef IPCDEBUG
   FTracer->GetList(List);
#else
   List->Add("Debug Tracing Disabled");
#endif
}

void __fastcall TIPCMonitor::SaveDebugInfo(const AnsiString FileName)
{
#if defined(IPCDEBUG)
   TStringList*  List;

   List = new TStringList();
   try{
      GetDebugInfo(List);
      List->SaveToFile(FileName);
   }
   catch(...){
      delete List;
      throw;
   }
   delete List;
#endif
}

void __fastcall TIPCMonitor::DoOnDirUpdate()
{
   if (FOnDirUpdate != NULL)
     FOnDirUpdate(this);
}

/* TIPCClient */

void __fastcall TIPCClient::Activate()
{
   if (FState == stInActive){
     FWaitEvent = FConnectEvent;
     FMonitorEvent->OwnerID = FID;
     FConnectEvent->OwnerID = FID;
     FClientEvent->OwnerID = FID;
     FClientDirectory->AddClient(FID, FName);
     FState = stDisconnected;
     Resume();
   }
}

void __fastcall TIPCClient::DeActivate()
{
   if (FClientDirectory != NULL)
     FClientDirectory->RemoveClient(FID);
   if ((FState != stInActive) && !(Suspended)){
      FWaitEvent->Signal(evClientExit);
      if (WaitForSingleObject((void *)Handle, TIMEOUT) != WAIT_OBJECT_0)
        TerminateThread((void *)Handle, 0);
    }
}

void __fastcall TIPCClient::Execute(void)
{
   DbgStr(FName + " Activated");
   bool bContinueThread = true;

   if ((FClientDirectory->MonitorID) != 0)
    {
      FMonitorEvent->SignalID(evClientStart, FID);
    }
   while (bContinueThread == true){
    try{
      if (WaitForSingleObject(FWaitEvent->Handle, INFINITE) != WAIT_OBJECT_0)
        break;
      if (FWaitEvent->ID != FID){
        Sleep(200);
        continue;
      }
      DbgStr("Client Event Signaled: " + EventName(FWaitEvent->Kind));
      switch(FWaitEvent->Kind){
        case evMonitorSignal:
          if (FOnSignal != NULL)
            FOnSignal(this, FWaitEvent->Data);
          break;
        case evMonitorAttach:
          ConnectToMonitor();
          break;
        case evMonitorDetach:
          DisconnectFromMonitor(false);
          Sleep(200);
          break;
        case evClientExit:
          if (FClientDirectory->MonitorID != 0) {
            if (FState == stConnected)
              DisconnectFromMonitor(true);
            else
              FMonitorEvent->Signal(evClientStop);
          }
          bContinueThread = false;
          break;
        default:
          break;
      } //end switch
    } //end try
    catch(Exception& E){
      DbgStr(Format("Exception raised in Thread Handler: %s at %X",
                    ARRAYOFCONST((E.Message, ExceptAddr))));
    }//end try-catch
   } //end while
   FState = stInActive;
   DbgStr("Thread Handler Exited");
}

void __fastcall TIPCClient::ConnectToMonitor()
{
   TEventData Data;
   DbgStr("ConnectToMonitor Begin");
   FConnectEvent->Reset();
   try {
     FState = stConnected;
     FWaitEvent = FClientEvent;
     Data.Flag = cfAttach;
     FMonitorEvent->SignalData(evClientAttach, FID, Data);
     if (FOnConnect != 0)
       FOnConnect(this, true);
   }
   catch(Exception& E){
     DbgStr("Exception in ConnectToMonitor: " + E.Message);
     Data.Flag = cfError;
     FMonitorEvent->SignalData(evClientAttach, FID, Data);
   }
   DbgStr("ConnectToMonitor End");
}

void __fastcall TIPCClient::DisconnectFromMonitor(bool Wait)
{
   DbgStr("DisconnectFromMonitor Begin");
   if (FState == stConnected) {
     if (Wait){
       DbgStr("Sending evClientDetach");
       FMonitorEvent->Signal(evClientDetach);
       if (FClientEvent->WaitFor(TIMEOUT, FID, evMonitorDetach))
         DbgStr("Got evMonitorDetach");
       else
         DbgStr("Error waiting for evMonitorDetach");
     }
     FState = stDisconnected;
     FWaitEvent = FConnectEvent;
     if (! Wait){
       DbgStr("DisconnectFromMonitor sending evClientDetach");
       FMonitorEvent->Signal(evClientDetach);
     }
     if (FOnConnect != NULL)
       FOnConnect((TIPCThread*)this, false);
   }
   DbgStr("DisconnectFromMonitor End");
}

void __fastcall TIPCClient::SignalMonitor(const TEventData& Data)
{
   if (FState == stConnected){
     DbgStr("Signaling Monitor");
     FMonitorEvent->SignalData(evClientSignal, FID, Data);
   }
}

int __fastcall TIPCClient::ClientCount()
{
   return FClientDirectory->Count;
}

void __fastcall TIPCClient::MakeCurrent()
{
   FMonitorEvent->SignalID(evClientStart, FID);
}

