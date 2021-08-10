// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'XMLSchemaTags.pas' rev: 6.00

#ifndef XMLSchemaTagsHPP
#define XMLSchemaTagsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Xmlschematags
{
//-- type declarations -------------------------------------------------------
typedef WideString XMLSchemaTags__1[45];

typedef WideString XMLSchemaTags__2[11];

//-- var, const, procedure ---------------------------------------------------
#define SAbstract "abstract"
#define SAll "all"
#define SAnnotation "annotation"
#define SAny "any"
#define SAppInfo "appinfo"
#define SAttribute "attribute"
#define SAttributeFormDefault "attributeFormDefault"
#define SAttributeGroup "attributeGroup"
#define SBase "base"
#define SBase64 "base64"
#define SBlockDefault "blockDefault"
#define SChoice "choice"
#define SComplexContent "complexContent"
#define SComplexType "complexType"
#define SDefault "default"
#define SDerivedBy "derivedBy"
#define SDocumentation "documentation"
#define SElement "element"
#define SElementFormDefault "elementFormDefault"
#define SExtension "extension"
#define SFinalDefault "finalDefault"
#define SFixed "fixed"
#define SGroup "group"
#define SHex "hex"
#define SImport "import"
#define SInclude "include"
#define SList "list"
#define SMaxOccurs "maxOccurs"
#define SMinOccurs "minOccurs"
#define SMixed "mixed"
#define SName "name"
#define SNotation "notation"
#define SOptional "optional"
#define SPublic "public"
#define SProhibited "prohibited"
#define SQualified "qualified"
#define SRef "ref"
#define SRequired "required"
#define SRestriction "restriction"
#define SSchema "schema"
#define SSchemaLocation "schemaLocation"
#define SSequence "sequence"
#define SSimpleContent "simpleContent"
#define SSimpleType "simpleType"
#define SSource "source"
#define SSystem "system"
#define STargetNamespace "targetNamespace"
#define SType "type"
#define SUnbounded "unbounded"
#define SUnqualified "unqualified"
#define SUse "use"
#define SValue "value"
#define SVersion "version"
#define xsdString "string"
#define xsdBoolean "boolean"
#define xsdDecimal "decimal"
#define xsdFloat "float"
#define xsdDouble "double"
#define xsdDuration "duration"
#define xsdDateTime "dateTime"
#define xsdTime "time"
#define xsdDate "date"
#define xsdGYearMonth "gYearMonth"
#define xsdGYear "gYear"
#define xsdGMonthDay "gMonthDay"
#define xsdGDay "gDay"
#define xsdGMonth "gMonth"
#define xsdHexBinary "hexBinary"
#define xsdBase64Binary "base64Binary"
#define xsdAnyUri "anyURI"
#define xsdQName "QName"
#define xsdNOTATION "NOTATION"
#define xsdNormalizedString "normalizedString"
#define xsdToken "token"
#define xsdLanguage "language"
#define xsdIDREFS "IDREFS"
#define xsdENTITIES "ENTITIES"
#define xsdNMTOKEN "NMTOKEN"
#define xsdNMTOKENS "NMTOKENS"
#define xsdName "Name"
#define xsdNCName "NCName"
#define xsdID "ID"
#define xsdIDREF "IDREF"
#define xsdENTITY "ENTITY"
#define xsdInteger "integer"
#define xsdNonPositiveInteger "nonPositiveInteger"
#define xsdNegativeInteger "negativeInteger"
#define xsdLong "long"
#define xsdInt "int"
#define xsdShort "short"
#define xsdByte "byte"
#define xsdNonNegativeInteger "nonNegativeInteger"
#define xsdUnsignedLong "unsignedLong"
#define xsdUnsignedInt "unsignedInt"
#define xsdUnsignedShort "unsignedShort"
#define xsdUnsignedByte "unsignedByte"
#define xsdPositiveInteger "positiveInteger"
#define xsdTimeDuration "timeDuration"
#define xsdBinary "binary"
#define xsdUriReference "uriReference"
#define xsdTimeInstant "timeInstant"
#define xsdRecurringDate "recurringDate"
#define xsdRecurringDay "recurringDay"
#define xsdMonth "month"
#define xsdYear "year"
#define xsdTimePeriod "timePeriod"
#define xsdRecurringDuration "recurringDuration"
#define xsdCentury "century"
#define xsdanySimpleType "anySimpleType"
#define xsfOrdered "ordered"
#define xsfBounded "bounded"
#define xsfCardinality "cardinality"
#define xsfNumeric "numeric"
#define xsfLength "length"
#define xsfMinLength "minLength"
#define xsfMaxLength "maxLength"
#define xsfPattern "pattern"
#define xsfEnumeration "enumeration"
#define xsfMaxInclusive "maxInclusive"
#define xsfMaxExclusive "maxExclusive"
#define xsfMinInclusive "minInclusive"
#define xsfMinExclusive "minExclusive"
#define xsfWhitespace "whiteSpace"
#define xsfTotalDigits "totalDigits"
#define xsfFractionalDigits "fractionalDigits"
extern PACKAGE WideString BuiltInTypeNames[45];
extern PACKAGE WideString LegacyTypeNames[11];
extern PACKAGE System::ResourceString _SInvalidSchema;
#define Xmlschematags_SInvalidSchema System::LoadResourceString(&Xmlschematags::_SInvalidSchema)
extern PACKAGE System::ResourceString _SNoLocalTypeName;
#define Xmlschematags_SNoLocalTypeName System::LoadResourceString(&Xmlschematags::_SNoLocalTypeName)
extern PACKAGE System::ResourceString _SUnknownDataType;
#define Xmlschematags_SUnknownDataType System::LoadResourceString(&Xmlschematags::_SUnknownDataType)
extern PACKAGE System::ResourceString _SInvalidValue;
#define Xmlschematags_SInvalidValue System::LoadResourceString(&Xmlschematags::_SInvalidValue)
extern PACKAGE System::ResourceString _SInvalidGroupDecl;
#define Xmlschematags_SInvalidGroupDecl System::LoadResourceString(&Xmlschematags::_SInvalidGroupDecl)
extern PACKAGE System::ResourceString _SMissingName;
#define Xmlschematags_SMissingName System::LoadResourceString(&Xmlschematags::_SMissingName)
extern PACKAGE System::ResourceString _SInvalidDerivation;
#define Xmlschematags_SInvalidDerivation System::LoadResourceString(&Xmlschematags::_SInvalidDerivation)
extern PACKAGE System::ResourceString _SNoNameOnRef;
#define Xmlschematags_SNoNameOnRef System::LoadResourceString(&Xmlschematags::_SNoNameOnRef)
extern PACKAGE System::ResourceString _SNoGlobalRef;
#define Xmlschematags_SNoGlobalRef System::LoadResourceString(&Xmlschematags::_SNoGlobalRef)
extern PACKAGE System::ResourceString _SNoRefPropSet;
#define Xmlschematags_SNoRefPropSet System::LoadResourceString(&Xmlschematags::_SNoRefPropSet)
extern PACKAGE System::ResourceString _SSetGroupRefProp;
#define Xmlschematags_SSetGroupRefProp System::LoadResourceString(&Xmlschematags::_SSetGroupRefProp)
extern PACKAGE System::ResourceString _SNoContentModel;
#define Xmlschematags_SNoContentModel System::LoadResourceString(&Xmlschematags::_SNoContentModel)
extern PACKAGE System::ResourceString _SNoFacetsAllowed;
#define Xmlschematags_SNoFacetsAllowed System::LoadResourceString(&Xmlschematags::_SNoFacetsAllowed)
extern PACKAGE System::ResourceString _SNotBuiltInType;
#define Xmlschematags_SNotBuiltInType System::LoadResourceString(&Xmlschematags::_SNotBuiltInType)
extern PACKAGE System::ResourceString _SBuiltInType;
#define Xmlschematags_SBuiltInType System::LoadResourceString(&Xmlschematags::_SBuiltInType)

}	/* namespace Xmlschematags */
using namespace Xmlschematags;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// XMLSchemaTags
