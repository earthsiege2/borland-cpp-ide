{ *************************************************************************** }
{                                                                             }
{ Delphi and Kylix Cross-Platform Visual Component Library                    }
{                                                                             }
{ Copyright (c) 2000, 2001 Borland Software Corporation                       }
{                                                                             }
{ *************************************************************************** }


unit QImgList;

{$T-,H+,X+}

interface

uses
  Classes, Types, Qt, QGraphics;

type
{ TChangeLink }

  TCustomImageList = class;

  TChangeLink = class(TObject)
  private
    FSender: TCustomImageList;
    FOnChange: TNotifyEvent;
  public
    destructor Destroy; override;
    procedure Change; dynamic;
    property OnChange: TNotifyEvent read FOnChange write FOnChange;
    property Sender: TCustomImageList read FSender write FSender;
  end;

{ TCustomImageList }
  TImageType = (itImage, itMask);
  TImageIndex = type Integer;

  TCustomImageList = class(TComponent)
  private
    FOnChange: TNotifyEvent;
    FClients: TList;
    FChanged: Boolean;
    FHeight: Integer;
    FWidth: Integer;
    FUpdateCount: Integer;
    FMasked: Boolean;
    FBkColor: TColor;
    FPixmapList: TList;
    FTempMask: QBitmapH;
    FMaskColor: TColor;
    procedure BeginUpdate;
    procedure EndUpdate;
    procedure SetHeight(const Value: Integer);
    procedure SetWidth(const Value: Integer); 
    procedure CheckImage(Image: TGraphic);
    procedure CopyImages(Value: TCustomImageList);
    function GetImageHandle(AImage: TBitmap): QPixmapH;
    function GetMaskHandle(AImage: TBitmap): QBitmapH;
    function Equal(IL: TCustomImageList): Boolean;
    procedure DefaultMask(AImage: QPixmapH);
    function AddImage(AImage: QPixmapH; AMask: QBitmapH): Integer; 
    procedure ReplaceImage(Index: Integer; AImage: QPixmapH; AMask: QBitmapH);
    procedure InsertImage(Index: Integer; AImage: QPixmapH; AMask: QBitmapH); 
    procedure DoDelete(Index: Integer);
    procedure DoDraw(Index: Integer; Canvas: TCanvas; X, Y: Integer;
      AImage: TImageType; Enabled: Boolean); virtual; 
    procedure HandleMultipleImages(AImage: QPixmapH; AIndex: Integer);
    function GetCount: Integer;
    procedure FillImageList(FullImage, FullMask: TBitmap;
      CX, CY, MaskOffset, Count: Integer);
    procedure ReadD2Stream(Stream: TStream);
    procedure ReadD3Stream(Stream: TStream);
    procedure ReadClxStream(Stream: TStream);
  protected
    procedure Change; dynamic;
    procedure DefineProperties(Filer: TFiler); override;
    procedure Initialize(const AWidth, AHeight: Integer); virtual;
    property Masked: Boolean read FMasked write FMasked default True;
    property OnChange: TNotifyEvent read FOnChange write FOnChange;
  public
    constructor Create(AOwner: TComponent); override;
    constructor CreateSize(AWidth, AHeight: Integer);
    destructor Destroy; override;
    procedure Assign(Source: TPersistent); override;
    function Add(AImage, AMask: TBitmap): Integer;
    procedure AddImages(Value: TCustomImageList);
    function AddMasked(AImage: TBitmap; MaskColor: TColor): Integer;
    procedure Clear;
    procedure Delete(Index: Integer);
    procedure Draw(Canvas: TCanvas; X, Y, Index: Integer;
      AImageType: TImageType = itImage; Enabled: Boolean = True);
    procedure GetBitmap(Index: Integer; Image: TBitmap);
    function GetPixmap(Index: Integer): QPixmapH;
    function GetMask(Index: Integer): QBitmapH;
    procedure Insert(Index: Integer; Image, Mask: TBitmap);
    procedure InsertMasked(Index: Integer; Image: TBitmap; MaskColor: TColor);
    procedure Move(CurIndex, NewIndex: Integer); virtual;
    procedure ReadData(Stream: TStream); virtual;
    procedure RegisterChanges(Value: TChangeLink);
    procedure Replace(Index: Integer; AImage, AMask: TBitmap);
    procedure ReplaceMasked(Index: Integer; NewImage: TBitmap; MaskColor: TColor);
    procedure UnRegisterChanges(Value: TChangeLink);
    procedure WriteData(Stream: TStream); virtual;
    property BkColor: TColor read FBkColor write FBkColor default clNone;
    property Count: Integer read GetCount;
    property Height: Integer read FHeight write SetHeight default 16;
    property Width: Integer read FWidth write SetWidth default 16;
  end;

  TImageList = class(TCustomImageList)
  published
    property BkColor;
    property Height;
    property Masked;
    property Width;
    property OnChange;
  end;

