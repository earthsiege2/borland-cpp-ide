#include <vcl.h>
#pragma hdrstop

#include "VersionInfoComponent.h"

#include <Dialogs.Hpp>
#include <shellapi.h>

#define NDEBUG
#include <cassert>

#pragma package(smart_init)

//---------------------------------------------------------------------------
// ValidCtrCheck is used to assure that the components created do not have
// any pure virtual functions.
//

static inline void ValidCtrCheck(TVersionInfo *)
{
  new TVersionInfo(NULL);
}

//---------------------------------------------------------------------------

// Definition of the design-time hook
// declared in our header.
TDesignTimeHook DesignTimeHook;

//---------------------------------------------------------------------------

// Component constructor with a funny side-effect at design-time:
// If the component is dropped onto a form and if
// the CURRENT project does not yet have the VERSIONINFO
// box checked, it can be checked (after asking)
__fastcall TVersionInfo::TVersionInfo(TComponent* Owner)
  : TComponent(Owner)
{
  if (ComponentState.Contains(csDesigning))
  {
    if ((Owner != 0) && !Owner->ComponentState.Contains(csLoading))
    {
      // Do the design-time "enable the VERSIONINFO thing" stuff.
      // This is a bit convoluted just to decouple the design-time
      // and runtime code as much as possible.
      if (DesignTimeHook != NULL)
        DesignTimeHook();
    }
  }

  FLanguageCharsetIndex = -1;
  FTranslations = new TStringList();

  FUiElements = new TList();
}

// Pretty much a standard destructor.
__fastcall TVersionInfo::~TVersionInfo(void)
{
  if (FUiElements != NULL)
    FUiElements->Clear();

  FreeVersionInfoMemory();

  delete FTranslations;
  FTranslations = NULL;

  delete FUiElements;
  FUiElements = NULL;
}

String __fastcall TVersionInfo::BuildStringFileInfo(const AnsiString& StringName) const
{
  assert(FTranslations != NULL);

  assert(FTranslations->Count > 0);
  assert(FLanguageCharsetIndex < FTranslations->Count);

  return "\\StringFileInfo\\" + FTranslations->Strings[FLanguageCharsetIndex] + "\\" + StringName;
}

void __fastcall TVersionInfo::ClearVersionInfoData(void)
{
  FHasVersionInfo = false;

  FLanguageCharsetIndex = -1;

  assert(FTranslations != NULL);
  FTranslations->Clear();

  memset(&FFixedFileInfo, 0, sizeof(FFixedFileInfo));
}

void __fastcall TVersionInfo::DoChanged(void)
{
  TCMVersionInfoComponent NotificationMessage = { };

  NotificationMessage.Msg = CM_VERSIONINFOCHANGE;
  NotificationMessage.Component = this;

  for (int i = 0; i < FUiElements->Count; ++i)
  {
    TObject* AnUiElement;

    // Trick: Since in our UI elements the message map as implemented
    //        through the overridden Dispatch method is not public,
    //        we down-cast to a descendant (TObject) where Dispatch is
    //        public and then call Dispatch.
    //        This technique works because Dispatch is virtual.
    AnUiElement = static_cast<TObject*>(FUiElements->Items[i]);
    assert(AnUiElement != NULL);
    AnUiElement->Dispatch(&NotificationMessage);
  }

  if (FOnChange != NULL)
  {
    FOnChange(this);
  }
}

void __fastcall TVersionInfo::FreeVersionInfoMemory(void)
{
  // Clean up any memory that might still be allocated.
  if (FFileVersionInfoData != NULL)
  {
    delete [](FFileVersionInfoData);
    FFileVersionInfoData = NULL;
  }
}

void __fastcall TVersionInfo::CMVersionInfoUiAttach(TCMVersionInfoUi& Message)
{
  int Index;

  Index = FUiElements->IndexOf(Message.UiElement);
  if ((Index < 0) && (Message.UiElement != NULL))
  {
    FUiElements->Add(Message.UiElement);
  }
}

void __fastcall TVersionInfo::CMVersionInfoUiDetach(TCMVersionInfoUi& Message)
{
  int Index;

  Index = FUiElements->IndexOf(Message.UiElement);
  if (Index >= 0)
  {
    FUiElements->Delete(Index);
  }
}

void __fastcall TVersionInfo::InitializeFixedFileInfoField(void)
{
  LPVOID Buffer;
  UINT BufferLength;

  Win32Check( VerQueryValue(FFileVersionInfoData, "\\", &Buffer, &BufferLength) );

  assert(BufferLength != 0);
  assert(BufferLength == sizeof(FFixedFileInfo));

  memmove(&FFixedFileInfo, Buffer, BufferLength);
}

