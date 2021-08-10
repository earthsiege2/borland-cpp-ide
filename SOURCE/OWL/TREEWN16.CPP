//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.5  $
//
// Implementation of class TTreeWindow for Win16
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/treewind.h>
#include <stdio.h>

const int ButtonHeight = 11;
const int ButtonWidth  = 10;

//
// Create the control dynamically.
//
TTreeWindow::TTreeWindow(TWindow* parent, int id, int x, int y, int w, int h,
                         TStyle style, TModule* module)
:
  TListBox(parent, id, x, y, w, h, module),
  Style(style)
{
  Attr.Style |= LBS_NOTIFY | LBS_OWNERDRAWVARIABLE | LBS_NOINTEGRALHEIGHT;
  Attr.Style &= ~LBS_HASSTRINGS;
  Attr.Style &= ~LBS_SORT;
  Init();
}

//
// Create the control from a resource
//
TTreeWindow::TTreeWindow(TWindow* parent, int resourceId, TModule* module)
:
  TListBox(parent, resourceId, module)
{
  Init();
}

//
// Private Init to initialize the control
//
void
TTreeWindow::Init()
{
  Font        = new TFont("MS Sans Serif", 16);
  RootLink    = new TTreeLink(*this);
  IndentUnits = 20;
}

//
//
//
TTreeWindow::~TTreeWindow()
{
  delete Font;
  delete RootLink;
}


DEFINE_RESPONSE_TABLE1(TTreeWindow, TListBox)
  EV_WM_GETFONT,
  EV_WM_SETFONT,
  EV_WM_CHAR,
  EV_NOTIFY_AT_CHILD(LBN_DBLCLK, EvLDblClk),
END_RESPONSE_TABLE;


//
//
//
void
TTreeWindow::EvChar(uint key, uint repeatCount, uint flags)
{
  int index = GetCaretIndex();
  TTreeLink* link = GetLinkAtIndex(index);

  if (link) {
    if (key == '+') {
      if (link->IsParent() && !link->IsOpened())   // expand
        OpenLink(link, index);
    }
    else if (key == '-') {
      if (link->IsParent() && link->IsOpened())   // compress
        CloseLink(link, index);
    }
  }
  TListBox::EvChar(key, repeatCount, flags);
}

//
//
//
void
TTreeWindow::EvLDblClk()
{
  int index = GetSelIndex();
  TTreeLink* link = GetLinkAtIndex(index);

  if (link && link->IsParent())
    if (link->IsOpened())
      CloseLink(link, index);
    else
      OpenLink(link, index);

  DefaultProcessing();
}

//
//
//
void
TTreeWindow::EvSetFont(HFONT hFont, bool redraw)
{
  TListBox::EvSetFont(hFont, redraw);
  delete Font;
  Font = new TFont(hFont);
}

//
//
//
HFONT
TTreeWindow::EvGetFont()
{
  if (Font)
    return *Font;
  else
    return (HFONT)DefaultProcessing();
}

//
//
//
int
TTreeWindow::AddLinks(TTreeLink* link, int indentLevel, int insertAfterIndex)
{
  if (link == 0)
    return insertAfterIndex;

  if (!link->IsRoot())
    insertAfterIndex = InsertString((char far*)link, insertAfterIndex);
  else {
    insertAfterIndex = -1;
    indentLevel = 0;
  }

  if ((link->IsParent() && link->IsOpened()) || link->IsRoot()) {
    TTreeLink* chase = link->LastChild;
    while (chase) {
      AddLinks(chase, indentLevel + 1, insertAfterIndex + 1);
      chase = chase->PrevSibling;
    }
  }

  link->SetIndentLevel(indentLevel);

  return 0;
}

//
//
//
void
TTreeWindow::OpenLink(TTreeLink* link, int index)
{
  if (link == 0)
    return;

  link->ToggleOpened();
  TTreeLink* chase = link->LastChild;
  while (chase) {
    AddLinks(chase, link->GetIndentLevel() + 1, index + 1);
    chase = chase->PrevSibling;
  }
}

//
//
//
void
TTreeWindow::CloseLink(TTreeLink* link, int index)
{
  if (link == 0)
    return;

  link->ToggleOpened();
  index++;

  if (index >= GetCount())
    return;

  int targetDeleteLevel = link->GetIndentLevel() + 1;
  TTreeLink* chase      = GetLinkAtIndex(index);
  int chaseIndentLevel  = chase->GetIndentLevel();

  // When closing a parent, remove all of the children with indent level
  // greater than the parents.
  //
  while (targetDeleteLevel <= chaseIndentLevel) {
    if (chase->IsOpened())
      CloseLink(chase, index);

    int count = DeleteString(index);
    if (index >= count)
      break;

    chase            = GetLinkAtIndex(index);
    chaseIndentLevel = chase->GetIndentLevel();
  }
}

