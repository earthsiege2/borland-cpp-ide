
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 2000-2001 Borland Software Corp.  }
{                                                       }
{*******************************************************}

unit DBAdaptImg;

interface

{$IFDEF MSWINDOWS}
uses Classes, Messages, HTTPApp, WebComp, DB, SiteComp, SysUtils,
  WebContnrs, WebAdapt, DBAdapt, AdaptReq;
{$ENDIF}
{$IFDEF LINUX}
uses Classes, HTTPApp, WebComp, DB, SiteComp, SysUtils,
  WebContnrs, WebAdapt, DBAdapt, AdaptReq;
{$ENDIF}

type
  TImageDataSetFieldGetImageEvent = procedure(Sender: TObject;
    var MimeType: string; var Image: TStream; var Owned: Boolean) of object;

  TCustomDataSetAdapterImageField = class(TBaseDataSetAdapterImageField,
    IGetAdapterImage, IGetAdapterItemRequestParams,
    IAdapterRequestHandler, IWebImageHREF)
  private
    FOnGetHREF: TImageFieldGetHREFEvent;
    FOnGetImage: TImageDataSetFieldGetImageEvent;
  protected
    function CheckOrUpdateValue(AActionRequest: IActionRequest;
      AFieldIndex: Integer; AUpdate: Boolean): Boolean;
    function GetDataSetFieldValue(Field: TField): Variant; override;
    { IWebImageHREF }
    function ImplWebImageHREF(var AHREF: string): Boolean; virtual;
    function WebImageHREF(var AHREF: string): Boolean;
    { IAdapterRequestHandler }
    procedure CreateRequestContext(DispatchParams: IAdapterDispatchParams);
    procedure ImplCreateRequestContext(DispatchParams: IAdapterDispatchParams);
    function HandleRequest(DispatchParams: IAdapterDispatchParams): Boolean;
    function ImplHandleRequest(DispatchParams: IAdapterDispatchParams): Boolean; virtual;
    { ICheckValueChange }
    function ImplCheckValueChange(AActionRequest: IActionRequest;
      AFieldIndex: Integer): Boolean; override;
    { IUpdateValue }
    procedure ImplUpdateValue(AActionRequest: IActionRequest; AFieldIndex: Integer); override;
    { IGetHTMLStyle }
    function GetDisplayStyleType(const AAdapterMode: string): TAdapterDisplayHTMLElementType; override;
    function GetInputStyleType(const AAdapterMode: string): TAdapterInputHTMLElementType; override;
    { IGetAdapterImage }
    function GetAdapterImage: IInterface;
    { IRenderAdapterImage }
    procedure RenderAdapterImage(ARequest: IImageRequest; AResponse: IImageResponse);
    { IGetAdapterItemRequestParams }
    procedure GetAdapterItemRequestParams(
      var AIdentifier: string; AParams: IAdapterItemRequestParams);
  public
    constructor Create(AOwner: TComponent); override;
    property OnGetImage: TImageDataSetFieldGetImageEvent read FOnGetImage write FOnGetImage;
    property OnGetHREF: TImageFieldGetHREFEvent read FOnGetHREF write FOnGetHREF;
  end;

  TDataSetAdapterImageField = class(TCustomDataSetAdapterImageField)
  published
    property DataSetField;
    property ViewAccess;
    property ModifyAccess;
    property OnGetImage;
    property OnGetHREF;
    property FieldModes;
  end;

implementation

uses Variants, WebCntxt,
  AutoAdap,
  {$IFDEF MSWINDOWS}
  Graphics, jpeg,
{$ENDIF}
  SiteConst;

{ TCustomDataSetAdapterImageField }

function TCustomDataSetAdapterImageField.GetAdapterImage: IInterface;
begin
  case Adapter.Mode of
    amInsert, amQuery:  Result := nil
  else
    Result := Self;
  end;
end;

function TCustomDataSetAdapterImageField.GetDisplayStyleType(const AAdapterMode: string): TAdapterDisplayHTMLElementType;
begin
  Result := htmldImage;
end;

function TCustomDataSetAdapterImageField.GetInputStyleType(const AAdapterMode: string): TAdapterInputHTMLElementType;
begin
  Result := htmliFile;
end;

procedure TCustomDataSetAdapterImageField.RenderAdapterImage(
  ARequest: IImageRequest; AResponse: IImageResponse);
var
  S: TStream;
  Bytes: array[0..7] of Byte; // Used for reading in the image header
  Response: TWebResponse;
  Field: TField;
  ContentType: string;
  ContentStream: TStream;
  MimeType: string;
  Image: TStream;
  Owned: Boolean;

  {$IFDEF MSWINDOWS}
  procedure ConvertBitmapToJpeg;
  var
    Bmp: TBitmap;
    JPEG: TJPEGImage;
  begin
    // Convert the bitmap to a jpeg
    Bmp := TBitmap.Create;
    try
      Bmp.LoadFromStream(ContentStream);
      JPEG := TJPEGImage.Create;
      try
        JPEG.Assign(Bmp);
        S := TMemoryStream.Create;
        JPEG.SaveToStream(S);
        S.Seek(0, soFromBeginning);
        ContentStream.Free; // Since, it already contained the blob
        ContentStream := S;
      finally
        JPEG.Free;
      end;
      ContentType := 'image/jpeg';
    finally
      Bmp.Free;
    end
  end;
  {$ENDIF}

