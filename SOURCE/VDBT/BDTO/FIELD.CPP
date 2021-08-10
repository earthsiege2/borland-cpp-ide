//-----------------------------------------------------------------------------
// Visual Database Tools
// Copyright (c) 1996 by Borland International, All Rights Reserved
//
// field.cpp
// TField and TBlobField wrapper classes
//-----------------------------------------------------------------------------

#include <vdbt\bdto.h>

#pragma hdrstop

#include "wrapit.h"
#include "misc.h"

//-----------------------------------------------------------------------------

static void _export STDAPICALLTYPE FieldNotifyEventCallback( int32 data, PITField field )
{
	if (data)
	{
		PTField ezField = WrapPITField( field );

		TFieldNotifySource* source = (TFieldNotifySource*) data;
		(*source)( *ezField );

		if (ezField)
			delete ezField;
	}
}

void TField::AttachOnChange( const TBdtEventSourceBase&, bool attach )
{
	if (field)
	{
		AttachedOnChange = attach;
		if (attach)
			field->AttachOnChange( FieldNotifyEventCallback, (int32) &OnChangeSource );
		else
			field->DetachOnChange( FieldNotifyEventCallback, (int32) &OnChangeSource );
	}
}

void TField::AttachOnValidate( const TBdtEventSourceBase&, bool attach )
{
	if (field)
	{
		AttachedOnValidate = attach;
		if (attach)
			field->AttachOnValidate( FieldNotifyEventCallback, (int32) &OnValidateSource );
		else
			field->DetachOnValidate( FieldNotifyEventCallback, (int32) &OnValidateSource );
	}
}


static void _export STDAPICALLTYPE FieldGetTextEventCallback( int32 data, PITField field, PITAnyString Text, VARIANT_BOOL DisplayText )
{
	if (data)
	{
		PTField ezField = WrapPITField( field );
		string* ezText = new string;
		AnyString( Text ).GetString( *ezText );
		bool ezDisplayText = MakeBool( DisplayText );

		TFieldGetTextSource* source = (TFieldGetTextSource*) data;
		(*source)( *ezField, *ezText, ezDisplayText );

		if (ezText)
		{
			Text->put_AsStringBuf( ezText->c_str() );
			delete ezText;
		}
		if (ezField)
			delete ezField;
	}
}

void TField::AttachOnGetText( const TBdtEventSourceBase&, bool attach )
{
	if (field)
	{
		AttachedOnGetText = attach;
		if (attach)
			field->AttachOnGetText( FieldGetTextEventCallback, (int32) &OnGetTextSource );
		else
			field->DetachOnGetText( FieldGetTextEventCallback, (int32) &OnGetTextSource );
	}
}

static void _export STDAPICALLTYPE FieldSetTextEventCallback( int32 data, PITField field, PITAnyString Text )
{
	if (data)
	{
		PTField ezField = WrapPITField( field );
		string* ezText = new string;
		AnyString( Text ).GetString( *ezText );

		TFieldSetTextSource* source = (TFieldSetTextSource*) data;
		(*source)( *ezField, *ezText );

		if (ezText)
			delete ezText;
		if (ezField)
			delete ezField;
	}
}

void TField::AttachOnSetText( const TBdtEventSourceBase&, bool attach )
{
	if (field)
	{
		AttachedOnSetText = attach;
		if (attach)
			field->AttachOnSetText( FieldSetTextEventCallback, (int32) &OnSetTextSource );
		else
			field->DetachOnSetText( FieldSetTextEventCallback, (int32) &OnSetTextSource );
	}
}

void TField::DetachEvents( void )
{
	if (field)
	{
		if (AttachedOnChange)
			field->DetachOnChange( FieldNotifyEventCallback, (int32) &OnChangeSource );
		if (AttachedOnGetText)
			field->DetachOnGetText( FieldGetTextEventCallback, (int32) &OnGetTextSource );
		if (AttachedOnSetText)
			field->DetachOnSetText( FieldSetTextEventCallback, (int32) &OnSetTextSource );
		if (AttachedOnValidate)
			field->DetachOnValidate( FieldNotifyEventCallback, (int32) &OnValidateSource );
	}
}

