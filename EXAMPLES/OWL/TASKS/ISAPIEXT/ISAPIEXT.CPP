//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1997 by Borland International, All Rights Reserved
// written by Michael Sawczyn
//----------------------------------------------------------------------------
#include "IsapiExt.h"
#include <stdio.h>
#include <except.h>

TCriticalSection TIsapiExtension::cs;
uint TIsapiStreambuf::bufsize = 1000;
TIsapiExtension *TIsapiExtension::gInstance = NULL;

/////////////////////////////////////////////////////////////////////
//    C interface functions
/////////////////////////////////////////////////////////////////////

BOOL WINAPI _export GetExtensionVersion(HSE_VERSION_INFO* pVer)
{
   pVer->dwExtensionVersion = MAKELONG(HSE_VERSION_MINOR,
                                       HSE_VERSION_MAJOR);
   if (TIsapiExtension::GetIsapiInstance())
   {
      lstrcpyn(pVer->lpszExtensionDesc,
               TIsapiExtension::GetIsapiInstance()->GetAppName(),
               HSE_MAX_EXT_DLL_NAME_LEN);
   }
   else
   {
      lstrcpyn(pVer->lpszExtensionDesc,
               "IIS Extension",
               HSE_MAX_EXT_DLL_NAME_LEN);
   }

   return TRUE;
}

DWORD WINAPI _export HttpExtensionProc(EXTENSION_CONTROL_BLOCK* pECB)
{
   TCriticalSection::Lock lock(TIsapiExtension::cs);
   DWORD   retval = HSE_STATUS_ERROR;

   if (TIsapiExtension::GetIsapiInstance())
   {
      TIsapiExtension::GetIsapiInstance()->SetControlBlock(pECB);
      TIsapiExtension::GetIsapiInstance()->SetLogInfo("");

      if (TIsapiExtension::GetIsapiInstance()->SendHeader())
      {
         pECB->dwHttpStatusCode = retval =
            TIsapiExtension::GetIsapiInstance()->Run();

         TIsapiExtension::GetIsapiInstance()->SendFooter();
         TIsapiExtension::GetIsapiInstance()->flush();
         lstrcpy(pECB->lpszLogData,
                 TIsapiExtension::GetIsapiInstance()->GetLogInfo());
         TIsapiExtension::GetIsapiInstance()->SetControlBlock(NULL);
      }
   }

   return retval;
}

BOOL WINAPI _export TerminateExtension(DWORD dwFlags)
{
   BOOL retval = TRUE;

   switch (dwFlags)
   {
      case HSE_TERM_ADVISORY_UNLOAD:
         if (TIsapiExtension::GetIsapiInstance())
         {
            if (TIsapiExtension::GetIsapiInstance()->CanUnload())
               TIsapiExtension::GetIsapiInstance()->Cleanup();
            else
               retval = FALSE;
         }
         break;

      case HSE_TERM_MUST_UNLOAD:
         if (TIsapiExtension::GetIsapiInstance())
            TIsapiExtension::GetIsapiInstance()->Cleanup();
   }

   return retval;
}

/////////////////////////////////////////////////////////////////////
//    TIsapiStreambuf
/////////////////////////////////////////////////////////////////////

TIsapiStreambuf::TIsapiStreambuf(TIsapiExtension* aParent)
{
   Parent = aParent;

   isapibuf = new char[bufsize];
   memset(isapibuf, 0, bufsize);
   setbuf(isapibuf, bufsize-1, 1);
   setp(isapibuf, isapibuf + (bufsize-1));
}

TIsapiStreambuf::~TIsapiStreambuf()
{

}

/////////////////////////////////////////////////////////////////////
//    TIsapiStream
/////////////////////////////////////////////////////////////////////

TIsapiStream::TIsapiStream(TIsapiExtension* parent)
{
   bp = new TIsapiStreambuf(parent);
   ios::init(bp);
}

TIsapiStream::~TIsapiStream()
{
   sync();
   delete  bp;
   bp = NULL;
}

/////////////////////////////////////////////////////////////////////
//    TIsapiExtension
/////////////////////////////////////////////////////////////////////

TIsapiExtension::TIsapiExtension(const char *modulename)
 : browser(*new TIsapiStream(this))
{
   if (gInstance)
      throw xmsg("Can't have more than one TIsapiExtension object active at a time");

   name = modulename;
   ecb = NULL;
   data = NULL;
   if (!name.length())
      name = "IIS Extension";
   gInstance = this;
   DefaultHeader = false;

   browser.SetParent(this);
}

