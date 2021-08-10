/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  mpdtest.cpp
  Created: 10/24/95
  Copyright (c) 1995, Borland International
  $Revision:   1.19  $
    
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/ 
#ifndef __AOEXPCH_H
  #include "aoexpch.h"
#endif
#pragma hdrstop

#include <owl\window.h>
#include <ideaddon\impd.h>
#include "mpdtest.h"
#include "addonpg.h"


/******************************************************************************
*
* MpdTest
*  MpdText demonstrates Enviroment and Project chapter in IDE
*
******************************************************************************/

MpdTest::MpdTest() {
  d_chapPrj = 0;
  d_chapEnv = 0;
}

MpdTest::~MpdTest() {}

const char * MpdTest::GetName() { return "MPD test";}

BOOL MpdTest::Init() 
{
  d_impdServer = GET_INTERFACE(IMpdServer);

  OutStr("Addon_Mpd created, click Test1 to add test chapter");
  return TRUE;
}


void MpdTest::UnInit() 
{
  if (d_impdServer) {
    d_impdServer->Release();
    d_impdServer = 0;
  }
}


const char * MpdTest::GetTestDescription( int testNum ) 
  {
  switch ( testNum )
    {
    case 1: 
      return "Add MPD pages to Project";
    case 2:
      return "Remove MPD pages from Project";
    case 3: 
      return "Add MPD pages to Enviroment";
    case 4: 
      return "Remove MPD pages from Environment";
    }
  return "This test not implemented";
  } 



void MpdTest::DoTest1() {
  //
  // add this Project to environment MPD
  //
  IMpdProjectChapterAddon* c = new IMpdProjectChapterAddon;
  d_chapPrj = c;
  c->Init();
  d_chapPrj->AddRef();
  d_impdServer->RegisterChapter(d_chapPrj, MT_ProjectOptions);

  OutStr("Test chapter registered, select Option->Project to see new pages");
}

void MpdTest::DoTest2() {
  if ( d_chapPrj ) {   
    d_impdServer->UnRegisterChapter(d_chapPrj);  // object will be released
    d_chapPrj = 0;
  }
};

void MpdTest::DoTest3() {
  //
  // add this chapter to environment MPD
  //
  IMpdChapterAddon* c = new IMpdChapterAddon;
  d_chapEnv = c;
  c->Init();

  d_chapEnv->AddRef();
  d_impdServer->RegisterChapter(d_chapEnv, MT_EnvironmentOptions);

  OutStr("Test chapter registered, select Option->Environment to see new pages");
}

void MpdTest::DoTest4() {
  if ( d_impdServer ) {
    d_impdServer->UnRegisterChapter(d_chapEnv);  // object will be released
    d_chapEnv = 0;
  }
};

void MpdTest::DoTest( int testNum ) 
{
  switch ( testNum ) 
  { 
    case 1: 
      DoTest1();
      break;
    case 2: 
      DoTest2();
      break;
    case 3:
      DoTest3();
      break;
    case 4:
      DoTest4();
      break;
    default: 
    {
      OutStr( FormatStr( "Test #%d Not Implemented!", testNum ) );
      break;
    }
  }
}


