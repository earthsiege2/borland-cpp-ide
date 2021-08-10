//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1999-2002 Borland Corporation.  All Rights Reserved.
//---------------------------------------------------------------------------

//---------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "app.h"              // application expert class def
#include "exconst.h"          // global constants, defines
#include "filters.h"          // file filter class def

#include <memory>             // for auto_ptr<>
#include <stdio.h>
using namespace std;

//---------------------------------------------------------------
#pragma resource "*.dfm"
TAppExpert *AppExpert;

TPages  FirstPage          = pgMenus;
TPages  LastPage           = pgAppInfo;

int     DefaultButtonSpace = 6;
TPoint  DefaultButtonSize(24, 24);
int     MenuItemCount      = 18;
int     MenuItemCounts[]   = { 7, 4, 3, 4 };
int     MenuItemOffsets[]  = { 0, 7, 11, 14 };

char    *SampleBitmaps[]   = { "MENUDSGN",
                               "EXTDSGN",
                               "SPEEDDSGN",
                               "INFODSGN" };

char    *cSourceBuffer;                 // code composition buffer
int     SourceBufferSize   = 1024;      // max code comp bfr size
char    *cCodeSnipets[csLastObject-1];  // code sniptes ptr array
char    *cResourceBuffer;               // code snipet strings
THandle *hCodeResource;

bool     snoop = false;                 // debug facility

//========================================[ AppCreatorEx ]=========
//--- Definitions for AppCreatorEx class  --------------
bool __stdcall AppCreatorEx::Existing(void)
{
  return false;
}
AnsiString __stdcall AppCreatorEx::GetFileName(void)
{
 return ProjectName;
}

AnsiString __stdcall AppCreatorEx::GetFileSystem(void)
{
return String("");
}

AnsiString __stdcall AppCreatorEx::NewProjectSource(const AnsiString ProjectName)
{
return String("");
}

void __stdcall AppCreatorEx::NewDefaultModule(void)
{
 TCreateModuleFlags CMF;
 CMF.Clear();
 CMF << cmAddToProject << cmShowSource << cmShowForm << cmExisting;
  TS->CreateModule(UnitName, NULL, NULL, CMF);
}

void __stdcall AppCreatorEx::NewProjectResource(TIModuleInterface* Module)
{
}



//--- CONSTRUCTOR AND DESTRUCTORS -------------------------------<<

//========================================[ TAppExpert ]=========
__fastcall TAppExpert::TAppExpert(TComponent* Owner)
                      :TForm(Owner)
{
}

//========================================[ TAppExpert ]=========
__fastcall TAppExpert::TAppExpert(TComponent* AOwner, int Dummy)
                      :TForm(AOwner, Dummy)
{
}

//========================================[ TAppExpert ]=========
__fastcall TAppExpert::~TAppExpert(void)
{
}

//--- NOTEBOOK PAGE CONTROL -------------------------------------<<

//========================================== TAppExpert =========
bool __fastcall TAppExpert::ValidateInfo(void)
{
  String e;

  if (AppName->Text == "")
  {
    e = LoadStr(sAppNameRequired);
    Application->MessageBox(e.c_str(), "ERROR", mbOK);
    return false;
  }
  if (!IsValidIdent(AppName->Text))
  {
    e = LoadStr(sInvalidAppName);
    Application->MessageBox(e.c_str(), "ERROR", mbOK);
    return false;
  }
  if (!DirectoryExists(AppPath->Text))
  {
    e = LoadStr(sInvalidPath);
    Application->MessageBox(e.c_str(), "ERROR", mbOK);
    return false;
  }
  return true;
} // end of TAppExpert::ValidateInfo()

//========================================== TAppExpert =========
// Calculate which page is next based on current page/settings:
//     -1 = last page
//     -2 = cannot move in requested direction
int __fastcall TAppExpert::NextPage(TMoveDirection Direction)
{
  int Result = -2;

  int CurPage = PageControl->ActivePage->PageIndex;
  switch(Direction)
  {
    case mdNoMove:
      if (CurPage == LastPage)
        Result = -1;
      else
        Result = 0;
      break;
    case mdPrevious:
      switch(CurPage)
      {
        case pgMenus: // do nothing
          break;
        case pgExtensions:
          Result = pgMenus;
          break;
        case pgSpeedbar:
          if (cbFileMenu->Checked)
            Result = pgExtensions;
          else
            Result = pgMenus;
          break;
        case pgAppInfo:
          if (HasMenus())
            Result = pgSpeedbar;
          else
            Result = pgMenus;
          break;
      }
      break;
    case mdNext:
      switch(CurPage)
      {
        case pgMenus:
            if (cbFileMenu->Checked)
              Result = pgExtensions;
            else
              if (HasMenus())
                Result = pgSpeedbar;
              else
                Result = pgAppInfo;
          break;
        case pgExtensions:
          Result = pgSpeedbar;
          break;
        case pgSpeedbar:
          Result = pgAppInfo;
          break;
        case pgAppInfo:
          Result = -1;
          break;
      }
      break;
  }
  return Result;
} // end of TAppExpert::NextPage()

//========================================== TAppExpert =========
void __fastcall TAppExpert::NextPrevClick(TObject *Sender)
{
  int NewPage;

  TButton* tb = (TButton*)(Sender);
  if (tb == PrevButton)
    NewPage = NextPage(mdPrevious);
  else
    NewPage = NextPage(mdNext);

  switch(NewPage)
  {
    case -1:
      // If we aren't going forward, allow invalid info on page...
      if (tb != NextButton)
        ModalResult = mrOK;
      else
        // ...but don't allow us to advance to next page with
        // invalid info on the current page.
        if (ValidateInfo())
          ModalResult = mrOK;
      break;
    case -2:
      break; // do nothing
    default:

      // If we have a suitable bitmap to add to our sample
      // bitmap...
      if (SampleBitmaps[NewPage] != 0)
      {
        // ...load it, redisplay updated sample,...
        SampleBmp->Handle = LoadBitmap(HInstance,
                                       SampleBitmaps[NewPage]);
        Sample->Invalidate();
      }

      // ...update the active notebook page and...
      PageControl->ActivePage = PageControl->Pages[NewPage];
      break;
  }

  // ...make the Notebook control buttons reflect current state.
  RefreshButtons();
} // end of TAppExpert::NextPrevClick()