//
//
//
void
TTreeWindow::Update()
{
  int topIndex = GetTopIndex();
  int selIndex = GetSelIndex();
  SendMessage(WM_SETREDRAW, false);
  ClearList();

  AddLinks(RootLink, 0, 0);

  SetTopIndex(topIndex);
  if (selIndex != LB_ERR)
    SetSelIndex(selIndex);
  SendMessage(WM_SETREDRAW, true);
}

//
//
//
TTreeLink*
TTreeWindow::GetLinkAtIndex(int index)
{
  if (index < 0 || index >= GetCount())
    return 0;
  return (TTreeLink*)GetItemData(index);
}

//
//
//
void
TTreeWindow::SetIndent(uint units)
{
  IndentUnits = units;

  if (IndentUnits < ButtonWidth + 2)
    IndentUnits = ButtonWidth + 2;

  if (*this != 0)
    Invalidate();
}

//
//
//
void
TTreeWindow::MeasureItem(MEASUREITEMSTRUCT far& measureItemInfo)
{
  TTreeLink* link = GetLinkAtIndex(measureItemInfo.itemID);
  if (link == 0)
    return;

  const int defCx = -1;
  const int defCy = -1;

  TSize size(defCx, defCy);
  link->GetSize(size, Font);

  if (size.cx != defCx)
    measureItemInfo.itemWidth = size.cx;

  if (size.cx != defCy)
    measureItemInfo.itemHeight = size.cy;

  if (measureItemInfo.itemHeight < ButtonHeight + 2)
    measureItemInfo.itemHeight = ButtonHeight + 2;
}

//
//
//
void
TTreeWindow::ODAFocus(DRAWITEMSTRUCT far& drawInfo)
{
  PaintLink(drawInfo);
}

//
//
//
void
TTreeWindow::ODASelect(DRAWITEMSTRUCT far& drawInfo)
{
  PaintLink(drawInfo);
}

//
//
//
void
TTreeWindow::ODADrawEntire(DRAWITEMSTRUCT far& drawInfo)
{
  PaintLink(drawInfo);
}

//
//
//
void
TTreeWindow::PaintLink(DRAWITEMSTRUCT far& drawInfo)
{
  TTreeLink* link = GetLinkAtIndex(drawInfo.itemID);
  if (link == 0)
    return;

  // Prepare dc
  //
  TDC dc(drawInfo.hDC);
  if (Font)
    dc.SelectObject(*Font);

  // Erase entire line
  //
  TRect rect(drawInfo.rcItem);
  TBrush bkgnd(TColor::SysWindow);
  dc.FillRect(rect, bkgnd);

  // Figure out "non user area"
  //
  TRect drawRect(rect);
  drawRect.right = GetIndent() * link->GetIndentLevel();

  // Draw connecting lines if necessary
  //
  if (HasStyle(twsHasLines)) {
    TPen pen(TColor::Gray, 1, PS_DOT);
    dc.SelectObject(pen);

    int indentLevel = link->GetIndentLevel();
    TTreeLink* chase = link;
    bool firstDraw = true;

    TRect temp = drawRect;
    temp.left = temp.right - GetIndent();

    while (indentLevel > 0) {
      int centerX = temp.left + (temp.right - temp.left) / 2;
      int centerY = temp.top + (temp.bottom - temp.top) / 2;

      if (firstDraw) {
        firstDraw = false;
        if (chase->IsFirstChild() && indentLevel == 1) {
          dc.MoveTo(centerX, temp.bottom);
          dc.LineTo(centerX, centerY);
          dc.LineTo(temp.right, centerY);
        }
        else if (chase->IsLastChild()) {
          dc.MoveTo(centerX, temp.top);
          dc.LineTo(centerX, centerY);
          dc.LineTo(temp.right, centerY);
        }
        else {
          dc.MoveTo(centerX, temp.top);
          dc.LineTo(centerX, temp.bottom);
          dc.MoveTo(centerX, centerY);
          dc.LineTo(temp.right, centerY);
        }
      }
      else {
        if (!chase->IsLastChild()) {
          dc.MoveTo(centerX, temp.top);
          dc.LineTo(centerX, temp.bottom);
          dc.MoveTo(centerX, centerY);
        }
      }

      temp.left -= GetIndent();
      temp.right -= GetIndent();
      indentLevel--;
      chase = chase->ParentLink;
    }

    dc.RestorePen();
  }

  // Draw parent blocks
  //
  if (HasStyle(twsHasButtons)) {
    TRect temp = drawRect;
    temp.left = temp.right - GetIndent();

    int width = GetIndent();
    temp.left += width / 2;
    temp.left -= ButtonWidth / 2;
    temp.right -= width / 2;
    temp.right += ButtonWidth / 2;

    int height = temp.bottom - temp.top;
    temp.top += height / 2;
    temp.top -= ButtonHeight / 2;
    temp.bottom -= height / 2;
    temp.bottom += ButtonHeight / 2;

    if (link->IsParent()) {
      const int offset = 2;
      dc.Rectangle(temp);

      // always draw -
      //
      int y = temp.top + (temp.bottom - temp.top) / 2;
      dc.MoveTo(temp.left + offset, y);
      dc.LineTo(temp.right - offset, y);

      // figure if need to draw |
      //
      if (!link->IsOpened()) {
        int x = temp.left + (temp.right - temp.left) / 2;
        dc.MoveTo(x, temp.top + offset);
        dc.LineTo(x, temp.bottom - offset);
      }
    }
  }

  // Find item's width
  //
  rect.left += GetIndent() * link->GetIndentLevel();
  TSize size;
  link->GetSize(size, Font);
  rect.right = rect.left + size.cx;

  // Draw the item
  //
  dc.DrawText(link->TreeItem->Text, -1, rect, DT_SINGLELINE | DT_VCENTER);

  // Draw focus and selected states
  //
  if (drawInfo.itemState & ODS_FOCUS)
    dc.DrawFocusRect(rect);

  if (drawInfo.itemState & ODS_SELECTED)
    dc.InvertRect(rect);
}

