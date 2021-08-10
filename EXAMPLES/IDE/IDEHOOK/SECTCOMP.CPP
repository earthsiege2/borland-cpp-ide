//----------------------------------------------------------------------------
// IdeHook - (C) Copyright 1994 by Borland International
//----------------------------------------------------------------------------
#pragma hdrstop

#include "idehook.h"
#include "pathspec.h"
#include <string.h>

static char realCppCompileName[]    = "CppCompile";
static char sectionCppCompileName[] = "SectionCppCompile";


class _HOOKCLASS LocalToolClient : public ToolClient
{
public:
    ToolReturn _HOOKEP RunSectionCompiler( ToolInvokeArgs * );

    void RegisterMyCallBacks( ToolServer * );

private:

            int                 registered;
    static  ToolRegisterPack    entryPoints[];

};

static LocalToolClient  localToolClient;

ToolRegisterPack LocalToolClient::entryPoints[] =
{
    { sectionCppCompileName, (ToolMethod)&LocalToolClient::RunSectionCompiler },
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
LocalToolClient::RunSectionCompiler( ToolInvokeArgs * args )
{
    ProjectNode   node = args->numNodes ? *args->nodeArray : 0;

    if( node )
    {
        OptionSetReq    optSetServer;
        const char *    defines;

        optSetServer->OptionGet( node, OID_Defines, defines );

        const char *    pSectionText;
        static char     szSection[] = "SECTION=";

        if( (pSectionText = strstr( defines, szSection)) != 0 )
        {
            ProjectNodeInfo    nodeInfo;
            ProjectReq         projectServer;

            projectServer->QueryNodeInfo( node, nodeInfo );

            PathSpec           outPath( nodeInfo.outputLocation );

            char               newName[ MAXFILE + 2 ];

            strcpy( newName, outPath.file() );

            int    numberIndex = strlen(newName);

            if( numberIndex == 8 )
                --numberIndex;

            newName[ numberIndex++ ] = *(pSectionText + (sizeof(szSection)-1));
            newName[ numberIndex ] = 0;

            outPath.file( newName );

            optSetServer->OptionApply( node, OID_Intermediate, outPath.path() );

        }

        ToolReq  server;
        ToolObj  realCompiler = server->ToolFind( realCppCompileName );

        return( server->ToolInvoke( realCompiler, node ) );

    }

    return( NotHandled );

}


//
//  Project stuff
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

    if( !ts->ToolFind( sectionCppCompileName ) )
    {
        ToolObj realCppCompiler;

        if( (realCppCompiler = ts->ToolFind( realCppCompileName )) != 0 )
        {
            ToolInfo toolInfo;

            ts->QueryToolInfo( realCppCompiler, toolInfo );

            toolInfo.name           = sectionCppCompileName;
            toolInfo.menuName       = "&Section Compiler";
            toolInfo.helpHint       = "Munge outname of node then C++ Compile";
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

