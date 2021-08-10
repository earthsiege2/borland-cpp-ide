/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

 ITarget.h
 Created: 09/12/95
 Copyright (c) 1995, 1996 Borland International
 $Header:   Y:\admin\bride\addon\deliver\interfac\itarg.h_v   1.19   18 Nov 1996 11:30:00   JDOUGLAS  $
 $Revision:   1.19  $

 Target Interfaces 
       
 Interface declared in this file:

 implemented by IDE
    ITargetServer

 implemented by IDE client
    None

 Overview:
    Cleint uses ITargetServer to create IDE built-in target.  Cleint can also
    create a target thru ITargetType interface if one is available.

    NOTE: Currently there is no way for client to query Target manager for a
          ITargetType.
      
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  

#ifndef _TARG_H_
#define _TARG_H_

#include <objbase.h>
#include <ideaddon\ipolystr.h>
#include	<ideaddon\Itarg.uid>
#include <ideaddon\common.h>

//.............................................................................
enum TargetType 
{
   TT_Application,         // default
   TT_Dll,
   TT_EasyWin,
   TT_StaticLib,
   TT_ImportLib,
   TT_WinHelp,
   TT_DosCom
};

//.............................................................................
enum TargetPlatform
{
   TP_Win16,
   TP_Win32,               // default
   TP_Dos16,
   TP_DosOverlay
};

//.............................................................................
enum TargetStdLibs      // may be combined
{
   TL_Owl =          0x0001,
   TL_Bids =         0x0002,
   TL_Rtl =          0x0004,
   TL_Bwcc =         0x0008,
   
   TL_TVision =      0x0010,
   TL_Bgi =          0x0020,

   TL_Math =         0x0100,
   TL_Emu =          0x0200,
   TL_C0F =          0x0400,
   TL_Ctl3d =        0x0800,

   TL_Static  =      0x1000,
   TL_Dynamic =      0x2000,
   TL_NoEH =         0x4000,     // no exception handling
   
   TL_Ole2 =         0x10000,
   TL_Ocf =          0x20000,
   TL_Vbx =          0x40000,
   TL_Codeguard =    0x80000,
   
   TL_Mfc3 =         0x100000,
   TL_Mfc4 =         0x200000,
   TL_Diagnostic =   0x400000,
   TL_Multithread =  0x800000,
   
   TL_StdLibs =      TL_Bids | TL_Rtl | TL_Bwcc | TL_Emu,      // default

   TL_AllLibs =      TL_StdLibs | TL_Owl,
}; 

//.............................................................................
enum TargetModel
{
   TM_Tiny,
   TM_Small,
   TM_Medium,
   TM_Compact,
   TM_Large,      // default if platform is not Win32
   TM_Huge,

   TM_Gui,        // default if platform is Win32
   TM_WinConsole,
   TM_FsConsole
};

//.............................................................................
class ITargetServer : public IUnknown 
{
 public:
   //
   // Adds a target node to the project.
   // 
   // IDEHOOK CHANGES:
   //    - Some options have changed (see enum's above).
   //    - 'type' is now an enum.
   //    - more default args and arg order has changed.
   //
   virtual ProjectNode BCWADDON_CMETHOD TargetAdd(   IPolyString * name,
                                    ProjectNode parent = 0,
                                    TargetType type = TT_Application,
                                    TargetPlatform platform = TP_Win32,
                                    int libs = TL_StdLibs,
                                    TargetModel model = TM_Gui ) = 0;

   //
   // Asks the node if it is a target.
   // IDEHOOK CHANGES:
   //    - Now returns a bool instead of int
   //
   virtual BOOL BCWADDON_CMETHOD NodeIsTarget( ProjectNode node ) = 0;

   //
   // Returns the target of the specified node.
   //
   virtual ProjectNode BCWADDON_CMETHOD FindNodesTarget( ProjectNode node ) = 0;

   virtual BOOL BCWADDON_CMETHOD QuerySupports(   ProjectNode node,
                                 TargetPlatform platform,
                                 int libs,
                                 TargetModel model ) = 0;
                                 
   virtual ProjectNode BCWADDON_CMETHOD ConvertNodeToTarget( ProjectNode node,
                                        TargetType type,
                                        TargetPlatform platform,
                                        int libs,
                                        TargetModel model) = 0;
   //
   // converts a target to a node. return 0 if sucesful, otherwise 1 is returned
   //
   virtual BOOL BCWADDON_CMETHOD ConvertTargetToNode(ProjectNode node) = 0;
};


#endif






