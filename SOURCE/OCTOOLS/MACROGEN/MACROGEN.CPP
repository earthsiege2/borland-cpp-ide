// ---------------------------------------------------------------------------
// Copyright (C) 1994 Borland International
// ---------------------------------------------------------------------------
#include <iostream.h>
#include <strstrea.h>
#include <cstring.h>
#include <stdlib.h>

enum bool
{
  false = 0,
  true = 1
};

//
// AutomationMacro
//  Abstract base class
//
class AutomationMacro {
  public:
    AutomationMacro() {}
    virtual ~AutomationMacro() {}

    virtual void Generate(strstream &stream, const bool voidReturnType, const int numArgs) = 0;
    virtual const char* GetMacroName() const = 0;
    virtual const int   GetRequiredArgs() const = 0;
};

void
GenerateDefArgsMacro(strstream& stream, const int numArgs)
{
  int i;

  stream << "#define DEFARGS" << numArgs << "(";
  for (i=1; i<=numArgs; i++) {
    stream << "t" << i;
    if (i != numArgs)
      stream << ",";
  }
  stream << ") ";

  for (i=1; i<=numArgs; i++)
    stream << "t" << i << " Arg" << i << ";";

  stream << endl;
}

void
GenerateBldArgsMacro(strstream& stream, const int numArgs)
{
  int i;

  stream << "#define BLDARGS" << numArgs << "(";
  for (i=1; i<=numArgs; i++) {
    stream << "t" << i;
    if (i != numArgs)
      stream << ",";
  }
  stream << ") ";

  for (i=1; i<=numArgs; i++)
    stream << ",(t" << i << ")args[" << (i-1) << "]";

  stream << endl;
}

void
GenerateCtrArgsMacro(strstream& stream, const int numArgs)
{
  int i;

  stream << "#define CTRARGS" << numArgs << "(";
  for (i=1; i<=numArgs; i++) {
    stream << "t" << i;
    if (i != numArgs)
      stream << ",";
  }
  stream << ") ";

  for (i=1; i<=numArgs; i++)
    stream << ",t" << i << " arg" << i;

  stream << endl;
}

void
GenerateSetArgsMacro(strstream& stream, const int numArgs)
{
  int i;

  stream << "#define SETARGS" << numArgs << " ";

  for (i=1; i<=numArgs; i++)
    stream << ",Arg" << i << "(arg" << i << ")";

  stream << endl;
}

void
GenerateMacrosUsage(strstream& stream, const char* macroName, const int numArgs)
{
  int i;

  stream << macroName << numArgs << "(";
  for (i=1; i<=numArgs; i++) {
    stream << "t" << i;
    if (i != numArgs)
      stream << ",";
  }
  stream << ")";
}


//
// AutoFunc
//
class AutoFunc : public AutomationMacro {
  public:
    void Generate(strstream& stream, const bool voidReturnType, const int numArgs);
    const char* GetMacroName() const      { return "AutoFunc"; }
    const int   GetRequiredArgs() const   { return 4; }
};

void
AutoFunc::Generate(strstream& stream, const bool voidReturnType, const int numArgs)
{
  int i;
  string returnTypeString;

  if (voidReturnType == true) {
    returnTypeString = "V";
  } else {
    returnTypeString = "";
  }

  GenerateDefArgsMacro(stream, numArgs);
  GenerateBldArgsMacro(stream, numArgs);
  GenerateCtrArgsMacro(stream, numArgs);
  GenerateSetArgsMacro(stream, numArgs);

  stream << "#define AUTOFUNC" << numArgs << returnTypeString << "(name, func";
  if (voidReturnType != true)
    stream << ", ret";
  for (i=1; i<=numArgs; i++)
    stream << ", t" << i;
  stream << ", defs) \\" << endl;

  stream << "  AUTOFUNC_(name, ";
  if (voidReturnType != true)
    stream << "Val=";
  stream << "This->func(";
  for (i=1; i<=numArgs; i++) {
    stream << "Arg" << i;
    if (i!=numArgs)
      stream << ", ";
  }
  stream << ");, defs, \\" << endl;

  stream << "  ";
  if (voidReturnType != true)
    stream << "RETARG(ret) ";
  GenerateMacrosUsage(stream, "DEFARGS", numArgs);
  stream << ", \\" << endl;
  GenerateMacrosUsage(stream, "  BLDARGS", numArgs);
  stream << ", \\" << endl;
  GenerateMacrosUsage(stream, "  CTRARGS", numArgs);
  stream << ", \\" << endl;
  stream << "  SETARGS" << numArgs << ")" << endl;
}