void TField::ReattachEvents( void )
{
	if (field)
	{
		if (AttachedOnChange)
			field->AttachOnChange( FieldNotifyEventCallback, (int32) &OnChangeSource );
		if (AttachedOnGetText)
			field->AttachOnGetText( FieldGetTextEventCallback, (int32) &OnGetTextSource );
		if (AttachedOnSetText)
			field->AttachOnSetText( FieldSetTextEventCallback, (int32) &OnSetTextSource );
		if (AttachedOnValidate)
			field->AttachOnValidate( FieldNotifyEventCallback, (int32) &OnValidateSource );
	}
}

//-----------------------------------------------------------------------------

void TField::SetTField( PIUnknown p )
{
	field = 0;
	if (p)
		p->QueryInterface( IID_ITField, (void**) &field );
	ReattachEvents();
}

void TField::ClearTField( void )
{
	DetachEvents();
	if (field)
	{
		field->Release();
		field = 0;
	}
}

TField::TField( PTBDTComponent Owner, TFieldType DataType ) :
	TBDTComponent(),
	OnChangeSource( SrcAttach_MFUNCTOR( *this, &TField::AttachOnChange ) ),
	AttachedOnChange( false ),
	OnGetTextSource( SrcAttach_MFUNCTOR( *this, &TField::AttachOnGetText ) ),
	AttachedOnGetText( false ),
	OnSetTextSource( SrcAttach_MFUNCTOR( *this, &TField::AttachOnSetText ) ),
	AttachedOnSetText( false ),
	OnValidateSource( SrcAttach_MFUNCTOR( *this, &TField::AttachOnValidate ) ),
	AttachedOnValidate( false )
{
	field = CreateITField( Owner ? Owner->GetPITBDTComponent() : 0, DataType);
	TBDTComponent::SetPIT( field );
}

TField::TField( void ) :
	TBDTComponent(),
	OnChangeSource( SrcAttach_MFUNCTOR( *this, &TField::AttachOnChange ) ),
	AttachedOnChange( false ),
	OnGetTextSource( SrcAttach_MFUNCTOR( *this, &TField::AttachOnGetText ) ),
	AttachedOnGetText( false ),
	OnSetTextSource( SrcAttach_MFUNCTOR( *this, &TField::AttachOnSetText ) ),
	AttachedOnSetText( false ),
	OnValidateSource( SrcAttach_MFUNCTOR( *this, &TField::AttachOnValidate ) ),
	AttachedOnValidate( false )
{
	field = CreateITField( 0, ftUnknown);
	TBDTComponent::SetPIT( field );
}

TField::TField( PITField p ) :
	TBDTComponent( p ),
	OnChangeSource( SrcAttach_MFUNCTOR( *this, &TField::AttachOnChange ) ),
	AttachedOnChange( false ),
	OnGetTextSource( SrcAttach_MFUNCTOR( *this, &TField::AttachOnGetText ) ),
	AttachedOnGetText( false ),
	OnSetTextSource( SrcAttach_MFUNCTOR( *this, &TField::AttachOnSetText ) ),
	AttachedOnSetText( false ),
	OnValidateSource( SrcAttach_MFUNCTOR( *this, &TField::AttachOnValidate ) ),
	AttachedOnValidate( false )
{
	SetTField( p );
}

TField::TField( const TField& p ) :
	TBDTComponent( p ),
	OnChangeSource( SrcAttach_MFUNCTOR( *this, &TField::AttachOnChange ) ),
	AttachedOnChange( false ),
	OnGetTextSource( SrcAttach_MFUNCTOR( *this, &TField::AttachOnGetText ) ),
	AttachedOnGetText( false ),
	OnSetTextSource( SrcAttach_MFUNCTOR( *this, &TField::AttachOnSetText ) ),
	AttachedOnSetText( false ),
	OnValidateSource( SrcAttach_MFUNCTOR( *this, &TField::AttachOnValidate ) ),
	AttachedOnValidate( false )
{
	SetTField( p.field );
}

TField::TField( PTField p ) :
	TBDTComponent( p ),
	OnChangeSource( SrcAttach_MFUNCTOR( *this, &TField::AttachOnChange ) ),
	AttachedOnChange( false ),
	OnGetTextSource( SrcAttach_MFUNCTOR( *this, &TField::AttachOnGetText ) ),
	AttachedOnGetText( false ),
	OnSetTextSource( SrcAttach_MFUNCTOR( *this, &TField::AttachOnSetText ) ),
	AttachedOnSetText( false ),
	OnValidateSource( SrcAttach_MFUNCTOR( *this, &TField::AttachOnValidate ) ),
	AttachedOnValidate( false )
{
	SetTField( p ? p->field : 0 );
}

