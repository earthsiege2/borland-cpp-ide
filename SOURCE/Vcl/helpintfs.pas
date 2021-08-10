{ *************************************************************************** }
{                                                                             }
{ Kylix and Delphi Cross-Platform Visual Component Library                    }
{                                                                             }
{ Copyright (c) 2000, 2001 Borland Software Corporation                       }
{                                                                             }
{ *************************************************************************** }


unit HelpIntfs;

{ *************************************************************************  }
{                                                                            }
{  This unit is the primary unit for the combined VCL/CLX Help System.       } 
{  TApplication contains a pointer to an IHelpSystem, through which it       }
{  calls into the Help System Manager. The Help System Manager maintains     }
{  a list of custom Help Viewers, which implement ICustomHelpViewer and,     }
{  if desired, one of several extended help interfaces derived from it.      }
{  Help Viewers talk to the Help System Manager through the IHelpManager     }
{  interface, which is returned to them when they register.                  }
{                                                                            }
{  Code wishing to invoke the Help System can go through Application, or     }
{  can call the flat function GetHelpSystem, which will return an            }
{  IHelpSystem if one is available. Viewers register by calling              }
{  RegisterViewer, which returns an IHelpManager.                            }
{                                                                            }
{  The same mechanism will work for design packages wishing to integrate     }
{  with the IDE Help System; calling HelpIntfs.RegisterViewer() in the       }
{  Register() procedure will cause the Viewer to be registered.              } 
{                                                                            }
{ *************************************************************************  }

interface

uses SysUtils, Classes;

