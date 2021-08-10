//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("Shape.res");
USEFORM("ShapeMain.cpp", ShapeForm);
USEFILE("readme.txt");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TShapeForm), &ShapeForm);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