implementation

uses
  SysUtils, QConsts;

function Min(A, B: Integer): Integer;
begin
  if A < B then
    Result := A
  else
    Result := B;
end;

{ TCustomImageList }

procedure TCustomImageList.AddImages(Value: TCustomImageList);
begin
  if Assigned(Value) then
    CopyImages(Value);
end;

function TCustomImageList.AddMasked(AImage: TBitmap; MaskColor: TColor): Integer;
var
  Image: TBitmap;
begin
  CheckImage(AImage);
  Image := TBitmap.Create;
  try
    FMaskColor := MaskColor;
    try
      if Masked and (FMaskColor <> clNone) then
        with Image do
        begin
          Assign(AImage);
          Mask(FMaskColor);
          Result := Add(AImage, Image);
        end
      else
        Result := Add(AImage, nil);
    finally
      FMaskColor := clNone;
    end;
  finally
    Image.Free;
  end;
end;

procedure TCustomImageList.Assign(Source: TPersistent);
var
  ImageList: TCustomImageList;
begin
  if Source is TCustomImageList then
  begin
    if not Equal(TCustomImageList(Source)) then
    begin
      Clear;
      ImageList := TCustomImageList(Source);
      Masked := ImageList.Masked;
      Width := ImageList.Width;
      Height := ImageList.Height;
      BkColor := ImageList.BkColor;
      AddImages(ImageList);
    end;
  end
  else
    inherited Assign(Source);
end;

procedure TCustomImageList.Clear;
begin
  Delete(-1);
end;

constructor TCustomImageList.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  Initialize(16, 16);
end;

constructor TCustomImageList.CreateSize(AWidth, AHeight: Integer);
begin
  inherited Create(nil);
  Initialize(AWidth, AHeight);
end;

destructor TCustomImageList.Destroy;
begin
  while FClients.Count > 0 do
    UnRegisterChanges(TChangeLink(FClients.Last));
  FClients.Free;
  FClients := nil;
  if Assigned(FTempMask) then
    QBitmap_destroy(FTempMask);
  inherited Destroy;
end;

procedure TCustomImageList.Delete(Index: Integer);
begin
  DoDelete(Index);
end;

procedure TCustomImageList.Draw(Canvas: TCanvas; X, Y, Index: Integer;
  AImageType: TImageType; Enabled: Boolean);
begin
  DoDraw(Index, Canvas, X, Y, AImageType, Enabled);
end;

procedure TCustomImageList.Insert(Index: Integer; Image, Mask: TBitmap);
begin
  CheckImage(Image);
  CheckImage(Mask);
  InsertImage(Index, GetImageHandle(Image), GetMaskHandle(Mask));
end;

procedure TCustomImageList.InsertMasked(Index: Integer; Image: TBitmap;
  MaskColor: TColor);
var
  Mask: TBitmap;
begin
  CheckImage(Image);
  Mask := TBitmap.Create;
  try
    try
      FMaskColor := MaskColor;
      if Masked and (FMaskColor <> clNone) then
      begin
        Mask.Assign(Image);
        Mask.Mask(FMaskColor);
        InsertImage(Index, GetImageHandle(Image), GetMaskHandle(Mask));
      end
      else
        InsertImage(Index, GetImageHandle(Image), nil);
    finally
      FMaskColor := clNone;
    end;
  finally
    Mask.Free;
  end;
end;

procedure TCustomImageList.Move(CurIndex, NewIndex: Integer);
begin
  FPixmapList.Move(CurIndex, NewIndex);
  Change;
end;

