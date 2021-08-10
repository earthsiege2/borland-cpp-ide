{*******************************************************}
{                                                       }
{ Borland Delphi Visual Component Library               }
{                SOAP Support                           }
{                                                       }
{ Copyright (c) 2001 Borland Software Corporation       }
{                                                       }
{*******************************************************}

unit SOAPConst;

interface

uses TypInfo, XMLSchema;

const

  SSoapXMLHeader = '<?xml version="1.0" encoding=''UTF-8''?>'; { Do not localize}
  SUTF8 = 'UTF-8';                                             { Do not localize}
  ContentHeaderUTF8 = 'Content-Type: text/xml; charset="utf-8"';        { Do not localize }
  ContentHeaderNoUTF8 = 'Content-Type: text/xml';                       { Do not localize }
  sTextHtml = 'text/html';                                 { Do not localize }
  sTextXML  = 'text/xml';                                  { Do not localize }

  ContentTypeUTF8 = 'text/xml; charset="utf-8"';           { Do not localize }
  ContentTypeNoUTF8 = 'text/xml';                          { Do not localize }

  SSoapNameSpace = 'http://schemas.xmlsoap.org/soap/envelope/'; { do not localize}
  SXMLNS = 'xmlns';                                        { do not localize}
  SSoapEncodingAttr = 'encodingStyle';                     { do not localize}
  SSoap11EncodingS5 = 'http://schemas.xmlsoap.org/soap/encoding/';  { do not localize}

  SSoapEncodingArray = 'Array';                            { do not localize}
  SSoapEncodingArrayType = 'arrayType';                    { do not localize}

  SSoapHTTPTransport = 'http://schemas.xmlsoap.org/soap/http';   { do not localize}
  SSoapBodyUseEncoded = 'encoded';                         { do not localize}
  SSoapBodyUseLiteral = 'literal';                         { do not localize}

  SSoapEnvelope = 'Envelope';                              { do not localize}
  SSoapHeader = 'Header';                                  { do not localize}
  SSoapBody = 'Body';                                      { do not localize}
  SSoapResponseSuff = 'Response';                          { do not localize}

  SSoapMustUnderstand = 'mustUnderstand';                  { do not localize}
  SSoapActor = 'actor';                                    { do not localize}

  SSoapServerFaultCode = 'Server';                         { do not localize}
  SSoapServerFaultString = 'Server Error';                 { do not localize}
  SSoapFault = 'Fault';                                    { do not localize}
  SSoapFaultCode = 'faultcode';                            { do not localize}
  SSoapFaultString = 'faultstring';                        { do not localize}
  SSoapFaultActor = 'faultactor';                          { do not localize}
  SSoapFaultDetails =  'detail';                           { do not localize}

  SHTTPSoapAction = 'SOAPAction';                          { do not localize}

  SSoapType = 'type';                                      { do not localize}
  SSoapResponse = 'Response';                              { do not localize}
  SDefaultReturnName = 'return';                           { do not localize}
  SDefaultResultName = 'result';                           { do not localize}

  SXMLID = 'id';                                           { do not localize}
  SXMLHREF = 'href';                                       { do not localize}

  { TODO Owner:JBB - Isn't the attribute 'null' instead of 'NULL' - See XMLSchema spec ?? }
  SSoapNULL = 'NULL';                                      { do not localize}

  SHREFPre = '#';                                          { do not localize}
  SArrayIDPre = 'Array-';                                  { do not localize}
  SDefVariantElemName = 'V';                               { do not localize}

  SDelphiTypeNamespace = 'http://www.borland.com/namespaces/Delphi/Types';    { do not localize}
  SBorlandTypeNamespace= 'http://www.borland.com/namespaces/Types';           { do not localize}

  SOperationNameSpecifier = '%operationName%';             { Do not localize }
  SDefaultReturnParamNames= 'Result;Return';               { Do not localize }
  sReturnParamDelimiters  = ';,/:';                        { Do not localize }



  KindNameArray:  array[tkUnknown..tkDynArray] of string =
    ('Unknown', 'Integer', 'Char', 'Enumeration', 'Float',                    { do not localize }
    'String', 'Set', 'Class', 'Method', 'WChar', 'LString', 'WString',        { do not localize }
    'Variant', 'Array', 'Record', 'Interface', 'Int64', 'DynArray');          { do not localize }

  SSoapNameSpacePre = 'SOAP-ENV';            { do not localize }
  SXMLSchemaNameSpacePre = 'xsd';            { do not localize}
  SXMLSchemaInstNameSpace99Pre = 'xsi';      { do not localize}
  SSoapEncodingPre = 'SOAP-ENC';             { do not localize}

  HTMLStylBeg = '<style type="text/css"><!--' + sLineBreak;
  HTMLStylEnd = '--></style>'                 + sLineBreak;
  BodyStyle1  = 'body       {font-family: Verdana, Arial, Helvetica, sans-serif; font-size: 9pt; }'                                                       + sLineBreak;
  BodyStyle2  = 'body       {font-family: Verdana, Arial, Helvetica, sans-serif; font-size: 9pt; margin-left: 0px; margin-top: 0px; margin-right: 0px; }' + sLineBreak;
  OtherStyles = 'h1         {color: #006699; font-size: 18pt; font-style: normal; font-weight: bold; }'                                                   + sLineBreak +
                'h2         {color: #006699; font-size: 14pt; font-style: normal; font-weight: bold; }'                                                   + sLineBreak +
                'h3         {color: #006699; font-size: 12pt; font-style: normal; font-weight: bold; }'                                                   + sLineBreak +
                '.h1Style   {color: #006699; font-size: 18pt; font-style: normal; font-weight: bold; }'                                                   + sLineBreak +
                '.TblRow    {color: #006699; font-family: Verdana, Arial, Helvetica, sans-serif; font-size: 10pt; font-weight: normal; }' + sLineBreak +
                '.TblRow1   {color: #006699; background-color: #FFFFCC; font-family: Verdana, Arial, Helvetica, sans-serif; font-size: 9pt; font-weight: normal; }' + sLineBreak +
                '.TblRow0   {color: #006699; background-color: #CCCC99; font-family: Verdana, Arial, Helvetica, sans-serif; font-size: 9pt; font-weight: normal; }' + sLineBreak +
                '.TblHdr    {color: #CCCC99; background-color: #006699; font-family: Verdana, Arial, Helvetica, sans-serif; font-size: 10pt; font-weight: bold; text-align: center;}' + sLineBreak +
                '.IntfName  {color: #006699; font-family: Verdana, Arial, Helvetica, sans-serif; font-size: 10pt; font-weight: bold; }'                             + sLineBreak +
                '.MethName  {color: #006699; font-family: Verdana, Arial, Helvetica, sans-serif; font-size: 8pt; font-weight: bold; text-decoration: none; }'       + sLineBreak +
                '.ParmName  {color: #006699; font-family: Verdana, Arial, Helvetica, sans-serif; font-size: 8pt; text-decoration: none; }'                          + sLineBreak +
                '.Namespace {color: #006699; font-family: Verdana, Arial, Helvetica, sans-serif; font-size: 9pt; font-style: italic; }'                             + sLineBreak +
                '.WSDL      {color: #666699; font-family: Verdana, Arial, Helvetica, sans-serif; font-size: 8pt; font-weight: bold; }'                              + sLineBreak +
                '.MainBkgnd {background-color : #CCCC99; }'                                                                                                         + sLineBreak +
                '.Info      {font-family: Verdana, Arial, Helvetica, sans-serif; font-size: 12pt; font-weight: bold; }'                                             + sLineBreak +
                '.NavBar    {color: #006699; background-color: #CCCCCC; font-family: Verdana, Arial, Helvetica, sans-serif; font-size: 8pt; font-weight: bold;text-decoration: none; }'+ sLineBreak +
                '.Off       {color: #A0A0A0; }'                                                                                                                     + sLineBreak +
                '.Tip 	    {color: #666666; font-family : Verdana, Arial, Helvetica, sans-serif; font-weight : normal; font-size : 9pt; }'                         + sLineBreak;


  HTMLStyles  = HTMLStylBeg + BodyStyle1 + OtherStyles + HTMLStylEnd;
  HTMLNoMargin= HTMLStylBeg + BodyStyle2 + OtherStyles + HTMLStylEnd;

  TableStyle  = 'border=1 cellspacing=1 cellpadding=2 ';
  HTMLTopPlain= '<html><head></head><body>';
  HTMLTop     = '<html><head></head>'+HTMLStyles+'<body>';
  HTMLTopNoM  = '<html><head></head>'+HTMLNoMargin+'<body>';
  HTMLTopTNoM = '<html><head><title>%s</title></head>'+HTMLNoMargin+'<body>';
  HTMLTopNS   = '<html><head></head><body>';
  HTMLTopTitle= '<html><head><title>%s</title></head>'+HTMLStyles+'<body>';
  HTMLEnd     = '</body></html>';
  InfoTitle1  = '<table class="MainBkgnd" border=0 cellpadding=0 cellspacing=0 width="100%">' +
                '<tr><td>&nbsp;</td></tr>';
  InfoTitle2  = '<tr><td class="h1Style" align="center">%s - %s</td></tr>' +
                '</table>';
  TblCls: array[Boolean] of string = ('TblRow0', 'TblRow1');
  sTblRow     = 'TblRow';
  sTblHdrCls  = 'TblHdr';

  sQueryStringIntf = 'intf';                                    { Do not localize }
  sQueryStringTypes= 'types';                                   { Do not localize }
  sNBSP = '&nbsp;';                                             { Do not localize }

var

  XMLSchemaNameSpace: string = SXMLSchemaURI_2001;    { Default namespace we publish under }
  XMLSchemaInstNameSpace: string =  SXMLSchemaInstURI;

resourcestring

  SUnsupportedEncodingSyle = 'Unsupported SOAP encodingStyle %s';
  SInvalidSoapRequest = 'Invalid SOAP request';
  SMultiBodyNotSupported = 'Multiple body elements not supported';
  SUnsupportedCC = 'Unsupported calling convention: %s';
  SUnsupportedCCIntfMeth = 'Remote Method Call: unsupported calling convention %s for method %s on interface %s';
  SInvClassNotRegistered  = 'No invokable class registered that implements interface %s of (soap action/path) %s';
  SInvInterfaceNotReg = 'No interface  registered for soap action ''%s''';
  SInvInterfaceNotRegURL = 'No interface  registered for URL ''%s''';
  SRemTypeNotRegistered  = 'Remotable Type %s not registered';
  STypeMismatchInParam = 'Type mismatch in parameter %s';
  SNoSuchMethod = 'No method named ''%s'' is supported by interface ''%s''';
  SInterfaceNotReg = 'Interface not registered, UUID = %s';
  SInterfaceNoRTTI = 'Interface has no RTTI, UUID = %s';
  SNoWSDL = 'No WSDL document associated with WSDLView';
  SWSDLError = 'Invalid WSDL document ''%s'' - Please verify the location and content!'#13#10'Error: %s';
  SEmptyWSDL = 'Empty document';
  sNoWSDLURL = 'No WSDL or URL property was set in the THTTPRIO component. You must set the WSDL or URL property before invoking the Web Service';
  sCantGetURL= 'Unable to retrieve the URL endpoint for Service/Port ''%s''/''%s'' from WSDL ''%s''';
  SDataTypeNotSupported = 'Datatype of TypeKind: %s not supported as argument for remote invocation';
{$IFDEF LINUX}
  SNoMatchingDelphiType = 'No matching Kylix type was found for type: URI = %s, Name = %s on Node %s';
{$ENDIF}
  SUnknownSOAPAction = 'Unknown SOAPAction %s';
  SScalarFromTRemotableS = 'Classes that represent scalar types must decsend from TRemotable, %s does not';
  SNoSerializeGraphs = 'Must allow multiref output for objects when serializing a graph of objects';
  SUnsuportedClassType = 'Conversion from Class %s to SOAP is not supported';
  SUnexpectedDataType = 'Internal error: data type kind %s not expected in this context';


  SArrayTooManyElem = 'Array Node: %s has too many elements';
  SWrongDocElem = 'DocumentElement %s:%s expected, %s:%s found';
  STooManyParameters = 'Too many parameters in method %s';
  SArrayExpected = 'Array type expected. Node %s';
  SNoMultiDimVar = 'Multidimensional variant arrays not supported in this release';
  SNoURL = 'No URL set';

  SNoInterfaceGUID = 'Class %s does not implement interface GUID %s';
  SNoArrayElemRTTI = 'Element of Array type %s has no RTTI';
  SInvalidResponse = 'Invalid SOAP Response';
  SInvalidArraySpec = 'Invalid SOAP array specification';
  SCannotFindNodeID = 'Cannot find node referenced by ID %s';
  SNoNativeNULL = 'Option not set to allow Native type to be set to NULL';
  SFaultCodeOnlyAllowed = 'Only one FaultCode element allowed';
  SFaultStringOnlyAllowed = 'Only one FaultString element allowed';
  SMissingFaultValue = 'Missing FaultString or FaultCode element';
  SNoInterfacesInClass = 'Invokable Class %s implements no interfaces';

  SVariantCastNotSupported = 'Type cannot be cast as Variant';
  SVarDateNotSupported = 'varDate type not supported';
  SVarDispatchNotSupported = 'varDispatch type not supported';
  SVarErrorNotSupported = 'varError type not supported';
  SVarVariantNotSupported = 'varVariant type not supported';
  SHeaderError = 'Error Processing Header %s';
  SMissingSoapReturn = 'SOAP Response Packet: result element expected, received "%s"';
  SInvalidPointer = 'Invalid Pointer';
  SNoMessageConverter = 'No Native to Message converter set';
  SNoMsgProcessingNode = 'No Message processing node set';
  SHeaderAttributeError = 'Soap header %s with attribute ''mustUnderstand'' set to true was not handled';

  {IntfInfo}
  SNoRTTI = 'Interface %s has no RTTI';
  SNoRTTIParam = 'Parameter %s on Method %s of Interface %s has no RTTI';

  {XSBuiltIns}
  SInvalidDateString        = 'Invalid date string: %s';
  SInvalidTimeString        = 'Invalid time string: %s';
  SInvalidHour              = 'Invalid hour: %d';
  SInvalidMinute            = 'Invalid minute: %d';
  SInvalidSecond            = 'Invalid second: %d';
  SInvalidFractionSecond    = 'Invalid second: %f';
  SInvalidMillisecond       = 'Invalid millisecond: %d';
  SInvalidFractionalSecond  = 'Invalid fractional second: %f';
  SInvalidHourOffset        = 'Invalid hour offset: %d';
  SInvalidDay               = 'Invalid day: %d';
  SInvalidMonth             = 'Invalid month: %d';
  SInvalidDuration          = 'Invalid duration string: %s';
  SMilSecRangeViolation     = 'Millisecond Values must be between 000 - 999';
  SInvalidYearConversion    = 'Year portion of date too large for conversion';
  SInvalidTimeOffset        = 'Hour Offset portion of time invalid';
  SInvalidDecimalString     = 'Invalid decimal string: ''''%s''''';
  SEmptyDecimalString       = 'Cannot convert empty string to TBcd value';
  SNoSciNotation            = 'Cannot convert scientific notation to TBcd value';
  SNoNAN                    = 'Cannot convert NAN to TBcd value';
  SInvalidBcd               = 'Invalid Bcd Precision (%d) or Scale (%d)';
  SBcdStringTooBig          = 'Cannot convert to TBcd: string has more than 64 digits: %s';
  SInvalidHexValue          = '%s is not a valid hex string';

  {WebServExp}
  SInvalidBooleanParameter  = 'ByteBool, WordBool and LongBool cannot be exposed by WebServices. Please use ''Boolean''';    

  {WSDLIntf}
  SWideStringOutOfBounds = 'WideString index out of bounds';

  {WSDLPub}
  IWSDLPublishDoc = 'Lists all the PortTypes published by this Service';

  SNoServiceForURL = 'No service available for URL %s';
  SNoInterfaceForURL = 'No interface is registered to handle URL %s';
  SNoClassRegisteredForURL = 'No Class is regisgtered to implement interface %s';
  SEmptyURL = 'No URL was specified for ''GET''';
  SInvalidURL = 'Invalid url ''%s'' - only supports ''http'' and ''https'' schemes';
  SNoClassRegistered = 'No class registered for invokable interface %s';
  SNoDispatcher = 'No Dispatcher set';
  SMethNoRTTI = 'Method has no RTTI';
  SUnsupportedVariant = 'Unsuppported variant type';
  SNoVarDispatch = 'varDispatch type not supported';
  SNoErrorDispatch = 'varError type not supported';
  SUnknownInterface = '(Unknown)';

  SInvalidTimeZone = 'Invalid or Unknown Time Zone';

  sUnknownError = 'Unknown Error';
  sErrorColon   = 'Error: ';
  sServiceInfo  = '%s exposes the following interfaces:';
  sInterfaceInfo= '<a class="NavBar" href="%s">%s</a>&nbsp;&gt;&nbsp;<span class="Off">%s</span>';
  sRegTypes     = 'Registered Types';

  sWebServiceListing      = 'WebService Listing';
  sWebServiceListingAdmin = 'WebService Listing Administrator';
  sPortType               = 'Port Type';
  sNameSpaceURI           = 'Namespace URI';
  sDocumentation          = 'Documentation';
  sWSDL                   = 'WSDL';
  sPortName               = 'PortName';
  sInterfaceNotFound      = HTMLTopPlain + '<h1>Error Encountered</h1><P>Interface %s not found</P>' +HTMLEnd;
  sForbiddenAccess        = HTMLTopNS + '<h1>Forbidden (403)</h1><P>Access Forbidden</P>' +HTMLEnd;
  sWSDLPortsforPortType   = 'WSDL Ports for PortType';
  sWSDLFor                = '';
  sServiceInfoPage        = 'Service Info Page';

implementation

end.
