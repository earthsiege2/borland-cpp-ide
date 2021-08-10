
//---------------------------------------------------------------------------

#ifndef UploadPicturesPgH
#define UploadPicturesPgH
//---------------------------------------------------------------------------
#include <WebInit.h>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <WebModu.hpp>
#include <HTTPProd.hpp>
#include <HTTPApp.hpp>
#include <WebAdapt.hpp>
#include <WebComp.hpp>

//---------------------------------------------------------------------------
class TUploadPicturesPage : public TWebPageModule
{
__published:	// IDE-managed Components
	TPageProducer *PageProducer;
  TAdapter *UploadAdapter;
  TAdapterAction *Upload;
  TAdapterFileField *UploadFile;
  TAdapterField *Title;
  TAdapterMemoField *Description;
  TAdapterField *Category;
  TStringsValuesList *UploadedFiles;
  void __fastcall UploadFileUploadFiles(TObject *Sender,
          TUpdateFileList *Files);
  void __fastcall UploadAdapterBeforeExecuteAction(TObject *Sender,
          TObject *Action, TStrings *Params, bool &Handled);
  void __fastcall UploadExecute(TObject *Sender, TStrings *Params);
  void __fastcall WebPageModuleActivate(TObject *Sender);
private:	// User declarations

public:		// User declarations
};

TUploadPicturesPage *UploadPicturesPage();

//---------------------------------------------------------------------------
extern PACKAGE TUploadPicturesPage *UploadPicturesPage();
//---------------------------------------------------------------------------
#endif