procedure TCustomImageList.RegisterChanges(Value: TChangeLink);
begin
  if not Assigned(Value) then
    Exit;
  Value.Sender := Self;
  if Assigned(FClients) then
    FClients.Add(Value);
end;

procedure TCustomImageList.Replace(Index: Integer; AImage, AMask: TBitmap);
begin
  CheckImage(AImage);
  CheckImage(AMask);
  ReplaceImage(Index, GetImageHandle(AImage), GetMaskHandle(AMask));
end;

procedure TCustomImageList.ReplaceMasked(Index: Integer; NewImage: TBitmap;
  MaskColor: TColor);
var
  Image: TBitmap;
begin
  CheckImage(NewImage);
  Image := TBitmap.Create;
  try
    FMaskColor := MaskColor;
    try
      if Masked and (FMaskColor <> clNone) and Assigned(NewImage) then
      begin
        Image.Assign(NewImage);
        Image.Mask(FMaskColor);
      end;
      ReplaceImage(Index, GetImageHandle(NewImage), GetMaskHandle(NewImage));
    finally
      FMaskColor := clNone;
    end;
  finally
    Image.Free;
  end;
end;

procedure TCustomImageList.UnRegisterChanges(Value: TChangeLink);
var
  I: Integer;
begin
  if Assigned(FClients) then
    for I := 0 to FClients.Count - 1 do
      if FClients[I] = Value then
      begin
        Value.Sender := nil;
        FClients.Delete(I);
        Break;
      end;
end;

procedure TCustomImageList.Change;
var
  I: Integer;
begin
  FChanged := True;
  if FUpdateCount > 0 then
    Exit;
  if Assigned(FClients) then
    for I := 0 to FClients.Count - 1 do
      TChangeLink(FClients[I]).Change;
  if Assigned(FOnChange) then
    FOnChange(Self);
end;

procedure TCustomImageList.CheckImage(Image: TGraphic);
begin
  if Image = nil then Exit;
  with Image do
    if (Height < FHeight) or (Width < FWidth) then
      raise EInvalidOperation.Create(SInvalidImageSize);
end;

procedure TCustomImageList.CopyImages(Value: TCustomImageList);
var
  I: Integer;
begin
  if Assigned(Value) and (Value.Count > 0) then
  begin
    if (FWidth <> Value.FWidth) or (FHeight <> Value.FHeight) then
      raise EInvalidOperation.CreateRes(@SInvalidImageDimensions);
    BeginUpdate;
    try
      for I := 0 to Value.Count-1 do
        AddImage(Value.GetPixmap(I), Value.GetMask(I));
    finally
      EndUpdate;
    end;
  end;
end;

procedure TCustomImageList.Initialize(const AWidth, AHeight: Integer);
begin
  FClients := TList.Create;
  FWidth := AWidth;
  FHeight := AHeight;
  BkColor := clNone;
  FMasked := True;
  FMaskColor := clNone;
  if (Height < 1) or (Width < 1) then
    raise EInvalidOperation.Create(SInvalidImageSize);
  if not Assigned(FPixmapList) then
    FPixmapList := TList.Create;
end;

function TCustomImageList.GetImageHandle(AImage: TBitmap): QPixmapH;
begin
  Result := nil;
  if Assigned(AImage) then
    Result := AImage.Handle;
end;

function TCustomImageList.Add(AImage, AMask: TBitmap): Integer;
begin
  CheckImage(AImage);
  CheckImage(AMask);
  Result := AddImage(GetImageHandle(AImage), GetMaskHandle(AMask));
end;

function TCustomImageList.Equal(IL: TCustomImageList): Boolean;

  function StreamsEqual(S1, S2: TMemoryStream): Boolean;
  begin
    Result := (S1.Size = S2.Size) and CompareMem(S1.Memory, S2.Memory, S1.Size);
  end;

var
  MyImage, OtherImage: TMemoryStream;
begin
  if not Assigned(IL) or (Count <> IL.Count) then
  begin
    Result := False;
    Exit;
  end;
  if (Count = 0) and (IL.Count = 0) then
  begin
    Result := True;
    Exit;
  end;
  MyImage := TMemoryStream.Create;
  try
    WriteData(MyImage);
    OtherImage := TMemoryStream.Create;
    try
      IL.WriteData(OtherImage);
      Result := StreamsEqual(MyImage, OtherImage);
    finally
      OtherImage.Free;
    end;
  finally
    MyImage.Free;
  end;
