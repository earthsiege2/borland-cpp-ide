{ *************************************************************************** }
{                                                                             }
{ Kylix and Delphi Cross-Platform Visual Component Library                    }
{ Internet Application Runtime                                                }
{                                                                             }
{ Copyright (C) 1997, 2001 Borland Software Corporation                       }
{                                                                             }
{ Licensees holding a valid Borland No-Nonsense License for this Software may }
{ use this file in accordance with such license, which appears in the file    }
{ license.txt that came with this Software.                                   }
{                                                                             }
{ *************************************************************************** }


unit WebConst;

interface

resourcestring
  sErrorDecodingURLText = 'Error decoding URL style (%XX) encoded string at position %d';
  sInvalidURLEncodedChar = 'Invalid URL encoded character (%s) at position %d';
  sInvalidHTMLEncodedChar = 'Invalid HTML encoded character (%s) at position %d';    
  sInvalidActionRegistration = 'Invalid Action registration';
  sDuplicateActionName = 'Duplicate action name';
  sFactoryAlreadyRegistered = 'Web Module Factory already registered';
  sAppFactoryAlreadyRegistered = 'Web App Module Factory already registered.';
  sOnlyOneDispatcher = 'Only one WebDispatcher per form/data module';
  sHTTPItemName = 'Name';
  sHTTPItemURI = 'PathInfo';
  sHTTPItemEnabled = 'Enabled';
  sHTTPItemDefault = 'Default';
  sHTTPItemProducer = 'Producer';

  sResNotFound = 'Resource %s not found';

  sTooManyColumns = 'Too many table columns';
  sFieldNameColumn = 'Field Name';
  sFieldTypeColumn = 'Field Type';

  sInvalidWebComponentsRegistration =  'Invalid Web component registration';
  sInvalidWebComponentsEnumeration =  'Invalid Web component enumeration';
  sInvalidWebParent = 'Operation not supported.  %s component does not support IGetWebComponentList'; 
                                                      
  sVariableIsNotAContainer = 'Variable %s is not a container';
  sInternalApplicationError = '<h1>Internal Application Error</h1>'#13#10 +
                              '<p>%0:s'#13#10 +
                              '<p><hr width="100%%"><i>%1:s</i>';
  sInvalidParent = 'Invalid parent';

  sActionDoesNotProvideResponse = 'Action does not provide response';
  sActionCantRespondToUnkownHTTPMethod = 'Action can''t respone to unknown HTTP method';
  sActionCantRedirectToBlankURL = 'Action can''t redirect to blank URL';

implementation

end.