//========================================= TAppExpert ==========
void __fastcall TAppExpert::RefreshButtons(void)
{
  switch(NextPage(mdNoMove))
  {
    case -1:
      NextButton->Caption = LoadStr(sFinish);
      break;
    case 0:
      NextButton->Caption = LoadStr(sNext);
      break;
  }

  switch(NextPage(mdPrevious))
  {
    case -2:
      PrevButton->Enabled = False;
      break;
    default:
      PrevButton->Enabled = True;
      break;
  }
} // end of TAppExpert::RefreshButtons()

//--- SPEEDBUTTON CONTROLS --------------------------------------<<

//========================================== TAppExpert =========
bool __fastcall TAppExpert::HasMenus(void)
{
  return (cbFileMenu->Checked || cbEditMenu->Checked ||
          cbWindowMenu->Checked || cbHelpMenu->Checked);
} // end of TAppExpert::HasMenus()

//---------------------------------------------------------------
void __fastcall RemoveItems(TList &List, TMainItems MenuIndex)
{
  int StartID = sMenuItemTextBase + MenuItemOffsets[MenuIndex];
  int EndID = StartID + MenuItemCounts[MenuIndex];

  int i = 0;
  while(i < List.Count)
  {

    EButtonImage* ButtonImage = (EButtonImage*)List.Items[i];
    if (ButtonImage != 0 && ButtonImage->BitmapID < EndID &&
        ButtonImage->BitmapID >= StartID)
      List.Delete(i);
    else
      i++;
  }
} // end of TAppExpert::RemoveItems()

//========================================= TAppExpert ==========
void __fastcall TAppExpert::MenuClicked(TObject *Sender)
{
  // Here if a menu category has been turned on/off.
  for (int MenuIndex = mmFile; MenuIndex < mmHelp; ++MenuIndex)
  {
    bool MenuOn;
    switch(MenuIndex)
    {
      case mmFile:
        MenuOn = cbFileMenu->Checked;
        break;
      case mmEdit:
        MenuOn = cbEditMenu->Checked;
        break;
      case mmWindow:
        MenuOn = cbWindowMenu->Checked;
        break;
      case mmHelp:
        MenuOn = cbHelpMenu->Checked;
        break;
    }

     // If a menu has been turned off...
    if (!MenuOn)
    {
      // ...remove its speedbutton (if it has one in the list).
      RemoveItems(*SpeedList, (TMainItems)MenuIndex);
      FSpeedIndex = 0;
    }
    if (MenuList->ItemIndex == MenuIndex)
      MenuListClick(this);
  }
} // end of TAppExpert::MenuClicked()

//========================================== TAppExpert =========
// return the rectangle of the specified speedbutton or space
TRect __fastcall TAppExpert::SpeedButtonRect(int Index)
{
  TRect Result;

  int x = 10;  // first usable position
  for (int i=0; i < Index; i++)
    if (SpeedList->Items[i] == NULL)
      x += DefaultButtonSpace;
    else
      x += DefaultButtonSize.x-1;

  Result = Bounds(x, 5, DefaultButtonSize.x, DefaultButtonSize.y);

  if (Index < SpeedList->Count && SpeedList->Items[Index] == NULL)
    Result.Right = Result.Left + DefaultButtonSpace;

  return Result;
} // end of TAppExpert::SpeedButtonRect()

//========================================== TAppExpert =========
int __fastcall TAppExpert::GetSpeedButtonCount(void)
{
  return SpeedList->Count;
} // end of TAppExpert::GetSpeedButtonCount()

//========================================== TAppExpert =========
//  Return bitmap ID of button in speedbutton list whose index
//   is passed in 'Value' or -1 if the button image at that
//   index is NULL.
int __fastcall TAppExpert::GetSpeedButtonID(int Value)
{
  int Result;

  EButtonImage* ButtonImage = (EButtonImage*)SpeedList->Items[Value];
  if (ButtonImage != NULL)
    Result = ButtonImage->BitmapID;
  else
    Result = -1;

  return Result;
} // end of TAppExpert::GetSpeedButtonID()

//========================================== TAppExpert =========
void __fastcall TAppExpert::SpeedbarPaint(TObject *Sender)
{
  EButtonImage *ButtonImage;

  TRect R;
  Offscreen->Canvas->Pen->Color   = (TColor)clWindowFrame;
  Offscreen->Canvas->Brush->Style = bsClear;
  Offscreen->Canvas->Brush->Color = Speedbar->Color;

  Offscreen->Canvas->Rectangle(1, 1, Speedbar->Width - 1,
                               Speedbar->Height - 1);
  Offscreen->Canvas->Pen->Color = (TColor)clBtnShadow;
  TPoint p[3];
  p[0].x = 0;
  p[0].y = Speedbar->Height-1;
  p[1].x = 0;
  p[1].y = 0;
  p[2].x = Speedbar->Width-1; p[2].y = 0;
  Offscreen->Canvas->Polyline(p, 3);
  Offscreen->Canvas->Pen->Color = (TColor)clBtnHighlight;
  p[0].x = Speedbar->Width-1;
  p[0].y = 0;
  p[1].x = Speedbar->Width-1;
  p[1].y = Speedbar->Height;
  Offscreen->Canvas->Polyline(p, 2);

  // Draw the buttons in the list
  int x = 10;
  for (int i=0; i < SpeedList->Count; i++)
  {
    ButtonImage = (EButtonImage*)SpeedList->Items[i];
    if (ButtonImage == NULL)
    {
      Offscreen->Canvas->Brush->Style = bsSolid;
      Offscreen->Canvas->Brush->Color = (TColor)clBtnShadow;
      R = Bounds(x + 2, 5, DefaultButtonSpace - 3,
                 DefaultButtonSize.y - 2);
      Offscreen->Canvas->FillRect((TRect&)R);
      x += DefaultButtonSpace;
    }
    else
    {
      Offscreen->Canvas->Brush->Style = bsSolid;
      ButtonImage->Draw(Offscreen->Canvas, x, 4);
      x += DefaultButtonSize.x-1;
    }

    if (x + (DefaultButtonSize.x * 2) > Speedbar->Width)
      break;

    // draw the insertion point }
    R = SpeedButtonRect(FSpeedIndex);
    OffsetRect((RECT*)&R, -5, 0);
    R.Top = R.Bottom + 2;
    R.Bottom = R.Top + SpeedPointer->Height;
    R.Right = R.Left + SpeedPointer->Width;
    Offscreen->Canvas->Brush->Color = Speedbar->Color;
    Offscreen->Canvas->BrushCopy((TRect&)R, SpeedPointer,
                                 (TRect&)Rect(0, 0, SpeedPointer->Width,
                                             SpeedPointer->Height),
                                 clWhite);
  }
  Speedbar->Canvas->Draw(0, 0, Offscreen);
} // end of TAppExpert::SpeedbarPaint()

