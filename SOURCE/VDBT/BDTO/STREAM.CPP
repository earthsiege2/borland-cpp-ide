//-----------------------------------------------------------------------------
// Visual Database Tools
// Copyright (c) 1996 by Borland International, All Rights Reserved
//
// stream.cpp
// TMemoryStream wrapper class
//-----------------------------------------------------------------------------

#include <vdbt\bdto.h>

#pragma hdrstop

#include "misc.h"

//-----------------------------------------------------------------------------

void TMemoryStream::SetTMemoryStream( PIUnknown p )
{
	stream = 0;
	if (p)
		p->QueryInterface( IID_ITMemoryStream, (void**) &stream );
}

void TMemoryStream::ClearTMemoryStream( void )
{
	if (stream)
	{
		stream->Release();
		stream = 0;
	}
}

TMemoryStream::TMemoryStream( void )
{
	stream = CreateITMemoryStream();
}

TMemoryStream::TMemoryStream( PITMemoryStream p )
{
	SetTMemoryStream( p );
}

TMemoryStream::TMemoryStream( const TMemoryStream& p )
{
	SetTMemoryStream( p.stream );
}

TMemoryStream::TMemoryStream( PTMemoryStream p )
{
	SetTMemoryStream( p ? p->stream : 0 );
}

TMemoryStream& TMemoryStream::operator=( PITMemoryStream p )
{
	ClearTMemoryStream();
	SetTMemoryStream( p );
	return *this;
}

TMemoryStream& TMemoryStream::operator=( const TMemoryStream& p )
{
	if (this != &p)
	{
		ClearTMemoryStream();
		SetTMemoryStream( p.stream );
	}
	return *this;
}

int TMemoryStream::operator==( const TMemoryStream& p ) const
{
	if (this == &p)
		return true;
	if (stream == p.stream)
		return true;
	return false;
}

int TMemoryStream::operator!=( const TMemoryStream& p ) const
{
	return ! operator==(p);
}

TMemoryStream::~TMemoryStream()
{
	ClearTMemoryStream();
}

void TMemoryStream::SetPIT( PIUnknown p )
{
	ClearTMemoryStream();
	SetTMemoryStream( p );
}

void TMemoryStream::Detach( void )
{
	if (stream)
		stream->Detach();
}

int32 TMemoryStream::Read( LPVOID Buffer, int32 Count )
{
	if (stream)
		return stream->Read( Buffer, Count );
	return 0;
}

int32 TMemoryStream::Write( LPVOID Buffer, int32 Count )
{
	if (stream)
		return stream->Write( Buffer, Count );
	return 0;
}

int32 TMemoryStream::Seek( int32 Offset, TSeekOrigin Origin )
{
	if (stream)
		return stream->Seek( Offset, Origin );
	return 0;
}

void TMemoryStream::ReadBuffer( LPVOID Buffer, int32 Count )
{
	if (stream)
		stream->ReadBuffer( Buffer, Count );
}

void TMemoryStream::WriteBuffer( LPVOID Buffer, int32 Count )
{
	if (stream)
		stream->WriteBuffer( Buffer, Count );
}

int32 TMemoryStream::CopyFrom( TMemoryStream& Source, int32 Count )
{
	if (stream)
		return stream->CopyFrom( Source.stream, Count );
	return 0;
}

DEFINE_BDTO_PROP_RW( TMemoryStream, int32, Position );
DEFINE_BDTO_PROP_RO( TMemoryStream, int32, Size );

void TMemoryStream::GetPosition( int32& p )
{
	if (stream)
		p = stream->get_Position();
}

void TMemoryStream::SetPosition( int32 p )
{
	if (stream)
		stream->put_Position( p );
}

void TMemoryStream::GetSize( int32& s )
{
	if (stream)
		s = stream->get_Size();
}