begin
  CheckViewAccess;
  Response := WebContext.Response;
  Response.ContentType := 'text/html'; // for any exceptions that may happen
  ContentStream := nil;
  Adapter.ExtractRequestParams(ARequest);
  if Adapter.SilentLocate(Adapter.LocateParamsList, True) then
  begin
    if Assigned(FOnGetImage) then
    begin
      Image := nil;
      Owned := True;
      S := nil;
      FOnGetImage(Self, MimeType, Image, Owned);
      if Image <> nil then
      begin
        try
          if not Owned then
          begin
            S := TMemoryStream.Create;
            S.CopyFrom(Image, 0);
          end
          else
            S := Image;
          S.Seek(0, soFromBeginning);
        except
          if Owned then
            Image.Free;
          if Image <> S then
            S.Free;
          raise;
        end;
        Assert(MimeType <> '');
        ContentType := MimeType;
        ContentStream := S;
      end;
    end;
    if ContentStream = nil then
    begin
      Field := Adapter.DataSet.FindField(DataSetField);
      if Assigned(Field) then
      begin
        ContentType := '';
        ContentStream := Field.DataSet.CreateBlobStream(Field, bmRead);
        // Try reading the first few (8 to be exact) bytes of the content
        // stream to see what type of image it is.
        try
          if ContentStream.Size < SizeOf(Bytes) then
            raise EAdapterFieldException.CreateFmt(sInvalidImageSize, [SizeOf(Bytes)]);

          ContentStream.Read(Bytes[0], SizeOf(Bytes));
          // 0xFFD8 is the starting marker for a JPEG
          if (Bytes[0] = $FF) and (Bytes[1] = $D8) then
            ContentType := 'image/jpeg' { Do not localize}
          // 'GIF' (as in the string literal) is the starting marker
          // for a GIF
          else if (Bytes[0] = Ord('G')) and { Do not localize}
                  (Bytes[1] = Ord('I')) and { Do not localize}
                  (Bytes[2] = Ord('F')) then { Do not localize}
            ContentType := 'image/gif' { Do not localize}
          // For ping, the first 8 bytes header is:
          // (HEX)                 89  50  4e  47  0d  0a  1a  0a
          // (ASCII C notation)    \211   P   N   G  \r  \n \032 \n
          else if (Bytes[0] = $89) and
                  (Bytes[1] = $50) and
                  (Bytes[2] = $4e) and
                  (Bytes[3] = $47) and
                  (Bytes[4] = $0d) and
                  (Bytes[5] = $0a) and
                  (Bytes[6] = $1a) and
                  (Bytes[7] = $0a) then
            ContentType := 'image/png' { Do not localize}
          {$IFDEF MSWINDOWS}
            // Paradox graphic header (bitmaps)
            //   TGraphicHeader = record
            //     Count: Word;                { Fixed at 1 }
            //     HType: Word;                { Fixed at $0100 }
            //     Size: Longint;              { Size not including header }
            //   end;
            // This looks strange below due to the byte order
          else if (Bytes[0] = $01) and
                  (Bytes[1] = $00) and
                  (Bytes[2] = $00) and
                  (Bytes[3] = $01) then // Ignore the Size:Longint
          begin
            // Remove the TGraphicHeader
            // SizeOf(TGraphicHeader) = 8 bytes, but TGraphicHeaderis not public
            ContentStream.Seek(8, soFromBeginning);
            ConvertBitmapToJpeg;
          end
          {$ENDIF}
          else if (Bytes[0] = Ord('B')) and   { Do not localize}
                   (Bytes[1] = Ord('M')) then // Windows bitmap  { Do not localize}
          {$IFDEF MSWINDOWS}
            ConvertBitmapToJpeg
          {$ENDIF MSWINDOWS}
          {$IFDEF LINUX}
            raise EAdapterFieldException.Create(Format(sIncorrectImageFormat,
              ['image/bmp']), FieldName)  { Do not localize}
          {$ENDIF LINUX}
          else
            raise EAdapterFieldException.Create(Format(sIncorrectImageFormat,
              ['']), FieldName)
        except
          FreeAndNil(ContentStream);
          raise;
        end;
        // Go back to the start of the file.
        ContentStream.Position := 0;
      end;
    end;
  end;
  Response.ContentType := ContentType;
  Response.ContentStream := ContentStream;
end;

function GetActionFieldValues(AActionRequest: IActionRequest): IActionFieldValues;
begin
  if not Supports(AActionRequest, IActionFieldValues, Result) then
    Assert(False);
end;

function TCustomDataSetAdapterImageField.CheckOrUpdateValue(AActionRequest: IActionRequest; AFieldIndex: Integer;
  AUpdate: Boolean): Boolean;
