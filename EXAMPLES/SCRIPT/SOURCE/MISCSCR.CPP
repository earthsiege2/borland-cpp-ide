
// Borland C++ - (C) Copyright 1991, 1994 by Borland International

//*******************************************************************
//
// This file contains miscellaneous functionality provided by the 
// Windows API that is exposed to the IDE's scripting system.
//
// It is provided as a demonstraton of how functionality exposed from 
// a DLL can be directly accessed from script.
//
//*******************************************************************
#define STRICT
#include "windows.h"
#include "dir.h"
#include "cstring.h"

// We want our own versions of these not the windows supplied Unicode 
// friendly varients.  
#undef CreateDirectory
#undef RemoveDirectory
#undef FindFirstFile
#undef FindNextFile
#undef GetEnvironmentVariable
#undef PlaySound
#undef CopyFile
#undef DeleteFile
#undef MoveFile
#undef GetFileAttributes
#undef SetFileAttributes


#define EXPOSEDFUNC _export _stdcall
//#define EXPOSEDFUNC _export _pascal

// a global string variable used to provide temporary storage for strings 
// returned to script.
static string StringReturn;

extern "C" char EXPOSEDFUNC CreateDirectory(const char * fileName){
   SECURITY_ATTRIBUTES sa;
   sa.nLength = sizeof(SECURITY_ATTRIBUTES);
   sa.lpSecurityDescriptor = NULL;
   sa.bInheritHandle = TRUE;  // why not?
   return (bool)::CreateDirectoryA(fileName, &sa);
}

extern "C" char EXPOSEDFUNC RemoveDirectory(const char * fileName){
   return (bool)::RemoveDirectoryA(fileName);
}

extern "C" void EXPOSEDFUNC Abort(){
   // User request to unconditionally exit the IDE - save nothing!
   ::ExitProcess(-3);
}

extern "C" void EXPOSEDFUNC IDEMessageBeep(int soundType){
   if(soundType != MB_ICONASTERISK && soundType != MB_ICONEXCLAMATION &&
      soundType != MB_ICONHAND && soundType != MB_ICONQUESTION){
      soundType = -1;
   }
   ::MessageBeep(soundType);
}

struct FindFirstHelper{
   FindFirstHelper();
   ~FindFirstHelper();
   LPWIN32_FIND_DATA ResetFindData();
   bool FindFirst(const char *);
   bool FindNext();
   const char *FileName();

   private:
   LPWIN32_FIND_DATA findData;
   HANDLE findFirstHandle;
};

FindFirstHelper::FindFirstHelper() : findData(NULL), findFirstHandle(INVALID_HANDLE_VALUE){
}

FindFirstHelper::~FindFirstHelper(){
   if(findData)
      delete findData;

   if(findFirstHandle != INVALID_HANDLE_VALUE)
      ::FindClose(findFirstHandle);
}

LPWIN32_FIND_DATA FindFirstHelper::ResetFindData(){
   if(findData == NULL){
      findData = new WIN32_FIND_DATA;
   }else{
      ::FindClose(findFirstHandle);
   }
   return findData;
}

bool FindFirstHelper::FindFirst(const char *filePattern){
   ResetFindData();

   #if 0
   // gmc revist: we should handle UNC filenames here as well
   string UNCAware = "\\\\?\\";
   UNCAware += filePattern;
   findFirstHandle = ::FindFirstFileW(UNCAware.c_str(), findData);
   #else
   string UNCAware = filePattern;
   findFirstHandle = ::FindFirstFileA(UNCAware.c_str(), findData);
   #endif

   return (findFirstHandle != INVALID_HANDLE_VALUE);
}

bool FindFirstHelper::FindNext(){
   return (findData && ::FindNextFileA(findFirstHandle, findData));
}

const char *FindFirstHelper::FileName(){
   return findData->cFileName;
}
static FindFirstHelper ffh;

extern "C" const char * EXPOSEDFUNC FindFirstFile(const char * filePattern){
   if(ffh.FindFirst(filePattern))
      StringReturn = ffh.FileName();
   else
      StringReturn = "";

   return StringReturn.c_str();
}

extern "C" const char * EXPOSEDFUNC FindNextFile(){
   if(ffh.FindNext())
      StringReturn = ffh.FileName();
   else
      StringReturn = "";

   return StringReturn.c_str();
}

extern "C" const char * EXPOSEDFUNC GetEnvironmentVariable(const char * envVar){
   char tmp[512];
   int cnt = ::GetEnvironmentVariableA(envVar, tmp, sizeof(tmp));
   if(!cnt){
      // gmc revist: Look in the registration database under the heading
      // "Environment" before giving up
      StringReturn = "";
   }else{
      StringReturn = tmp;
   }

   return StringReturn.c_str();
}

