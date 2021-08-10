//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "DataMod.h"
#include <WebReq.hpp>
#include <WebCntxt.hpp>
#include <WebFact.hpp>
#include <WebInit.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TBioDataModule *BioDataModule()
{
  return (TBioDataModule*)WebContext()->FindModuleClass(__classid (TBioDataModule));
}

static TWebDataModuleInit WebInit(__classid(TBioDataModule),
  crOnDemand, caCache);

//---------------------------------------------------------------------------



