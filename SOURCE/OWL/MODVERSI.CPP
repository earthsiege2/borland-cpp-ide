//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.5  $
//
// Implementation of class TModuleVersionInfo, version resource parser &
// accessor class
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/pch.h>
#if !defined(OWL_MODULE_H)
# include <owl/module.h>
#endif
#include <stdio.h>
#if defined(BI_PLAT_WIN16)
# include <ver.h>
#endif

static char viRootStr[] =             "\\";
static char viTransStr[] =            "\\VarFileInfo\\Translation";
static char viSubBlockQueryFmt[] =    "\\StringFileInfo\\%08lx\\%s";
static char viFileDescStr[] =         "FileDescription";
static char viFileVersionStr[] =      "FileVersion";
static char viInternalNameStr[] =     "InternalName";
static char viLegalCopyrightStr[] =   "LegalCopyright";
static char viOriginalFilenameStr[] = "OriginalFilename";
static char viProductNameStr[] =      "ProductName";
static char viProductVersionStr[] =   "ProductVersion";
static char viSpecialBuildStr[] =     "SpecialBuild";

//
// Construct a TModuleVersionInfo given a module or instance handle
//
TModuleVersionInfo::TModuleVersionInfo(TModule::THandle hModule)
:
  Buff(0),
  Lang(0),
  FixedInfo(0)
{
  char    modFName[_MAX_PATH];
  ::GetModuleFileName(hModule, modFName, sizeof modFName);
  ::OemToAnsi(modFName, modFName);

  if (!Init(modFName)) {
    delete Buff;  
    Buff = 0; 
  }
}

//
// Construct a TModuleVersionInfo given a module filename
//
TModuleVersionInfo::TModuleVersionInfo(const char far* modFName)
:
  Buff(0),
  Lang(0),
  FixedInfo(0)
{
  if (!Init(modFName)) {
    delete Buff;    
    Buff = 0; 
  }
}

//
// Internal initialization fills in the data members
//
bool
TModuleVersionInfo::Init(const char far* modFName)
{
  uint32 fvHandle;
  uint32 infoSize = ::GetFileVersionInfoSize((char far*)modFName, &fvHandle);
  if (!infoSize) {  
    long rc;
#if defined(BI_PLAT_WIN16)      
    rc = 0;                     
#else                           
    rc = GetLastError();        
#endif                          
    char buf[10];               
    sprintf(buf, "%ld", rc);    
    TXOwl::Raise(buf);          
  }

  Buff  = new char[uint(infoSize)];
  if (!::GetFileVersionInfo((char far*)modFName, fvHandle, infoSize, Buff))
    return false;

  // Copy string to buffer so if the -dc compiler switch (Put constant
  // strings in code segments) is on, VerQueryValue will work under Win16.
  // This works around a problem in Microsoft's ver.dll which writes to the
  // string pointed to by subBlockName.
  //
  uint    vInfoLen;                 // not really used, but must be passed
#if defined(BI_PLAT_WIN16) && defined(BI_MODEL_LARGE)
  char    subBlockName[sizeof viTransStr + 16];
  strcpy(subBlockName, viRootStr);
#else
  char* subBlockName = viRootStr;
#endif
  if (!::VerQueryValue(Buff, subBlockName, (void far**)&FixedInfo, &vInfoLen))
    return false;

#if defined(BI_PLAT_WIN16) && defined(BI_MODEL_LARGE)
  strcpy(subBlockName, viTransStr);
#else
  subBlockName = viTransStr;
#endif
  uint32 far* trans;
  if (!::VerQueryValue(Buff, subBlockName, (void far**)&trans, &vInfoLen))
    return false;

  // Swap the words so sprintf will print the lang-charset in the correct
  // format.
  //
  Lang = MkUint32(HiUint16(*trans), LoUint16(*trans));

  return true;
}

//
// Clean up the new'd buffer
//
TModuleVersionInfo::~TModuleVersionInfo()
{
  delete[] Buff;
}

//
// Query any given "\StringFileInfo\lang-charset\<str>" version info string
// lang indicates the language translation, may be 0 to signify file default.
//
bool
TModuleVersionInfo::GetInfoString(const char far* str, const char far*& value, uint lang)
{
  uint    vSize;
  char    subBlockName[255];

  sprintf(subBlockName, viSubBlockQueryFmt, lang ? uint32(lang) : Lang, str);
  return Buff ? ::VerQueryValue(Buff, subBlockName, (void far**)&value, &vSize)
              : false;
}

