/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

	ivfile.h
	Created: 11/13/95
	Copyright (c) 1987, 1995 Borland International Inc.  All Rights Reserved.
	$Header:   Y:\admin\bride\addon\deliver\interfac\ivfile.h_v   1.20   18 Nov 1996 11:30:12   JDOUGLAS  $
	$Revision:   1.20  $

   IVirtualFile

	The IDE uses a virtual file system to hide the difference between  
	files in edit buffers vs. files on disk. If a file is opened that is 
	already in an edit buffer, the read (not write) methods of this interface 
	will act on the file image in the edit buffer, otherwise they will act on the 
	file on disk. Write methods always act on the file on disk. To write to an
   edit buffer, you must use the IEditorServer interface.
    
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/	

#ifndef __IVFILE_H
#define __IVFILE_H

#include <objbase.h>
#include <ideaddon\ivfile.uid>
#include <ideaddon\ipolystr.h>
#include <ideaddon\common.h>

enum VFOpenMode {
	VFOM_Read,
	VFOM_Write,
	VFOM_ReadWrite,
	VFOM_Create
};

//.............................................................................
class IVirtualFile : public IUnknown {
 public:
	//
	//	Init() sets the file name for subsequent method calls through this
	// interface. This affects Open(), IsReadOnly(), Exists() and GetAge()
   //
	virtual void BCWADDON_CMETHOD Init( IPolyString * fileName ) = 0;
	//
	//	GetErrorCode() returns the file system error number of the last error.
	//
   //
	virtual int BCWADDON_CMETHOD GetErrorCode() = 0;
	//
	//	IsReadOnly() and Exists() return the status of the file specified through
	// SetName().
	//
	virtual BOOL BCWADDON_CMETHOD IsReadOnly() = 0;     
	virtual BOOL BCWADDON_CMETHOD Exists() = 0;
	//
	//	Opens the file specified through Init(). Subsequent calls to Read(),
	// Write(), Seek(), Close() and Delete() work with the file opened by
	// this method.
	//
	virtual BOOL BCWADDON_CMETHOD Open( VFOpenMode mode = VFOM_ReadWrite ) = 0;
	//
	//	Read() returns the number of bytes read.
	//
	virtual int BCWADDON_CMETHOD Read( char * buffer, int len ) = 0;
	//
	//	Write() returns the number of bytes written.
	//
	virtual int BCWADDON_CMETHOD Write( char * buffer, int len ) = 0;
	//
	//	Seek() returns the offset from the beginning of the file.
	//	Use the Windows API FILE_BEGIN, FILE_CURRENT, FILE_END origin flags.
	// 
	virtual int BCWADDON_CMETHOD Seek( int offset, int origin = FILE_BEGIN ) = 0;
	//
	//	Close() the file opened with Open(). This will automatically be called
	// when this interface's refcount reaches 0.
	//
	virtual void BCWADDON_CMETHOD Close() = 0;
	//
	//	If a buffer is open on a file that is being Deleted, that buffer is 
	// unaffected by the call to Delete(), but the file on disk is deleted.
	//
	virtual void BCWADDON_CMETHOD Delete() = 0;
   
   //
   //	Return the age of the file.
   //
   virtual long BCWADDON_CMETHOD GetAge() = 0;
   
};

#endif