end;

procedure TCustomImageList.DefaultMask(AImage: QPixmapH);
var
  Bitmap: TBitmap;
begin
  if Assigned(QPixmap_mask(AImage)) or (QPixmap_depth(AImage) = 1) then
    Exit;
  Bitmap := TBitmap.Create;
  try
    Bitmap.Handle := AImage;
    Bitmap.Transparent := True;
    Bitmap.ReleasePixmap;
  finally
    Bitmap.Free;
  end;
end;

procedure TCustomImageList.BeginUpdate;
begin
  Inc(FUpdateCount);
end;

procedure TCustomImageList.EndUpdate;
begin
  if FUpdateCount > 0 then
    Dec(FUpdateCount);
  if FChanged then
  begin
    FChanged := False;
    Change;
  end;
end;

function TCustomImageList.GetMaskHandle(AImage: TBitmap): QBitmapH;
var
  Bitmap: TBitmap;
begin
  Result := nil;
  if Assigned(AImage) then
    if QPixmap_isQBitmap(AImage.Handle) then
      Result := QBitmapH(AImage.Handle)
    else
    begin
      Result := QPixmap_mask(AImage.Handle);
      if AImage.PixelFormat <> pf1bit then
        if Result = nil then
        begin
          if Assigned(FTempMask) then
            QBitmap_destroy(FTempMask);
          Bitmap := TBitmap.Create;
          try
            Bitmap.Assign(AImage);
            Bitmap.Mask(FMaskColor);
            FTempMask := QBitmap_create(QPixmap_mask(Bitmap.Handle));
            Result := FTempMask;
          finally
            Bitmap.Free;
          end;
        end;
    end;
end;

procedure TCustomImageList.GetBitmap(Index: Integer; Image: TBitmap);
begin
  if Assigned(Image) then
    with Image do
    begin
      Height := FHeight;
      Width := FWidth;
      Draw(Canvas, 0, 0, Index);
    end;
end;

function TCustomImageList.GetMask(Index: Integer): QBitmapH;
begin
  if (Index > -1) and (Index < Count) then
    Result := QPixmap_mask(QPixmapH(FPixmapList[Index]))
  else
    Result := nil;
end;

function TCustomImageList.GetPixmap(Index: Integer): QPixmapH;
begin
  if (Index > -1) and (Index < Count) then
    Result := QPixmapH(FPixmapList[Index])
  else
    Result := nil;
end;

procedure TCustomImageList.DefineProperties(Filer: TFiler);

  function DoWrite: Boolean;
  begin
    if Filer.Ancestor <> nil then
      Result := not (Filer.Ancestor is TCustomImageList) or
        not Equal(TCustomImageList(Filer.Ancestor))
    else
      Result := Count > 0;
  end;

begin
  inherited DefineProperties(Filer);
  Filer.DefineBinaryProperty('Bitmap', ReadData, WriteData, DoWrite);
end;

{ TChangeLink }

procedure TChangeLink.Change;
begin
  if Assigned(OnChange) then
    OnChange(Sender);
end;

destructor TChangeLink.Destroy;
begin
  if Assigned(Sender) then
    Sender.UnRegisterChanges(Self);
  inherited Destroy;
end;

function TCustomImageList.AddImage(AImage: QPixmapH; AMask: QBitmapH): Integer;
var
  Pixmap: QPixmapH;
begin
  if not Assigned(AImage) then
  begin
    Pixmap := QPixmap_create;
    QPixmap_resize(Pixmap, Width, Height);
  end
  else
    Pixmap := QPixmap_create(AImage);
  Result := FPixmapList.Add(Pixmap);
  HandleMultipleImages(Pixmap, Count);
  if Masked then
  begin
    if Assigned(AMask) then
      QPixmap_setMask(Pixmap, AMask)
    else
      DefaultMask(Pixmap);
  end;
  QPixmap_resize(Pixmap, Min(FWidth, QPixmap_width(Pixmap)),
    Min(FHeight, QPixmap_height(Pixmap)));
  Change;
end;

