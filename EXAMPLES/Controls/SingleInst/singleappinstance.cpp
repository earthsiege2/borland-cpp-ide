//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#define NDEBUG
#include <cassert>

#include "SingleAppInstance.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
// ValidCtrCheck is used to assure that the components created do not have
// any pure virtual functions.
//

static inline void ValidCtrCheck(TSingleAppInstance *)
{
  new TSingleAppInstance(NULL);
}

//---------------------------------------------------------------------------


// We introduce a global boolean to serve as
// a marker. If a component is "activated"
// to serve as a single instance guarantee,
// we flag this here.
// This provides a mechanism that prevents
// more than a single component from getting
// active at any time.
// This is extremely important in those cases
// where the user might accidentally instatiate
// a second copy of the component in *the same*
// process.
// Alert: as with all global variables this
//        is NOT thread-safe.
bool SingleAppInstanceComponentActive = false;


//---------------------------------------------------------------------------

void __fastcall TSingleAppInstance::AssertValidMarkerText(const String& Value)
{
  int Len;

  // Note the Windows API documentation:
  // "The name can contain any character except the backslash character (\)"
  Len = Value.Length();
  for (int i = 1; i <= Len; ++i)
  {
    if (Value[i] == '\\')
    {
      throw Exception("A marker may not contain the '\\' character");
    }
  }
}

bool __fastcall TSingleAppInstance::IsValidMarkerText(const String& Value)
{
  int Len;
  bool IsValid;

  // Note the Windows API documentation:
  // "The name can contain any character except the backslash character (\)"
  IsValid = true;

  Len = Value.Length();
  for (int i = 1; i <= Len; ++i)
  {
    if (Value[i] == '\\')
    {
      IsValid = false;
      break;
    }
  }

  return IsValid;
}

String __fastcall TSingleAppInstance::TranslateSlashes(const String& Value)
{
  // Since slashes are not allowed in certain
  // strings (see above), provide an internal
  // mapping that replaces these slashes with
  // something else.
  const char ReplacementCharacter = '_';

  int Len;
  String Result;

  Result = Value;
  Len = Result.Length();

  for (int i = 1; i <= Len; ++i)
  {
    if (Result[i] == '\\')
    {
      Result[i] = ReplacementCharacter;
    }
  }

  return Result;
}

//---------------------------------------------------------------------------

// We are storing some data in the marking
// memory-mapped file. The following struct
// makes the data structure reasonably opaque.
struct MappedData
{
  HANDLE FirstInstanceHandle;
};

typedef MappedData* PMappedData;

//---------------------------------------------------------------------------

__fastcall TSingleAppInstance::TSingleAppInstance(TComponent* Owner)
   : TComponent(Owner)
{
  InitializeCriticalSection(&FWndProcCriticalSection);

  FHiddenWindow = AllocateHWnd(LocalWinProc);

  FPassCommandLine = true;

  // If we are loaded as part of a stream,
  // set Enabled = true - the default streaming
  // value specified in the property declaration.
  //
  // If this is not the case, it is very likely
  // that the user manually instantiates the
  // component. Start disabled then and allow
  // (rather: force) the user to assign events
  // and only then enable the component.
  FEnabled = true;
  FEnabled = (Owner != NULL) &&
             Owner->ComponentState.Contains(csLoading);
}

__fastcall TSingleAppInstance::~TSingleAppInstance(void)
{
  ReleaseInternalMapFile();

  DeleteCriticalSection(&FWndProcCriticalSection);

  DeallocateHWnd(FHiddenWindow);
  FHiddenWindow = INVALID_HANDLE_VALUE;

  delete[] FPassedCommandLine;
  FPassedCommandLine = NULL;
}

void __fastcall TSingleAppInstance::DoOnSecondInstance(bool& DoTerminate)
{
  if (FOnSecondInstance != NULL)
    FOnSecondInstance(this, DoTerminate);
}

void __fastcall TSingleAppInstance::Loaded(void)
{
  inherited::Loaded();

  if (!ComponentState.Contains(csDesigning))
  {
    if (SingleAppInstanceComponentActive)
    {
      // In case an instance is already active,
      // we simply unconditionally set FEnabled
      // to false. 
      if (FEnabled)
        FEnabled = false;
    }
    else
    {
      PerformSingletonCode();
    }
  }
}

