//-----------------------------------------------------------------------------
// Visual Database Tools
// Copyright (c) 1996 by Borland International, All Rights Reserved
//
// dataset.cpp
// TDataSet and TDBDataSet wrapper classes
//-----------------------------------------------------------------------------

#include <vdbt\bdto.h>

#pragma hdrstop

#include "wrapit.h"
#include "misc.h"

//-----------------------------------------------------------------------------

static void _export STDAPICALLTYPE DataSetNotifyEventCallback( int32 data, PITDataSet dataset )
{
	if (data)
	{
		PTDataSet ezDataSet = WrapPITDataSet( dataset );

		TDataSetNotifySource* source = (TDataSetNotifySource*) data;
		(*source)( *ezDataSet );

		if (ezDataSet)
			delete ezDataSet;
	}
}

void TDataSet::AttachBeforeOpen( const TBdtEventSourceBase&, bool attach )
{
	if (dataset)
	{
		AttachedBeforeOpen = attach;
		if (attach)
			dataset->AttachBeforeOpen( DataSetNotifyEventCallback, (int32) &BeforeOpenSource );
		else
			dataset->DetachBeforeOpen( DataSetNotifyEventCallback, (int32) &BeforeOpenSource );
	}
}

void TDataSet::AttachAfterOpen( const TBdtEventSourceBase&, bool attach )
{
	if (dataset)
	{
		AttachedAfterOpen = attach;
		if (attach)
			dataset->AttachAfterOpen( DataSetNotifyEventCallback, (int32) &AfterOpenSource );
		else
			dataset->DetachAfterOpen( DataSetNotifyEventCallback, (int32) &AfterOpenSource );
	}
}

void TDataSet::AttachBeforeClose( const TBdtEventSourceBase&, bool attach )
{
	if (dataset)
	{
		AttachedBeforeClose = attach;
		if (attach)
			dataset->AttachBeforeClose( DataSetNotifyEventCallback, (int32) &BeforeCloseSource );
		else
			dataset->DetachBeforeClose( DataSetNotifyEventCallback, (int32) &BeforeCloseSource );
	}
}

void TDataSet::AttachAfterClose( const TBdtEventSourceBase&, bool attach )
{
	if (dataset)
	{
		AttachedAfterClose = attach;
		if (attach)
			dataset->AttachAfterClose( DataSetNotifyEventCallback, (int32) &AfterCloseSource );
		else
			dataset->DetachAfterClose( DataSetNotifyEventCallback, (int32) &AfterCloseSource );
	}
}

void TDataSet::AttachBeforeInsert( const TBdtEventSourceBase&, bool attach )
{
	if (dataset)
	{
		AttachedBeforeInsert = attach;
		if (attach)
			dataset->AttachBeforeInsert( DataSetNotifyEventCallback, (int32) &BeforeInsertSource );
		else
			dataset->DetachBeforeInsert( DataSetNotifyEventCallback, (int32) &BeforeInsertSource );
	}
}

void TDataSet::AttachAfterInsert( const TBdtEventSourceBase&, bool attach )
{
	if (dataset)
	{
		AttachedAfterInsert = attach;
		if (attach)
			dataset->AttachAfterInsert( DataSetNotifyEventCallback, (int32) &AfterInsertSource );
		else
			dataset->DetachAfterInsert( DataSetNotifyEventCallback, (int32) &AfterInsertSource );
	}
}

void TDataSet::AttachBeforeEdit( const TBdtEventSourceBase&, bool attach )
{
	if (dataset)
	{
		AttachedBeforeEdit = attach;
		if (attach)
			dataset->AttachBeforeEdit( DataSetNotifyEventCallback, (int32) &BeforeEditSource );
		else
			dataset->DetachBeforeEdit( DataSetNotifyEventCallback, (int32) &BeforeEditSource );
	}
}

void TDataSet::AttachAfterEdit( const TBdtEventSourceBase&, bool attach )
{
	if (dataset)
	{
		AttachedAfterEdit = attach;
		if (attach)
			dataset->AttachAfterEdit( DataSetNotifyEventCallback, (int32) &AfterEditSource );
		else
			dataset->DetachAfterEdit( DataSetNotifyEventCallback, (int32) &AfterEditSource );
	}
}

