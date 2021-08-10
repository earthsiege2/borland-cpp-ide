//----------------------------------------------------------------------------
// IdeHook - (C) Copyright 1994 by Borland International
//----------------------------------------------------------------------------
#pragma hdrstop

#include "idehook.h"
#include <string.h>

static char wipeOptsName[] = "OptionsWiper";


class _HOOKCLASS LocalToolClient : public ToolClient
{
public:
    ToolReturn _HOOKEP RunOptionWiper( ToolInvokeArgs * );

    void RegisterMyCallBacks( ToolServer * );

private:

   void WipeNodeOptions( ProjectNode, ProjectServer *, OptionSetServer * );

            int                 registered;
    static  ToolRegisterPack    entryPoints[];

};

static LocalToolClient  localToolClient;

ToolRegisterPack LocalToolClient::entryPoints[] =
{
    { wipeOptsName, (ToolMethod)&LocalToolClient::RunOptionWiper },
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

void
LocalToolClient::WipeNodeOptions
(
   ProjectNode         node,
   ProjectServer *     projectServer,
   OptionSetServer *  optSetServer
)
{
    optSetServer->OptionRemove( node, OID_RemoveAll );

    ProjectNodeInfo    nodeInfo;

    projectServer->QueryNodeInfo( node, nodeInfo );

    node = nodeInfo.firstChild;

    while( node )
    {
       WipeNodeOptions( node, projectServer, optSetServer );

       projectServer->QueryNodeInfo( node, nodeInfo );

       node = nodeInfo.nextSibling;
    }
}

ToolReturn _HOOKEP 
LocalToolClient::RunOptionWiper( ToolInvokeArgs * args )
{
    int count = args->numNodes;

    ProjectReq     projectServer;
    OptionSetReq   optSetServer;
    
    for( int i = 0; i < count; i++ )
    {
       ProjectNode   node = args->nodeArray[i];

       WipeNodeOptions( node, projectServer, optSetServer );
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

    if( !ts->ToolFind( wipeOptsName ) )
    {
        ToolInfo toolInfo;

        toolInfo.toolType      = Transfer;
        toolInfo.name          = wipeOptsName;
        toolInfo.path          = 0;
        toolInfo.flags         = OnToolsMenu;
        toolInfo.menuName      = "&Options Wiper";
        toolInfo.helpHint      = "Delete the local overrides for node(s)";
        toolInfo.defCmdLine    = 0;
        toolInfo.appliesTo     = 0;
        toolInfo.defaultFor    = 0;
        toolInfo.translateTo   = 0;
        toolInfo.launchId      = CALLBACK_LAUNCH_ID;

        ts->ToolAdd( &toolInfo );
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