void __fastcall TSingleAppInstance::LocalWinProc(Messages::TMessage &Message)
{
  if (Message.Msg != WM_COPYDATA)
  {
    Message.Result = DefWindowProc(FHiddenWindow, Message.Msg, Message.WParam, Message.LParam);
  }
  else
  {
    DWORD CountData;
    PCOPYDATASTRUCT PassedCopyDataStruct;

    // We need to be left alone for a moment,
    // so lock everyone out of this code sequence.
    //
    // Design issue:
    //
    // This piece of code will BLOCK the SENDING
    // application until we have made our call
    // to ReplyMessage below.
    // This means that if multiple "single-instance"
    // processes are launched roughly at the same
    // time ALL these processes will block at the
    // same time.
    // The provided critical section should guarantee,
    // though, that we have a nice, serialized access.
    // (no mutex, since we stay inside the same process)
    EnterCriticalSection(&FWndProcCriticalSection);
    try
    {

      if (FPassedCommandLine != NULL)
      {
        delete[] FPassedCommandLine;
        FPassedCommandLine = NULL;
      }

      assert(Message.LParam != NULL);

      PassedCopyDataStruct = reinterpret_cast<COPYDATASTRUCT*>(Message.LParam);
      // We copy the passed command-line to a local
      // buffer in order to be able to return to the
      // calling application as soon as possible,
      // without it waiting for us to process the data.
      CountData = PassedCopyDataStruct->cbData;
      if (CountData > 0)
      {
        FPassedCommandLine = new char[CountData];

        if (PassedCopyDataStruct->lpData != NULL)
          memmove(FPassedCommandLine, PassedCopyDataStruct->lpData, CountData);
      }

      FPassedData = PassedCopyDataStruct->dwData;

      // Fine, so we have the data let the other process
      // off the SendMessage "hook" (metaphorically speaking).
      Win32Check( ReplyMessage(true) );

      DoReceiveCommandLine(FPassedCommandLine);
    }
    __finally
    {
      LeaveCriticalSection(&FWndProcCriticalSection);
    }
  }
}

void __fastcall TSingleAppInstance::DoReceiveCommandLine(const char * const CommandLine)
{
  if (FOnReceiveCommandLine != NULL)
  {
    FOnReceiveCommandLine(this, FPassedCommandLine);
  }
}

// Return true if the memory mapped file was successfully created;
// false if this was not done.
bool __fastcall TSingleAppInstance::CreateInternalMapFile(void)
{
  LPVOID MapView;
  bool CreateResult;
  DWORD LastErrorCode;

  CreateResult = false;

  assert(FMappingObject == NULL);

  FMappingObject = CreateFileMapping( reinterpret_cast<HANDLE>(0xFFFFFFFF), NULL,
                                      PAGE_READWRITE | SEC_COMMIT,
                                      0, sizeof(MappedData),
                                      FMarker.c_str() );

  if (FMappingObject == NULL)
    RaiseLastWin32Error();

  LastErrorCode = GetLastError();
  if (LastErrorCode == ERROR_ALREADY_EXISTS)
  {
    // Whoops. Somebody already has created this memory mapped file.
    // Do nothing; CreateResult has the right value
    // already and will signal that the memory mapped file
    // (and thus the marker) already existed.

    // TODO: Is this the right thing to do? Return with false? Or throw an exception?

  }
  else
  {
    MapView = MapViewOfFile(FMappingObject, FILE_MAP_ALL_ACCESS, 0, 0, 0);
    if (MapView == NULL)
      RaiseLastWin32Error();
    try
    {
      assert(FHiddenWindow != INVALID_HANDLE_VALUE);


      static_cast<PMappedData>(MapView)->FirstInstanceHandle = FHiddenWindow;
    }
    __finally
    {
      Win32Check( UnmapViewOfFile(MapView) );
    }
    CreateResult = true;
  }

  return CreateResult;
}

void __fastcall TSingleAppInstance::ReleaseInternalMapFile(void)
{
  if (FMappingObject != NULL)
  {
    Win32Check( CloseHandle(FMappingObject) );
    FMappingObject = NULL;
  }
}

