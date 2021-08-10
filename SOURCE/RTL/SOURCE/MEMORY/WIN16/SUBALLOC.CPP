/*------------------------------------------------------------------------
 * filename - suballoc.cpp
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1991, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#if !defined(__DLL__)
struct far TSubAllocClientData
{
        void far *MemBlockPtr;
        int MemBlockCount;
};

extern "C"
{
        extern TSubAllocClientData far * far __GetSubAllocClientData();
}

TSubAllocClientData SubAllocClientData;

TSubAllocClientData far * far __GetSubAllocClientData()
{
    return &SubAllocClientData;
}
#endif // !__DLL__
