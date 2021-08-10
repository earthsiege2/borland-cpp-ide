/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

 ioption.h
 Created: 10/10/95
 Copyright (c) 1995, Borland International
 $Header:   Y:\admin\bride\addon\deliver\interfac\ioption.h_v   1.19   18 Nov 1996 11:29:46   JDOUGLAS  $
 $Revision:   1.19  $

 OptionSet Interface
   
 This interface is one of several being brought forward from BC4.x IdeHook
 interface. 
   
 Interface declared in this file:

 implemented by IDE
    IOptionSetServer


 implemented by IDE client
    None

 Overview:
  Client uses IOptionSetServer to manipulate a limited number of options at a
  node. OptionApply() and OptionRemove() only deal with local option values
  while OptionGet() deals with effective option values. An effective option
  values is the resulting option value client sees at node regardless whether
  the node is locally overriden.

:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  
#ifndef __IOPTION_H
#define __IOPTION_H

#include <ideaddon\ipolystr.h>
#include <ideaddon\IOption.uid>
#include <ideaddon\common.h>     // ProjectNode

//.............................................................................
enum OptionsStringIds
{
    OID_RemoveAll = 0,      // remove all local options
    OID_Include,
    OID_Library,
    OID_Source,
    OID_Intermediate,
    OID_Final,
    OID_Defines,
    OID_CmdlineOverride,
    OID_Invalid             // not used
};


//.............................................................................
class IOptionSetServer : public IUnknown
{ 
 public:
   //
   // OptionApply() sets the node's local override for the given option.
   //
   // ProjectNode node     : Specifies the node to apply the option to.
   // OptionsStringIds oid : Specifies the option id.
   // IPolyString * value  : Specifies the new value of the option
   //
   virtual void BCWADDON_CMETHOD OptionApply(  ProjectNode node,
                              OptionsStringIds oid,
                              IPolyString * value ) = 0;

   //
   //
   // OptionGet() gets the node's effective option for the given option id
   //
   // ProjectNode node     : Specifies the node to get the option from.
   // OptionsStringIds oid : Specifies the option id.
   //
   // 
   // IDEHOOK CHANGES:
   // -  The returned option string is now retrieved through the IPolyString
   //    pointer.
   //
   virtual IPolyString * BCWADDON_CMETHOD OptionGet( ProjectNode node,
                                    OptionsStringIds oid ) = 0;

   //
   // OptionRemove() removes the node's local override for the given option.
   //                if oid == OID_RemoveAll, this will remove all local options. 
   // ProjectNode node     : Specifies the node the the option is to be removed.
   // OptionsStringIds oid : Specifies the option id.
   //
   virtual void BCWADDON_CMETHOD OptionRemove( ProjectNode node,
                              OptionsStringIds oid ) = 0;
};
                                       
#endif      //  __IOPTION_H