TIsapiExtension::~TIsapiExtension()
{
   gInstance = NULL;
   delete &browser;
}

DWORD   TIsapiExtension::Run()
{
   return Success;
}

void    TIsapiExtension::SetControlBlock(EXTENSION_CONTROL_BLOCK* lpEcb)
{
   ecb = lpEcb;
   FormVariables.erase(FormVariables.begin(), FormVariables.end());

   if (ecb)
   {
      char    buffer[100];
      DWORD   bufferlen = 100;
      ecb->GetServerVariable(ecb->ConnID,
                             "REQUEST_METHOD",
                             (void *) (buffer),
                             &bufferlen);

      if (string(buffer) == "GET")
         GetFVsFromString(NULL);

      if (string(buffer) == "POST" ||
          (ecb->cbAvailable &&
           string(ecb->lpszContentType) == "application/x-www-form-urlencoded"))
         GetFVsFromStream();
   }

}

void    TIsapiExtension::GetFVsFromString(const char *s)
{
   if (s == NULL)
      s = GetQueryString();

   if (!ecb || !s) return;

   while (isspace(*s) || *s == '&')
      s++;                            /* some cases that shouldn't happen */

   if (*s != '\0')
   {
      string  name,
              value;

      /* get form field name */
      for (int i = 0; *s && *s != '&' && *s != '='; s++, i++)
      {

         switch (*s)
         {
            case '+':
               name += ' ';
               break;
            case '%':
               name += dd2c(s[1], s[2]);
               s += 2;
               break;
            default:
               name += *s;
         }

      }

      switch (*s++)
      {
         case '&':
            break;
         case '=':
            for (int i = 0; *s && *s != '&'; s++, i++)
            {
               switch (*s)
               {
                  case '+':
                     value += ' ';
                     break;
                  case '%':
                     value += dd2c(s[1], s[2]);
                     s += 2;
                     break;
                  default:
                     value += *s;
               }

            }
      }

      FormVariables.insert(FormVariables.end(),
                           TFormVariable(name, value));

      if (*s++ == '&')
         GetFVsFromString(s);
   }

}

void TIsapiExtension::GetFVsFromStream()
{
   if (!ecb) return;

   char *buffer = NULL;
   GetData(&buffer);

   if (buffer)
   {
      GetFVsFromString(buffer);
      delete[] buffer;
   }

}


unsigned char TIsapiExtension::dd2c(char d1, char d2)
{
   unsigned char digit;

   digit = (d1 >= 'A' ? ((d1 & 0xdf) - 'A') + 10 : (d1 - '0'));
   digit *= 16;
   digit += (d2 >= 'A' ? ((d2 & 0xdf) - 'A') + 10 : (d2 - '0'));
   return digit;
}

bool TIsapiExtension::GetVariable(const char *varName, char *buffer, DWORD bufferlen)
{
   DWORD length = bufferlen;

   if (ecb && buffer && varName && bufferlen)
   {
      memset(buffer, 0, bufferlen);

      if (ecb->GetServerVariable(ecb->ConnID,
                                 const_cast < char *>(varName),
                                 buffer,
                                 &length))
         return true;

      for (int l = 0; l < FormVariables.size(); l++)
      {
         if (FormVariables[l].Name == varName)
         {
            lstrcpyn(buffer, FormVariables[l].Value.c_str(), bufferlen);
            buffer[bufferlen - 1] = 0;
            return true;
         }
      }
   }

   if (buffer)
      buffer[0] = 0;
   return false;
}

string TIsapiExtension::GetVariable(const char *varName)
{
   char buffer[1024];
   DWORD bufferlen = 1024;

   if (ecb && varName)
   {
      if (ecb->GetServerVariable(ecb->ConnID,
                                 const_cast < char *>(varName),
                                 (void *) (buffer),
                                 &bufferlen))
         return string(buffer);

      for (int l = 0; l < FormVariables.size(); l++)
      {
         if (FormVariables[l].Name == varName)
         {
            lstrcpyn(buffer, FormVariables[l].Value.c_str(), 1024);
            buffer[1023] = 0;
            return string(buffer);
         }
      }

   }

   return string("");
}

void TIsapiExtension::Cleanup()
{

}

bool TIsapiExtension::CanUnload()
{
   return true;
}

void TIsapiExtension::SetLogInfo(const char *info)
{
   lstrcpyn(LogInfo, info, HSE_LOG_BUFFER_LEN);
   LogInfo[HSE_LOG_BUFFER_LEN - 1] = NULL;
}