//
// AutoStat
//
class AutoStat : public AutomationMacro {
  public:
    void Generate(strstream& stream, const bool voidReturnType, const int numArgs);
    const char* GetMacroName() const      { return "AutoStat"; }
    const int   GetRequiredArgs() const   { return 4; }
};

void
AutoStat::Generate(strstream& stream, const bool voidReturnType, const int numArgs)
{
  int i;
  string returnTypeString;

  if (voidReturnType == true) {
    returnTypeString = "V";
  } else {
    returnTypeString = "";
  }

  GenerateDefArgsMacro(stream, numArgs);
  GenerateBldArgsMacro(stream, numArgs);
  GenerateCtrArgsMacro(stream, numArgs);
  GenerateSetArgsMacro(stream, numArgs);

  stream << "#define AUTOSTAT" << numArgs << returnTypeString << "(name, func";
  if (voidReturnType != true)
    stream << ", ret";
  for (i=1; i<=numArgs; i++)
    stream << ", t" << i;
  stream << ", defs) \\" << endl;

  stream << "  AUTOFUNC_(name, ";
  if (voidReturnType != true)
    stream << "Val=";
  stream << "func(";

  for (i=1; i<=numArgs; i++) {
    stream << "Arg" << i;
    if (i!=numArgs)
      stream << ", ";
  }
  stream << ");, defs, \\" << endl;

  stream << "  ";
  if (voidReturnType != true)
    stream << "RETARG(ret) ";
  GenerateMacrosUsage(stream, "DEFARGS", numArgs);
  stream << ", \\" << endl;
  GenerateMacrosUsage(stream, "  BLDARGS", numArgs);
  stream << ", \\" << endl;
  GenerateMacrosUsage(stream, "  CTRARGS", numArgs);
  stream << ", \\" << endl;
  stream << "  SETARGS" << numArgs << ")" << endl;
}


//
// AutoBuild
//
class AutoBuild : public AutomationMacro {
  public:
    void Generate(strstream& stream, const bool voidReturnType, const int numArgs);
    const char* GetMacroName() const      { return "AutoBuild"; }
    const int   GetRequiredArgs() const   { return 4; }
};

void
AutoBuild::Generate(strstream& stream, const bool /*voidReturnType*/, const int numArgs)
{
  int i;

  GenerateDefArgsMacro(stream, numArgs);
  GenerateBldArgsMacro(stream, numArgs);
  GenerateCtrArgsMacro(stream, numArgs);
  GenerateSetArgsMacro(stream, numArgs);

  stream << "#define AUTOBUILD" << numArgs << "(name, func";
  for (i=1; i<=numArgs; i++)
    stream << ", t" << i;
  stream << ", defs) \\" << endl;

  stream << "  AUTOBUILD_(name, Val=new ThisClass(";
  for (i=1; i<=numArgs; i++) {
    stream << "Arg" << i;
    if (i!=numArgs)
      stream << ", ";
  }

  stream << ");, defs, \\" << endl;

  GenerateMacrosUsage(stream, "  DEFARGS", numArgs);
  stream << ", \\" << endl;
  GenerateMacrosUsage(stream, "  BLDARGS", numArgs);
  stream << ", \\" << endl;
  GenerateMacrosUsage(stream, "  CTRARGS", numArgs);
  stream << ", \\" << endl;
  stream << "  SETARGS" << numArgs << ")" << endl;
}


