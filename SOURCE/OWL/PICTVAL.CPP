//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1993 by Borland International
//   source\owl\pictval.cpp
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl\owlpch.h>
#include <owl\validate.h>
#include <owl\applicat.h>
#include <classlib\objstrm.h>
#include <ctype.h>

#if !defined(SECTION) || SECTION == 1

TPXPictureValidator::TPXPictureValidator(const char far* pic, BOOL autoFill)
  : TValidator(),
    Pic(pic)
{
  Options = voOnAppend;
  if (autoFill)
    Options |= voFill;
  if (Picture(0, FALSE) != prEmpty)
    THROW( TValidator::TXValidator() );
}

void
TPXPictureValidator::Error()
{
  char msg[256];
  wsprintf(msg, string(*GetApplicationObject(), IDS_VALPXPCONFORM).c_str(),
           (LPCSTR)Pic.c_str());
  ::MessageBox(0, msg, GetApplicationObject()->GetName(), 
    MB_ICONEXCLAMATION | MB_OK | MB_TASKMODAL);
}

BOOL
TPXPictureValidator::IsValidInput(char far* str, BOOL suppressFill)
{
  BOOL autoFill = (Options&voFill) && !suppressFill;
  return Pic.is_null() || (Picture(str, autoFill) != prError);
}

BOOL
TPXPictureValidator::IsValid(const char far* str)
{
  if (Pic.is_null())
    return TRUE;
  TPicResult rslt = Picture((char far*)str, FALSE);
  return rslt == prComplete || rslt == prEmpty;
}

inline BOOL
TPXPictureValidator::IsComplete(TPicResult rslt)
{
  return rslt == prComplete || rslt == prAmbiguous;
}

inline BOOL
TPXPictureValidator::IsIncomplete(TPicResult rslt)
{
  return rslt == prIncomplete || rslt == prIncompNoFill;
}

//
// Skip a character or a picture group
//
void
TPXPictureValidator::ToGroupEnd(UINT termCh, UINT& i)
{
  int brkLevel = 0;
  int brcLevel = 0;

  do {
    if (i == termCh)
      return;
    switch (Pic[i]) {
      case '[': brkLevel++; break;
      case ']': brkLevel--; break;
      case '{': brcLevel++; break;
      case '}': brcLevel--; break;
      case ';': i++; break;
      case '*':
        i++;
        while (isdigit(Pic[i]))
          i++;
        ToGroupEnd(termCh, i);
        continue;
    }
    i++;
  } while (brkLevel || brcLevel);
}

//
// Find the next comma separator
//
BOOL
TPXPictureValidator::SkipToComma(UINT termCh, UINT& i)
{
  for (;;) {
    ToGroupEnd(termCh, i);
    if (i == termCh)
      return FALSE;
    if (Pic[i] == ',') {
      i++;
      return i < termCh;
    }
  }
}

//
// Calculate the end of a group(does not modify i)
//
UINT
TPXPictureValidator::CalcTerm(UINT termCh, UINT i)
{
  ToGroupEnd(termCh, i);
  return i;
}

//
// The next group is repeated X times
//
TPicResult
TPXPictureValidator::Iteration(char far* input, UINT termCh, UINT& i, UINT& j)
{
  TPicResult rslt;
  UINT newTermCh;

  i++;  // Skip '*'

  // Retrieve number

  UINT itr = 0;
  for (; isdigit(Pic[i]); i++)
    itr = itr * 10 + Pic[i] - '0';

  if (i >= termCh)
    return prSyntax;

  newTermCh = CalcTerm(termCh, i);

  //
  // if itr is 0 allow any number, otherwise enforce the number
  //
  UINT k = i;
  if (itr) {
    for (int m = 0; m < itr; m++) {
      i = k;
      rslt = Process(input, newTermCh, i, j);
      if (!IsComplete(rslt)) {
        if (rslt == prEmpty)  // Empty means incomplete since all are required
          rslt = prIncomplete;
        return rslt;
      }
    }
  } else {
    do {
      i = k;
      rslt = Process(input, newTermCh, i, j);
    } while (IsComplete(rslt));
    if (rslt == prEmpty || rslt == prError) {
      i++;
      rslt = prAmbiguous;
    }
  }
  i = newTermCh;
  return rslt;
}

//
// Process a picture group
//
TPicResult
TPXPictureValidator::Group(char far* input, UINT termCh, UINT& i, UINT& j)
{
  UINT groupTermCh = CalcTerm(termCh, i);
  i++;
  TPicResult rslt = Process(input, groupTermCh - 1, i, j);
  if (!IsIncomplete(rslt))
    i = termCh;
  return rslt;
}

//
//
//
TPicResult
TPXPictureValidator::CheckComplete(UINT termCh, UINT& i, TPicResult rslt)
{
  UINT j = i;
  if (IsIncomplete(rslt)) {
    // Skip optional pieces
    for (;;) {
      if (Pic[j] == '[')
        ToGroupEnd(termCh, j);

      else if (Pic[j] == '*') {
        if (!isdigit(Pic[j+1])) {
          j++;
          ToGroupEnd(termCh, j);
        } else
          break;
      } else
        break;
    }
    if (j == termCh)
      rslt = prAmbiguous;
  }
  return rslt;
}

