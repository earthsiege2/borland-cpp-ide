
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{  Copyright (c) 1995,2001 Borland Software Corporation }
{                                                       }
{*******************************************************}

unit GraphUtil;

interface

uses Windows, Graphics;

type
  TScrollDirection = (sdLeft, sdRight, sdUp, sdDown);
  TArrowType = (atSolid, atArrows);

{ GetHighLightColor and GetShadowColor take a Color and calculate an
  "appropriate" highlight/shadow color for that value.  If the color's
  saturation is beyond 220 then it's lumination is decreased rather than
  increased.  Since these routines may be called repeatedly for (potentially)
  the same color value they cache the results of the previous call. }

function GetHighLightColor(const Color: TColor): TColor;
function GetShadowColor(const Color: TColor): TColor;

{ Draws checkmarks of any Size at Location with/out a shadow. }

procedure DrawCheck(ACanvas: TCanvas; Location: TPoint; Size: Integer;
  Shadow: Boolean = True);

{ Draws arrows that look like ">" which can point in any TScrollDirection }

procedure DrawChevron(ACanvas: TCanvas; Direction: TScrollDirection;
  Location: TPoint; Size: Integer);

{ Draws a solid triangular arrow that can point in any TScrollDirection }

procedure DrawArrow(ACanvas: TCanvas; Direction: TScrollDirection;
  Location: TPoint; Size: Integer);

{ The following routines mimic the like named routines from Shlwapi.dll except
  these routines do not rely on any specific version of IE being installed. }

{ Calculates Hue, Luminance and Saturation for the clrRGB value }

procedure ColorRGBToHLS(clrRGB: COLORREF; var Hue, Luminance, Saturation: Word);

{ Calculates a color given Hue, Luminance and Saturation values }

function ColorHLSToRGB(Hue, Luminance, Saturation: Word): TColorRef;

{ Given a color and a luminance change "n" this routine returns a color whose
  luminace has been changed accordingly. }
  
function ColorAdjustLuma(clrRGB: TColorRef; n: Integer; fScale: BOOL): TColorRef;

implementation

uses Classes, Math;

const
  ArrowPts: array[TScrollDirection, 0..2] of TPoint =
    (((X:1; Y:0), (X:0; Y:1), (X:1; Y:2)),
     ((X:0; Y:0), (X:1; Y:1), (X:0; Y:2)),
     ((X:0; Y:1), (X:1; Y:0), (X:2; Y:1)),
     ((X:0; Y:0), (X:1; Y:1), (X:2; Y:0)));

{-----------------------------------------------------------------------
References:

1) J. Foley and a.van Dam, "Fundamentals of Interactive Computer Graphics",
   Addison-Wesley (IBM Systems Programming Series), Reading, MA, 664 pp., 1982.
2) MSDN online HOWTO: Converting Colors Between RGB and HLS (HBS)
   http://support.microsoft.com/support/kb/articles/Q29/2/40.ASP

  SUMMARY
  The code fragment below converts colors between RGB (Red, Green, Blue) and
  HLS/HBS (Hue, Lightness, Saturation/Hue, Brightness, Saturation).


  http://lists.w3.org/Archives/Public/www-style/1997Dec/0182.html
  http://www.math.clemson.edu/~rsimms/neat/math/hlsrgb.pas

-----------------------------------------------------------------------}

const
  HLSMAX = 240;            // H,L, and S vary over 0-HLSMAX
  RGBMAX = 255;            // R,G, and B vary over 0-RGBMAX
                           // HLSMAX BEST IF DIVISIBLE BY 6
                           // RGBMAX, HLSMAX must each fit in a byte.

  { Hue is undefined if Saturation is 0 (grey-scale)
    This value determines where the Hue scrollbar is
    initially set for achromatic colors }
  HLSUndefined = (HLSMAX*2/3);

procedure ColorRGBToHLS(clrRGB: COLORREF; var Hue, Luminance, Saturation: Word);
var
  H, L, S: Double;
  R, G, B: Word;
  cMax, cMin: Double;
  Rdelta, Gdelta, Bdelta: Extended; { intermediate value: % of spread from max }
begin
  R := GetRValue(clrRGB);
  G := GetGValue(clrRGB);
  B := GetBValue(clrRGB);

  { calculate lightness }
  cMax := Math.Max(Math.Max(R, G), B);
  cMin := Math.Min(Math.Min(R, G), B);
  L := ( ((cMax + cMin) * HLSMAX{239}) + RGBMAX ) / ( 2 * RGBMAX);
  if cMax = cMin then  { r=g=b --> achromatic case }
  begin                { saturation }
    Hue := Round(HLSUndefined);