//
// AutoNames
//
class AutoNames : public AutomationMacro {
  public:
    void Generate(strstream& stream, const bool voidReturnType, const int numArgs);
    const char* GetMacroName() const      { return "AutoNames"; }
    const int   GetRequiredArgs() const   { return 6; }
};

void
AutoNames::Generate(strstream& stream, const bool /*voidReturnType*/, const int numArgs)
{
  int i;
  stream << "#define AUTONAMES" << numArgs << "(id";

  for (i=1; i<=numArgs; i++) {
    stream << ",n" << i;
  }
  stream << ") static TAutoDispIds<" << numArgs << "> i_(this, id, ";
  for (i=numArgs; i>=1; i--) {
    stream << "_A(n" << i << ")";
  }
  stream << ");" << endl;
}


//
// AutoArgs
//
class AutoArgs : public AutomationMacro {
  public:
    void Generate(strstream& stream, const bool voidReturnType,
      const int numArgs);
    const char* GetMacroName() const      { return "AutoArgs"; }
    const int   GetRequiredArgs() const   { return 6; }
};

void
AutoArgs::Generate(strstream& stream, const bool /*voidReturnType*/, const int numArgs)
{
  int i;
  stream << "#define AUTOARGS" << numArgs << "(";

  for (i=1; i<=numArgs; i++) {
    stream << "a" << i;
    if (i != numArgs)
      stream << ",";
  }
  stream << ") TAutoArgs<" << numArgs << ">a_; ";
  for (i=1; i<=numArgs; i++) {
    stream << "a_[" << i << "]=a" << i << "; ";
  }
  stream << endl;
}


//
// Global variables
//
AutoFunc    GlobalAutoFunc;
AutoStat    GlobalAutoStat;
AutoBuild   GlobalAutoBuild;
AutoNames   GlobalAutoNames;
AutoArgs    GlobalAutoArgs;

AutomationMacro *Macros[] = {
  &GlobalAutoFunc,    &GlobalAutoStat,  &GlobalAutoBuild,
  &GlobalAutoNames, &GlobalAutoArgs
};

const int NumMacros = sizeof(Macros) / sizeof(Macros[0]);

void
PrintUsage()
{
  cerr << "MacroGen Utility v1.0" << endl;
  cerr << "Copyright (c) 1994, Borland International Inc" << endl;
  cerr << "All Rights Reserved" << endl;
  cerr << endl;
  cerr << "  MacroGen AutomationMacro [void] numArgs" << endl;
  cerr << endl;
  cerr << "where AutomationMacro is one of the following:" << endl;
  cerr << endl;
  for (int i=0; i<NumMacros; i++)
    cerr << "\t" << Macros[i]->GetMacroName() << endl;
}

void
ErrorMsg(const char* msg, const int exitCode)
{
  cerr << "Error: " << msg << endl;
  cerr << endl;
  PrintUsage();
  exit(exitCode);
}

//
// starting point
//
int
main(int argc, char *argv[])
{
  bool voidReturnType = false;
  bool macroMatch = false;
  int numArgs = 0;

  if (argc <= 2 || 4 < argc)
    ErrorMsg("Wrong number of arguments", 1);

  if (strcmpi(argv[2], "void") == 0) {
    if (argc == 3)
      ErrorMsg("Missing 'numArgs' argument", 1);
    voidReturnType = true;
    numArgs = atoi(argv[3]);
  } else {
    if (argc == 4)
      ErrorMsg("Extra argument", 1);
    numArgs = atoi(argv[2]);
  }

  strstream outStream;

  for (int i=0; i<NumMacros; i++) {
    if (strcmpi(argv[1], Macros[i]->GetMacroName()) == 0) {
      macroMatch = true;
      if (numArgs <= Macros[i]->GetRequiredArgs())
        ErrorMsg("Number of arguments specified for macro is already defined in automacr.h", 1);
      Macros[i]->Generate(outStream, voidReturnType, numArgs);
//      OutStream << ends;
      cout << outStream.rdbuf();
    }
  }

  if (macroMatch == false)
    ErrorMsg("Macro not found", 1);

  return 0;
}