procedure TCustomImageList.DoDelete(Index: Integer);
begin
  if Index = -1 then 
  begin
    while FPixmapList.Count > 0 do
      QPixmap_destroy(QPixmapH(FPixmapList.Extract(FPixmapList[0])));
  end
  else
  begin
    if Index >= Count then
      raise EInvalidOperation.Create(SImageIndexError);
    QPixmap_destroy(QPixmapH(FPixmapList.Extract(FPixmapList[Index])));
  end;

  if not (csDestroying in ComponentState) then
    Change;
end;

type
  TCanvasAccessor = class(TCanvas);

procedure TCustomImageList.DoDraw(Index: Integer; Canvas: TCanvas; X, Y: Integer;
  AImage: TImageType; Enabled: Boolean);
var
  PixH: QPixmapH;
  DisabledPixH: QPixmapH;
  IconSet: QIconSetH;
begin
  if (Index <= -1) or (Index >= Count) then
    Exit;
  TCanvasAccessor(Canvas).Changing;
  Canvas.Start;
  try
    if BkColor <> clNone then
    begin
      Canvas.Brush.Color := BkColor;
      Canvas.FillRect(Rect(X, Y, X + Width, Y + Height));
    end;
    
    if AImage = itImage then
      PixH := QPixmapH(FPixmapList[Index])
    else
      PixH := QPixmap_mask(QPixmapH(FPixmapList[Index]));

    TCanvasAccessor(Canvas).RequiredState([csHandleValid, csPenValid]);
    if Enabled then
    begin
      if Assigned(PixH) then
        QPainter_drawPixmap(Canvas.Handle, X, Y, PixH, 0, 0, Width, Height);
    end
    else
    begin
      IconSet := QIconSet_create(PixH, QIconSetSize_Small);
      try
        DisabledPixH := QPixmap_create;
        try
          QIconSet_pixmap(IconSet, DisabledPixH, QIconSetSize_Small, False);
          QPainter_drawPixmap(Canvas.Handle, X, Y, DisabledPixH, 0, 0,
            Width, Height);
        finally
          QPixmap_destroy(DisabledPixH);
        end;
      finally
        QIconSet_destroy(IconSet);
      end;
    end;
  finally
    Canvas.Stop;
  end;
  TCanvasAccessor(Canvas).Changed;
end;

function TCustomImageList.GetCount: Integer;
begin
  Result := FPixmapList.Count;
end;

procedure TCustomImageList.HandleMultipleImages(AImage: QPixmapH; AIndex: Integer);
var
  I: Integer;
  J: Integer;
  Bitmap: TBitmap;
  WidthLoop: Integer;
  HeightLoop: Integer;
  Pixmap: QPixmapH;
begin
  if (QPixmap_width(AImage) > FWidth) or (QPixmap_height(AImage) > FHeight) then
  begin
    BeginUpdate;
    try
      Bitmap := TBitmap.Create;
      Bitmap.Width := FWidth;
      Bitmap.Height := FHeight;
      try
        WidthLoop := (QPixmap_width(AImage) div FWidth) - 1;
        for J := 1 to WidthLoop do
        begin
          Bitmap.Canvas.Start;
          TCanvasAccessor(Bitmap.Canvas).RequiredState([csHandleValid, csPenValid]);
          try
            QPainter_drawPixmap(Bitmap.Canvas.Handle, 0, 0, AImage,
              J * FWidth, 0, FWidth, FHeight);
          finally
            Bitmap.Canvas.Stop;
          end;
          if Masked and (FMaskColor <> clNone) then
            DefaultMask(Bitmap.Handle);
          Pixmap := QPixmap_create(Bitmap.Handle);
          QPixmap_resize(Pixmap, Min(FWidth, QPixmap_width(Pixmap)),
            Min(FHeight, QPixmap_height(Pixmap)));
          FPixmapList.Insert(AIndex, Pixmap);
          Inc(AIndex);
        end;
        HeightLoop := (QPixmap_height(AImage) div FHeight) - 1;
        for I := 1 to HeightLoop do
          for J := 0 to WidthLoop do
          begin
            Bitmap.Canvas.Start;
            TCanvasAccessor(Bitmap.Canvas).RequiredState([csHandleValid, csPenValid]);
            try
              QPainter_drawPixmap(Bitmap.Canvas.Handle, 0, 0, AImage,
                J * FWidth, I * FHeight, FWidth, FHeight);
            finally
              Bitmap.Canvas.Stop;
            end;
            if Masked and (FMaskColor <> clNone) then
              DefaultMask(Bitmap.Handle);
            Pixmap := QPixmap_create(Bitmap.Handle);
            QPixmap_resize(Pixmap, Min(FWidth, QPixmap_width(Pixmap)),
              Min(FHeight, QPixmap_height(Pixmap)));
            FPixmapList.Insert(AIndex, Pixmap);
            Inc(AIndex);
          end;
      finally
        Bitmap.Free;
      end;
    finally
      EndUpdate;
    end;
  end;
