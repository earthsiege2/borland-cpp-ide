#pragma option push -b -a8 -pc -A- /*P_O_Push*/
//***************************************************************************
//
//  Copyright (c) 1997-1999 Microsoft Corporation
//
//  stllock.h
//
//  Purpose: Critical section class
//
//***************************************************************************

#if _MSC_VER > 1000
#pragma once
#endif

#ifndef _STLLOCK_H_
#define _STLLOCK_H_

class CCritSec : public CRITICAL_SECTION
{
public:
    CCritSec() 
    {
        InitializeCriticalSection(this);
    }
    ~CCritSec()
    {
        DeleteCriticalSection(this);
    }
    void Enter()
    {
        EnterCriticalSection(this);
    }
    void Leave()
    {
        LeaveCriticalSection(this);
    }
};

#endif

#pragma option pop /*P_O_Pop*/