//
//
//
TTreeNode
TTreeWindow::GetSelection()
{
  TTreeLink* link = GetLinkAtIndex(GetSelIndex());
  return TTreeNode(*link);
}

//
//
//
void
TTreeWindow::SetStyle(TStyle style)
{
  Style = style;
}

//
//
//
bool
TTreeWindow::HasStyle(TStyle style)
{
  return (Style & style) ? true : false;
}

//----------------------------------------------------------------------------
// TTreeLink

//
//
//
TTreeLink::TTreeLink(TTreeWindow& window)
:
  Window(window),
  Opened(false),
  TreeItem(0),
  ParentLink(0),
  FirstChild(0),
  LastChild(0),
  PrevSibling(0),
  NextSibling(0),
  IndentLevel(0)
{
}


//
// if FirstChild == LastChild {
//   only has 0 or 1 child
// } else {
//   multiple child
// }
//
TTreeLink::~TTreeLink()
{
  // Get rid of children
  //
  TTreeLink* chase = FirstChild;

  while (chase != LastChild) {
    TTreeLink* nextChild = chase->NextSibling;
    delete chase;
    chase = nextChild;
  }
  delete chase;

  delete TreeItem;

  // Special case root node
  //
  if (ParentLink == 0)
    return;

  // Fix parent's children pointers
  //
  if (PrevSibling == 0)
    ParentLink->FirstChild = NextSibling;

  if (NextSibling == 0)
    ParentLink->LastChild = PrevSibling;

  // Fix sibling pointers
  //
  if (PrevSibling)
    PrevSibling->NextSibling = NextSibling;

  if (NextSibling)
    NextSibling->PrevSibling = PrevSibling;
}

//
//
//
TTreeLink*
TTreeLink::AddAtHead(const TTreeItem& itemToAdd)
{
  TTreeItem* newItem = new TTreeItem(itemToAdd);
  TTreeLink* newLink = new TTreeLink(Window);
  newLink->TreeItem = newItem;
  newLink->ParentLink = ParentLink;

  TTreeLink* head;

  // Find head of list
  //
  if (ParentLink) {
    head = ParentLink->FirstChild;
  }
  else {
    head = this;
    while (head->PrevSibling)
      head = head->PrevSibling;
  }

  newLink->NextSibling = head;
  head->PrevSibling = newLink;

  if (ParentLink)
    ParentLink->FirstChild = newLink;

  return newLink;
}

