///////////////////////////////////////////////////////////////////////
//
// Copyright <c> Borland International, 1994
//
// Example Tools added for common OLE development.
//
///////////////////////////////////////////////////////////////////////
//
// To enable the tools:
// --------------------
// 1) Build the OLETOOLS.DLL target.
// 2) Add the following to the [AddOns] section of your BCW.INI file:
//    Addon000=Drive:Path\OLETOOLS.DLL
//    Note: The 000 must actually be the next numeric value in sequence.
//          That is, if you already have an entry with 000, use 001 etc...
//          If the [AddOns] section doesn't exist you may create it.
// 3) On certain environments you will need to verify that the STDOLE.DLL
//    resides in your windows system directory.
//
// Tools Descriptions:
// ------------------
// translateODLtoTLB
//    Convert .odl to .tlb files. 
//    (Requires Non-Borland distributed MkTypLib.exe)
// msMKTypLib
//    Internal (to example) tool used for converting from ODL to TLB files.
// extractAndBindTLB
//    Create .tlb from .exe/.dll bind .tlb back into .dll/.exe
// oleRegister
//    Internal (to example) tool used to invoke register.exe
// oleExtractTLB
//    Extract TypeLib Information
// oleExtractReg
//    Create a .reg file from .exe/.dll
// oleRegEditAdvanced
//    Tools Menu option to invoke regedit with /v parameter.
// generateAndAddSource
//    Create nodes (.cxx [.cpp] /.hxx [.h] ) in your target from .exe/.dll
// oleAutoGen
//    Internal (to example) tool used to invoke Autogen.
//
///////////////////////////////////////////////////////////////////////
#pragma hdrstop
// Standard include files.
#include <string.h>
#include <windows.h>
#include <dir.h>

// IDEHOOK include file.
#include "idehook.h"

// OLE Tool names.
static char translateODLtoTLB[]    = "OLE_ODLtoTLB";
static char msMkTypLib[]           = "OLE_IMkTypeLib";
static char extractAndBindTLB[]    = "OLE_ExtractAndBindTypeInfo";
static char oleRegister[]          = "OLE_IRegister";
static char oleExtractTLB[]        = "OLE_ExtractTypeInfo";
static char oleExtractReg[]        = "OLE_ExtractReg";
static char oleRegEditAdvanced[]   = "OLE_RegEditAdvanced";
static char generateAndAddSource[] = "OLE_GenerateAndAddSource";
static char oleAutoGen[]           = "OLE_IAutoGen";

// Existing tool names provided by BCW
static char realLinker[]           = "LinkTarget";
static char realResCompiler[]      = "CompileResources";
static char realCppPreprocess[]    = "CppPreprocessor";

///////////////////////////////////////////////////////////////////////
//  LocalToolClient ctor
//  Encapsulates the callback routines for tools.       
///////////////////////////////////////////////////////////////////////
class _HOOKCLASS LocalToolClient : public ToolClient
{
 public:

    // Callback routines.
	 ToolReturn _HOOKEP RunGenerateAndAddSource( ToolInvokeArgs * );
	 ToolReturn _HOOKEP RunExtractAndBind( ToolInvokeArgs * );
	 ToolReturn _HOOKEP RunTypeLibrary( ToolInvokeArgs * );

    // Registers Callback routines
	 void RegisterMyCallBacks( ToolServer * );

 private:

	 int registered; 
	 static ToolRegisterPack entryPoints[];
};

// Instantiated LocalToolClient object.  
static LocalToolClient localToolClient;

// Static ToolRegisterPack object.  
ToolRegisterPack LocalToolClient::entryPoints[] =
{
 { ::generateAndAddSource, (ToolMethod)&LocalToolClient::RunGenerateAndAddSource },
 { ::extractAndBindTLB, (ToolMethod)&LocalToolClient::RunExtractAndBind },
 { ::translateODLtoTLB, (ToolMethod)&LocalToolClient::RunTypeLibrary },
 { 0 }
};

///////////////////////////////////////////////////////////////////////////
// LocalToolClient::RegisterMyCallBacks 
//    Register tool callback routines.
///////////////////////////////////////////////////////////////////////////
void                              
LocalToolClient::RegisterMyCallBacks( ToolServer * ts )
{
 // Have these been registered before?
 if (!registered)
	 {
	  registered = 1;
	  ts->ToolRegisterImplementor( this, entryPoints );
	 }
}

