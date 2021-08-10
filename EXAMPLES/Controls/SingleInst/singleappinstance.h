      
#ifndef SingleAppInstanceH
#define SingleAppInstanceH

#include <SysUtils.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Forms.hpp>

typedef
  void __fastcall (__closure *TSecondInstanceEvent)(System::TObject* Sender, bool& ShutDown);

typedef
  void __fastcall (__closure *TReceiveCommandLineEvent)(System::TObject* Sender, char* CommandLine);

class PACKAGE TSingleAppInstance : public TComponent
{
  private:
    typedef TComponent inherited;

  private:
    HANDLE FMappingObject;
    CRITICAL_SECTION FWndProcCriticalSection;
    HWND FHiddenWindow;

    bool FEnabled;
    String FMarker;
    bool FPassCommandLine;

    TReceiveCommandLineEvent FOnReceiveCommandLine;
    TSecondInstanceEvent FOnSecondInstance;

    void __fastcall SetEnabled(const bool Value);
    void __fastcall SetMarker(const String Value);

    void __fastcall LocalWinProc(Messages::TMessage &Message);

  private:
    char* FPassedCommandLine;
    DWORD FPassedData;

    bool __fastcall CreateInternalMapFile(void);
    void __fastcall ReleaseInternalMapFile(void);

    void __fastcall PassThisInstanceCommandLine(void);
    void __fastcall PerformSingletonCode(void);

    void __fastcall TakeSecondInstanceAction(void);

  protected:
    virtual void __fastcall DoOnSecondInstance(bool&);
    virtual void __fastcall DoReceiveCommandLine(const char* const CommandLine);
    virtual void __fastcall Loaded(void);

  public:
    __fastcall TSingleAppInstance(TComponent* Owner);
    virtual __fastcall ~TSingleAppInstance(void);

    static void __fastcall AssertValidMarkerText(const String& Value);
    static bool __fastcall IsValidMarkerText(const String& Value);
    static String __fastcall TranslateSlashes(const String& Value);

  __published:
    // Since the default value of the Enabled property is true
    // we do not need to worry about the order in which Enabled
    // and the events are read in.
    // Only if Enabled == false, will SetEnabled be triggered -
    // but then we do not need values for the events.
    __property bool Enabled = { read = FEnabled, write = SetEnabled, default = true };
    __property String Marker = { read = FMarker, write = SetMarker, stored = true };
    __property bool PassCommandLine = { read = FPassCommandLine, write = FPassCommandLine, default = true };

    __property TReceiveCommandLineEvent OnReceiveCommandLine = { read = FOnReceiveCommandLine, write = FOnReceiveCommandLine };
    __property TSecondInstanceEvent OnSecondInstance = { read = FOnSecondInstance, write = FOnSecondInstance };
};

#endif
