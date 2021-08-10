/*
   ToolAPI.H           copyright (c) Borland International 1993

      Borland IDE external tool API definitions

*/

#if !defined( _TOOLAPI_H )
#define _TOOLAPI_H

#if !defined( _TRANTYPE_H )
#include "TranType.h"
#endif // _TRANTYPE_H

// All of the functions exported from the IDE are C callable
// to allow the use of both C and C++ for tool development
#if defined( __cplusplus )
extern "C" {
#endif // __cplusplus

/*
  This first section of the ToolAPI header file show prototypes for functions
  which reside in the IDE.  These functions are passed to the tool DLL as a
  parameter to the Run function in the form of an array of void (*func)(void)
  pointers. Detailed below are macros which correspond to the prototypes which
  allow the tool DLL to use the functions from the pointer array directly as
  they are defined.
*/

/************************************************/
/* function which must be defined by transfer DLL */
/************************************************/
int far pascal Run( pTransferBlock TransBlock );

#if 0
/***********************************/
/* functions exported by Borland IDE */
/***********************************/
/*** IDE versioning functions ***/
//  IDE_Version() fills the tVersion structure with necessary information
//  for the DLL to determine if it is compatible with the caller.
void IDE_Version( tVersion *version );

//  IDE_Exec() attempts to launch the program identified by Path.  If
//  searchpath is set, the IDE will look in the current working directory
//  and then look along the path for the program.
//  Returns: exit code of executed program or -1 on failure
int IDE_Exec( const char *Path, BOOL searchpath );

/*** File I/O oriented functions ***/
// File I/O maps as closely as possible to standard RTL IO.H functions
FileHandle IDE_Open  ( LPSTR file, mode_t Mode );
FileHandle IDE_SOpen ( LPSTR file, mode_t Mode, share_t Share );
FileHandle IDE_Create( LPSTR file );
WORD       IDE_Read  ( FileHandle fh, LPSTR buffer, WORD len );
WORD       IDE_Write ( FileHandle fh, LPSTR buffer, WORD len );
WORD32     IDE_Seek  ( FileHandle fh, WORD32 offset, WORD whence );
void       IDE_Close ( FileHandle fh );

void       IDE_Delete( LPSTR file );


/*** Memory management oriented functions ***/
// The memory management functions parallel windows functions as closely
// as possible.  A tool DLL can allocate memory via the native environment
// if that is preferred.
HMEM   IDE_memalloc  ( memflags_t memflags, WORD32 size );
LPSTR  IDE_memlock   ( HMEM hMemory );
void   IDE_memunlock ( HMEM hMemory );
HMEM   IDE_memhandle ( LPSTR location );
void   IDE_memfree   ( HMEM hMemory );
WORD32 IDE_memsize   ( HMEM hMemory );
HMEM   IDE_memrealloc( HMEM hMemory, WORD32 size, memflags_t memflags );
memflags_t IDE_memflags ( HMEM hMemory );
WORD32 IDE_freespace( void );

/*** Message system oriented functions ***/
// IDE_NewMessageGroup() checks for a group of messages tagged with the
// group name provided.  If it exists, it is cleared if the clear==TRUE.
// The current message group is set to the MsgGroupID for that tag and
// the message group ID is returned to caller.
MsgGroupID IDE_NewMessageGroup( LPSTR GroupName, BOOL clear );

// IDE_SetMessageGroup() sets the current message group to MsgGrpID.
// if clear==TRUE, the group is cleared
void       IDE_SetMessageGroup( MsgGroupID MsgGrpID, BOOL clear );

// IDE_PostMessage() posts a new message to the MsgGroupID indicated
void       IDE_PostMessage    ( MsgGroupID MsgGrpID, lpMsg Msg );

// IDE_ClearMessages() clears all messages in all message groups
void       IDE_ClearMessages  ( void );


/*** Message Box posting functions ***/
// IDE_ErrorBox() is used to put a message box onto the screen for purposes
// of notifying the user that something has happened.  The box has a singe OK
// button.  The IDE box has an exclamation point and a single ok button
void IDE_ErrorBox( const char *message );

#endif

/*
  The remaining section of this header file details macros which allow calling
  of functions in the IDE's ToolAPI function pointer array without having to
  typecast or concider array locations or parameters.  The macros cause the
  entries in the IDE_ToolAPI array of void (*func)(void) function pointers to
  be accessed as the corresponding prototypes listed above detail.
*/

extern _pascal IDE_ToolAPIFunc IDE_ToolAPI[];


// enumeration for the tool api array of functions
typedef enum
{
  // Version functions
  IDEVersion,

  // Task functions
  IDEMonitor,
  IDEExec,
  IDEGetTaskID,

  // File I/O functions
  IDEOpen,
  IDESOpen,
  IDECreate,
  IDERead,
  IDEWrite,
  IDEClose,
  IDESeek,
  IDEDelete,
  IDECapture,

  // Memory management functions
  IDEMemAlloc,
  IDEMemLock,
  IDEMemUnlock,
  IDEMemHandle,
  IDEMemFree,
  IDEMemSize,
  IDEMemRealloc,
  IDEMemFlags,
  IDEFreeSpace,

  // Message system functions
  IDENewMessageGroup,
  IDESetMessageGroup,
  IDEPostMessage,
  IDEClearMessages,

  // Error Box functions
  IDEErrorBox,

  // End of list, indicate size of array
  IDE_NumFunctions,
} ToolApi;

// typedef pointer for the run function exported from the tool DLL
typedef  int far pascal (*runFuncPtr)( pTransferBlock );

// Typedefs allow convertion from void (*func)( void ) function pointers
// to functions of the correct type
typedef void far pascal      (*versionptr)   ( tVersion * );

typedef monitor_t far pascal (*monitorptr)( TaskID );
typedef TaskID far pascal    (*taskptr)      ( const char *, BOOL );

typedef FileHandle far pascal (*openptr)    ( LPSTR, mode_t );
typedef FileHandle far pascal (*sopenptr)   ( LPSTR, mode_t, share_t );
typedef FileHandle far pascal (*creatptr)   ( LPSTR );
typedef WORD       far pascal (*rdwrptr)    ( FileHandle , LPSTR, WORD );
typedef void       far pascal (*closeptr)   ( FileHandle );
typedef WORD32     far pascal (*seekptr)    ( FileHandle, WORD32, WORD );
typedef void       far pascal (*deleteptr)  ( LPSTR );
typedef int        far pascal (*captureptr) ( const char *, LPSTR, LPSTR );


typedef WORD32 far pascal (*memsizeptr)   ( HMEM );
typedef HMEM   far pascal (*memallocptr)  ( memflags_t, WORD32 );
typedef HMEM   far pascal (*memreallocptr)( HMEM, WORD32, memflags_t );
typedef void   far pascal (*memunlockptr) ( HMEM );
typedef LPSTR  far pascal (*memlockptr)   ( HMEM );
typedef HMEM   far pascal (*memhandleptr) ( LPSTR );
typedef memflags_t far pascal (*memflagsptr) ( HMEM );
typedef WORD32 far pascal (*memfreeptr)( void );

typedef MsgGroupID far pascal (*newgroupptr) ( LPSTR, BOOL );
typedef void       far pascal (*setmsgptr)   ( MsgGroupID, BOOL );
typedef void       far pascal (*postmsgptr)  ( MsgGroupID, lpMsg );
typedef void       far pascal (*clearmsgptr) ( void );

typedef void       far pascal (*errboxptr)   ( const char * );

/*
  For the following, the single letters translate as:
     V   pointer to version structure   ( tVersion * )
     T   TaskID
     S   Search? (boolean)
     CR  Create (boolean)
     FN  FileName
     FH  FileHandle
     M   File open Mode
     SH  Share flags
     H   Handle to memory
     SZ  Size of block (unsigned LONG)
     F   Memory Flags (Type memflags_t )
     L   Lenght  (unsigned LONG)
     B   Buffer (LPSTR)
     CB  const string (const char *)
     P   Path  (LPSTR)
     C   Clear (boolean)
     G   Message Group (MsgGroupID)
     M   pointer to a Message structure ( lpMsg )
*/

// IDE version
#define IDE_Version( V )       ((versionptr)(*IDE_ToolAPI[IDEVersion]))( V )

// Task functions
#define IDE_Monitor( T )       ((monitorptr)(*IDE_ToolAPI[IDEMonitor]))( T )
#define IDE_Exec( P, S )       ((taskptr)(*IDE_ToolAPI[IDEExec]))( P, S )
#define IDE_GetTaskID( P, CR ) ((taskptr)(*IDE_ToolAPI[IDEExec]))( P, CR )

// File I/O functions
#define IDE_Open( FN, M )      ((openptr)(*IDE_ToolAPI[IDEOpen]))( FN, M )
#define IDE_SOpen( FN, M, SH ) ((sopenptr)(*IDE_ToolAPI[IDESOpen]))( FN, M, SH )
#define IDE_Create( FN )       ((creatptr)(*IDE_ToolAPI[IDECreate]))( FN )
#define IDE_Read( FH, B, L )   ((rdwrptr)(*IDE_ToolAPI[IDERead]))( FH, B, L )
#define IDE_Write( FH, B, L )  ((rdwrptr)(*IDE_ToolAPI[IDEWrite]))( FH, B, L )
#define IDE_Close( FH )        ((closeptr)(*IDE_ToolAPI[IDEClose]))( FH )
#define IDE_Delete( FN )       ((deleteptr)(*IDE_ToolAPI[IDEDelete]))( FN )
#define IDE_Seek( FH, O, Wh )  ((seekptr)(*IDE_ToolAPI[IDESeek]))( FH, O, Wh )
#define IDE_CaptureToPipe( P, CT, PF ) ((captureptr)(*IDE_ToolAPI[IDECapture]))( P, CT, PF )

// Memory management functions
#define IDE_memalloc( F, SZ )     ((memallocptr)(*IDE_ToolAPI[IDEMemAlloc]))( F, SZ )
#define IDE_memlock( H )          ((memlockptr)(*IDE_ToolAPI[IDEMemLock]))( H )
#define IDE_memunlock( H )        ((memunlockptr)(*IDE_ToolAPI[IDEMemUnlock]))( H )
#define IDE_memhandle( B )        ((memhandleptr)(*IDE_ToolAPI[IDEMemHandle]))( B )
#define IDE_memfree( H )          ((memunlockptr)(*IDE_ToolAPI[IDEMemFree]))( H )
#define IDE_memsize( H )          ((memsizeptr)(*IDE_ToolAPI[IDEMemSize]))( H )
#define IDE_memrealloc( H, SZ, F )((memreallocptr)(*IDE_ToolAPI[IDEMemRealloc]))( H, SZ, F )
#define IDE_memflags ( H )        ((memflagsptr)(*IDE_ToolAPI[IDEMemFlags]))( H )
#define IDE_freespace             (*IDE_ToolAPI[IDEFreeSpace])

// message system functions
#define IDE_NewMessageGroup( B, C ) ((newgroupptr)(*IDE_ToolAPI[IDENewMessageGroup]))( B, C )
#define IDE_SetMessageGroup( G, C ) ((setmsgptr)(*IDE_ToolAPI[IDESetMessageGroup]))( G, C )
#define IDE_PostMessage( G, M )     ((postmsgptr)(*IDE_ToolAPI[IDEPostMessage]))( G, M )
#define IDE_ClearMessages           (*IDE_ToolAPI[IDEClearMessages])

#define IDE_ErrorBox( CB )           ((errboxptr)(*IDE_ToolAPI[IDEErrorBox]))( CB )

#if defined( __cplusplus )
}   // matches extern "C" { 
#endif  // __cplusplus

#endif // _TOOLAPI_H