void TDataSet::AttachBeforePost( const TBdtEventSourceBase&, bool attach )
{
	if (dataset)
	{
		AttachedBeforePost = attach;
		if (attach)
			dataset->AttachBeforePost( DataSetNotifyEventCallback, (int32) &BeforePostSource );
		else
			dataset->DetachBeforePost( DataSetNotifyEventCallback, (int32) &BeforePostSource );
	}
}

void TDataSet::AttachAfterPost( const TBdtEventSourceBase&, bool attach )
{
	if (dataset)
	{
		AttachedAfterPost = attach;
		if (attach)
			dataset->AttachAfterPost( DataSetNotifyEventCallback, (int32) &AfterPostSource );
		else
			dataset->DetachAfterPost( DataSetNotifyEventCallback, (int32) &AfterPostSource );
	}
}

void TDataSet::AttachBeforeCancel( const TBdtEventSourceBase&, bool attach )
{
	if (dataset)
	{
		AttachedBeforeCancel = attach;
		if (attach)
			dataset->AttachBeforeCancel( DataSetNotifyEventCallback, (int32) &BeforeCancelSource );
		else
			dataset->DetachBeforeCancel( DataSetNotifyEventCallback, (int32) &BeforeCancelSource );
	}
}

void TDataSet::AttachAfterCancel( const TBdtEventSourceBase&, bool attach )
{
	if (dataset)
	{
		AttachedAfterCancel = attach;
		if (attach)
			dataset->AttachAfterCancel( DataSetNotifyEventCallback, (int32) &AfterCancelSource );
		else
			dataset->DetachAfterCancel( DataSetNotifyEventCallback, (int32) &AfterCancelSource );
	}
}

void TDataSet::AttachBeforeDelete( const TBdtEventSourceBase&, bool attach )
{
	if (dataset)
	{
		AttachedBeforeDelete = attach;
		if (attach)
			dataset->AttachBeforeDelete( DataSetNotifyEventCallback, (int32) &BeforeDeleteSource );
		else
			dataset->DetachBeforeDelete( DataSetNotifyEventCallback, (int32) &BeforeDeleteSource );
	}
}

void TDataSet::AttachAfterDelete( const TBdtEventSourceBase&, bool attach )
{
	if (dataset)
	{
		AttachedAfterDelete = attach;
		if (attach)
			dataset->AttachAfterDelete( DataSetNotifyEventCallback, (int32) &AfterDeleteSource );
		else
			dataset->DetachAfterDelete( DataSetNotifyEventCallback, (int32) &AfterDeleteSource );
	}
}

void TDataSet::AttachOnNewRecord( const TBdtEventSourceBase&, bool attach )
{
	if (dataset)
	{
		AttachedOnNewRecord = attach;
		if (attach)
			dataset->AttachOnNewRecord( DataSetNotifyEventCallback, (int32) &OnNewRecordSource );
		else
			dataset->DetachOnNewRecord( DataSetNotifyEventCallback, (int32) &OnNewRecordSource );
	}
}

void TDataSet::AttachOnCalcFields( const TBdtEventSourceBase&, bool attach )
{
	if (dataset)
	{
		AttachedOnCalcFields = attach;
		if (attach)
			dataset->AttachOnCalcFields( DataSetNotifyEventCallback, (int32) &OnCalcFieldsSource );
		else
			dataset->DetachOnCalcFields( DataSetNotifyEventCallback, (int32) &OnCalcFieldsSource );
	}
}

