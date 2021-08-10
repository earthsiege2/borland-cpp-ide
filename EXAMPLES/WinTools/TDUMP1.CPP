//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 2000-2002 Borland Corporation. All Rights Reserved.
//----------------------------------------------------------------------------
//------------------------------------------------------------
#define NO_WIN32_LEAN_AND_MEAN

#pragma hdrstop
#include <sys\stat.h>
#include <WindowsX.h>
#include <registry.hpp>
#include <io.h>
#include <assert.h>

#include "TDump1.h"
#include "about.h"

#pragma resource "*.dfm"

TMainForm *MainForm;
//------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
    GetRegInfo();
    BinPth = "PATH=" + BCBRoot + "bin";
    LibPth = BCBRoot + "lib";
    IncPth = BCBRoot + "include";
    ObjPth = BCBRoot + "lib\\obj";

    //Initialize globals
    AppCaption = "BCB Command Line Tools : ";
    Application->Title = "BCB WinTools";
    Application->Icon->LoadFromFile(WintoolsDir + "WinTools.ico");
    //OutFileMi->Checked = true;
	SourceFileSelected = false;
    ObjList = new TStringList();
    Clear = false;
    IsDirty = false;
    BCC32 = true;
    CmdStrRE->Text = "BCC32";
    FilterStr = "*.c;*.cpp";
    MainForm->Caption = AppCaption + "Borland 32bit C++ Compiler";
    WorkDir = "C:\\";
}
//------------------------------------------------------------

void TMainForm::GetRegInfo()
{
    const String RegKey = "\\software\\borland\\C++Builder\\5.0";
    TRegistry *MyRegistry = new TRegistry();
    MyRegistry->RootKey = HKEY_LOCAL_MACHINE;
    try {
        if(MyRegistry->OpenKey(RegKey, false)) {
            BCBRoot = MyRegistry->ReadString("RootDir");
            if (!BCBRoot.IsEmpty()) {
                BCBRoot = BCBRoot + "\\";
                WintoolsDir = BCBRoot + "examples\\wintools\\";
            }
            else ShowMessage("Registry RootDir error");
        MyRegistry->CloseKey();
        }
    }
    catch(ERegistryException &E) {
    	ShowMessage(E.Message);
        delete MyRegistry;
        return;
    }
    delete MyRegistry;
}

void TMainForm::SetEnvPath()
{
    String TempPath = "";
    String RawPath;
    String TotPath = "";
    TStringList *PathList = new TStringList();
    PathList->LoadFromFile(WintoolsDir + "Path.txt");
    for (int n = 0; n < PathList->Count; n++) {
        RawPath = "";
        RawPath = PathList->Strings[n];
        if (RawPath.Pos("$(BCB)")) {
            RawPath.Delete(1, 7);
            TempPath = TempPath + BCBRoot + RawPath + ";";
        }
        else  TempPath = TempPath + RawPath + ";";
    }
    TotPath = "PATH=" + TempPath + WorkDir;
    putenv(TotPath.c_str());
}

void __fastcall TMainForm::ClearClick(TObject *Sender)
{

    Closeall1Click(Sender);
    ClearCtls();

    // Reset globals
	IsDirty = false;
    ResetTools();
    SourceFileSelected = false;
    Clear = false;
    DefExt = "";
    OptionString = "";
    SourceFileDir = "";
    StripExt = "";
    ODFileName = "";
    NewDestEdit = "";
    NewSourceEdit = "";
    CmdStrRE->Text = "";
    ObjList->Clear();

    // Reset to BCC32
    PageCtl->ActivePage = PageCtl->Pages[0];
    DestEd = ".txt";
    RunBtn->Enabled = false;
    BCC32 = true;
    CmdStrRE->Text = "BCC32";
    MainForm->Caption = AppCaption + "Borland 32bit C++ Compiler";

    // Set richedit
    ResultsRE->Lines->Clear();
    BackBtnClick(Sender);
    CmdStrRE->SelStart = 0;
    CmdStrRE->SelLength = CmdStrRE->Text.Length();
    CmdStrRE->SelAttributes->Color = clBlack;
    CmdStrRE->SelStart = 0;

}
//------------------------------------------------------------

void TMainForm::ResetTools()
{
    // Set all tools to a non-selected state
    TDump = false;
    TLib = false;
    ImpDef = false;
    ImpLib = false;
    BCC32 = false;
    ILink32 = false;
    TLink32 = false;
    Make = false;
    BRCC32 = false;
    CPP32 = false;
    TDStrp32 = false;
    Grep = false;
    Touch = false;
    Coff = false;
    Convert = false;
    TRegAX = false;
    TlbImp = false;
    Tasm = false;
}

void __fastcall TMainForm::ClearCtls()
{
    // Initialize stuff
    Clear = true;
    if (Grep) CmdStrRE->Text = PageCtl->ActivePage->Caption +
    													 " -";
    else
    	CmdStrRE->Text = PageCtl->ActivePage->Caption + " ";


    ResultsRE->Lines->Clear();
    PosFound = 0;
    ResultPnl->Hide();
    // reset option checkboxes
    TPcb3->Checked = false;
    TPcb4->Checked = false;
    TPcb5->Checked = false;
    TPcb6->Checked = false;
    TPcb7->Checked = false;
    TPcb8->Checked = false;
    TPcb9->Checked = false;
    TLcb4->Checked = false;
    TLcb5->Checked = false;
    TLcb6->Checked = false;
    TLcb7->Checked = false;
    TLcb8->Checked = false;
    TLcb9->Checked = false;

    TPcb3->Font->Color = clBlack;
    TPcb4->Font->Color = clBlack;
    TPcb5->Font->Color = clBlack;
    TPcb6->Font->Color = clBlack;
    TPcb7->Font->Color = clBlack;
    TPcb8->Font->Color = clBlack;
    TPcb9->Font->Color = clBlack;
    TLcb4->Font->Color = clBlack;
    TLcb5->Font->Color = clBlack;
    TLcb6->Font->Color = clBlack;
    TLcb7->Font->Color = clBlack;
    TLcb8->Font->Color = clBlack;
    TLcb9->Font->Color = clBlack;


    // reset checkbox controls and font
    if (ObjList->Count) {
        TCheckBox *CB;
    	for (int indx = 0; indx < ObjList->Count; indx++) {
        	CB = (TCheckBox *) ObjList->Objects[indx];
        	CB->Checked = false;
        	CB->Font->Color = clBlack;
        }
    }
    ObjList->Clear();
    OptionString = "";
    Clear = false;
}
//------------------------------------------------------------