type

 { IHelpSelector. IHelpSelector is used by the HelpSystem to ask the
   application to decide which keyword, out of multiple matches returned 
   by multiple different Help Viewers, it wishes to support. If an application 
   wishes to support this, it passes an IHelpSelector interface into
   IHelpSystem.AssignHelpSelector. }

  IHelpSelector = interface(IInterface)
    ['{B0FC9358-5F0E-11D3-A3B9-00C04F79AD3A}']
    function SelectKeyword(Keywords: TStrings) : Integer;
    function TableOfContents(Contents: TStrings): Integer;
  end;

 { IHelpSystem. IHelpSystem is the interface through which an application
   request that help be displayed. ShowHelp() uses functionality which is
   guaranteed to be supported by all Help Viewers. ShowContextHelp() and
   ShowTopicHelp() are supported only by extended Help Viewers. In the
   event that there are no extended Viewers installed, ShowTableOfContents asks
   the System to display a table of contents; either the first registered 
   Viewer's table of contents will be displayed, a dialog will be displayed to
   ask the user to pick one, or, if no Viewer supports tables of contents,
   an exception will be thrown. When appropriate, these procedures
   will raise an EHelpSystemException. Hook() is the mechanism by which
   the application asks the Help System to package winhelp-specific commands
  into something understood by the Help Viewers. }

 IHelpSystem = interface(IInterface)
   ['{B0FC9353-5F0E-11D3-A3B9-00C04F79AD3A}']
   procedure ShowHelp(const HelpKeyword, HelpFileName: String);
   procedure ShowContextHelp(const ContextID: Longint; const HelpFileName: String);
   procedure ShowTableOfContents;
   procedure ShowTopicHelp(const Topic, HelpFileName: String);
   procedure AssignHelpSelector(Selector: IHelpSelector);
   function Hook(Handle: Longint; HelpFile: String; Comand: Word; Data: Longint): Boolean;
 end;

 { ICustomHelpViewer. The Help System talks to Help Viewers through
   this interface. If there is *more* than one Help Viewer registered,
   the Help System calls UnderstandsKeyword() on each Viewer, which is required
   to return the number of available keyword matches. If more than one
   Viewer has help available for a particular keyword, then each Viewer
   is asked to supply a list of keyword strings through GetHelpStrings();
   the Help Manager allows the user to choose one, and then calls ShowHelp()
   only on the selected Viewer. At the time of registration, the Help
   Manager will call NotifyID to give the Viewer a cookie; if the Viewer
   disconnects, it must pass that cookie back to the Manager in the Release()
   call. If the Manager is disconnecting, it will call ShutDown() on all Viewers,
   to notify them that the System is going away and the application will be
   shutting down. If the Manager receives a request that it terminate all
   externally visible manifestations of the Help System, it will call
   SoftShutDown() on all Viewers. }

 ICustomHelpViewer = interface(IInterface)
   ['{B0FC9364-5F0E-11D3-A3B9-00C04F79AD3A}']
   function  GetViewerName : String;
   function  UnderstandsKeyword(const HelpString: String): Integer;
   function  GetHelpStrings(const HelpString: String): TStringList;
   function  CanShowTableOfContents : Boolean; 
   procedure ShowTableOfContents;
   procedure ShowHelp(const HelpString: String);
   procedure NotifyID(const ViewerID: Integer);
   procedure SoftShutDown;
   procedure ShutDown;
 end;

 { IExtendedHelpViewer.  Help Viewers which wish to support context-ids and
   topics may do so. Unlike standard keyword help, the Help Manager will
   only invoke the *first* registered Viewer which supports a particular
   context id or topic; this limitation is necessary in order to make
   interaction with WinHelp more efficient. }

 IExtendedHelpViewer = interface(ICustomHelpViewer)
   ['{B0FC9366-5F0E-11D3-A3B9-00C04F79AD3A}']
   function  UnderstandsTopic(const Topic: String): Boolean;
   procedure DisplayTopic(const Topic: String);
   function  UnderstandsContext(const ContextID: Integer; 
     const HelpFileName: String): Boolean;
   procedure DisplayHelpByContext(const ContextID: Integer; 
     const HelpFileName: String);
 end;

 { ISpecialWinHelpViewer. Certain Help System messages are difficult
   if not impossible to unpackage into commands that do not depend on
   WinHelp syntax. Help Viewers wishing to recieve such messages may
   implement this interface. Note that this interface is primarily
   intended for use in Windows-based applications and should only
   be implemented under Linux under extreme circumstances. }

 ISpecialWinHelpViewer = interface(IExtendedHelpViewer)
   ['{B0FC9366-5F0E-11D3-A3B9-00C04F79AD3A}']
   function CallWinHelp(Handle: LongInt; const HelpFile: String; Command: Word;
     Data: LongInt): Boolean;
 end;

 { IHelpManager. IHelpManager provides a mechanism for Help Viewers to
   talk to the Help System. Release() must be called by any Help Viewer
   when it is shutting down *unless* it is shutting down in response to
   a ShutDown() call. }

 IHelpManager = interface
   ['{B0FC9366-5F0E-11D3-A3B9-00C04F79AD3A}']
   function  GetHandle: LongInt; { sizeof(LongInt) = sizeof (HWND) }
   function  GetHelpFile: String;
   procedure Release(const ViewerID: Integer);
 end;

 { All help-specific error messages should be thrown as this type. }
 EHelpSystemException = class(Exception);

 { NOTE: RegisterViewer raises an exception on failure. }
 function RegisterViewer(newViewer: ICustomHelpViewer; 
   out Manager: IHelpManager): Integer;

 { NOTE: GetHelpSystem does not raise on failure. }
 function  GetHelpSystem(out System: IHelpSystem) : Integer;

{$IFDEF LINUX}

{ Constants used by the windows help system. Needed here to understand
  messages that come from, or are intended for, windows-based systems
  or emulations thereof. }

const
 HELP_CONTEXT = 1;
 HELP_QUIT = 2;
 HELP_INDEX = 3;
 HELP_CONTENTS = HELP_INDEX;
 HELP_HELPONHELP = 4;
 HELP_SETINDEX = 5;
 HELP_SETCONTENTS = HELP_SETINDEX;
 HELP_CONTEXTPOPUP = 8;
 HELP_FORCEFILE = 9;
 HELP_CONTEXTMENU = 10;
 HELP_FINDER = 11;
 HELP_WM_HELP = 12;
 HELP_SETPOPUP_POS = 13;
 HELP_TCARD_OTHER_CALLER = 17;
 HELP_KEY = 257;
 HELP_COMMAND = 258;
 HELP_PARTIALKEY = 261;
 HELP_MULTIKEY = 513;
 HELP_SETWINPOS = 515;
 HELP_TCARD_DATA = $10;
 HELP_TCARD = $8000;
{$ENDIF}

implementation

{$IFDEF MSWINDOWS}
uses Contnrs, Windows, RTLConsts;
{$ENDIF}
{$IFDEF LINUX}
uses Libc, Contnrs, RTLConsts;
{$ENDIF}

