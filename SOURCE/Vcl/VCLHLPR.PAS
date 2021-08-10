{*******************************************************}
{  VCL helpers/hacks for C++Builder                     }
{                                                       }
{ $Revision:   1.0.1.0  $                                  }
{ $Date:   21 Sep 1999 12:54:52  $                      }
{*******************************************************}
unit Vclhlpr;

interface

uses
  Windows, Messages, ActiveX, SysUtils, ComObj, Classes, Graphics,
  Controls, Forms, ExtCtrls, StdVcl, Axctrls;

type

  TVarDispProc = procedure(Result: PVariant;
                           const Instance: Variant;
                           CallDesc: PCallDesc
                           // NOTE: Here there may be other parameters pushed on the stack (for arguments)
                           //       See _DispInvoke in SYSTEM.PAS for more information.
                           ); cdecl;

  TPropertyPageImplHack = class(TPropertyPageImpl, IUnknown)
    { IUnknown methods for other interfaces }
    function QueryInterface(const IID: TGUID; out Obj): HResult; stdcall;
    function _AddRef: Integer; stdcall;
    function _Release: Integer; stdcall;
  end;

// Helper routines use by C++Builder
//
procedure VariantCpy(const src: Variant; var dst: Variant);
procedure VariantAdd(const src: Variant; var dst: Variant);
procedure VariantSub(const src: Variant; var dst: Variant);
procedure VariantMul(const src: Variant; var dst: Variant);
procedure VariantDiv(const src: Variant; var dst: Variant);
procedure VariantMod(const src: Variant; var dst: Variant);
procedure VariantAnd(const src: Variant; var dst: Variant);
procedure VariantOr (const src: Variant; var dst: Variant);
procedure VariantXor(const src: Variant; var dst: Variant);
procedure VariantShl(const src: Variant; var dst: Variant);
procedure VariantShr(const src: Variant; var dst: Variant);

function  VariantCmp(const v1: Variant; const V2: Variant): Boolean;
function  VariantLT (const V1: Variant; const V2: Variant): Boolean;
function  VariantGT (const V1: Variant; const V2: Variant): Boolean;
function  VariantAdd2(const V1: Variant; const V2: Variant): Variant;
function  VariantSub2(const V1: Variant; const V2: Variant): Variant;
function  VariantMul2(const V1: Variant; const V2: Variant): Variant;
function  VariantDiv2(const V1: Variant; const V2: Variant): Variant;
function  VariantMod2(const V1: Variant; const V2: Variant): Variant;
function  VariantAnd2(const V1: Variant; const V2: Variant): Variant;
function  VariantOr2 (const V1: Variant; const V2: Variant): Variant;
function  VariantXor2(const V1: Variant; const V2: Variant): Variant;
function  VariantShl2(const V1: Variant; const V2: Variant): Variant;
function  VariantShr2(const V1: Variant; const V2: Variant): Variant;
function  VariantNot (const V1: Variant): Variant;
function  VariantNeg (const V1: Variant): Variant;

function  VariantGetElement(const V: Variant; i1: integer): Variant; overload;
function  VariantGetElement(const V: Variant; i1, i2: integer): Variant; overload;
function  VariantGetElement(const V: Variant; i1, i2, i3: integer): Variant; overload;
function  VariantGetElement(const V: Variant; i1, i2, i3, i4: integer): Variant; overload;
function  VariantGetElement(const V: Variant; i1, i2, i3, i4, i5: integer): Variant; overload;

procedure VariantPutElement(var V: Variant; const data: Variant; i1: integer); overload;
procedure VariantPutElement(var V: Variant; const data: Variant; i1, i2: integer); overload;
procedure VariantPutElement(var V: Variant; const data: Variant; i1, i2, i3: integer); overload;
procedure VariantPutElement(var V: Variant; const data: Variant; i1, i2, i3, i4: integer); overload;
procedure VariantPutElement(var V: Variant; const data: Variant; i1, i2, i3, i4, i5: integer); overload;

// Raise an instance of EVariantError using the CreateRes constructor.
// This function is necessary to avoid attempts to export EVariantError
// from variant.cpp, which is not permitted by the linker when building
// a package.
procedure VariantRaiseError(Ident: Integer);

implementation

procedure VariantCpy(const src: Variant; var dst: Variant);
begin
  dst := src;
end;

procedure VariantAdd(const src: Variant; var dst: Variant);
begin
  dst := dst + src;
end;

procedure VariantSub(const src: Variant; var dst: Variant);
begin
  dst := dst - src;
end;

procedure VariantMul(const src: Variant; var dst: Variant);
begin
  dst := dst * src;