void TDataSet::DetachEvents( void )
{
	if (dataset)
	{
		if (AttachedBeforeOpen)
			dataset->DetachBeforeOpen( DataSetNotifyEventCallback, (int32) &BeforeOpenSource );
		if (AttachedAfterOpen)
			dataset->DetachAfterOpen( DataSetNotifyEventCallback, (int32) &AfterOpenSource );
		if (AttachedBeforeClose)
			dataset->DetachBeforeClose( DataSetNotifyEventCallback, (int32) &BeforeCloseSource );
		if (AttachedAfterClose)
			dataset->DetachAfterClose( DataSetNotifyEventCallback, (int32) &AfterCloseSource );
		if (AttachedBeforeInsert)
			dataset->DetachBeforeInsert( DataSetNotifyEventCallback, (int32) &BeforeInsertSource );
		if (AttachedAfterInsert)
			dataset->DetachAfterInsert( DataSetNotifyEventCallback, (int32) &AfterInsertSource );
		if (AttachedBeforeEdit)
			dataset->DetachBeforeEdit( DataSetNotifyEventCallback, (int32) &BeforeEditSource );
		if (AttachedAfterEdit)
			dataset->DetachAfterEdit( DataSetNotifyEventCallback, (int32) &AfterEditSource );
		if (AttachedBeforePost)
			dataset->DetachBeforePost( DataSetNotifyEventCallback, (int32) &BeforePostSource );
		if (AttachedAfterPost)
			dataset->DetachAfterPost( DataSetNotifyEventCallback, (int32) &AfterPostSource );
		if (AttachedBeforeCancel)
			dataset->DetachBeforeCancel( DataSetNotifyEventCallback, (int32) &BeforeCancelSource );
		if (AttachedAfterCancel)
			dataset->DetachAfterCancel( DataSetNotifyEventCallback, (int32) &AfterCancelSource );
		if (AttachedBeforeDelete)
			dataset->DetachBeforeDelete( DataSetNotifyEventCallback, (int32) &BeforeDeleteSource );
		if (AttachedAfterDelete)
			dataset->DetachAfterDelete( DataSetNotifyEventCallback, (int32) &AfterDeleteSource );
		if (AttachedOnNewRecord)
			dataset->DetachOnNewRecord( DataSetNotifyEventCallback, (int32) &OnNewRecordSource );
		if (AttachedOnCalcFields)
			dataset->DetachOnCalcFields( DataSetNotifyEventCallback, (int32) &OnCalcFieldsSource );
	}
}

void TDataSet::ReattachEvents( void )
{
	if (dataset)
	{
		if (AttachedBeforeOpen)
			dataset->AttachBeforeOpen( DataSetNotifyEventCallback, (int32) &BeforeOpenSource );
		if (AttachedAfterOpen)
			dataset->AttachAfterOpen( DataSetNotifyEventCallback, (int32) &AfterOpenSource );
		if (AttachedBeforeClose)
			dataset->AttachBeforeClose( DataSetNotifyEventCallback, (int32) &BeforeCloseSource );
		if (AttachedAfterClose)
			dataset->AttachAfterClose( DataSetNotifyEventCallback, (int32) &AfterCloseSource );
		if (AttachedBeforeInsert)
			dataset->AttachBeforeInsert( DataSetNotifyEventCallback, (int32) &BeforeInsertSource );
		if (AttachedAfterInsert)
			dataset->AttachAfterInsert( DataSetNotifyEventCallback, (int32) &AfterInsertSource );
		if (AttachedBeforeEdit)
			dataset->AttachBeforeEdit( DataSetNotifyEventCallback, (int32) &BeforeEditSource );
		if (AttachedAfterEdit)
			dataset->AttachAfterEdit( DataSetNotifyEventCallback, (int32) &AfterEditSource );
		if (AttachedBeforePost)
			dataset->AttachBeforePost( DataSetNotifyEventCallback, (int32) &BeforePostSource );
		if (AttachedAfterPost)
			dataset->AttachAfterPost( DataSetNotifyEventCallback, (int32) &AfterPostSource );
		if (AttachedBeforeCancel)
			dataset->AttachBeforeCancel( DataSetNotifyEventCallback, (int32) &BeforeCancelSource );
		if (AttachedAfterCancel)
			dataset->AttachAfterCancel( DataSetNotifyEventCallback, (int32) &AfterCancelSource );
		if (AttachedBeforeDelete)
			dataset->AttachBeforeDelete( DataSetNotifyEventCallback, (int32) &BeforeDeleteSource );
		if (AttachedAfterDelete)
			dataset->AttachAfterDelete( DataSetNotifyEventCallback, (int32) &AfterDeleteSource );
		if (AttachedOnNewRecord)
			dataset->AttachOnNewRecord( DataSetNotifyEventCallback, (int32) &OnNewRecordSource );
		if (AttachedOnCalcFields)
			dataset->AttachOnCalcFields( DataSetNotifyEventCallback, (int32) &OnCalcFieldsSource );
	}
}