///////////////////////////////////////////////////////////////////////////
// LocalToolClient::generateAndAddSource
//    Create nodes (.cxx [.cpp] /.hxx [.h] ) in your target from .exe/.dll
///////////////////////////////////////////////////////////////////////////
ToolReturn _HOOKEP
LocalToolClient::RunGenerateAndAddSource(ToolInvokeArgs * args)
{
 ToolReq trTool;           // Tool Requestor.
 ProjectReq prProject;     // Project Requestor
 ToolReturn trReturn = FatalError;  // Return Value.

 ProjectNode pnParent = args->numNodes ? *args->nodeArray : 0;

 if (pnParent)
	 {
	  // Obtain code generation tool.
	  ToolObj toAutoGen = trTool->ToolFind(::oleAutoGen);

	  if (toAutoGen)
		  {
			// Base used for new file names.
			char acBaseName[10];

			// Project Node Information.
			ProjectNodeInfo pniParent;

			// Get filename from node information.
			prProject->QueryNodeInfo(pnParent,pniParent);

			// Extract base file name.
			fnsplit(pniParent.name,NULL,NULL,acBaseName,NULL);

			// Check for valid name.
			if (acBaseName[0] != 0)
				{
             char acNodeNameCXX[14];
			    char acNodeNameHXX[14];

             // Create New Node Names
             wsprintf(acNodeNameCXX,"%s.cxx",acBaseName);
             wsprintf(acNodeNameHXX,"%s.hxx",acBaseName);

				 ToolObj regServer = trTool->ToolFind( oleRegister );

				 if (regServer)
					 {
                 // Create needed .olb file.
					  if (trTool->ToolInvoke( regServer, pnParent, "$TARGET -TypeLib=$NAME($TARGET).olb") == Success)
						  {
							// Invoke tool and generate new source modules.
							// upon success, add new source modules to the project.
                     if (trTool->ToolInvoke( toAutoGen, (const char *)0, "$NAME($TARGET).olb" ) == Success )
					         {
                         // Add generated source code to project.
					          ProjectNode pnCpp = prProject->NodeAdd(pnParent,acNodeNameCXX,".cpp");
					          prProject->NodeAdd(pnCpp,acNodeNameHXX,".h");
					          trReturn = Success;
					         }
				         else
					         ::MessageBox(::GetActiveWindow(),"AutoGen Reported Failure","Error",MB_ICONEXCLAMATION | MB_OK);
						  }
                 else
					     ::MessageBox(::GetActiveWindow(),"Register Reported Failure","Error",MB_ICONEXCLAMATION | MB_OK);
                }
             else
                ::MessageBox(::GetActiveWindow(),"REGISTER.EXE Not Found","Error",MB_ICONEXCLAMATION | MB_OK);
				}    
			else
		      ::MessageBox(::GetActiveWindow(),"Base File Name Not Found","Error",MB_ICONEXCLAMATION | MB_OK);
	     }
     else
        ::MessageBox(::GetActiveWindow(),"AUTOGEN.EXE Not Found","Error",MB_ICONEXCLAMATION | MB_OK);
    }
 else
    ::MessageBox(::GetActiveWindow(),"Parent Node Invalid","Error",MB_ICONEXCLAMATION | MB_OK);

 return (trReturn);
}