//========================================= TAppExpert ==========
// The list of menus was clicked
void __fastcall TAppExpert::MenuListClick(TObject *Sender)
{
  if (MenuList->ItemIndex > -1)
  {
    long ID = sMenuItemTextBase + MenuItemOffsets[MenuList->ItemIndex];
    MenuItemList->Items->BeginUpdate();
    try
    {
      MenuItemList->Clear();

      bool MenuOn;
      switch(MenuList->ItemIndex)
      {
        case 0:
          MenuOn = cbFileMenu->Checked;
          break;
        case 1:
          MenuOn = cbEditMenu->Checked;
          break;
        case 2:
          MenuOn = cbWindowMenu->Checked;
          break;
        case 3:
          MenuOn = cbHelpMenu->Checked;
          break;
      }

      if (MenuOn)
      {
        // load the list box with the buttons and text }
        for (int i=0; i < MenuItemCounts[MenuList->ItemIndex]; i++)
        {
          int ButtonIndex = i+MenuItemOffsets[MenuList->ItemIndex];
          MenuItemList->Items->AddObject(LoadStr(ID+i),
                       (TObject*)ButtonList->Items[ButtonIndex]);
        }
      }
    }
    catch(...)
    {
    }

    MenuItemList->Items->EndUpdate();
  }
} // end of TAppExpert::MenuListClick()

//========================================== TAppExpert =========
void __fastcall TAppExpert::DrawMenuItem(TWinControl *Control,
                                         Integer Index,
                                         const TRect &Rect,
                                         TOwnerDrawState State)
{
  TRect R;
  ExtTextOut(MenuItemList->Canvas->Handle, R.Left, R.Top,
             ETO_OPAQUE, (RECT*)&Rect, NULL, 0, NULL);


  EButtonImage*
  ButtonImage = (EButtonImage*)MenuItemList->Items->Objects[Index];
  ButtonImage->Draw(MenuItemList->Canvas, Rect.Left+2, Rect.Top+1);

  R = Rect;
  R.Left += DefaultButtonSize.x + 2 + 4;

  char C[255];
  DrawText(MenuItemList->Canvas->Handle,
           StrPCopy(C, MenuItemList->Items->Strings[Index]), -1,
           (RECT*)&R, DT_VCENTER || DT_SINGLELINE);
} // end of TAppExpert::DrawMenuItem()

//========================================== TAppExpert =========
// Insert the current button into the Speedbar
void __fastcall TAppExpert::InsertClick(TObject *Sender)
{
  // If any item in the menu items list is selected...
  if (MenuItemList->ItemIndex > -1)
  {
    // ...get the associated button image object.
    EButtonImage* ButtonImage =
    (EButtonImage*)MenuItemList->Items->Objects[MenuItemList->ItemIndex];

    // Don't permit user to insert the same button multiple times.
    EButtonImage *bi;
    for (int i=0; i<SpeedList->Count; i++) {
      bi = (EButtonImage*)SpeedList->Items[i];
      if (bi != NULL && bi->BitmapID == ButtonImage->BitmapID)
        return;
    }

    // If insertion cursor is between buttons, insert new
    // button between existing buttons...
    if (FSpeedIndex < SpeedList->Count)
      SpeedList->Insert(FSpeedIndex, ButtonImage);
    else

      // ...otherwise just add the right of the last button.
      SpeedList->Add(ButtonImage);

    FSpeedIndex++;
    Speedbar->Invalidate();
  }
} // end of TAppExpert::InsertClick()

//========================================== TAppExpert =========
// Insert a space to the right of the insertion cursor on the
//   speedbar.
void __fastcall TAppExpert::SpaceClick(TObject *Sender)
{
  if (FSpeedIndex < SpeedList->Count)
    SpeedList->Insert(FSpeedIndex, NULL);
  else
    SpeedList->Add(NULL);

  FSpeedIndex++;
  Speedbar->Invalidate();
} // end of TAppExpert::SpaceClick()

//========================================== TAppExpert =========
//  Remove the speedbutton to the right of the insertion cursor.
void __fastcall TAppExpert::RemoveClick(TObject *Sender)
{
  // If insertion cursor is on a deleteable button delete it...
  if (FSpeedIndex < SpeedList->Count) {
    SpeedList->Delete(FSpeedIndex);

    // ...but if it is beyond any possible deleteable button
    // just set cursor to beyond last button in speedbar.
    if (FSpeedIndex > SpeedList->Count)
      FSpeedIndex = SpeedList->Count;

    Speedbar->Invalidate();
  }
} // end of TAppExpert::RemoveClick()

//========================================== TAppExpert =========
// Return an index into SpeedList from the TPoint. If there is
//  no speedbutton at TPoint position, return -1.
int __fastcall TAppExpert::SpeedButtonAtPos(const tagPOINT &Pos)
{
  for (int i=0; i < SpeedList->Count; i++)
  {
    TRect R = SpeedButtonRect(i);
    if (PtInRect((RECT*)&R, Pos))
    {
      return i;
    }
  }

  return -1;
} // end of TAppExpert::SpeedButtonAtPos()

//========================================== TAppExpert =========
// The mouse was clicked in the Speedbar area. If the cursor is
//  over a speebutton, hilight it otherwise hilight the last
//  speedbutton in the list.
void __fastcall TAppExpert::SpeedMouseDown(TObject *Sender,
                                TMouseButton Button,
                                TShiftState Shift,
                                Integer X, Integer Y)
{
  // Get the index of the speedbutton under the cursor and...
  int Index = SpeedButtonAtPos(Point(X, Y));

  // ...if there is one there make it current else set current
  // index to last speedbutton in list and...
  if (Index != -1)
    FSpeedIndex = Index;
  else
    FSpeedIndex = SpeedList->Count;

  // ...update for hilite.
  Speedbar->Invalidate();
} // end of TAppExpert::SpeeMouseDown()