//-----------------------------------------------------------------------------

void TDataSet::SetTDataSet( PIUnknown p )
{
	dataset = 0;
	if (p)
		p->QueryInterface( IID_ITDataSet, (void**) &dataset );
	ReattachEvents();
}

void TDataSet::ClearTDataSet( void )
{
	DetachEvents();
	if (dataset)
	{
		dataset->Release();
		dataset = 0;
	}
}

TDataSet::TDataSet( void ) :
	TBDTComponent(),
	BeforeOpenSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachBeforeOpen ) ),
	AttachedBeforeOpen( false ),
	AfterOpenSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachAfterOpen ) ),
	AttachedAfterOpen( false ),
	BeforeCloseSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachBeforeClose ) ),
	AttachedBeforeClose( false ),
	AfterCloseSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachAfterClose ) ),
	AttachedAfterClose( false ),
	BeforeInsertSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachBeforeInsert ) ),
	AttachedBeforeInsert( false ),
	AfterInsertSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachAfterInsert ) ),
	AttachedAfterInsert( false ),
	BeforeEditSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachBeforeEdit ) ),
	AttachedBeforeEdit( false ),
	AfterEditSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachAfterEdit ) ),
	AttachedAfterEdit( false ),
	BeforePostSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachBeforePost ) ),
	AttachedBeforePost( false ),
	AfterPostSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachAfterPost ) ),
	AttachedAfterPost( false ),
	BeforeCancelSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachBeforeCancel ) ),
	AttachedBeforeCancel( false ),
	AfterCancelSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachAfterCancel ) ),
	AttachedAfterCancel( false ),
	BeforeDeleteSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachBeforeDelete ) ),
	AttachedBeforeDelete( false ),
	AfterDeleteSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachAfterDelete ) ),
	AttachedAfterDelete( false ),
	OnNewRecordSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachOnNewRecord ) ),
	AttachedOnNewRecord( false ),
	OnCalcFieldsSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachOnCalcFields ) ),
	AttachedOnCalcFields( false )
{
	SetTDataSet( 0 );
}

TDataSet::TDataSet( PITDataSet p ) :
	TBDTComponent( p ),
	BeforeOpenSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachBeforeOpen ) ),
	AttachedBeforeOpen( false ),
	AfterOpenSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachAfterOpen ) ),
	AttachedAfterOpen( false ),
	BeforeCloseSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachBeforeClose ) ),
	AttachedBeforeClose( false ),
	AfterCloseSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachAfterClose ) ),
	AttachedAfterClose( false ),
	BeforeInsertSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachBeforeInsert ) ),
	AttachedBeforeInsert( false ),
	AfterInsertSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachAfterInsert ) ),
	AttachedAfterInsert( false ),
	BeforeEditSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachBeforeEdit ) ),
	AttachedBeforeEdit( false ),
	AfterEditSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachAfterEdit ) ),
	AttachedAfterEdit( false ),
	BeforePostSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachBeforePost ) ),
	AttachedBeforePost( false ),
	AfterPostSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachAfterPost ) ),
	AttachedAfterPost( false ),
	BeforeCancelSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachBeforeCancel ) ),
	AttachedBeforeCancel( false ),
	AfterCancelSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachAfterCancel ) ),
	AttachedAfterCancel( false ),
	BeforeDeleteSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachBeforeDelete ) ),
	AttachedBeforeDelete( false ),
	AfterDeleteSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachAfterDelete ) ),
	AttachedAfterDelete( false ),
	OnNewRecordSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachOnNewRecord ) ),
	AttachedOnNewRecord( false ),
	OnCalcFieldsSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachOnCalcFields ) ),
	AttachedOnCalcFields( false )
{
	SetTDataSet( p );
}