void TMainForm::PrepareCmdLine()
{
   if (GetFileSize(ODFileName) > 2000000) {
    	ShowMessage("File is too large to process. Use dos prompt!");
        ClearClick(DummySender);
        return;
    }
    int FirstIndex;

    // Handle options selected if any
    if (ObjList->Count) {
    	TCheckBox *CB;
    	for (int indx = 0; indx < ObjList->Count; indx++) {
        	CB = (TCheckBox *) ObjList->Objects[indx];
            FirstIndex = ObjList->IndexOfObject(ObjList->
            								Objects[indx]);
            if (FirstIndex >= indx) {
            	if (Grep) {
            		if (CB->Checked) OptionString = OptionString
                 							 + CB->Caption;
            	}
            	else
        			if (CB->Checked) OptionString = OptionString
                						 + " " + CB->Caption;
            }
        }
    }

    // Prepare command line String for all tools
    const String Cmd = CmdStrRE->Text;
    const String Source = "\"" + ODFileName +"\"";
    const String Dest = "\"" + DestEd + "\"";
    const String Combine = Cmd + OptionString + " ";
    const String Combine2 = Source + " ";

    if (TDump || Make || BRCC32 || TDStrp32 || Touch ||TRegAX || Tasm32)
    			 CmdStrRE->Text = Combine + Source;

    if (BCC32 || CPP32)
    	CmdStrRE->Text = Combine + Source;

    if (ILink32 || TLink32) {
    	CmdStrRE->Text = Combine + Source;
        if (IKcb5->Checked || TKcb5->Checked)   // console app
        	CmdStrRE->Text = Combine + "\"" + LibPth +
             "\\c0x32.obj\" " + Source;
        if (IKcb20->Checked || TKcb24->Checked) // win dll
        	CmdStrRE->Text = Combine + "\"" + LibPth +
             "\\c0d32.obj\" " + Source;
        if (IKcb21->Checked || TKcb25->Checked) // win exe
        	CmdStrRE->Text = Combine + "\"" + LibPth +
             "\\c0w32.obj\" " + "\"" + LibPth +
             "\\import32.lib\" " + "\"" + LibPth +
             "\\cw32mt.lib\" " + Source;
    }

    if (ImpLib) {
    	String SubFn;
        String MultiSource = OpenDlg->Files->Count?OpenDlg->Files->Strings[0]:String("");
        if (OpenDlg->Files->Count > 1)
            SubFn = StripFileExt(MultiSource) + ".lib\"";
        else SubFn = StripFileExt(Source) + ".lib\"";
    	CmdStrRE->Text = Combine + SubFn + " " + Source;
    }

    if (ImpDef) {
        DefExt = StripFileExt(Source) + ".def\"";
    	CmdStrRE->Text = Combine + DefExt + " " + Source;
    }
    if (Grep) {
        if (!GPcb1->Checked)
    	CmdStrRE->Text = Cmd + OptionString + " " +
        	Dest + " " + "\"" + ODFileName + "\\*.*\"";
        else
        	CmdStrRE->Text = Cmd + OptionString + " " +
    									 Dest + " " + Source;
    }

    if (TDump || TLib) OutFileMi->Enabled = true;
    else OutFileMi->Enabled = false;

    if (TDump && (OutFileMi->Checked)) CmdStrRE->Text =
    							 CmdStrRE->Text + " " + Dest;

    if (Convert) {
        CmdStrRE->Text =  CmdStrRE->Text + OpenDlg->FileName;
        SetCurrentDir(BCBRoot + "bin");
    }

    if (TlbImp) {
    	bool a = TPcb3->Checked;
   		bool b = TPcb4->Checked;
    	bool c = TPcb5->Checked;
    	bool d = TPcb6->Checked;
    	bool e = TPcb7->Checked;
    	bool f = TPcb8->Checked;
        bool g = TPcb9->Checked;
    	LibOps = "";
        if (a) LibOps = LibOps + " " + TPcb3->Caption;
        if (b) LibOps = LibOps + " " + TPcb4->Caption;
        if (c) LibOps = LibOps + " " + TPcb5->Caption;
        if (d) LibOps = LibOps + " " + TPcb6->Caption;
        if (e) LibOps = LibOps + " " + TPcb7->Caption;
        if (f) LibOps = LibOps + " " + TPcb8->Caption;
        if (g) LibOps = LibOps + " " + TPcb9->Caption;
    }
    if (TLib) {
    	bool a = TLcb4->Checked;
   		bool b = TLcb5->Checked;
    	bool c = TLcb6->Checked;
    	bool d = TLcb7->Checked;
    	bool e = TLcb8->Checked;
    	bool f = TLcb9->Checked;
    	LibOps = "";
        if (a) LibOps = LibOps + " " + TLcb4->Caption;
        if (b) LibOps = LibOps + " " + TLcb5->Caption;
        if (c) LibOps = LibOps + " " + TLcb6->Caption;
        if (d) LibOps = LibOps + " " + TLcb7->Caption;
        if (e) LibOps = LibOps + " " + TLcb8->Caption;
        if (f) LibOps = LibOps + " " + "&";
    }
    if (Coff) {
        DefExt = StripFileExt(Source) + "OMF.lib\"";
    	CmdStrRE->Text = Combine + Source + " " + DefExt;
    }

    if ((TLib || TlbImp) && (OutFileMi->Checked)) CmdStrRE->Text =
    			Combine + Combine2 + LibOps + "," + Dest;
    if ((TLib || TlbImp) && (!OutFileMi->Checked))CmdStrRE->Text =
    						Combine + Combine2 + LibOps;

    // Setup color red for word found
    CHARFORMAT SelectWordFmat;
    memset(&SelectWordFmat, 0, sizeof(CHARFORMAT));
    SelectWordFmat.cbSize = sizeof(CHARFORMAT);
    SelectWordFmat.dwMask = CFM_COLOR;
    SelectWordFmat.crTextColor = 0x000000FF;

    String OneLine = CmdStrRE->Lines->Strings[0];
    int Len = OneLine.Length();
    String OneChar;
    bool BeginSel = false;
    bool EndSel = false;
    int BeginPos;
    int EndPos;

    // Highlight CmdLine items needing modification
    for (int p = 1; p <= Len; p++) {
     	OneChar = OneLine.SubString(p, 1);
        if ((OneChar == "'") && (!BeginSel)) {
        	BeginSel = true;
            BeginPos = p;
        }
        if ((OneChar == "'") && (BeginSel)) {
            if (BeginPos != p) {
            	EndPos = p;
            	EndSel = true;
            }
        }

        // Paint highlighted text red
    	if ((EndSel) && (BeginSel)) {
    		CmdStrRE->Perform(EM_SETSEL, BeginPos-1, EndPos);
        	CmdStrRE->Perform(EM_SETCHARFORMAT,
         				   SCF_SELECTION,
                           (LPARAM) (CHARFORMAT FAR *)
                           &SelectWordFmat);
        	CmdStrRE->Perform(EM_SETSEL, BeginPos - 1, BeginPos - 1);
            BeginSel = false;
            EndSel = false;
    	}
    }
}
//------------------------------------------------------------

