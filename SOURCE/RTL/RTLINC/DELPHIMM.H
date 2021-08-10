
namespace System
{
    typedef void* Pointer;
    typedef int Integer;
    typedef unsigned int Cardinal;

    class TMemoryManager {
      public:
            Pointer __fastcall (*GetMem)(Integer Size);
            Integer __fastcall (*FreeMem)(Pointer P);
            Pointer __fastcall (*ReallocMem)(Pointer P, Integer Size);
    } ;

    struct THeapStatus
    {
      Cardinal TotalAddrSpace;
      Cardinal TotalUncommitted;
      Cardinal TotalCommitted;
      Cardinal TotalAllocated;
      Cardinal TotalFree;
      Cardinal FreeSmall;
      Cardinal FreeBig;
      Cardinal Unused;
      Cardinal Overhead;
      Cardinal HeapErrorCode;
    };


    void*   __cdecl GetMemory(int Size);
    int     __cdecl FreeMemory(void*  P);
    void*   __cdecl ReallocMemory(void*  P, int Size);
    void    __fastcall initialization (void);
    void    __fastcall Finalization (void);
    void    __fastcall SetMemoryManager (const System::TMemoryManager&);
    void    __fastcall GetMemoryManager (System::TMemoryManager&);
    bool    __fastcall IsMemoryManagerSet(void);
    THeapStatus __fastcall GetHeapStatus(void);

}

namespace Borlndmm
{
    void*   __fastcall SysGetMem(int Size);
    int     __fastcall SysFreeMem(void*  P);
    void*   __fastcall SysReallocMem(void*  P, int Size);
}