//========================================== TAppExpert =========
void __fastcall TAppExpert::BrowseClick(TObject *Sender)
{
  TSelectDirOpts tso;
  tso << sdAllowCreate << sdPrompt << sdPerformCreate;

  String d = AppPath->Text;
  if (SelectDirectory(d, tso, NULL))
    AppPath->Text = d;
} // end of TAppExpert::BrowseClick()

//========================================== TAppExpert =========
void __fastcall TAppExpert::SamplePaint(TObject *Sender)
{
  if (SampleBmp != NULL)
    Sample->Canvas->Draw(0, 0, SampleBmp);
} // end of TAppExpert::SamplePaint()

//========================================== TAppExpert =========
void __fastcall TAppExpert::FormCreate(TObject *Sender)
{
  SpeedList            = new TList;
  ButtonList           = new TList;
  Offscreen            = new Graphics::TBitmap;
  Offscreen->Width     = Speedbar->Width;
  Offscreen->Height    = Speedbar->Height;
  SpeedPointer         = new Graphics::TBitmap;
  SpeedPointer->Handle = LoadBitmap(HInstance, "SPEEDPOINTER");
  SampleBmp            = new Graphics::TBitmap;

  // Fill the MenuItemList with the speedbuttons.
  EButtonImage *ButtonImage;
  for (long ID=sMenuItemTextBase;
       ID < sMenuItemTextBase + MenuItemCount; ID++)
  {
    ButtonImage            = new EButtonImage;
    ButtonImage->NumGlyphs = 2;
    ButtonImage->BitmapID  = ID;
    ButtonList->Add(ButtonImage);
  }

  // This is required to prevent the Speedbar from erasing its
  // background each time it paints.  This dramatically reduces
  // (eliminates) any flicker when painting (try commenting
  // out this line to see the difference).
  Speedbar->ControlStyle << csOpaque;

  PageControl->ActivePage = PageControl->Pages[FirstPage];
  SampleBmp->Handle = LoadBitmap(HInstance, SampleBitmaps[FirstPage]);

  RefreshButtons();
} // end of TAppExpert::FormCreate()

//========================================== TAppExpert =========
void __fastcall TAppExpert::FormDestroy(TObject *Sender)
{
  ButtonList->Clear();
  delete ButtonList;
  delete SpeedList;
  delete SpeedPointer;
  delete Offscreen;
  delete SampleBmp;
} // end of TAppExpert::FormDestroy()


//=========================================[ EButtonImage ]======
// EButtonImage
__fastcall EButtonImage::EButtonImage(void)
{
  bmFBitmap = new Graphics::TBitmap;
  FNumGlyphs = 1;
}

//=========================================[ EButtonImage ]======
__fastcall EButtonImage::~EButtonImage(void)
{
  delete bmFBitmap;
}

//========================================= EButtonImage ========
void __fastcall EButtonImage::SetBitmapID(long Value)
{
  if (FBitmapID != Value)
  {
    FBitmapID = Value;
    bmFBitmap->Handle = LoadBitmap(HInstance, (char*)FBitmapID);
  }
} // end of EButtonImage::SetBitmapID()

//========================================= EButtonImage ========
void __fastcall EButtonImage::Draw(TCanvas *Canvas, int x, int y)
{
  TColor SavePen   = Canvas->Pen->Color;
  TColor SaveBrush = Canvas->Brush->Color;

  TRect Target = DrawButtonFace(Canvas, Bounds(x, y,
                                DefaultButtonSize.x,
                                DefaultButtonSize.y), 1, bsWin31,
                                False, False, False);

  // draw bitmap
  int bx = bmFBitmap->Width / FNumGlyphs;
  if (bx > 0)
  {
    Target = Bounds(x, y, bx, bmFBitmap->Height);
    OffsetRect((RECT*)&Target, (DefaultButtonSize.x /2)-(bx/2),
               (DefaultButtonSize.y / 2) - (bmFBitmap->Height/2));
    TRect Source = Bounds(0, 0, bx, bmFBitmap->Height);
    Canvas->BrushCopy(Target, bmFBitmap, Source,
                      bmFBitmap->Canvas->Pixels[0][bmFBitmap->Height-1]);
  }

  Canvas->Pen->Color   = SavePen;
  Canvas->Brush->Color = SaveBrush;
} // end of EButtonImage::Draw()

//--- FILE FILTER LIST CONTROLS ---------------------------------<<

//=========================================== TAppExpert ========
// Draw the file extension list box.
void __fastcall TAppExpert::DrawExtension(TWinControl *Control,
                                          Integer Index,
                                          const TRect &Rect,
                                          TOwnerDrawState State)
{
  // Find the separator in the string and...
  int P = ExtListBox->Items->Strings[Index].Pos("|");

  // ...adjust the rectangle so we draw only the left "column".
  TRect R = Rect;
  R.Right = R.Left + ExtHeader->SectionWidth[0];

  // Draw the filter description and...
  char C[255];
  String S = ExtListBox->Items->Strings[Index].SubString(1, P - 1);
  ExtTextOut(ExtListBox->Canvas->Handle, R.Left, R.Top,
             ETO_CLIPPED | ETO_OPAQUE, (RECT*)&R, StrPCopy(C, S),
             S.Length(), NULL);

  // ...move the rectangle to the next column and draw the
  // file extensions.
  R.Left = R.Right;
  R.Right = Rect.Right;
  S = ExtListBox->Items->Strings[Index].SubString(P + 1, 255);
  ExtTextOut(ExtListBox->Canvas->Handle, R.Left, R.Top,
             ETO_CLIPPED | ETO_OPAQUE, (RECT*)&R, StrPCopy(C, S),
             S.Length(), NULL);
} // end of TAppExpert::DrawEstension()

//========================================== TAppExpert =========
void __fastcall TAppExpert::HeaderSized(TObject *Sender,
                                        Integer ASection,
                                        Integer AWidth)
{
  ExtListBox->Invalidate();
} // end of TAppExpert::HeaderSized()