void __fastcall TMainForm::RunBtnClick(TObject *Sender)
{
    if (SourceFileSelected) {
        ResultsRE->Clear();
    	int FBreak;
    	String TempFile;
        Screen->Cursor = crHourGlass;
        if (!Grep) SetEnvPath();
        if (IsDirty) ResultsRE->Lines->
        				SaveToFile(OpenDlg->FileName);

        ViewResults(Sender);
        Application->ProcessMessages();

        // If NT do security stuff
        SECURITY_DESCRIPTOR sd;
        SECURITY_ATTRIBUTES sa;
        LPSECURITY_ATTRIBUTES lpsa = NULL;
        if (IsWindowsNT()) {
        	InitializeSecurityDescriptor(&sd,
            	SECURITY_DESCRIPTOR_REVISION);
            SetSecurityDescriptorDacl(&sd, true, NULL, false);
            sa.nLength = sizeof(SECURITY_ATTRIBUTES);
            sa.bInheritHandle = true;
            sa.lpSecurityDescriptor = &sd;
            lpsa = &sa;
        }

        // Create the Pipe and get r/w handles
        HANDLE hReadPipe;
        HANDLE hWritePipe;
        assert(CreatePipe(&hReadPipe,
        				  &hWritePipe,
                          lpsa,
                          2500000));
        // initialize STARTUPINFO struct
        STARTUPINFO si;
        memset(&si, 0, sizeof(STARTUPINFO));
        si.cb = sizeof(STARTUPINFO);
        si.dwFlags = STARTF_USESHOWWINDOW |STARTF_USESTDHANDLES;
        si.wShowWindow = SW_HIDE;
        si.hStdOutput = hWritePipe;
        si.hStdError = hWritePipe;
        PROCESS_INFORMATION pi;
        assert(hWritePipe);
        // Run the cmdLine tool
        ResultsRE->Lines->Add("Working.....");
        Application->ProcessMessages();

      if(  CreateProcess(NULL,
                             CmdStrRE->Text.c_str(),
                             NULL,//security
                             NULL,// security
                             TRUE,//inherits handles
                             0,
                             0,
                             0,
                             &si,
                             &pi)

         ){
        CloseHandle(pi.hThread);
        WaitForSingleObject(pi.hProcess, 90000);

        // read from the pipe and put in richedit
        assert(hReadPipe);
        DWORD BytesRead; //unsigned long
        char dest[4000];
        bool RdLoopDone = false;
        ResultsRE->Lines->Clear();
        FBreak = 1;
        if (ExitCode) Screen->Cursor = crDefault;
        while (!RdLoopDone) {
        	memset(dest, 0, 4000);
            assert(ReadFile(hReadPipe, &dest, sizeof(dest), &BytesRead, NULL));
            ResultsRE->Lines->Add(String(dest));
            if (BytesRead < 4000) RdLoopDone = true;
            if (FBreak > 150) RdLoopDone = true;
            FBreak++;
        }
        ResultsRE->Lines->Add("FINISHED!");
        String RawPath;
        if (BCC32 || CPP32) {
        	for (int h = 0; h < OpenDlg->Files->Count; h++) {
                RawPath = "";
                RawPath = OpenDlg->Files->Strings[h];
        		TTabSheet *NewTabSheet = new TTabSheet(this);
                if (CPP32)
        			NewTabSheet->Caption = StripFileExt(
                    		ExtractFileName(RawPath)) + ".i";
                else NewTabSheet->Caption =
                     ExtractFileName(OpenDlg->Files->Strings[h]);
                NewTabSheet->PageControl= PageCtl2;
        		TRichEdit *NewRichEdit = new TRichEdit(this);
                NewRichEdit->ScrollBars = ssBoth;
                NewRichEdit->PlainText = true;
        		NewRichEdit->Parent = NewTabSheet;
        		NewRichEdit->Align = alClient;
                Application->ProcessMessages();
                try {
                	if (CPP32) {
                        TempFile = ExtractFilePath(RawPath) +
                        				 NewTabSheet->Caption;
                        if (GetFileSize(TempFile) > 4000000)
                        	NewRichEdit->Lines->
                            	Add("File size exceeds limit! Use WordPad to view!");
                        else
                    		NewRichEdit->Lines->LoadFromFile(TempFile);
                    }
                	else NewRichEdit->Lines->LoadFromFile(RawPath);
                }
                catch(...) {
    				ShowMessage("Unable to open file " + RawPath);
                    Screen->Cursor = crDefault;
                    return;
                }
            }
        }

        try {
        	if (TLib || TDump) {
                 if (GetFileSize(DestEd) > 4000000)
                 	ResultsRE->Lines->Add("File size exceeds limit! Use WordPad to view!");
                else
            		ResultsRE->Lines->LoadFromFile(DestEd);
            }
        	if (ImpDef) ResultsRE->Lines->
            	LoadFromFile(StripFileExt(OpenDlg->FileName) +
                									 ".def");
        }
        catch (...) {
        	ShowMessage("Unable to open file!");
            Screen->Cursor = crDefault;
            return;
        }
        }//if CreateProcess
        else{
          Screen->Cursor = crDefault;
          ResultsRE->Lines->Add("FINISHED!");
          ShowMessage("Unable to execute program.");
        }
        // Process cleanup
    	CloseHandle(hReadPipe);
    	CloseHandle(hWritePipe);
    	CloseHandle(pi.hProcess);
    	ResultsRE->Perform(EM_SETSEL,0,0);
    	Screen->Cursor = crDefault;
    	IsDirty = false;
        BackBtn->Enabled = true;
    }
    else ShowMessage("Select a File!");
}
//------------------------------------------------------------

