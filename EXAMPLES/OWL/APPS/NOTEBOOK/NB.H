//----------------------------------------------------------------------------
//    nb.h - include file for nb.cpp file
//----------------------------------------------------------------------------
//    copyright (c) 1993 Borland International
//----------------------------------------------------------------------------
#define MID_TOP         1025
#define MID_RIGHT       1026
#define MID_BOTTOM      1027
#define MID_LEFT        1028
#define MID_EXIT         199

#define MID_CASCADE     1001
#define MID_TILEH       1003
#define MID_TILEV       1002
#define MID_ARRANGE     1005
//----------------------------------------------------------------------------
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#define min(a,b)            (((a) < (b)) ? (a) : (b))
//----------------------------------------------------------------------------
class TMyNotebook: public TMDIChild, TNotebook
{
  public:
    TMyNotebook(TMDIClient& parent, const char far* title = 0, int tabloc = 0);
    void ActivateTab(int tabnum);
    virtual void Paint(TDC& dc, bool erase, TRect& rect);
    void EvSize(UINT sizeType, TSize& newsize);
    void EvHScroll(UINT scrollCode, UINT thumbPos, HWND hWndCtl);
    void EvVScroll(UINT scrollCode, UINT thumbPos, HWND hWndCtl);
    //------------------------------------------------------------------
    char textbuff[100];
    int maxhs;
    int curhs;
    int maxxval;
    int maxyval;
    int maxvs;
    int curvs;
    BOOL myresizing;
    //------------------------------------------------------------------
    DECLARE_RESPONSE_TABLE(TMyNotebook);
};
//----------------------------------------------------------------------------
class TNBClient : public TMDIClient
{
  public:
    TNBClient(TModule* module = 0);
    //------------------------------------------------------------------
    void CmdExit();
    void NewWin(WPARAM cmd);
    void CmdCascade();
    void CmdTileH();
    void CmdTileV();
    void CmdArrange();
    //------------------------------------------------------------------
    DECLARE_RESPONSE_TABLE(TNBClient);
};
//----------------------------------------------------------------------------
class TTestApp : public TApplication
{
  public:
    //--- redefined functions ---
    TTestApp();
    void InitMainWindow();
    void InitInstance();
    TNBClient *Client;
};
//----------------------------------------------------------------------------
