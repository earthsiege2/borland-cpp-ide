#ifndef __AOEXPCH_H
  #include "aoexpch.h"
#endif
#pragma hdrstop

#include <ideaddon\iidewin.h>
#include "ideuitst.h"



///////////////////////////
// IdeUITest Implementation
///////////////////////////


IdeUITest::IdeUITest() 
          : ideui( 0 )
{
}


IdeUITest::~IdeUITest()
{
  if( ideui )
      ideui->Release();
}


BOOL IdeUITest::Init()
{
   OutStr( "IdeUITest::Init()" );
   ideui = GET_INTERFACE( IIdeUI );
   if( !ideui )  {
     OutStr( "Couldn't get IdeUI interface" );
     return FALSE;
   }
     
   return TRUE;
}


void IdeUITest::UnInit()
{
  OutStr( "IdeUITest::UnInit()" );
}


const char* IdeUITest::GetName()
{
   return "IdeUI Test";
}


const char* IdeUITest::GetTestDescription(int testNum)
{
    switch(testNum)  {
        case 1:
          return "Start Hourglass Cursor for a few seconds";
        case 2:
          return "Display IDE MessageBoxes";
        default: 
          return "Test Not Implemented";
    }
}


void IdeUITest::DoTest(int testNum)
{
    switch(testNum)  {
        case 1:  {
          ideui->StartWait();
          OutStr( "Waiting for a few seconds" );
          Sleep( 4000 );
          OutStr( "Done Waiting" );
          ideui->StopWait();
          break;
        }  
        case 2:
          RunMessageBoxes();
          break;
        default:
          OutStr( "Test not implemented." );
    }
}


void IdeUITest::RunMessageBoxes()
{
   IIdeWindow* idewin = GET_INTERFACE( IIdeWindow );
   HWND parent = idewin->GetHwnd();
   idewin->Release();
   
   ideui->InfoBox( parent, "InfoBox" );
   ideui->GetYesNoBox( parent, "YesNoBox" );
   ideui->DoOkCancelBox( parent, "OkCancelBox" );
   ideui->ErrorBox( parent, "ErrorBox" );
}

