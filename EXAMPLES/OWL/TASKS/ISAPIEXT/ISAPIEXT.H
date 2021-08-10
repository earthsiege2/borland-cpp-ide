//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1997 by Borland International, All Rights Reserved
// written by Michael Sawczyn
//----------------------------------------------------------------------------
#ifndef TIsapiExtension_H
#define TIsapiExtension_H

#include <httpext.h>
#include <cstring.h>
#include <classlib/thread.h>
#include <iostream.h>
#include <vector>

// convenience macros that allow embedded HTML tags to be streamed to the
// user's browser.
#define HEAD(s)         "<HEAD>" << s << "</HEAD>\n"
#define TITLE(s)        "<TITLE>" << s << "</TITLE>\n"
#define H1(s)           "<H1>" << s << "</H1>\n"
#define H2(s)           "<H2>" << s << "</H2>\n"
#define H3(s)           "<H3>" << s << "</H3>\n"
#define H4(s)           "<H4>" << s << "</H4>\n"
#define H5(s)           "<H5>" << s << "</H5>\n"
#define H6(s)           "<H6>" << s << "</H6>\n"
#define P(s)            "<P>" << s << "</P>\n"
#define PRE(s)          "<PRE>" << s << "</PRE>\n"
#define ADDRESS(s)      "<ADDRESS>" << s << "</ADDRESS>\n"
#define DIRLIST(s)      "<DIR>" << s << "</DIR>\n"
#define MENULIST(s)     "<MENU>" << s << "</MENU>\n"
#define BULLETLIST(s)   "<UL>" << s << "</UL>\n"
#define NUMBERLIST(s)   "<OL>" << s << "</OL>\n"
#define LISTITEM(s)     "<LI>" << s << "</LI>\n"
#define DEFN_LIST(s)    "<DL>\n" << s << "</DL>\n"
#define DEFN_ITEM(t,d)  "<DT>" << t << "</DT>\n<DD>" << d << "</DD>\n"
#define BEGINBODY       "<BODY>\n"
#define ENDBODY         "</BODY>\n"

class TIsapiExtension;

// the stream buffer for the browser member of TIsapiExtension. Allows
// output to be streamed to the user
class TIsapiStreambuf : public streambuf
{
public:
   TIsapiStreambuf(TIsapiExtension* aParent);
   virtual ~TIsapiStreambuf();

   void        SetParent(TIsapiExtension* aParent);
   virtual int overflow(int);
   virtual int sync();
protected:
private:
   // kept private to prevent accidental use
   TIsapiStreambuf(const TIsapiStreambuf&);
   TIsapiStreambuf& operator = (const TIsapiStreambuf&);

   static uint bufsize;
   TIsapiExtension* Parent;
   char* isapibuf;
};

class TIsapiStream : public ostream
{
   friend class TIsapiExtension;
public:
   TIsapiStream(TIsapiExtension* parent);
   virtual ~TIsapiStream();

   int sync();

protected:
private:
   void SetParent(TIsapiExtension* parent);

   // private to prevent accidental use
   TIsapiStream();
   TIsapiStream(const TIsapiStream&);
   TIsapiStream& operator = (const TIsapiStream&);
};

struct TFormVariable
{
   string Name;
   string  Value;

   TFormVariable(string& name, string& value);
   TFormVariable();
   TFormVariable(const TFormVariable& v);
   TFormVariable& operator=(const TFormVariable& v);
};


//Operation class for an ISAPI DLL. Represents the working object that
//encapsulates the function of the server extension application.
//
//Various virtual functions are provided, and at the very least the program
//should derive from this class and override the Run function to perform the
//custom functionality for the extension.

class TIsapiExtension
{
   friend class TIsapiStreambuf;
public:

   // modulename: the human readable name of the ISAPI application.
   // If NULL is passed, the name of the application will be "IIS Extension"
   TIsapiExtension(const char *modulename);
   ~TIsapiExtension();

   // used to pass the pointer to the work object to the C functions that
   // communicate with the server. Could have used a global pointer here and
   // namespace'd it (and in fact did in an earlier version), but decided on a
   // static pointer instead. Six of one, half dozen of the other ...

   static TIsapiExtension *GetIsapiInstance();

   // Called internally by the server communication routines to set information
   // within the object.
   void SetControlBlock(EXTENSION_CONTROL_BLOCK* lpEcb);

   // This is where the work is done. By default, simply informs the server
   // that all processing proceeded normally, but does nothing.
   //
   // Override this function to perform any custom processing.
   //
   // This function is already threadsafe; it is surrounded by a critical
   // section and cannot be entered by multiple threads.
   //
   // Output: Returns the success value (see TIsapiResult).
   virtual DWORD Run();

   // Called when the server has requested that the ISAPI DLL unloads.
   //
   // Should return true if ok to unload, false otherwise. If ok to unload,
   // Cleanup will be called next.
   //
   // Note: At times, the server may not make this request, but instead make
   // a demand that the DLL unload. In this case, CanUnload will not be called,
   // but instead Cleanup will be called directly.
   virtual bool CanUnload();

   // Called when ISAPI DLL is about to unload.
   //
   // Any termination functions can be written here."] */
   virtual void Cleanup();

   // Should return the human-readable name of the ISAPI extension.
   // If not overridden, the default is "IIS Extension"
    virtual const char *GetAppName();

