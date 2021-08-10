//---------------------------------------------------------------------------

#ifndef MainPgH
#define MainPgH
//---------------------------------------------------------------------------
#include <WebInit.h>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <WebModu.hpp>
#include <HTTPProd.hpp>
#include <ReqMulti.hpp>
#include <HTTPApp.hpp>
#include <WebAdapt.hpp>
#include <WebComp.hpp>
#include <WebDisp.hpp>
#include <Jpeg.hpp>

//---------------------------------------------------------------------------
class TMainPage : public TWebAppPageModule
{
__published:	// IDE-managed Components
	TPageProducer *PageProducer;
	TWebAppComponents *WebAppComponents;
	TApplicationAdapter *ApplicationAdapter;
	TPageDispatcher *PageDispatcher;
	TAdapterDispatcher *AdapterDispatcher;
  TAdapter *Adapter1;
  TAdapterImageField *ImageData;
  TAdapterField *ImageWidth;
  TAdapterField *ImageHeight;
  void __fastcall ImageDataGetImage(TObject *Sender,
          TStrings *Params, AnsiString &MimeType, TStream *&Image,
          bool &Owned);
  void __fastcall WebAppPageModuleCreate(TObject *Sender);
  void __fastcall WebAppPageModuleDestroy(TObject *Sender);
  void __fastcall ImageWidthGetValue(TObject *Sender, Variant &Value);
  void __fastcall ImageHeightGetValue(TObject *Sender, Variant &Value);
private:	// User declarations
  TJPEGImage *m_pjpgImage;
public:		// User declarations
};

TMainPage *MainPage();

//---------------------------------------------------------------------------
extern PACKAGE TMainPage *MainPage();
//---------------------------------------------------------------------------
#endif

