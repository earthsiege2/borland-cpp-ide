/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 3.00.15 */
/* at Tue Jan 14 11:01:47 1997
 */
/* Compiler settings for docobj.idl:
    Os, W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#ifdef __cplusplus
extern "C"{
#endif 


#ifndef IID_DEFINED
#define IID_DEFINED

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // IID_DEFINED

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID IID_IOleDocument = {0xb722bcc5,0x4e68,0x101b,{0xa2,0xbc,0x00,0xaa,0x00,0x40,0x47,0x70}};


const IID IID_IOleDocumentSite = {0xb722bcc7,0x4e68,0x101b,{0xa2,0xbc,0x00,0xaa,0x00,0x40,0x47,0x70}};


const IID IID_IOleDocumentView = {0xb722bcc6,0x4e68,0x101b,{0xa2,0xbc,0x00,0xaa,0x00,0x40,0x47,0x70}};


const IID IID_IEnumOleDocumentViews = {0xb722bcc8,0x4e68,0x101b,{0xa2,0xbc,0x00,0xaa,0x00,0x40,0x47,0x70}};


const IID IID_IContinueCallback = {0xb722bcca,0x4e68,0x101b,{0xa2,0xbc,0x00,0xaa,0x00,0x40,0x47,0x70}};


const IID IID_IPrint = {0xb722bcc9,0x4e68,0x101b,{0xa2,0xbc,0x00,0xaa,0x00,0x40,0x47,0x70}};


const IID IID_IOleCommandTarget = {0xb722bccb,0x4e68,0x101b,{0xa2,0xbc,0x00,0xaa,0x00,0x40,0x47,0x70}};


#ifdef __cplusplus
}
#endif