type

  { THelpViewerNode.
    THelpViewerNode is a small wrapper class which links a Help Viewer to
    its associated Viewer ID. }
  THelpViewerNode = class(TObject)
  private
    FViewer: ICustomHelpViewer;
    FViewerID: Integer;
  public
    constructor Create(Viewer: ICustomHelpViewer);
    property Viewer: ICustomHelpViewer read FViewer;
    property ViewerID : Integer read FViewerID write FViewerID;
  end;

  { THelpManager.
    THelpManager implements the IHelpSystem and IHelpManager interfaces. }
  THelpManager = class(TInterfacedObject, IHelpSystem, IHelpManager)
  private
    FHelpSelector: IHelpSelector;
    FViewerList: TObjectList;
    FExtendedViewerList: TObjectList;
    FSpecialWinHelpViewerList: TObjectList;
    FMinCookie : Integer;
    FHandle: LongInt;
    FHelpFile: String;
    procedure UnloadAllViewers;
    procedure DoSoftShutDown;
    procedure DoTableOfContents;
    function CallSpecialWinHelp(Handle: LongInt; const HelpFile: String;
      Command: Word; Data: LongInt): Boolean;
  public
    constructor Create;
    function RegisterViewer(newViewer: ICustomHelpViewer): IHelpManager;
    { IHelpSystem }
    procedure ShowHelp(const HelpKeyword, HelpFileName: String );
    procedure ShowContextHelp(const ContextID: Longint;
      const HelpFileName: String);
    procedure ShowTableOfContents;
    procedure ShowTopicHelp(const Topic, HelpFileName: String);
    procedure AssignHelpSelector(Selector: IHelpSelector);
    function Hook(Handle: Longint; HelpFile: String;
      Command: Word; Data: Longint) : Boolean;

      { IHelpManager }
    function GetHandle: LongInt;
    function GetHelpFile: String;
    procedure Release(const ViewerID: Integer);
      { properties }
    property Handle : Longint read FHandle write FHandle;
    property HelpFile : String read FHelpFile write FHelpFile;
    destructor Destroy; override;
  end;

{ global instance of THelpManager which TApplication can talk to. }
var
 HelpManager : THelpManager;

{ Warning: resource strings will be moved to RtlConst in the next revision. }
resourcestring
  hNoTableOfContents = 'Unable to find a Table of Contents';
  hNothingFound = 'No help found for %s';
  hNoContext = 'No context-sensitive help installed';
  hNoTopics = 'No topic-based help system installed';

{ Exported flat functions }

function RegisterViewer(newViewer: ICustomHelpViewer; 
  out Manager: IHelpManager): Integer;
begin
  if not Assigned(HelpManager) then
    HelpManager := THelpManager.Create;
  
  Manager := HelpManager.RegisterViewer(newViewer);
  Result := 0;
end;

function GetHelpSystem(out System : IHelpSystem) : Integer;
begin
  if not Assigned(HelpManager) then
  begin
    HelpManager := THelpManager.Create;
    HelpManager._AddRef;
  end;

  System := HelpManager as IHelpSystem;
  Result := 0;
end;

{ THelpViewerNode }

constructor THelpViewerNode.Create(Viewer: ICustomHelpViewer);
begin
  FViewer := Viewer;
  Viewer._AddRef;
end;

{ THelpManager }

constructor THelpManager.Create;
begin
  inherited Create;
  FViewerList := TObjectList.Create;
  FExtendedViewerList := TObjectList.Create;
  FSpecialWinHelpViewerList := TObjectList.Create;
  FHelpFile := '';
  FMinCookie := 1;
end;

function THelpManager.RegisterViewer(NewViewer: ICustomHelpViewer): IHelpManager;
var
  ExtendedViewer: IExtendedHelpViewer;
  SpecialViewer: ISpecialWinHelpViewer;
  NewNode: THelpViewerNode;