TField& TField::operator=( PITField p )
{
	TBDTComponent::operator=(p);
	ClearTField();
	SetTField( p );
	return *this;
}

TField& TField::operator=( const TField& p )
{
	if (this != &p)
	{
		TBDTComponent::operator=(p);
		ClearTField();
		SetTField( p.field );
	}
	return *this;
}

int TField::operator==( const TField& p ) const
{
	if (this == &p)
		return true;
	if (field == p.field)
		return true;
	return false;
}

int TField::operator!=( const TField& p ) const
{
	return ! operator==(p);
}

TField::~TField()
{
	ClearTField();
}

void TField::SetPIT( PIUnknown p )
{
	ClearTField();
	SetTField( p );
	TBDTComponent::SetPIT( p );
}

void TField::AssignValue( TVarRec& v )
{
	if (field)
		field->AssignValue( v.GetVariant() );
}

void TField::Clear( void )
{
	if (field)
		field->Clear();
}

bool TField::GetData( LPVOID buffer )
{
	if (field)
		return MakeBool( field->GetData( buffer ) );
	return true;
}

void TField::SetData( LPVOID buffer )
{
	if (field)
		field->SetData( buffer );
}

bool TField::IsValidChar( char c )
{
	if (field)
		return MakeBool( field->IsValidChar( c ) );
	return false;
}

DEFINE_BDTO_PROP_RW( TField, bool, AsBoolean );
DEFINE_BDTO_PROP_RW( TField, DATE, AsDateTime );
DEFINE_BDTO_PROP_RW( TField, double, AsFloat );
DEFINE_BDTO_PROP_RW( TField, int32, AsInteger );
DEFINE_BDTO_OBJECTPROP_RW( TField, string, AsString );
DEFINE_BDTO_PROP_RO( TField, bool, CanModify );
DEFINE_BDTO_OBJECTPROP_RW_FAST( TField, TDataSet, PITDataSet, DataSet );
DEFINE_BDTO_PROP_RO( TField, int, DataSize );
DEFINE_BDTO_PROP_RO( TField, TFieldType, DataType );
DEFINE_BDTO_OBJECTPROP_RO( TField, string, DisplayText );
DEFINE_BDTO_OBJECTPROP_RW( TField, string, EditMask );
DEFINE_BDTO_PROP_RO( TField, int, FieldNo );
DEFINE_BDTO_PROP_RO( TField, bool, IsIndexField );
DEFINE_BDTO_PROP_RO( TField, bool, IsNull );
DEFINE_BDTO_PROP_RW( TField, uint16, Size );
DEFINE_BDTO_OBJECTPROP_RW( TField, string, Text );

void TField::GetAsBoolean( bool& b )
{
	if (field)
		b = MakeBool( field->get_AsBoolean() );
}

void TField::SetAsBoolean( bool b )
{
	if (field)
		field->put_AsBoolean( MakeVariantBool( b ) );
}

void TField::GetAsDateTime( DATE& d )
{
	if (field)
		d = field->get_AsDateTime();
}

void TField::SetAsDateTime( DATE d )
{
	if (field)
		field->put_AsDateTime( d );
}

void TField::GetAsFloat( double& d )
{
	if (field)
		d = field->get_AsFloat();
}

void TField::SetAsFloat( double d )
{
	if (field)
		field->put_AsFloat( d );
}

void TField::GetAsInteger( int32& i )
{
	if (field)
		i = field->get_AsInteger();
}

void TField::SetAsInteger( int32 i )
{
	if (field)
		field->put_AsInteger( i );
}

void TField::GetAsString( string& s )
{
	if (field)
		AnyString( field->get_AsString() ).GetString( s );
}

void TField::SetAsString( const string& s )
{
	if (field)
		field->put_AsString( AnyString(s).GetPITAnyString() );
}

void TField::GetCanModify( bool& c )
{
	if (field)
		c = MakeBool( field->get_CanModify() );
}

void TField::GetDataSet( TDataSet& d )
{
	if (field)
	{
		PITDataSet pit = field->get_DataSet();
		if (pit)
		{
			d.SetPIT( pit );
			pit->Release();
		}
	}
}

