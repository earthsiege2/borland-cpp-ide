//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("TeeDemo.res");
USEFORM("TeeMain.cpp", TeeMainForm);
USEFORM("TeeBasic.cpp", DemoForm);
USEFORM("Basic.cpp", BasicForm);
USEFORM("specs.cpp", ChartSpecs);
USEFORM("Features.cpp", FeaturesForm);
USEFORM("UColor.cpp", ColoredForm);
USEFORM("UAniZoom.cpp", FormAnimatedZoom);
USEFORM("UBitmap.cpp", BitmapForm);
USEFORM("UDraw.cpp", DrawForm);
USEFORM("UClick.cpp", ClickingForm);
USEFORM("UMain.cpp", MiniForm);
USEFORM("UOverbar.cpp", OverBarForm);
USEFORM("ULegend.cpp", LegendForm);
USEFORM("UAxisLab.cpp", AxisLabelsForm);
USEFORM("UScroll.cpp", ScrollForm);
USEFORM("UShapes.cpp", ShapesForm);
USEFORM("UScrollB.cpp", ScrollBarForm);
USEFORM("LastValu.cpp", DigitalForm);
USEFORM("UCrossH.cpp", CrossHairForm);
USEFORM("UKBoar.cpp", KeyboardForm);
USEFORM("UPrint.cpp", PrintForm);
USEFORM("LogLab.cpp", CustomLabelsForm);
USEFORM("UPages.cpp", PagesForm);
USEFORM("UMetafil.cpp", MetafileForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
        Application->Initialize();
        Application->CreateForm(__classid(TTeeMainForm), &TeeMainForm);
                 Application->Run();
    }
    catch (Exception &exception)
    {
        Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
