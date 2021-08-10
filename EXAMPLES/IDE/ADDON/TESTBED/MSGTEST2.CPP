#ifndef __AOEXPCH_H
  #include "aoexpch.h"
#endif
#pragma hdrstop

#include <ideaddon\imsgsys.h>


#include "msgtest2.h"
#include "helpids.hh"

const char* HelpFileName = "..\\examples\\ide\\addon\\testbed\\testhelp.hlp";


///////////////////////////
// MsgTest Implementation
///////////////////////////


MsgTest::MsgTest()
      : folder(0), folder2(0), parentMsg(0)
{
}


MsgTest::~MsgTest()
{
  if( folder )
     folder->Release();

  if( folder2 )
     folder2->Release();
}


BOOL MsgTest::Init()
{
  OutStr( "MsgTest::Init()" );
  IMessageSystem* msgSys = GET_INTERFACE( IMessageSystem );
  if( !msgSys )  {
     OutStr( "Couldn't get IMessageSystem" );
     return FALSE;
  }

  folder = msgSys->NewFolder( MakePolyString("Addon"),
                     MakePolyString("Buildtime")
                    );
  msgSys->Release();
                    
  if( !folder )  {
     OutStr( "Couldn't get IMessageFolder" );
     return FALSE;
  }
  
  return TRUE;
}


void MsgTest::UnInit()
{
  OutStr( "MsgTest::UnInit()" );
}


const char* MsgTest::GetName()
{
   return "Message System Test 2";
}


const char* MsgTest::GetTestDescription(int testNum)
{
   switch( testNum )  {
      case 1:
        return "Add Top Level Message to Buildtime tab of Message View";
      case 2:
        return "Add Child Message to Message created in Test 1";
      case 3:
        return "Add Group of nested messages with auto scroll support";
      case 4:
        return "Add Group of top level messages with auto scroll suppport"; 

      default:
        return "This test is not yet implemented";
   }
}


void MsgTest::DoTest(int testNum)
{
   switch( testNum )  {
      case 1:  {
        parentMsg = folder->NewFileMessage( MakePolyString("msgtest.cpp"),
                                MakePolyString("Message Test")
                               );  
        break;
      }
      
      case 2:  {
        if( !parentMsg )  {
           OutStr( "Please run test 1 first" );
           break;
        }

        folder->NewMessage( parentMsg, 
                      MakePolyString("msgtest.cpp"),
                      MakePolyString("No help associated with this message"),
                      97, 13, ADDON_MESSAGE_STRING 
                    );  
        
        break;
      }     
      
      case 3:  {
        if( folder2 )  {
           folder2->Release();
           folder2 = 0;
        }

        folder2 = QUERY_INTERFACE( folder, IMessageFolder2 );
        if( !folder2 )  {
           OutStr( "Couldn't get IMessageFolder2" );
           break;
        }

        folder2->BeginAutoScrollGroup();
        
        parentMsg = folder->NewFileMessage( MakePolyString("msgtest.cpp"),
                                MakePolyString("AutoScroll Test")
                               );  
        folder2->NewMessage2( parentMsg,
                       MakePolyString("msgtest.cpp"),
                       MakePolyString("Warning "),
                       138, 0, ADDON_MESSAGE_WARNING,
                       IDH_CM_ADDONWARN, 
                       MakePolyString(HelpFileName)
                      );  
                     
        folder2->NewMessage2( parentMsg,
                       MakePolyString("msgtest.cpp"),
                       MakePolyString("Fatal "),
                       146, 0, ADDON_MESSAGE_FATAL,
                       IDH_CM_ADDONFATAL, 
                       MakePolyString(HelpFileName)
                      );  
        
        folder2->NewMessage2( parentMsg,
                       MakePolyString("msgtest.cpp"),
                       MakePolyString("Error "),
                       154, 0, ADDON_MESSAGE_ERROR,
                       IDH_CM_ADDONERROR, 
                       MakePolyString(HelpFileName)
                      );  

        folder2->EndAutoScrollGroup();

        break;
      }     

      case 4:  {
        if( folder2 )  {
           folder2->Release();
           folder2 = 0;
        }

        folder2 = QUERY_INTERFACE( folder, IMessageFolder2 );
        if( !folder2 )  {
           OutStr( "Couldn't get IMessageFolder2" );
           break;
        }

        folder2->BeginAutoScrollGroup();

        folder2->NewMessage2( 0,
                       MakePolyString("msgtest.cpp"),
                       MakePolyString("Warning "),
                       175, 0, ADDON_MESSAGE_WARNING,
                       IDH_CM_ADDONWARN, 
                       MakePolyString(HelpFileName)
                      );  
                     
        folder2->NewMessage2( 0,
                       MakePolyString("msgtest.cpp"),
                       MakePolyString("Fatal "),
                       183, 0, ADDON_MESSAGE_FATAL,
                       IDH_CM_ADDONFATAL, 
                       MakePolyString(HelpFileName)
                      );  
        
        folder2->NewMessage2( 0,
                       MakePolyString("msgtest.cpp"),
                       MakePolyString("Error "),
                       191, 0, ADDON_MESSAGE_ERROR,
                       IDH_CM_ADDONERROR, 
                       MakePolyString(HelpFileName)
                      );  

        folder2->EndAutoScrollGroup();

        break;

        
      }

      default:
        OutStr( FormatStr( "Test #%d Not Implemented!", testNum ) );
   }

}
