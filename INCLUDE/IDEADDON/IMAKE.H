/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

   imake.h
   Created: 10/11/95
   Copyright (c) 1995, Borland International
   $Header:   Y:\admin\bride\addon\deliver\interfac\imake.h_v   1.19   18 Nov 1996 11:29:34   JDOUGLAS  $
   $Revision:   1.19  $

   Make Interface
   
   Interfaces declared in this file:

   implemented by IDE
    IMakeServer


   implemented by IDE client
    IMakeClient

   Overview:
    Client implements IMakeClient when client wants to receive make notification.

:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
#ifndef __IMAKE_H
#define __IMAKE_H
  

#include <ideaddon\IMakeSvr.uid>
#include <ideaddon\common.h>

//.............................................................................
enum MakeMode
{
    MM_Make,
    MM_Build,       // build this node and all its dependents
    MM_Translate    // build this node only
};

//.............................................................................
class IMakeClient : public IUnknown
{
 public:
   virtual void BCWADDON_CMETHOD MakeBeginNotify() = 0;
   virtual void BCWADDON_CMETHOD MakeEndNotify()   = 0;
};

//.............................................................................
class IMakeServer : public IUnknown
{
 public:
   // 
   // Use this method when you wish to start recieving events.
   //
   virtual void BCWADDON_CMETHOD RegisterMakeClient( IMakeClient * ) = 0;

   // 
   // Use this method when you are done with a command.
   // Your IMakeClient object will be released by this call.
   //
   virtual void BCWADDON_CMETHOD UnRegisterMakeClient( IMakeClient * ) = 0;

   virtual void BCWADDON_CMETHOD MakeNodes( MakeMode mode, 
                           ProjectNode * nodes, 
                           int numNodes = 1 ) = 0;

   virtual long BCWADDON_CMETHOD NodeInputAge( ProjectNode node ) = 0;

   virtual long BCWADDON_CMETHOD NodeOutputAge( ProjectNode node ) = 0;

};


#endif      //  __IMAKE_H