end;

procedure TCustomImageList.InsertImage(Index: Integer; AImage: QPixmapH;
  AMask: QBitmapH);
var
  Pixmap: QPixmapH;
begin
  if not Assigned(AImage) then
  begin
    Pixmap := QPixmap_create;
    QPixmap_resize(Pixmap, Width, Height);
  end
  else
    Pixmap := QPixmap_create(AImage);
  FPixmapList.Insert(Index, Pixmap);
  Inc(Index);
  HandleMultipleImages(Pixmap, Index);
  if Masked and (FMaskColor <> clNone) then
    if Assigned(AMask) then
      QPixmap_setMask(Pixmap, AMask)
    else
      DefaultMask(Pixmap);
  QPixmap_resize(Pixmap, Min(FWidth, QPixmap_width(Pixmap)),
    Min(FHeight, QPixmap_height(Pixmap)));
  Change;
end;

procedure TCustomImageList.ReplaceImage(Index: Integer; AImage: QPixmapH;
  AMask: QBitmapH);
var
  Pixmap: QPixmapH;
begin
  if (Index >= 0) and (Index < Count) then
  begin
    QPixmap_destroy(QPixmapH(FPixmapList[Index]));
    Pixmap := QPixmap_create(AImage);
    FPixmapList[Index] := Pixmap;
    if Masked and (FMaskColor <> clNone) then
      if Assigned(AMask) then
        QPixmap_setMask(Pixmap, QBitmap_create(AMask))
      else
        DefaultMask(Pixmap);
    QPixmap_resize(Pixmap, Min(FWidth, QPixmap_width(Pixmap)),
      Min(FHeight, QPixmap_height(Pixmap)));
    Change;
  end;
end;

procedure TCustomImageList.SetHeight(const Value: Integer);
begin
  if FHeight <> Value then
  begin
    if (Value <= 0) then
      raise EInvalidOperation.CreateRes(@SInvalidImageDimension);
    FHeight := Value;
    Clear;
    Change;
  end;
end;

procedure TCustomImageList.SetWidth(const Value: Integer);
begin
  if FWidth <> Value then
  begin
    if (Value <= 0) then
      raise EInvalidOperation.CreateRes(@SInvalidImageDimension);
    FWidth := Value;
    Clear;
    Change;
  end;
end;

const
  ILMagic = Word(Ord('L') shl 8 + Ord('I'));
  ILVersion = Word($0101);
  ILC_MASK = $0001;
  Magic = Integer(Ord('L') shl 24 + Ord('G') shl 16 + Ord('M') shl 8 + Ord('I'));
  OldVersion = $00010000;
  Version = $00010001;

type
  TILHeader = packed record
    usMagic: Word;
    usVersion: Word;
    cCurImage: Word;
    cMaxImage: Word;
    cGrow: Word;
    cx: Word;
    cy: Word;
    bkcolor: Longint;
    flags: Word;
    ovls: array[0..3] of Smallint;
  end;

  TOldBMPHeader = packed record
    Width: Integer;
    Height: Integer;
    Count: Integer;
  end;

  TBMPHeader = packed record
    Magic: Integer;
    Version: Integer;
    Width: Integer;
    Height: Integer;
    Count: Integer;
  end;

procedure TCustomImageList.FillImageList(FullImage, FullMask: TBitmap; CX, CY,
  MaskOffset, Count: Integer);
var
  AImage: TBitmap;
  AMask: TBitmap;
  I, J: Integer;
