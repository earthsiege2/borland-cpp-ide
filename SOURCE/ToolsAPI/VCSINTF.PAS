
{*******************************************************}
{                                                       }
{       Delphi Visual Component Library                 }
{                                                       }
{       Copyright (c) 1995,1996 Borland International   }
{                                                       }
{*******************************************************}

unit VcsIntf;  { VCS Interface declarations }

{  This file defines the cooperative interface between the IDE
   and a VCS Manager DLL.  The VCS Manager DLL must be named in the
   registry at startup time under the isVersionContol key, as the value
   for the ivVCSManager variable.

   As the IDE loads, it will load the specified DLL and attempt
   to obtain a proc address for the DLL's initialization function, which
   must be exported using the VCSManagerEntryPoint constant.  }

interface

uses Windows, VirtIntf, ToolIntf;

const
  isVersionControl = 'Version Control';
  ivVCSManager = 'VCSManager';
  VCSManagerEntryPoint = 'INITVCS0014';

type

  { The VCS client object should be returned by the VCS Manager DLL as the
    result of the init call.  The IDE is responsible for freeing the
    client object before unloading the VCS Manager DLL.

    GetIDString     - Called at initialization.  Client should return
                      a unique identification string.  The following
                      string is reserved for Borland use:

                        Borland.StdVcs

    ExecuteVerb     - Called when the user selects a verb from a menu.

    GetMenuName     - Called to retrieve the name of the main menu item
                      to be added to the application's menu bar.  Return
                      a blank string to indicate no menu.

    GetVerb         - Called to retrieve the menu text for each verb.
                      A verb may be returned as a blank string to create a
                      seperator bar.

    GetVerbCount    - Called to determine the number of available verbs. This
                      function will not be called if the GetMenuName function
                      returns a blank string (indicating no menu).

    GetVerbState    - Called to determine the state of a particular verb.
                      The return value is a bit field of various states.
                      (See below for definition of bit values).

    ProjectChange   - Called when there is any state change of the current
                      project, i.e. when a project is destroyed or created.

  }

  TIVCSClient = class(TInterface)
    function GetIDString: string; virtual; stdcall; abstract;
    procedure ExecuteVerb(Index: Integer); virtual; stdcall; abstract;
    function GetMenuName: string; virtual; stdcall; abstract;
    function GetVerb(Index: Integer): string; virtual; stdcall; abstract;
    function GetVerbCount: Integer; virtual; stdcall; abstract;
    function GetVerbState(Index: Integer): Word; virtual; stdcall; abstract;
    procedure ProjectChange; virtual; stdcall; abstract;
  end;

  { A function matching this signature must be exported from the VCS
    Manager DLL. }
  TVCSManagerInitProc = function (VCSInterface: TIToolServices): TIVCSClient stdcall;

{ Bit flags for GetVerbState function }
const
  vsEnabled	= $01;    { Verb enabled if set, otherwise disabled }
  vsChecked	= $02;    { Verb checked if set, otherwise cleared  }

implementation

end.