void __fastcall TSingleAppInstance::PerformSingletonCode(void)
{
  if (FEnabled)
  {
    // It is pretty pointless to have an empty marker.
    // Use a default marker (i.e. the name of the executable)
    // if we are in dire need of one.
    if (FMarker.Length() == 0)
    {
      // Note that we have to translate backslashes ('\')
      // into something else (here: underscores ('_'))
      // as the Windows API does not allow names for
      // memory mapped files that contain backslashes.
      // And we use the creating process's name
      // as the "default" marker which definitely does
      // contain backslashes.
      SetMarker(TranslateSlashes(ParamStr(0)));
    }

    if (CreateInternalMapFile())
    {
      SingleAppInstanceComponentActive = true;
    }
    else
    {
      // The memory mapped file already existed.
      TakeSecondInstanceAction();
    }
  }
  else
  {
    ReleaseInternalMapFile();
  }
}

void __fastcall TSingleAppInstance::PassThisInstanceCommandLine(void)
{
  HANDLE FileMapping;
  LPVOID MapView;

  HANDLE FirstInstance;

  // Before sending over the command line, we need to
  // retrieve the handle from the present memory-mapped
  // file.
  FileMapping = OpenFileMapping(FILE_MAP_READ, false, FMarker.c_str());

  if (FileMapping == NULL)
    RaiseLastWin32Error();

  try
  {
    MapView = MapViewOfFile(FileMapping, FILE_MAP_READ, 0, 0, 0);

    if (MapView == NULL)
      RaiseLastWin32Error();

    try
    {
      FirstInstance = static_cast<PMappedData>(MapView)->FirstInstanceHandle;
    }
    __finally
    {
      Win32Check( UnmapViewOfFile(MapView) );
    }
  }
  __finally
  {
    Win32Check( CloseHandle(FileMapping) );
  }

  // Now we pass on our command-line. Note that we must
  // use SendMessage in combination with WM_COPYDATA; only
  // then does the Win32 kernel marshal the data across
  // process boundaries.

  COPYDATASTRUCT CopyData = { 0, strlen(CmdLine) + sizeof(char), CmdLine };

  // We don't bother about a return value...
  SendMessage( FirstInstance, WM_COPYDATA,
               reinterpret_cast<WPARAM>(FHiddenWindow),
               reinterpret_cast<LPARAM>(&CopyData));
}

void __fastcall TSingleAppInstance::TakeSecondInstanceAction(void)
{
  bool TerminateApplication;

  // Send command line to other application if this is desired.
  if (FPassCommandLine)
    PassThisInstanceCommandLine();

  // Fire the event for this application, "notifying"
  // it that there is something else.
  // By default, terminate the application.
  TerminateApplication = true;

  if (FOnSecondInstance != NULL)
  {
    FOnSecondInstance(this, TerminateApplication);
  }

  if (TerminateApplication)
    Application->Terminate();
}

void __fastcall TSingleAppInstance::SetEnabled(const bool Value)
{
  if (Value != FEnabled)
  {
    // Is there an attempt to enable a second
    // instance of the component at runtime?
    // We cannot allow this to pass through,
    // as there can be only one entry point
    // for command line parameter messages.
    if (SingleAppInstanceComponentActive &&
        Value /* == true */ &&
        !ComponentState.Contains(csDesigning))
    {
      // TODO: Possibly throw an exception here?
    /*
      AnsiString ExceptionMessage;

      ExceptionMessage.sprintf( "Only one instance of %s may be active at a time",
                                AnsiString(this->ClassName()).c_str() );

      throw Exception(ExceptionMessage);
    */
      return;
    }

    FEnabled = Value;

    // We only react to changes in the Enabled
    // state if
    // a) this happens at runtime (!csDesigning)
    // b) the component data is not streaming
    //    [because for *streaming*, we use the Loaded
    //     method which is a tad bit better.]
    if (!ComponentState.Contains(csDesigning) &&
        !ComponentState.Contains(csReading))
    {
      PerformSingletonCode();
    }
  }
}

void __fastcall TSingleAppInstance::SetMarker(const String Value)
{
  if (Value != FMarker)
  {
    AssertValidMarkerText(Value);

    FMarker = Value;
  }
}