void __fastcall TMainForm::BackBtnClick(TObject *Sender)
{
    ResultPnl->Hide();
    BackBtn->Enabled = false;
}
//------------------------------------------------------------

void __fastcall TMainForm::ToolsMi(TObject *Sender)
{
	ResetTools();
    TMenuItem* Item = dynamic_cast<TMenuItem *>(Sender);
    SetupTool(Item->Caption);
}
//------------------------------------------------------------

void __fastcall TMainForm::ToolsPg(TObject *Sender)
{
	ResetTools();
    SetupTool(PageCtl->ActivePage->Caption);
}
//------------------------------------------------------------

void TMainForm::SetupTool(String Caption)
{
    OutFileMi->Checked = false;
    BrowseBtn->Enabled = true;

	if (Caption == "TDump") {
    	OutFileMi->Checked = true;
   		PageCtl->ActivePage = PageCtl->Pages[12];
    	MainForm->Caption = AppCaption + "Turbo Dump";
   		TDump = true;
        FilterStr = "*.*";
    }
    if (Caption == "BCC32") {
        PageCtl->ActivePage = PageCtl->Pages[0];
    	MainForm->Caption = AppCaption + "Borland 32bit C++ Compiler";
    	BCC32 = true;
        FilterStr = "*.c;*.cpp";
    }
    if (Caption == "ImpLib") {
        PageCtl->ActivePage = PageCtl->Pages[8];
    	MainForm->Caption = AppCaption + "Create Import Library from a DLL/DEF";
    	ImpLib = true;
        FilterStr = "*.dll;*.def";
    }
    if (Caption == "ImpDef") {
    	PageCtl->ActivePage = PageCtl->Pages[7];
		MainForm->Caption = AppCaption + "Create a .DEF File from a DLL";
    	ImpDef = true;
        FilterStr = "*.dll";
    }
    if (Caption == "TRegSvr") {
    	PageCtl->ActivePage = PageCtl->Pages[17];
		MainForm->Caption = AppCaption + "ActiveX Registration Utility .OCX";
    	TRegAX = true;
        FilterStr = "*.ocx";
    }
    if (Caption == "Tasm32") {
    	PageCtl->ActivePage = PageCtl->Pages[10];
		MainForm->Caption = AppCaption + "Turbo Assembler";
    	Tasm = true;
        FilterStr = "*.asm";
    }
    if (Caption == "TLibImp") {
    	PageCtl->ActivePage = PageCtl->Pages[14];
		MainForm->Caption = AppCaption + "Generate a C++ class from Type library .TLB";
    	TlbImp = true;
        FilterStr = "*.tlb";
    }
    if (Caption == "TLib") {
        PageCtl->ActivePage = PageCtl->Pages[13];
    	MainForm->Caption = AppCaption + "Build or Modify Libraries";
    	TLib = true;
        FilterStr = "*.lib";
    }
    if (Caption == "ILink32") {
        MainForm->Caption = AppCaption + "Turbo Incremental Linker";
    	PageCtl->ActivePage = PageCtl->Pages[6];
    	ILink32 = true;
        FilterStr = "*.obj;*.lib";
    }
    if (Caption == "TLink32") {
        MainForm->Caption = AppCaption + "Turbo Linker";
    	PageCtl->ActivePage = PageCtl->Pages[15];
    	TLink32 = true;
        FilterStr = "*.obj;*.lib";
    }
    if (Caption == "Make") { //************************************************************************
        PageCtl->ActivePage = PageCtl->Pages[9];
    	MainForm->Caption = AppCaption + "MAKE runs rules from a text file (MAKEFILE or .MAK)";
    	Make = true;
        FilterStr = "*.mak";
    }
    if (Caption == "BRCC32") {
        PageCtl->ActivePage = PageCtl->Pages[1];
    	MainForm->Caption = AppCaption + "Resource Compiler for .RC files";
    	BRCC32 = true;
        FilterStr = "*.rc";
    }
    if (Caption == "CPP32") {
        PageCtl->ActivePage = PageCtl->Pages[2];
    	MainForm->Caption = AppCaption + "C++ PreProcessor for .Cxx and .Hxx files";
    	CPP32 = true;
        FilterStr = "*.c;*.cpp;*.h;*.hpp";
    }
    if (Caption == "Coff2omf") {
        PageCtl->ActivePage = PageCtl->Pages[3];
    	MainForm->Caption = AppCaption + "Convert Coff import Lib to OMF import lib";
    	Coff = true;
        FilterStr = "*.lib";
    }
    if (Caption == "Convert") {
        PageCtl->ActivePage = PageCtl->Pages[4];
    	MainForm->Caption = AppCaption + "Convert .DFM to .TXT or .TXT to .DFM";
    	Convert = true;
        FilterStr = "*.dfm;*.txt";
    }
    if (Caption == "TDStrp32") {
        PageCtl->ActivePage = PageCtl->Pages[11];
    	MainForm->Caption = AppCaption + "Turbo Debugger Symbol Table Stripper for .EXE";
    	TDStrp32 = true;
        FilterStr = "*.exe";
    }
    if (Caption == "Grep") {
    	GrepMi(DummySender);
    }
    if (Caption == "Touch") {
        PageCtl->ActivePage = PageCtl->Pages[16];
    	MainForm->Caption = AppCaption + "Change File Date/Time Attributes";
    	Touch = true;
        FilterStr = "*.*";
    }
    ClearCtls();
    CmdStrRE->Text = PageCtl->ActivePage->Caption + " ";
    OptionString = "";
    if (SourceFileSelected) PrepareCmdLine();
}