extern "C" void EXPOSEDFUNC AssociateButton(int resId, const char * scriptToExecute){
   // gmc revisit: Conrad needs to implement this!
}

extern "C" char EXPOSEDFUNC PlaySound(const char *wavFile, int optionsMask){
   return (bool)::sndPlaySoundA(wavFile, optionsMask);
}

extern "C" char EXPOSEDFUNC CopyFile(const char *src, const char *dst, bool overWrite){
   BOOL failIfExists = !overWrite;

   return (bool)::CopyFileA(src, dst, failIfExists);
}

extern "C" char EXPOSEDFUNC MoveFile(const char *src, const char *dst){
   return (bool)::MoveFileA(src, dst);
}

extern "C" char EXPOSEDFUNC DeleteFile(const char *src){
   return bool(::DeleteFileA(src));
}

extern "C" unsigned EXPOSEDFUNC GetFileAttributes(const char *fileName){
   return GetFileAttributesA(fileName);
}

extern "C" char EXPOSEDFUNC SetFileAttributes(const char *fileName, int newAttrs){
   return char(SetFileAttributesA(fileName, newAttrs));
}

extern "C" char EXPOSEDFUNC FileExists(char * fileName){
   if(!(*fileName))
      return FALSE;
   OFSTRUCT dummy;
   if(::OpenFile(fileName, &dummy, OF_EXIST) == HFILE_ERROR)
      return FALSE;
   return TRUE;
}

extern "C" char EXPOSEDFUNC IsLegalFileName(char * fileName){
   if(fileName == NULL)
      return FALSE;
   if(!(*fileName))
      return FALSE;
   if(strlen (fileName) > MAXPATH)
      return FALSE;

   char drive[MAXDRIVE];
   char dir[MAXDIR];
   char name[MAXFILE];
   char ext[MAXEXT];

   int rv = fnsplit(fileName, drive, dir, name, ext);

   if(rv & WILDCARDS)
      return FALSE;

   if(!(rv & FILENAME))
      return FALSE;

   // looks like it is okay
   return TRUE;
}

extern "C" bool EXPOSEDFUNC Spawn(LPTSTR szCmdLine){
   PROCESS_INFORMATION  piProcInfo;
   STARTUPINFO          siStartInfo;

   siStartInfo.cb                = sizeof( STARTUPINFO );
   siStartInfo.lpReserved        = NULL;
   siStartInfo.lpDesktop         = NULL;
   siStartInfo.lpTitle           = NULL;
   //siStartInfo.dwX;
   //siStartInfo.dwY;
   //siStartInfo.dwXSize;
   //siStartInfo.dwYSize;
   //siStartInfo.dwXCountChars;
   //siStartInfo.dwYCountChars;
   //siStartInfo.dwFillAttribute;
   //siStartInfo.dwFlags;
   //siStartInfo.wShowWindow;
   siStartInfo.cbReserved2        = 0;
   siStartInfo.lpReserved2        = NULL;
   //siStartInfo.hStdInput;
   //siStartInfo.hStdOutput;
   //siStartInfo.hStdError;       

   return CreateProcess( NULL, szCmdLine, NULL, NULL, FALSE, NULL, NULL,
                         NULL, &siStartInfo, &piProcInfo );
}

extern "C" const char * EXPOSEDFUNC GetValueData(HKEY hTopKey,
                                                 const char *szSubKey,
                                                 const char *szValueName){
   char bigTempBuffer[1024];                                                  
   DWORD  dwDataSize = 1;
   StringReturn = "";
   HKEY   hKey;

   if (RegOpenKeyEx(hTopKey, szSubKey, 0, KEY_READ, &hKey) == ERROR_SUCCESS){

      // Get the size of the value data.
      if (RegQueryValueEx(hKey, szValueName, NULL, NULL, NULL,
                          &dwDataSize) == ERROR_SUCCESS){

         // Get the value data.
         RegQueryValueEx(hKey, szValueName, NULL, NULL, bigTempBuffer, &dwDataSize);
         StringReturn = bigTempBuffer;
      }
   }
   RegCloseKey(hKey);

   return StringReturn.c_str();;
}

extern "C" bool EXPOSEDFUNC SetValueData(HKEY hTopKey,
                                         const char *szSubKey,
                                         const char *szValueName,
                                         const char *szValueData){

   HKEY   hKey;
   LONG   lResult;
   BOOL   bSuccess;

   if (RegOpenKeyEx(hTopKey, szSubKey, 0, KEY_WRITE, &hKey) == ERROR_SUCCESS){
      lResult = RegSetValueEx(hKey, szValueName, 0, REG_SZ, (LPBYTE)szValueData,
                              strlen(szValueData) + 1);
      bSuccess = (lResult == ERROR_SUCCESS ? TRUE : FALSE);
   }
   RegCloseKey(hKey);

   return bSuccess;
}
