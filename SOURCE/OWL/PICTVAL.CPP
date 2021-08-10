//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1993, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.6  $
//
// Implementation of TPXPictureValidator, Paradox-picture input validator
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/pch.h>
#if !defined(OWL_VALIDATE_H)
# include <owl/validate.h>
#endif
#if !defined(OWL_APPLICAT_H)
# include <owl/applicat.h>
#endif
#if !defined(OWL_APPDICT_H)
# include <owl/appdict.h>
#endif
#if !defined(OWL_FRAMEWIN_H)
# include <owl/framewin.h>
#endif
#include <ctype.h>
#include <stdio.h>

OWL_DIAGINFO;

#if !defined(SECTION) || SECTION == 1

//
//
//
TPXPictureValidator::TPXPictureValidator(const char far* pic, bool autoFill)
:
  TValidator(),
  Pic(pic)
{
  Options = voOnAppend;
  if (autoFill)
    Options |= voFill;
  if (Picture(0, false) != prEmpty)
    TXValidator::Raise();
}

//
//
//
void
TPXPictureValidator::Error(TWindow* owner)
{
  PRECONDITION(owner);
  TApplication* app = owner->GetApplication();
  string msgTmpl = app->LoadString(IDS_VALPXPCONFORM);
  TAPointer<char> msg = new char[msgTmpl.length() + Pic.length() + 1];
  sprintf(msg, msgTmpl.c_str(), (const char far*)Pic.c_str());
  owner->MessageBox(msg, app->GetName(), MB_ICONEXCLAMATION|MB_OK);
}

//
//
//
bool
TPXPictureValidator::IsValidInput(char far* input, bool suppressFill)
{
  bool autoFill = (Options&voFill) && !suppressFill;
  return Pic.is_null() || Picture(input, autoFill) != prError;
}

//
//
//
bool
TPXPictureValidator::IsValid(const char far* input)
{
  if (Pic.is_null())
    return true;
  TPicResult rslt = Picture(CONST_CAST(char far*,input), false);
  return rslt == prComplete || rslt == prEmpty;
}

//
// Adjust the 'value' of the text, given a cursor position & an amount
// Return the actual amount adjusted.
//
int
TPXPictureValidator::Adjust(string& /*text*/, uint& /*begPos*/,
                            uint& /*endPos*/, int /*amount*/)
{
  return 0;
}

//
//
//
inline bool
TPXPictureValidator::IsComplete(TPicResult rslt)
{
  return rslt == prComplete || rslt == prAmbiguous;
}

//
//
//
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
        while (isdigit((uchar)Pic[i]))
          i++;
        ToGroupEnd(termCh, i);
        continue;
    }
    i += CharSize((const char far*)Pic.c_str() + i);
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
  for (; isdigit((uchar)Pic[i]); i++)
    itr = itr * 10 + Pic[i] - '0';

  if (i >= termCh)
    return prSyntax;

  newTermCh = CalcTerm(termCh, i);

  //
  // if itr is 0 allow any number, otherwise enforce the number
  //
  uint k = i;
  if (itr) {
    for (uint m = 0; m < itr; m++) {
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
        if (!isdigit((uchar)Pic[j+1])) {
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

//
//
//
#pragma warn -aus
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
        if (!isdigit((uchar)ch))
          return prError;
        else {
          input[j++] = ch;
          i++;
        }
        break;
      case '?':
        if (!isalpha((uchar)ch))
          return prError;
        else {
          input[j++] = ch;
          i++;
        }
        break;
      case '&':
        if (!isalpha((uchar)ch))
          return prError;
        else {
          input[j++] = (char)toupper(ch);
          i++;
        }
        break;
      case '!': {
#if defined(BI_DBCS_SUPPORT)
        uint n = CharSize(&input[j]);
        if (j + n >= len)
          j = len;
        else {
          if (n == 1)
            input[j++] = (char)toupper((uchar)ch);
          else
            j += n;
        }
#else
        input[j++] = (char)toupper(ch);
#endif
        i++;
        break;
      }
      case '@': {
#if defined(BI_DBCS_SUPPORT)
        uint n = CharSize(&input[j]);
        if (j + n >= len)
          j = len;
        else
          j += n;
#else
        input[j++] = ch;
#endif
        i++;
        break;
      }
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
      default: {
#if defined(BI_DBCS_SUPPORT)
        if (Pic[i] == ';')
          i++;
        uint n  = CharSize(&input[j]);
        uint n2 = CharSize((const char far*)Pic.c_str() + i);

        if (j + n >= len)
          n = len - j;
        if (n == 1) {
          if (ch == ' ') {
            if (n != n2)
              return prError;
            input[j++] = Pic[i++];
          }
          else {
            if (n != n2)
              return prError;
            if (toupper((uchar)Pic[i]) != toupper((uchar)ch))
              return prError;
            input[j++] = Pic[i++];
          }
        }
        else {
          if (n > n2)
            return prError;
          for (uint i1 = 0; i1 < n; i1++)
            if (input[j+i1] != Pic[i+i1])
              return prError;
          while (n-- > 0)
            input[j++] = Pic[i++];
        }
#else
        if (Pic[i] == ';')
          i++;
        if (toupper(Pic[i]) != toupper(ch))
          if (ch == ' ')
            ch = Pic[i];
          else
            return prError;
        input[j++] = Pic[i];
        i++;
#endif
      }
    }
    if (rslt == prAmbiguous)
      rslt = prIncompNoFill;
    else
      rslt = prIncomplete;
  }

  return (rslt == prIncompNoFill) ? prAmbiguous : prComplete;
}
#pragma warn .aus

//
//
//
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

//
//
//
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
  for (uint i = 0; i < Pic.length(); ) {
    switch (Pic[i]) {
      case '[': brkLevel++; break;
      case ']': brkLevel--; break;
      case '{': brcLevel++; break;
      case '}': brcLevel--; break;
      case ';': i++;
    }
    i += CharSize((const char far*)Pic.c_str() + i);
  }
  return !(brkLevel || brcLevel);
}

//
//
//
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
#if defined(BI_DBCS_SUPPORT)
      uint k = strlen(input);
      uint n = CharSize((const char far*)Pic.c_str() + i);
      memmove(input + k, Pic.c_str() + i, n);
      input[k + n] = '\0';
      i += n;
      j += n;
#else
      input[j++] = Pic[i++];
#endif
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

#if !defined(BI_NO_OBJ_STREAMING)

//
//
//
void*
TPXPictureValidator::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadBaseObject((TValidator*)GetObject(), is);
  is >> GetObject()->Pic;
  return GetObject();
}

//
//
//
void
TPXPictureValidator::Streamer::Write(opstream& os) const
{
  WriteBaseObject((TValidator*)GetObject(), os);
  os << GetObject()->Pic;
}

#endif  // if !defined(BI_NO_OBJ_STREAMING)

#endif
