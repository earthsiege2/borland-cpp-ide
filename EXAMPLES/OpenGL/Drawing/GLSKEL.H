//---------------------------------------------------------------------------
#ifndef GlSkelH
#define GlSkelH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <gl\gl.h>
#include <gl\glu.h>
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Componentsvoid __fastcall FormCreate(TObject *Sender);
    void __fastcall FormResize(TObject *Sender);
    void __fastcall FormPaint(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
    HDC hdc;
    HGLRC hrc;
    int PixelFormat;
    GLuint startoflist;
    GLfloat x, y, xstep, ystep, w, h;
    GLsizei size;
    GLuint texture1, texture2, texture3;
    GLUquadricObj* GoldCube, *GoldCubeTop, *GoldCubeBottom,
                    *RedPyramid, *RedPyramidBottom, *BlueSphere, *Ring;
    Graphics::TBitmap* bitmap;
public:		// User declarations
    __fastcall TFormMain(TComponent* Owner);
    void __fastcall IdleLoop(TObject*, bool&);
    void __fastcall RenderGLScene();
    void __fastcall SetPixelFormatDescriptor();
    void __fastcall DrawObjects();
    void __fastcall CreateInpriseCorporateLogo();
    void __fastcall DrawGoldCube();
    void __fastcall DrawRedPyramid();
    void __fastcall DrawBlueSphere();
    void __fastcall DrawRing();
    void __fastcall SetupLighting();
    void __fastcall SetupTextures();


};
//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