end;

procedure VariantDiv(const src: Variant; var dst: Variant);
begin
  dst := dst / src;
end;

procedure VariantMod(const src: Variant; var dst: Variant);
begin
  dst := dst mod src;
end;

procedure VariantAnd(const src: Variant; var dst: Variant);
begin
  dst := dst and src;
end;

procedure VariantOr (const src: Variant; var dst: Variant);
begin
  dst := dst or src;
end;

procedure VariantXor(const src: Variant; var dst: Variant);
begin
  dst := dst xor src;
end;

procedure VariantShl(const src: Variant; var dst: Variant);
begin
  dst := dst shl src;
end;

procedure VariantShr(const src: Variant; var dst: Variant);
begin
  dst := dst shr src;
end;

function  VariantCmp(const v1: Variant; const V2: Variant): Boolean;
begin
  Result := v1 = v2;
end;

function  VariantLT (const V1: Variant; const V2: Variant): Boolean;
begin
  Result := V1 < V2;
end;

function  VariantGT (const V1: Variant; const V2: Variant): Boolean;
begin
  Result := V1 > V2;
end;

function  VariantAdd2(const V1: Variant; const V2: Variant): Variant;
begin
  Result := v1 + V2;
end;

function  VariantSub2(const V1: Variant; const V2: Variant): Variant;
begin
  Result := V1 - V2;
end;


function  VariantMul2(const V1: Variant; const V2: Variant): Variant;
begin
  Result := V1 * V2;
end;

function  VariantDiv2(const V1: Variant; const V2: Variant): Variant;
begin
  Result := V1 / V2;
end;

function  VariantMod2(const V1: Variant; const V2: Variant): Variant;
begin
  Result := V1 mod V2;
end;

function  VariantAnd2(const V1: Variant; const V2: Variant): Variant;
begin
  Result := V1 and V2;
end;

function  VariantOr2 (const V1: Variant; const V2: Variant): Variant;
begin
  Result := V1 or V2;
end;

function  VariantXor2(const V1: Variant; const V2: Variant): Variant;
begin
  Result := V1 xor V2;
end;

function  VariantShl2(const V1: Variant; const V2: Variant): Variant;
begin
  Result := V1 shl V2;
end;

function  VariantShr2(const V1: Variant; const V2: Variant): Variant;
begin
  Result := V1 shr V2;
end;

function  VariantNot (const V1: Variant): Variant;
begin
  Result := not V1;
end;

function  VariantNeg (const V1: Variant): Variant;
begin
  Result := -V1;
end;

function  VariantGetElement(const V: Variant; i1: integer): Variant; overload;
begin
  Result := V[i1];
end;

function  VariantGetElement(const V: Variant; i1, i2: integer): Variant; overload;
begin
  Result := V[i1, i2];
end;

function  VariantGetElement(const V: Variant; i1, i2, i3: integer): Variant; overload;
begin
  Result := V[I1, i2, i3];
end;

function  VariantGetElement(const V: Variant; i1, i2, i3, i4: integer): Variant; overload;
begin
  Result := V[i1, i2, i3, i4];
end;

function  VariantGetElement(const V: Variant; i1, i2, i3, i4, i5: integer): Variant; overload;
begin
  Result := V[i1, i2, i3, i4, i5];
end;

procedure VariantPutElement(var V: Variant; const data: Variant; i1: integer); overload;
begin
  V[i1] := data;
end;

procedure VariantPutElement(var V: Variant; const data: Variant; i1, i2: integer); overload;
begin
  V[i1, i2] := data;
end;

procedure VariantPutElement(var V: Variant; const data: Variant; i1, i2, i3: integer); overload;
begin
  V[i1, i2, i3] := data;
end;

procedure VariantPutElement(var V: Variant; const data: Variant; i1, i2, i3, i4: integer); overload;
begin
  V[i1, i2, i3, i4] := data;
end;

procedure VariantPutElement(var V: Variant; const data: Variant; i1, i2, i3, i4, i5: integer); overload;
begin
  V[i1, i2, i3, i4, i5] := data;
end;

procedure VariantRaiseError(Ident: Integer);
begin
  raise EVariantError.CreateRes(Ident);
end;


function TPropertyPageImplHack.QueryInterface(const IID: TGUID; out Obj): HResult;
begin
  if GetInterface(IID, Obj) then
    Result := S_OK
  else
    Result := inherited QueryInterface(IID, Obj);
end;

function TPropertyPageImplHack._AddRef: Integer;
begin
  Result := inherited _AddRef;
end;

function TPropertyPageImplHack._Release: Integer;
begin
  Result := inherited _Release;
end;

end.