TDataSet::TDataSet( const TDataSet& p ) :
	TBDTComponent( p ),
	BeforeOpenSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachBeforeOpen ) ),
	AttachedBeforeOpen( false ),
	AfterOpenSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachAfterOpen ) ),
	AttachedAfterOpen( false ),
	BeforeCloseSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachBeforeClose ) ),
	AttachedBeforeClose( false ),
	AfterCloseSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachAfterClose ) ),
	AttachedAfterClose( false ),
	BeforeInsertSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachBeforeInsert ) ),
	AttachedBeforeInsert( false ),
	AfterInsertSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachAfterInsert ) ),
	AttachedAfterInsert( false ),
	BeforeEditSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachBeforeEdit ) ),
	AttachedBeforeEdit( false ),
	AfterEditSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachAfterEdit ) ),
	AttachedAfterEdit( false ),
	BeforePostSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachBeforePost ) ),
	AttachedBeforePost( false ),
	AfterPostSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachAfterPost ) ),
	AttachedAfterPost( false ),
	BeforeCancelSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachBeforeCancel ) ),
	AttachedBeforeCancel( false ),
	AfterCancelSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachAfterCancel ) ),
	AttachedAfterCancel( false ),
	BeforeDeleteSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachBeforeDelete ) ),
	AttachedBeforeDelete( false ),
	AfterDeleteSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachAfterDelete ) ),
	AttachedAfterDelete( false ),
	OnNewRecordSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachOnNewRecord ) ),
	AttachedOnNewRecord( false ),
	OnCalcFieldsSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachOnCalcFields ) ),
	AttachedOnCalcFields( false )
{
	SetTDataSet( p.dataset );
}

TDataSet::TDataSet( PTDataSet p ) :
	TBDTComponent( p ),
	BeforeOpenSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachBeforeOpen ) ),
	AttachedBeforeOpen( false ),
	AfterOpenSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachAfterOpen ) ),
	AttachedAfterOpen( false ),
	BeforeCloseSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachBeforeClose ) ),
	AttachedBeforeClose( false ),
	AfterCloseSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachAfterClose ) ),
	AttachedAfterClose( false ),
	BeforeInsertSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachBeforeInsert ) ),
	AttachedBeforeInsert( false ),
	AfterInsertSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachAfterInsert ) ),
	AttachedAfterInsert( false ),
	BeforeEditSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachBeforeEdit ) ),
	AttachedBeforeEdit( false ),
	AfterEditSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachAfterEdit ) ),
	AttachedAfterEdit( false ),
	BeforePostSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachBeforePost ) ),
	AttachedBeforePost( false ),
	AfterPostSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachAfterPost ) ),
	AttachedAfterPost( false ),
	BeforeCancelSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachBeforeCancel ) ),
	AttachedBeforeCancel( false ),
	AfterCancelSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachAfterCancel ) ),
	AttachedAfterCancel( false ),
	BeforeDeleteSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachBeforeDelete ) ),
	AttachedBeforeDelete( false ),
	AfterDeleteSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachAfterDelete ) ),
	AttachedAfterDelete( false ),
	OnNewRecordSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachOnNewRecord ) ),
	AttachedOnNewRecord( false ),
	OnCalcFieldsSource( SrcAttach_MFUNCTOR( *this, &TDataSet::AttachOnCalcFields ) ),
	AttachedOnCalcFields( false )
{
	SetTDataSet( p ? p->dataset : 0 );
}

TDataSet& TDataSet::operator=( PITDataSet p )
{
	TBDTComponent::operator=(p);
	ClearTDataSet();
	SetTDataSet( p );
	return *this;
}

TDataSet& TDataSet::operator=( const TDataSet& p )
{
	if (this != &p)
	{
		TBDTComponent::operator=(p);
		ClearTDataSet();
		SetTDataSet( p.dataset );
	}
	return *this;
}

int TDataSet::operator==( const TDataSet& p ) const
{
	if (this == &p)
		return true;
	if (dataset == p.dataset)
		return true;
	return false;
}

int TDataSet::operator!=( const TDataSet& p ) const
{
	return ! operator==(p);
}

