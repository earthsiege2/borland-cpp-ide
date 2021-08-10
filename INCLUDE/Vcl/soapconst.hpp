// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'SOAPConst.pas' rev: 6.00

#ifndef SOAPConstHPP
#define SOAPConstHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <XMLSchema.hpp>	// Pascal unit
#include <TypInfo.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Soapconst
{
//-- type declarations -------------------------------------------------------
typedef AnsiString SOAPConst__1[18];

typedef AnsiString SOAPConst__2[2];

//-- var, const, procedure ---------------------------------------------------
#define SSoapXMLHeader "<?xml version=\"1.0\" encoding='UTF-8'?>"
#define SUTF8 "UTF-8"
#define ContentHeaderUTF8 "Content-Type: text/xml; charset=\"utf-8\""
#define ContentHeaderNoUTF8 "Content-Type: text/xml"
#define sTextHtml "text/html"
#define sTextXML "text/xml"
#define ContentTypeUTF8 "text/xml; charset=\"utf-8\""
#define ContentTypeNoUTF8 "text/xml"
#define SSoapNameSpace "http://schemas.xmlsoap.org/soap/envelope/"
#define SXMLNS "xmlns"
#define SSoapEncodingAttr "encodingStyle"
#define SSoap11EncodingS5 "http://schemas.xmlsoap.org/soap/encoding/"
#define SSoapEncodingArray "Array"
#define SSoapEncodingArrayType "arrayType"
#define SSoapHTTPTransport "http://schemas.xmlsoap.org/soap/http"
#define SSoapBodyUseEncoded "encoded"
#define SSoapBodyUseLiteral "literal"
#define SSoapEnvelope "Envelope"
#define SSoapHeader "Header"
#define SSoapBody "Body"
#define SSoapResponseSuff "Response"
#define SSoapMustUnderstand "mustUnderstand"
#define SSoapActor "actor"
#define SSoapServerFaultCode "Server"
#define SSoapServerFaultString "Server Error"
#define SSoapFault "Fault"
#define SSoapFaultCode "faultcode"
#define SSoapFaultString "faultstring"
#define SSoapFaultActor "faultactor"
#define SSoapFaultDetails "detail"
#define SHTTPSoapAction "SOAPAction"
#define SSoapType "type"
#define SSoapResponse "Response"
#define SDefaultReturnName "return"
#define SDefaultResultName "result"
#define SXMLID "id"
#define SXMLHREF "href"
#define SSoapNULL "NULL"
static const char SHREFPre = '\x23';
#define SArrayIDPre "Array-"
static const char SDefVariantElemName = '\x56';
#define SDelphiTypeNamespace "http://www.borland.com/namespaces/Delphi/Types"
#define SBorlandTypeNamespace "http://www.borland.com/namespaces/Types"
#define SOperationNameSpecifier "%operationName%"
#define SDefaultReturnParamNames "Result;Return"
#define sReturnParamDelimiters ";,/:"
extern PACKAGE AnsiString KindNameArray[18];
#define SSoapNameSpacePre "SOAP-ENV"
#define SXMLSchemaNameSpacePre "xsd"
#define SXMLSchemaInstNameSpace99Pre "xsi"
#define SSoapEncodingPre "SOAP-ENC"
#define HTMLStylBeg "<style type=\"text/css\"><!--\r\n"
#define HTMLStylEnd "--></style>\r\n"
#define BodyStyle1 "body       {font-family: Verdana, Arial, Helvetica, sans-s"\
	"erif; font-size: 9pt; }\r\n"
#define BodyStyle2 "body       {font-family: Verdana, Arial, Helvetica, sans-s"\
	"erif; font-size: 9pt; margin-left: 0px; margin-top: 0px; m"\
	"argin-right: 0px; }\r\n"
#define OtherStyles "h1         {color: #006699; font-size: 18pt; font-style: n"\
	"ormal; font-weight: bold; }\r\nh2         {color: #006699;"\
	" font-size: 14pt; font-style: normal; font-weight: bold; }"\
	"\r\nh3         {color: #006699; font-size: 12pt; font-styl"\
	"e: normal; font-weight: bold; }\r\n.h1Style   {color: #006"\
	"699; font-size: 18pt; font-style: normal; font-weight: bol"\
	"d; }\r\n.TblRow    {color: #006699; font-family: Verdana, "\
	"Arial, Helvetica, sans-serif; font-size: 10pt; font-weight"\
	": normal; }\r\n.TblRow1   {color: #006699; background-colo"\
	"r: #FFFFCC; font-family: Verdana, Arial, Helvetica, sans-s"\
	"erif; font-size: 9pt; font-weight: normal; }\r\n.TblRow0  "\
	" {color: #006699; background-color: #CCCC99; font-family: "\
	"Verdana, Arial, Helvetica, sans-serif; font-size: 9pt; fon"\
	"t-weight: normal; }\r\n.TblHdr    {color: #CCCC99; backgro"\
	"und-color: #006699; font-family: Verdana, Arial, Helvetica"\
	", sans-serif; font-size: 10pt; font-weight: bold; text-ali"\
	"gn: center;}\r\n.IntfName  {color: #006699; font-family: V"\
	"erdana, Arial, Helvetica, sans-serif; font-size: 10pt; fon"\
	"t-weight: bold; }\r\n.MethName  {color: #006699; font-fami"\
	"ly: Verdana, Arial, Helvetica, sans-serif; font-size: 8pt;"\
	" font-weight: bold; text-decoration: none; }\r\n.ParmName "\
	" {color: #006699; font-family: Verdana, Arial, Helvetica, "\
	"sans-serif; font-size: 8pt; text-decoration: none; }\r\n.N"\
	"amespace {color: #006699; font-family: Verdana, Arial, Hel"\
	"vetica, sans-serif; font-size: 9pt; font-style: italic; }\r"\
	"\n.WSDL      {color: #666699; font-family: Verdana, Arial,"\
	" Helvetica, sans-serif; font-size: 8pt; font-weight: bold;"\
	" }\r\n.MainBkgnd {background-color : #CCCC99; }\r\n.Info  "\
	"    {font-family: Verdana, Arial, Helvetica, sans-serif; f"\
	"ont-size: 12pt; font-weight: bold; }\r\n.NavBar    {color:"\
	" #006699; background-color: #CCCCCC; font-family: Verdana,"\
	" Arial, Helvetica, sans-serif; font-size: 8pt; font-weight"\
	": bold;text-decoration: none; }\r\n.Off       {color: #A0A"\
	"0A0; }\r\n.Tip \t    {color: #666666; font-family : Verdan"\
	"a, Arial, Helvetica, sans-serif; font-weight : normal; fon"\
	"t-size : 9pt; }\r\n"
#define HTMLStyles "<style type=\"text/css\"><!--\r\nbody       {font-family: "\
	"Verdana, Arial, Helvetica, sans-serif; font-size: 9pt; }\r"\
	"\nh1         {color: #006699; font-size: 18pt; font-style:"\
	" normal; font-weight: bold; }\r\nh2         {color: #00669"\
	"9; font-size: 14pt; font-style: normal; font-weight: bold;"\
	" }\r\nh3         {color: #006699; font-size: 12pt; font-st"\
	"yle: normal; font-weight: bold; }\r\n.h1Style   {color: #0"\
	"06699; font-size: 18pt; font-style: normal; font-weight: b"\
	"old; }\r\n.TblRow    {color: #006699; font-family: Verdana"\
	", Arial, Helvetica, sans-serif; font-size: 10pt; font-weig"\
	"ht: normal; }\r\n.TblRow1   {color: #006699; background-co"\
	"lor: #FFFFCC; font-family: Verdana, Arial, Helvetica, sans"\
	"-serif; font-size: 9pt; font-weight: normal; }\r\n.TblRow0"\
	"   {color: #006699; background-color: #CCCC99; font-family"\
	": Verdana, Arial, Helvetica, sans-serif; font-size: 9pt; f"\
	"ont-weight: normal; }\r\n.TblHdr    {color: #CCCC99; backg"\
	"round-color: #006699; font-family: Verdana, Arial, Helveti"\
	"ca, sans-serif; font-size: 10pt; font-weight: bold; text-a"\
	"lign: center;}\r\n.IntfName  {color: #006699; font-family:"\
	" Verdana, Arial, Helvetica, sans-serif; font-size: 10pt; f"\
	"ont-weight: bold; }\r\n.MethName  {color: #006699; font-fa"\
	"mily: Verdana, Arial, Helvetica, sans-serif; font-size: 8p"\
	"t; font-weight: bold; text-decoration: none; }\r\n.ParmNam"\
	"e  {color: #006699; font-family: Verdana, Arial, Helvetica"\
	", sans-serif; font-size: 8pt; text-decoration: none; }\r\n"\
	".Namespace {color: #006699; font-family: Verdana, Arial, H"\
	"elvetica, sans-serif; font-size: 9pt; font-style: italic; "\
	"}\r\n.WSDL      {color: #666699; font-family: Verdana, Ari"\
	"al, Helvetica, sans-serif; font-size: 8pt; font-weight: bo"\
	"ld; }\r\n.MainBkgnd {background-color : #CCCC99; }\r\n.Inf"\
	"o      {font-family: Verdana, Arial, Helvetica, sans-serif"\
	"; font-size: 12pt; font-weight: bold; }\r\n.NavBar    {col"\
	"or: #006699; background-color: #CCCCCC; font-family: Verda"\
	"na, Arial, Helvetica, sans-serif; font-size: 8pt; font-wei"\
	"ght: bold;text-decoration: none; }\r\n.Off       {color: #"\
	"A0A0A0; }\r\n.Tip \t    {color: #666666; font-family : Ver"\
	"dana, Arial, Helvetica, sans-serif; font-weight : normal; "\
	"font-size : 9pt; }\r\n--></style>\r\n"
#define HTMLNoMargin "<style type=\"text/css\"><!--\r\nbody       {font-family: "\
	"Verdana, Arial, Helvetica, sans-serif; font-size: 9pt; mar"\
	"gin-left: 0px; margin-top: 0px; margin-right: 0px; }\r\nh1"\
	"         {color: #006699; font-size: 18pt; font-style: nor"\
	"mal; font-weight: bold; }\r\nh2         {color: #006699; f"\
	"ont-size: 14pt; font-style: normal; font-weight: bold; }\r"\
	"\nh3         {color: #006699; font-size: 12pt; font-style:"\
	" normal; font-weight: bold; }\r\n.h1Style   {color: #00669"\
	"9; font-size: 18pt; font-style: normal; font-weight: bold;"\
	" }\r\n.TblRow    {color: #006699; font-family: Verdana, Ar"\
	"ial, Helvetica, sans-serif; font-size: 10pt; font-weight: "\
	"normal; }\r\n.TblRow1   {color: #006699; background-color:"\
	" #FFFFCC; font-family: Verdana, Arial, Helvetica, sans-ser"\
	"if; font-size: 9pt; font-weight: normal; }\r\n.TblRow0   {"\
	"color: #006699; background-color: #CCCC99; font-family: Ve"\
	"rdana, Arial, Helvetica, sans-serif; font-size: 9pt; font-"\
	"weight: normal; }\r\n.TblHdr    {color: #CCCC99; backgroun"\
	"d-color: #006699; font-family: Verdana, Arial, Helvetica, "\
	"sans-serif; font-size: 10pt; font-weight: bold; text-align"\
	": center;}\r\n.IntfName  {color: #006699; font-family: Ver"\
	"dana, Arial, Helvetica, sans-serif; font-size: 10pt; font-"\
	"weight: bold; }\r\n.MethName  {color: #006699; font-family"\
	": Verdana, Arial, Helvetica, sans-serif; font-size: 8pt; f"\
	"ont-weight: bold; text-decoration: none; }\r\n.ParmName  {"\
	"color: #006699; font-family: Verdana, Arial, Helvetica, sa"\
	"ns-serif; font-size: 8pt; text-decoration: none; }\r\n.Nam"\
	"espace {color: #006699; font-family: Verdana, Arial, Helve"\
	"tica, sans-serif; font-size: 9pt; font-style: italic; }\r\n"\
	".WSDL      {color: #666699; font-family: Verdana, Arial, H"\
	"elvetica, sans-serif; font-size: 8pt; font-weight: bold; }"\
	"\r\n.MainBkgnd {background-color : #CCCC99; }\r\n.Info    "\
	"  {font-family: Verdana, Arial, Helvetica, sans-serif; fon"\
	"t-size: 12pt; font-weight: bold; }\r\n.NavBar    {color: #"\
	"006699; background-color: #CCCCCC; font-family: Verdana, A"\
	"rial, Helvetica, sans-serif; font-size: 8pt; font-weight: "\
	"bold;text-decoration: none; }\r\n.Off       {color: #A0A0A"\
	"0; }\r\n.Tip \t    {color: #666666; font-family : Verdana,"\
	" Arial, Helvetica, sans-serif; font-weight : normal; font-"\
	"size : 9pt; }\r\n--></style>\r\n"
#define TableStyle "border=1 cellspacing=1 cellpadding=2 "
#define HTMLTopPlain "<html><head></head><body>"
#define HTMLTop "<html><head></head><style type=\"text/css\"><!--\r\nbody  "\
	"     {font-family: Verdana, Arial, Helvetica, sans-serif; "\
	"font-size: 9pt; }\r\nh1         {color: #006699; font-size"\
	": 18pt; font-style: normal; font-weight: bold; }\r\nh2    "\
	"     {color: #006699; font-size: 14pt; font-style: normal;"\
	" font-weight: bold; }\r\nh3         {color: #006699; font-"\
	"size: 12pt; font-style: normal; font-weight: bold; }\r\n.h"\
	"1Style   {color: #006699; font-size: 18pt; font-style: nor"\
	"mal; font-weight: bold; }\r\n.TblRow    {color: #006699; f"\
	"ont-family: Verdana, Arial, Helvetica, sans-serif; font-si"\
	"ze: 10pt; font-weight: normal; }\r\n.TblRow1   {color: #00"\
	"6699; background-color: #FFFFCC; font-family: Verdana, Ari"\
	"al, Helvetica, sans-serif; font-size: 9pt; font-weight: no"\
	"rmal; }\r\n.TblRow0   {color: #006699; background-color: #"\
	"CCCC99; font-family: Verdana, Arial, Helvetica, sans-serif"\
	"; font-size: 9pt; font-weight: normal; }\r\n.TblHdr    {co"\
	"lor: #CCCC99; background-color: #006699; font-family: Verd"\
	"ana, Arial, Helvetica, sans-serif; font-size: 10pt; font-w"\
	"eight: bold; text-align: center;}\r\n.IntfName  {color: #0"\
	"06699; font-family: Verdana, Arial, Helvetica, sans-serif;"\
	" font-size: 10pt; font-weight: bold; }\r\n.MethName  {colo"\
	"r: #006699; font-family: Verdana, Arial, Helvetica, sans-s"\
	"erif; font-size: 8pt; font-weight: bold; text-decoration: "\
	"none; }\r\n.ParmName  {color: #006699; font-family: Verdan"\
	"a, Arial, Helvetica, sans-serif; font-size: 8pt; text-deco"\
	"ration: none; }\r\n.Namespace {color: #006699; font-family"\
	": Verdana, Arial, Helvetica, sans-serif; font-size: 9pt; f"\
	"ont-style: italic; }\r\n.WSDL      {color: #666699; font-f"\
	"amily: Verdana, Arial, Helvetica, sans-serif; font-size: 8"\
	"pt; font-weight: bold; }\r\n.MainBkgnd {background-color :"\
	" #CCCC99; }\r\n.Info      {font-family: Verdana, Arial, He"\
	"lvetica, sans-serif; font-size: 12pt; font-weight: bold; }"\
	"\r\n.NavBar    {color: #006699; background-color: #CCCCCC;"\
	" font-family: Verdana, Arial, Helvetica, sans-serif; font-"\
	"size: 8pt; font-weight: bold;text-decoration: none; }\r\n."\
	"Off       {color: #A0A0A0; }\r\n.Tip \t    {color: #666666"\
	"; font-family : Verdana, Arial, Helvetica, sans-serif; fon"\
	"t-weight : normal; font-size : 9pt; }\r\n--></style>\r\n<b"\
	"ody>"
#define HTMLTopNoM "<html><head></head><style type=\"text/css\"><!--\r\nbody  "\
	"     {font-family: Verdana, Arial, Helvetica, sans-serif; "\
	"font-size: 9pt; margin-left: 0px; margin-top: 0px; margin-"\
	"right: 0px; }\r\nh1         {color: #006699; font-size: 18"\
	"pt; font-style: normal; font-weight: bold; }\r\nh2        "\
	" {color: #006699; font-size: 14pt; font-style: normal; fon"\
	"t-weight: bold; }\r\nh3         {color: #006699; font-size"\
	": 12pt; font-style: normal; font-weight: bold; }\r\n.h1Sty"\
	"le   {color: #006699; font-size: 18pt; font-style: normal;"\
	" font-weight: bold; }\r\n.TblRow    {color: #006699; font-"\
	"family: Verdana, Arial, Helvetica, sans-serif; font-size: "\
	"10pt; font-weight: normal; }\r\n.TblRow1   {color: #006699"\
	"; background-color: #FFFFCC; font-family: Verdana, Arial, "\
	"Helvetica, sans-serif; font-size: 9pt; font-weight: normal"\
	"; }\r\n.TblRow0   {color: #006699; background-color: #CCCC"\
	"99; font-family: Verdana, Arial, Helvetica, sans-serif; fo"\
	"nt-size: 9pt; font-weight: normal; }\r\n.TblHdr    {color:"\
	" #CCCC99; background-color: #006699; font-family: Verdana,"\
	" Arial, Helvetica, sans-serif; font-size: 10pt; font-weigh"\
	"t: bold; text-align: center;}\r\n.IntfName  {color: #00669"\
	"9; font-family: Verdana, Arial, Helvetica, sans-serif; fon"\
	"t-size: 10pt; font-weight: bold; }\r\n.MethName  {color: #"\
	"006699; font-family: Verdana, Arial, Helvetica, sans-serif"\
	"; font-size: 8pt; font-weight: bold; text-decoration: none"\
	"; }\r\n.ParmName  {color: #006699; font-family: Verdana, A"\
	"rial, Helvetica, sans-serif; font-size: 8pt; text-decorati"\
	"on: none; }\r\n.Namespace {color: #006699; font-family: Ve"\
	"rdana, Arial, Helvetica, sans-serif; font-size: 9pt; font-"\
	"style: italic; }\r\n.WSDL      {color: #666699; font-famil"\
	"y: Verdana, Arial, Helvetica, sans-serif; font-size: 8pt; "\
	"font-weight: bold; }\r\n.MainBkgnd {background-color : #CC"\
	"CC99; }\r\n.Info      {font-family: Verdana, Arial, Helvet"\
	"ica, sans-serif; font-size: 12pt; font-weight: bold; }\r\n"\
	".NavBar    {color: #006699; background-color: #CCCCCC; fon"\
	"t-family: Verdana, Arial, Helvetica, sans-serif; font-size"\
	": 8pt; font-weight: bold;text-decoration: none; }\r\n.Off "\
	"      {color: #A0A0A0; }\r\n.Tip \t    {color: #666666; fo"\
	"nt-family : Verdana, Arial, Helvetica, sans-serif; font-we"\
	"ight : normal; font-size : 9pt; }\r\n--></style>\r\n<body>"\
	""
#define HTMLTopTNoM "<html><head><title>%s</title></head><style type=\"text/cs"\
	"s\"><!--\r\nbody       {font-family: Verdana, Arial, Helve"\
	"tica, sans-serif; font-size: 9pt; margin-left: 0px; margin"\
	"-top: 0px; margin-right: 0px; }\r\nh1         {color: #006"\
	"699; font-size: 18pt; font-style: normal; font-weight: bol"\
	"d; }\r\nh2         {color: #006699; font-size: 14pt; font-"\
	"style: normal; font-weight: bold; }\r\nh3         {color: "\
	"#006699; font-size: 12pt; font-style: normal; font-weight:"\
	" bold; }\r\n.h1Style   {color: #006699; font-size: 18pt; f"\
	"ont-style: normal; font-weight: bold; }\r\n.TblRow    {col"\
	"or: #006699; font-family: Verdana, Arial, Helvetica, sans-"\
	"serif; font-size: 10pt; font-weight: normal; }\r\n.TblRow1"\
	"   {color: #006699; background-color: #FFFFCC; font-family"\
	": Verdana, Arial, Helvetica, sans-serif; font-size: 9pt; f"\
	"ont-weight: normal; }\r\n.TblRow0   {color: #006699; backg"\
	"round-color: #CCCC99; font-family: Verdana, Arial, Helveti"\
	"ca, sans-serif; font-size: 9pt; font-weight: normal; }\r\n"\
	".TblHdr    {color: #CCCC99; background-color: #006699; fon"\
	"t-family: Verdana, Arial, Helvetica, sans-serif; font-size"\
	": 10pt; font-weight: bold; text-align: center;}\r\n.IntfNa"\
	"me  {color: #006699; font-family: Verdana, Arial, Helvetic"\
	"a, sans-serif; font-size: 10pt; font-weight: bold; }\r\n.M"\
	"ethName  {color: #006699; font-family: Verdana, Arial, Hel"\
	"vetica, sans-serif; font-size: 8pt; font-weight: bold; tex"\
	"t-decoration: none; }\r\n.ParmName  {color: #006699; font-"\
	"family: Verdana, Arial, Helvetica, sans-serif; font-size: "\
	"8pt; text-decoration: none; }\r\n.Namespace {color: #00669"\
	"9; font-family: Verdana, Arial, Helvetica, sans-serif; fon"\
	"t-size: 9pt; font-style: italic; }\r\n.WSDL      {color: #"\
	"666699; font-family: Verdana, Arial, Helvetica, sans-serif"\
	"; font-size: 8pt; font-weight: bold; }\r\n.MainBkgnd {back"\
	"ground-color : #CCCC99; }\r\n.Info      {font-family: Verd"\
	"ana, Arial, Helvetica, sans-serif; font-size: 12pt; font-w"\
	"eight: bold; }\r\n.NavBar    {color: #006699; background-c"\
	"olor: #CCCCCC; font-family: Verdana, Arial, Helvetica, san"\
	"s-serif; font-size: 8pt; font-weight: bold;text-decoration"\
	": none; }\r\n.Off       {color: #A0A0A0; }\r\n.Tip \t    {"\
	"color: #666666; font-family : Verdana, Arial, Helvetica, s"\
	"ans-serif; font-weight : normal; font-size : 9pt; }\r\n-->"\
	"</style>\r\n<body>"
#define HTMLTopNS "<html><head></head><body>"
#define HTMLTopTitle "<html><head><title>%s</title></head><style type=\"text/cs"\
	"s\"><!--\r\nbody       {font-family: Verdana, Arial, Helve"\
	"tica, sans-serif; font-size: 9pt; }\r\nh1         {color: "\
	"#006699; font-size: 18pt; font-style: normal; font-weight:"\
	" bold; }\r\nh2         {color: #006699; font-size: 14pt; f"\
	"ont-style: normal; font-weight: bold; }\r\nh3         {col"\
	"or: #006699; font-size: 12pt; font-style: normal; font-wei"\
	"ght: bold; }\r\n.h1Style   {color: #006699; font-size: 18p"\
	"t; font-style: normal; font-weight: bold; }\r\n.TblRow    "\
	"{color: #006699; font-family: Verdana, Arial, Helvetica, s"\
	"ans-serif; font-size: 10pt; font-weight: normal; }\r\n.Tbl"\
	"Row1   {color: #006699; background-color: #FFFFCC; font-fa"\
	"mily: Verdana, Arial, Helvetica, sans-serif; font-size: 9p"\
	"t; font-weight: normal; }\r\n.TblRow0   {color: #006699; b"\
	"ackground-color: #CCCC99; font-family: Verdana, Arial, Hel"\
	"vetica, sans-serif; font-size: 9pt; font-weight: normal; }"\
	"\r\n.TblHdr    {color: #CCCC99; background-color: #006699;"\
	" font-family: Verdana, Arial, Helvetica, sans-serif; font-"\
	"size: 10pt; font-weight: bold; text-align: center;}\r\n.In"\
	"tfName  {color: #006699; font-family: Verdana, Arial, Helv"\
	"etica, sans-serif; font-size: 10pt; font-weight: bold; }\r"\
	"\n.MethName  {color: #006699; font-family: Verdana, Arial,"\
	" Helvetica, sans-serif; font-size: 8pt; font-weight: bold;"\
	" text-decoration: none; }\r\n.ParmName  {color: #006699; f"\
	"ont-family: Verdana, Arial, Helvetica, sans-serif; font-si"\
	"ze: 8pt; text-decoration: none; }\r\n.Namespace {color: #0"\
	"06699; font-family: Verdana, Arial, Helvetica, sans-serif;"\
	" font-size: 9pt; font-style: italic; }\r\n.WSDL      {colo"\
	"r: #666699; font-family: Verdana, Arial, Helvetica, sans-s"\
	"erif; font-size: 8pt; font-weight: bold; }\r\n.MainBkgnd {"\
	"background-color : #CCCC99; }\r\n.Info      {font-family: "\
	"Verdana, Arial, Helvetica, sans-serif; font-size: 12pt; fo"\
	"nt-weight: bold; }\r\n.NavBar    {color: #006699; backgrou"\
	"nd-color: #CCCCCC; font-family: Verdana, Arial, Helvetica,"\
	" sans-serif; font-size: 8pt; font-weight: bold;text-decora"\
	"tion: none; }\r\n.Off       {color: #A0A0A0; }\r\n.Tip \t "\
	"   {color: #666666; font-family : Verdana, Arial, Helvetic"\
	"a, sans-serif; font-weight : normal; font-size : 9pt; }\r\n"\
	"--></style>\r\n<body>"
#define HTMLEnd "</body></html>"
#define InfoTitle1 "<table class=\"MainBkgnd\" border=0 cellpadding=0 cellspac"\
	"ing=0 width=\"100%\"><tr><td>&nbsp;</td></tr>"
#define InfoTitle2 "<tr><td class=\"h1Style\" align=\"center\">%s - %s</td><"\
	"/tr></table>"
extern PACKAGE AnsiString TblCls[2];
#define sTblRow "TblRow"
#define sTblHdrCls "TblHdr"
#define sQueryStringIntf "intf"
#define sQueryStringTypes "types"
#define sNBSP "&nbsp;"
extern PACKAGE AnsiString XMLSchemaNameSpace;
extern PACKAGE AnsiString XMLSchemaInstNameSpace;
extern PACKAGE System::ResourceString _SUnsupportedEncodingSyle;
#define Soapconst_SUnsupportedEncodingSyle System::LoadResourceString(&Soapconst::_SUnsupportedEncodingSyle)
extern PACKAGE System::ResourceString _SInvalidSoapRequest;
#define Soapconst_SInvalidSoapRequest System::LoadResourceString(&Soapconst::_SInvalidSoapRequest)
extern PACKAGE System::ResourceString _SMultiBodyNotSupported;
#define Soapconst_SMultiBodyNotSupported System::LoadResourceString(&Soapconst::_SMultiBodyNotSupported)
extern PACKAGE System::ResourceString _SUnsupportedCC;
#define Soapconst_SUnsupportedCC System::LoadResourceString(&Soapconst::_SUnsupportedCC)
extern PACKAGE System::ResourceString _SUnsupportedCCIntfMeth;
#define Soapconst_SUnsupportedCCIntfMeth System::LoadResourceString(&Soapconst::_SUnsupportedCCIntfMeth)
extern PACKAGE System::ResourceString _SInvClassNotRegistered;
#define Soapconst_SInvClassNotRegistered System::LoadResourceString(&Soapconst::_SInvClassNotRegistered)
extern PACKAGE System::ResourceString _SInvInterfaceNotReg;
#define Soapconst_SInvInterfaceNotReg System::LoadResourceString(&Soapconst::_SInvInterfaceNotReg)
extern PACKAGE System::ResourceString _SInvInterfaceNotRegURL;
#define Soapconst_SInvInterfaceNotRegURL System::LoadResourceString(&Soapconst::_SInvInterfaceNotRegURL)
extern PACKAGE System::ResourceString _SRemTypeNotRegistered;
#define Soapconst_SRemTypeNotRegistered System::LoadResourceString(&Soapconst::_SRemTypeNotRegistered)
extern PACKAGE System::ResourceString _STypeMismatchInParam;
#define Soapconst_STypeMismatchInParam System::LoadResourceString(&Soapconst::_STypeMismatchInParam)
extern PACKAGE System::ResourceString _SNoSuchMethod;
#define Soapconst_SNoSuchMethod System::LoadResourceString(&Soapconst::_SNoSuchMethod)
extern PACKAGE System::ResourceString _SInterfaceNotReg;
#define Soapconst_SInterfaceNotReg System::LoadResourceString(&Soapconst::_SInterfaceNotReg)
extern PACKAGE System::ResourceString _SInterfaceNoRTTI;
#define Soapconst_SInterfaceNoRTTI System::LoadResourceString(&Soapconst::_SInterfaceNoRTTI)
extern PACKAGE System::ResourceString _SNoWSDL;
#define Soapconst_SNoWSDL System::LoadResourceString(&Soapconst::_SNoWSDL)
extern PACKAGE System::ResourceString _SWSDLError;
#define Soapconst_SWSDLError System::LoadResourceString(&Soapconst::_SWSDLError)
extern PACKAGE System::ResourceString _SEmptyWSDL;
#define Soapconst_SEmptyWSDL System::LoadResourceString(&Soapconst::_SEmptyWSDL)
extern PACKAGE System::ResourceString _sNoWSDLURL;
#define Soapconst_sNoWSDLURL System::LoadResourceString(&Soapconst::_sNoWSDLURL)
extern PACKAGE System::ResourceString _sCantGetURL;
#define Soapconst_sCantGetURL System::LoadResourceString(&Soapconst::_sCantGetURL)
extern PACKAGE System::ResourceString _SDataTypeNotSupported;
#define Soapconst_SDataTypeNotSupported System::LoadResourceString(&Soapconst::_SDataTypeNotSupported)
extern PACKAGE System::ResourceString _SUnknownSOAPAction;
#define Soapconst_SUnknownSOAPAction System::LoadResourceString(&Soapconst::_SUnknownSOAPAction)
extern PACKAGE System::ResourceString _SScalarFromTRemotableS;
#define Soapconst_SScalarFromTRemotableS System::LoadResourceString(&Soapconst::_SScalarFromTRemotableS)
extern PACKAGE System::ResourceString _SNoSerializeGraphs;
#define Soapconst_SNoSerializeGraphs System::LoadResourceString(&Soapconst::_SNoSerializeGraphs)
extern PACKAGE System::ResourceString _SUnsuportedClassType;
#define Soapconst_SUnsuportedClassType System::LoadResourceString(&Soapconst::_SUnsuportedClassType)
extern PACKAGE System::ResourceString _SUnexpectedDataType;
#define Soapconst_SUnexpectedDataType System::LoadResourceString(&Soapconst::_SUnexpectedDataType)
extern PACKAGE System::ResourceString _SArrayTooManyElem;
#define Soapconst_SArrayTooManyElem System::LoadResourceString(&Soapconst::_SArrayTooManyElem)
extern PACKAGE System::ResourceString _SWrongDocElem;
#define Soapconst_SWrongDocElem System::LoadResourceString(&Soapconst::_SWrongDocElem)
extern PACKAGE System::ResourceString _STooManyParameters;
#define Soapconst_STooManyParameters System::LoadResourceString(&Soapconst::_STooManyParameters)
extern PACKAGE System::ResourceString _SArrayExpected;
#define Soapconst_SArrayExpected System::LoadResourceString(&Soapconst::_SArrayExpected)
extern PACKAGE System::ResourceString _SNoMultiDimVar;
#define Soapconst_SNoMultiDimVar System::LoadResourceString(&Soapconst::_SNoMultiDimVar)
extern PACKAGE System::ResourceString _SNoURL;
#define Soapconst_SNoURL System::LoadResourceString(&Soapconst::_SNoURL)
extern PACKAGE System::ResourceString _SNoInterfaceGUID;
#define Soapconst_SNoInterfaceGUID System::LoadResourceString(&Soapconst::_SNoInterfaceGUID)
extern PACKAGE System::ResourceString _SNoArrayElemRTTI;
#define Soapconst_SNoArrayElemRTTI System::LoadResourceString(&Soapconst::_SNoArrayElemRTTI)
extern PACKAGE System::ResourceString _SInvalidResponse;
#define Soapconst_SInvalidResponse System::LoadResourceString(&Soapconst::_SInvalidResponse)
extern PACKAGE System::ResourceString _SInvalidArraySpec;
#define Soapconst_SInvalidArraySpec System::LoadResourceString(&Soapconst::_SInvalidArraySpec)
extern PACKAGE System::ResourceString _SCannotFindNodeID;
#define Soapconst_SCannotFindNodeID System::LoadResourceString(&Soapconst::_SCannotFindNodeID)
extern PACKAGE System::ResourceString _SNoNativeNULL;
#define Soapconst_SNoNativeNULL System::LoadResourceString(&Soapconst::_SNoNativeNULL)
extern PACKAGE System::ResourceString _SFaultCodeOnlyAllowed;
#define Soapconst_SFaultCodeOnlyAllowed System::LoadResourceString(&Soapconst::_SFaultCodeOnlyAllowed)
extern PACKAGE System::ResourceString _SFaultStringOnlyAllowed;
#define Soapconst_SFaultStringOnlyAllowed System::LoadResourceString(&Soapconst::_SFaultStringOnlyAllowed)
extern PACKAGE System::ResourceString _SMissingFaultValue;
#define Soapconst_SMissingFaultValue System::LoadResourceString(&Soapconst::_SMissingFaultValue)
extern PACKAGE System::ResourceString _SNoInterfacesInClass;
#define Soapconst_SNoInterfacesInClass System::LoadResourceString(&Soapconst::_SNoInterfacesInClass)
extern PACKAGE System::ResourceString _SVariantCastNotSupported;
#define Soapconst_SVariantCastNotSupported System::LoadResourceString(&Soapconst::_SVariantCastNotSupported)
extern PACKAGE System::ResourceString _SVarDateNotSupported;
#define Soapconst_SVarDateNotSupported System::LoadResourceString(&Soapconst::_SVarDateNotSupported)
extern PACKAGE System::ResourceString _SVarDispatchNotSupported;
#define Soapconst_SVarDispatchNotSupported System::LoadResourceString(&Soapconst::_SVarDispatchNotSupported)
extern PACKAGE System::ResourceString _SVarErrorNotSupported;
#define Soapconst_SVarErrorNotSupported System::LoadResourceString(&Soapconst::_SVarErrorNotSupported)
extern PACKAGE System::ResourceString _SVarVariantNotSupported;
#define Soapconst_SVarVariantNotSupported System::LoadResourceString(&Soapconst::_SVarVariantNotSupported)
extern PACKAGE System::ResourceString _SHeaderError;
#define Soapconst_SHeaderError System::LoadResourceString(&Soapconst::_SHeaderError)
extern PACKAGE System::ResourceString _SMissingSoapReturn;
#define Soapconst_SMissingSoapReturn System::LoadResourceString(&Soapconst::_SMissingSoapReturn)
extern PACKAGE System::ResourceString _SInvalidPointer;
#define Soapconst_SInvalidPointer System::LoadResourceString(&Soapconst::_SInvalidPointer)
extern PACKAGE System::ResourceString _SNoMessageConverter;
#define Soapconst_SNoMessageConverter System::LoadResourceString(&Soapconst::_SNoMessageConverter)
extern PACKAGE System::ResourceString _SNoMsgProcessingNode;
#define Soapconst_SNoMsgProcessingNode System::LoadResourceString(&Soapconst::_SNoMsgProcessingNode)
extern PACKAGE System::ResourceString _SHeaderAttributeError;
#define Soapconst_SHeaderAttributeError System::LoadResourceString(&Soapconst::_SHeaderAttributeError)
extern PACKAGE System::ResourceString _SNoRTTI;
#define Soapconst_SNoRTTI System::LoadResourceString(&Soapconst::_SNoRTTI)
extern PACKAGE System::ResourceString _SNoRTTIParam;
#define Soapconst_SNoRTTIParam System::LoadResourceString(&Soapconst::_SNoRTTIParam)
extern PACKAGE System::ResourceString _SInvalidDateString;
#define Soapconst_SInvalidDateString System::LoadResourceString(&Soapconst::_SInvalidDateString)
extern PACKAGE System::ResourceString _SInvalidTimeString;
#define Soapconst_SInvalidTimeString System::LoadResourceString(&Soapconst::_SInvalidTimeString)
extern PACKAGE System::ResourceString _SInvalidHour;
#define Soapconst_SInvalidHour System::LoadResourceString(&Soapconst::_SInvalidHour)
extern PACKAGE System::ResourceString _SInvalidMinute;
#define Soapconst_SInvalidMinute System::LoadResourceString(&Soapconst::_SInvalidMinute)
extern PACKAGE System::ResourceString _SInvalidSecond;
#define Soapconst_SInvalidSecond System::LoadResourceString(&Soapconst::_SInvalidSecond)
extern PACKAGE System::ResourceString _SInvalidFractionSecond;
#define Soapconst_SInvalidFractionSecond System::LoadResourceString(&Soapconst::_SInvalidFractionSecond)
extern PACKAGE System::ResourceString _SInvalidMillisecond;
#define Soapconst_SInvalidMillisecond System::LoadResourceString(&Soapconst::_SInvalidMillisecond)
extern PACKAGE System::ResourceString _SInvalidFractionalSecond;
#define Soapconst_SInvalidFractionalSecond System::LoadResourceString(&Soapconst::_SInvalidFractionalSecond)
extern PACKAGE System::ResourceString _SInvalidHourOffset;
#define Soapconst_SInvalidHourOffset System::LoadResourceString(&Soapconst::_SInvalidHourOffset)
extern PACKAGE System::ResourceString _SInvalidDay;
#define Soapconst_SInvalidDay System::LoadResourceString(&Soapconst::_SInvalidDay)
extern PACKAGE System::ResourceString _SInvalidMonth;
#define Soapconst_SInvalidMonth System::LoadResourceString(&Soapconst::_SInvalidMonth)
extern PACKAGE System::ResourceString _SInvalidDuration;
#define Soapconst_SInvalidDuration System::LoadResourceString(&Soapconst::_SInvalidDuration)
extern PACKAGE System::ResourceString _SMilSecRangeViolation;
#define Soapconst_SMilSecRangeViolation System::LoadResourceString(&Soapconst::_SMilSecRangeViolation)
extern PACKAGE System::ResourceString _SInvalidYearConversion;
#define Soapconst_SInvalidYearConversion System::LoadResourceString(&Soapconst::_SInvalidYearConversion)
extern PACKAGE System::ResourceString _SInvalidTimeOffset;
#define Soapconst_SInvalidTimeOffset System::LoadResourceString(&Soapconst::_SInvalidTimeOffset)
extern PACKAGE System::ResourceString _SInvalidDecimalString;
#define Soapconst_SInvalidDecimalString System::LoadResourceString(&Soapconst::_SInvalidDecimalString)
extern PACKAGE System::ResourceString _SEmptyDecimalString;
#define Soapconst_SEmptyDecimalString System::LoadResourceString(&Soapconst::_SEmptyDecimalString)
extern PACKAGE System::ResourceString _SNoSciNotation;
#define Soapconst_SNoSciNotation System::LoadResourceString(&Soapconst::_SNoSciNotation)
extern PACKAGE System::ResourceString _SNoNAN;
#define Soapconst_SNoNAN System::LoadResourceString(&Soapconst::_SNoNAN)
extern PACKAGE System::ResourceString _SInvalidBcd;
#define Soapconst_SInvalidBcd System::LoadResourceString(&Soapconst::_SInvalidBcd)
extern PACKAGE System::ResourceString _SBcdStringTooBig;
#define Soapconst_SBcdStringTooBig System::LoadResourceString(&Soapconst::_SBcdStringTooBig)
extern PACKAGE System::ResourceString _SInvalidHexValue;
#define Soapconst_SInvalidHexValue System::LoadResourceString(&Soapconst::_SInvalidHexValue)
extern PACKAGE System::ResourceString _SInvalidBooleanParameter;
#define Soapconst_SInvalidBooleanParameter System::LoadResourceString(&Soapconst::_SInvalidBooleanParameter)
extern PACKAGE System::ResourceString _SWideStringOutOfBounds;
#define Soapconst_SWideStringOutOfBounds System::LoadResourceString(&Soapconst::_SWideStringOutOfBounds)
extern PACKAGE System::ResourceString _IWSDLPublishDoc;
#define Soapconst_IWSDLPublishDoc System::LoadResourceString(&Soapconst::_IWSDLPublishDoc)
extern PACKAGE System::ResourceString _SNoServiceForURL;
#define Soapconst_SNoServiceForURL System::LoadResourceString(&Soapconst::_SNoServiceForURL)
extern PACKAGE System::ResourceString _SNoInterfaceForURL;
#define Soapconst_SNoInterfaceForURL System::LoadResourceString(&Soapconst::_SNoInterfaceForURL)
extern PACKAGE System::ResourceString _SNoClassRegisteredForURL;
#define Soapconst_SNoClassRegisteredForURL System::LoadResourceString(&Soapconst::_SNoClassRegisteredForURL)
extern PACKAGE System::ResourceString _SEmptyURL;
#define Soapconst_SEmptyURL System::LoadResourceString(&Soapconst::_SEmptyURL)
extern PACKAGE System::ResourceString _SInvalidURL;
#define Soapconst_SInvalidURL System::LoadResourceString(&Soapconst::_SInvalidURL)
extern PACKAGE System::ResourceString _SNoClassRegistered;
#define Soapconst_SNoClassRegistered System::LoadResourceString(&Soapconst::_SNoClassRegistered)
extern PACKAGE System::ResourceString _SNoDispatcher;
#define Soapconst_SNoDispatcher System::LoadResourceString(&Soapconst::_SNoDispatcher)
extern PACKAGE System::ResourceString _SMethNoRTTI;
#define Soapconst_SMethNoRTTI System::LoadResourceString(&Soapconst::_SMethNoRTTI)
extern PACKAGE System::ResourceString _SUnsupportedVariant;
#define Soapconst_SUnsupportedVariant System::LoadResourceString(&Soapconst::_SUnsupportedVariant)
extern PACKAGE System::ResourceString _SNoVarDispatch;
#define Soapconst_SNoVarDispatch System::LoadResourceString(&Soapconst::_SNoVarDispatch)
extern PACKAGE System::ResourceString _SNoErrorDispatch;
#define Soapconst_SNoErrorDispatch System::LoadResourceString(&Soapconst::_SNoErrorDispatch)
extern PACKAGE System::ResourceString _SUnknownInterface;
#define Soapconst_SUnknownInterface System::LoadResourceString(&Soapconst::_SUnknownInterface)
extern PACKAGE System::ResourceString _SInvalidTimeZone;
#define Soapconst_SInvalidTimeZone System::LoadResourceString(&Soapconst::_SInvalidTimeZone)
extern PACKAGE System::ResourceString _sUnknownError;
#define Soapconst_sUnknownError System::LoadResourceString(&Soapconst::_sUnknownError)
extern PACKAGE System::ResourceString _sErrorColon;
#define Soapconst_sErrorColon System::LoadResourceString(&Soapconst::_sErrorColon)
extern PACKAGE System::ResourceString _sServiceInfo;
#define Soapconst_sServiceInfo System::LoadResourceString(&Soapconst::_sServiceInfo)
extern PACKAGE System::ResourceString _sInterfaceInfo;
#define Soapconst_sInterfaceInfo System::LoadResourceString(&Soapconst::_sInterfaceInfo)
extern PACKAGE System::ResourceString _sRegTypes;
#define Soapconst_sRegTypes System::LoadResourceString(&Soapconst::_sRegTypes)
extern PACKAGE System::ResourceString _sWebServiceListing;
#define Soapconst_sWebServiceListing System::LoadResourceString(&Soapconst::_sWebServiceListing)
extern PACKAGE System::ResourceString _sWebServiceListingAdmin;
#define Soapconst_sWebServiceListingAdmin System::LoadResourceString(&Soapconst::_sWebServiceListingAdmin)
extern PACKAGE System::ResourceString _sPortType;
#define Soapconst_sPortType System::LoadResourceString(&Soapconst::_sPortType)
extern PACKAGE System::ResourceString _sNameSpaceURI;
#define Soapconst_sNameSpaceURI System::LoadResourceString(&Soapconst::_sNameSpaceURI)
extern PACKAGE System::ResourceString _sDocumentation;
#define Soapconst_sDocumentation System::LoadResourceString(&Soapconst::_sDocumentation)
extern PACKAGE System::ResourceString _sWSDL;
#define Soapconst_sWSDL System::LoadResourceString(&Soapconst::_sWSDL)
extern PACKAGE System::ResourceString _sPortName;
#define Soapconst_sPortName System::LoadResourceString(&Soapconst::_sPortName)
extern PACKAGE System::ResourceString _sInterfaceNotFound;
#define Soapconst_sInterfaceNotFound System::LoadResourceString(&Soapconst::_sInterfaceNotFound)
extern PACKAGE System::ResourceString _sForbiddenAccess;
#define Soapconst_sForbiddenAccess System::LoadResourceString(&Soapconst::_sForbiddenAccess)
extern PACKAGE System::ResourceString _sWSDLPortsforPortType;
#define Soapconst_sWSDLPortsforPortType System::LoadResourceString(&Soapconst::_sWSDLPortsforPortType)
extern PACKAGE System::ResourceString _sWSDLFor;
#define Soapconst_sWSDLFor System::LoadResourceString(&Soapconst::_sWSDLFor)
extern PACKAGE System::ResourceString _sServiceInfoPage;
#define Soapconst_sServiceInfoPage System::LoadResourceString(&Soapconst::_sServiceInfoPage)

}	/* namespace Soapconst */
using namespace Soapconst;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SOAPConst