void TField::SetDataSet( const TDataSet& d )
{
	if (field)
		field->put_DataSet( d.GetPITDataSet() );
}

void TField::GetDataSize( int& s )
{
	if (field)
		s = field->get_DataSize();
}

void TField::GetDataType( TFieldType& t )
{
	if (field)
		t = field->get_DataType();
}

void TField::GetDisplayText( string& s )
{
	if (field)
		AnyString( field->get_DisplayText() ).GetString( s );
}

void TField::GetEditMask( string& s )
{
	if (field)
		AnyString( field->get_EditMask() ).GetString( s );
}

void TField::SetEditMask( const string& m )
{
	if (field)
		field->put_EditMask( AnyString(m).GetPITAnyString() );
}

void TField::GetFieldNo( int& n )
{
	if (field)
		n = field->get_FieldNo();
}

void TField::GetIsIndexField( bool& i )
{
	if (field)
		i = MakeBool( field->get_IsIndexField() );
}

void TField::GetIsNull( bool& i )
{
	if (field)
		i = MakeBool( field->get_IsNull() );
}

void TField::GetSize( uint16& s )
{
	if (field)
		s = field->get_Size();
}

void TField::SetSize( uint16 s )
{
	if (field)
		field->put_Size( s );
}

void TField::GetText( string& s )
{
	if (field)
		AnyString( field->get_Text() ).GetString( s );
}

void TField::SetText( const string& t )
{
	if (field)
		field->put_Text( AnyString(t).GetPITAnyString() );
}

DEFINE_BDTO_PROP_RW( TField, bool, Calculated );
DEFINE_BDTO_OBJECTPROP_RW( TField, string, FieldName );
DEFINE_BDTO_PROP_RW( TField, int, Index );
DEFINE_BDTO_PROP_RW( TField, bool, ReadOnly );
DEFINE_BDTO_PROP_RW( TField, bool, Required );
DEFINE_BDTO_PROP_RW( TField, bool, Visible );

void TField::GetCalculated( bool& c )
{
	if (field)
		c = MakeBool( field->get_Calculated() );
}

void TField::SetCalculated( bool c )
{
	if (field)
		field->put_Calculated( MakeVariantBool( c ) );
}

void TField::GetFieldName( string& s )
{
	if (field)
		AnyString( field->get_FieldName() ).GetString( s );
}

void TField::SetFieldName( const string& n )
{
	if (field)
		field->put_FieldName( AnyString(n).GetPITAnyString() );
}

void TField::GetIndex( int& i )
{
	if (field)
		i = field->get_Index();
}

void TField::SetIndex( int i )
{
	if (field)
		field->put_Index( i );
}

void TField::GetReadOnly( bool& r )
{
	if (field)
		r = MakeBool( field->get_ReadOnly() );
}

void TField::SetReadOnly( bool r )
{
	if (field)
		field->put_ReadOnly( MakeVariantBool( r ) );
}

void TField::GetRequired( bool& r )
{
	if (field)
		r = MakeBool( field->get_Required() );
}

void TField::SetRequired( bool r )
{
	if (field)
		field->put_Required( MakeVariantBool( r ) );
}

void TField::SetVisible( bool v )
{
	if (field)
		field->put_Visible( MakeVariantBool( v ) );
}

void TField::GetVisible( bool& v )
{
	if (field)
		v = MakeBool( field->get_Visible() );
}

//-----------------------------------------------------------------------------

#define DEFINE_DERIVED_FIELD( type, base )                                    \
	type::type( PITField p ) : base( p )                                       \
	{                                                                          \
	}                                                                          \
	type::type( const TField& p ) : base( p )                                  \
	{                                                                          \
	}                                                                          \
	type::type( PTField p ) : base( p )                                        \
	{                                                                          \
	}                                                                          \
	type& type::operator=( PITField p )                                        \
	{                                                                          \
		base::operator=(p);                                                     \
		return *this;                                                           \
	}                                                                          \
	type& type::operator=( const TField& p )                                   \
	{                                                                          \
		if (this != &p)                                                         \
			base::operator=(p);                                                  \
		return *this;                                                           \
	}                                                                          \
	int type::operator==( const TField& p ) const                              \
	{                                                                          \
		return base::operator==(p);                                             \
	}                                                                          \
	int type::operator!=( const TField& p ) const                              \
	{                                                                          \
		return base::operator!=(p);                                             \
	}                                                                          \
	type::~type()                                                              \
	{                                                                          \
	}

