/*++

Copyright (c) 1997-1999 Microsoft Corporation

Module Name:

    MSPutils.h

Abstract:
    
    This file defines several utility classes used by the MSP base classes.

--*/

#ifndef __MSPUTILS_H_
#pragma option push -b -a8 -pc -A- /*P_O_Push*/
#define __MSPUTILS_H_

#define DECLARE_VQI() \
    STDMETHOD(QueryInterface)(REFIID iid, void ** ppvObject) = 0; \
    STDMETHOD_(ULONG, AddRef)() = 0; \
    STDMETHOD_(ULONG, Release)() = 0;

//
// Make sure we have exactly one media type. That's not the case if
// dwMediaType is 0 or more than one bit is set in dwMediaType. Note
// that DWORD is unsigned so this should be safe.
//
inline BOOL IsSingleMediaType(DWORD dwMediaType) 
{   
    return !((dwMediaType == 0) || ((dwMediaType & (dwMediaType - 1)) != 0));
}

//
// Check to see if the mediatype is a single type and is in the mask.
//

inline BOOL IsValidSingleMediaType(DWORD dwMediaType, DWORD dwMask)
{
    return IsSingleMediaType(dwMediaType)
        && ((dwMediaType & dwMask) == dwMediaType);
}

/*++

CMSPArray template Description:

    Definitions for a simple vector template. The implementaion is borrowed
    from CMSPArray in atlapp.h. Modified only the allocation behavior.

    This array should only be used to store simple types. It doesn't call the
    constructor nor the destructor for each element in the array.

--*/
const DWORD INITIAL = 8;
const DWORD DELTA   = 8;

template <class T, DWORD dwInitial = INITIAL, DWORD dwDelta = DELTA>
class CMSPArray
{

protected:
    T* m_aT;
    int m_nSize;
    int m_nAllocSize;

public:
// Construction/destruction
    CMSPArray() : m_aT(NULL), m_nSize(0), m_nAllocSize(0)
    { }

    ~CMSPArray()
    {
        RemoveAll();
    }

// Operations
    int GetSize() const
    {
        return m_nSize;
    }
    BOOL Grow()
    {
        T* aT;
        int nNewAllocSize = 
            (m_nAllocSize == 0) ? dwInitial : (m_nSize + DELTA);

        aT = (T*)realloc(m_aT, nNewAllocSize * sizeof(T));
        if(aT == NULL)
            return FALSE;
        m_nAllocSize = nNewAllocSize;
        m_aT = aT;
        return TRUE;
    }

    BOOL Add(T& t)
    {
        if(m_nSize == m_nAllocSize)
        {
            if (!Grow()) return FALSE;
        }
        m_nSize++;
        SetAtIndex(m_nSize - 1, t);
        return TRUE;
    }
    BOOL Remove(T& t)
    {
        int nIndex = Find(t);
        if(nIndex == -1)
            return FALSE;
        return RemoveAt(nIndex);
    }
    BOOL RemoveAt(int nIndex)
    {
        if(nIndex != (m_nSize - 1))
            memmove((void*)&m_aT[nIndex], (void*)&m_aT[nIndex + 1], 
                (m_nSize - (nIndex + 1)) * sizeof(T));
        m_nSize--;
        return TRUE;
    }
    void RemoveAll()
    {
        if(m_nAllocSize > 0)
        {
            free(m_aT);
            m_aT = NULL;
            m_nSize = 0;
            m_nAllocSize = 0;
        }
    }
    T& operator[] (int nIndex) const
    {
        _ASSERTE(nIndex >= 0 && nIndex < m_nSize);
        return m_aT[nIndex];
    }
    T* GetData() const
    {
        return m_aT;
    }

// Implementation
    void SetAtIndex(int nIndex, T& t)
    {
        _ASSERTE(nIndex >= 0 && nIndex < m_nSize);
        m_aT[nIndex] = t;
    }
    int Find(T& t) const
    {
        for(int i = 0; i < m_nSize; i++)
        {
            if(m_aT[i] == t)
                return i;
        }
        return -1;  // not found
    }
};

/*++

CMSPCritSection Description:

    Definitions for a auto initialize critical section.

--*/
class CMSPCritSection
{
private:
    CRITICAL_SECTION m_CritSec;

public:
    CMSPCritSection()
    {
        InitializeCriticalSection(&m_CritSec);
    }

    ~CMSPCritSection()
    {
        DeleteCriticalSection(&m_CritSec);
    }

    void Lock() 
    {
        EnterCriticalSection(&m_CritSec);
    }

    BOOL TryLock() 
    {
        return TryEnterCriticalSection(&m_CritSec);
    }