TDataSet::~TDataSet()
{
	ClearTDataSet();
}

void TDataSet::SetPIT( PIUnknown p )
{
	ClearTDataSet();
	SetTDataSet( p );
	TBDTComponent::SetPIT( dataset );
}

LPSTR TDataSet::ActiveBuffer( void )
{
	if (dataset)
		return dataset->ActiveBuffer();
	return 0;
}

void TDataSet::Append( void )
{
	if (dataset)
		dataset->Append();
}

void TDataSet::AppendRecord( TVarRecs& values )
{
	if (dataset)
		dataset->AppendRecord( values.Count, values.Variants );
}

void TDataSet::Cancel( void )
{
	if (dataset)
		dataset->Cancel();
}

void TDataSet::CheckBrowseMode( void )
{
	if (dataset)
		dataset->CheckBrowseMode();
}

void TDataSet::ClearFields( void )
{
	if (dataset)
		dataset->ClearFields();
}

void TDataSet::Close( void )
{
	if (dataset)
		dataset->Close();
}

void TDataSet::CursorPosChanged( void )
{
	if (dataset)
		dataset->CursorPosChanged();
}

void TDataSet::Delete( void )
{
	if (dataset)
		dataset->Delete();
}

void TDataSet::DisableControls( void )
{
	if (dataset)
		dataset->DisableControls();
}

void TDataSet::Edit( void )
{
	if (dataset)
		dataset->Edit();
}

void TDataSet::EnableControls( void )
{
	if (dataset)
		dataset->EnableControls();
}

DEFINE_BDTO_OBJECTMETHOD1( TDataSet, TField, PITField, FieldByName, string& );

void TDataSet::CallFieldByName( string& n, TField& f )
{
	if (dataset)
	{
		PITField pit = dataset->FieldByName( AnyString(n).GetPITAnyString() );
		if (pit)
		{
			f.SetPIT( pit );
			pit->Release();
		}
	}
}

DEFINE_BDTO_OBJECTMETHOD1( TDataSet, TField, PITField, FindField, string& );

void TDataSet::CallFindField( string& n, TField& f )
{
	if (dataset)
	{
		PITField pit = dataset->FindField( AnyString(n).GetPITAnyString() );
		if (pit)
		{
			f.SetPIT( pit );
			pit->Release();
		}
	}
}

void TDataSet::First( void )
{
	if (dataset)
		dataset->First();
}

void TDataSet::FreeBookmark( TBookmark bm )
{
	if (dataset)
		dataset->FreeBookmark( bm );
}

TBookmark TDataSet::GetBookmark( void )
{
	if (dataset)
		return dataset->GetBookmark();
	return 0;
}

bool TDataSet::GetCurrentRecord( LPSTR buffer )
{
	if (dataset)
		return MakeBool( dataset->GetCurrentRecord( buffer ) );
	return false;
}

void TDataSet::GetFieldNames( TStrings& list )
{
	if (dataset)
		dataset->GetFieldNames( list.GetPITStrings() );
}

void TDataSet::GotoBookmark( TBookmark bm )
{
	if (dataset)
		dataset->GotoBookmark( bm );
}

void TDataSet::Insert( void )
{
	if (dataset)
		dataset->Insert();
}

void TDataSet::InsertRecord( TVarRecs& values )
{
	if (dataset)
		dataset->InsertRecord( values.Count, values.Variants );
}

bool TDataSet::IsLinkedTo( TDataSource& source )
{
	if (dataset)
		return MakeBool( dataset->IsLinkedTo( source.GetPITDataSource() ) );
	return false;
}

void TDataSet::Last( void )
{
	if (dataset)
		dataset->Last();
}

void TDataSet::MoveBy( int distance )
{
	if (dataset)
		dataset->MoveBy( distance );
}

void TDataSet::Next( void )
{
	if (dataset)
		dataset->Next();
}

void TDataSet::Open( void )
{
	if (dataset)
		dataset->Open();
}

void TDataSet::Post( void )
{
	if (dataset)
		dataset->Post();
}

void TDataSet::Prior( void )
{
	if (dataset)
		dataset->Prior();
}

