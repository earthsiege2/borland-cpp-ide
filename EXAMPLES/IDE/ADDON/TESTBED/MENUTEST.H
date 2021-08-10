/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  menutest.h
  Created: 10/24/95
  Copyright (c) 1995, Borland International
  $Revision:   1.15  $
   
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  
#ifndef __MENUTEST_H
#define __MENUTEST_H

#include <ideaddon\icmd.h>
#include <ideaddon\imenu.h>
#include "tests.h"

//.............................................................................
class myMenuClient : public IUnknownImp< IMenuClient > {
 public:
  myMenuClient() : IUNKNOWNIMPL_INIT( IMenuClient ) {
    _menuAvailable = TRUE;
  }
  BOOL AddItemToMenu( IMenuItem * item ) {
    item->Release();
    return _menuAvailable;
  }
  BOOL MenuAvailable() { return _menuAvailable; }
  void MenuAvailable( BOOL b ) { _menuAvailable = b; }
 protected:
  BOOL _menuAvailable;
}; 
//.............................................................................
class MenuTestA : public TestObject {
 public:
  MenuTestA();
  ~MenuTestA();

  //........ TestObject Methods .......
  virtual BOOL Init();
  virtual void UnInit();  
  virtual const char * GetName();
  virtual const char * GetTestDescription( int testNum );
  virtual void DoTest( int testNum );

 protected:
  IMenuServer  * _menuServer;
  ICommandServer * _cmdServer;
  BOOL         _startInitFailed;
  ICommand     * _openFileCmd;
  ICommand     * _windowCmd;
  IMenuItem   * _pWindowMenuItem;
  IMenuItem   * _pOpenFileMenu1;
  IMenuItem   * _pOpenFileMenu2;
  IMenuItem   * _pEditorMenu;
  IMenuItem   * _pWindowRestoreMenu;
  myMenuClient  * _myMenuClient;
}; 
//.............................................................................
class MenuTestB : public TestObject {
 public:
  MenuTestB();
  ~MenuTestB();

  //........ TestObject Methods .......
  virtual BOOL Init();
  virtual void UnInit();  
  virtual const char * GetName();
  virtual const char * GetTestDescription( int testNum );
  virtual void DoTest( int testNum );

 protected:
  IMenuServer  * _menuServer;
  ICommandServer * _cmdServer;
  ICommand * _cmd1;
  ICommand * _cmd2;
  ICommand * _cmd3;
  ICommand * _cmd4;
  IMenuItem * _menu1;
  IMenuItem * _menu2;
  IMenuItem * _menu3;
  IMenuItem * _menu4;
}; 


#endif    //  __MENUTEST_H