begin
  { insert it into the regular list; }
  NewNode := THelpViewerNode.Create(NewViewer);
  NewNode.ViewerID := FMinCookie;
  FViewerList.Insert(FViewerList.Count, NewNode);
  NewViewer.NotifyID(NewNode.ViewerID);
  { insert it into the context Viewer list, if appropriate. }

  if Supports(NewViewer, IExtendedHelpViewer, ExtendedViewer) then
  begin
    NewNode := THelpViewerNode.Create(ExtendedViewer);
    NewNode.ViewerID := FMinCookie;
    FExtendedViewerList.Insert(FExtendedViewerList.Count, NewNode);
  end;

  { insert it into the special win help Viewer list, if appropriate. }
  if Supports(NewViewer, ISpecialWinHelpViewer, SpecialViewer) then
  begin
    NewNode := THelpViewerNode.Create(SpecialViewer);
    NewNode.ViewerID := FMinCookie;
    FSpecialWinHelpViewerList.Insert(FSpecialWinHelpViewerList.Count, NewNode);
  end;
  
  FMinCookie := FMinCookie + 1;
  Result := Self as IHelpManager;
end;

procedure THelpManager.UnloadAllViewers;
var
  I: Integer;
begin
  for I:=0 to FViewerList.Count-1 do
  begin
    THelpViewerNode(FViewerList[I]).Viewer.ShutDown;
  end;
  FViewerList.Clear;
  FExtendedViewerList.Clear;
  FSpecialWinHelpViewerList.Clear;
end;

procedure THelpManager.DoSoftShutDown;
var
  I : Integer;
begin
  { this procedure is called when an application wants to shut down any
    *externally visible* evidence of help invocation, but does not want
    to terminate the Help Viewer. }
  for I := 0 to FViewerList.Count-1 do
  begin
    THelpViewerNode(FViewerList[I]).Viewer.SoftShutDown;
  end;
end;

procedure THelpManager.DoTableOfContents;
var
  ViewerNames : TStringList;
  I : Integer;
  HelpNode : THelpViewerNode;