//-----------------------------------------------------------------------------

DEFINE_DERIVED_FIELD( TStringField, TField )

TStringField::TStringField( void ) : TField( 0, ftString )
{
}

TStringField::TStringField( PTBDTComponent Owner ) : TField( Owner, ftString )
{
}

DEFINE_BDTO_OBJECTPROP_RW( TStringField, string, Value );

void TStringField::GetValue( string& s )
{
	GetAsString( s );
}

void TStringField::SetValue( const string& s )
{
	SetAsString( s );
}

DEFINE_BDTO_PROP_RW( TStringField, bool, Transliterate );

void TStringField::GetTransliterate( bool& t )
{
	if (field)
		t = MakeBool( field->get_Transliterate() );
}

void TStringField::SetTransliterate( bool t )
{
	if (field)
		field->put_Transliterate( MakeVariantBool( t ) );
}

//-----------------------------------------------------------------------------

DEFINE_DERIVED_FIELD( TNumericField, TField )

TNumericField::TNumericField( void ) : TField( 0, ftFloat )
{
}

TNumericField::TNumericField( PTBDTComponent Owner, TFieldType DataType ) : TField( Owner, DataType )
{
}

DEFINE_BDTO_OBJECTPROP_RW( TNumericField, string, DisplayFormat );
DEFINE_BDTO_OBJECTPROP_RW( TNumericField, string, EditFormat );

void TNumericField::GetDisplayFormat( string& s )
{
	if (field)
		AnyString( field->get_DisplayFormat() ).GetString( s );
}

void TNumericField::SetDisplayFormat( const string& s )
{
	if (field)
		field->put_DisplayFormat( AnyString(s).GetPITAnyString() );
}

void TNumericField::GetEditFormat( string& s )
{
	if (field)
		AnyString( field->get_EditFormat() ).GetString( s );
}

void TNumericField::SetEditFormat( const string& s )
{
	if (field)
		field->put_EditFormat( AnyString(s).GetPITAnyString() );
}

//-----------------------------------------------------------------------------

DEFINE_DERIVED_FIELD( TIntegerField, TNumericField )

TIntegerField::TIntegerField( void ) : TNumericField( 0, ftInteger )
{
}

TIntegerField::TIntegerField( PTBDTComponent Owner ) : TNumericField( Owner, ftInteger )
{
}

TIntegerField::TIntegerField( PTBDTComponent Owner, TFieldType DataType ) : TNumericField( Owner, DataType )
{
}

DEFINE_BDTO_PROP_RW( TIntegerField, int32, Value );

void TIntegerField::GetValue( int32& v )
{
	GetAsInteger( v );
}

void TIntegerField::SetValue( int32 v )
{
	SetAsInteger( v );
}

DEFINE_BDTO_PROP_RW( TIntegerField, int32, MaxValue );
DEFINE_BDTO_PROP_RW( TIntegerField, int32, MinValue );

void TIntegerField::GetMaxValue( int32& v )
{
	if (field)
		v = field->get_MaxValueAsInteger();
}

void TIntegerField::SetMaxValue( int32 v )
{
	if (field)
		field->put_MaxValueAsInteger( v );
}

void TIntegerField::GetMinValue( int32& v )
{
	if (field)
		v = field->get_MinValueAsInteger();
}

void TIntegerField::SetMinValue( int32 v )
{
	if (field)
		field->put_MinValueAsInteger( v );
}

//-----------------------------------------------------------------------------

DEFINE_DERIVED_FIELD( TSmallintField, TIntegerField )

TSmallintField::TSmallintField( void ) : TIntegerField( 0, ftSmallint )
{
}

TSmallintField::TSmallintField( PTBDTComponent Owner ) : TIntegerField( Owner, ftSmallint )
{
}

//-----------------------------------------------------------------------------

DEFINE_DERIVED_FIELD( TWordField, TIntegerField )

TWordField::TWordField( void ) : TIntegerField( 0, ftWord )
{
}

TWordField::TWordField( PTBDTComponent Owner ) : TIntegerField( Owner, ftWord )
{
}