var
  Field: TField;
  FieldValue: IActionFieldValue;
{$IFDEF MSWINDOWS}
  Bmp: TBitmap;
{$ENDIF}
begin
  Result := False;
  Assert(Adapter <> nil);
  Assert(Adapter.DataSet <> nil);
  with GetActionFieldValues(AActionRequest) do
    FieldValue := Values[AFieldIndex];
  if FieldValue.FileCount > 0 then
  begin
    Field := Adapter.DataSet.FindField(DataSetField);
    if Field = nil then
      Adapter.RaiseFieldNotFound(DataSetField);
    if FieldValue.FileCount = 1 then
    begin
      if AUpdate then
      begin
        {$IFDEF MSWINDOWS}
        if FieldValue.Files[0].ContentType = 'image/bmp' then
        begin
          Bmp := TBitmap.Create;
          try
            Bmp.LoadFromStream(FieldValue.Files[0].Stream);
            Field.Assign(Bmp);
          finally
            Bmp.Free;
          end;
        end
        else
        {$ENDIF MSWINDOWS}
        // Only support jpeg and gif on Kylix. pjpeg is sent by IE, and is "progressive" jpeg
        if (FieldValue.Files[0].ContentType = 'image/jpeg') or
           (FieldValue.Files[0].ContentType = 'image/pjpeg') or
           (FieldValue.Files[0].ContentType = 'image/gif') or
           (FieldValue.Files[0].ContentType = 'image/png') or
           (FieldValue.Files[0].ContentType = 'image/x-png') then
          (Field as TBlobField).LoadFromStream(FieldValue.Files[0].Stream)
        else
          raise EAdapterFieldException.Create(Format(sIncorrectImageFormat, [FieldValue.Files[0].ContentType]),
            FieldName);
      end
      else
        Result := True;
    end
    else
      RaiseMultipleFilesException(FieldName);
  end
  else if (FieldValue.ValueCount > 0) and (FieldValue.Values[0] <> '') then
    raise EAdapterFieldException.Create(sFileExpected,
      FieldName);
end;

procedure TCustomDataSetAdapterImageField.ImplUpdateValue(AActionRequest: IActionRequest; AFieldIndex: Integer);
begin
  CheckModifyAccess;
  CheckOrUpdateValue(AActionRequest, AFieldIndex, True);
end;

function TCustomDataSetAdapterImageField.GetDataSetFieldValue(
  Field: TField): Variant;
begin
  // Field.Value will return binary data.  Use DisplayText instead.
  Result := Field.DisplayText;
end;

function TCustomDataSetAdapterImageField.ImplCheckValueChange(
  AActionRequest: IActionRequest; AFieldIndex: Integer): Boolean;
begin
  Result := CheckOrUpdateValue(AActionRequest, AFieldIndex, False);
end;

function TCustomDataSetAdapterImageField.ImplWebImageHREF(var AHREF: string): Boolean;
begin
  if DesigningComponent(Self) and Assigned(GetHTMLSampleImage) then
    AHREF := GetHTMLSampleImage
  else
  begin
    AHREF := '';
    if Assigned(FOnGetHREF) then
      FOnGetHREF(Self, AHREF);
  end;
  Result := AHREF <> '';
end;

function TCustomDataSetAdapterImageField.WebImageHREF(var AHREF: string): Boolean;
begin
  Result := ImplWebImageHREF(AHREF);
end;

procedure TCustomDataSetAdapterImageField.CreateRequestContext(
  DispatchParams: IAdapterDispatchParams);
begin
  ImplCreateRequestContext(DispatchParams);
end;

function TCustomDataSetAdapterImageField.HandleRequest(
  DispatchParams: IAdapterDispatchParams): Boolean;
begin
  Result := ImplHandleRequest(DispatchParams);
end;

procedure TCustomDataSetAdapterImageField.ImplCreateRequestContext(
  DispatchParams: IAdapterDispatchParams);
var
  Obj: TBasicImageRequestImpl;
begin
  Obj := TBasicImageRequestImpl.Create(DispatchParams);
  TBasicImageResponseImpl.Create(Obj);
end;

function TCustomDataSetAdapterImageField.ImplHandleRequest(
  DispatchParams: IAdapterDispatchParams): Boolean;
var
  ImageRequest: IImageRequest;
  ImageResponse: IImageResponse;
begin
  Result := Supports(WebContext.AdapterRequest, IImageRequest, ImageRequest) and
    Supports(WebContext.AdapterResponse, IImageResponse, ImageResponse);
  Assert(Result);
  if Result then
    RenderAdapterImage(ImageRequest, ImageResponse);
end;

procedure TCustomDataSetAdapterImageField.GetAdapterItemRequestParams(
  var AIdentifier: string; AParams: IAdapterItemRequestParams);
begin
  AIdentifier := MakeAdapterRequestIdentifier(Self);
  Adapter.EncodeActionParamsFlags(AParams, [poLocateParams]);
end;

constructor TCustomDataSetAdapterImageField.Create(AOwner: TComponent);
begin
  inherited;
  FieldModes := [amInsert, amEdit, amBrowse {, amQuery}];
end;

initialization
  DataSetAdapterImageFieldClass := TDataSetAdapterImageField;
end.

