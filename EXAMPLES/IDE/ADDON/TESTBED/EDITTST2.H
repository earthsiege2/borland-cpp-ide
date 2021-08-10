/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  edittst2.h
  Created: 03/10/96
  Copyright (c) 1996, Borland International
  $Revision:   1.2  $
  
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  
#ifndef __EDITTST2_H
#define __EDITTST2_H

#include <ideaddon\ieditor.h>
#include "tests.h"

//.............................................................................
class EditTestC : public TestObject {
 public:
  EditTestC();
  virtual ~EditTestC();

  //........ TestObject Methods .......
  virtual BOOL Init();
  virtual void UnInit();
  virtual const char * GetName();
  virtual const char * GetTestDescription( int testNum );
  virtual void DoTest( int testNum );

 protected:
  IEditorServer * _editServer;
};

//.............................................................................
BufferId bid = -1;

#endif   //  __EDITTST2_H
