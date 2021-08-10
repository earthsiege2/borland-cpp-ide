//----------------------------------------------------------------------------
// IdeHook - (C) Copyright 1994 by Borland International
//----------------------------------------------------------------------------
#pragma hdrstop

#include "idehook.h"
#include "pathspec.h"
#include <cstring.h>

static char genVbxTransferName[]   = "VbxHeaderGen";
static char genVbxViewerName[]     = "VbxHeaderNodeGen";
static char genVbxTranslatorName[] = "VbxTranslator";
static char genVbxPath[]           = "vbxgen.exe";
static char genVbxMenuName[]       = "&Generate VBX Header";
static char genVbxHelpHint[]       = "Generate header files for VBX controls";


static char VBXFilter[]    = "VBX Controls (*.vbx)|*.vbx|"
                             "All Files (*.*)|*.*|";
static char DotHFilter[]   = "Header File (*.h)|*.h|"
                             "All Files (*.*)|*.*|";
           


class _HOOKCLASS LocalToolClient : public ToolClient
{
public:
    ToolReturn _HOOKEP RunVbxHeaderGen( ToolInvokeArgs * );

    void RegisterMyCallBacks( ToolServer * );

private:
            int                 registered;
    static  ToolRegisterPack    entryPoints[];

};

static LocalToolClient  localToolClient;

ToolRegisterPack LocalToolClient::entryPoints[] =
{
    { genVbxViewerName, (ToolMethod)&LocalToolClient::RunVbxHeaderGen },
    { 0 }
};

void
LocalToolClient::RegisterMyCallBacks( ToolServer * ts )
{
    if( !registered )
    {
        registered = 1;
        ts->ToolRegisterImplementor( this, entryPoints );
    }
}

ToolReturn _HOOKEP 
LocalToolClient::RunVbxHeaderGen( ToolInvokeArgs * args )
{
   PathSpec    vbxPath;
   PathSpec    headerPath;

   if( vbxPath.openFileDialog( VBXFilter ) )
   {
       headerPath.path( vbxPath.path() );
       headerPath.ext( ".h" );
       
       if( headerPath.newFileDialog( DotHFilter ) )
       {
           ToolReq     ts;

           ToolObj     vbxGenner = ts->ToolFind( genVbxTransferName );
                                            
           string  cmdLine;

           cmdLine = vbxPath.path();
           cmdLine += " ";
           cmdLine += headerPath.path();

           if
           (
              ( ts->ToolInvoke( vbxGenner, (const char *)0, cmdLine.c_str() ) ) 
                  == Success 
           )
           {
               ProjectReq  project;

               int count = args->numNodes;
    
               for( int i = 0; i < count; i++ )
               {
                  ProjectNode   parent = args->nodeArray[i];

                  project->NodeAdd( parent, headerPath.path() );
               }

               ts->ToolInvoke( ts->ToolFind( "EditText" ), headerPath.path() );
               
           }
       }
   }
   
   return( Success );
}


//
//      Project stuff
//

class _HOOKCLASS LocalProjClient : public ProjectClient
{
public:
    LocalProjClient();
   
    virtual void _HOOKEP OpenNotify ( const char * name );
    virtual void _HOOKEP CloseNotify() {}
    virtual void _HOOKEP NodeDeleteNotify( ProjectNode ) {}
    virtual void _HOOKEP DependencyQueryResponder(ProjectNode,const char *) {}
};

static LocalProjClient LocalProjClient;

LocalProjClient::LocalProjClient()
{
   ProjectReq ps;

   ps->RegisterProjectClient(this);
}


void _HOOKEP    
LocalProjClient::OpenNotify
(
   const char * // name 
)
{
    ToolReq   ts;

    localToolClient.RegisterMyCallBacks( ts );

    if( !ts->ToolFind( genVbxTransferName ) )
    {
        ToolInfo toolInfo;

        //                                              //
        // Install this as simple 'Tool' menu transfer  //
        // It will run the tool 'straight'              //
        //                                              //
        
	     toolInfo.toolType		= Transfer;
        toolInfo.name          = genVbxTransferName;
        toolInfo.path          = genVbxPath;
	     toolInfo.flags         = OnToolsMenu;
        toolInfo.menuName      = genVbxMenuName; 
        toolInfo.helpHint      = genVbxHelpHint; 
        toolInfo.defCmdLine    = "$PROMPT";
		 toolInfo.appliesTo     = 0;
        toolInfo.defaultFor    = 0;
        toolInfo.translateTo   = 0;
        toolInfo.launchId      = DEFAULT_LAUNCH_ID;

        ts->ToolAdd( &toolInfo );

        //                                              //
        // Install this as a Viewer on [.c] and [.cpp]  //
        // We will implement the tool here (above) by   //
        // putting put our own FileOpen dialogs and     //
        // adding the results into tree.                //
        //                                              //
        
	     toolInfo.toolType		= Viewer;
        toolInfo.name          = genVbxViewerName;
        toolInfo.path          = 0;
	     toolInfo.flags         = OnLocalMenu;
        toolInfo.menuName      = genVbxMenuName;
        toolInfo.helpHint      = genVbxHelpHint;
        toolInfo.defCmdLine    = 0;
		 toolInfo.appliesTo     = ".cpp;.c;";
        toolInfo.defaultFor    = 0;
        toolInfo.translateTo   = 0;
        toolInfo.launchId      = CALLBACK_LAUNCH_ID;

        ts->ToolAdd( &toolInfo );
        
        //                                              //
        // Install this as a translator on [.vbx] nodes //
        // with the output being a [.h]                 //
        //                                              //
        
	     toolInfo.toolType		= Translator;
        toolInfo.name          = genVbxTranslatorName;
        toolInfo.path          = genVbxPath;
	     toolInfo.flags         = OnLocalMenu;
        toolInfo.menuName      = genVbxMenuName;
        toolInfo.helpHint      = genVbxHelpHint;
        toolInfo.defCmdLine    = "$EDNAME $OUTNAME";
		 toolInfo.appliesTo     = ".vbx";
        toolInfo.defaultFor    = ".vbx";
        toolInfo.translateTo   = ".h";
        toolInfo.launchId      = DEFAULT_LAUNCH_ID;

        ts->ToolAdd( &toolInfo );

    }
}
    
// End of file