void TDataSet::Refresh( void )
{
	if (dataset)
		dataset->Refresh();
}

void TDataSet::Resync( TResyncMode mode )
{
	if (dataset)
		dataset->Resync( mode );
}

void TDataSet::SetFields( TVarRecs& values )
{
	if (dataset)
		dataset->SetFields( values.Count, values.Variants );
}

void TDataSet::UpdateCursorPos( void )
{
	if (dataset)
		dataset->UpdateCursorPos();
}

void TDataSet::UpdateRecord( void )
{
	if (dataset)
		dataset->UpdateRecord();
}

DEFINE_BDTO_PROP_RO( TDataSet, bool, AtBOF );
DEFINE_BDTO_PROP_RO( TDataSet, bool, CanModify );
DEFINE_BDTO_OBJECTPROP_RO_FAST( TDataSet, TDataSource, PITDataSource, DataSource );
DEFINE_BDTO_PROP_RO( TDataSet, bool, DefaultFields );
DEFINE_BDTO_PROP_RO( TDataSet, bool, AtEOF );
DEFINE_BDTO_PROP_RO( TDataSet, int, FieldCount );
DEFINE_BDTO_OBJECTPROP_RO_FAST( TDataSet, TFieldDefs, PITFieldDefs, FieldDefs );
DEFINE_BDTO_ARRAYOBJECTPROP_RO_FAST( TDataSet, TField, PITField, Fields, int );
DEFINE_BDTO_PROP_RO( TDataSet, hDBICur, Handle );
DEFINE_BDTO_PROP_RO( TDataSet, bool, Modified );
DEFINE_BDTO_PROP_RO( TDataSet, int32, RecordCount );
DEFINE_BDTO_PROP_RO( TDataSet, uint16, RecordSize );
DEFINE_BDTO_PROP_RO( TDataSet, TDataSetState, State );
DEFINE_BDTO_PROP_RO( TDataSet, TLocale, Locale );

void TDataSet::GetAtBOF( bool& b )
{
	if (dataset)
		b = MakeBool( dataset->get_AtBOF() );
}

void TDataSet::GetCanModify( bool& c )
{
	if (dataset)
		c = MakeBool( dataset->get_CanModify() );
}

void TDataSet::GetDataSource( TDataSource& d )
{
	if (dataset)
	{
		PITDataSource pit = dataset->get_DataSource();
		if (pit)
		{
			d.SetPIT( pit );
			pit->Release();
		}
	}
}

void TDataSet::GetDefaultFields( bool& d )
{
	if (dataset)
		d = MakeBool( dataset->get_DefaultFields() );
}

void TDataSet::GetAtEOF( bool& e )
{
	if (dataset)
		e = MakeBool( dataset->get_AtEOF() );
}

void TDataSet::GetFieldCount( int& c )
{
	if (dataset)
		c = dataset->get_FieldCount();
}

void TDataSet::GetFieldDefs( TFieldDefs& f )
{
	if (dataset)
	{
		PITFieldDefs pit = dataset->get_FieldDefs();
		if (pit)
		{
			f.SetPIT( pit );
			pit->Release();
		}
	}
}

void TDataSet::GetFields( int i, TField& f )
{
	if (dataset)
	{
		PITField pit = dataset->get_Fields( i );
		if (pit)
		{
			f.SetPIT( pit );
			pit->Release();
		}
	}
}

void TDataSet::GetHandle( hDBICur& h )
{
	if (dataset)
		h = dataset->get_Handle();
}

void TDataSet::GetModified( bool& m )
{
	if (dataset)
		m = MakeBool( dataset->get_Modified() );
}

void TDataSet::GetRecordCount( int32& c )
{
	if (dataset)
		c = dataset->get_RecordCount();
}

void TDataSet::GetRecordSize( uint16& s )
{
	if (dataset)
		s = dataset->get_RecordSize();
}

void TDataSet::GetState( TDataSetState& s )
{
	if (dataset)
		s = dataset->get_State();
}

void TDataSet::GetLocale( TLocale& l )
{
	if (dataset)
		l = dataset->get_Locale();
}

