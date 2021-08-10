//----------------------------------------------------------------------------
// IdeHook - (C) Copyright 1994 by Borland International
//----------------------------------------------------------------------------
#pragma hdrstop

#include "idehook.h"
#include <windows.h>


//  Editor addon

static char szClassHeader[] =
{
    "//\n"
    "//   Class:\n"
    "//\n"
    "//   Description:\n"
    "//\n"
    "//   Last modified date:\n"
    "//   Last modified by:  \n"
    "//\n"
};


int KeyStrokeTest2( KeyStroke * )
{
    EditorReq   editor;

    long    line;
    long    col;

    editor->inq_position( &line, &col );
    while( col-- )
        editor->left();
    editor->down();

    editor->insert( szClassHeader );

    return(1);
}

int KeyStrokeTest1( KeyStroke * )
{
    EditorReq   editor;

    long    line;
    long    col;

    editor->inq_position( &line, &col );
    while( col-- )
        editor->left();
    editor->drop_anchor();
    editor->end_of_line();
    editor->raise_anchor();

    return(1);
}


//
//      Project stuff
//

class _HOOKCLASS LocalProjClient : public ProjectClient
{
public:
    LocalProjClient();
   
    virtual void _HOOKEP OpenNotify( const char * name );
    virtual void _HOOKEP CloseNotify()  {}
    virtual void _HOOKEP NodeDeleteNotify(ProjectNode) {}
    virtual void _HOOKEP DependencyQueryResponder(ProjectNode,const char*) {}

    int _registered;

};

LocalProjClient::LocalProjClient()
{
   ProjectReq ps;

   ps->RegisterProjectClient(this);
}

static LocalProjClient LocalProjClient;


#define NUM_KEYSTROKES  (sizeof(keyStrokes)/sizeof(keyStrokes[0]))

static KeyStroke    keyStrokes[] =
{
    { WM_KEYDOWN, VK_F11, NoModifier,  KeyStrokeTest2 },
    { WM_KEYDOWN, VK_F11, Shift,       KeyStrokeTest1 }
};

void _HOOKEP    
LocalProjClient::OpenNotify
(
   const char * // name 
)
{
    if( !_registered )
    {
        EditorReq   editor;

        editor->register_keyhit_handlers( keyStrokes, NUM_KEYSTROKES );

        _registered = 1;
    }
}
    
// End of file

