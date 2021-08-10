//-----------------------------------------------------------------------------
// Visual Database Tools
// Copyright (c) 1996 by Borland International, All Rights Reserved
//
// datasour.cpp
// TDataSource wrapper class
//-----------------------------------------------------------------------------

#include <vdbt\bdto.h>

#pragma hdrstop

#include "wrapit.h"
#include "misc.h"

#include <stdarg.h>
#include <stdio.h>

//-----------------------------------------------------------------------------

static void STDAPICALLTYPE _export DataSourceNotifyEventCallback( int32 data, PITDataSource datasource )
{
	if (data)
	{
		PTDataSource ezDataSource = WrapPITDataSource( datasource );

		TDataSourceNotifySource* source = (TDataSourceNotifySource*) data;
		(*source)( *ezDataSource );

		if (ezDataSource)
			delete ezDataSource;
	}
}

void TDataSource::AttachOnStateChange( const TBdtEventSourceBase&, bool attach )
{
	if (datasource)
	{
		AttachedOnStateChange = attach;
		if (attach)
			datasource->AttachOnStateChange( DataSourceNotifyEventCallback, (int32) &OnStateChangeSource );
		else
			datasource->DetachOnStateChange( DataSourceNotifyEventCallback, (int32) &OnStateChangeSource );
	}
}

void TDataSource::AttachOnUpdateData( const TBdtEventSourceBase&, bool attach )
{
	if (datasource)
	{
		AttachedOnUpdateData = attach;
		if (attach)
			datasource->AttachOnUpdateData( DataSourceNotifyEventCallback, (int32) &OnUpdateDataSource );
		else
			datasource->DetachOnUpdateData( DataSourceNotifyEventCallback, (int32) &OnUpdateDataSource );
	}
}

static void STDAPICALLTYPE _export DataChangeEventCallback( int32 data, PITDataSource datasource, PITField field )
{
	if (data)
	{
		PTDataSource ezDataSource = WrapPITDataSource( datasource );
		PTField ezField = WrapPITField( field );

		TDataChangeSource* source = (TDataChangeSource*) data;
		(*source)( *ezDataSource, ezField );

		if (ezField)
			delete ezField;
		if (ezDataSource)
			delete ezDataSource;
	}
}

void TDataSource::AttachOnDataChange( const TBdtEventSourceBase&, bool attach )
{
	if (datasource)
	{
		AttachedOnDataChange = attach;
		if (attach)
			datasource->AttachOnDataChange( DataChangeEventCallback, (int32) &OnDataChangeSource );
		else
			datasource->DetachOnDataChange( DataChangeEventCallback, (int32) &OnDataChangeSource );
	}
}

void TDataSource::DetachEvents( void )
{
	if (datasource)
	{
		if (AttachedOnStateChange)
			datasource->DetachOnStateChange( DataSourceNotifyEventCallback, (int32) &OnStateChangeSource );
		if (AttachedOnDataChange)
			datasource->DetachOnDataChange( DataChangeEventCallback, (int32) &OnDataChangeSource );
		if (AttachedOnUpdateData)
			datasource->DetachOnUpdateData( DataSourceNotifyEventCallback, (int32) &OnUpdateDataSource );
	}
}

void TDataSource::ReattachEvents( void )
{
	if (datasource)
	{
		if (AttachedOnStateChange)
			datasource->AttachOnStateChange( DataSourceNotifyEventCallback, (int32) &OnStateChangeSource );
		if (AttachedOnDataChange)
			datasource->AttachOnDataChange( DataChangeEventCallback, (int32) &OnDataChangeSource );
		if (AttachedOnUpdateData)
			datasource->AttachOnUpdateData( DataSourceNotifyEventCallback, (int32) &OnUpdateDataSource );
	}
}

//-----------------------------------------------------------------------------

void TDataSource::SetTDataSource( PIUnknown p )
{
	datasource = 0;
	if (p)
		p->QueryInterface( IID_ITDataSource, (void**) &datasource );
	ReattachEvents();
}

void TDataSource::ClearTDataSource( void )
{
	DetachEvents();
	if (datasource)
	{
		datasource->Release();
		datasource = 0;
	}
}

TDataSource::TDataSource( void ) :
	TBDTComponent(),
	OnStateChangeSource( SrcAttach_MFUNCTOR( *this, &TDataSource::AttachOnStateChange ) ),
	AttachedOnStateChange( false ),
	OnDataChangeSource( SrcAttach_MFUNCTOR( *this, &TDataSource::AttachOnDataChange ) ),
	AttachedOnDataChange( false ),
	OnUpdateDataSource( SrcAttach_MFUNCTOR( *this, &TDataSource::AttachOnUpdateData ) ),
	AttachedOnUpdateData( false )
{
	datasource = CreateITDataSource();
	TBDTComponent::SetPIT( datasource );
}

TDataSource::TDataSource( PITDataSource p ) :
	TBDTComponent( p ),
	OnStateChangeSource( SrcAttach_MFUNCTOR( *this, &TDataSource::AttachOnStateChange ) ),
	AttachedOnStateChange( false ),
	OnDataChangeSource( SrcAttach_MFUNCTOR( *this, &TDataSource::AttachOnDataChange ) ),
	AttachedOnDataChange( false ),
	OnUpdateDataSource( SrcAttach_MFUNCTOR( *this, &TDataSource::AttachOnUpdateData ) ),
	AttachedOnUpdateData( false )
{
	SetTDataSource( p );
}