void __fastcall TVersionInfo::InitializeTranslationTable(void)
{
  #pragma pack(push, 1)
    union TTranslationTableEntry
    {
      struct struct_Codes
      {
        WORD LanguageCode;
        WORD CharsetCode;
      } Codes;

      DWORD RawData;
    };
  #pragma pack(pop)

  TTranslationTableEntry* ATranslationTableEntry;
  unsigned int BufferLength;

  String TempString;

  QueryValue("\\VarFileInfo\\Translation", static_cast<void*>(ATranslationTableEntry), BufferLength);

  // We assume that the translation table is stored correctly;
  // the operating system provides no other means to retrieve
  // the count of items, so dividing table size by
  // sizeof(table entry) is the only means to achieve this.
  assert(BufferLength % sizeof(TTranslationTableEntry) == 0);

  while (BufferLength != 0)
  {
    TempString = "";
    TempString.printf("%.4X%.4X", ATranslationTableEntry->Codes.LanguageCode,
                                  ATranslationTableEntry->Codes.CharsetCode);

    FTranslations->AddObject(TempString, reinterpret_cast<TObject*>(ATranslationTableEntry->RawData));

    ATranslationTableEntry++;
    BufferLength = BufferLength - sizeof(TTranslationTableEntry);
  }

  if ((FTranslations->Count == 0) && FHasVersionInfo)
  {
    // Interestingly, there was *NO* translation
    // data stored inside the buffer - for whatever
    // reason there might be.
    // The operating system mandates a language-charset
    // identifier, though, when it comes to querying
    // for string data.
    // Resolution: create a fake entry which is
    //             language-neutral and which uses
    //             the Unicode charset.

    TTranslationTableEntry TranslationCode;
    TranslationCode.Codes.LanguageCode = MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL);
    TranslationCode.Codes.CharsetCode = 0x04b0; // Unicode

    TempString = "";
    TempString.printf("%.4X%.4X", TranslationCode.Codes.LanguageCode,
                                  TranslationCode.Codes.CharsetCode );

    FTranslations->AddObject(TempString, reinterpret_cast<TObject*>(TranslationCode.RawData));
  }

  // By default pick the first language-charset entry
  // for display / analysis.
  FLanguageCharsetIndex = 0;
}

bool __fastcall TVersionInfo::GetIsDebugBuild(void) const
{
  return ((FFixedFileInfo.dwFileFlags & VS_FF_DEBUG) == VS_FF_DEBUG);
}

bool __fastcall TVersionInfo::GetIsDll(void) const
{
  return ((FFixedFileInfo.dwFileType & VFT_DLL) == VFT_DLL);
}

bool __fastcall TVersionInfo::GetIsPatched(void) const
{
  return ((FFixedFileInfo.dwFileFlags & VS_FF_PATCHED) == VS_FF_PATCHED);
}

bool __fastcall TVersionInfo::GetIsPreRelease(void) const
{
  return ((FFixedFileInfo.dwFileFlags & VS_FF_PRERELEASE) == VS_FF_PRERELEASE);
}

bool __fastcall TVersionInfo::GetIsPrivateBuild(void) const
{
  return ((FFixedFileInfo.dwFileFlags & VS_FF_PRIVATEBUILD) == VS_FF_PRIVATEBUILD);
}

bool __fastcall TVersionInfo::GetIsSpecialBuild(void) const
{
  return ((FFixedFileInfo.dwFileFlags & VS_FF_SPECIALBUILD) == VS_FF_SPECIALBUILD);
}

DWORD __fastcall TVersionInfo::GetFileVersionMajor(void) const
{
  return HIWORD(FileVersionMS);
}

DWORD __fastcall TVersionInfo::GetFileVersionMinor(void) const
{
  return LOWORD(FileVersionMS);
}

DWORD __fastcall TVersionInfo::GetFileVersionRelease(void) const
{
  return HIWORD(FileVersionLS);
}

DWORD __fastcall TVersionInfo::GetFileVersionBuild(void) const
{
  return LOWORD(FileVersionLS);
}

DWORD __fastcall TVersionInfo::GetProductVersionMajor(void) const
{
  return HIWORD(ProductVersionMS);
}

DWORD __fastcall TVersionInfo::GetProductVersionMinor(void) const
{
  return LOWORD(ProductVersionMS);
}

