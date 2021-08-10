/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  msgcli.h
  Created: 06/27/96
  Copyright (c) 1996, Borland International
  $Revision:   1.0  $

  MessageClientTest
   
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  
#ifndef __MSGCLI_H
#define __MSGCLI_H

#include <ideaddon\comhelp.h>
#include <ideaddon\imsgsys.h>

#include "tests.h"


class MessageClientTest :  public TestObject, 
                  public IUnknownImp< IMessageClient > {
 public:                  
  MessageClientTest();
  
  //........  IMessageClient methods ........ 
  virtual BOOL CanHandleMessage( 
      IPolyString * handlerType, 
      IPolyString * action );
  
  virtual void HandleMessage( 
      IPolyString * action,
      int column,
      int line,
      IPolyString * filePath );
  


  //........ TestObject Methods .......
  virtual BOOL Init();
  virtual void UnInit();  
  virtual const char * GetName();
  virtual const char * GetTestDescription( int testNum );
  virtual void DoTest( int testNum );
  
 protected: 
  void warnIfTooLate();
  bool _tooLateToStartHandling;
  bool _showHandlingEnabled;  
  bool _viewHandlingEnabled;
  bool _editHandlingEnabled;
};

#endif    // __MSGCLI_H
