
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{  Copyright (c) 1995-2001 Borland Software Corporation }
{                                                       }
{*******************************************************}

unit ActnRes;

interface

(*$HPPEMIT '#pragma link "dclact.lib"'*)

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  ImgList, StdActns, ActnList, ExtActns;

type
  TStandardActions = class(TDataModule)
    ActionList1: TActionList;
    EditCut1: TEditCut;
    EditCopy1: TEditCopy;
    EditPaste1: TEditPaste;
    WindowArrange1: TWindowArrange;
    WindowCascade1: TWindowCascade;
    WindowClose1: TWindowClose;
    WindowMinimizeAll1: TWindowMinimizeAll;
    WindowTileHorizontal1: TWindowTileHorizontal;
    WindowTileVertical1: TWindowTileVertical;
    ImageList1: TImageList;
    EditDelete1: TEditDelete;
    EditSelectAll1: TEditSelectAll;
    EditUndo1: TEditUndo;
    HelpContents1: THelpContents;
    HelpOnHelp1: THelpOnHelp;
    HelpTopicSearch1: THelpTopicSearch;
    FileExit1: TFileExit;
    FileOpen1: TFileOpen;
    FilePrintSetup1: TFilePrintSetup;
    FileSaveAs1: TFileSaveAs;
    RichEditBold1: TRichEditBold;
    RichEditItalic1: TRichEditItalic;
    RichEditUnderline1: TRichEditUnderline;
    SearchFind1: TSearchFind;
    SearchFindNext1: TSearchFindNext;
    SearchReplace1: TSearchReplace;
    RichEditAlignCenter1: TRichEditAlignCenter;
    RichEditAlignLeft1: TRichEditAlignLeft;
    RichEditAlignRight1: TRichEditAlignRight;
    RichEditBullets1: TRichEditBullets;
    RichEditStrikeOut1: TRichEditStrikeOut;
    ColorSelect1: TColorSelect;
    FontEdit1: TFontEdit;
    OpenPicture1: TOpenPicture;
    SavePicture1: TSavePicture;
    FileRun1: TFileRun;
    PreviousTab1: TPreviousTab;
    NextTab1: TNextTab;
    SearchFindFirst1: TSearchFindFirst;
    HelpContextAction1: THelpContextAction;
    BrowseURL1: TBrowseURL;
    DownLoadURL1: TDownLoadURL;
    ListControlCopySelection1: TListControlCopySelection;
    ListControlDeleteSelection1: TListControlDeleteSelection;
    ListControlSelectAll1: TListControlSelectAll;
    ListControlClearSelection1: TListControlClearSelection;
    ListControlMoveSelection1: TListControlMoveSelection;
    SendMail1: TSendMail;
    PrintDlg1: TPrintDlg;
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  StandardActions: TStandardActions;

implementation

{$R *.dfm}

end.