DEFINE_BDTO_PROP_RW( TDataSet, bool, Active );
DEFINE_BDTO_PROP_RW( TDataSet, bool, AutoCalcFields );

void TDataSet::GetActive( bool& a )
{
	if (dataset)
		a = MakeBool( dataset->get_Active() );
}

void TDataSet::SetActive( bool a )
{
	if (dataset)
		dataset->put_Active( MakeVariantBool( a ) );
}

void TDataSet::GetAutoCalcFields( bool& a )
{
	if (dataset)
		a = MakeBool( dataset->get_AutoCalcFields() );
}

void TDataSet::SetAutoCalcFields( bool a )
{
	if (dataset)
		dataset->put_AutoCalcFields( MakeVariantBool( a ) );
}

//-----------------------------------------------------------------------------

void TDBDataSet::SetTDBDataSet( PIUnknown p )
{
	dbdataset = 0;
	if (p)
		p->QueryInterface( IID_ITDBDataSet, (void**) &dbdataset );
}

void TDBDataSet::ClearTDBDataSet( void )
{
	if (dbdataset)
	{
		dbdataset->Release();
		dbdataset = 0;
	}
}

TDBDataSet::TDBDataSet( void ) : TDataSet()
{
	SetTDBDataSet( 0 );
}

TDBDataSet::TDBDataSet( PITDBDataSet p) : TDataSet( p )
{
	SetTDBDataSet( p );
}

TDBDataSet::TDBDataSet( const TDBDataSet& p ) : TDataSet( p )
{
	SetTDBDataSet( p.dbdataset );
}

TDBDataSet::TDBDataSet( PTDBDataSet p ) : TDataSet( p )
{
	SetTDBDataSet( p ? p->dbdataset : 0 );
}

TDBDataSet& TDBDataSet::operator=( PITDBDataSet p )
{
	TDataSet::operator=(p);
	ClearTDBDataSet();
	SetTDBDataSet( p );
	return *this;
}

TDBDataSet& TDBDataSet::operator=( const TDBDataSet& p )
{
	if (this != &p)
	{
		TDataSet::operator=(p);
		ClearTDBDataSet();
		SetTDBDataSet( p.dbdataset );
	}
	return *this;
}

int TDBDataSet::operator==( const TDBDataSet& p ) const
{
	if (this == &p)
		return true;
	if (dbdataset == p.dbdataset)
		return true;
	return false;
}

int TDBDataSet::operator!=( const TDBDataSet& p ) const
{
	return ! operator==(p);
}

TDBDataSet::~TDBDataSet()
{
	ClearTDBDataSet();
}

void TDBDataSet::SetPIT( PIUnknown p )
{
	ClearTDBDataSet();
	SetTDBDataSet( p );
	TDataSet::SetPIT( p );
}

DEFINE_BDTO_OBJECTPROP_RO_FAST( TDBDataSet, TDatabase, PITDatabase, Database );
DEFINE_BDTO_PROP_RO( TDBDataSet, hDBIDb, DBHandle );
DEFINE_BDTO_PROP_RO( TDBDataSet, TLocale, DBLocale );

void TDBDataSet::GetDatabase( TDatabase& d )
{
	if (dbdataset)
	{
		PITDatabase pit = dbdataset->get_Database();
		if (pit)
		{
			d.SetPIT( pit );
			pit->Release();
		}
	}
}

void TDBDataSet::GetDBHandle( hDBIDb& h )
{
	if (dbdataset)
		h = dbdataset->get_DBHandle();
}

void TDBDataSet::GetDBLocale( TLocale& l )
{
	if (dbdataset)
		l = dbdataset->get_DBLocale();
}

DEFINE_BDTO_OBJECTPROP_RW( TDBDataSet, string, DatabaseName );

void TDBDataSet::GetDatabaseName( string& s )
{
	if (dbdataset)
		AnyString( dbdataset->get_DatabaseName() ).GetString( s );
}

void TDBDataSet::SetDatabaseName( const string& n )
{
	if (dbdataset)
		dbdataset->put_DatabaseName( AnyString(n).GetPITAnyString() );
}

