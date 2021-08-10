
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1995,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit Exptintf;

interface

uses Windows, VirtIntf, ToolIntf;

const
  isExperts = 'Experts';
  ExpertEntryPoint = 'INITEXPERT0017';
  ValidExpertVersion = 3;

type
  TExpertStyle = (esStandard, esForm, esProject, esAddIn);
  TExpertState = set of (esEnabled, esChecked);

  {
    This is the declaration of the pure-virtual base class for the expert
    interface within the Delphi IDE.

    NOTE: In Delphi 1.0, the GetGlyph function used to return an HBITMAP,
          whereas now it must return an HICON.

    GetName -      REQUIRED.  This must return a unique descriptive name
                   identifying this expert.

    GetAuthor  -   REQUIRED is style is esForm or esProject.  This should
                   return the "author" of this add-in/expert.  This could
                   be a person or company, for example.  This value will
                   be displayed in the Object Repository.

    GetComment -   REQUIRED if style is esForm or esProject.  This should
                   return a 1 - 2 sentence describing the function of this
                   expert.

    GetPage -      REQUIRED if style is esForm or esProject. Should return
                   short string indicating on  which page in the repository
                   this expert should be placed.  NOTE: The user can still
                   override this setting from the Tool|Repository dialog.

    GetGlyph -     REQUIRED if style is esForm or esProject.  This should
                   return a handle to a icon to be displayed in the form or
                   project list boxes or dialogs.  Return 0 to display the
                   default icon.

    GetStyle -     REQUIRED.  Returns one of four possible values:
                   esStandard - Tells the IDE to treat the interface to
                                this expert as a menu item on the Help
                                menu.
                   esForm     - Tells the IDE to treat this expert interface
                                in a fashion similar to form templates.
                   esProject  - Tells the IDE to treat this interface in a
                                fashion similar to project templates.
                   esAddIn    - Tells the IDE that this expert handles all its
                                own interfacing to the IDE through the
                                TIToolServices interface.

    GetState -     REQUIRED. If the style is esStandard, esChecked will cause
                   the menu to display a checkmark. NOTE: This function is
                   called each time the expert is shown in a menu or listbox in
                   order to determine how it should be displayed.

    GetIDString -  REQUIRED. This ID string should be unique to all experts
                   that could be installed.  By convention, the format of the
                   string is:
                   CompanyName.ExpertFunction, ex. Borland.WidgetExpert

    GetMenuText -  REQURED if style is esStandard.  This should return the
                   actual text to display for the menu item. NOTE: This
                   function is called each time the parent menu is pulled-down,
                   so it is possible to provide context sensative text.

    Execute -      REQUIRED if style is esStandard, esForm, or esProject.
                   Called whenever this expert is invoked via the menu, form
                   repository dialog, or project repository dialog.  The style
                   will determine how the expert was invoked.  This procedure
                   is never called if the style is esAddIn.

    TExpertInitProc - defines the number and types of parameters passed to the
                      single exported entry-point to the expert DLL.
                      ToolServices - a pure-virtual class containing all the
                                     tool services provided by the IDE.
                      RegisterProc - The function to call in order to register
                                     an expert.  NOTE: This function is called
                                     once for each expert instance that the DLL
                                     wants to register with the IDE.
                      Terminate -    Set this parameter to point to a procedure
                                     that will be called immediately before the
                                     expert DLL is unloaded by the IDE.  Leave
                                     nil, if not needed.
  }

  TIExpert = class(TInterface)
  public
    { Expert UI strings }
    function GetName: string; virtual; stdcall; abstract;
    function GetAuthor: string; virtual; stdcall; abstract;
    function GetComment: string; virtual; stdcall; abstract;
    function GetPage: string; virtual; stdcall; abstract;
    function GetGlyph: HICON; virtual; stdcall; abstract;
    function GetStyle: TExpertStyle; virtual; stdcall; abstract;
    function GetState: TExpertState; virtual; stdcall; abstract;
    function GetIDString: string; virtual; stdcall; abstract;
    function GetMenuText: string; virtual; stdcall; abstract;

    { Launch the Expert }
    procedure Execute; virtual; stdcall; abstract;
  end;

  TExpertRegisterProc = function(Expert: TIExpert): Boolean;
  TExpertTerminateProc = procedure;
  TExpertInitProc = function(ToolServices: TIToolServices;
    RegisterProc: TExpertRegisterProc;
    var Terminate: TExpertTerminateProc): Boolean stdcall;

var
  LibraryExpertProc: TExpertRegisterProc = nil;
  ToolServices: TIToolServices = nil;

procedure RegisterLibraryExpert(Expert: TIExpert);

implementation

procedure RegisterLibraryExpert(Expert: TIExpert);
begin
  if @LibraryExpertProc <> nil then
    LibraryExpertProc(Expert);
end;

end.