TPicResult
TPXPictureValidator::Scan(char far* input, UINT termCh, UINT& i, UINT& j)
{
  char ch;
  TPicResult rslt = prEmpty;

  unsigned len = strlen(input);
  while (i != termCh && Pic[i] != ',') {
    if (j >= len)
      return CheckComplete(termCh, i, rslt);

    ch = input[j];
    switch (Pic[i]) {
      case '#':
        if (!isdigit(ch))
          return prError;
        else {
          input[j++] = ch;
          i++;
        }
        break;
      case '?':
        if (!isalpha(ch))
          return prError;
        else {
          input[j++] = ch;
          i++;
        }
        break;
      case '&':
        if (!isalpha(ch))
          return prError;
        else {
          input[j++] = (char)toupper(ch);
          i++;
        }
        break;
      case '!':
        input[j++] = (char)toupper(ch);
        i++;
        break;
      case '@':
        input[j++] = ch;
        i++;
        break;
      case '*':
        rslt = Iteration(input, termCh, i, j);
        if (!IsComplete(rslt))
          return rslt;
        if (rslt == prError)
          rslt = prAmbiguous;
        break;
      case '{':
        rslt = Group(input, termCh, i, j);
        if (!IsComplete(rslt))
          return rslt;
        break;
      case '[':
        rslt = Group(input, termCh, i, j);
        if (IsIncomplete(rslt))
          return rslt;
        if (rslt == prError)
          rslt = prAmbiguous;
        break;
      default:
        if (Pic[i] == ';')
          i++;
        if (toupper(Pic[i]) != toupper(ch))
          if (ch == ' ')
            ch = Pic[i];
          else
            return prError;
        input[j++] = Pic[i];
        i++;
    }
    if (rslt == prAmbiguous)
      rslt = prIncompNoFill;
    else
      rslt = prIncomplete;
  }

  return (rslt == prIncompNoFill) ? prAmbiguous : prComplete;
}

TPicResult
TPXPictureValidator::Process(char far* input, UINT termCh, UINT& i, UINT& j)
{
  TPicResult rslt;
  UINT incompJ, incompI;
  incompJ = incompI = 0;

  BOOL incomp = FALSE;
  UINT oldI = i;
  UINT oldJ = j;
  do {
    rslt = Scan(input, termCh, i, j);

    //
    // Only accept completes if they make it farther in the input
    // stream from the last incomplete
    //
    if ((rslt==prComplete || rslt==prAmbiguous) && incomp && j < incompJ) {
      rslt = prIncomplete;
      j = incompJ;
    }

    if (rslt == prError || rslt == prIncomplete) {
      if (!incomp && rslt == prIncomplete) {
        incomp = TRUE;
        incompI = i;
        incompJ = j;
      }
      i = oldI;
      j = oldJ;
      if (!SkipToComma(termCh, i)) {
        if (incomp) {
          i = incompI;
          j = incompJ;
          return prIncomplete;
        }
        return rslt;
      }
      oldI = i;
    }
  } while (rslt == prError || rslt == prIncomplete);

  return (rslt == prComplete && incomp) ? prAmbiguous : rslt;
}

BOOL
TPXPictureValidator::SyntaxCheck()
{
  if (Pic.is_null())
    return FALSE;
  if (Pic[Pic.length()-1] == ';')
    return FALSE;
  if (Pic[Pic.length()-1] == '*' && Pic[Pic.length()-2] != ';')
    return FALSE;

  int brkLevel = 0;
  int brcLevel = 0;
  for (int i = 0; i < Pic.length(); i++) {
    switch (Pic[i]) {
      case '[': brkLevel++; break;
      case ']': brkLevel--; break;
      case '{': brcLevel++; break;
      case '}': brcLevel--; break;
      case ';': i++;
    }
  }
  return !(brkLevel || brcLevel);
}

TPicResult
TPXPictureValidator::Picture(char far* input, BOOL autoFill)
{
  if (!SyntaxCheck())
    return prSyntax;
  if (!input || !*input)
    return prEmpty;

  UINT j = 0;  // index for input[]
  UINT i = 0;  // index for Pic[]

  TPicResult rslt = Process(input, Pic.length(), i, j);
  if (rslt != prError && rslt != prSyntax && j < strlen(input))
    rslt = prError;

  if (rslt == prIncomplete && autoFill) {
    BOOL  reprocess = FALSE;
    while (i < Pic.length() && !strchr("#?&!@*{}[],", Pic[i])) {
      if (Pic[i] == ';')
        i++;
      input = input + Pic[i];
      i++;
      reprocess = TRUE;
    }
    j = 0;
    i = 0;
    if (reprocess)
      rslt = Process(input, Pic.length(), i, j);
  }

  return (rslt == prAmbiguous) ? prComplete
                               : (rslt == prIncompNoFill) ? prIncomplete : rslt;
}

#endif
#if !defined(SECTION) || SECTION == 2

IMPLEMENT_STREAMABLE1(TPXPictureValidator, TValidator);

void*
TPXPictureValidator::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadBaseObject((TValidator*)GetObject(), is);
  is >> GetObject()->Pic;
  return GetObject();
}

void
TPXPictureValidator::Streamer::Write(opstream& os) const
{
  WriteBaseObject((TValidator*)GetObject(), os);
  os << GetObject()->Pic;
}

#endif

