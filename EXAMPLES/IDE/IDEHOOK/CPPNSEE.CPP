//----------------------------------------------------------------------------
// IdeHook - (C) Copyright 1994 by Borland International
//----------------------------------------------------------------------------
#pragma hdrstop

#include "idehook.h"
#include <string.h>
#include <windows.h>

static char realCppPreprocess[]  = "CppPreprocessor";
static char myPreprocessorName[] = "CppPreprocessAndSee";


class _HOOKCLASS LocalToolClient : public ToolClient
{
public:
    ToolReturn _HOOKEP RunPreprocessor( ToolInvokeArgs * );

    void RegisterMyCallBacks( ToolServer * );

private:

            int                 registered;
    static  ToolRegisterPack    entryPoints[];

};

static LocalToolClient  localToolClient;

ToolRegisterPack LocalToolClient::entryPoints[] =
{
    { myPreprocessorName, (ToolMethod)&LocalToolClient::RunPreprocessor },
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
LocalToolClient::RunPreprocessor( ToolInvokeArgs * args )
{
    ToolReq   server;

    ProjectNode node = args->numNodes ? *args->nodeArray : 0;

    ToolObj preprocessor = server->ToolFind( realCppPreprocess );
    ToolObj editTool = 0;
    
    if( preprocessor )
    {
        if( server->ToolInvoke( preprocessor, node, 0 ) == Success )
        {
           if( (editTool = server->ToolFind( "EditText" )) == 0 )
           {
               ::MessageBox( ::GetActiveWindow(), 
                               "Can't find editor!",
                               "Error!", 
                               MB_ICONEXCLAMATION | MB_OK );
           }
        }
        else
        {
           ::MessageBox( ::GetActiveWindow(), 
                           "CppPreprocess did not complete ok!",
                           "Error!", 
                           MB_ICONEXCLAMATION | MB_OK );
        }
    }

    if( editTool )
    {
        ProjectNodeInfo     nodeInfo;
        ProjectReq          projectServer;

        projectServer->QueryNodeInfo( node, nodeInfo );

        char * str = new char [ strlen( nodeInfo.outputLocation ) + 3 ];

        strcpy( str, nodeInfo.outputLocation );

        char * pdot = strrchr( str, '.' );

        if( pdot )
            *pdot = 0;

        strcat( str, ".i" );

        return( server->ToolInvoke( editTool, str ) );
    }

    return( Errors );

}

//
//      Project stuff
//
class _HOOKCLASS LocalProjClient : public ProjectClient
{
public:
   LocalProjClient();
   
    virtual void _HOOKEP    OpenNotify
                                    (
                                        const char * name 
                                    );
    
    virtual void _HOOKEP    CloseNotify();

    virtual void _HOOKEP NodeDeleteNotify
                                    (
                                        ProjectNode
                                    );
                                
    virtual void _HOOKEP  DependencyQueryResponder
                                    (
                                        ProjectNode , 
                                        const char * 
                                    );

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

    if( !ts->ToolFind( myPreprocessorName ) )
    {
        ToolObj realPreProcessor;

        if( (realPreProcessor = ts->ToolFind( realCppPreprocess )) != 0 )
        {
            ToolInfo toolInfo;

            ts->QueryToolInfo( realPreProcessor, toolInfo );

            toolInfo.toolType       = Viewer;
            toolInfo.name           = myPreprocessorName;
            toolInfo.menuName       = "&Preprocess and see";
            toolInfo.defCmdLine     = 0;
            toolInfo.helpHint       = "Preprocess a c/c++ file and dump"
                                      " into editor";
            toolInfo.launchId       = CALLBACK_LAUNCH_ID;

            ts->ToolAdd( &toolInfo );
        }
    }
   
}
    
void _HOOKEP    
LocalProjClient::CloseNotify()
{
}

void _HOOKEP 
LocalProjClient::NodeDeleteNotify
(
   ProjectNode
)
{
}
                                                
void _HOOKEP  
LocalProjClient::DependencyQueryResponder
(
   ProjectNode , 
   const char * 
)
{
}
    

// End of file