//-----------------------------------------------------------------------------

DEFINE_DERIVED_FIELD( TFloatField, TNumericField )

TFloatField::TFloatField( void ) : TNumericField( 0, ftFloat)
{
}

TFloatField::TFloatField( PTBDTComponent Owner ) : TNumericField( Owner, ftFloat )
{
}

TFloatField::TFloatField( PTBDTComponent Owner, TFieldType DataType ) : TNumericField( Owner, DataType )
{
}

DEFINE_BDTO_PROP_RW( TFloatField, double, Value );

void TFloatField::GetValue( double& v )
{
	GetAsFloat( v );
}

void TFloatField::SetValue( double v )
{
	SetAsFloat( v );
}

DEFINE_BDTO_PROP_RW( TFloatField, bool, Currency );
DEFINE_BDTO_PROP_RW( TFloatField, double, MaxValue );
DEFINE_BDTO_PROP_RW( TFloatField, double, MinValue );
DEFINE_BDTO_PROP_RW( TFloatField, int, Precision );

void TFloatField::GetCurrency( bool& c )
{
	if (field)
		c = MakeBool( field->get_Currency() );
}

void TFloatField::SetCurrency( bool c )
{
	if (field)
		field->put_Currency( MakeVariantBool( c ) );
}

void TFloatField::GetMaxValue( double& v )
{
	if (field)
		v = field->get_MaxValueAsFloat();
}

void TFloatField::SetMaxValue( double v )
{
	if (field)
		field->put_MaxValueAsFloat( v );
}

void TFloatField::GetMinValue( double& v )
{
	if (field)
		v = field->get_MinValueAsFloat();
}

void TFloatField::SetMinValue( double v )
{
	if (field)
		field->put_MinValueAsFloat( v );
}

void TFloatField::GetPrecision( int& p )
{
	if (field)
		p = field->get_Precision();
}

void TFloatField::SetPrecision( int p )
{
	if (field)
		field->put_Precision( p );
}

//-----------------------------------------------------------------------------

DEFINE_DERIVED_FIELD( TCurrencyField, TFloatField )

TCurrencyField::TCurrencyField( void ) : TFloatField( 0, ftCurrency )
{
}

TCurrencyField::TCurrencyField( PTBDTComponent Owner ) : TFloatField( Owner, ftCurrency )
{
}

//-----------------------------------------------------------------------------

DEFINE_DERIVED_FIELD( TBCDField, TFloatField )

TBCDField::TBCDField( void ) : TFloatField( 0, ftBCD )
{
}

TBCDField::TBCDField( PTBDTComponent Owner ) : TFloatField( Owner, ftBCD )
{
}

//-----------------------------------------------------------------------------

DEFINE_DERIVED_FIELD( TBooleanField, TField )

TBooleanField::TBooleanField( void ) : TField( 0, ftBoolean )
{
}

TBooleanField::TBooleanField( PTBDTComponent Owner ) : TField( Owner, ftBoolean )
{
}

DEFINE_BDTO_PROP_RW( TBooleanField, bool, Value );

void TBooleanField::GetValue( bool& v )
{
	GetAsBoolean( v );
}

void TBooleanField::SetValue( bool v )
{
	SetAsBoolean( v );
}

DEFINE_BDTO_OBJECTPROP_RW( TBooleanField, string, DisplayValues );

void TBooleanField::GetDisplayValues( string& s )
{
	if (field)
		AnyString( field->get_DisplayValues() ).GetString( s );
}

void TBooleanField::SetDisplayValues( const string& s )
{
	if (field)
		field->put_DisplayValues( AnyString(s).GetPITAnyString() );
}

//-----------------------------------------------------------------------------

DEFINE_DERIVED_FIELD( TDateTimeField, TField )

TDateTimeField::TDateTimeField( void ) : TField( 0, ftDateTime )
{
}

TDateTimeField::TDateTimeField( PTBDTComponent Owner ) : TField( Owner, ftDateTime )
{
}

TDateTimeField::TDateTimeField( PTBDTComponent Owner, TFieldType DataType ) : TField( Owner, DataType )
{
}

DEFINE_BDTO_PROP_RW( TDateTimeField, DATE, Value );

void TDateTimeField::GetValue( DATE& v )
{
	GetAsDateTime( v );
}