///////////////////////////////////////////////////////////////////////////
// extractAndBindTLB
//    Create .tlb from .exe/.dll bind .tlb back into .dll/.exe
///////////////////////////////////////////////////////////////////////////
ToolReturn _HOOKEP
LocalToolClient::RunExtractAndBind( ToolInvokeArgs * args )
{
 ProjectReq  ps;
 EditorReq   editor;
 ToolReq     server;

 ToolReturn trReturn = FatalError;

 ProjectNode targetNode = args->numNodes ? *args->nodeArray : 0;

 if (targetNode)
	 {
	  // Extract the .tlb from the .dll/.exe
	  ToolObj regServer = server->ToolFind( oleRegister );

	  if (regServer)
		  {
			server->ToolInvoke( regServer, targetNode, "$TARGET -TypeLib=__temp.tlb" );

			// Create a .rc node
			static char rcNodeName[] = "__temp.rc";

			ProjectNode rcNode = ps->NodeAdd( targetNode, rcNodeName );

			if (rcNode)
				{
				 // Create a edit buffer for the .rc script
				 static char rcStatement[]  = "TYPELIB 1 __temp.tlb";

				 BufferId newBuffer_id  = editor->create_buffer( 0, rcNodeName, 0 );
				 BufferId currBuffer_id = editor->set_buffer(newBuffer_id);

				 editor->insert( rcStatement  );

				 // Resource compile the .rc script
				 ToolObj resCompiler = server->ToolFind( realResCompiler );

				 if (resCompiler)
					 {
					  server->ToolInvoke( resCompiler, rcNode, 0);

					  // Run the linker (this re-bind the .dll with the new .res)
					  ToolObj linker = server->ToolFind( realLinker );

					  if (linker)
						  {
							server->ToolInvoke( linker, targetNode, 0 );
							trReturn = Success;
						  }
					  else
						  ::MessageBox(::GetActiveWindow(),"Internal Linker Not Found","Error!",MB_ICONEXCLAMATION | MB_OK);

					  // Re-register now that the .tlb is inside the .dll/.exe
					  server->ToolInvoke( regServer, targetNode, "$TARGET -RegServer" );
					 }
				else
				  ::MessageBox(::GetActiveWindow(),"Internal Resource Compiler Not Found","Error!",MB_ICONEXCLAMATION | MB_OK);

				// Restore the user's editor state
				editor->set_buffer( currBuffer_id );
				editor->delete_buffer( newBuffer_id );

				// Remove temporary node.
				ps->NodeRemove(rcNode);
			  }
		  else
			  ::MessageBox(::GetActiveWindow(),"Unable to create a temporary node.","Error!",MB_ICONEXCLAMATION | MB_OK);
		  }
	  else
		  ::MessageBox(::GetActiveWindow(),"REGISTER.EXE Not Found","Error!",MB_ICONEXCLAMATION | MB_OK);
	 }
 else
	 ::MessageBox(::GetActiveWindow(),"Target Node Not Found","Error!",MB_ICONEXCLAMATION | MB_OK);

 return( trReturn );
}

///////////////////////////////////////////////////////////////////////////////
// translateODLtoTLB
//    Convert .odl to .tlb files. (Requires Non-Borland distributed MkTypLib.exe?)
///////////////////////////////////////////////////////////////////////////////
ToolReturn _HOOKEP
LocalToolClient::RunTypeLibrary( ToolInvokeArgs * args )
{
 static char cppCmdLine[]
						= "+$RSP(-D__MKTYPLIB__;$DEF -I$INC -P- -otlbt@@@.tm~) $EDNAME";

 ToolReq   server;

 ProjectNode node = args->numNodes ? *args->nodeArray : 0;

 ToolObj preprocessor = server->ToolFind( realCppPreprocess );
 ToolObj msTool = 0;

 if ( preprocessor )
	 {
	  if ( server->ToolInvoke( preprocessor, node, cppCmdLine) == Success )
		  {
			if ((msTool = server->ToolFind( ::msMkTypLib )) == 0)
            ::MessageBox(::GetActiveWindow(),"Can't find mktyplib.exe tool", "Error!",MB_ICONEXCLAMATION | MB_OK);
		  }
	  else
        ::MessageBox(::GetActiveWindow(),"CppPreprocess did not complete ok!","Error!",MB_ICONEXCLAMATION | MB_OK);
	 }

 if ( msTool )
	 return( server->ToolInvoke( msTool, node, args->cmdLine ) );

 return( Errors );
}

///////////////////////////////////////////////////////////////////////
//  Project Client Implementation
//  Encapsulates Project Manager Notifications
///////////////////////////////////////////////////////////////////////
class _HOOKCLASS LocalProjClient : public ProjectClient
{
 public:

	 // Ctor
	 LocalProjClient();

	 // Required pure virtual implementations.
	 virtual void _HOOKEP OpenNotify(const char * name);
	 virtual void _HOOKEP CloseNotify();
	 virtual void _HOOKEP NodeDeleteNotify(ProjectNode);
	 virtual void _HOOKEP DependencyQueryResponder(ProjectNode ,const char *);

};

// Instantiated LocalProjectClient object.  
static LocalProjClient LocalProjClient;

///////////////////////////////////////////////////////////////////////
// LocalProjectClient Ctor
// Register Project Client with IDE using a Project requestor.
///////////////////////////////////////////////////////////////////////
LocalProjClient::LocalProjClient()
{
 ProjectReq ps;
 ps->RegisterProjectClient(this);
}