TDataSource::TDataSource( const TDataSource& p ) :
	TBDTComponent( p ),
	OnStateChangeSource( SrcAttach_MFUNCTOR( *this, &TDataSource::AttachOnStateChange ) ),
	AttachedOnStateChange( false ),
	OnDataChangeSource( SrcAttach_MFUNCTOR( *this, &TDataSource::AttachOnDataChange ) ),
	AttachedOnDataChange( false ),
	OnUpdateDataSource( SrcAttach_MFUNCTOR( *this, &TDataSource::AttachOnUpdateData ) ),
	AttachedOnUpdateData( false )
{
	SetTDataSource( p.datasource );
}

TDataSource::TDataSource( PTDataSource p ) :
	TBDTComponent( p ),
	OnStateChangeSource( SrcAttach_MFUNCTOR( *this, &TDataSource::AttachOnStateChange ) ),
	AttachedOnStateChange( false ),
	OnDataChangeSource( SrcAttach_MFUNCTOR( *this, &TDataSource::AttachOnDataChange ) ),
	AttachedOnDataChange( false ),
	OnUpdateDataSource( SrcAttach_MFUNCTOR( *this, &TDataSource::AttachOnUpdateData ) ),
	AttachedOnUpdateData( false )
{
	SetTDataSource( p ? p->datasource : 0 );
}

TDataSource::TDataSource( HWND hdlg, int idc ) :
	TBDTComponent(),
	OnStateChangeSource( SrcAttach_MFUNCTOR( *this, &TDataSource::AttachOnStateChange ) ),
	AttachedOnStateChange( false ),
	OnDataChangeSource( SrcAttach_MFUNCTOR( *this, &TDataSource::AttachOnDataChange ) ),
	AttachedOnDataChange( false ),
	OnUpdateDataSource( SrcAttach_MFUNCTOR( *this, &TDataSource::AttachOnUpdateData ) ),
	AttachedOnUpdateData( false )
{
	SetTDataSource( GetVBXPIUnknown( hdlg, idc ) );
	TBDTComponent::SetPIT( datasource );
}

void TDataSource::AttachToControl( HWND hdlg, int idc )
{
	SetPIT( GetVBXPIUnknown( hdlg, idc ) );
}

void TDataSource::AttachControl( HWND hdlg, int idc )
{
	SetVBXPIUnknown( hdlg, idc, datasource );
}

TDataSource& TDataSource::operator=( PITDataSource p )
{
	TBDTComponent::operator=(p);
	ClearTDataSource();
	SetTDataSource( p );
	return *this;
}

TDataSource& TDataSource::operator=( const TDataSource& p )
{
	if (this != &p)
	{
		TBDTComponent::operator=(p);
		ClearTDataSource();
		SetTDataSource( p.datasource );
	}
	return *this;
}

int TDataSource::operator==( const TDataSource& p ) const
{
	if (this == &p)
		return true;
	if (datasource == p.datasource)
		return true;
	return false;
}

int TDataSource::operator!=( const TDataSource& p ) const
{
	return ! operator==(p);
}

TDataSource::~TDataSource()
{
	ClearTDataSource();
}

void TDataSource::SetPIT( PIUnknown p )
{
	ClearTDataSource();
	SetTDataSource( p );
	TBDTComponent::SetPIT( p );
}

void TDataSource::Edit( void )
{
	if (datasource)
		datasource->Edit();
}

bool TDataSource::IsLinkedTo( TDataSet& DataSet )
{
	if (datasource)
		return MakeBool( datasource->IsLinkedTo( DataSet.GetPITDataSet() ) );
	return false;
}

DEFINE_BDTO_PROP_RO( TDataSource, TDataSetState, State );

void TDataSource::GetState( TDataSetState& s )
{
	if (datasource)
		s = datasource->get_State();
}

DEFINE_BDTO_PROP_RW( TDataSource, bool, AutoEdit );
DEFINE_BDTO_OBJECTPROP_RW_FAST( TDataSource, TDataSet, PITDataSet, DataSet );
DEFINE_BDTO_PROP_RW( TDataSource, bool, Enabled );

void TDataSource::GetAutoEdit( bool& a )
{
	if (datasource)
		a = MakeBool( datasource->get_AutoEdit() );
}

void TDataSource::SetAutoEdit( bool a )
{
	if (datasource)
		datasource->put_AutoEdit( MakeVariantBool( a ) );
}

void TDataSource::GetDataSet( TDataSet& d )
{
	if (datasource)
	{
		PITDataSet pit = datasource->get_DataSet();
		if (pit)
		{
			d.SetPIT( pit );
			pit->Release();
		}
	}
}

void TDataSource::SetDataSet( const TDataSet& d )
{
	if (datasource)
		datasource->put_DataSet( d.GetPITDataSet() );
}

void TDataSource::GetEnabled( bool& e )
{
	if (datasource)
		e = MakeBool( datasource->get_Enabled() );
}

void TDataSource::SetEnabled( bool e )
{
	if (datasource)
		datasource->put_Enabled( MakeVariantBool( e ) );
}