DWORD __fastcall TVersionInfo::GetProductVersionRelease(void) const
{
  return HIWORD(ProductVersionLS);
}

DWORD __fastcall TVersionInfo::GetProductVersionBuild(void) const
{
  return LOWORD(ProductVersionLS);
}

#pragma pack(push, 1)
  union TInt64Merger
  {
    struct struct_HiLo
    {
      DWORD Hi;
      DWORD Lo;
    } HiLo;

    __int64 Int64;
  };
#pragma pack(pop)

__int64 __fastcall TVersionInfo::GetRawFileVersion(void) const
{
  TInt64Merger Merger;

  Merger.HiLo.Hi = FileVersionMS;
  Merger.HiLo.Lo = FileVersionLS;

  return Merger.Int64;
}

__int64 __fastcall TVersionInfo::GetRawProductVersion(void) const
{
  TInt64Merger Merger;

  Merger.HiLo.Hi = ProductVersionMS;
  Merger.HiLo.Lo = ProductVersionLS;

  return Merger.Int64;
}

FILETIME __fastcall TVersionInfo::GetRawFileDate(void) const
{
  FILETIME Result;

  Result.dwHighDateTime = FFixedFileInfo.dwFileDateMS;
  Result.dwLowDateTime = FFixedFileInfo.dwFileDateLS;

  return Result;
}

TDateTime __fastcall TVersionInfo::GetFileDate(void) const
{
  FILETIME AFileTime;
  SYSTEMTIME ASystemTime;

  // The FILETIME structure is a 64-bit value representing the
  // number of 100-nanosecond intervals since January 1, 1601.
  //
  //   We need to convert this to a TDateTime double value:
  //
  // The integral part of a TDateTime value is the number of days
  // that have passed since 12/30/1899. The fractional part of a
  // TDateTime value is the time of day.

  AFileTime = GetRawFileDate();

  Win32Check( FileTimeToSystemTime(&AFileTime, &ASystemTime) );

  return SystemTimeToDateTime(ASystemTime);
}

String __fastcall TVersionInfo::GetComments(void) const
{
  return QueryStringValue("Comments");
}

String __fastcall TVersionInfo::GetCompanyName(void) const
{
  return QueryStringValue("CompanyName");
}

String __fastcall TVersionInfo::GetFileDescription(void) const
{
  return QueryStringValue("FileDescription");
}

String __fastcall TVersionInfo::GetFileVersion(void) const
{
  return QueryStringValue("FileVersion");
}

String __fastcall TVersionInfo::GetInternalName(void) const
{
  return QueryStringValue("InternalName");
}

String __fastcall TVersionInfo::GetLegalCopyright(void) const
{
  return QueryStringValue("LegalCopyright");
}

String __fastcall TVersionInfo::GetLegalTrademarks(void) const
{
  return QueryStringValue("LegalTrademarks");
}

String __fastcall TVersionInfo::GetOriginalFileName(void) const
{
  return QueryStringValue("OriginalFileName");
}

String __fastcall TVersionInfo::GetProductName(void) const
{
  return QueryStringValue("ProductName");
}

String __fastcall TVersionInfo::GetProductVersion(void) const
{
  return QueryStringValue("ProductVersion");
}

bool __fastcall TVersionInfo::QueryValue(const AnsiString& SubBlock, LPVOID& Buffer,
  unsigned int& BufferLength) const
{
  assert(FFileVersionInfoData != NULL);

  return VerQueryValue(FFileVersionInfoData, SubBlock.c_str(), &Buffer, &BufferLength);
}

String __fastcall TVersionInfo::QueryStringValue(const AnsiString& SubBlock) const
{
  String ResultString;
  char* StringBuffer;
  unsigned int BufferLength;

  if (FEnabled && FHasVersionInfo)
  {
    if (QueryValue(BuildStringFileInfo(SubBlock), static_cast<void*>(StringBuffer), BufferLength))
    {
      assert(BufferLength != 0);

      ResultString = StringBuffer;
    }
    else
    {
      ResultString = "";
    }
  }
  else
  {
    ResultString = "";
  }
  return ResultString;
}