void __fastcall TMainForm::GrepMi(TObject *Sender)
{
    BrowseBtn->Enabled = false;
    ResetTools();
    PageCtl->ActivePage = PageCtl->Pages[5];
    MainForm->Caption = AppCaption + "Grep Text Search Utility";
    String GWord;
    Application->ProcessMessages();

    // Use Windows 95 Directory box to get dir
    BROWSEINFO bi;
  	char GDir[MAX_PATH];
  	char FolderName[MAX_PATH];
  	LPITEMIDLIST ItemID;
  	memset(&bi, 0, sizeof(BROWSEINFO));
  	memset(GDir, 0, MAX_PATH);
  	bi.hwndOwner      = Handle;
  	bi.pszDisplayName = FolderName;
  	bi.lpszTitle      = "Select Directory to Search In!";
  	ItemID = SHBrowseForFolder(&bi);
  	SHGetPathFromIDList(ItemID, GDir);
  	GlobalFreePtr(ItemID);
    String Temp = String(GDir);
    if (Temp == "") return;

    // Get the word to search for
    bool SelectOK = InputQuery("Enter Word", "Grep for ?",GWord);
    if (!SelectOK) return;
   	Grep = true;
   	OptionString = "";
   	ObjList->Clear();
   	ClearCtls();
   	CmdStrRE->Text = "Grep -";
    DestEd = GWord;
    SourceEd = Temp;
    ODFileName = Temp;
    FindDialog1->FindText = GWord;

    SourceFileSelected = true;
    CmdStrRE->Text = PageCtl->ActivePage->Caption + " -";
    OptionString = "";
    PrepareCmdLine();
    RunBtn->Enabled = true;
    OpenAtCursor->Enabled = true;
}
//------------------------------------------------------------

int TMainForm::HandleOpenDlgs(String FilterStr)
{
    OpenDlg->FileName = FilterStr;
    OpenDlg->InitialDir = WorkDir;
    if (OpenDlg->Execute()) {
    	SourceFileSelected = true;
        SourceEd = "";

        // For multifiles
        if (OpenDlg->Files->Count > 1) {
            for (int h = 0; h < OpenDlg->Files->Count; h++) {
                if (h < OpenDlg->Files->Count -1) {

                    if (h == 0)
            	        SourceEd = SourceEd +
                        	 OpenDlg->Files->Strings[h] +
                             "\"" + " ";
                    else
                        SourceEd = SourceEd +
                        	  "\"" + OpenDlg->Files->
                              Strings[h] + "\"" + " ";
                }
                else
                    SourceEd = SourceEd + "\"" +
                    		OpenDlg->Files->Strings[h];
            }
        }
        else
    		SourceEd = OpenDlg->FileName;


    	ODFileName = ExtractFileName(OpenDlg->FileName);
        SourceEd = OpenDlg->FileName;
    	SourceFileDir = ExtractFileDir(OpenDlg->FileName);
        SetCurrentDir(SourceFileDir);
        WorkDir = SourceFileDir;
    	NewDestEdit = StripFileExt(ODFileName) + ".txt";
    	DestEd = SourceFileDir + "\\" + NewDestEdit;
    	CmdStrRE->Text = PageCtl->ActivePage->Caption + " ";
    	OptionString = "";
    	PrepareCmdLine();
        ObjList->Clear();
        RunBtn->Enabled = true;
    	return 1;
    }
    else
    	return 0;
}
//------------------------------------------------------------