//
//
//
TTreeLink*
TTreeLink::AddAtTail(const TTreeItem& itemToAdd)
{
  TTreeItem* newItem = new TTreeItem(itemToAdd);
  TTreeLink* newLink = new TTreeLink(Window);
  newLink->TreeItem = newItem;
  newLink->ParentLink = ParentLink;

  TTreeLink* tail;

  // Find tail of list
  //
  if (ParentLink) {
    tail = ParentLink->LastChild;
  }
  else {
    tail = this;
    while (tail->NextSibling)
      tail = tail->NextSibling;
  }

  newLink->PrevSibling = tail;
  tail->NextSibling = newLink;

  if (ParentLink)
    ParentLink->LastChild = newLink;

  return newLink;
}

//
//
//
TTreeLink*
TTreeLink::AddAfter(const TTreeItem& itemToAdd)
{
  TTreeItem* newItem = new TTreeItem(itemToAdd);
  TTreeLink* newLink = new TTreeLink(Window);
  newLink->TreeItem = newItem;
  newLink->ParentLink = ParentLink;

  if (ParentLink && ParentLink->LastChild == this)
    ParentLink->LastChild = newLink;

  newLink->PrevSibling = this;
  newLink->NextSibling = NextSibling;
  if (NextSibling)
    NextSibling->PrevSibling = newLink;
  NextSibling = newLink;

  return newLink;
}

//
//
//
TTreeLink*
TTreeLink::AddFirstChild(const TTreeItem& itemToAdd)
{
  TTreeItem* newItem = new TTreeItem(itemToAdd);
  TTreeLink* newLink = new TTreeLink(Window);
  newLink->TreeItem = newItem;
  newLink->ParentLink = this;

  if (FirstChild)
    FirstChild->PrevSibling = newLink;

  newLink->NextSibling = FirstChild;

  FirstChild = newLink;
  if (LastChild == 0)
    LastChild = newLink;

  return newLink;
}

//
//
//
TTreeLink*
TTreeLink::AddLastChild(const TTreeItem& itemToAdd)
{
  TTreeItem* newItem = new TTreeItem(itemToAdd);
  TTreeLink* newLink = new TTreeLink(Window);
  newLink->TreeItem = newItem;
  newLink->ParentLink = this;

  if (LastChild)
    LastChild->NextSibling = newLink;

  newLink->PrevSibling = LastChild;

  LastChild = newLink;
  if (FirstChild == 0)
    FirstChild = newLink;

  return newLink;
}

//
//
//
bool
TTreeLink::Delete()
{
  // Cannot delete the root
  //
  if (IsRoot())
    return false;

  // deleting only child
  //
  if (!PrevSibling && !NextSibling)  {
    ParentLink->FirstChild = ParentLink->LastChild = 0;
    delete this;
    return true;
  }

  // deleting tail
  //
  if (PrevSibling && !NextSibling) {
    ParentLink->LastChild = PrevSibling;
    PrevSibling->NextSibling = 0;
    delete this;
    return true;
  }

  // deleting head
  //
  if (!PrevSibling && NextSibling) {
    ParentLink->FirstChild = NextSibling;
    NextSibling->PrevSibling = 0;
    delete this;
    return true;
  }

  // deleting middle of list
  //
  NextSibling->PrevSibling = PrevSibling;
  PrevSibling->NextSibling = NextSibling;
  delete this;
  return true;
}

//
//
//
void
TTreeLink::GetSize(TSize& size, TFont* font)
{
  if (font) {
    size = font->GetTextExtent(TreeItem->Text);
  }
}

//
//
//
void
TTreeLink::ToggleOpened()
{
  Opened = Opened ? false : true;
}

//
//
//
bool
TTreeLink::IsLastChild()
{
  if (ParentLink == 0)
    return false;

  if (ParentLink->LastChild == this)
    return true;

  return false;
}

//
//
//
bool
TTreeLink::IsFirstChild()
{
  if (ParentLink == 0)
    return false;

  if (ParentLink->FirstChild == this)
    return true;

  return false;
}


//----------------------------------------------------------------------------
// TTreeNode

//
// Initialize based on the root for TTreeWindow
//
TTreeNode::TTreeNode(TTreeWindow& window)
{
  *this = window.GetRoot();
}

//
//
//
TTreeNode::TTreeNode(TTreeLink& link)
{
  Link = &link;
}

//
// Copy constructor
//
TTreeNode::TTreeNode(const TTreeNode& other)
{
  Link = other.Link;
}

