/* ----------------------------------------------------------------------------
Microsoft	D.T.C (Distributed Transaction Coordinator)

(c)	1995	Microsoft Corporation.	All Rights Reserved

@doc

@module		XACTOMSG.H	|

@devnotes	Macro to convert from transaction error message values to 
		message ids in edudtc.dll

@rev	0	|	29-Aug-1995	|	Shaiwals |	Created
----------------------------------------------------------------------------- */
#ifndef __XACTOMSG_H__
#pragma option push -b -a8 -pc -A- /*P_O_Push*/
#define __XACTOMSG_H__

#define XACTTOMSG(dwXact) (dwXact-0x00040000+0x40000000)

#pragma option pop /*P_O_Pop*/
#endif __XACTOMSG_H__
