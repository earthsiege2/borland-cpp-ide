//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "GlSkel.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormMain *FormMain;
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
    : TForm(Owner)
{
    Application->OnIdle = IdleLoop;
    size = 50.0f;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::IdleLoop(TObject*, bool& done)
{
    done = false;
    RenderGLScene();
    SwapBuffers(hdc);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::FormCreate(TObject *Sender)
{
    hdc = GetDC(Handle);
    SetPixelFormatDescriptor();
    hrc = wglCreateContext(hdc);
    if(hrc == NULL)
    	ShowMessage(":-)~ hrc == NULL");
    if(wglMakeCurrent(hdc, hrc) == false)
    	ShowMessage("Could not MakeCurrent");
    w = ClientWidth;
    h = ClientHeight;

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    SetupLighting();
    SetupTextures();
    CreateInpriseCorporateLogo();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::SetPixelFormatDescriptor()
{
    PIXELFORMATDESCRIPTOR pfd = {
    	sizeof(PIXELFORMATDESCRIPTOR),
        1,
        PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
        PFD_TYPE_RGBA,
        24,
        0,0,0,0,0,0,
        0,0,
        0,0,0,0,0,
        32,
        0,
        0,
        PFD_MAIN_PLANE,
        0,
        0,0,
    };
    PixelFormat = ChoosePixelFormat(hdc, &pfd);
    SetPixelFormat(hdc, PixelFormat, &pfd);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::FormResize(TObject *Sender)
{

    GLfloat nRange = 50.0;

    w = ClientWidth;
    h = ClientHeight;
    
    if(h == 0)
    	h = 1;

    glViewport(0, 0, w, h);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (w <= h)
        glOrtho (-nRange, nRange, -nRange*h/w, nRange*h/w, -nRange, nRange);
    else
	glOrtho (-nRange*w/h, nRange*w/h, -nRange, nRange, -nRange, nRange);

    //For perspective correction
    //GLfloat aspect = (GLfloat)w/(GLfloat)h;
    //gluPerspective(30.0f, aspect, 1.0, 50.0);


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::RenderGLScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    DrawObjects();
    glFlush();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::DrawObjects()
{
    //GoldCube
    glBindTexture(GL_TEXTURE_2D, texture1);

    //Body
    glPushMatrix();
    glColor3f(0.8f, 0.8f, 0.8f);
    glTranslatef(0.0f, 15.0f, 20.0f);
    glRotatef(90, 1.0, 0.0, 0.0);
    glCallList(startoflist);
    glPopMatrix();

    //Top
    glPushMatrix();
    glDisable(GL_CULL_FACE);
    glColor3f(0.8f, 0.8f, 0.8f);
    glTranslatef(0.0f, 15.0f, 20.0f);
    glRotatef(-90, 1.0, 0.0, 0.0);
    glCallList(startoflist + 1);
    glEnable(GL_CULL_FACE);
    glPopMatrix();

    //Bottom
    glPushMatrix();
    glColor3f(0.8f, 0.8f, 0.8f);
    glTranslatef(0.0f, -10.0f, 20.0f);
    glRotatef(90, 1.0, 0.0, 0.0);
    glCallList(startoflist + 2);
    glPopMatrix();


    //Red Pyramid
    glBindTexture(GL_TEXTURE_2D, texture2);
    //Body
    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(-20.0f, -10.0f, -5.0);
    glRotatef(-90, 1.0, 0.0, 0.0);
    glCallList(startoflist + 3);
    glPopMatrix();

    //Bottom
    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(-20.0f, -10.0f, -5.0);
    glRotatef(90, 1.0, 0.0, 0.0);
    glCallList(startoflist + 4);
    glPopMatrix();

    //Blue Sphere
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture3);
    glColor3f(0.0f, 0.0f, 1.0f);
    glTranslatef(15.0, 5.0f, -7.5f);
    glRotatef(90, 1.0, 0.0, 0.0);
    glRotatef(90, 0.0, 0.0, 1.0);
    glCallList(startoflist + 5);
    glPopMatrix();

    //Ring
    glPushMatrix();
    glDisable(GL_CULL_FACE);
    glRotatef(-90, 1.0, 0.0, 0.0);
    glCallList(startoflist + 6);
    glEnable(GL_CULL_FACE);
    glPopMatrix();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::FormPaint(TObject *Sender)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glFlush();
    DrawObjects();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::FormDestroy(TObject *Sender)
{
    gluDeleteQuadric(GoldCube);
    gluDeleteQuadric(GoldCubeTop);
    gluDeleteQuadric(GoldCubeBottom);
    gluDeleteQuadric(RedPyramid);
    gluDeleteQuadric(RedPyramidBottom);
    gluDeleteQuadric(BlueSphere);
    gluDeleteQuadric(Ring);
    delete bitmap;
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(hrc);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::CreateInpriseCorporateLogo()
{
    startoflist = glGenLists(4);
    DrawGoldCube();
    DrawRedPyramid();
    DrawBlueSphere();
    DrawRing();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::DrawGoldCube()
{
    GoldCube = gluNewQuadric();
    GoldCubeTop = gluNewQuadric();
    GoldCubeBottom = gluNewQuadric();

    glBindTexture(GL_TEXTURE_2D, texture1);
    gluQuadricTexture(GoldCube, GL_TRUE);
    gluQuadricDrawStyle(GoldCube, GLU_FILL);
    gluQuadricNormals(GoldCube, GLU_SMOOTH);

    gluQuadricTexture(GoldCubeTop, GL_TRUE);
    gluQuadricDrawStyle(GoldCubeTop, GLU_FILL);
    gluQuadricNormals(GoldCubeTop, GLU_SMOOTH);

    gluQuadricTexture(GoldCubeBottom, GL_TRUE);
    gluQuadricDrawStyle(GoldCubeBottom, GLU_FILL);
    gluQuadricNormals(GoldCubeBottom, GLU_SMOOTH);

    glNewList(startoflist, GL_COMPILE);
        gluCylinder(GoldCube, 15, 15, 25, 4, 10);
    glEndList();

    glNewList(startoflist + 1, GL_COMPILE);
        gluDisk(GoldCubeTop, 0, 15, 4, 1);
    glEndList();

    glNewList(startoflist + 2, GL_COMPILE);
        gluDisk(GoldCubeBottom, 0, 15, 4, 1);
    glEndList();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::DrawRedPyramid()
{
    RedPyramid = gluNewQuadric();
    RedPyramidBottom = gluNewQuadric();

    glBindTexture(GL_TEXTURE_2D, texture2);
    gluQuadricTexture(RedPyramid, GL_TRUE);
    gluQuadricDrawStyle(RedPyramid, GLU_FILL);
    gluQuadricNormals(RedPyramid, GLU_SMOOTH);

    gluQuadricTexture(RedPyramidBottom, GL_TRUE);
    gluQuadricDrawStyle(RedPyramidBottom, GLU_FILL);
    gluQuadricNormals(RedPyramidBottom, GLU_SMOOTH);

    glNewList(startoflist + 3, GL_COMPILE);
        gluCylinder(RedPyramid, 16, 0, 35, 4, 10);
    glEndList();

    glNewList(startoflist + 4, GL_COMPILE);
        gluCylinder(RedPyramidBottom, 16, 0, 1, 4, 10);
    glEndList();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::DrawBlueSphere()
{
    BlueSphere = gluNewQuadric();

    glBindTexture(GL_TEXTURE_2D, texture3);
    gluQuadricTexture(BlueSphere, GL_TRUE);
    gluQuadricDrawStyle(BlueSphere, GLU_FILL);
    gluQuadricNormals(BlueSphere, GLU_SMOOTH);
    glNewList(startoflist + 5, GL_COMPILE);
        gluSphere(BlueSphere, 15, 25, 25);
    glEndList();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::DrawRing()
{
    Ring = gluNewQuadric();
    glColor3f(1.0f, 1.0f, 1.0f);
    gluQuadricDrawStyle(Ring, GLU_FILL);
    gluQuadricNormals(Ring, GLU_SMOOTH);
    glNewList(startoflist + 6, GL_COMPILE);
        gluDisk(Ring, 24, 25, 50, 50);
    glEndList();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key == VK_UP)
        glRotatef(-5, 1.0, 0.0, 0.0);
    if(Key == VK_DOWN)
        glRotatef(5, 1.0, 0.0, 0.0);
    if(Key == VK_LEFT)
        glRotatef(-5, 0.0, 1.0, 0.0);
    if(Key == VK_RIGHT)
        glRotatef(5, 0.0, 1.0, 0.0);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::SetupLighting()
{
    GLfloat MaterialAmbient[] = {0.5, 0.5, 0.5, 1.0};
    GLfloat MaterialDiffuse[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat MaterialSpecular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat MaterialShininess[] = {50.0};
    GLfloat AmbientLightPosition[] = {0.5, 1.0, 1.0, 0.0};
    GLfloat LightAmbient[] = {0.5, 0.5, 0.5, 1.0};

    glMaterialfv(GL_FRONT, GL_AMBIENT, MaterialAmbient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, MaterialSpecular);
    glMaterialfv(GL_FRONT, GL_SHININESS, MaterialShininess);
    glLightfv(GL_LIGHT0, GL_POSITION, AmbientLightPosition);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, LightAmbient);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glShadeModel(GL_SMOOTH);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::SetupTextures()
{
    bitmap = new Graphics::TBitmap;
    bitmap->LoadFromFile("red.bmp");
    GLubyte bits[64][64][4];
    for(int i = 0; i < 64; i++)
    {
    	for(int j = 0; j < 64; j++)
        {
            bits[i][j][0]= (GLbyte)GetRValue(bitmap->Canvas->Pixels[i][j]);
            bits[i][j][1]= (GLbyte)GetGValue(bitmap->Canvas->Pixels[i][j]);
            bits[i][j][2]= (GLbyte)GetBValue(bitmap->Canvas->Pixels[i][j]);
            bits[i][j][3]= (GLbyte)255;
        }
    }
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 64, 64, 0, GL_RGBA, GL_UNSIGNED_BYTE, bits);

    bitmap->LoadFromFile("gold.bmp");
    for(int i = 0; i < 64; i++)
    {
    	for(int j = 0; j < 64; j++)
        {
            bits[i][j][0]= (GLbyte)GetRValue(bitmap->Canvas->Pixels[i][j]);
            bits[i][j][1]= (GLbyte)GetGValue(bitmap->Canvas->Pixels[i][j]);
            bits[i][j][2]= (GLbyte)GetBValue(bitmap->Canvas->Pixels[i][j]);
            bits[i][j][3]= (GLbyte)255;
        }
    }
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
    glGenTextures(1, &texture2);
    glBindTexture(GL_TEXTURE_2D, texture2);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 64, 64, 0, GL_RGBA, GL_UNSIGNED_BYTE, bits);

    bitmap->LoadFromFile("blue.bmp");
    for(int i = 0; i < 64; i++)
    {
    	for(int j = 0; j < 64; j++)
        {
            bits[i][j][0]= (GLbyte)GetRValue(bitmap->Canvas->Pixels[i][j]);
            bits[i][j][1]= (GLbyte)GetGValue(bitmap->Canvas->Pixels[i][j]);
            bits[i][j][2]= (GLbyte)GetBValue(bitmap->Canvas->Pixels[i][j]);
            bits[i][j][3]= (GLbyte)255;
        }
    }
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
    glGenTextures(1, &texture3);
    glBindTexture(GL_TEXTURE_2D, texture3);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 64, 64, 0, GL_RGBA, GL_UNSIGNED_BYTE, bits);

    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
}