begin

  { if there's only one Help Viewer, use its TOC, if it supports that. }
  if FViewerList.Count = 1 then
  begin
    if THelpViewerNode(FViewerList[0]).Viewer.CanShowTableOfContents then
       THelpViewerNode(FViewerList[0]).Viewer.ShowTableOfContents;
  end

  { otherwise, ask the Help Selector to do the job }
  else if FHelpSelector <> nil then
  begin
    ViewerNames := TStringList.Create;
    try
      { ask each Viewer which supports TOC to provide its name. }
      for I := 0 to FViewerList.Count -1 do
      begin
        HelpNode := THelpViewerNode(FViewerList[I]);
        if HelpNode.Viewer.CanShowTableOfContents then
           ViewerNames.AddObject(HelpNode.Viewer.GetViewerName, TObject(HelpNode));
      end;

      { if there is now more than one TOC provider, pass all of the names
        off to the selector and use its choice. }
      if ViewerNames.Count > 1 then
      begin
        ViewerNames.Sort;
        I := FHelpSelector.TableOfContents(ViewerNames);
        THelpViewerNode(ViewerNames.Objects[I]).Viewer.ShowTableOfContents;
      end
      else begin
        { otherwise, use the one TOC provider available. }
        THelpViewerNode(ViewerNames.Objects[0]).Viewer.ShowTableOfContents;
      end;
    finally
      ViewerNames.Free;
    end;
  end

  { or, if there's no selector, and the first guy supports a TOC, go with it ...}
  else if (FViewerList.Count > 0) and
          (THelpViewerNode(FViewerList[0]).Viewer.CanShowTableOfContents) then
  begin
    THelpViewerNode(FViewerList[0]).Viewer.ShowTableOfContents;
  end

  { or, complain }
  else raise EHelpSystemException.CreateRes(@hNoTableOfContents);
end;

function THelpManager.CallSpecialWinHelp(Handle: LongInt;
                                         const HelpFile: String;
                                         Command: Word;
																				 Data: LongInt): Boolean;
var
  View : ICustomHelpViewer;
begin
  Result := false;
  if HelpFile <> '' then FHelpFile := HelpFile;

  { only do something if someone is listening. }
  if FSpecialWinHelpViewerList.Count > 0 then
  begin
    { if there's only one special winhelp Viewer, then talk to it. }
    if FSpecialWinHelpViewerList.Count = 1 then
    begin
      View := THelpViewerNode(FSpecialWinHelpViewerList[0]).Viewer;
      Result := (View as ISpecialWinHelpViewer).CallWinHelp(Handle, HelpFile,
                                                            Command, Data);
    end else
    { if there's more then one special winhelp Viewer, then something
      very strange is going on. Pick the first one and hope it was ok.
      This might someday be delegatable to an IHelpSelector2 interface. }
    begin
       View := THelpViewerNode(FSpecialWinHelpViewerList[0]).Viewer;
       Result := (View as ISpecialWinHelpViewer).CallWinHelp(Handle, HelpFile,
                                                             Command, Data);
    end;
  end;
end;

{ THelpManager - IHelpSystem }

procedure THelpManager.ShowHelp(const HelpKeyword, HelpFileName : String);
var
  I, J: Integer;
  AvailableHelp: Integer;
  HelpfulViewerCount : Integer;
  ViewerIndex: Integer;
  AvailableHelpList: TStringList;
  ViewerHelpList: TStringList;
  HelpNode : THelpViewerNode;
  KeywordIndex : Integer;
  Obj: TObject;
  ObjString: String;
begin
  { nullify. }
  ViewerIndex := 0;
  HelpfulViewerCount := 0;

  { if the invoker passed in a help file name, use it; otherwise, assume
    that Application.HelpFile is correct, and use it. }
  if HelpFileName <> ''  then
    HelpFile := HelpFileName;

  { ask everyone how much help they have on this token, and maintain count;
    keep track of the last guy who said they had any help at all, in case
    they're the only one. }

  if FViewerList.Count > 0 then
  begin
    for I := 0 to (FViewerList.Count - 1) do
    begin
     AvailableHelp := THelpViewerNode(FViewerList[I]).Viewer.UnderstandsKeyword(HelpKeyword);
     if AvailableHelp > 0 then
     begin
       ViewerIndex := I;
       HelpfulViewerCount := HelpfulViewerCount + 1;
     end;
    end;

    { if nobody can help, game over. }
    if HelpfulViewerCount = 0 then
      raise EHelpSystemException.CreateResFmt(@hNothingFound, [PChar(HelpKeyword)]);

    { if one guy can help, go ahead. }
    if HelpfulViewerCount = 1 then
    begin
      THelpViewerNode(FViewerList[ViewerIndex]).Viewer.ShowHelp(HelpKeyword);
    end;

    { do complicated processing if more than one guy offers to help. }
    if HelpfulViewerCount > 1 then
    begin
     AvailableHelpList := TStringList.Create();

     { Ask each Viewer if it can supply help. If it can, then get the help
       strings and build a string list which maps help strings to the
       supplying Viewer. } { note: it may be more efficient to do this
       by caching the original responses to UnderstandsKeyword() in an array and
       then iterating through it. }
     for I := 0 to FViewerList.Count -1 do
     begin
       HelpNode := THelpViewerNode(FViewerList[I]);
       AvailableHelp := HelpNode.Viewer.UnderstandsKeyword(HelpKeyword);
       if AvailableHelp > 0 then
       begin
         ViewerHelpList := HelpNode.Viewer.GetHelpStrings(HelpKeyword);
         for J := 0 to ViewerHelpList.Count - 1 do
         begin
           AvailableHelpList.AddObject(ViewerHelpList.Strings[J], TObject(HelpNode));
         end;
         ViewerHelpList.Free;
       end;
     end;

     if FHelpSelector <> nil then
     begin
       AvailableHelpList.Sort;

       { pass the list off to some display mechanism. }
       KeywordIndex := FHelpSelector.SelectKeyword(AvailableHelpList);

       { God help us if the number doesn't mean what we think it did, ie.,
         if the client reordered and didn't maintain the original order. }
       if KeywordIndex >= 0 then
       begin
         Obj := AvailableHelpList.Objects[KeywordIndex];
         ObjString := AvailableHelpList.Strings[KeywordIndex];
         THelpViewerNode(Obj).Viewer.ShowHelp(ObjString);
       end;
       { if KeywordIndex is negative, they cancelled out of the help
         selection dialog; the right thing to do is silently fall through. }
     end
     else begin
       { The programmer doesn't want to override the default behavior,
       so just pick the first one and hope it was right. }
       Obj := AvailableHelpList.Objects[0];
       ObjString := AvailableHelpList.Strings[0];
       THelpViewerNode(Obj).Viewer.ShowHelp(ObjString);
     end;

     AvailableHelpList.Free;
    end;
  end;
end;

procedure THelpManager.ShowContextHelp(const ContextID: Longint; const HelpFileName: String);
var
 I : Integer;
 View: ICustomHelpViewer;
begin
  if HelpFileName <> '' then HelpFile := HelpFileName;

  { if nobody handles context-sensitive help, then bail. }
  if FExtendedViewerList.Count = 0 then
    raise EHelpSystemException.CreateRes(@hNoContext)

 { if multiple people handle context-sensitive help, hand it off to the first
   handler. This will lead to some subtle annoying behavior, but the opposite
   is worse. Note that contexts depend on file names, while tokens do not;
   that's a wierd winhelpism. }

  else begin
    for I := 0 to FExtendedViewerList.Count -1 do
    begin
      View := THelpViewerNode(FExtendedViewerList[I]).Viewer;
      if (View as IExtendedHelpViewer).UnderstandsContext(ContextID, HelpFileName) then
      begin
        (View as IExtendedHelpViewer).DisplayHelpByContext(ContextID, HelpFileName);
        break;
      end;
    end;
  end;
end;

procedure THelpManager.ShowTableOfContents;
begin
  DoTableOfContents;
end;

procedure THelpManager.ShowTopicHelp(const Topic, HelpFileName: String);
var
  I: Integer;
  View: ICustomHelpViewer;
begin
  if HelpFileName <> '' then HelpFile := HelpFileName;
  { if nobody supports this kind of help request, bail. }
  if FExtendedViewerList.Count = 0 then
    raise EHelpSystemException.CreateRes(@hNoTopics)

  { otherwise, iterate through the list, and pass it off to the first
    guy who cares. }
  else begin
    for I := 0 to FExtendedViewerList.Count - 1 do
    begin
      View := THelpViewerNode(FExtendedViewerList[I]).Viewer;
      if (View as IExtendedHelpViewer).UnderstandsTopic(Topic) then
      begin
        (View as IExtendedHelpViewer).DisplayTopic(Topic);
        break;
      end;
    end;
  end;
end;

procedure THelpManager.AssignHelpSelector(Selector: IHelpSelector);
begin
  if FHelpSelector <> nil then FHelpSelector := nil;
  FHelpSelector := Selector;
  Selector._AddRef;
end;

function THelpManager.Hook(Handle: Longint; HelpFile: String;
  Command: Word; Data: Longint): Boolean;
begin
  if HelpFile <> '' then FHelpFile := HelpFile;
  case Command of
    HELP_CONTEXT:
    begin
     ShowContextHelp(Data, HelpFile);
    end;
    { note -- the following subtly turns HELP_CONTEXTPOPUP into HELP_CONTEXT.
      This is consistent with D5 behavior but may not be ideal. }
    HELP_CONTEXTPOPUP:
    begin
     ShowContextHelp(Data, HelpFile);
    end;
    HELP_QUIT:
    begin
     DoSoftShutDown;
    end;
    HELP_CONTENTS:
    begin
      DoTableOfContents;
    end;
  else
    CallSpecialWinHelp(Handle, HelpFile, Command, Data);
  end;
  Result := true;
end;

{ THelpManager --- IHelpManager }

function THelpManager.GetHandle: LongInt;
begin
  Result := Handle;
end;

function THelpManager.GetHelpFile: String;
begin
  Result := HelpFile;
end;

procedure THelpManager.Release(const ViewerID: Integer);
var
  I : Integer;
begin
  for I := 0 to FViewerList.Count-1 do
  begin
    if THelpViewerNode(FViewerList[I]).ViewerID = ViewerID then
      FViewerList.Delete(I);
  end;
  for I := 0 to FExtendedViewerList.Count-1 do
  begin
    if THelpViewerNode(FExtendedViewerList[I]).ViewerID = ViewerID then
      FExtendedViewerList.Delete(I);
  end;
  for I := 0 to FSpecialWinHelpViewerList.Count-1 do
  begin
    if THelpViewerNode(FSpecialWinHelpViewerList[I]).ViewerID = ViewerID then
      FSpecialWinHelpViewerList.Delete(I);
  end;
end;

destructor THelpManager.Destroy;
begin
  UnloadAllViewers;
  if FHelpSelector <> nil then FHelpSelector := nil;
  FSpecialWinHelpViewerList.Free;
  FExtendedViewerList.Free;
  FViewerList.Free;
  inherited Destroy;
end;

initialization
finalization
  if Assigned(HelpManager) then HelpManager := nil;
end.