//
// Navigational constructor
//
TTreeNode::TTreeNode(const TTreeNode& other, TNextCode nextCode)
{
  TTreeNode node = other;
  *this = node.GetNextItem(nextCode);
}

//
//
//
TTreeNode
TTreeNode::operator =(const TTreeNode& other)
{
  Link = other.Link;
  return *this;
}


//
//
//
TTreeNode::~TTreeNode()
{
  // don't do anything
}

//
//
//
bool
TTreeNode::ExpandItem(TExpandCode flag)
{
  if (!Link->IsParent())
    return false;

  for (int index = 0; index < Link->Window.GetCount(); index++) {
    TTreeLink* link = Link->Window.GetLinkAtIndex(index);

    if (!link->IsParent())
      continue;

    if (Link == link) {
      if (flag == Toggle) {
        if (link->IsOpened())
          link->Window.CloseLink(link, index);
        else
          link->Window.OpenLink(link, index);
        return true;
      }
      else if (flag == Expand) {
        if (!link->IsOpened())
          link->Window.OpenLink(link, index);
        return true;
      }
      else if (flag == Collapse) {
        if (link->IsOpened())
          link->Window.CloseLink(link, index);
        return true;
      }
    }
  }

  return false;
}

//
//
//
TTreeNode
TTreeNode::GetNextItem(TNextCode flag)
{
  switch (flag) {
    case Root:
      return Link->Window.GetRoot();

    case Next: {
      if (Link->NextSibling)
        return TTreeNode(*Link->NextSibling);
      break;
    }

    case Previous: {
      if (Link->PrevSibling)
        return TTreeNode(*Link->PrevSibling);
      break;
    }

    case Parent: {
      if (Link->ParentLink)
        return TTreeNode(*Link->ParentLink);
      break;
    }

    case Child: {
      if (Link->FirstChild)
        return TTreeNode(*Link->FirstChild);
      break;
    }

  }
  throw TXOwl("Default case occured in TTreeNode::GetNextItem");
}

//
//
//
bool
TTreeNode::GetItem(TTreeItem* item)
{
  *item = *(Link->TreeItem);
  return true;
}

//
//
//
TTreeNode
TTreeNode::AddChild(TTreeItem& item)
{
  return TTreeNode(*Link->AddLastChild(item));
}

//
//
//
TTreeNode
TTreeNode::AddSibling(TTreeItem& item)
{
  return TTreeNode(*Link->AddAtTail(item));
}

//
//
//
TTreeNode
TTreeNode::InsertChild(TTreeItem& item, THowToInsert howToInsert)
{
  TTreeLink* link;

  switch (howToInsert) {
    case First: {
      link = Link->AddAtHead(item);
      break;
    }

    case Last: {
      link = Link->AddAtTail(item);
      break;
    }

    default:
      throw TXOwl("Not yet currently implemented in TTreeNode::InsertChild");
  }
  return TTreeNode(*link);
}

//
//
//
TTreeNode
TTreeNode::InsertItem(TTreeItem& item)
{
  return TTreeNode(*(Link->AddAfter(item)));
}

//
//
//
bool
TTreeNode::Delete()
{
  return Link->Delete();
}


//----------------------------------------------------------------------------
// TTreeItem

//
//
//
TTreeItem::TTreeItem()
{
  Init();
}

//
//
//
TTreeItem::TTreeItem(char far* text, int len)
{
  Init();
  SetText(text, len);
}

//
//
//
void
TTreeItem::Init()
{
  Text     = 0;
  Length   = 0;
  ItemData = 0;
}

//
//
//
TTreeItem::~TTreeItem()
{
  delete[] Text;
}

//
//
//
TTreeItem::TTreeItem(const TTreeItem& other)
{
  Init();

  delete[] Text;
  ItemData = other.ItemData;

  Length = other.Length;
  Text   = new char[Length + 1];
  strcpy(Text, other.Text);
}

//
//
//
void
TTreeItem::SetText(char far* text, int len)
{
  delete[] Text;
  Text   = strnewdup(text);
  Length = len ? len : strlen(text);
}

//
//
//
void
TTreeItem::GetText(char far* text, int len)
{
  if (Length < len)
    strcpy(text, Text);
  else
    strncpy(text, Text, len);
}

//
//
//
TTreeItem
TTreeItem::operator =(const TTreeItem& other)
{
  delete[] Text;
  ItemData = other.ItemData;

  Length = other.Length;
  Text   = new char[Length + 1];
  strcpy(Text, other.Text);

  return *this;
}
