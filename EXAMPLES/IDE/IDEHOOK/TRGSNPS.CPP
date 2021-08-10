//----------------------------------------------------------------------------
// IdeHook - (C) Copyright 1994 by Borland International
//----------------------------------------------------------------------------
#pragma hdrstop

#include "idehook.h"
#include "pathspec.h"
#include <string.h>
#include <windows.h>

static char targetExeSnipName[] = "TargetExeSnippets";
static char targetDllSnipName[] = "TargetDllSnippets";

#define CRLF "\n"

static char szExeWinMain[] =
   "//"                                   CRLF
   "//     This is the WinMain snippet"   CRLF
   "//"                                   CRLF
   "#include <windows.h>"                 CRLF
                                          CRLF
   "int WINAPI WinMain"                   CRLF
   "("                                    CRLF
   "   HINSTANCE /* hInstance */,"        CRLF
   "   HINSTANCE /* hPrevInstance */, "   CRLF
   "   LPSTR     /* lpCmdLine */,"        CRLF
   "   int       /* howShow */"           CRLF
   ")"                                    CRLF
   "{"                                    CRLF
   "   return(0);"                        CRLF
   "}"                                    CRLF
   ;

static char szExeOwlMain[] =
   "//"                                                    CRLF
   "//     This is the OwlMain snippet"                    CRLF
   "//"                                                    CRLF
   "#include <owl/applicat.h>"                             CRLF
                                                           CRLF
   "int OwlMain( int /* argc */ , char ** /* argv */ )"    CRLF
   "{"                                                     CRLF
   "   return( TApplication().Run() );"                    CRLF
   "}"                                                     CRLF
   ;

static char szExeDefSnip[] =
   "EXETYPE WINDOWS"                     CRLF
   "CODE PRELOAD MOVEABLE DISCARDABLE"   CRLF
   "DATA PRELOAD MOVEABLE MULTIPLE"      CRLF
   "HEAPSIZE 4096"                       CRLF
   "STACKSIZE 8192"                      CRLF
   ;

class _HOOKCLASS LocalToolClient : public ToolClient
{
public:
    ToolReturn _HOOKEP RunTargetExeSnips( ToolInvokeArgs * );
    ToolReturn _HOOKEP RunTargetDllSnips( ToolInvokeArgs * );

    void RegisterMyCallBacks( ToolServer * );

private:
            int                 registered;
    static  ToolRegisterPack    entryPoints[];

};

static LocalToolClient  localToolClient;

ToolRegisterPack LocalToolClient::entryPoints[] =
{
    { targetExeSnipName, (ToolMethod)&LocalToolClient::RunTargetExeSnips },
//  { targetDllSnipName, (ToolMethod)&LocalToolClient::RunTargetDllSnips },
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
LocalToolClient::RunTargetExeSnips( ToolInvokeArgs * args )
{
    ToolReq   server;

    ProjectNode node = args->numNodes ? *args->nodeArray : 0;

    if( node )
    {
        ProjectNodeInfo    nodeInfo;
        ProjectReq         project;
        PathSpec           nodePath;
        EditorReq          editor;

        project->QueryNodeInfo( node, nodeInfo );

        nodePath.path( nodeInfo.outputLocation );

        //                                 //
        // Do the [.cpp] main source node  //
        //                                 //
        
        nodePath.ext( ".cpp" );

        project->NodeAdd( node, nodePath.path() );

        editor->set_buffer( editor->create_buffer( 0,
                                                   (char *)nodePath.path(),
                                                   0 ) );

        TargetExpertReq    targetExpert;

        const char * mainSnip;
         
        if( targetExpert->QuerySupports( node, 0, OWL, 0 ) )
           mainSnip = szExeOwlMain;
        else
           mainSnip = szExeWinMain;

        editor->insert( (char *)mainSnip );

        editor->show_buffer();

        //                                 //
        // Do the [.def] main source node  //
        //                                 //

        nodePath.ext( ".def" );
        project->NodeAdd( node, nodePath.path() );
        editor->set_buffer( editor->create_buffer( 0,
                                                   (char *)nodePath.path(),
                                                   0 ) );
        editor->insert( szExeDefSnip );
    }

    return( Success );

}

//                       //
//      Project stuff    //
//                       //

class _HOOKCLASS LocalProjClient : public ProjectClient
{
public:
   LocalProjClient();
   
 virtual void _HOOKEP OpenNotify( const char * name );
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

    if( !ts->ToolFind( targetExeSnipName ) )
    {
        ToolInfo toolInfo;

        toolInfo.toolType      = Viewer;
        toolInfo.name          = targetExeSnipName;
        toolInfo.path          = 0;
        toolInfo.flags         = OnLocalMenu;
        toolInfo.menuName      = "&Target snippets";
        toolInfo.helpHint      = "Generate a skeleton for a target";
        toolInfo.defCmdLine    = 0;
        toolInfo.appliesTo     = ".exe;";
        toolInfo.defaultFor    = 0;
        toolInfo.translateTo   = 0;
        toolInfo.launchId      = CALLBACK_LAUNCH_ID;

        ts->ToolAdd( &toolInfo );
    }
   
}

// End of file

