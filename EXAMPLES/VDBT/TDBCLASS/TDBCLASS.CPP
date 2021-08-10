//----------------------------------------------------------------------------
//  Project Tdbaccap
//  
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    Tdbclass Application
//  FILE:         tdbclass.cpp
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Source file for TDBWindow.
//
//----------------------------------------------------------------------------


#include <owl\pch.h>
#include <vdbt\dbedit.h>
#include <vdbt\dbnvgtr.h>
#include <vdbt\dbacc.h>

//derived class that will contian the VDBT controls
class TDBWindow : public TWindow , public TVbxEventHandler
{
public:
   TDBWindow( );
   ~TDBWindow(){};

   virtual void SetupWindow();

protected:
//
// the new TDB- data access control classes
// these classes are ment to be used in a window when
// you do not have a vbx you have dropped on a dialog and
// you want to connect a data aware control to the data access control
//
   TDBDataSource *DBDataSource;
   TDBTable *DBTable;
//
// data aware controls to be conected to the data access controls above
//
   TDBEdit *DBEdit;
   TDBNavigator *DBNav;

   DECLARE_RESPONSE_TABLE( TDBWindow );
};

DEFINE_RESPONSE_TABLE2( TDBWindow , TWindow , TVbxEventHandler )
END_RESPONSE_TABLE;


TDBWindow::TDBWindow()
: TWindow( 0 , "TDBWindow" )
{
   // set the size of the window
   Attr.X=10;
   Attr.Y=10;
   Attr.W=220;
   Attr.H=150;
//
// since the C++ classes are created in the constructor, the controls
// are listed on the child list of the TWindow class and we do not
// have to call the Create member function of these classes.  If
// they were created outside of the constructor, it would be neccassary
// to call the Create functions.
//
   DBDataSource = new TDBDataSource(this,1100, "Test DBDataSource");
   DBTable= new TDBTable(this,1200,"Test TDBTable");
   DBEdit = new TDBEdit( this , 102, "", 10, 70, 200, 20 );
   DBNav= new TDBNavigator(this,103,"",10,30,200,30);
}

void
TDBWindow::SetupWindow()
{
   TWindow::SetupWindow();
   try {
        DBTable->DatabaseName= string("DivePlan");
        DBTable->TableName = string("names.db");
        DBDataSource->DataSet= DBTable;
        DBEdit->DataSource = DBDataSource;
        DBNav->DataSource= DBDataSource;
        DBTable->Open();
        DBEdit->DataField= DBTable->FieldByName(string("Name"));
        DBTable->TDataSet::Refresh();
   }
   catch (BDTException e)
   {
   	e.Show("Error");
   }
}


class App :public TApplication
{
public:
   App() : TApplication( "TDBWindow App" ) {};
   ~App() {}

   void InitMainWindow() { SetMainWindow( new TFrameWindow( 0 , "TDBWindow" , new TDBWindow(), true )); }

};


int OwlMain(int /*argc*/, char* /*argv*/ [])
{
  TBIVbxLibrary vbxLib;     // constructing this loads & inits the library

  return App().Run();
}
