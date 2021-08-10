{*******************************************************}
{                                                       }
{ Borland Delphi Visual Component Library               }
{       Pascal Invoker Support                          }
{                                                       }
{ Copyright (c) 2001 Borland Software Corporation       }
{                                                       }
{*******************************************************}

unit Invoker;

interface

uses
  SysUtils, Classes, Typinfo, IntfInfo, InvokeRegistry;

type

  TInterfaceInvoker = class  
  public
    procedure Invoke(const Obj: TObject; IntfMD: TIntfMetaData;
      const MethNum: Integer; const Context: TInvContext);
    constructor Create;
  end;

implementation

uses InvConst, InvRules, SOAPConst, Variants;


constructor TInterfaceInvoker.Create;
begin
  inherited Create;
end;
{
  PushStackParm

  Copies an aligned number of bytes specified by ByteCount from the Parm
  to the current stack.  N.B.  We leave the bytes on the stack when we
  exit!

  Stack parameters come in many different sizes, ranging from 4 bytes to
  16 bytes.  This function copies a parameter of arbitrary
  size from a prior stack location (assumed the stack), onto the current
  stack.  On exit, we leave the additional bytes on the stack.  We use this
  to build the parameter list to the server side functions.

  We don't have to worry about copying bytes at the end of a page, because
  we assume that Parm is pointing to something higher up on the stack, and
  aligned on a proper stack boundary.
}
procedure PushStackParm(Parm: Pointer; ByteCount: Integer);
asm
        {
          EAX -> Parm (the parameter to be copied)
          EDX -> ByteCount (the number of bytes of data in Parm)
        }
        { We just use a jump table to copy the bits }
        LEA     ECX, @JT
{$IFDEF PIC}
        ADD     ECX, EBX
        ADD     ECX, EDX        // Assume that ByteCount is a DWORD multiple
        POP     EDX             // Remove and save the return address
        MOV     ECX, [ECX]
        ADD     ECX, EBX
        JMP     ECX
{$ELSE}
        ADD     ECX, EDX        // Assume that ByteCount is a DWORD multiple
        POP     EDX             // Remove and save the return address
        JMP     [ECX]
{$ENDIF}
@L4:
        PUSH    [EAX+12]
@L3:
        PUSH    [EAX+8]
@L2:
        PUSH    [EAX+4]
@L1:
        PUSH    [EAX]
        PUSH    EDX             // Push back the saved ret addr
        RET                     // All done
@JT:
        DD  0                   // 0 bytes (never happens)
        DD  @L1                 // 4 bytes
        DD  @L2                 // 8 bytes
        DD  @L3                 // 12 bytes
        DD  @L4                 // 16 bytes
end;

{
  GetFloatReturn

  Handles the nuances of retrieving the various different sized floating
  point values from the FPU and storing them in a buffer.
}
procedure GetFloatReturn(RetP: Pointer; FloatType: TFloatType);
asm
        CMP     EDX, ftSingle
        JE      @@Single
        CMP     EDX, ftDouble
        JE      @@Double
        CMP     EDX, ftExtended
        JE      @@Extended
        CMP     EDX, ftCurr
        JE      @@Curr
        CMP     EDX, ftComp
        JE      @@Curr      { Same as Curr  }
        { Should never get here :) }
@@Single:
        FSTP      DWORD PTR [EAX]
        WAIT
        RET
@@Double:
        FSTP      QWORD PTR [EAX]
        WAIT
        RET
@@Extended:
        FSTP      TBYTE PTR [EAX]
        WAIT
        RET
@@Curr:
        FISTP     QWORD PTR [EAX]
        WAIT
end;

procedure TInterfaceInvoker.Invoke(const Obj: TObject;
      IntfMD: TIntfMetaData; const MethNum: Integer;
      const Context: TInvContext);
var
  MethPos: Integer;
  Unk: IUnknown;
  IntfEntry: PInterfaceEntry;
  IntfVTable: Pointer;
  RetIsOnStack, RetIsInFPU, RetInAXDX: Boolean;
  I: Integer;
  RetP : Pointer;
  MD : TIntfMethEntry;
  DataP: Pointer;
  Temp, Temp1: Integer;
  RetEAX: Integer;
  RetEDX: Integer;
  TotalParamBytes: Integer;
  ParamBytes: Integer;
