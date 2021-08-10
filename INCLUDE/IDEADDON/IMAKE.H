/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  imake.h
  Created: 10/11/95
  Copyright (c) 1995, Borland International
  $Revision:   1.15  $

  Make Interface

:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
#ifndef __IMAKE_H
#define __IMAKE_H
  

#include <ideaddon\IMakeSvr.uid>
#include <ideaddon\common.h>

//.............................................................................
enum MakeMode
{
   MM_Make,
   MM_Build,
   MM_Translate
};

//.............................................................................
class IMakeClient : public IUnknown
{
 public:
  virtual void MakeBeginNotify() = 0;
  virtual void MakeEndNotify()  = 0;
};

//.............................................................................
class IMakeServer : public IUnknown
{
 public:
  // 
  // Use this method when you wish to start recieving events.
  //
  virtual void RegisterMakeClient( IMakeClient * ) = 0;

  // 
  // Use this method when you are done with a command.
  // Your IMakeClient object will be released by this call.
  //
  virtual void UnRegisterMakeClient( IMakeClient * ) = 0;

  virtual void MakeNodes( MakeMode mode, 
                  ProjectNode * nodes, 
                  int numNodes = 1 ) = 0;

  virtual long NodeInputAge( ProjectNode node ) = 0;

  virtual long NodeOutputAge( ProjectNode node ) = 0;

};


#endif    //  __IMAKE_H
