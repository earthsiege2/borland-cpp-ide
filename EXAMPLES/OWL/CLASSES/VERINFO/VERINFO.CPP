//----------------------------------------------------------------------------
// Owl
// Copyright (c) 1996, 1996 by Borland International, All Rights Reserved
//
// Sample illustrating information obtainable from TModuleVersionInfo
//----------------------------------------------------------------------------
#include <owl/pch.h>

#include <owl/opensave.h>
#include <owl/docview.h>
#include "verinfo.rh"

int PASCAL WinMain(HINSTANCE instance, HINSTANCE, LPSTR, int)
{
  TFileOpenDialog::TData data;
  TFileOpenDialog dlg(0, data);
  if (dlg.DoExecute() != IDOK)
    return 1;

  char msg[2048];
  char* fileOS;
  char* fileType;
  char fileSubType[30];
  char fileDateStr[50];

  char* subTypeStr[] = {"UnknownDriver",
                        "PtrDriver",
                        "KybdDriver",
                        "LangDriver",
                        "DisplayDriver",
                        "MouseDriver",
                        "NtwkDriver",
                        "SysDriver",
                        "InstallableDriver",
                        "SoundDriver",
                        "UnknownFont",
                        "RasterFont",
                        "VectorFont",
                        "TrueTypeFont"};

  try {
    TModuleVersionInfo verInfo(data.FileName);

  switch (verInfo.GetFileOS()) {
    case TModuleVersionInfo::OSUnknown:
      fileOS = "OSUNKNOWN";
      break;
    case TModuleVersionInfo::DOS:
      fileOS = "DOS";
      break;
    case TModuleVersionInfo::OS216:
      fileOS = "OS216";
      break;
    case TModuleVersionInfo::OS232:
      fileOS = "OS232";
      break;
    case TModuleVersionInfo::NT:
      fileOS = "NT";
      break;
    case TModuleVersionInfo::Windows16:
      fileOS = "Windows16";
      break;
    case TModuleVersionInfo::PM16:
      fileOS = "PM16";
      break;
    case TModuleVersionInfo::PM32:
      fileOS = "PM32";
      break;
    case TModuleVersionInfo::Windows32:
      fileOS = "Windows32";
      break;
    case TModuleVersionInfo::DosWindows16:
      fileOS = "DosWindows16";
      break;
    case TModuleVersionInfo::DosWindows32:
      fileOS = "DosWindows32";
      break;
    case TModuleVersionInfo::OS216PM16:
      fileOS = "OS216PM16";
      break;
    case TModuleVersionInfo::OS232PM32:
      fileOS = "OS232PM32";
      break;
    case TModuleVersionInfo::NTWindows32:
      fileOS = "NTWindows32";
      break;
    default:
      fileOS = "";
  }

  switch (verInfo.GetFileType()) {
    case TModuleVersionInfo::TypeUnknown:
      fileType = "TypeUnknown";
      break;
    case TModuleVersionInfo::App:
      fileType = "App";
      break;
    case TModuleVersionInfo::DLL:
      fileType = "DLL";
      break;
    case TModuleVersionInfo::DevDriver:
      fileType = "DevDriver";
      break;
    case TModuleVersionInfo::Font:
      fileType = "Font";
      break;
    case TModuleVersionInfo::VirtDevice:
      fileType = "VirtDevice";
      break;
    case TModuleVersionInfo::StaticLib:
      fileType = "StaticLib";
      break;
    default:
      fileType = "";
  }

  if (verInfo.GetFileType() == TModuleVersionInfo::DevDriver ||
      verInfo.GetFileType() == TModuleVersionInfo::Font)
    strcpy(fileSubType, subTypeStr[(int)verInfo.GetFileSubType()]);
  else
    wsprintf(fileSubType, "%ld", (uint32)verInfo.GetFileSubType());

  FILETIME fileDate = verInfo.GetFileDate();
  if (fileDate.dwLowDateTime || fileDate.dwHighDateTime)
    FormatFileTime(&fileDate, fileDateStr, sizeof (fileDateStr));
  else
    strcpy(fileDateStr, "N/A");

  const char far* fileDesc;
  const char far* fileVersion;
  const char far* internalName;
  const char far* legalCopyright;
  const char far* originalFilename;
  const char far* productName;
  const char far* productVersion;
  const char far* specialBuild;
  if (!verInfo.GetFileDescription(fileDesc))
    fileDesc = "N/A";
  if (!verInfo.GetFileVersion(fileVersion))
    fileVersion = "N/A";
  if (!verInfo.GetInternalName(internalName))
    internalName = "N/A";
  if (!verInfo.GetLegalCopyright(legalCopyright))
    legalCopyright = "N/A";
  if (!verInfo.GetOriginalFilename(originalFilename))
    originalFilename = "N/A";
  if (!verInfo.GetProductName(productName))
    productName = "N/A";
  if (!verInfo.GetProductVersion(productVersion))
    productVersion = "N/A";
  if (!verInfo.GetSpecialBuild(specialBuild))
    specialBuild = "N/A";
  uint lang = verInfo.GetLanguage();

  wsprintf(msg,"Signature                     %lu\n" //uint32
               "Structure Version:            %lu\n" //uint32
               "File Version(Hi 32 bits):     %lu\n" //uint32
               "File Version(Lo 32 bits):     %lu\n" //uint32
               "Product Version (Hi 32 bits): %lu\n" //uint32
               "Product Version (Lo 32 bits): %lu\n" //uint32
               "FileFlagsMask:                %lu\n" //uint32
               "File Flags:                   %lu\n" //uint32
               "Debug:                        %c\n"  //bool->char
               "Inferred Version Information: %c\n"  //bool->char
               "Patched:                      %c\n"  //bool->char
               "Pre-release:                  %c\n"  //bool->char
               "Private Build:                %c\n"  //bool->char
               "Special Build:                %c",   //bool->char
               verInfo.GetSignature(), //uint32
               verInfo.GetStrucVersion(), //uint32
               verInfo.GetFileVersionMS(), //uint32
               verInfo.GetFileVersionLS(), //uint32
               verInfo.GetProductVersionMS(), //uint32
               verInfo.GetProductVersionLS(), //uint32
               verInfo.GetFileFlagsMask(), //uint32
               verInfo.GetFileFlags(), //uint32
               (verInfo.IsDebug())? '1': '0', //bool->char
               (verInfo.InfoInferred())? '1': '0', //bool->char
               (verInfo.IsPatched())? '1': '0', //bool->char
               (verInfo.IsPreRelease())? '1': '0', //bool->char
               (verInfo.IsPrivateBuild())? '1': '0', //bool->char
               (verInfo.IsSpecialBuild())? '1': '0'); //bool->char
  MessageBox(0, msg, "Module Version Info (Page 1 of 2)", MB_OK);

  wsprintf(msg,"File OS:                      %s\n"  //uint32->char*
               "File Type:                    %s\n"  //TModuleVersionInfo::TFileType->char*
               "File Subtype:                 %s\n"  //uint32->char*
               "File Date:                    %s\n"   //FILETIME->char*
               "File Description:             %s\n"
               "File Version String:          %s\n"
               "Internal Name:                %s\n"
               "LegalCopyright:               %s\n"
               "Original Filename:            %s\n"
               "Product Name:                 %s\n"
               "Product Version String:       %s\n"
               "Special Build String:         %s\n"
               "Language:                     %u\n"
               "Language Name:                %s",
               fileOS, //uint32->char*
               fileType, //TModuleVersionInfo::TFileType->char*
               fileSubType, //uint32->char*
               fileDateStr, //FILETIME->char*
               fileDesc,
               fileVersion,
               internalName,
               legalCopyright,
               originalFilename,
               productName,
               productVersion,
               specialBuild,
               lang,
               verInfo.GetLanguageName().c_str());
  MessageBox(0, msg, "Module Version Info (Page 2 of 2)", MB_OK);
  return 0;
  }
  catch (...) {
    char errMsg[200];
    LoadString(instance, IDS_NOSUCHFILE, errMsg, sizeof (errMsg));
    MessageBox(0, errMsg, "VerInfo", MB_OK);
    return 1;
  }
}
