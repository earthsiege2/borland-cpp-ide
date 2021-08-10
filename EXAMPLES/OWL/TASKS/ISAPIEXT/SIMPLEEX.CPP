//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1997 by Borland International, All Rights Reserved
// written by Michael Sawczyn
//----------------------------------------------------------------------------
#include "IsapiExt.h"
#include <classlib\time.h>

class TSimpleExtension : public TIsapiExtension
{
protected:
public:
   TSimpleExtension(const char* modulename = "Simple Extension");
   virtual DWORD Run();
};

TSimpleExtension::TSimpleExtension(const char* modulename)
   : TIsapiExtension(modulename)
{

}

DWORD TSimpleExtension::Run()
{
   // this extension creates two possible pages: one is a textual output
   // that creates some verbage and displays a simple form. The second,
   // called from the form that the first creates, demonstrates how form
   // variables can be trapped.

   if (!GetVariable("MyForm").length())
   {
      // this wasn't called from our form, so output the first page
      browser << HEAD(TITLE("Simple Extension Test Page"));
      browser << BEGINBODY;
      browser << H1("Simple Test Page");

      // no problem mixing embedded html with macros
      string p;
      browser << "<PRE>Your current information:<BR>";
      p=GetVariable("AUTH_TYPE");
      browser << "Authentication type: " << (p.length()?p.c_str():"Unavailable") << "<BR>";
      p=GetVariable("REMOTE_ADDR");
      browser << "IP Address         : " << (p.length()?p.c_str():"Unavailable") << "<BR>";
      p=GetVariable("REMOTE_HOST");
      browser << "Your Host Name     : " << (p.length()?p.c_str():"Unavailable") << "</PRE>";

      browser << P("Here's a form for you to fill in:");

      browser << "<form method=\"GET\">";
      browser << "<input type=\"hidden\" name=\"MyForm\" value=\"1\">";
      browser << P("My name: <input type=\"text\" size=\"45\" name=\"NameField\">");
      browser << P("My favorite color: <input type=\"text\" size=\"20\" name=\"ColorField\">");
      browser << P("<input type=\"checkbox\" name=\"GoToBorland\" value=\"ON\">Forget all this ... just take me to Borland's website");
      browser << P("<input type=\"submit\" name=\"SubmitButton\" value=\"Submit this information\">");
      browser << "</form>";
      browser << ENDBODY;
   }
   else
   {
      char NameField[46];
      char ColorField[21];
      char GoToBorland[3];

      GetVariable("NameField",NameField,46);
      GetVariable("ColorField",ColorField,21);
      GetVariable("GoToBorland",GoToBorland,3);

      if (!strcmp(GoToBorland,"ON"))
         RedirectToURL("http://www.borland.com");
      else
      {
         browser << HEAD(TITLE("Form Results"));
         browser << BEGINBODY;
         browser << H2("Hello " << NameField << "!");
         browser << P("The current time at the server is " << TTime().AsString());
         browser << P("I see your favorite color is " << ColorField);
         browser << ENDBODY;
      }
   }

   return Success;
}

BOOL WINAPI __export DllEntryPoint( HINSTANCE, DWORD fdwReason, LPVOID )
{
   static TSimpleExtension* module = NULL;

   switch (fdwReason)
   {
      case DLL_PROCESS_ATTACH:
         module = new TSimpleExtension;
         break;

      case DLL_PROCESS_DETACH:
         delete module;
         break;
   }

   return TRUE;
}