void __fastcall TMainForm::FindDialog1Find(TObject *Sender)
{
    const String Search = FindDialog1->FindText;
    FindNext1->Enabled = true;
    FindNext2->Enabled = true;

    // Setup color red for word found
    CHARFORMAT SelectWordFmat;
    memset(&SelectWordFmat, 0, sizeof(CHARFORMAT));
    SelectWordFmat.cbSize = sizeof(CHARFORMAT);
    SelectWordFmat.dwMask = CFM_COLOR;
    SelectWordFmat.crTextColor = 0x000000FF;

    // Setup search struct
    bool FoundOne;
    TFindText MyTFindText;
    MyTFindText.chrg.cpMin = PosFound;
    if (PosFound)
    	MyTFindText.chrg.cpMin = PosFound + Search.Length();
    MyTFindText.chrg.cpMax = -1;
    MyTFindText.lpstrText = strdup(Search.c_str());

    // Perform search on active richedit
    TRichEdit *RE = (TRichEdit *) PageCtl2->ActivePage->
    											Controls[0];

    PosFound = RE->Perform(EM_FINDTEXT, 0, (LPARAM) (&MyTFindText));
    FoundOne = PosFound != -1;
    RE->Perform(EM_SETSEL, PosFound, PosFound + Search.Length());
    RE->Perform(EM_SCROLLCARET, 0, 0);
    RE->SetFocus();

    if (!FoundOne) {
        if (Search != "Function name") {
            ShowMessage("End of Page! \"" + Search +
            							 "\" not found!");
            FindNext1->Enabled = false;
    		FindNext2->Enabled = false;
            return;
        }
    }
    else{ // Set select color red
        RE->Perform(EM_SETCHARFORMAT,
         				   SCF_SELECTION,
                           (LPARAM) (CHARFORMAT FAR *)
                           &SelectWordFmat);
        RE->Perform(EM_SETSEL, PosFound, PosFound);
      }
}
//------------------------------------------------------------

void __fastcall TMainForm::Toolcbs(TObject *Sender)
{
	// Handle font colors
    TFontStyles BoldFnt;
    TCheckBox* cb = dynamic_cast<TCheckBox *>(Sender);
    if (cb->State == cbChecked) {
    	cb->Font->Color = clBlue;
    	BoldFnt << fsBold;
    	cb->Font->Style = BoldFnt ;
    }
    else {
    	cb->Font->Color = clBlack;
    	BoldFnt >> fsBold;
    	cb->Font->Style = BoldFnt;
    }
    // Add checked boxes to the object list
    ObjList->AddObject("TCheckBox", Sender);
    if (!SourceFileSelected && !Clear && (ObjList->Count)) {
    	ShowMessage("Select a File!");
    	ClearCtls();
    }
    else {
    	if (Grep) CmdStrRE->Text = PageCtl->
    							ActivePage->Caption +  " -";
    	else
    		CmdStrRE->Text = PageCtl->ActivePage->Caption + " ";
        OptionString = "";
        if (SourceFileSelected) PrepareCmdLine();
    }
}
//------------------------------------------------------------

void __fastcall TMainForm::LabToCB(TObject *Sender)
{
    // Make label activate corresponding checkbox
    if (SourceFileSelected) {
    	String LabToCB;
    	String cbName;
    	int ctl;
    	TCheckBox *CB;
    	TLabel* lab = dynamic_cast<TLabel *>(Sender);
    	int Len = lab->Name.Length();

		LabToCB = lab->Name.SubString(6, Len-5);
    	if (TDump) cbName = "TDcb"+LabToCB;
    	if (BCC32) cbName = "BCcb"+LabToCB;
        if (ImpLib) cbName = "ILcb"+LabToCB;
        if (ImpDef) cbName = "IDcb"+LabToCB;
        if (TLib) cbName = "TLcb"+LabToCB;
        if (ILink32) cbName = "IKcb"+LabToCB;
        if (TLink32) cbName = "TKcb"+LabToCB;
        if (Make) cbName = "MKcb"+LabToCB;
        if (BRCC32) cbName = "BRcb"+LabToCB;
        if (CPP32) cbName = "CPcb"+LabToCB;
        if (TDStrp32) cbName = "DScb"+LabToCB;
        if (Grep) cbName = "GPcb"+LabToCB;
        if (Touch) cbName = "TCcb"+LabToCB;
        if (Coff) cbName = "CFcb"+LabToCB;
        if (TlbImp) cbName = "TPcb"+LabToCB;
        if (TRegAX) cbName = "TRcb"+LabToCB;
        if (Tasm) cbName = "TScb"+LabToCB;

        if (BCC32) {
            if (BCCPnl1->Visible) {
    		    for (ctl=0; ctl<BCCPnl1->ControlCount; ctl++) {
        		    if (BCCPnl1->Controls[ctl]->Name == cbName) break;
        	    }
        	    CB = (TCheckBox *) BCCPnl1->Controls[ctl];
    	    }
            if (BCCPnl2->Visible) {
    		    for (ctl=0; ctl<BCCPnl2->ControlCount; ctl++) {
        		    if (BCCPnl2->Controls[ctl]->Name == cbName) break;
        	    }
        	    CB = (TCheckBox *) BCCPnl2->Controls[ctl];
    	    }
            if (BCCPnl3->Visible) {
    		    for (ctl=0; ctl<BCCPnl3->ControlCount; ctl++) {
        		    if (BCCPnl3->Controls[ctl]->Name == cbName) break;
        	    }
        	    CB = (TCheckBox *) BCCPnl3->Controls[ctl];
    	    }
        }
    	else {
    		for (ctl=0; ctl<PageCtl->ActivePage->ControlCount; ctl++) {
        		if (PageCtl->ActivePage->Controls[ctl]->
                						Name == cbName) break;
        	}
        	CB = (TCheckBox *) PageCtl->ActivePage->Controls[ctl];
    	}
		CB->Checked = CB->State==cbUnchecked;
    }
    else ShowMessage("Select a File!");
}
//------------------------------------------------------------