//=========================================== TAppExpert ========
void __fastcall TAppExpert::AddClick(TObject *Sender)
{
//  String Filter;

  String Filter(""); // = "";
  if (EditFilterInfo(Filter))
    ExtListBox->Items->Add(Filter);
} // end of TAppExpert::AddClick()

//========================================== TAppExpert =========
void __fastcall TAppExpert::EditClick(TObject *Sender)
{
  String Filter;

  if (ExtListBox->ItemIndex > -1)
  {
    Filter = ExtListBox->Items->Strings[ExtListBox->ItemIndex];
    if (EditFilterInfo(Filter))
      ExtListBox->Items->Strings[ExtListBox->ItemIndex] = Filter;
  }
} // end of TAppExpert::EditClick()

//========================================== TappExpert =========
void __fastcall TAppExpert::DeleteClick(TObject *Sender)
{
  if (ExtListBox->ItemIndex > -1)
    ExtListBox->Items->Delete(ExtListBox->ItemIndex);
} // end of TAppExpert::DeleteClick()

//========================================= TAppExpert ==========
void __fastcall TAppExpert::MoveClick(TObject *Sender)
{
  int Delta;
  int NewPos;

  if (ExtListBox->ItemIndex != -1)
  {
    if (Sender == UpButton)
      Delta = -1;
    else
      if (Sender == DownButton)
        Delta = 1;
      else
        Delta = 0;

    if (Delta != 0)
    {
      NewPos = ExtListBox->ItemIndex + Delta;
      if (NewPos >= 0 && NewPos < ExtListBox->Items->Count)
      {
        ExtListBox->Items->Move(ExtListBox->ItemIndex, NewPos);
        ExtListBox->ItemIndex = NewPos;
      }
    }
  }
} // end of TAppExpert::MoveClick()

//---------------------------------------------------------------
//  Display file filter dialog box and get new file description
//    and file filter type(s) as bar ('|") formatted AnsiString
//    in 'Filter'. If dialog box was cancelled, return false else
//    return true.
bool __fastcall EditFilterInfo(String &Filter)
{
  bool result;

  try
  {
    auto_ptr<TFilterDlg> d(new TFilterDlg(Application));
    d.get()->Filter = Filter;
    result = d.get()->ShowModal() == mrOK;
    if (result)
      Filter = d.get()->Filter;

  } catch(...)
  {
  }

  return result;
} // end of EditFilterInfo()

//--- SOURCE GENERATION FUNCTIONS -------------------------------<<

//---------------------------------------------------------------
void _fastcall FmtWrite(TStream *Stream, char *Fmt,
                        const TVarRec *Args, const int Args_Size)
{
  StrLFmt(cSourceBuffer, SourceBufferSize, Fmt, Args, Args_Size);

  if (snoop)
    MessageBox(NULL, cSourceBuffer, "Snooper duper", MB_OK);

  Stream->Write((void*)cSourceBuffer, strlen(cSourceBuffer));
} // end of FmtWrite()

//---------------------------------------------------------------
void __fastcall WriteSnipet(TStream *Stream, TCodeSnipet Snipet)
{
  Stream->Write((void*)cCodeSnipets[Snipet],
                strlen(cCodeSnipets[Snipet]));
} // end of WriteSnipet()

//---------------------------------------------------------------
void __fastcall WriteIdent(TStream *Stream, long ResID,
                           const String VarType)
{
  sprintf(cSourceBuffer, "%s%s *%s;\n", INDENT, VarType.c_str(),
                                        LoadStr(ResID).c_str());
  Stream->Write((void*)cSourceBuffer, strlen(cSourceBuffer));
} // WriteIdent()

//---------------------------------------------------------------
void __fastcall WriteMenuItems(TStream *Stream,
                               TMainItems MenuIndex)
{
  for (int i=0; i<MenuItemCounts[MenuIndex]-1; i++)
  {
    WriteIdent(Stream,
               sMenuItemNameBase+MenuItemOffsets[MenuIndex]+i,
               "TMenuItem");
  }
} // end of WriteMenuItems()

//---------------------------------------------------------------
void __fastcall WriteMethodDecl(TStream *Stream, long ResID)
{
  sprintf(cSourceBuffer, "%svoid __fastcall %s(TObject *Sender);",
          INDENT, LoadStr(ResID).c_str());
  Stream->Write(cSourceBuffer, strlen(cSourceBuffer));
  Stream->Write(CRLF, 2);
} // end of WriteMethodDecl()

//---------------------------------------------------------------
void __fastcall WriteMethodHeader(TStream *Stream, long ResID)
{
  sprintf(cSourceBuffer,
          "%s%svoid __fastcall T%s::%s(TObject *Sender)",
          SEPARATOR, CRLF, LoadStr(sMainForm).c_str(),
          LoadStr(ResID).c_str());
  Stream->Write((void*)cSourceBuffer, strlen(cSourceBuffer));
} // end of WriteMethodHeader()

//---------------------------------------------------------------
void __fastcall WriteMenuMethodDecls(TStream *Stream,
                                     TMainItems MenuIndex)
{
  for (int i=0; i<MenuItemCounts[MenuIndex]; i++)
    WriteMethodDecl(Stream,
                    sMenuProcNames+MenuItemOffsets[MenuIndex]+i);
} // end of WriteMethodDecls()

//---------------------------------------------------------------
void __fastcall WriteMenuMethods(TStream *Stream,
                                 TMainItems MenuIndex,
                                 TCodeSnipet BaseSnipet)
{
  TCodeSnipet snipet;

  int id = sMenuProcNames + MenuItemOffsets[MenuIndex];
  for (int i=0; i<MenuItemCounts[MenuIndex]; i++)
  {
    WriteMethodHeader(Stream, id+i);
    snipet = TCodeSnipet(i+BaseSnipet);
    WriteSnipet(Stream, snipet);
  }
} // end of WriteMenuMethods()

