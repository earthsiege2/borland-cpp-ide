//---------------------------------------------------------------------------
//    condefs.h - defines needed by Borland C++ Builder console apps
//---------------------------------------------------------------------------
// $Revision:   1.3.1.0  $
//-------------------------------------------------------------------------
//    copyright (c) 1997 Borland International
//----------------------------------------------------------------------------
#ifndef CONDEFS_H
#define CONDEFS_H
//---------------------------------------------------------------------------
#if defined(_NO_VCL)

#define USEUNIT(ModName) \
   extern DummyThatIsNeverReferenced
//-----------------------------------------------------------------------
#define USEOBJ(FileName) \
   extern DummyThatIsNeverReferenced
//-----------------------------------------------------------------------
#define USERC(FileName) \
   extern DummyThatIsNeverReferenced
//-----------------------------------------------------------------------
#define USEASM(FileName) \
   extern DummyThatIsNeverReferenced
//-----------------------------------------------------------------------
#define USEDEF(FileName) \
   extern DummyThatIsNeverReferenced
//-----------------------------------------------------------------------
#define USERES(FileName) \
   extern DummyThatIsNeverReferenced
//-----------------------------------------------------------------------
#define USETLB(FileName) \
   extern DummyThatIsNeverReferenced
//-----------------------------------------------------------------------
#define USELIB(FileName) \
   extern DummyThatIsNeverReferenced
//-----------------------------------------------------------------------
#define USEFILE(FileName) \
   extern DummyThatIsNeverReferenced
//-----------------------------------------------------------------------
#define USEIDL(FileName) \
   extern DummyThatIsNeverReferenced
//-----------------------------------------------------------------------
#define USE(FileName, ContainerID) \
   extern DummyThatIsNeverReferenced
//-----------------------------------------------------------------------
#else // _NO_VCL
# include <vcl.h>
#endif // _NO_VCL

#endif // CONDEFS_H