void __fastcall TMainForm::Print1Click(TObject *Sender)
{
    if (SourceFileSelected) {
    	try {
    		TRichEdit *RE = (TRichEdit *) PageCtl2->ActivePage->
    											Controls[0];
        	if (PrintDialog1->Execute())
				RE->Print(PageCtl2->ActivePage->Caption);
            else return;
        }
        catch(...) {
        	ShowMessage("Could not print file !");
            return;
        }
    }
    else
    	ShowMessage("Select a File!");
}
//------------------------------------------------------------

void __fastcall TMainForm::AdvBtnClick(TObject *Sender)
{
    BCCPnl1->Hide();
    BCCPnl3->Hide();
    BCCPnl2->Show();
}
//------------------------------------------------------------



void __fastcall TMainForm::ResultsREKeyPress(TObject *Sender,
	char &Key)
{
	IsDirty = true;
}
//------------------------------------------------------------

void __fastcall TMainForm::SetWorkingDir1Click(
	TObject *Sender)
{
    // Use Windows 95 Directory box to get dir
    BROWSEINFO bi;
  	char WDir[MAX_PATH];
  	char FolderName[MAX_PATH];
  	LPITEMIDLIST ItemID;

  	memset(&bi, 0, sizeof(BROWSEINFO));
  	memset(WDir, 0, MAX_PATH);
  	bi.hwndOwner = Handle;
  	bi.pszDisplayName = FolderName;
  	bi.lpszTitle = "Select Working Directory!";
  	ItemID = SHBrowseForFolder(&bi);
  	SHGetPathFromIDList(ItemID, WDir);
  	GlobalFreePtr(ItemID);
    if (WorkDir == "") return;
    WorkDir = String(WDir);
}
//------------------------------------------------------------

bool TMainForm::IsWindowsNT()
{
	OSVERSIONINFO osv;
    osv.dwOSVersionInfoSize = sizeof(osv);
    GetVersionEx(&osv);
    return (osv.dwPlatformId == VER_PLATFORM_WIN32_NT);
}

void __fastcall TMainForm::CloseActive(TObject *Sender)
{
	if (PageCtl2->PageCount > 1) {
      	PageCtl2->ActivePage->Free();
      	PageCtl2->ActivePage = PageCtl2->Pages[0];
    }
}
//------------------------------------------------------------

void __fastcall TMainForm::Closeall1Click(TObject *Sender)
{
	if (PageCtl2->PageCount > 1) {
      	while (PageCtl2->PageCount > 1) {            
      		PageCtl2->ActivePage = PageCtl2->Pages[1];
            if (PageCtl2->ActivePage->Caption != "Results") {
        		PageCtl2->ActivePage->Free();
         		Application->ProcessMessages();
            }
        }
    PageCtl2->ActivePage = PageCtl2->Pages[0];
    }
}
//------------------------------------------------------------

void __fastcall TMainForm::Save2Click(TObject *Sender)
{
    if (SourceFileSelected) {
    	try {
        	TRichEdit *RE = (TRichEdit *) PageCtl2->
            					ActivePage->Controls[0];
            // not saved yet do saveas
            if (SourceFileDir.IsEmpty()) {
                SaveAs2Click(Sender);
                return;
            }
            RE->Lines->SaveToFile(SourceFileDir + "\\" +
            		 	PageCtl2->ActivePage->Caption) ;
        }
        catch (...) {
        	ShowMessage("Could not save file " + SourceFileDir +
            	"\\" + PageCtl2->ActivePage->Caption);
            return;
        }
    }
    else
    	ShowMessage("Select a File!");

}
//------------------------------------------------------------

void __fastcall TMainForm::SaveAs2Click(TObject *Sender)
{
	if (SourceFileSelected) {
    	try {
    		TRichEdit *RE = (TRichEdit *) PageCtl2->ActivePage->
    											Controls[0];
        	if (SaveDialog1->Execute())
				RE->Lines->SaveToFile(SaveDialog1->FileName);
        }
        catch (...) {
        	ShowMessage("Could not save file " +  SaveDialog1->
            										FileName) ;
            return;
        }
    }
    else
    	ShowMessage("Select a File!");
}
//------------------------------------------------------------

void __fastcall TMainForm::About1Click(TObject *Sender)
{
	AboutBox = new TAboutBox(this);
    AboutBox->ShowModal();
    delete AboutBox;
}
//------------------------------------------------------------

void __fastcall TMainForm::OpenAtCursorClick(
	TObject *Sender)
{
    String OneChar;
    String FilePath = "";
	int LineNum = ResultsRE->Perform(EM_LINEFROMCHAR,ResultsRE->
    											SelStart,0);
    String RawPath = ResultsRE->Lines->Strings[LineNum];
    int x = RawPath.Length() -1; // Skip last char :
    while (x) {
    	OneChar = RawPath.SubString(x, 1);
        if (OneChar == " ") break;
        FilePath.Insert(OneChar, 1);
        x--;
    }
    CreateNewPage(ExtractFileName(FilePath), FilePath);
}
//------------------------------------------------------------

void __fastcall TMainForm::BrowseMi(TObject *Sender)
{
    HandleOpenDlgs(FilterStr);
}
//------------------------------------------------------------

void __fastcall TMainForm::Find2Click(TObject *Sender)
{
	if (FindDialog1->Execute())	PosFound = 0;
}
//------------------------------------------------------------

void __fastcall TMainForm::Exit1Click(TObject *Sender)
{
	Application->Terminate();	
}
//------------------------------------------------------------

void __fastcall TMainForm::OutFileMiClick(TObject *Sender)
{
	OutFileMi->Checked = !OutFileMi->Checked;
    CmdStrRE->Text = PageCtl->ActivePage->Caption + " ";
    OptionString = "";
    PrepareCmdLine();
}
//------------------------------------------------------------

