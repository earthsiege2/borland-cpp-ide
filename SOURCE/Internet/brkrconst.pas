{ *************************************************************************** }
{                                                                             }
{ Delphi and Kylix Cross-Platform Visual Component Library                    }
{ Internet Application Runtime                                                }
{                                                                             }
{ Copyright (C) 1995, 2001 Borland Software Corporation                       }
{                                                                             }
{ Licensees holding a valid Borland No-Nonsense License for this Software may }
{ use this file in accordance with such license, which appears in the file    }
{ license.txt that came with this Software.                                   }
{                                                                             }
{ *************************************************************************** }


unit BrkrConst;          

interface

resourcestring
  sOnlyOneDataModuleAllowed = 'Only one data module per application';
  sNoDataModulesRegistered = 'No data modules registered';
  sNoDispatcherComponent = 'No dispatcher component found on data module';
  sNoWebModulesActivated = 'No automatically activated data modules';
  sTooManyActiveConnections = 'Maximum number of concurrent connections exceeded.  ' +
    'Please try again later';
  sInternalServerError = '<html><title>Internal Server Error 500</title>'#13#10 +
    '<h1>Internal Server Error 500</h1><hr>'#13#10 +
    'Exception: %s<br>'#13#10 +
    'Message: %s<br></html>'#13#10;
  sDocumentMoved = '<html><title>Document Moved 302</title>'#13#10 +
    '<body><h1>Object Moved</h1><hr>'#13#10 +
    'This Object may be found <a HREF="%s">here.</a><br>'#13#10 +
    '<br></body></html>'#13#10;

implementation

end.
