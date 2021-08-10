{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{  Copyright (c) 2000-2001 Borland Software Corp.       }
{                                                       }
{*******************************************************}
unit WebFact;

interface

uses
  Classes, HTTPApp;

type

  TBaseWebModuleFactory = class(TAbstractWebModuleFactory)
  private
    FComponentClass: TComponentClass;
    FCacheMode: TWebModuleCacheMode;
    FCreateMode: TWebModuleCreateMode;
  protected
    function GetModuleName: string; override;
    function GetIsAppModule: Boolean; override;
    function GetCreateMode: TWebModuleCreateMode; override;
    function GetCacheMode: TWebModuleCacheMode; override;
    function GetComponentClass: TComponentClass; override;
    constructor Create(AComponentClass: TComponentClass;
      ACreateMode: TWebModuleCreateMode;
      ACacheMode: TWebModuleCacheMode);
  public
    procedure PreventDestruction; override;
    function GetModule: TComponent; override;
  end;

  TWebPageAccessFlags = (wpPublished, wpLoginRequired);
  TWebPageAccess = set of TWebPageAccessFlags;
  TBaseWebPageInfo = class(TAbstractWebPageInfo)
  private
    FFile: string;
    FName: string;
    FAccess: TWebPageAccess;
    FDescription: string;
    FTitle: string;
    FViewAccess: string;
  protected
    constructor Create(
      AAccess: TWebPageAccess;
      const AFile, AName: string;
      const ATitle, ADescription: string;
      const AViewAccess: string);
    function GetPageFile: string; override;
    function GetPageHREF: string; override;
    function GetPageName: string; override;
    function GetIsPublished: Boolean; override;
    function GetIsLoginRequired: Boolean; override;
    function GetPageDescription: string; override;
    function GetPageTitle: string; override;
    function GetViewAccess: string; override;
    procedure SetFactory(AFactory: TAbstractWebPageModuleFactory); override;
  end;

  TWebPageInfo = class(TBaseWebPageInfo)
  public
    constructor Create(
      AAccess: TWebPageAccess = [wpPublished];
      const APageFile: string = '.html'; const APageName: string = '';
      const ACaption: string = ''; const ADescription: string = '';
      const AViewAccess: string = '');
  end;

  TBaseWebPageModuleFactory = class(TAbstractWebPageModuleFactory)
  private
    FComponentClass: TComponentClass;
    FCacheMode: TWebModuleCacheMode;
    FCreateMode: TWebModuleCreateMode;
  protected
    constructor Create(AComponentClass: TComponentClass;
      AWebPageInfo: TAbstractWebPageInfo;
      ACreateMode: TWebModuleCreateMode;
      ACacheMode: TWebModuleCacheMode);
    function GetModuleName: string; override;
    function GetIsAppModule: Boolean; override;
    function GetCreateMode: TWebModuleCreateMode; override;
    function GetCacheMode: TWebModuleCacheMode; override;
    function GetComponentClass: TComponentClass; override;
  public
    procedure PreventDestruction; override;
    function GetModule: TComponent; override;
  end;

  TWebPageModuleFactory = class(TBaseWebPageModuleFactory)
  public
    constructor Create(AComponentClass: TComponentClass;
      AWebPageInfo: TAbstractWebPageInfo;
      ACreateMode: TWebModuleCreateMode = crOnDemand;
      ACacheMode: TWebModuleCacheMode = caCache);
  end;

  TWebDataModuleFactory = class(TBaseWebModuleFactory)
  public
    constructor Create(AComponentClass: TComponentClass;
      ACreateMode: TWebModuleCreateMode = crOnDemand;
      ACacheMode: TWebModuleCacheMode = caCache);
  end;

  TWebAppDataModuleFactory = class(TBaseWebModuleFactory)
  protected
    function GetIsAppModule: Boolean; override;
  public
    constructor Create(AComponentClass: TComponentClass;
      ACacheMode: TWebModuleCacheMode = caCache);
  end;

  TWebAppPageModuleFactory = class(TBaseWebPageModuleFactory)
  protected
    function GetIsAppModule: Boolean; override;
  public
    constructor Create(AComponentClass: TComponentClass;
      AWebPageInfo: TAbstractWebPageInfo;
      ACacheMode: TWebModuleCacheMode = caCache);
  end;

implementation

uses
 TypInfo, WebComp, SysUtils, WebCntxt, SiteComp;

{ TBaseWebModuleFactory }

constructor TBaseWebModuleFactory.Create(AComponentClass: TComponentClass;
  ACreateMode: TWebModuleCreateMode; ACacheMode: TWebModuleCacheMode);
begin
  inherited Create;
  FComponentClass := AComponentClass;
  FCacheMode := ACacheMode;
  FCreateMode := ACreateMode;

end;

function TBaseWebModuleFactory.GetCacheMode: TWebModuleCacheMode;
begin
  Result := FCacheMode;
end;

function TBaseWebModuleFactory.GetComponentClass: TComponentClass;
begin
  Result := FComponentClass;
end;

function TBaseWebModuleFactory.GetCreateMode: TWebModuleCreateMode;
begin
  Assert((not IsAppModule) or (FCreateMode = crAlways), 'Invalid createmode');
  Result := FCreateMode;
end;

function TBaseWebModuleFactory.GetIsAppModule: Boolean;
begin
  Result := False;
end;

function TBaseWebModuleFactory.GetModule: TComponent;
begin
  Result := FComponentClass.Create(nil);
end;

function TBaseWebModuleFactory.GetModuleName: string;
begin
  Result := Copy(FComponentClass.ClassName, 2, MaxInt);
end;

procedure TBaseWebModuleFactory.PreventDestruction;
begin
  FCacheMode := caCache;
end;

{ TBaseWebPageModuleFactory }

constructor TBaseWebPageModuleFactory.Create(AComponentClass: TComponentClass;
      AWebPageInfo: TAbstractWebPageInfo;
      ACreateMode: TWebModuleCreateMode;
      ACacheMode: TWebModuleCacheMode);
begin
  FComponentClass := AComponentClass;
  FCacheMode := ACacheMode;
  FCreateMode := ACreateMode;
  inherited Create(AWebPageInfo);
end;

function TBaseWebPageModuleFactory.GetModule: TComponent;
begin
  Result := FComponentClass.Create(nil);
end;

function TBaseWebPageModuleFactory.GetCacheMode: TWebModuleCacheMode;
begin
  Result := FCacheMode;
end;

function TBaseWebPageModuleFactory.GetComponentClass: TComponentClass;
begin
  Result := FComponentClass;
end;

function TBaseWebPageModuleFactory.GetCreateMode: TWebModuleCreateMode;
begin
  Assert((not IsAppModule) or (FCreateMode = crAlways), 'Invalid createmode');
  Result := FCreateMode;
end;

function TBaseWebPageModuleFactory.GetIsAppModule: Boolean;
begin
  Result := False;
end;

function TBaseWebPageModuleFactory.GetModuleName: string;
begin
  Result := Copy(FComponentClass.ClassName, 2, MaxInt);
end;

procedure TBaseWebPageModuleFactory.PreventDestruction;
begin
  FCacheMode := caCache;
end;

{ TWebAppPageModuleFactory }

constructor TWebAppPageModuleFactory.Create(AComponentClass: TComponentClass;
  AWebPageInfo: TAbstractWebPageInfo;
  ACacheMode: TWebModuleCacheMode);
begin
  inherited Create(AComponentClass, AWebPageInfo, crAlways, ACacheMode);
end;

function TWebAppPageModuleFactory.GetIsAppModule: Boolean;
begin
  Result := True;
end;

{ TWebPageModuleFactory }

constructor TWebPageModuleFactory.Create(AComponentClass: TComponentClass;
  AWebPageInfo: TAbstractWebPageInfo;
  ACreateMode: TWebModuleCreateMode; ACacheMode: TWebModuleCacheMode);
begin
  inherited;
end;

{ TWebAppDataModuleFactory }

constructor TWebAppDataModuleFactory.Create(
  AComponentClass: TComponentClass; ACacheMode: TWebModuleCacheMode);
begin
  inherited Create(AComponentClass, crAlways, ACacheMode);
end;

function TWebAppDataModuleFactory.GetIsAppModule: Boolean;
begin
  Result := True;
end;

{ TWebDataModuleFactory }

constructor TWebDataModuleFactory.Create(AComponentClass: TComponentClass;
  ACreateMode: TWebModuleCreateMode; ACacheMode: TWebModuleCacheMode);
begin
  inherited;
end;

{ TBaseWebPageInfo }

constructor TBaseWebPageInfo.Create(
      AAccess: TWebPageAccess;
      const AFile, AName: string;
      const ATitle, ADescription, AViewAccess: string);
begin
  FAccess := AAccess;
  FFile := AFile;
  FName := AName;
  FDescription := ADescription;
  FTitle := ATitle;
  FViewAccess := AViewAccess;
end;

function TBaseWebPageInfo.GetIsPublished: Boolean;
begin
  Result := wpPublished in FAccess;
end;

function TBaseWebPageInfo.GetIsLoginRequired: Boolean;
begin
  Result := wpLoginRequired in FAccess;
end;

function TBaseWebPageInfo.GetPageTitle: string;
begin
  Result := FTitle;
end;

function TBaseWebPageInfo.GetPageDescription: string;
begin
  Result := FDescription;
end;

function TBaseWebPageInfo.GetPageFile: string;
begin
  Result := FFile;
end;

function TBaseWebPageInfo.GetPageHREF: string;
begin
  if WebContext.Request <> nil then
    Result := WebContext.Request.InternalScriptName + '/' + PageName
  else
    Result := '';
end;

function TBaseWebPageInfo.GetPageName: string;
begin
  Result := FName;
end;

procedure TBaseWebPageInfo.SetFactory(
  AFactory: TAbstractWebPageModuleFactory);
begin
  inherited;
  if FName = '' then
    FName := Copy(Factory.ComponentClass.ClassName, 2, MaxInt);
  if (FFile <> '') then
    if AnsiCompareFileName(ExtractFileExt(FFile), FFile) = 0 then
      // FFile is a file ext
      FFile := ChangeFileExt(GetTypeData(Factory.ComponentClass.ClassInfo)^.UnitName, FFile)
end;

function TBaseWebPageInfo.GetViewAccess: string;
begin
  Result := FViewAccess;
end;

{ TWebPageInfo }

constructor TWebPageInfo.Create(AAccess: TWebPageAccess; const APageFile, APageName: string;
  const ACaption, ADescription, AViewAccess: string);
begin
  inherited;
end;

end.