    void Unlock() 
    {
        LeaveCriticalSection(&m_CritSec);
    }
};

/*++

CMSPCritSection Description:

    Definitions for a auto lock that unlocks when the variable is out
    of scope.

--*/
class CLock
{
private:
    CMSPCritSection &m_CriticalSection;

public:
    CLock(CMSPCritSection &CriticalSection)
        : m_CriticalSection(CriticalSection)
    {
        m_CriticalSection.Lock();
    }

    ~CLock()
    {
        m_CriticalSection.Unlock();
    }
};


/*++

LINK list:

    Definitions for a double link list.

--*/

//
// Calculate the address of the base of the structure given its type, and an
// address of a field within the structure.
//
#ifndef CONTAINING_RECORD
#define CONTAINING_RECORD(address, type, field) \
    ((type *)((PCHAR)(address) - (ULONG_PTR)(&((type *)0)->field)))
#endif


#ifndef InitializeListHead
//
//  VOID
//  InitializeListHead(
//      PLIST_ENTRY ListHead
//      );
//

#define InitializeListHead(ListHead) (\
    (ListHead)->Flink = (ListHead)->Blink = (ListHead))

//
//  BOOLEAN
//  IsListEmpty(
//      PLIST_ENTRY ListHead
//      );
//

#define IsListEmpty(ListHead) \
    ((ListHead)->Flink == (ListHead))

//
//  PLIST_ENTRY
//  RemoveHeadList(
//      PLIST_ENTRY ListHead
//      );
//

#define RemoveHeadList(ListHead) \
    (ListHead)->Flink;\
    {RemoveEntryList((ListHead)->Flink)}

//
//  PLIST_ENTRY
//  RemoveTailList(
//      PLIST_ENTRY ListHead
//      );
//

#define RemoveTailList(ListHead) \
    (ListHead)->Blink;\
    {RemoveEntryList((ListHead)->Blink)}

//
//  VOID
//  RemoveEntryList(
//      PLIST_ENTRY Entry
//      );
//

#define RemoveEntryList(Entry) {\
    PLIST_ENTRY _EX_Blink;\
    PLIST_ENTRY _EX_Flink;\
    _EX_Flink = (Entry)->Flink;\
    _EX_Blink = (Entry)->Blink;\
    _EX_Blink->Flink = _EX_Flink;\
    _EX_Flink->Blink = _EX_Blink;\
    }

//
//  VOID
//  InsertTailList(
//      PLIST_ENTRY ListHead,
//      PLIST_ENTRY Entry
//      );
//

#define InsertTailList(ListHead,Entry) {\
    PLIST_ENTRY _EX_Blink;\
    PLIST_ENTRY _EX_ListHead;\
    _EX_ListHead = (ListHead);\
    _EX_Blink = _EX_ListHead->Blink;\
    (Entry)->Flink = _EX_ListHead;\
    (Entry)->Blink = _EX_Blink;\
    _EX_Blink->Flink = (Entry);\
    _EX_ListHead->Blink = (Entry);\
    }

//
//  VOID
//  InsertHeadList(
//      PLIST_ENTRY ListHead,
//      PLIST_ENTRY Entry
//      );
//

#define InsertHeadList(ListHead,Entry) {\
    PLIST_ENTRY _EX_Flink;\
    PLIST_ENTRY _EX_ListHead;\
    _EX_ListHead = (ListHead);\
    _EX_Flink = _EX_ListHead->Flink;\
    (Entry)->Flink = _EX_Flink;\
    (Entry)->Blink = _EX_ListHead;\
    _EX_Flink->Blink = (Entry);\
    _EX_ListHead->Flink = (Entry);\
    }

#endif //InitializeListHead

//
// Templates for private addref and release. See Platform SDK documentation.
//

template <class T> ULONG MSPAddRefHelper (T * pMyThis)
{
    LOG((MSP_INFO, "MSPAddRefHelper - this = 0x%08x", pMyThis));
    typedef CComAggObject<T> AggClass;
    AggClass * p = CONTAINING_RECORD(pMyThis, AggClass, m_contained);
    return p->AddRef();
}

template <class T> ULONG MSPReleaseHelper (T * pMyThis)
{
    LOG((MSP_INFO, "MSPReleaseHelper - this = 0x%08x", pMyThis));
    typedef CComAggObject<T> AggClass;
    AggClass * p = CONTAINING_RECORD(pMyThis, AggClass, m_contained);
    return p->Release();
}

#pragma option pop /*P_O_Pop*/
#endif  //__MSPUTILS_H_

// eof
