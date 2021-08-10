//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/framewin.h>
#include <owl/static.h>
#include <owl/draglist.h>
#include <owl/radiobut.h>
#include <stdio.h>

const int DragListId1 = 100;
const int DragListId2 = 101;
const int CopyButtonId= 102;
const int MoveButtonId= 103;
TStatic* Status;
char Buffer[512];

//
// class TExampleDragList
// ~~~~~ ~~~~~~~~~~~~~~~~
class _USERCLASS TExampleDragList : public TDragList {
  public:
    // Constructors
    //
    TExampleDragList(TWindow* parent,int id,int x, int y, int w, int h,
                     TModule* module = 0)
    :
      TDragList(parent, id, x, y, w, h, module)
    {
      Attr.Style &= ~LBS_SORT;
      Copy = true;
    }

    TExampleDragList(TWindow* parent, int resourceId, TModule* module = 0)
    :
      TDragList(parent, resourceId, module)
    {
      Copy = true;
    }

    bool BeginDrag(int item, const TPoint&);
    TCursorType Dragging(int item, const TPoint&);
    void Dropped(int item, const TPoint& point);
    void CancelDrag(int item, const TPoint&);
    void SetCopy(bool newValue)
    {
      Copy= newValue;
    }

  private:
    int StartItem;
    bool Copy;
};

bool
TExampleDragList::BeginDrag(int item, const TPoint&)
{
   StartItem = item;

   if (StartItem == 0)
      return false;
   sprintf(::Buffer, "Start item %d", StartItem);

   if (::Status)
      ::Status->SetText(::Buffer);
   return true;
}

TDragList::TCursorType
TExampleDragList::Dragging(int item, const TPoint& point)
{
   HWND hwnd=WindowFromPoint(point);
   if (hwnd == *(Parent->ChildWithId(DragListId1)) || 
            hwnd == *(Parent->ChildWithId(DragListId2)) ) {
      if (hwnd != *this) {
         if (Copy)
            sprintf(::Buffer, "Copying to top of other ListBox");
         else
            sprintf(::Buffer, "Move to top of other ListBox");
      }
      else if (item == 0) {
         sprintf(::Buffer, "Cannot insert new item here");  
      }
      else {
         if (item == -1)
            sprintf(::Buffer, "Move to end of list");
         else
            sprintf(::Buffer, "Moving to item %d", item);
      }

      if (::Status)
         ::Status->SetText(::Buffer);

      if (Copy && (hwnd != *this) )
         return TDragList::dlCopy;
      else if (item==0)
         return TDragList::dlStop;
      else
         return TDragList::dlMove;
   }
   sprintf(::Buffer, "Cancel");
   if (::Status)
      ::Status->SetText(::Buffer);
   return TDragList::dlMove;
}

void
TExampleDragList::Dropped(int item, const TPoint& point)
{
   if ( (StartItem != 0) && (StartItem != item) && (item != 0) ) {
      int len= GetStringLen(StartItem);
      char *moveItem= new char[len+1];
      if (moveItem) {
         GetString(moveItem, StartItem);
         HWND hwnd = WindowFromPoint(point);
         if (hwnd == *(Parent->ChildWithId(DragListId1)) || 
            hwnd == *(Parent->ChildWithId(DragListId2)) ) {
         if (!Copy || (hwnd == *this) )
            DeleteString(StartItem);
         if (hwnd == *this) {
            if (item != -1)
               sprintf(::Buffer, "Dragged from %d to %d", StartItem, item);
            else
               sprintf(::Buffer, "Dragged to end of list");
            InsertString(moveItem, item);
         }
         else {
            sprintf(::Buffer, "Dragged from %d to the top of the other ListBox", StartItem);
            ::SendMessage(hwnd, LB_INSERTSTRING, 1, (LPARAM)((LPSTR)moveItem));
         }
         }
      }
      if (::Status)
         ::Status->SetText(::Buffer);
   }
}