begin
  AImage := TBitmap.Create;
  try
    if FullMask <> nil then
      AMask := TBitmap.Create
    else
      AMask := nil;
    try
      AImage.Width := FullImage.Width div CX;
      AImage.Height := FullImage.Height div CY;
      try
        if Assigned(AMask) then
        begin
          AMask.Width := FullMask.Width div CX;
          AMask.Height := FullMask.Height div CY;
        end;
        Masked := AMask <> nil;
        BeginUpdate;
        for J := 0 to CY - 1 do
        begin
          if Count = 0 then
            Break;
          for I := 0 to CX - 1 do
          begin
            if Count = 0 then
              Break;
            AImage.Canvas.Start;
            try
              TCanvasAccessor(AImage.Canvas).RequiredState([csHandleValid, csPenValid]);
              QPainter_drawPixmap(AImage.Canvas.Handle, 0, 0, FullImage.Handle,
                I * Width, J * Height, Width, Height);
            finally
              AImage.Canvas.Stop;
            end;
            if Assigned(FullMask) and Assigned(AMask) then
            begin
              AMask.Canvas.Start;
              try
                TCanvasAccessor(AMask.Canvas).RequiredState([csHandleValid,
                  csPenValid]);
                QPainter_drawPixmap(AMask.Canvas.Handle, 0, 0, FullMask.Handle,
                  I * Width, J * Height + MaskOffset, Width, Height);
                AMask.PixelFormat := pf1bit;
              finally
                AMask.Canvas.Stop;
              end;
            end;
            Add(AImage, AMask);
            Dec(Count);
          end;
        end;
      finally
        EndUpdate;
      end;
    finally
      AMask.Free;
    end;
  finally
    AImage.Free;
  end;
end;

procedure TCustomImageList.ReadD2Stream(Stream: TStream);
var
  FullImage, FullMask: TBitmap;
  Size, Count: Integer;
  Pos: Int64;
begin
  Stream.ReadBuffer(Size, SizeOf(Size));
  Stream.ReadBuffer(Count, SizeOf(Count));
  FullImage := TBitmap.Create;
  try
    Pos := Stream.Position;
    FullImage.LoadFromStream(Stream);
    Stream.Position := Pos + Size;
    FullMask := TBitmap.Create;
    try
      FullMask.LoadFromStream(Stream);
      FillImageList(FullImage, FullMask, FullImage.Width div Width,
        FullImage.Height div Height, 0, Count);
    finally
      FullMask.Free;
    end;
  finally
    FullImage.Free;
  end;
end;

procedure TCustomImageList.ReadD3Stream(Stream: TStream);
var
  ILHeader: TILHeader;
  Colors, Mask: TBitmap;
begin
  Stream.Read(ILHeader, SizeOf(TILHeader));
  if (ILHeader.usMagic <> ILMagic) or (ILHeader.usVersion <> ILVersion) then
    Exit;
  Mask := nil;
  Colors := TBitmap.Create;
  try
    Colors.LoadFromStream(Stream);
    if ILHeader.flags and ILC_MASK <> 0 then
    begin
      Mask := TBitmap.Create;
      Mask.LoadFromStream(Stream);
    end;
    FillImageList(Colors, Mask, Colors.Width div ILHeader.cx,
      Colors.Height div ILHeader.cy, 0, ILHeader.cCurImage);
  finally
    Colors.Free;
    Mask.Free;
  end;
end;

procedure TCustomImageList.ReadClxStream(Stream: TStream);
var
  StreamPos: Int64;

  procedure ReadOldImages(AWidth, AHeight, Count: Integer);
  var
    Bitmap: TBitmap;
  begin
    Bitmap := TBitmap.Create;
    try
      Width := AWidth;
      Height := AHeight;
      Masked := True;
      Bitmap.LoadFromStream(Stream);
      FillImageList(Bitmap, Bitmap, Bitmap.Width div Width,
        Bitmap.Height div Height, Height, Count);
    finally
      Bitmap.Free;
    end;
  end;

  procedure ReadImages(AWidth, AHeight, Count: Integer);
  var
    Colors, Mask: TBitmap;
  begin
    Colors := TBitmap.Create;
    try
      Width := AWidth;
      Height := AHeight;
      Masked := True;
      Colors.LoadFromStream(Stream);
      Mask := TBitmap.Create;
      try
        Mask.LoadFromStream(Stream);
        FillImageList(Colors, Mask, Colors.Width div Width,
          Colors.Height div Height, 0, Count);
      finally
        Mask.Free;
      end;
    finally
      Colors.Free;
    end;
  end;

  function TryClxStream: Boolean;
  var
    Header: TBMPHeader;
  begin
    Result := False;
    Stream.Position := StreamPos;
    Stream.Read(Header, SizeOf(Header));
    if Header.Magic <> Magic then Exit;
    if Header.Version = OldVersion then
      ReadOldImages(Header.Width, Header.Height, Header.Count)
    else if Header.Version = Version then
      ReadImages(Header.Width, Header.Height, Header.Count)
    else Exit;
    Result := True;
  end;

  procedure ReadFtStream;
  var
    Header: TOldBMPHeader;
  begin
    Stream.Position := StreamPos;
    Stream.Read(Header, SizeOf(Header));
    ReadOldImages(Header.Width, Header.Height, Header.Count);
  end;

