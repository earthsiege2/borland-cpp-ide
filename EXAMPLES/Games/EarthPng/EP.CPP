//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "EP.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormMain *FormMain;
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
	: TForm(Owner)
{
    //Assign idle time function
    Application->OnIdle = IdleLoop;

    if(Application->MessageBox("Would you like to play with Earth?", "Hello Earthling", MB_OKCANCEL) == IDOK)
    {
        //load sound effect
        sndPlaySound("Utopia Default.wav", SND_ASYNC | SND_FILENAME);
      	x = 0;
        y = 0;
        GameOver = false;
	ShowCursor(false);
        
    }
    else
        Application->Terminate();

}
//---------------------------------------------------------------------------


void __fastcall TFormMain::IdleLoop(TObject*, bool &done)
{
    //keeps loop going
 	done = false;
    //slows down action
    ::Sleep(1);

    changeRect = spriteRect;
    spriteRect.Left = x;
    spriteRect.Top = y;
    spriteRect.Right = x + spriteImage->Picture->Width;
    spriteRect.Bottom = y + spriteImage->Picture->Height;

    workCanvas->CopyRect(paddleRect, backgroundCanvas, paddleRect);

    changePaddleRect = paddleRect;
    paddleRect.Left = paddleCenter - ((paddle->Picture->Width)/2);
    paddleX = paddleRect.Left;
    paddleRect.Top = paddleY;
    paddleRect.Right = paddleX + paddle->Picture->Width;
    paddleRect.Bottom = paddleY + paddle->Picture->Height;

	{
    	int SideDef = changeRect.Left - spriteRect.Left;
	    // If SideDiff < 0 the paddle is to the right
	    if(SideDef < 0) {
	    	changeRect.Right = spriteRect.Right;
	    }
	    else {
	    	changeRect.Left = spriteRect.Left;
	    }

	    int TopDef = changeRect.Top - spriteRect.Top;
	    // If SideDiff < 0 the paddle is to the Down
	    if(TopDef < 0) {
	    	changeRect.Bottom = spriteRect.Bottom;
	    }
	    else {
	    	changeRect.Top = spriteRect.Top;
	    }
    }

    workCanvas->CopyRect(spriteRect, backgroundCanvas, spriteRect);


    //ChangeRectCalcs
    if (y <= 0)
    {
    	yDir = 5;
    }
    if (y >= ClientHeight - 16)
    {
        GameOver = true;
        ::SetCursor((HCURSOR)IDC_ARROW);
        ShowCursor(true);
        int choice = MessageBox(Handle, "You lost Earth", "Try Again?", MB_RETRYCANCEL);
        if(choice == IDRETRY)
        {
            x = 0;
            y = 0;
            ShowCursor(false);

        }
        else
            Close();
    }

    if ((spriteRect.Bottom - 16) >= (paddleRect.Top) &&
    		(spriteRect.Bottom - 16) <= (paddleRect.Top + 5) &&
        		(spriteRect.Right) >= (paddleRect.Left) &&
    	        	(spriteRect.Left) <= (paddleRect.Right))
    {
        yDir = -5;
        sndPlaySound("Utopia Default.wav", SND_ASYNC | SND_FILENAME);
    }

    if (x <= 0)
    {
    	xDir = 5;
    }

    if(x >= ClientWidth - 16)
    {
    	xDir = -5;
    }

    x += xDir;
    y += yDir;

    int PaddleDifference = changePaddleRect.Left - paddleRect.Left;
    // If PaddleDiff < 0 the paddle is to the right
    if(PaddleDifference < 0) {
    	changePaddleRect.Right = paddleRect.Right;
    }
    else {
		changePaddleRect.Left = paddleRect.Left;
    }

    //Perform dirty rectangle animation on memory and Form canvas
    workCanvas->Draw(x, y, spriteImage->Picture->Icon);
    workCanvas->Draw(paddleX, paddleY, paddle->Picture->Icon);
    RealizePalette(backgroundCanvas->Handle);
    RealizePalette(workCanvas->Handle);
    Canvas->CopyRect(changeRect, workCanvas, changeRect);
    Canvas->CopyRect(changePaddleRect, workCanvas, changePaddleRect);
}