//    pwHue := 160;      { MS's ColorRGBToHLS always defaults to 160 in this case }
    Luminance := Round(L);
    Saturation := 0;
  end
  else                 { chromatic case }
  begin
    { saturation }
    if L <= HLSMAX/2 then
      S := ( ((cMax-cMin)*HLSMAX) + ((cMax+cMin)/2) ) / (cMax+cMin)
    else
      S := ( ((cMax-cMin)*HLSMAX) + ((2*RGBMAX-cMax-cMin)/2) ) / (2*RGBMAX-cMax-cMin);

    { hue }
    Rdelta := ( ((cMax-R)*(HLSMAX/6)) + ((cMax-cMin)/2) ) / (cMax-cMin);
    Gdelta := ( ((cMax-G)*(HLSMAX/6)) + ((cMax-cMin)/2) ) / (cMax-cMin);
    Bdelta := ( ((cMax-B)*(HLSMAX/6)) + ((cMax-cMin)/2) ) / (cMax-cMin);

    if (R = cMax) then
      H := Bdelta - Gdelta
    else if (G = cMax) then
      H := (HLSMAX/3) + Rdelta - Bdelta
    else // B == cMax
      H := ((2 * HLSMAX) / 3) + Gdelta - Rdelta;

    if (H < 0) then
      H := H + HLSMAX;
    if (H > HLSMAX) then
      H := H - HLSMAX;
    Hue := Round(H);
    Luminance := Round(L);
    Saturation := Round(S);
  end;
end;

function HueToRGB(Lum, Sat, Hue: Double): Integer;
var
  ResultEx: Double;
begin
  { range check: note values passed add/subtract thirds of range }
  if (hue < 0) then
     hue := hue + HLSMAX;

  if (hue > HLSMAX) then
     hue := hue - HLSMAX;

  { return r,g, or b value from this tridrant }
  if (hue < (HLSMAX/6)) then
    ResultEx := Lum + (((Sat-Lum)*hue+(HLSMAX/12))/(HLSMAX/6))
  else if (hue < (HLSMAX/2)) then
    ResultEx := Sat
  else if (hue < ((HLSMAX*2)/3)) then
    ResultEx := Lum + (((Sat-Lum)*(((HLSMAX*2)/3)-hue)+(HLSMAX/12))/(HLSMAX/6))
  else
    ResultEx := Lum;
  Result := Round(ResultEx);
end;

function ColorHLSToRGB(Hue, Luminance, Saturation: Word): TColorRef;

  function RoundColor(Value: Double): Integer;
  begin
    if Value > 255 then
      Result := 255
    else
      Result := Round(Value);
  end;

var
  R,G,B: Double;               { RGB component values }
  Magic1,Magic2: Double;       { calculated magic numbers (really!) }
begin
  if (Saturation = 0) then
  begin            { achromatic case }
     R := (Luminance * RGBMAX)/HLSMAX;
     G := R;
     B := R;
     if (Hue <> HLSUndefined) then
       ;{ ERROR }
  end
  else
  begin            { chromatic case }
     { set up magic numbers }
     if (Luminance <= (HLSMAX/2)) then
        Magic2 := (Luminance * (HLSMAX + Saturation) + (HLSMAX/2)) / HLSMAX
     else
        Magic2 := Luminance + Saturation - ((Luminance * Saturation) + (HLSMAX/2)) / HLSMAX;
     Magic1 := 2 * Luminance - Magic2;

     { get RGB, change units from HLSMAX to RGBMAX }
     R := (HueToRGB(Magic1,Magic2,Hue+(HLSMAX/3))*RGBMAX + (HLSMAX/2))/HLSMAX;
     G := (HueToRGB(Magic1,Magic2,Hue)*RGBMAX + (HLSMAX/2)) / HLSMAX;
     B := (HueToRGB(Magic1,Magic2,Hue-HLSMAX/3)*RGBMAX + (HLSMAX/2))/HLSMAX;
  end;
  Result := RGB(RoundColor(R), RoundColor(G), RoundColor(B));
end;

function ColorAdjustLuma(clrRGB: TColorRef; n: Integer;
  fScale: BOOL): TColorRef; 
var
  H, L, S: Word;
begin
  ColorRGBToHLS(ColorToRGB(clrRGB), H, L, S);
  Result := TColor(ColorHLSToRGB(H, L + n, S));
end;

threadvar
  CurrentHighlightColor,
  CurrentHighlight: TColor;
  CurrentShadowColor,
  CurrentShadow: TColor;

function GetHighLightColor(const Color: TColor): TColor;
var
  H, L, S: Word;
  Clr: Cardinal;
begin
  if Color = CurrentHighlightColor then
    Result := CurrentHighlight
  else
  begin
    Clr := ColorToRGB(Color);
    ColorRGBToHLS(Clr, H, L, S);
    if S > 220 then
      Result := ColorHLSToRGB(H, L - 19, S)
    else
      Result := TColor(ColorAdjustLuma(Clr, 19, False));
    CurrentHighlightColor := Color;
    CurrentHighlight := Result;
  end;
