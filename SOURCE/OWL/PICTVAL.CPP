//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1993, 1994 by Borland International, All Rights Reserved
//
//   Implementation of TPXPictureValidator, Paradox-picture input validator
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/owlpch.h>
#include <owl/validate.h>
#include <owl/applicat.h>
#include <owl/appdict.h>
#include <owl/framewin.h>
#include <ctype.h>

#if !defined(SECTION) || SECTION == 1

TPXPictureValidator::TPXPictureValidator(const char far* pic, bool autoFill)
:
  TValidator(),
  Pic(pic)
{
  Options = voOnAppend;
  if (autoFill)
    Options |= voFill;
  if (Picture(0, false) != prEmpty)
    THROW( TValidator::TXValidator() );
}

void
TPXPictureValidator::Error()
{
  TApplication* app = GetApplicationObject();
  string msgTmpl = app->LoadString(IDS_VALPXPCONFORM).c_str();
  char* msg = new char[msgTmpl.length() + Pic.length() + 1];
  wsprintf(msg, msgTmpl.c_str(), (const char far*)Pic.c_str());
  TWindow* w = GetWindowPtr(app->GetMainWindow()->GetLastActivePopup());
  if (w)
    w->MessageBox(msg, app->GetName(), MB_ICONEXCLAMATION|MB_OK);
  else
    ::MessageBox(0, msg, app->GetName(), MB_ICONEXCLAMATION|MB_OK|MB_TASKMODAL);
  delete [] msg;
}

bool
TPXPictureValidator::IsValidInput(char far* str, bool suppressFill)
{
  bool autoFill = (Options&voFill) && !suppressFill;
  return Pic.is_null() || Picture(str, autoFill) != prError;
}

bool
TPXPictureValidator::IsValid(const char far* str)
{
  if (Pic.is_null())
    return true;
  TPicResult rslt = Picture((char far*)str, false);
  return rslt == prComplete || rslt == prEmpty;
}

inline bool
TPXPictureValidator::IsComplete(TPicResult rslt)
{
  return rslt == prComplete || rslt == prAmbiguous;
}

inline bool
TPXPictureValidator::IsIncomplete(TPicResult rslt)
{
  return rslt == prIncomplete || rslt == prIncompNoFill;
}

//
// Skip a character or a picture group
//
void
TPXPictureValidator::ToGroupEnd(uint termCh, uint& i)
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
bool
TPXPictureValidator::SkipToComma(uint termCh, uint& i)
{
  for (;;) {
    ToGroupEnd(termCh, i);
    if (i == termCh)
      return false;
    if (Pic[i] == ',') {
      i++;
      return i < termCh;
    }
  }
}

//
// Calculate the end of a group (does not modify i)
//
uint
TPXPictureValidator::CalcTerm(uint termCh, uint i)
{
  ToGroupEnd(termCh, i);
  return i;
}

//
// The next group is repeated X times
//
TPicResult
TPXPictureValidator::Iteration(char far* input, uint termCh, uint& i, uint& j)
{
  TPicResult rslt;
  uint newTermCh;

  i++;  // Skip '*'

  // Retrieve number

  uint itr = 0;
  for (; isdigit(Pic[i]); i++)
    itr = itr * 10 + Pic[i] - '0';

  if (i >= termCh)
    return prSyntax;

  newTermCh = CalcTerm(termCh, i);

  //
  // if itr is 0 allow any number, otherwise enforce the number
  //
  uint k = i;
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
  }
  else {
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
TPXPictureValidator::Group(char far* input, uint termCh, uint& i, uint& j)
{
  uint groupTermCh = CalcTerm(termCh, i);
  i++;
  TPicResult rslt = Process(input, groupTermCh - 1, i, j);
  if (!IsIncomplete(rslt))
    i = groupTermCh;
  return rslt;
}

//
//
//
TPicResult
TPXPictureValidator::CheckComplete(uint termCh, uint& i, TPicResult rslt)
{
  uint j = i;
  if (IsIncomplete(rslt)) {
    // Skip optional pieces
    for (;;) {
      if (Pic[j] == '[')
        ToGroupEnd(termCh, j);

      else if (Pic[j] == '*') {
        if (!isdigit(Pic[j+1])) {
          j++;
          ToGroupEnd(termCh, j);
        }
        else
          break;
      }
      else
        break;

      if (j == termCh)
        return prAmbiguous;  // end of the string, don't know if complete
    }
  }
  return rslt;
}

TPicResult
TPXPictureValidator::Scan(char far* input, uint termCh, uint& i, uint& j)
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
TPXPictureValidator::Process(char far* input, uint termCh, uint& i, uint& j)
{
  TPicResult rslt;
  uint incompJ, incompI;
  incompJ = incompI = 0;

  bool incomp = false;
  uint oldI = i;
  uint oldJ = j;
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
        incomp = true;
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

bool
TPXPictureValidator::SyntaxCheck()
{
  if (Pic.is_null())
    return false;
  if (Pic[Pic.length()-1] == ';')
    return false;
  if (Pic[Pic.length()-1] == '*' && Pic[Pic.length()-2] != ';')
    return false;

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
TPXPictureValidator::Picture(char far* input, bool autoFill)
{
  if (!SyntaxCheck())
    return prSyntax;
  if (!input || !*input)
    return prEmpty;

  uint j = 0;  // index for input[]
  uint i = 0;  // index for Pic[]

  TPicResult rslt = Process(input, Pic.length(), i, j);
  if (rslt != prError && rslt != prSyntax && j < strlen(input))
    rslt = prError;

  // If the result is incomplete & autofill is requested, then copy literal
  // characters from the picture over to the input.
  //
  if (rslt == prIncomplete && autoFill) {
    bool  reprocess = false;
    while (i < Pic.length() && !strchr("#?&!@*{}[],", Pic[i])) {
      if (Pic[i] == ';')
        i++;
      input[j++] = Pic[i++];
      reprocess = true;
    }
    if (reprocess) {
      input[j] = 0;   // terminate the copy, since we are probably appending
      j = i = 0;
      rslt = Process(input, Pic.length(), i, j);
    }
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

