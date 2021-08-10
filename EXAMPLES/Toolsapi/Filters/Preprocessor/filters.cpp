#include <vcl.h>
#pragma hdrstop

#include "Filters.h"


#pragma package(smart_init)

TPreprocessFilter *PreprocessFilter = NULL; 

/* IUnknown */
HRESULT STDMETHODCALLTYPE TPreprocessFilter::QueryInterface(REFIID riid,
  void __RPC_FAR *__RPC_FAR *ppvObject)
{
  *ppvObject = NULL;

  if (IsEqualIID(riid, __uuidof(IUnknown)))
    *ppvObject = static_cast<IUnknown *>(this);
  else if (IsEqualIID(riid, __uuidof(IOTANotifier)))
    *ppvObject = static_cast<IOTANotifier *>(this);
  else if (IsEqualIID(riid, __uuidof(IOTAToolsFilterNotifier)))
    *ppvObject = static_cast<IOTAToolsFilterNotifier *>(this);

  if (*ppvObject != NULL)
  {
    reinterpret_cast<IUnknown *>(*ppvObject)->AddRef();
    return S_OK;
  }

  return E_NOINTERFACE;
};

ULONG STDMETHODCALLTYPE TPreprocessFilter::AddRef(void)
{
  return InterlockedIncrement(&m_Count);
};

ULONG STDMETHODCALLTYPE TPreprocessFilter::Release(void)
{
  if (InterlockedDecrement(&m_Count) == 0)
  {
    PreprocessFilter = NULL;
    delete this;
    return 0;
  }
  return m_Count;
};

/* IOTANotifier */
void __fastcall TPreprocessFilter::AfterSave(void)
{
};

void __fastcall TPreprocessFilter::BeforeSave(void)
{
};

void __fastcall TPreprocessFilter::Destroyed(void)
{
  _di_IOTAToolsFilter ToolsFilter;
  if (SUCCEEDED(BorlandIDEServices->QueryInterface(__uuidof(IOTAToolsFilter),
    (void **)&ToolsFilter)))
    ToolsFilter->RemoveNotifier(FilterID);
};

void __fastcall TPreprocessFilter::Modified(void)
{
};

AnsiString NextToken(AnsiString &buffer)
{
  int p;
  p = buffer.Pos(" ");
  if (p != 0)
  {
    AnsiString Result;
    Result = buffer.SubString(1, p - 1);
    buffer.Delete(1, p);
    return Result;
  }
  else
    return "";
};


/* IOTAToolsFilterNotifiter */
void __fastcall TPreprocessFilter::Filter(AnsiString FileName, int ErrorCode,
   Classes::TStrings* StdOut, Classes::TStrings* StdError)
{
  if (ErrorCode == 0)
  {
    _di_IOTAModuleServices ModuleServices;
    _di_IOTAModule Module = NULL;
    if (SUCCEEDED(BorlandIDEServices->QueryInterface(__uuidof(IOTAModuleServices),
      (void **)&ModuleServices)))
        Module = ModuleServices->FindModule(ChangeFileExt(FileName, ".i"));
    _di_IOTAActionServices ActionServices;
    if (SUCCEEDED(BorlandIDEServices->QueryInterface(__uuidof(IOTAActionServices),
      (void **)&ActionServices)))
      {
        if (Module != NULL)
          ActionServices->ReloadFile(ChangeFileExt(FileName, ".i"));
        else
          ActionServices->OpenFile(ChangeFileExt(FileName, ".i"));
      }
    return;
  }
  int i;
  for (i = 0; i < StdOut->Count; i++)
  {
    AnsiString buffer;
    buffer = StdOut->Strings[i];
    if (NextToken(buffer) == "Error")
    {
      AnsiString ErrorType;
      ErrorType = NextToken(buffer);
      if (ErrorType.Pos(":") != 0)
      {
        _di_IOTAMessageServices MessageServices;
        void *Unused = 0;
        if (SUCCEEDED(BorlandIDEServices->QueryInterface(__uuidof(IOTAMessageServices),
          (void **)&MessageServices)))
          MessageServices->AddToolMessage("", buffer, "Cpp32", 0, 0, NULL, Unused, NULL);
      }
      else
      {
        AnsiString ErrorFile;
        ErrorFile = NextToken(buffer);
        if ((ErrorType.Length() != 0) && (ErrorFile.Length() != 0))
        {
          AnsiString LineString;
          LineString = NextToken(buffer);
          LineString = LineString.SubString(1, LineString.Length() - 1);
          try
          {
            int LineNumber;
            LineNumber = LineString.ToInt();
            _di_IOTAMessageServices MessageServices;
            void *Unused = 0;
            if (SUCCEEDED(BorlandIDEServices->QueryInterface(__uuidof(IOTAMessageServices),
              (void **)&MessageServices)))
            MessageServices->AddToolMessage(ErrorFile, buffer, "Cpp32", LineNumber, 0, NULL, Unused, NULL);
          }
          catch (...)
          {
          }
        }
      }
    }
  }
}

AnsiString __fastcall TPreprocessFilter::GetFilterName(void)
{
  return "PreprocessorFilter";
}

namespace Filters
{
  void __fastcall PACKAGE Register()
  {
    _di_IOTAToolsFilter ToolsFilter;
    if (SUCCEEDED(BorlandIDEServices->QueryInterface(__uuidof(IOTAToolsFilter),
      (void **)&ToolsFilter)))
    {
      PreprocessFilter = new TPreprocessFilter;
      PreprocessFilter->FilterID = ToolsFilter->AddNotifier(PreprocessFilter);
    }
  }
}