void __fastcall TMainForm::ToolHelpMi(
	TObject *Sender)
{
	TMenuItem* Item = dynamic_cast<TMenuItem *>(Sender);
    CreateNewPage(ExtractFileName(Item->Caption + ".txt"),
    				WintoolsDir + Item->Caption + ".txt");
    SourceFileSelected = true;
}
//------------------------------------------------------------

String TMainForm::StripFileExt(String FileName)
{
    String Temp;
    String OneChar;
    bool FoundDot = false;
    int Len = FileName.Length();

    while (Len > 0) {
    	OneChar = FileName.SubString(Len, 1);
        if (FoundDot) Temp.Insert(OneChar, 0);
    	if (OneChar == ".") FoundDot = true;
    	Len--;
    }
    return Temp;
}

void __fastcall TMainForm::New1Click(TObject *Sender)
{
    MainForm->Caption = AppCaption + "Create a New File";
    CreateNewPage("New File", "None");
    TRichEdit *RE = (TRichEdit *) PageCtl2->ActivePage->
                     Controls[0];
    RE->SetFocus();
    CmdStrRE->Text = "";
    DestEd = "";
    SourceFileSelected = true;
}
//------------------------------------------------------------ 

void __fastcall TMainForm::OpenClick(TObject *Sender)
{
    TMenuItem* mi = dynamic_cast<TMenuItem *>(Sender);
    String MItem = mi->Caption;
    MainForm->Caption = AppCaption + "View/Edit a File";

	if (HandleOpenDlgs("*.*")) {
    	ResultPnl->Parent = this;
    	ResultPnl->Align = alClient;
        String File = OpenDlg->FileName;
        CreateNewPage(ExtractFileName(File),File);
        BackBtn->Enabled = true;
        RunBtn->Enabled = false;
        CmdStrRE->Text = "";
        DestEd = "";
        TRichEdit *RE = (TRichEdit *) PageCtl2->ActivePage->
                         Controls[0];
        RE->SetFocus();
    }
}
//------------------------------------------------------------

void TMainForm::CreateNewPage(String TabName, String LoadFile)
{
	TTabSheet *NewTabSheet = new TTabSheet(this);
    NewTabSheet->Caption = TabName;
    NewTabSheet->PageControl = PageCtl2;

    TRichEdit *NewRichEdit = new TRichEdit(this);
    NewRichEdit->ScrollBars = ssBoth;
    NewRichEdit->PlainText = true;
    NewRichEdit->WordWrap = true;
    NewRichEdit->Parent = NewTabSheet;
    NewRichEdit->Align = alClient;
    NewRichEdit->PopupMenu = PopupMenu1;

    PageCtl2->ActivePage = PageCtl2->Pages[PageCtl2->PageCount - 1];
    try {
    	if (LoadFile != "None")
    			NewRichEdit->Lines->LoadFromFile(LoadFile);
    }
    catch(...) {
    	ShowMessage("Unable to open file " + LoadFile);
        return;
    }
    ResultPnl->Parent = this;
    ResultPnl->Align = alClient;
    ResultPnl->Show();
    BackBtn->Enabled = true;
} 

void __fastcall TMainForm::Operations(TObject *Sender)
{
    if (SourceFileSelected) {
		TFontStyles BoldFnt;
    	TCheckBox* cb = dynamic_cast<TCheckBox *>(Sender);
    	if (cb->State == cbChecked) {
    		cb->Font->Color = clBlue;
    		BoldFnt << fsBold;
    		cb->Font->Style = BoldFnt;
    	}
    	else {
    		cb->Font->Color = clBlack;
    		BoldFnt >> fsBold;
    		cb->Font->Style = BoldFnt;
    	}
    	CmdStrRE->Text = PageCtl->ActivePage->Caption + " ";
        OptionString = "";
        PrepareCmdLine();
    }
    else ShowMessage("Select a File!");
}
//------------------------------------------------------------

int TMainForm::GetFileSize(String SFile)
{
    struct stat statbuf;
    stat(SFile.c_str(), &statbuf);
	return statbuf.st_size;
}

void __fastcall TMainForm::SymbolBtn(TObject *Sender)
{
    if (SourceFileSelected) {
    	TButton* btn = dynamic_cast<TButton *>(Sender);
		CmdStrRE->Text = CmdStrRE->Text + " " + btn->Caption;
    }
    else ShowMessage("Select a File!");
}
//------------------------------------------------------------

void __fastcall TMainForm::Button10Click(TObject *Sender)
{
    BCCPnl2->Hide();
    BCCPnl3->Hide();
    BCCPnl1->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button8Click(TObject *Sender)
{
    BCCPnl1->Hide();
    BCCPnl3->Hide();
    BCCPnl2->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button11Click(TObject *Sender)
{
    BCCPnl1->Hide();
    BCCPnl2->Hide();
    BCCPnl3->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ViewResults(TObject *Sender)
{
    ResultPnl->Parent = this;
    ResultPnl->Align = alClient;
    ResultPnl->Show();
    BackBtn->Enabled = true;
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::RevisePath1Click(TObject *Sender)
{
    CreateNewPage("Path", WintoolsDir + "Path.txt");
    String AddPath;
    if (!InputQuery("Add to Path", "",AddPath)) return;
    TRichEdit *RE = (TRichEdit *) PageCtl2->ActivePage->
                         Controls[0];
    RE->Lines->Add(AddPath);
    RE->Lines->SaveToFile(WintoolsDir + "Path.txt");
    SetEnvPath();
}
//---------------------------------------------------------------------------




void __fastcall TMainForm::CmdStrREMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
    CmdStrRE->Align = alClient;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PageCtlMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
    CmdStrRE->Align = alNone;
    CmdStrRE->Width = 343;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ResultPnlMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{       
    CmdStrRE->Align = alNone;
    CmdStrRE->Width = 343;
}
//---------------------------------------------------------------------------





