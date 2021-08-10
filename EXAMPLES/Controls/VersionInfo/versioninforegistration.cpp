
#include <vcl.h>
#pragma hdrstop

#include <TypInfo.hpp>

#include "VersionInfoComponent.h"
#include "VersionInfoUI.h"
#include "VersionInfoDesignTimeCode.h"
#include "VersionInfoIdeInteraction.h"
#include "VersionInfoRegistration.h"

#define NDEBUG
#include <cassert>

#pragma package(smart_init)

//---------------------------------------------------------------------------

PTypeInfo AnsiStringTypeInfo(void)
{
  PPTypeInfo Temp;

  Temp = GetPropInfo(__typeinfo(TVersionInfo), "FileName")->PropType;
  assert(Temp != NULL);

  return *Temp;
}

//---------------------------------------------------------------------------

PTypeInfo TDateTimeTypeInfo(void)
{
  PPTypeInfo Temp;

  Temp = GetPropInfo(__typeinfo(TVersionInfo), "FileDate")->PropType;
  assert(Temp != NULL);

  return *Temp;
}

//---------------------------------------------------------------------------

PTypeInfo intTypeInfo(void)
{
  PPTypeInfo Temp;

  Temp = GetPropInfo(__typeinfo(TVersionInfo), "LanguageCharsetIndex")->PropType;
  assert(Temp != NULL);

  return *Temp;
}

//---------------------------------------------------------------------------
// Registration code for design-time interaction
//

namespace Versioninforegistration
{
  void __fastcall PACKAGE Register(void)
  {
    const AnsiString ComponentPaletteLocation = "VersionInfo";
    //
    // Register the components on the component palette
    //
    const int NumberCoreClasses = 1;
    TComponentClass CoreClass[NumberCoreClasses] = { __classid(TVersionInfo) };
    RegisterComponents(ComponentPaletteLocation, CoreClass, NumberCoreClasses - 1);

    const int NumberUIClasses = 12;
    TComponentClass UIClasses[NumberUIClasses] = { __classid(TVersionInfoGenericLabel),

                                                   __classid(TVersionInfoCompanyNameLabel),
                                                   __classid(TVersionInfoCommentsLabel),
                                                   __classid(TVersionInfoFileDescriptionLabel),
                                                   __classid(TVersionInfoFileVersionLabel),
                                                   __classid(TVersionInfoFileVersionLabel),
                                                   __classid(TVersionInfoInternalNameLabel),
                                                   __classid(TVersionInfoLegalCopyrightLabel),
                                                   __classid(TVersionInfoLegalTrademarksLabel),
                                                   __classid(TVersionInfoOriginalFileNameLabel),
                                                   __classid(TVersionInfoProductNameLabel),
                                                   __classid(TVersionInfoProductVersionLabel)
                                                 };
    RegisterComponents(ComponentPaletteLocation, UIClasses, NumberUIClasses - 1);

    //
    // Register an AnsiString property editor for the FileName property
    //
    RegisterPropertyEditor( AnsiStringTypeInfo(), __classid(TVersionInfo),
                            "FileName", __classid(TVersionInfoFileNameEditor) );

    //
    // Register a TDateTime property editor for the FileDate property
    // This property editor will only change the display of the property.
    //
    RegisterPropertyEditor( TDateTimeTypeInfo(), __classid(TVersionInfo),
                            "FileDate", __classid(TVersionInfoFileDateEditor) );

    //
    // Register a TStrings property editor for the Translations property
    // This property editor will allow the user to actually see all available
    // translation at design-time rendered in a readable manner
    //
    RegisterPropertyEditor( intTypeInfo(), __classid(TVersionInfo),
                            "LanguageCharsetIndex", __classid(TVersionInfoLanguageCharsetIndexEditor) );

    //
    // Register a bool property editor for the Enabled property
    // This property editor's duty will only be to call "Modified"
    // on the component to refresh the design-time representation.
    //

    //
    // Register a component editor (for double-clicking on the component)
    //
    RegisterComponentEditor( __classid(TVersionInfo),
                             __classid(TVersionInfoComponentEditor) );

    //
    // Install design-time hook for enabling VERSIONINFO resources
    // in the IDE via the Open Tools API interface.
    //
    #if 0
      // This code is currently disabled, since
      // enabling the Version Information does
      // not work from design-time code.
      DesignTimeHook = EnableVersionInfoInIDE;
    #endif
  }
}