   // This sends a complete HTTP server response header including the status,
   // server version, message time, and MIME version. It then sends the <HTML>
   // tag to begin the document.
   //
   // Applications can override this function if they wish to send other
   // than textual data, using the appropriate header format for the type of
   // data to be sent.
   //
   // If overridden, the ISAPI application should append other HTTP headers
   // such as the content type and content length, followed by an
   // extra \r\n
   virtual bool SendHeader(const char *tags = NULL);

   // Sends ending html information. By default, just sends </HTML>. Can override
   // to provide increased functionality, but should still finish with either a
   // call to TIsapiExtension::SendFooter or simply send the </HTML> tag to
   // the browser.
   virtual void SendFooter();

   // clears the browser stream. A double dispatch mechanism for convenience
   void flush();

   // returns the information the derived class has requested be placed
   // in the event log
   const char *GetLogInfo();

   // sets data that will later be written to the event log
   void SetLogInfo(const char *info);

   // Returns a null-terminated string containing the query information. This
   // is equivalent to the CGI variable QUERY_STRING.
   const char *GetQueryString();

   // The total number of bytes to be received from the client.
   // This is equivalent to the CGI variable CONTENT_LENGTH.

   // If this value is -1, then there are 4 gigabytes or more of available data.
   int GetTotalBytesReceived();

   // returns a variable, either a system variable (eg., REMOTE_HOST,
   // REMOTE_ADDR, etc.) or a form variable
   bool GetVariable(const char *varName, char *buffer, DWORD bufferlen);

   // Returns data that has been sent by the server. Can be NULL.
   string GetVariable(const char *varName);

   // Returns data that has been sent by the server. Can be NULL.
   bool    GetData(char **data);

   // This sends the data specified by the URL to the client as if the client
   // had requested that URL. The null-terminated URL pointed to by url must
   // be on the server and must not specify protocol information (that is,
   // it must begin with a "/"). No further processing is required after
   // this call.
   bool    SendFromURL(const char *url);

   // This function requests that the server convert the logical path
   // (specified by the url parameter) to a server-specific physical path,
   // which is returned in path. Only pathsize characters will be written,
   // so the path array should be at least _MAX_PATH in size.
   bool    GetPhysicalPath(const char *url, char *path, int pathsize);

   // This sends a 302 (URL Redirect) message to the client. No further
   // processing is needed after the call. This operation is similar to
   // specifying "URI: <URL>" in a CGI script header. The url variable should
   // point to a null-terminated string of URL.
   bool    RedirectToURL(const char *url);

   // Stream that can be used to write information to the user's browser.
   TIsapiStream& browser;

   // Used to provide thread safety.
   static TCriticalSection cs;
protected:
   enum TIsapiResult
   {
      Success = HSE_STATUS_SUCCESS,    // The ISAPI application has finished processing. The
                                       // server can disconnect and free up allocated resources.

      KeepConnection = HSE_STATUS_SUCCESS_AND_KEEP_CONN,
                                       // The ISAPI application has finished processing and the
                                       // server should wait for the next HTTP request if the
                                       // client supports persistent connections. The application
                                       // should return this only if it was able to send the
                                       // correct content length header to the client. The server
                                       // is not required to keep the session open. The
                                       // application should return this value only if it has
                                       // sent a connection: a keep-alive header to the client.

      Pending = HSE_STATUS_PENDING,    // The ISAPI application has queued the request for
                                       // processing and will notify the server when it has
                                       // finished. See HSE_REQ_DONE_WITH_SESSION under the
                                       // ServerSupportFunction function.

      Error = HSE_STATUS_ERROR         // The ISAPI application has encountered an error while
                                       // processing the request. The server can disconnect and
                                       // free up allocated resources.
   };

   // Holds various information about the connection with the server.
   EXTENSION_CONTROL_BLOCK *ecb;

   // Used to ensure only one instance of this object is active at any
   // given time.
   static TIsapiExtension *gInstance;

   // these strip the form variables from either the parameter string
   // (for GET calls) or the input stream (for POST calls). DLL does not need
   // to know or care which type of call was made.
   void    GetFVsFromString(const char *s);
   void    GetFVsFromStream();

   // converts %xx hex values to char values
   unsigned char dd2c(char d1, char d2);

private:
   bool DefaultHeader;
   // Holds the data obtained from the server.
   char   *data;
   // Human-readable name of the ISAPI server extension.
   string  name;
   char    LogInfo[HSE_LOG_BUFFER_LEN];
   std::vector<TFormVariable> FormVariables;
};


inline
void TIsapiStreambuf::SetParent(TIsapiExtension* aParent)
{
   Parent = aParent;
}

inline
int TIsapiStream::sync()
{
   return bp->sync();
}

inline
void TIsapiStream::SetParent(TIsapiExtension* parent)
{
   dynamic_cast<TIsapiStreambuf*>(bp)->SetParent(parent);
}

inline
TIsapiExtension* TIsapiExtension::GetIsapiInstance()
{
   return gInstance;
}

inline
void TIsapiExtension::flush()
{
   browser.flush();
}

inline
const char* TIsapiExtension::GetLogInfo()
{
   return LogInfo;
}

inline
const char *TIsapiExtension::GetAppName()
{
   return name.c_str();
}

inline
const char* TIsapiExtension::GetQueryString()
{
   if (ecb)
      return ecb->lpszQueryString;

   return "";
}

inline
int TIsapiExtension::GetTotalBytesReceived()
{
   if (ecb)
      return ecb->cbTotalBytes;

   return 0;
}


#endif