///////////////////////////////////////////////////////////////////////
// LocalProjectClient::OpenNotify 
// Register Callbacks.
// Add Tools to Project Manager.
///////////////////////////////////////////////////////////////////////
void _HOOKEP
LocalProjClient::OpenNotify(const char * /*name */)
{
 ///////////////////////////////////////////////////////////////////////
 // Register Callbacks
 ///////////////////////////////////////////////////////////////////////

 // Obtain a ToolRequestor.
 ToolReq ts;

 // Register callbacks for tools.
 localToolClient.RegisterMyCallBacks( ts );

 ///////////////////////////////////////////////////////////////////////
 // Add Tools
 ///////////////////////////////////////////////////////////////////////
 
 // translateODLtoTLB
 //    Convert .odl to .tlb files.
 if ( !ts->ToolFind( ::translateODLtoTLB ) )
	 {
	  ToolInfo toolInfo;

	  toolInfo.toolType    = Translator;
	  toolInfo.name        = ::translateODLtoTLB;
	  toolInfo.path        = 0;
	  toolInfo.flags       = OnLocalMenu;
	  toolInfo.menuName    = "OLE Compile to .TLB";
	  toolInfo.helpHint    = "Translate an ODL script to automation type library";
	  toolInfo.defCmdLine  = 0;
	  toolInfo.translateFrom = ".odl";
	  toolInfo.defaultFor  = ".odl";
	  toolInfo.translateTo = ".tlb";
	  toolInfo.launchId    = CALLBACK_LAUNCH_ID;

	  ts->ToolAdd( &toolInfo );
	 }

 // msMKTypLib
 //    Internal (to example) tool used for converting from ODL to TLB files.
 if (!ts->ToolFind( ::msMkTypLib ) )
	 {
	  ToolInfo toolInfo;

	  toolInfo.toolType    = Transfer;
	  toolInfo.name        = ::msMkTypLib;
	  toolInfo.path        = "mktyplib.exe";
	  toolInfo.flags       = ToolFlags(0);
	  toolInfo.menuName    = 0;
	  toolInfo.helpHint    = 0;
	  toolInfo.defCmdLine  = "/W0 /nocpp /nologo /tlb $OUTNAME tlbt@@@.tm~ ";
	  toolInfo.translateFrom = 0;
	  toolInfo.defaultFor  = 0;
	  toolInfo.translateTo = 0;
	  toolInfo.launchId    = DEFAULT_LAUNCH_ID;

	  ts->ToolAdd( &toolInfo );
	 }

 // oleRegister
 //    Internal (to example) tool used to invoke register.exe
 if ( !ts->ToolFind( oleRegister ) )
	 {
	  ToolInfo toolInfo;

	  toolInfo.toolType    = Transfer;
	  toolInfo.name        = ::oleRegister;
	  toolInfo.path        = "register.exe";
	  toolInfo.flags       = ToolFlags(0);
	  toolInfo.menuName    = 0;
	  toolInfo.helpHint    = 0;
	  toolInfo.defCmdLine  = 0;
	  toolInfo.translateFrom = 0;
	  toolInfo.defaultFor  = 0;
	  toolInfo.translateTo = 0;
	  toolInfo.launchId    = DEFAULT_LAUNCH_ID;

	  ts->ToolAdd( &toolInfo );
	 }

 // extractAndBindTLB
 //    Create .tlb from .exe/.dll bind .tlb back into .dll/.exe
 if ( !ts->ToolFind( ::extractAndBindTLB ) )
	 {
	  ToolInfo toolInfo;

	  toolInfo.toolType    = Translator;
	  toolInfo.name        = ::extractAndBindTLB;
	  toolInfo.path        = 0;
	  toolInfo.flags       = TargetTranslator | OnLocalMenu;
	  toolInfo.menuName    = "OLE Bind TypeLib";
	  toolInfo.helpHint    = "Extract Typelibrary and re-link target with .tlb";
	  toolInfo.defCmdLine  = "$TARGET";
	  toolInfo.translateFrom = ".dll;.exe;AppExpert;AppExpertDLL;";
	  toolInfo.defaultFor  = 0;
	  toolInfo.translateTo = 0;
	  toolInfo.launchId    = CALLBACK_LAUNCH_ID;
	  
	  ts->ToolAdd( &toolInfo );
	 }
	 
 // oleExtractTLB
 //    Extract TypeLib Information
 if ( !ts->ToolFind( ::oleExtractTLB) )
	 {
	  ToolInfo toolInfo;

	  toolInfo.toolType    = Translator;
	  toolInfo.name        = ::oleExtractTLB;
	  toolInfo.path        = "register.exe";
	  toolInfo.flags       = OnLocalMenu;
	  toolInfo.menuName    = "OLE Extract TypeLib";
	  toolInfo.helpHint    = "Extract automation type library from module";
	  toolInfo.defCmdLine  = "$TARGET -TypeLib=$NAME($TARGET).olb";
	  toolInfo.translateFrom = ".exe;.dll;AppExpert;AppExpertDLL;";
	  toolInfo.defaultFor  = 0;
	  toolInfo.translateTo = ".olb";
	  toolInfo.launchId    = DEFAULT_LAUNCH_ID;

	  ts->ToolAdd( &toolInfo );
	 }

 // oleExtractReg
 //    Create a .reg file from .exe/.dll
 if ( !ts->ToolFind( ::oleExtractReg) )
	 {
	  ToolInfo toolInfo;

	  toolInfo.toolType    = Translator;
	  toolInfo.name        = ::oleExtractReg;
	  toolInfo.path        = "register.exe";
	  toolInfo.flags       = OnLocalMenu;
	  toolInfo.menuName    = "OLE Extract Register";
	  toolInfo.helpHint    = "Extract Registry database script from module";
	  toolInfo.defCmdLine  = "$TARGET -RegServer=$NAME($TARGET).reg";
	  toolInfo.translateFrom = ".exe;.dll;AppExpert;AppExpertDLL;";
	  toolInfo.defaultFor  = 0;
	  toolInfo.translateTo = ".reg";
	  toolInfo.launchId    = DEFAULT_LAUNCH_ID;

	  ts->ToolAdd( &toolInfo );
	 }

 // oleRegEditAdvanced
 //    Tools Menu option to invoke regedit with /v parameter.
 if ( !ts->ToolFind(::oleRegEditAdvanced))
	 {
	  ToolInfo toolInfo;

	  toolInfo.toolType    = Transfer;
	  toolInfo.name        = ::oleRegEditAdvanced;
	  toolInfo.path        = "RegEdit.exe";
	  toolInfo.flags       = OnToolsMenu | OnLocalMenu;
	  toolInfo.menuName    = "OLE RegEdit Advanced";
	  toolInfo.helpHint    = "Invoke RegEdit using advanced display";
	  toolInfo.defCmdLine  = "/v";
	  toolInfo.translateFrom = 0;
	  toolInfo.defaultFor  = 0;
	  toolInfo.translateTo = 0;
	  toolInfo.launchId    = DEFAULT_LAUNCH_ID;

	  ts->ToolAdd( &toolInfo );
	 }

 // generateAndAddSource
 //    Create nodes (.cxx [.cpp] /.hxx [.h] ) in your target from .exe/.dll
 if ( !ts->ToolFind(::generateAndAddSource))
	 {
	  ToolInfo toolInfo;

	  toolInfo.toolType    = Translator;
	  toolInfo.name        = ::generateAndAddSource;
	  toolInfo.path        = 0;
	  toolInfo.flags       = OnLocalMenu;
	  toolInfo.menuName    = "OLE Generate Source";
	  toolInfo.helpHint    = "Generate class interface source";
	  toolInfo.defCmdLine  = 0;
	  toolInfo.translateFrom = ".exe;.dll;AppExpert;AppExpertDLL;";
	  toolInfo.defaultFor  = 0;
	  toolInfo.translateTo = 0;
	  toolInfo.launchId    = CALLBACK_LAUNCH_ID;

	  ts->ToolAdd( &toolInfo );
	 }

 // oleAutoGen
 //    Internal (to example) tool used to invoke Autogen.
 if ( !ts->ToolFind( ::oleAutoGen ) )
	 {
	  ToolInfo toolInfo;

	  toolInfo.toolType    = Transfer;
	  toolInfo.name        = ::oleAutoGen;
	  toolInfo.path        = "autogen.exe";
	  toolInfo.flags       = ToolFlags(0);
	  toolInfo.menuName    = 0;
	  toolInfo.helpHint    = 0;
	  toolInfo.defCmdLine  = 0;
	  toolInfo.translateFrom = 0;
	  toolInfo.defaultFor  = 0;
	  toolInfo.translateTo = 0;
	  toolInfo.launchId    = DEFAULT_LAUNCH_ID;

	  ts->ToolAdd( &toolInfo );
	 }
}

///////////////////////////////////////////////////////////////////////
// LocalProjectClient::CloseNotify, forced pure virtual implementation.
///////////////////////////////////////////////////////////////////////
void _HOOKEP
LocalProjClient::CloseNotify()
{
}

////////////////////////////////////////////////////////////////////////////
// LocalProjectClient::NodeDeleteNotify, forced pure virtual implementation.
////////////////////////////////////////////////////////////////////////////
void _HOOKEP
LocalProjClient::NodeDeleteNotify(ProjectNode)
{
}

////////////////////////////////////////////////////////////////////////////////////
// LocalProjectClient::DependencyQueryResponder, forced pure virtual implementation.
////////////////////////////////////////////////////////////////////////////////////
void _HOOKEP
LocalProjClient::DependencyQueryResponder(ProjectNode ,const char *)
{
}

// End of file
