
#include <vcl.h>
#pragma hdrstop

#include <ToolsApi.Hpp>

#include "VersionInfoIdeInteraction.h"

#define NDEBUG
#include <cassert>

#pragma package(smart_init)

IOTAProjectGroup* GetProjectGroup(const _di_IOTAModuleServices& IModuleServices)
{
  IOTAProjectGroup* Result;

  _di_IOTAModule IModule;
  int ModuleCount;

  Result = NULL;

  assert(IModuleServices != NULL);
  ModuleCount = IModuleServices->GetModuleCount();

  for (int i = 0; i < ModuleCount; ++i)
  {
    IModule = IModuleServices->GetModule(i);
    assert(IModule != NULL);

    if (Supports( IModule, __uuidof(IOTAProjectGroup),
                  &static_cast<void*>(Result) ))
    {
      break;
    }
    else
    {
      Result = NULL;
    }
  }

  assert(Result != NULL);
  return Result;
}

bool __fastcall ConfirmInclusionOfVersionInfo(void)
{
  bool Result;

  Result = (MessageDlg( "Currently version information data is not included " \
                        "into your compiled binary.\n" \
                        "\n" \
                        "Do you enable inclusion of this into the binary?",
                        mtConfirmation,
                        TMsgDlgButtons() << mbYes << mbNo,
                        0 ) == mrYes);

  return Result;
}

void __fastcall EnableVersionInfoInIDE(void)
{
  const AnsiString IncludeVersionInfoSetting = "IncludeVersionInfo";

  void* TemporaryIntf;

  _di_IOTAModuleServices IModuleServices;

  _di_IOTAProjectGroup IProjectGroup;
  _di_IOTAProject IProject;
  _di_IOTAProjectOptions IProjectOptions;

  bool VersionInfoInProject;

  if (Supports( BorlandIDEServices, __uuidof(IOTAModuleServices),
                &TemporaryIntf ))
  {
    IModuleServices = static_cast<IOTAModuleServices*>(TemporaryIntf);

    IProjectGroup = GetProjectGroup(IModuleServices);

    IProject = IProjectGroup->GetActiveProject();
    assert(IProject != NULL);

    IProjectOptions = IProject->GetProjectOptions();
    assert(IProjectOptions != NULL);

    VersionInfoInProject = IProjectOptions->GetOptionValue(IncludeVersionInfoSetting);
    if (!VersionInfoInProject)
    {
      if (ConfirmInclusionOfVersionInfo())
        IProjectOptions->SetOptionValue(IncludeVersionInfoSetting, true);
    }
  }

}

