//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//----------------------------------------------------------------------------
#ifndef INFO_H
#define INFO_H

#ifndef OWL_STATIC_H
# include <owl/static.h>
#endif
class _OWLCLASS TDC;

class TNoEraseBkGndStatic : public TStatic {
  public:
    TNoEraseBkGndStatic(TWindow* parent, int id, const char* title, int x,
                        int y, int w, int h, WORD textLen);

    BOOL EvEraseBkGnd(HDC);

    void SetErase() {DoErase = TRUE;}
    void SetText(const char* text);

  private:
    BOOL DoErase;
    int LastLen;

  DECLARE_RESPONSE_TABLE(TNoEraseBkGndStatic);
};

class TInfoWindow : public TWindow {
  public:
    TInfoWindow(TWindow* parent, const char* title);

    void SetTurnText(const char* text)      {Color->SetText(text);}
    void SetWhiteInfoText(const char* text) {WhiteInfo->SetText(text);}
    void SetBlackInfoText(const char* text) {BlackInfo->SetText(text);}
    void SetTimerText(const char* text)     {Timer->SetText(text);}
    void SetLevelText(const char* text)     {Level->SetText(text);}
    void SetIterationText(const char* text) {Iteration->SetText(text);}
    void SetValueText(const char* text)     {Value->SetText(text);}
    void SetNodeText(const char* text)      {Nodes->SetText(text);}
    void SetSecondsText(const char* text)   {Seconds->SetText(text);}
    void SetDepthText(const char* text)     {Depth->SetText(text);}
    void SetBestLineText(const char* text)  {BestLine->SetText(text);}
    void SetMessageText(const char* text)   {Message->SetText(text);}

    void   EvPaint();
    HBRUSH EvCtlColor(HDC hDC, HWND hWndChild, UINT ctlType);
    void   Reset();
    void   IterReset();

  private:
    TStatic* Color;
    TStatic* WhiteInfo;
    TStatic* BlackInfo;
    TNoEraseBkGndStatic* Timer;
    TStatic* Level;
    TStatic* Iteration;
    TStatic* Value;
    TStatic* Nodes;
    TStatic* Seconds;
    TNoEraseBkGndStatic* Depth;
    TStatic* BestLine;
    TStatic* Message;
    TRect    InfoRect;

    void     DrawSFrame(TDC&, TRect&);
    void     DrawStaticFrames(TDC&);
    void     DrawInfoFrame(TDC& dc);

  DECLARE_RESPONSE_TABLE(TInfoWindow);
};

#endif  // INFO_H