begin
  StreamPos := Stream.Position;
  if not TryClxStream then
    ReadFtStream;
end;

procedure TCustomImageList.ReadData(Stream: TStream);
var
  CheckInt1, CheckInt2, CheckInt3: Integer;
  CheckByte1, CheckByte2, CheckByte3, CheckByte4: Byte;
  StreamPos: Int64;
begin
  if Stream.Size = 0 then
    Exit;
  StreamPos := Stream.Position;                  // check stream signature to
  Stream.Read(CheckInt1, SizeOf(CheckInt1));     // determine a Delphi 2 or Delphi
  Stream.Read(CheckInt2, SizeOf(CheckInt2));     // 3 imagelist stream.  Delphi 2
  CheckByte1 := CheckInt1 and $000000ff;         // streams can be read, but only
  CheckByte2 := (CheckInt1 and $0000ff00) shr 8; // Delphi 3 streams will be written
  Stream.Read(CheckInt3, SizeOf(CheckInt3));
  CheckByte3 := CheckInt3 and $000000ff;
  CheckByte4 := (CheckInt3 and $0000ff00) shr 8;
  Stream.Position := StreamPos;
  if (CheckInt1 <> CheckInt2) and (CheckByte1 = $49) and (CheckByte2 = $4C) then
    ReadD3Stream(Stream)
  else if (CheckByte3 = $42) and (CheckByte4 = $4D) then
    ReadD2Stream(Stream)
  else ReadClxStream(Stream);
end;

procedure TCustomImageList.WriteData(Stream: TStream);
var
  Colors, Mask: TBitmap;
  Header: TBMPHeader;
  I, J, C: Integer;
  BWidth, BHeight: Integer;

  procedure CalcDimensions(var AWidth, AHeight: Integer);
  var
    X: Double;
  begin
    X := Sqrt(Count);
    AWidth := Trunc(X);
    if Frac(X) > 0 then
      Inc(AWidth);
    X := Count / AWidth;
    AHeight := Trunc(X);
    if Frac(X) > 0 then
      Inc(AHeight);
  end;

begin
  if Count = 0 then
    Exit;
  Colors := TBitmap.Create;
  try
    Mask := TBitmap.Create;
    try
      Header.Magic := Magic;
      Header.Version := Version;
      Header.Width := FWidth;
      Header.Height := FHeight;
      Header.Count := Count;
      Stream.Write(Header, SizeOf(TBMPHeader));
      CalcDimensions(BWidth, BHeight);
      Colors.Width := BWidth * FWidth;
      Colors.Height := BHeight * FHeight;
      Mask.Width := Colors.Width;
      Mask.Height := Colors.Height;
      Mask.PixelFormat := pf1Bit;
      C := 0;
      for I := 0 to BHeight - 1 do
      begin
        if C >= Count then Break;
        for J := 0 to  BWidth - 1 do
        begin
          if C >= Count then Break;
          Draw(Colors.Canvas, J * FWidth, I * FHeight, C);
          Draw(Mask.Canvas, J * FWidth, I * FHeight, C, itMask);
          Inc(C);
        end;
      end;
      Colors.SaveToStream(Stream);
      Mask.SaveToStream(Stream);
    finally
      Mask.Free;
    end;
  finally
    Colors.Free;
  end;
end;

end.