void
TExampleDragList::CancelDrag(int, const TPoint&)
{
   sprintf(::Buffer, "Cancelled drag");

   if (::Status)
      ::Status->SetText(::Buffer);
}



//
// class TDragListWindow
// ~~~~~ ~~~~~~~~~~~~~~~
class _USERCLASS TDragListWindow : public TWindow, public TDragListEventHandler {
  public:
    TDragListWindow();
    void SetupWindow();
    // EV_COMMAND_AND_ID function- void ButtonClicked(WPARAM id);
    void CopyClicked();
    void MoveClicked();

  private:
    TExampleDragList* DragList1;
    TExampleDragList* DragList2;
    TRadioButton* CopyButton;
    TRadioButton* MoveButton;

  DECLARE_RESPONSE_TABLE(TDragListWindow);
};

DEFINE_RESPONSE_TABLE2(TDragListWindow, TWindow, TDragListEventHandler)
   // EV_COMMAND_AND_ID(CopyButtonId,ButtonClicked),
   // EV_COMMAND_AND_ID(MoveButtonId,ButtonClicked),
   EV_BN_CLICKED(CopyButtonId, CopyClicked),
   EV_BN_CLICKED(MoveButtonId, MoveClicked),
END_RESPONSE_TABLE;

TDragListWindow::TDragListWindow() 
: 
   TWindow(0, 0, 0) 
{
   ::Status = new TStatic(this, -1, "", 10, 0, 410, 35);
   DragList1 = new TExampleDragList(this, DragListId1, 10, 60, 210, 160);
   DragList2 = new TExampleDragList(this, DragListId2, 230, 60, 210, 160);
   CopyButton= new TRadioButton(this, CopyButtonId, "Copy Entry", 115, 235, 100, 20);
   MoveButton= new TRadioButton(this, MoveButtonId, "Move Entry", 255, 235, 100, 20);
}

void 
TDragListWindow::SetupWindow() 
{
   TWindow::SetupWindow();
   CopyButton->SetCheck(BF_CHECKED);
   DragList1->SetCopy(true);
   DragList2->SetCopy(true);

   // Add items to listbox
   //
   DragList1->AddString("Cannot be dragged");
   DragList1->AddString("Amber");
   DragList1->AddString("Annie");
   DragList1->AddString("Anh");
   DragList1->AddString("Della");
   DragList1->AddString("Doreen");
   DragList1->AddString("Elizabeth");
   DragList1->AddString("Eva");
   DragList1->AddString("Della");
   DragList1->AddString("Jean");
   DragList1->AddString("Josephine");
   DragList1->AddString("Maya");
   DragList1->AddString("Soyeun");
   DragList1->AddString("Sally");
   DragList1->AddString("Valerie");

   DragList2->AddString("Cannot be dragged");
   DragList2->AddString("Chris");
   DragList2->AddString("Tommy");
   DragList2->AddString("Bruneau");
   DragList2->AddString("Jason");
   DragList2->AddString("Dave");
   DragList2->AddString("Carl");
}

/* EV_COMMAND_AND_ID function- 
void 
TDragListWindow::ButtonClicked(WPARAM id)
{
   if(id== CopyButtonId) {
      DragList1->SetCopy(true);
      DragList2->SetCopy(true);
   }
   else {
      DragList1->SetCopy(false);
      DragList2->SetCopy(false);
   }
}  */

void 
TDragListWindow::CopyClicked()
{
   DragList1->SetCopy(true);
   DragList2->SetCopy(true);
}

void 
TDragListWindow::MoveClicked()
{
   DragList1->SetCopy(false);
   DragList2->SetCopy(false);
}

//
// class TDragListApp
// ~~~~~ ~~~~~~~~~~~~
class _USERCLASS TDragListApp : public TApplication {
  public:
    void InitMainWindow();
};

void
TDragListApp::InitMainWindow()
{
  TFrameWindow* frame = new TFrameWindow(0, "DragList Example",
    new TDragListWindow);
  SetMainWindow(frame);
}

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TDragListApp().Run();
}
