{ *************************************************************************** }
{                                                                             }
{ Delphi and Kylix Cross-Platform Visual Component Library                    }
{                                                                             }
{ Copyright (c) 2000, 2001 Borland Software Corporation                       }
{                                                                             }
{ *************************************************************************** }


unit QSearch;

{$R-,T-,X+,H+}

interface

uses SysUtils, QStdCtrls, QDialogs;

const
{ Default word delimiters are any character except the core alphanumerics. }
  WordDelimiters: set of Char = [#0..#255] - ['a'..'z','A'..'Z','1'..'9','0'];

{ TSearchRec contains information prepared about the search to increase
  performance of the search is multiple searchs are performed. See
  PrepareSearch. }
type
  TSearchRec = record
    Options: TFindOptions;
    BMTable: array[Byte] of Integer;
  end;
  
{ SearchMemo scans the text of a TCustomEdit-derived component for a given
  search string.  The search starts at the current caret position in the
  control.  The Options parameter determines whether the search runs forward
  (frDown) or backward from the caret position, whether or not the text
  comparison is case sensitive, and whether the matching string must be a
  whole word.  If text is already selected in the control, the search starts
  at the 'far end' of the selection (SelStart if searching backwards, SelEnd
  if searching forwards).  If a match is found, the control's text selection
  is changed to select the found text and the function returns True.  If no
  match is found, the function returns False. }
function Search(EditControl: TCustomEdit; const SearchString: WideString;
  Options: TFindOptions): Boolean; overload;

function Search(EditControl: TCustomEdit; const SearchString: WideString;
  const SearchRec: TSearchRec): Boolean; overload;

function Search(MemoControl: TCustomMemo; const SearchString: WideString;
  Options: TFindOptions): Boolean; overload;

function Search(MemoControl: TCustomMemo; const SearchString: WideString;
  const SearchRec: TSearchRec): Boolean; overload;

{ SearchBuf is a lower-level search routine for arbitrary text buffers.  Same
  rules as SearchMemo above.  If a match is found, the function returns a
  pointer to the start of the matching string in the buffer.  If no match,
  the function returns nil. }
function Search(const Text: WideString; SelStart, SelLength: Integer;
  const SearchString: WideString; Options: TFindOptions): Integer; overload;

function Search(const Text: WideString; SelStart, SelLength: Integer;
  const SearchString: WideString; const SearchRec: TSearchRec): Integer; overload;

{ PrepareSearch can be used to speed the search by collection information about
  the search string once, instead of every time the search is performed. If
  multiple searches are going to be performed with the same search string,
  PrepareSearch should be called and the resulting record be used instead of
  passing the options }
function PrepareSearch(const SearchString: WideString;
  Options: TFindOptions): TSearchRec;

implementation

uses QForms,
{$IFDEF LINUX}
  Libc;
{$ENDIF}
{$IFDEF MSWINDOWS}
  Windows;
{$ENDIF}

function UpperCaseWideChar(C: WideChar): WideChar;
begin
{$IFDEF MSWINDOWS}
  CharUpperBuffW(@C, 1);
  Result := C;
{$ENDIF}
{$IFDEF LINUX}
  Result := WideChar(towupper(UCS4Char(C)));
{$ENDIF}
end;

{ These search routines use a modified Boyer-Moore search algorithm. It was
  modified to adapt it to be used effectively with Unicode characters. The
  Unicode characters are hashed into a 0..255 range by xor'ing the high and low
  bytes of the Unicode character. It will perform more compares than a true
  Boyer-Moore but the skip table still has 256 entries instead of
  the 65536 entries in an unmodified Boyer-Moore. Thus hashing a character that
  is not in the search string to a character in the search string's entry,
  the skip will be smaller than if the real entry was used. }

function PrepareSearch(const SearchString: WideString;
  Options: TFindOptions): TSearchRec;
var
  I, L, N: Integer;
  W: Word;
begin
  L := Length(SearchString);
  N := L;
  Result.Options := Options;
  // Set up the Boyer-Moore table
  if not (frDown in Options) then
    N := -L;
  for I := Low(Result.BMTable) to High(Result.BMTable) do
    Result.BMTable[I] := N;
  if frDown in Options then
    for I := 1 to L - 1 do
    begin
      W := Word(SearchString[I]);
      if not (frMatchCase in Options) then
        W := Word(UpperCaseWideChar(WideChar(W)));
      Result.BMTable[Hi(W) xor Lo(W)] := L - I
    end
  else
    for I := 2 to L do
    begin
      W := Word(SearchString[I]);
      if not (frMatchCase in Options) then
        W := Word(UpperCaseWideChar(WideChar(W)));
      Result.BMTable[Hi(W) xor Lo(W)] := -I + 1;
    end
end;

function SearchForward(const Text: WideString; SelStart, SelLength: Integer;
  const SearchString: WideString; const SearchRec: TSearchRec): Integer;
var
  K, L, PL: Integer;
  I, J: Integer;
  W: Word;
begin
  L := Length(Text);
  PL := Length(SearchString);
  K := SelStart + PL;
  while K <= L do
  begin
    I := K;
    J := PL;
    while J >= 1 do
      if Text[I] = SearchString[J] then
      begin
        Dec(I);
        Dec(J);
      end
      else
        Break;
    if J = 0 then
    begin
      Result := I + 1;
      Exit;
    end;
    W := Word(Text[K]);
    Inc(K, SearchRec.BMTable[Hi(W) xor Lo(W)]);
  end;
  Result := 0;
end;

function SearchBackward(const Text: WideString; SelStart, SelLength: Integer;
  const SearchString: WideString; const SearchRec: TSearchRec): Integer;
var
  K, PL: Integer;
  I, J: Integer;
  W: Word;
begin
  PL := Length(SearchString);
  K := SelStart - PL;
  while K > 0 do
  begin
    I := K;
    J := 1;
    while J < PL do
      if Text[I] = SearchString[J] then
      begin
        Inc(I);
        Inc(J);
      end
      else
        Break;
    if J = PL then
    begin
      Result := K;
      Exit;
    end;
    W := Word(Text[K]);
    Inc(K, SearchRec.BMTable[Hi(W) xor Lo(W)]);
  end;
  Result := 0;
end;

function SearchForwardIgnoreCase(const Text: WideString; SelStart,
  SelLength: Integer; const SearchString: WideString;
  const SearchRec: TSearchRec): Integer;
var
  K, L, PL: Integer;
  I, J: Integer;
  W: Word;
begin
  L := Length(Text);
  PL := Length(SearchString);
  K := SelStart + PL;
  while K <= L do
  begin
    I := K;
    J := PL;
    while J >= 1 do
      if UpperCaseWideChar(Text[I]) = UpperCaseWideChar(SearchString[J]) then
      begin
        Dec(I);
        Dec(J);
      end
      else
        Break;
    if J = 0 then
    begin
      Result := I + 1;
      Exit;
    end;
    W := Word(UpperCaseWideChar(Text[K]));
    Inc(K, SearchRec.BMTable[Hi(W) xor Lo(W)]);
  end;
  Result := 0;
end;

function SearchBackwardIgnoreCase(const Text: WideString; SelStart,
  SelLength: Integer; const SearchString: WideString;
  const SearchRec: TSearchRec): Integer;
var
  K, PL: Integer;
  I, J: Integer;
  W: Word;
begin
  PL := Length(SearchString);
  K := SelStart - PL;
  while K > 0 do
  begin
    I := K;
    J := 1;
    while J < PL do
      if UpperCaseWideChar(Text[I]) = UpperCaseWideChar(SearchString[J]) then
      begin
        Inc(I);
        Inc(J);
      end
      else
        Break;
    if J = PL then
    begin
      Result := K;
      Exit;
    end;
    W := Word(UpperCaseWideChar(Text[K]));
    Inc(K, SearchRec.BMTable[Hi(W) xor Lo(W)]);
  end;
  Result := 0;
end;

function Search(const Text: WideString; SelStart, SelLength: Integer;
  const SearchString: WideString; const SearchRec: TSearchRec): Integer; overload;
begin
  while True do
  begin
    if frDown in SearchRec.Options then
      if frMatchCase in SearchRec.Options then
        Result := SearchForward(Text, SelStart, SelLength, SearchString, SearchRec)
      else
        Result := SearchForwardIgnoreCase(Text, SelStart, SelLength, SearchString,
          SearchRec)
    else
      if frMatchCase in SearchRec.Options then
        Result := SearchBackward(Text, SelStart, SelLength, SearchString, SearchRec)
      else
        Result := SearchBackwardIgnoreCase(Text, SelStart, SelLength, SearchString,
          SearchRec);
    if Result = 0 then Exit;
    if frWholeWord in SearchRec.Options then
      // Make sure we found a whole word, if not continue searching
      if ((Result = 1) or (Ord(Text[Result - 1]) > 255) or
        (Char(Text[Result - 1]) in WordDelimiters)) and
        ((Result = Length(Text) - Length(SearchString) + 1) or (Ord(Text[Result +
        Length(SearchString)]) > 255) or (Char(Text[Result + Length(SearchString)]) in
        WordDelimiters)) then
        Exit
      else
      begin
        SelStart := Result;
        SelLength := 0;
      end
    else
      Exit;
  end;
end;

function Search(const Text: WideString; SelStart, SelLength: Integer;
  const SearchString: WideString; Options: TFindOptions): Integer; overload;
begin
  Result := Search(Text, SelStart, SelLength, SearchString,
    PrepareSearch(SearchString, Options));
end;

function Search(EditControl: TCustomEdit; const SearchString: WideString;
  const SearchRec: TSearchRec): Boolean; overload;
var
  Text: WideString;
  Index: Integer;
begin
  Result := False;
  if (Length(SearchString) = 0) then Exit;
  Text := EditControl.Text;
  if Length(Text) = 0 then Exit;
  Index := Search(Text, EditControl.SelStart, EditControl.SelLength,
    SearchString, SearchRec);
  if Index > 0 then
  begin
    EditControl.SelStart := Index;
    EditControl.SelLength := Length(SearchString);
    Result := True;
  end;
end;

function Search(EditControl: TCustomEdit; const SearchString: WideString;
  Options: TFindOptions): Boolean; overload;
begin
  Result := Search(EditControl, SearchString, PrepareSearch(SearchString,
    Options));
end;

function Search(MemoControl: TCustomMemo; const SearchString: WideString;
  const SearchRec: TSearchRec): Boolean; overload;
var
  Text: WideString;
  Index: Integer;
begin
  Result := False;
  if (Length(SearchString) = 0) then Exit;
  Text := MemoControl.Text;
  if Length(Text) = 0 then Exit;
  Index := Search(Text, MemoControl.SelStart, MemoControl.SelLength,
    SearchString, SearchRec);
  if Index > 0 then
  begin
    MemoControl.SelStart := Index;
    MemoControl.SelLength := Length(SearchString);
    Result := True;
  end;
end;

function Search(MemoControl: TCustomMemo; const SearchString: WideString;
  Options: TFindOptions): Boolean; overload;
begin
  Result := Search(MemoControl, SearchString, PrepareSearch(SearchString,
    Options));
end;

end.