begin
{$IFDEF LINUX}
  try
{$ENDIF}
  TotalParamBytes := 0;
  MD := IntfMD.MDA[MethNUm];
  if not Obj.GetInterface(IntfMD.IID, Unk) then
    raise Exception.CreateFmt(SNoInterfaceGUID,
      [Obj.ClassName, GUIDToString(IntfMD.IID)]);
  IntfEntry := Obj.GetInterfaceEntry(IntfMD.IID);
  IntfVTable := IntfEntry.VTable;
  MethPos := MD.Pos * 4; { Pos is absolute to whole VMT }
  if MD.ResultInfo <> nil then
  begin
    RetIsInFPU := RetInFPU(MD.ResultInfo);
    RetIsOnStack := RetOnStack(MD.ResultInfo);
    RetInAXDX := IsRetInAXDX(MD.ResultInfo);
    RetP := Context.GetResultPointer;
  end else
  begin
    RetIsOnStack := False;
    RetIsInFPU := False;
    RetInAXDX := False;
  end;

  if MD.CC in [ccCDecl, ccStdCall, ccSafeCall] then
  begin
    if (MD.ResultInfo <> nil) and (MD.CC = ccSafeCall) then
      asm PUSH DWORD PTR [RetP] end;
    for I := MD.ParamCount - 1 downto 0 do
    begin
      DataP := Context.GetParamPointer(I);
      if IsParamByRef(MD.Params[I].Flags,MD.Params[I].Info, MD.CC) then
      asm
        PUSH DWORD PTR [DataP]
      end
      else
      begin
        ParamBytes := GetStackTypeSize(MD.Params[I].Info, MD.CC);
        PushStackParm(DataP, ParamBytes);
        Inc(TotalParamBytes, ParamBytes);
      end;
    end;
    asm PUSH DWORD PTR [Unk] end;
    if RetIsOnStack and (MD.CC <> ccSafeCall) then
      asm PUSH DWORD PTR [RetP] end;
  end
  else if MD.CC = ccPascal then
  begin
    for I := 0 to MD.ParamCount - 1 do
    begin
      DataP := Context.GetParamPointer(I);
      if IsParamByRef(MD.Params[I].Flags,MD.Params[I].Info, MD.CC) then
      asm
         PUSH DWORD PTR [DataP]
      end
      else
      begin
//        PushStackParm(DataP, GetStackTypeSize(MD.Params[I].Info, MD.CC));
        ParamBytes := GetStackTypeSize(MD.Params[I].Info, MD.CC);
        PushStackParm(DataP, ParamBytes);
        Inc(TotalParamBytes, ParamBytes);
      end;
    end;
    if RetIsOnStack then
      asm PUSH DWORD PTR [RetP] end;
    asm PUSH DWORD PTR [Unk] end;
  end else
     raise Exception.CreateFmt(SUnsupportedCC, [CallingConventionName[MD.CC]]);

  if MD.CC <> ccSafeCall then
  begin
    asm
      MOV DWORD PTR [Temp], EAX
      MOV DWORD PTR [Temp1], ECX
      MOV EAX, MethPos
      MOV ECX, [IntfVtable]
      MOV ECX, [ECX + EAX]
      CALL ECX
      MOV DWORD PTR [RetEAX], EAX
      MOV DWORD PTR [RetEDX], EDX
      MOV EAX, DWORD PTR [Temp]
      MOV ECX, DWORD PTR [Temp1]
    end;
  end else
  begin
    asm
      MOV DWORD PTR [Temp], EAX
      MOV DWORD PTR [Temp1], ECX
      MOV EAX, MethPos
      MOV ECX, [IntfVtable]
      MOV ECX, [ECX + EAX]
      CALL ECX
      CALL System.@CheckAutoResult
      MOV DWORD PTR [RetEAX], EAX
      MOV DWORD PTR [RetEDX], EDX
      MOV EAX, DWORD PTR [Temp]
      MOV ECX, DWORD PTR [Temp1]
    end;
  end;

  // If we're cdecl, we're responsible for cleanup up the stack.
  if MD.CC = ccCDecl then
  asm
    MOV EAX, DWORD PTR [TotalParamBytes]
    ADD ESP, EAX
  end;

  if MD.ResultInfo <> nil then
  begin
    if MD.CC <> ccSafeCall then
    begin
      if RetIsInFPU then
      begin
        GetFloatReturn(RetP, GetTypeData(MD.ResultInfo).FloatType);
      end else if not RetIsOnStack then
      begin
        if RetInAXDX then
        asm
            PUSH EAX
            PUSH ECX
            MOV EAX, DWORD PTR [RetP]
            MOV ECX, DWORD PTR [RetEAX]
            MOV [EAX], ECX
            MOV ECX, DWORD PTR [RetEDX]
            MOV [EAX + 4], ECX
            POP ECX
            POP EAX
        end
        else
        asm
            PUSH EAX
            PUSH ECX
            MOV EAX, DWORD PTR [RetP]
            MOV ECX, DWORD PTR [RetEAX]
            MOV [EAX], ECX
            POP ECX
            POP EAX
        end;
      end;
    end;
  end;
{$IFDEF LINUX}
  except
    // This little bit of code is required to reset the stack back to a more
    // resonable state since the exception unwinder is completely unaware of
    // the stack pointer adjustments made in this function.
    asm
      MOV EAX, DWORD PTR [TotalParamBytes]
      ADD ESP, EAX
    end;
    raise;
  end;
{$ENDIF}
end;

end.

