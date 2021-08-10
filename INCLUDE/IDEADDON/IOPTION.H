/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  ioption.h
  Created: 10/10/95
  Copyright (c) 1995, Borland International
  $Revision:   1.15  $

  OptionSet Interface
  
  This interface is one of several being brought forward from BC4.x IdeHook
  interface. 

:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  
#ifndef __IOPTION_H
#define __IOPTION_H

#include <ideaddon\ipolystr.h>
#include <ideaddon\IOption.uid>
#include <ideaddon\common.h>    // ProjectNode

//.............................................................................
enum OptionsStringIds
{
   OID_RemoveAll = 0,
   OID_Include,
   OID_Library,
   OID_Source,
   OID_Intermediate,
   OID_Final,
   OID_Defines,
   OID_CmdlineOverride,
   OID_Invalid
};


//.............................................................................
class IOptionSetServer : public IUnknown
{ 
 public:
  //
  // Set the node's local override for the given option
  //
  virtual void OptionApply(  ProjectNode node,
                    OptionsStringIds oid,
                    IPolyString * value ) = 0;

  //
  // Get the node's local override for the given option
  // 
  // IDEHOOK CHANGES:
  // -  The returned option string is now retrieved through the IPolyString
  //   pointer.
  //
  virtual IPolyString * OptionGet( ProjectNode node,
                        OptionsStringIds oid ) = 0;

  //
  //  Remove the node's local override for the given option. This
  //  removes *all* local overrides if oid == OID_RemoveAll.
  //
  virtual void OptionRemove( ProjectNode node,
                    OptionsStringIds oid ) = 0;
};
                          
#endif    //  __IOPTION_H