//---------------------------------------------------------------
TFileName* __fastcall GenerateProjectSource(TAppExpert *AppExpert)
{
  // Get the application expert's fully qualified specification
  // (path\APPNAME.CPP).
  TFileName *result = new TFileName;
  *result = AppExpert->AppPath->Text;

  // If it is not slash terminated, slash terminate it and...
  int rl = result->Length();
  if (rl > 0)
    if ((*result)[rl-1] != ':')
      if ((*result)[rl-1] != '\\')
        *result += "\\";

  // ...add application file name and a CPP extension.
  *result += AppExpert->AppName->Text + ".CPP";
  // Open the project file stream and...
  try
  {
    auto_ptr<TFileStream> projectFile(new TFileStream(*result,
                                                      fmCreate));

    // ...write the usual WinMain() and app startup code.
    sprintf(cSourceBuffer, cCodeSnipets[csMainImpl],
            AppExpert->AppName->Text.c_str());
        projectFile.get()->Write(cSourceBuffer, strlen(cSourceBuffer));

  } catch(...)
  {
  }

  // Return the file spec to caller.
  return result;
} // end of GenerateProjectSource()

//---------------------------------------------------------------
void __fastcall GenerateHdrSourceFile(TAppExpert *AppExpert)
{
  String      buttonName;
  String      buttonText;

  // Create fully qualified name spec for the header module
  // (i.e., path\main.h).
  TFileName filename(AppExpert->AppPath->Text);
  if (filename.Length() > 0 && (filename[filename.Length()] != ':' &&
                                 filename[filename.Length()] != '\\'))
    filename += '\\';

  // "main.h" in Strings.rc
  filename += LoadStr(sHdrSourceFile);

  try
  {
    auto_ptr<TFileStream> stream(new TFileStream(filename, fmCreate));
    WriteSnipet(stream.get(), csHdr1);
    *cSourceBuffer = 0;

    // Create the menu declarations.
    if (AppExpert->HasMenus())
    {
      WriteIdent(stream.get(), sMainMenu, "TMainMenu");
      if (AppExpert->cbFileMenu->Checked)
        WriteMenuItems(stream.get(), mmFile);
      if (AppExpert->cbEditMenu->Checked)
        WriteMenuItems(stream.get(), mmEdit);
      if (AppExpert->cbWindowMenu->Checked)
        WriteMenuItems(stream.get(), mmWindow);
      if (AppExpert->cbHelpMenu->Checked)
        WriteMenuItems(stream.get(), mmHelp);
    }

    // Create any variable declarations
    if (AppExpert->cbStatusLine->Checked)
      WriteIdent(stream.get(), sStatusLine, "TStatusBar");

    if (AppExpert->cbFileMenu->Checked)
    {
      WriteIdent(stream.get(), sOpenDialog, "TOpenDialog");
      WriteIdent(stream.get(), sSaveDialog, "TSaveDialog");
      WriteIdent(stream.get(), sPrintDialog, "TPrintDialog");
      WriteIdent(stream.get(), sPrintSetupDialog, "TPrinterSetupDialog");
    }

    // If there are any speedbuttons specified...
    if (AppExpert->SpeedButtonCount > 0)
    {
      // Write the TPanel data member ("TPanel *SpeedBar") to the
      // stream and...
      WriteIdent(stream.get(), sSpeedBar, "TPanel");

      // ...compose the format string for a SpeedButton data
      // member ("TSpeedButton *SpeedButton%d  // %s").
      buttonName = (String)INDENT + "TSpeedButton *" +
                           LoadStr(sSpeedButton) +
                           ";  // %s" + CRLF;

      // For every speed button specified in the ButtonList,...
      int buttonID = 1;
      for (int i=0; i < AppExpert->SpeedButtonCount; i++)
      {
        // ...excluding speedbutton entries that are not used,...
        if (AppExpert->SpeedButtonID[i] > -1)
        {
          // ...get the id for the button and compose the
          // speed button data member's string and write it out
          // to the stream.
          buttonText = LoadStr(AppExpert->SpeedButtonID[i]);
          sprintf(cSourceBuffer, buttonName.c_str(), buttonID,
                  buttonText.c_str());
          stream.get()->Write(cSourceBuffer, strlen(cSourceBuffer));
          buttonID++;
        }
      }
    }

    // Generate method declarations.
    if (AppExpert->cbStatusLine->Checked &&
        AppExpert->cbHints->Checked)
    {
      WriteMethodDecl(stream.get(), sFormCreateProc);
      WriteMethodDecl(stream.get(), sShowHelpProc);
    }

    if (AppExpert->cbFileMenu->Checked)
      WriteMenuMethodDecls(stream.get(), mmFile);
    if (AppExpert->cbEditMenu->Checked)
      WriteMenuMethodDecls(stream.get(), mmEdit);
    if (AppExpert->cbWindowMenu->Checked)
      WriteMenuMethodDecls(stream.get(), mmWindow);
    if (AppExpert->cbHelpMenu->Checked)
      WriteMenuMethodDecls(stream.get(), mmHelp);

    WriteSnipet(stream.get(), csHdr2);

  } catch(...)
  {
  }
} // end of GenerateHdrSourceFile()

//---------------------------------------------------------------
TFileName * __fastcall GenerateMainSourceFile(TAppExpert *AppExpert) {
  String ButtonName;
  String ButtonText;

  // Create fully qualified name spec for the main() module
  // (i.e., path\main.cpp).
  TFileName filename(AppExpert->AppPath->Text);
  TFileName *result = new TFileName;

  if (filename.Length() > 0 && (filename[filename.Length()] != ':' &&
                                filename[filename.Length()] != '\\'))
    filename += '\\';

  filename += LoadStr(sMainSourceFile);
  *result = filename;
  // Create/open file,
  try
  {
    auto_ptr<TFileStream> stream(new TFileStream(filename, fmCreate));
    WriteSnipet(stream.get(), csProgram);
    *cSourceBuffer = 0;

    // Write code implementations.
    if (AppExpert->cbStatusLine->Checked &&
        AppExpert->cbHints->Checked)
    {
      WriteMethodHeader(stream.get(), sFormCreateProc);
      WriteSnipet(stream.get(), csFormCreateProc);
      WriteMethodHeader(stream.get(), sShowHelpProc);
      WriteSnipet(stream.get(), csShowHelpProc);
    }

    // Create menu variables...
    if (AppExpert->cbFileMenu->Checked)
      WriteMenuMethods(stream.get(), mmFile, csFileNewProc);

    if (AppExpert->cbEditMenu->Checked)
      WriteMenuMethods(stream.get(), mmEdit, csEditUndoProc);

    if (AppExpert->cbWindowMenu->Checked)
      WriteMenuMethods(stream.get(), mmWindow, csWindowTileProc);

    if (AppExpert->cbHelpMenu->Checked)
      WriteMenuMethods(stream.get(), mmHelp, csHelpContentsProc);

    String s = (String)SEPARATOR + CRLF;
    FmtWrite(stream.get(), s.c_str(), OPENARRAY(TVarRec, (NULL)));
  } catch(...)
  {
  }
  return result;
} // end of GenerateMainSourceFile()

