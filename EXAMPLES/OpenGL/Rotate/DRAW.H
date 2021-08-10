//---------------------------------------------------------------------------
#ifndef drawH
#define drawH
//---------------------------------------------------------------------------
#include <vcl\Classes.hpp>
#include <vcl\Controls.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\ExtCtrls.hpp>
#include <GL/gl.h>
#include <GL/glu.h>

//---------------------------------------------------------------------------

#define BLACK_INDEX     0
#define RED_INDEX       13
#define GREEN_INDEX     14
#define BLUE_INDEX      16

#define GLOBE    1
#define CYLINDER 2
#define CONE     3

//---------------------------------------------------------------------------
class TOpenGL_Form : public TForm
{
__published:	// IDE-managed Components
	TTimer *Timer1;
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
private:	// User declarations
	void DrawScene();
    void polarView(GLdouble radius, GLdouble twist, GLdouble latitude,
           		   GLdouble longitude);
    GLvoid initializeGL(GLsizei width, GLsizei height);
    GLvoid createObjects();
    GLvoid resize( GLsizei width, GLsizei height );
    GLfloat latitude, longitude, latinc, longinc;
    GLdouble radius;
    HGLRC ghRC;
    HDC   ghDC;

public:		// User declarations
	__fastcall TOpenGL_Form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TOpenGL_Form *OpenGL_Form;
//---------------------------------------------------------------------------
#endif
