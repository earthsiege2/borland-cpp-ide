{************************************************************************}
{                                                                        }
{       Borland Delphi Visual Component Library                          }
{       InterBase Express core components                                }
{                                                                        }
{       Copyright (c) 1998-2001 Borland Software Corporation             }
{                                                                        }
{    InterBase Express is based in part on the product                   }
{    Free IB Components, written by Gregory H. Deatz for                 }
{    Hoagland, Longo, Moran, Dunst & Doukas Company.                     }
{    Free IB Components is used under license.                           }
{                                                                        }
{    The contents of this file are subject to the InterBase              }
{    Public License Version 1.0 (the "License"); you may not             }
{    use this file except in compliance with the License. You may obtain }
{    a copy of the License at http://www.borland.com/interbase/IPL.html  }
{    Software distributed under the License is distributed on            }
{    an "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, either              }
{    express or implied. See the License for the specific language       }
{    governing rights and limitations under the License.                 }
{    The Original Code was created by InterBase Software Corporation     }
{       and its successors.                                              }
{    Portions created by Borland Software Corporation are Copyright      }
{       (C) Borland Software Corporation. All Rights Reserved.           }
{    Contributor(s): Jeff Overcash                                       }
{                                                                        }
{************************************************************************}

unit IBGeneratorEditor;

interface

uses
{$IFDEF MSWINDOWS}
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  StdCtrls, ExtCtrls;
{$ENDIF}
{$IFDEF LINUX}
  QForms, QStdCtrls, QExtCtrls, Classes, QControls;
{$ENDIF}

type
  TfrmGeneratorEditor = class(TForm)
    Label1: TLabel;
    Label2: TLabel;
    OKBtn: TButton;
    CancelBtn: TButton;
    cbxGenerators: TComboBox;
    cbxFields: TComboBox;
    grpApplyEvent: TRadioGroup;
    HelpBtn: TButton;
    Label3: TLabel;
    edtIncrement: TEdit;
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  frmGeneratorEditor: TfrmGeneratorEditor;

implementation

{$IFDEF MSWINDOWS}
{$R *.dfm}
{$ENDIF}
{$IFDEF LINUX}
{$R *.xfm}
{$ENDIF}

end.