// Read VERSIONINFO data from the file referred to
// by the "FileName" property.
void __fastcall TVersionInfo::ReadVersionInfoFromFile(void)
{
  String VersionInfoFileName;
  DWORD FileVersionInfoSize;
  DWORD OldErrorMode;
  DWORD LastErrorCode;
  DWORD ApiResult;
  DWORD DummyDWORD;

  if (FFileName.Length() == 0)
  {
    // No file name is defined
    // -> current binary is VERSIONINFO container.
    VersionInfoFileName = Application->ExeName;

    // If there is no application ExeName
    // we are inside a DLL. Query the DLL.
    if (VersionInfoFileName.Length() == 0)
      VersionInfoFileName = GetCurrentModuleFileName();
  }
  else
  {
    // Use the pre-defined file name.
    VersionInfoFileName = FFileName;
  }

  // Assume that no VERSIONINFO is present.
  FHasVersionInfo = false;

  ClearVersionInfoData();

  // Setting the error mode guarantees that the
  // pesky "File <this or that> could not be found"
  // dialog is not shown.
  OldErrorMode = SetErrorMode(SEM_NOOPENFILEERRORBOX | SEM_FAILCRITICALERRORS);
  try
  {
    if (!FileExists(VersionInfoFileName))
    {
      return;
    }

    // We only support 32 bit files, so test
    // the EXE file type.
    // Alert: NT 3.x is not supported.
    SHFILEINFO FileInfo;
    ApiResult = SHGetFileInfo(VersionInfoFileName.c_str(), 0, &FileInfo, sizeof(FileInfo), SHGFI_EXETYPE);

    bool IsWin32Application = false;

    // Check for Win32 console application
    IsWin32Application = (ApiResult == IMAGE_NT_SIGNATURE);

    if (!IsWin32Application)
    {
      if (LOWORD(ApiResult) == LOWORD(IMAGE_NT_SIGNATURE))
      {
        if ( (HIWORD(ApiResult) == 0x0400) ||  // 4.0
             (HIWORD(ApiResult) == 0x0305) ||  // 3.5
             (HIWORD(ApiResult) == 0x3000)     // 3.0
            )
        {
          IsWin32Application = true;
        }
      }
    }
    if (!IsWin32Application)
      return;
  }
  __finally
  {
    SetErrorMode(OldErrorMode);
  }

  // Retrieve file version information based upon
  // component properties.
  FileVersionInfoSize = GetFileVersionInfoSize(VersionInfoFileName.c_str(), &DummyDWORD);
  if (FileVersionInfoSize == 0)
  {
    LastErrorCode = GetLastError();

    // So the API call failed.
    // There are a number of reasons for this happening;
    //
    // a) The specified image file did not contain a
    //    resource section: ERROR_RESOURCE_DATA_NOT_FOUND
    //
    // b) The specified resource type cannot be found
    //    in the image file: ERROR_RESOURCE_TYPE_NOT_FOUND
    //
    // c) The specified resource name cannot
    //    be found in the image file: ERROR_RESOURCE_NAME_NOT_FOUND
    //
    // d) The specified resource language ID cannot be found
    //    in the image file: ERROR_RESOURCE_LANG_NOT_FOUND

    switch (LastErrorCode)
    {
      case ERROR_RESOURCE_DATA_NOT_FOUND:
      case ERROR_RESOURCE_TYPE_NOT_FOUND:
      case ERROR_RESOURCE_NAME_NOT_FOUND:
      case ERROR_RESOURCE_LANG_NOT_FOUND:
      {
        // We just ignore foreseeable problems
        // and exit from this routine.
        return;
      }

      default:
        // We hit none of the known problems, so
        // that's a bit exceptional:
        EWin32Error* Error;
        TVarRec Params[] = { int(LastErrorCode), SysErrorMessage(LastErrorCode) };

        Error = new EWin32Error(Sysconst_SWin32Error, Params, ARRAYSIZE(Params) - 1 );
        Error->ErrorCode = LastErrorCode;

        throw *Error;
    }
  }

  // Zero out all data - and immediately allocate new memory
  // to store the VERSIONINFO data in.
  // Note: FreeVersionInfoMemory() handles the situation where
  //       no memory was allocated gracefully.
  FreeVersionInfoMemory();
  FFileVersionInfoData = new char [FileVersionInfoSize];

  // Get VERSIONINFO data.
  Win32Check( GetFileVersionInfo(VersionInfoFileName.c_str(), 0, FileVersionInfoSize, FFileVersionInfoData) );

  // Initial processing...
  InitializeFixedFileInfoField();
  InitializeTranslationTable();

  // ...and if we made it down here, we definitely
  // do have VERSIONINFO in that binary.
  FHasVersionInfo = true;
}