//
// Commonly used, predefined info string queries. Pass requested language thru,
// may be 0 to signify default.
//
bool TModuleVersionInfo::GetFileDescription(const char far*& fileDesc, uint lang)
{
  return GetInfoString(viFileDescStr, fileDesc, lang);
}

//
// Retrieve the file version information in the requested language id.
//
bool
TModuleVersionInfo::GetFileVersion(const char far*& fileVersion, uint lang)
{
  return GetInfoString(viFileVersionStr, fileVersion, lang);
}

//
// Retrieve the internal name of the module.
//
bool
TModuleVersionInfo::GetInternalName(const char far*& internalName, uint lang)
{
  return GetInfoString(viInternalNameStr, internalName, lang);
}

//
// Retrieve the copyright message.
//
bool
TModuleVersionInfo::GetLegalCopyright(const char far*& copyright, uint lang)
{
  return GetInfoString(viLegalCopyrightStr, copyright, lang);
}

//
// Retrieve the original filename.
//
bool
TModuleVersionInfo::GetOriginalFilename(const char far*& originalFilename, uint lang)
{
  return GetInfoString(viOriginalFilenameStr, originalFilename, lang);
}

//
// Retrieve the product name this module is associated with.
//
bool
TModuleVersionInfo::GetProductName(const char far*& prodName, uint lang)
{
  return GetInfoString(viProductNameStr, prodName, lang);
}

//
// Retrieve the version of the product.
//
bool
TModuleVersionInfo::GetProductVersion(const char far*& prodVersion, uint lang)
{
  return GetInfoString(viProductVersionStr, prodVersion, lang);
}

//
// Retrieve the special build number.
//
bool
TModuleVersionInfo::GetSpecialBuild(const char far*& specialBuild, uint lang)
{
  return GetInfoString(viSpecialBuildStr, specialBuild, lang);
}

//
// Get the language name string associated with a language/charset code
//
string
TModuleVersionInfo::GetLanguageName(uint lang)
{
  char langStr[128];
  ::VerLanguageName(uint(lang), langStr, sizeof langStr);

  return string(langStr);
}

// returns values of TFileType if GetFileType() returned
// DevDriver or Font.
// If GetFileType() returned VirtDriver, this function returns the virtual
// device inentifier included in the virtual device control block.
uint32 TModuleVersionInfo::GetFileSubType() const
{
  uint32 fileSubType = FixedInfo->dwFileSubtype;

  switch (GetFileType()) {
    case DevDriver:
      switch (FixedInfo->dwFileSubtype) {
        case VFT2_UNKNOWN:
          fileSubType = UnknownDevDriver;
          break;
        case VFT2_DRV_PRINTER:
          fileSubType = PtrDriver;
          break;
        case VFT2_DRV_KEYBOARD:
          fileSubType = KybdDriver;
          break;
        case VFT2_DRV_LANGUAGE:
          fileSubType = LangDriver;
          break;
        case VFT2_DRV_DISPLAY:
          fileSubType = DisplayDriver;
          break;
        case VFT2_DRV_MOUSE:
          fileSubType = MouseDriver;
          break;
        case VFT2_DRV_NETWORK:
          fileSubType = NtwkDriver;
          break;
        case VFT2_DRV_SYSTEM:
          fileSubType = SysDriver;
          break;
        case VFT2_DRV_INSTALLABLE:
          fileSubType = InstallableDriver;
          break;
        default: //case VFT2_DRV_SOUND:
          fileSubType = SoundDriver;
      }
      break;
    case Font:
      switch (FixedInfo->dwFileSubtype) {
        case VFT2_UNKNOWN:
          fileSubType = UnknownFont;
          break;
        case VFT2_FONT_RASTER:
          fileSubType = RasterFont;
          break;
        case VFT2_FONT_VECTOR:
          fileSubType = VectorFont;
          break;
        default: //case VFT2_FONT_TRUETYPE:
          fileSubType = TrueTypeFont;
      }
      break;
  }
  return fileSubType;
}

//
//
//
FILETIME TModuleVersionInfo::GetFileDate() const
{
  FILETIME ft = {FixedInfo->dwFileDateLS, FixedInfo->dwFileDateMS};
  return ft;
}

