/*
    TranType.H       copyright (c) Borland International 1993

       IDE defined types for various tranfer tool types
*/

#if !defined( __TRANTYPE_H )
#define __TRANTYPE_H

typedef unsigned char BYTE;

typedef unsigned long WORD32;
typedef unsigned WORD16;

#if !defined( LPSTR )
typedef char *LPSTR;
#endif

typedef int BOOL;  // matches Windows.H
#define FALSE               0
#define TRUE                1

#if !defined( __FLAT__ )
 #define FAR _far
#endif

#if !defined( WORD )
typedef unsigned short WORD;
#endif

#if !defined( NULL )
#define NULL 0
#endif

/********************/
/* Type definitions */
/********************/
// tool return codes
enum
{
  toolUnknownProblem = -1,
  toolSuccess,
  toolWarnings,
  toolErrors,
  toolFatalError,
};

// task montitor type
typedef enum
{
  TSK_NOTLOADED,
  TSK_COMPLETE,
  TSK_RUNNING,
  TSK_IDLE,
} monitor_t;

typedef WORD32 TaskID;
#define NO_TASK 0l

typedef WORD16 HMEM;

typedef void far pascal (*IDE_ToolAPIFunc)( void );
typedef IDE_ToolAPIFunc *lpIDE_ToolAPIFunc;

#define SAVE_NONE   0x0000
#define SAVE_EDIT   0x0001
#define SAVE_CUR    0x0002
#define SAVE_PRJ    0x0004
#define SAVE_PROMPT 0x0008

#define SAVE_ALL  (SAVE_EDIT | SAVE_CUR | SAVE_PRJ)

typedef struct tag_TransferBlock
{
  LPSTR program;
  LPSTR cmdline;
  LPSTR filter;
  lpIDE_ToolAPIFunc IDE_ToolAPI;
} TransferBlock;
typedef TransferBlock *pTransferBlock;

// Values of memflags_t directly map to WINDOWS 3.1 GMEM_ flags
typedef enum
{
  MEM_FIXED         = 0x0000,
  MEM_MOVEABLE      = 0x0002,
  MEM_NOCOMPACT     = 0x0010,
  MEM_NODISCARD     = 0x0020,
  MEM_ZEROINIT      = 0x0040,
  MEM_MODIFY        = 0x0080,
  MEM_DISCARDABLE   = 0x0100,
  MEM_NOT_BANKED    = 0x1000,
  MEM_SHARE         = 0x2000,
  MEM_DDESHARE      = 0x2000,
  MEM_NOTIFY        = 0x4000,
  MEM_LOWER         = MEM_NOT_BANKED,
} memflags_t;

// File open and share flags
typedef enum
{                                 //  Windows.H equivalents
  O_RDONLY     = 0x01,            //  OF_READ
  O_WRONLY     = 0x02,            //  OF_WRITE
  O_RDWR       = 0x04,            //
  O_DENYALL    = 0x10,            //  OF_SHARE_EXCLUSIVE										  
  O_DENYWRITE  = 0x20,            //  OF_SHARE_DENY_WRITE
  O_DENYREAD   = 0x30,            //  OF_SHARE_DENY_READ										  
  O_DENYNONE   = 0x40,            //  OF_SHARE_DENY_NONE										  
} mode_t;

typedef enum
{
  SH_DENYALL   = 0x10,            //  OF_SHARE_EXCLUSIVE
  SH_DENYWRITE = 0x20,	          //  OF_SHARE_DENY_WRITE
  SH_DENYREAD  = 0x30,	          //  OF_SHARE_DENY_READ
  SH_DENYNONE  = 0x40,	          //  OF_SHARE_DENY_NONE
} share_t;

typedef int FileHandle;

// message system message structure
typedef WORD16 MsgGroupID;
typedef struct Message_tag
{
  LPSTR  message;
  LPSTR  filename;
  WORD16 column;
  WORD16 line;
} Msg;
typedef Msg *lpMsg;

#define CUR_MSG_GROUP -1

// IDE version structure
typedef struct IDEversion_tag
{
  BYTE IDEMajor;
  BYTE IDEMinor;
  BYTE IDEPlatform;
} tVersion;

#define DosPlatform 1
#define WinPlatform 2


#endif // _TRANTYPE_H