bool TIsapiExtension::GetData(char **data)
{
   bool retval = false;
   *data = 0;

   if (ecb)
   {
      *data = new char[ecb->cbTotalBytes];
      memcpy(*data, ecb->lpbData, ecb->cbAvailable);

      if (ecb->cbAvailable != ecb->cbTotalBytes)
      {
         DWORD bufsize = 10000;
         char *buffer = new char[bufsize];
         int   offset = ecb->cbAvailable;

         while (bufsize)
         {
            ecb->ReadClient(ecb->ConnID,
                            (void *) (buffer),
                            &bufsize);

            if (bufsize)
               memcpy(&((*data)[offset]), buffer, bufsize);
            offset += bufsize;
         }

         delete[] buffer;
      }

      retval = true;
   }

   return retval;
}

void TIsapiExtension::SendFooter()
{
   if (DefaultHeader)
      browser << "</HTML>";
}

bool TIsapiExtension::SendHeader(const char *tags)
{
   if (ecb)
   {
      DWORD   size = 0;
      BOOL    retval = ecb->ServerSupportFunction(ecb->ConnID,
                                                  HSE_REQ_SEND_RESPONSE_HEADER,
                                                  (void *) tags,
                                                  &size,
                                                  NULL);
      if (retval && (!tags || tags[0] == 0))
      {
         browser << "<HTML>";
         DefaultHeader = true;
      }

      return retval;
   }

   return false;
}

bool TIsapiExtension::SendFromURL(const char *url)
{
   if (url && ecb)
   {
      DWORD   size = strlen(url);
      return ecb->ServerSupportFunction(ecb->ConnID,
                                        HSE_REQ_SEND_URL,
                                        (void *) (url),
                                        &size,
                                        NULL);
   }

   return false;
}

bool TIsapiExtension::GetPhysicalPath(const char *url, char *path, int pathsize)
{
   if (url && path && pathsize && ecb)
   {
      DWORD   size = max(strlen(url), (unsigned int) pathsize) + 1;
      char   *buffer = new char[size];
      lstrcpy(buffer, url);

      BOOL    retval = ecb->ServerSupportFunction(ecb->ConnID,
                                                  HSE_REQ_MAP_URL_TO_PATH,
                                                  (void *) (buffer),
                                                  &size,
                                                  NULL);

      lstrcpyn(path, buffer, pathsize);
      path[pathsize - 1] = NULL;
      delete[] buffer;
      return retval;
   }

   return false;
}

bool TIsapiExtension::RedirectToURL(const char *url)
{
   if (url && ecb)
   {
      DWORD   size = strlen(url);
      return ecb->ServerSupportFunction(ecb->ConnID,
                                        HSE_REQ_SEND_URL_REDIRECT_RESP,
                                        (void *) (url),
                                        &size,
                                        NULL);
   }

   return false;
}

/////////////////////////////////////////////////////////////////////
//    TIsapiStreambuf
/////////////////////////////////////////////////////////////////////

int     TIsapiStreambuf::sync()
{
   DWORD   size = strlen(isapibuf);
   DWORD   totalsize = size;

   if (Parent && Parent->ecb)
   {
      if (!Parent->ecb->WriteClient(Parent->ecb->ConnID,
                                    (void *) (isapibuf),
                                    &size,
                                    HSE_IO_SYNC))
         return EOF;

      if (size != totalsize)
      {
         int     offset = size;
         int     remaining = totalsize - size;

         while (remaining)
         {
            size = remaining;

            if (!Parent->ecb->WriteClient(Parent->ecb->ConnID,
                                          (void *) (&(isapibuf[offset])),
                                          &size,
                                          HSE_IO_SYNC))
               return EOF;

            offset += size;
            remaining -= size;
         }
      }

   }
   else
      return EOF;

   memset(isapibuf, 0, bufsize);
   setp(isapibuf, isapibuf + (bufsize - 1));
   return 0;
}

int TIsapiStreambuf::overflow(int c)
{
   sync();
   return sputc(c);
}

/////////////////////////////////////////////////////////////////////
//    TFormVariable
/////////////////////////////////////////////////////////////////////

TFormVariable::TFormVariable()
{

}

TFormVariable::TFormVariable(string& name, string& value)
{
   Name = name;
   Value = value;
}

TFormVariable::TFormVariable(const TFormVariable& v)
{
   operator = (v);
}

TFormVariable& TFormVariable::operator=(const TFormVariable& v)
{
   Name = v.Name;
   Value = v.Value;
   return *this;
}