// Property setter for the "FileName" property.
void __fastcall TVersionInfo::SetFileName(const String& AFileName)
{
  // Remove all white space from any file name.
  FFileName = Trim(AFileName);

  if (FEnabled)
    ReadVersionInfoFromFile();

  DoChanged();
}

// Property setter for the "Enabled" property.
void __fastcall TVersionInfo::SetEnabled(const bool Value)
{
  // Only update the state if it is actually changed.
  if (Value != FEnabled)
  {
    FEnabled = Value;

    if (FEnabled)
      ReadVersionInfoFromFile();
    else
      ClearVersionInfoData();

    DoChanged();
  }
}

String __fastcall TVersionInfo::GetAboutBoxString(void) const
{
  String AboutString;
  String ItemString;

  //
  // Build up a nice-ish looking,
  // default About box string.
  //
  ItemString = ProductName;
  if (ItemString.Length() > 0)
    AboutString += ItemString;

  ItemString = FileVersion;
  if (ItemString.Length() > 0)
  {
    AboutString += "\nVersion: ";
    AboutString += ItemString;
  }

  ItemString = LegalCopyright;
  if (ItemString.Length() > 0)
    AboutString += "\n\n" + ItemString;

  ItemString = LegalTrademarks;
  if (ItemString.Length())
    AboutString += ", " + ItemString;

  ItemString = CompanyName;
  if (ItemString.Length())
    AboutString += "\n\n" + ItemString;

  ItemString = FileDescription;
  if (ItemString.Length())
    AboutString += "\n\n" + ItemString;

  ItemString = Comments;
  if (ItemString.Length())
    AboutString += "\n" + ItemString;

  return AboutString;
}

// Show a default About box.
void __fastcall TVersionInfo::ShowAboutBox(void) const
{
  MessageDlg( GetAboutBoxString(),
              mtInformation,
              TMsgDlgButtons() << mbOK, 0);
}

// Retrieve the file name including fully expanded path of
// the current module (DLL, package, EXE, etc).
String __fastcall TVersionInfo::GetCurrentModuleFileName(void)
{
  String ResultString;
  DWORD ApiResult;

  DWORD BufferSize;

  BufferSize = MAX_PATH;
  while (true)
  {
    // Allocate some memory for the buffer.
    // Note: Resizing an (Ansi)String to do this
    //       is a legitimate technique, although
    //       it is not exactly politically correct.
    ResultString.SetLength(BufferSize);
    ApiResult = GetModuleFileName(HInstance, ResultString.c_str(), BufferSize);

    // ApiResult contains the length of the copied data.
    // If this is less than the buffer size, the buffer
    // was large enough and we are done.
    if (ApiResult < BufferSize)
    {
      // We almost certainly did over-allocate, so trim
      // the amount of memory allocated now.
      ResultString.SetLength(strlen(ResultString.c_str()));

      // Leave "while" loop since we got the data we needed.
      break;
    }
    else
    {
      // Increase buffer size available for retrieving
      // the full module name.
      BufferSize = BufferSize + MAX_PATH;
    }
  }

  return ResultString;
}

// Translate a language code (e.g. 0x0407) into the text
// representation (e.g. "Deutsch (Deutschland)").
String __fastcall TVersionInfo::TranslateVersionLanguageName(DWORD Language)
{
  const int GrowthConstant = 50;

  char* LanguageStringBuffer;
  DWORD BufferSize;

  DWORD ApiResult;

  String ResultString;

  BufferSize = GrowthConstant;
  LanguageStringBuffer = NULL;
  try
  {
    while (true)
    {
      delete[] LanguageStringBuffer;
      LanguageStringBuffer = new char[BufferSize];

      // VerLanguageName returns the MAX of length of bytes required
      // or bytes copied to the string buffer.
      ApiResult = VerLanguageName(Language, LanguageStringBuffer, BufferSize);
      if (ApiResult == 0)
      {
        // If there is an error (signalled by ApiResult == 0),
        // return an empty string. The Windows API documentation
        // does not indicate that there is additional error
        // information that would allow a call to RaiseLastWin32Error()
        // to yield a meaningful result.
        ResultString = "";
        break;
      }
      else
      {
        if (ApiResult > BufferSize-1)
        {
          // Buffer was too small for language name.
          // Increase buffer size and try again.
          BufferSize = BufferSize + GrowthConstant;
        }
        else
        {
          // Successfully retrieved the name...
          ResultString = LanguageStringBuffer;

          // ... so we now may leave the loop.
          break;
        }
      }
    }
  }
  __finally
  {
    delete[] LanguageStringBuffer;
  }

  return ResultString;
}