//---------------------------------------------------------------
void __fastcall BinToHex(char *Binary, char *Text, int Count)
{
  char *HexChars = "0123456789ABCDEF";
  int              i;

  // For number of bytes specified in 'Count'..."
  for (i=0; i < Count; i++)
  {
    // ...strip lo nibble, move hi to lo, convert to ASCII hex
    // and stuff in buffer.
    *Text = HexChars[(Binary[i] & 0xF0) >> 4];
    Text++;

    // Strip hi nibble of next byte, convert to ASCII hex and
    // stuff in buffer.
    *Text = HexChars[Binary[i] & 0x0F];
    Text++;
  }
} // end of BinToHex()

//---------------------------------------------------------------
void __fastcall WriteBinaryAsText(TStream *Input, TStream *Output)
{
  const int BytesPerLine = 32;
  bool      MultiLine;
  int       i;
  long      Count;
  char      Buffer[BytesPerLine];
  char      Text[BytesPerLine * 2 - 1];

  // Get the size of the input buffer and...
  Count = Input->Size;

  // ...if its longer than our max line length (32 bytes)
  // flag it a multiline buffer.
  MultiLine = Count > BytesPerLine;

  // Convert buffer size to hex and write to stream.
  ::BinToHex((char *)&Count, Text, 4);
  Output->Write(Text, 4 * 2);

  while(Count > 0)
  {
    if (MultiLine)
      Output->Write((void*)CRLF, 2);

    // If we have at least 32 bytes left to write write 32 bytes...
    if (Count >= BytesPerLine)
      i = BytesPerLine;
    else

      // ...else write the last of the bytes.
      i = Count;

    // Get the bytes, convert 'um to ASCII hex and write 'um out.
    Input->Read(Buffer, i);
    ::BinToHex(Buffer, Text, i);
    Output->Write(Text, i * 2);

    // Adjust bytes to write for next run.
    Count -= i;
  }
} // end of WriteBinaryAsText()

//---------------------------------------------------------------
void __fastcall WriteGlyphData(TStream *Stream, long BitmapID)
{
  try
  {
    // Create a bitmap and load with the specified glyph.
    auto_ptr<Graphics::TBitmap> bitmap(new Graphics::TBitmap);
    bitmap.get()->Handle = LoadBitmap(HInstance, (char*)BitmapID);

    // Stream the bitmap to a memory stream, and the write that
    // stream as text.
    try
    {
      auto_ptr<TMemoryStream> memory(new TMemoryStream);
      bitmap.get()->SaveToStream(memory.get());
      memory.get()->Position = 0;
      WriteBinaryAsText(memory.get(), Stream);   // 1 invokation
    } catch(...)
    {
    }
  } catch(...)
  {
  }

  FmtWrite(Stream, "}\nend\n", OPENARRAY(TVarRec, (NULL)));
} // end of WriteGlyphData()