end;

function GetShadowColor(const Color: TColor): TColor;
var
  H, L, S: Word;
begin
  if Color = CurrentShadowColor then
    Result := CurrentShadow
  else
  begin
    if Color = clBtnFace then
      Result := clBtnShadow
    else
    begin
      ColorRGBToHLS(ColorToRGB(ColorToRGB(Color)), H, L, S);
      if S >= 160 then
        Result := ColorHLSToRGB(H, L - 50, S)
      else
        Result := TColor(ColorAdjustLuma(ColorToRGB(ColorToRGB(Color)), -52, False));
    end;
    CurrentShadowColor := Color;
    CurrentShadow := Result;
  end;
end;

{ Utility Drawing Routines }

procedure DrawArrow(ACanvas: TCanvas; Direction: TScrollDirection;
  Location: TPoint; Size: Integer);
var
  I: Integer;
  Pts: array[0..2] of TPoint;
  OldWidth: Integer;
  OldColor: TColor;
begin
  if ACanvas = nil then exit;
  OldColor := ACanvas.Brush.Color;
  ACanvas.Brush.Color := ACanvas.Pen.Color;
  Move(ArrowPts[Direction], Pts, SizeOf(Pts));
  for I := 0 to 2 do
    Pts[I] := Point(Pts[I].x * Size + Location.X, Pts[I].y * Size + Location.Y);
  with ACanvas do
  begin
    OldWidth := Pen.Width;
    Pen.Width := 1;
    Polygon(Pts);
    Pen.Width := OldWidth;
    Brush.Color := OldColor;
  end;
end;

procedure DrawChevron(ACanvas: TCanvas; Direction: TScrollDirection;
  Location: TPoint; Size: Integer);

  procedure DrawLine;
  var
    I: Integer;
    Pts: array[0..2] of TPoint;
  begin
    Move(ArrowPts[Direction], Pts, SizeOf(Pts));
    // Scale to the correct size
    for I := 0 to 2 do
      Pts[I] := Point(Pts[I].X * Size + Location.X, Pts[I].Y * Size + Location.Y);
    case Direction of
      sdDown : Pts[2] := Point(Pts[2].X + 1, Pts[2].Y - 1);
      sdRight: Pts[2] := Point(Pts[2].X - 1, Pts[2].Y + 1);
      sdUp,
      sdLeft : Pts[2] := Point(Pts[2].X + 1, Pts[2].Y + 1);
    end;
    ACanvas.PolyLine(Pts);
  end;

var
  OldWidth: Integer;
begin
  if ACanvas = nil then exit;
  OldWidth := ACanvas.Pen.Width;
  ACanvas.Pen.Width := 1;
  case Direction of
    sdLeft, sdRight:
      begin
        Dec(Location.x, Size);
        DrawLine;
        Inc(Location.x);
        DrawLine;
        Inc(Location.x, 3);
        DrawLine;
        Inc(Location.x);
        DrawLine;
      end;
    sdUp, sdDown:
      begin
        Dec(Location.y, Size);
        DrawLine;
        Inc(Location.y);
        DrawLine;
        Inc(Location.y, 3);
        DrawLine;
        Inc(Location.y);
        DrawLine;
      end;
  end;
  ACanvas.Pen.Width := OldWidth;
end;

procedure DrawCheck(ACanvas: TCanvas; Location: TPoint; Size: Integer;
  Shadow: Boolean = True);
var
  PR: TPenRecall;
begin
  if ACanvas = nil then exit;
  PR := TPenRecall.Create(ACanvas.Pen);
  try
    ACanvas.Pen.Width := 1;
    ACanvas.PolyLine([
      Point(Location.X, Location.Y),
      Point(Location.X + Size, Location.Y + Size),
      Point(Location.X + Size * 2 + Size, Location.Y - Size),
      Point(Location.X + Size * 2 + Size, Location.Y - Size - 1),
      Point(Location.X + Size, Location.Y + Size - 1),
      Point(Location.X - 1, Location.Y - 2)]);
    if Shadow then
    begin
      ACanvas.Pen.Color := clWhite;
      ACanvas.PolyLine([
        Point(Location.X - 1, Location.Y - 1),
        Point(Location.X - 1, Location.Y),
        Point(Location.X, Location.Y + 1),
        Point(Location.X + Size, Location.Y + Size + 1),
        Point(Location.X + Size * 2 + Size + 1, Location.Y - Size),
        Point(Location.X + Size * 2 + Size + 1, Location.Y - Size - 1),
        Point(Location.X + Size * 2 + Size + 1, Location.Y - Size - 2)]);
    end;
  finally
    PR.Free;
  end;
end;

end.