//---------------------------------------------------------------------------
void __fastcall TFormMain::FormPaint(TObject *Sender)
{
	RealizePalette(backgroundCanvas->Handle);
    RealizePalette(workCanvas->Handle);
    Canvas->CopyRect(backgroundRect, workCanvas, backgroundRect);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::FormActivate(TObject *Sender)
{
	backgroundImage = new TImage(Owner);
    spriteImage = new TImage(Owner);
    paddle = new TImage(Owner);
    workCanvas = new TCanvas;
    backgroundCanvas = new TCanvas;

    Angle = 1;

    spriteImage->
    	Picture->LoadFromFile("Earth.ico");
    backgroundImage->
        Picture->LoadFromFile("androm.bmp");
	paddle->
    	Picture->LoadFromFile("paddle.ico");

    WindowState = wsMaximized;

    backgroundRect.Top = 0;
	backgroundRect.Left = 0;
    backgroundRect.Right =  ClientWidth;
    backgroundRect.Bottom =  ClientHeight;


    spriteRect.Top = 0;
    spriteRect.Left = 0;
    spriteRect.Right = spriteImage->Picture->Width;
    spriteRect.Bottom = spriteImage->Picture->Height;

    //Set up backgroundCanvas
    HDC backgrounddc = CreateCompatibleDC(Canvas->Handle);
    HBITMAP  bkbmp = CreateCompatibleBitmap(Canvas->Handle, ClientWidth, ClientHeight);
    SelectObject(backgrounddc, bkbmp);
    SelectPalette(backgrounddc, backgroundImage->Picture->Bitmap->Palette, false);
    backgroundCanvas->Handle = backgrounddc;
    backgroundCanvas->StretchDraw( backgroundRect, backgroundImage->Picture->Bitmap);


    //Set up workCanvas
    HDC workdc = CreateCompatibleDC(Canvas->Handle);
    HBITMAP  bmp = CreateCompatibleBitmap(Canvas->Handle, ClientWidth, ClientHeight);
    SelectObject(workdc, bmp);
    SelectPalette(workdc, backgroundImage->Picture->Bitmap->Palette, false);
    workCanvas->Handle = workdc;
    workCanvas->CopyRect(backgroundRect,  backgroundCanvas, backgroundRect);
    workCanvas->Draw( 0, 0, spriteImage->Picture->Icon);
    paddleX = ClientWidth / 2;
    paddleY = ClientHeight - 50;
    workCanvas->Draw( paddleX, paddleY, paddle->Picture->Icon);

	paddleRect.Left = paddleX - paddle->Width;
    paddleRect.Right = paddleX + paddle->Width;
    paddleRect.Top	= paddleY;
    paddleRect.Bottom = paddleY + paddle->Height;


    RealizePalette(backgroundCanvas->Handle);
    RealizePalette(workCanvas->Handle);
    Canvas->CopyRect(backgroundRect, workCanvas, backgroundRect);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::FormMouseMove(TObject *Sender, TShiftState Shift, int X,
	int Y)
{
    //Animates and moves paddle
    paddleCenter = X;
    if(paddleCenter < paddle->Picture->Width/2)
    	paddleCenter = paddle->Picture->Width/2;
    if(paddleCenter > ClientWidth - (paddle->Picture->Width/2))
    	paddleCenter = ClientWidth - (paddle->Picture->Width/2);
}

void __fastcall TFormMain::SetCursor(TMessage &) {
	//Hides Cursor
        if(!GameOver)
        {
	::SetCursor(NULL);
        }
}
//---------------------------------------------------------------------------