void TDateTimeField::SetValue( DATE v )
{
	SetAsDateTime( v );
}

DEFINE_BDTO_OBJECTPROP_RW( TDateTimeField, string, DisplayFormat );

void TDateTimeField::GetDisplayFormat( string& s )
{
	if (field)
		AnyString( field->get_DisplayFormat() ).GetString( s );
}

void TDateTimeField::SetDisplayFormat( const string& s )
{
	if (field)
		field->put_DisplayFormat( AnyString(s).GetPITAnyString() );
}

//-----------------------------------------------------------------------------

DEFINE_DERIVED_FIELD( TDateField, TDateTimeField )

TDateField::TDateField( void ) : TDateTimeField( 0, ftDate )
{
}

TDateField::TDateField( PTBDTComponent Owner ) : TDateTimeField( Owner, ftDate )
{
}

//-----------------------------------------------------------------------------

DEFINE_DERIVED_FIELD( TTimeField, TDateTimeField )

TTimeField::TTimeField( void ) : TDateTimeField( 0, ftTime )
{
}

TTimeField::TTimeField( PTBDTComponent Owner ) : TDateTimeField( Owner, ftTime )
{
}

//-----------------------------------------------------------------------------

DEFINE_DERIVED_FIELD( TBytesField, TField )

TBytesField::TBytesField( void ) : TField( 0, ftBytes )
{
}

TBytesField::TBytesField( PTBDTComponent Owner ) : TField( Owner, ftBytes )
{
}

//-----------------------------------------------------------------------------

DEFINE_DERIVED_FIELD( TVarBytesField, TField )

TVarBytesField::TVarBytesField( void ) : TField( 0, ftVarBytes )
{
}

TVarBytesField::TVarBytesField( PTBDTComponent Owner ) : TField( Owner, ftVarBytes )
{
}

//-----------------------------------------------------------------------------

DEFINE_DERIVED_FIELD( TBlobField, TField )

TBlobField::TBlobField( void ) : TField( 0, ftBlob )
{
}

TBlobField::TBlobField( PTBDTComponent Owner ) : TField( Owner, ftBlob )
{
}

TBlobField::TBlobField( PTBDTComponent Owner, TFieldType DataType ) : TField( Owner, DataType )
{
}

void TBlobField::LoadFromFile( const string& filename )
{
	if (field)
		field->LoadFromFile( AnyString(filename).GetPITAnyString() );
}

void TBlobField::LoadFromStream( TMemoryStream& stream )
{
	if (field)
		field->LoadFromStream( stream.GetPITMemoryStream() );
}

void TBlobField::SaveToFile( const string& filename )
{
	if (field)
		field->SaveToFile( AnyString(filename).GetPITAnyString() );
}

void TBlobField::SaveToStream( TMemoryStream& stream )
{
	if (field)
		field->SaveToStream( stream.GetPITMemoryStream() );
}

//-----------------------------------------------------------------------------

DEFINE_DERIVED_FIELD( TMemoField, TBlobField )

TMemoField::TMemoField( void ) : TBlobField( 0, ftMemo )
{
}

TMemoField::TMemoField( PTBDTComponent Owner ) : TBlobField( Owner, ftMemo )
{
}

DEFINE_BDTO_PROP_RW( TMemoField, bool, Transliterate );

void TMemoField::GetTransliterate( bool& t )
{
	if (field)
		t = MakeBool( field->get_Transliterate() );
}

void TMemoField::SetTransliterate( bool t )
{
	if (field)
		field->put_Transliterate( MakeVariantBool( t ) );
}

//-----------------------------------------------------------------------------

DEFINE_DERIVED_FIELD( TGraphicField, TBlobField )

TGraphicField::TGraphicField( void ) : TBlobField( 0, ftGraphic )
{
}

TGraphicField::TGraphicField( PTBDTComponent Owner ) : TBlobField( Owner, ftGraphic )
{
}

void TGraphicField::SaveToBitmap( HBITMAP& hbitmap, HPALETTE& hpalette )
{
	if (field)
		field->SaveToBitmap( &hbitmap, &hpalette );
}

void TGraphicField::LoadFromBitmap( HBITMAP hbitmap, HPALETTE hpalette )
{
	if (field)
		field->LoadFromBitmap( hbitmap, hpalette );
}

//-----------------------------------------------------------------------------