//---------------------------------------------------------------
void __fastcall GenerateMainFormFile(TAppExpert *AppExpert)
{
  int    buttonWidth = 25;
  int    spaceWidth = 4;
  String filter;
  int    buttonNumber;
  int    buttonID;
  String buttonMethod;
  String buttonHint;
  int    buttonX;
  int    i;

  // Compose a slash terminated path spec for the text represent-
  // ation of the application's form (MAIN.TXT) and the target
  // form itself (MAIN.DFM).
  TFileName textName(AppExpert->AppPath->Text);
  if (textName.Length() > 0 && (textName[textName.Length()] != ':' ||
                                textName[textName.Length()] != '\\'))
    textName += '\\';

  // Compose the full file spec for the form and its text
  // representation then...
  TFileName formName(textName + LoadStr(sMainFormFile));
  textName += LoadStr(sMainFormText);

  try
  {
    // ...open/create them.
    auto_ptr<TFileStream> textStream(new TFileStream(textName,
                                                     fmCreate));
    auto_ptr<TFileStream> formStream(new TFileStream(formName,
                                                     fmCreate));

    // Write the prologue of the form resource:
    //  object MainForm: TMainForm
    //     Left = 214
    //     Top = 112
    //     Width = 409
    //     Height = 249
    //     Caption = 'MainForm'
    //     Font.Color = clWindowText
    //     Font.Height = -11
    //     Font.Name = 'MS Sans Serif'
    //     PixelsPerInch = 96
    //     TextHeight = 13
    WriteSnipet(textStream.get(), csForm);

    // If this is to be an MDI app, init style member:
    //     FormStyle = fsMDIForm
    if (AppExpert->cbMDIApp->Checked) {
      WriteSnipet(textStream.get(), csFormMDI);
    }

    // If it has menus, init the menu member:
    //     Menu = MainMenu
    if (AppExpert->HasMenus())
      WriteSnipet(textStream.get(), csFormMenu);

    // If hints are enabled...
    if (AppExpert->cbHints->Checked)
    {

      // ...enable hints like this:...
      //   ShowHint = True
      WriteSnipet(textStream.get(), csHints);

      // ...and if both hints and status line are selected:
      //   OnCreate = FormCreate
      if (AppExpert->cbStatusLine->Checked)
        WriteSnipet(textStream.get(), csCreateMethod);
    }

    // If we have any menus selected, write...
    if (AppExpert->HasMenus())
    {
      // ...the menu object prologue...
      //   object MainMenu: TMainMenu
      //     Left = 220
      //     Top = 40
      WriteSnipet(textStream.get(), csMenuObject);

      // ...followed by the resource statements for any selected
      // menu(s)...
      if (AppExpert->cbFileMenu->Checked)
        WriteSnipet(textStream.get(), csFileMenuObject);
      if (AppExpert->cbEditMenu->Checked)
        WriteSnipet(textStream.get(), csEditMenuObject);
      if (AppExpert->cbWindowMenu->Checked)
        WriteSnipet(textStream.get(), csWindowMenuObject);
      if (AppExpert->cbHelpMenu->Checked) {
        WriteSnipet(textStream.get(), csHelpMenuObject);
      }

      // ...and terminate section.
      FmtWrite(textStream.get(), "  end\n",
               OPENARRAY(TVarRec, (NULL)));

      // If the file menu was selected we need to deal with the
      // file filters.
      if (AppExpert->cbFileMenu->Checked)
      {
        // Concatenate all listed filters with bar ('|') separator.
        filter = "";
        for (i=0; i < AppExpert->ExtListBox->Items->Count; i++)
          filter += AppExpert->ExtListBox->Items->Strings[i] + "|";

        // Eliminate the last bar from the conactenated string of
        // filters and...
        if ((filter.Length() > 0) && filter.SubString(1, filter.Length()) == "|")
          filter.Delete(1, filter.Length());

        // ...format and write the filters string to the Open and
        // Save Dialog box resource templates.
        FmtWrite(textStream.get(), cCodeSnipets[csOpenDialogObject],
                 OPENARRAY(TVarRec, (filter)));
        FmtWrite(textStream.get(), cCodeSnipets[csSaveDialogObject],
                 OPENARRAY(TVarRec, (filter)));
        WriteSnipet(textStream.get(), csPrintDialogObject);
        WriteSnipet(textStream.get(), csPrintSetupDialogObject);
      }
    }

    // If selected, write the status line object.
    if (AppExpert->cbStatusLine->Checked)
      WriteSnipet(textStream.get(), csStatusLineObject);

    // Create speedbuttons.
    if (AppExpert->SpeedButtonCount > 0)
    {
      // object SpeedBar: TPanel
      //    Align = alTop
      //    Height = 33
      WriteSnipet(textStream.get(), csSpeedbarObject);

      buttonNumber = 0;
      buttonX      = 8;  // x coordinate of speedbutton
      for (i=0; i < AppExpert->SpeedButtonCount; i++)
      {
        if (AppExpert->SpeedButtonID[i] > -1)
        {
          buttonNumber++;
          buttonID = AppExpert->SpeedButtonID[i]-sMenuItemTextBase;
          buttonMethod = LoadStr(buttonID + sMenuProcNames);
          buttonHint = LoadStr(buttonID + sHintBase);

          // csSpeedButtonObject:
          //    object SpeedButton%d: TSpeedButton
          //      Left = %d
          //      Top = 4
          //      Width = 25
          //      Height = 25
          //      OnClick = %s
          //      Hint = '%s'
          //      NumGlyphs = 2
          //      Glyph.Data = {
          sprintf(cSourceBuffer, cCodeSnipets[csSpeedButtonObject],
                  buttonNumber, buttonX, buttonMethod.c_str(),
                  buttonHint.c_str());
          textStream.get()->Write((void*)cSourceBuffer,
                                  strlen(cSourceBuffer));
          WriteGlyphData(textStream.get(), buttonID + 100);
          buttonX += buttonWidth-1;
        }
        else
        {
          buttonX += spaceWidth;
        }
      }
      FmtWrite(textStream.get(), "  end\n",
               OPENARRAY(TVarRec, (NULL)));
    }

    FmtWrite(textStream.get(), "end\n", OPENARRAY(TVarRec, (NULL)));

    // reset the text stream for conversion
    textStream.get()->Position = 0;

    try
    {
      ObjectTextToResource(textStream.get(), formStream.get());
    } catch(...)
    {
    }

  } catch(...)
  {
  }
} // end of GenerateMainFormFile()

//--- INITIALIZATION AND DEINITIALIZATION FUNCTIONS -------------<<

//---------------------------------------------------------------
void __fastcall InitCodeGeneration(void)
{
  // Allocate the composition buffer,...
  cSourceBuffer = new char[SourceBufferSize];

  // ...find out how much data is in the code snippets resource...
  int ResourceSize = SizeofResource(HInstance,
                                    FindResource(HInstance,
                                                 "SNIPETS",
                                                 RT_RCDATA));

  // ...and get them into global memory.
  hCodeResource =(unsigned int*) LoadResource(HInstance,
                                     FindResource(HInstance,
                                                  "SNIPETS",
                                                  RT_RCDATA));

  // Keep 'um from moving around,...
  char *cResourcePtr = (char*)LockResource(hCodeResource);

  // ...allocate some local memory for them and...
  cResourceBuffer = new char[ResourceSize];

  // ...transfer the global data to the local allocation.
  memcpy(cResourceBuffer, cResourcePtr, ResourceSize);

  // Make ASCIIZ strings out of the snippets by replacing bars
  // ('|') with zeros and load into snippets pointer array.
  int j = 0;
  int t = 0;
  char *cText = cResourceBuffer;
  for (int i=0; i < ResourceSize; i++)
  {
    if (cText[i] == '|') {
      cText[i] = 0;
      cCodeSnipets[j++] = &(cText[t]);
      t = i+1;
    }
  }
} // end of InitCodeGeneration()

//---------------------------------------------------------------
void __fastcall DoneCodeGeneration(void)
{
  delete cSourceBuffer;
  UnlockResource(hCodeResource);
  FreeResource(hCodeResource);
//delete cResourceBuffer;
} // end of DoneCodeGeneration()

//*****************************************************************
// interface void
void __fastcall ApplicationExpert(TIToolServices *ToolServices)
{
  String    usesClause;
  TFileName projectName;
  TFileName unitName;

  try
  {
    // Create an application expert and...
    auto_ptr<TAppExpert> d(new TAppExpert(Application));

    // ...do user input.
    if (d.get()->ShowModal() == mrOK) {

      // If that's good set it up for execution.
      InitCodeGeneration();

      try
      {
        projectName = ExpandFileName(*GenerateProjectSource(d.get()));
        GenerateHdrSourceFile(d.get());
        unitName = ExpandFileName(*GenerateMainSourceFile(d.get()));
        GenerateMainFormFile(d.get());
      } catch(...)
      {
      }

      DoneCodeGeneration();

      // open the new project
      if (ToolServices != NULL && ToolServices->CloseProject())
      {
        // Create a new project makefile
        TCreateProjectFlags CPF;
        AppCreatorEx *AppCreator = new AppCreatorEx(projectName, unitName, ToolServices);
        ToolServices->ProjectCreate(AppCreator, CPF << cpApplication);
       }
    }
  } catch(...)
  {
  }
} // end of ApplicationExpert()

