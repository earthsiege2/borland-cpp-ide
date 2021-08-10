
#define gmalloc  malloc
#define gfree    free
#define grealloc realloc

//#define WORSTFIT
//#define BESTFIT
//#define BALANCEDFIT

#define UNROLL				// optimize loops
//#define UNROLL2			// optimize loops


#define PAGESIZE	0x1000		// system page size
#define ALIGNMENT	4		// block size alignment
#define MAXSYSBLOCKS 	32		// max number of system blocks that can be merged

//
//	Useful macros
//

#define	ALIGNUPBY(x,a)	(((x)+( (a)-1) )   & (~((a)-1L)))
#define	ALIGNDNBY(x,a)	( (x)              & (~((a)-1L)))

#ifndef MAX
#define MAX(a,b)	( ((a)>(b)) ? (a) : (b) )
#endif

#ifndef MIN
#define MIN(a,b)	( ((a)<(b)) ? (a) : (b) )
#endif

//
//	Block header
//

#define	F_FREE	1			// block is free
#define	F_PFREE	2			// previous block is free
#define	F_BITS	3			// mask for flags in the blocksize
#define	F_SIZE	0xFFFFFFFC		// mask for size in the blocksize


typedef	struct BLOCKHDR
	{
	size_t	blockSize;	// bit 0 = this block is free. bit 1= prev is free

	// for free blocks:

	struct BLOCKHDR * nextFree;
	struct BLOCKHDR * prevFree;
	} BLOCKHDR;

//	free blocks also have a terminating 'size_t' of their size+4.

#define	MINFREEH    sizeof(BLOCKHDR) + sizeof(size_t)
#define	MINFREE     sizeof(BLOCKHDR)
#define	MINSIZE     sizeof(BLOCKHDR)

#define	PTR2HDR(p) ((BLOCKHDR*) ((char*) (p) - sizeof(size_t)))
#define	HDR2PTR(b) ((void *) ((char*) &(b)->blockSize + sizeof(size_t)))

#define	SIZE(b)    (((b)->blockSize)& (~F_BITS))
#define	ISFREE(b)  (((b)->blockSize)&F_FREE)
#define	ISPFREE(b) (((b)->blockSize)&F_PFREE)
#define	PFREE(b)   ((BLOCKHDR*) ((char *) (b) - *((size_t*) (b) - 1)))
#define	NEXT(b)    ((BLOCKHDR*) ((char *) HDR2PTR(b) + SIZE(b)))

#define	SETFSIZE(b,s) *((size_t*)((char *)(b) + s)) = s+sizeof(size_t)

//
//
// The heap header
//
//

typedef struct HEAP
	{
	size_t 	cSize;			// committed size, 'brklevel'
	size_t	rSize;			// reserved size
	int	numSysBlocks;		// number of system blocks this heap consists of
	char *	sysBlocks[MAXSYSBLOCKS];// address of system blocks

	struct HEAP	* nextHeap;	// next non-contigous heap
	struct HEAP	* prevHeap;	// previous non-contigous heap
	} HEAP;

#define	LASTBLOCK(h)  ((BLOCKHDR*) ((char *) (h) + (h)->cSize -sizeof(size_t)))
#define	FIRSTBLOCK(h) ((BLOCKHDR*) ((char *) (h) + sizeof(HEAP)))



#define ADDFREEAFTER(b,f)	b->nextFree = (f)->nextFree;b->prevFree=(f);\
				       b->nextFree->prevFree=b;(f)->nextFree=b;

#define REMOVEFREE(b) 		b->nextFree->prevFree = b->prevFree; \
			               b->prevFree->nextFree = b->nextFree;



#define	HDR4SIZE(x)	((BLOCKHDR*) ((char *) _linktable + (x)*(sizeof(DLINK)/ALIGNMENT)-(sizeof(size_t)+sizeof(DLINK))))

typedef struct	DLINK
	{
	BLOCKHDR * nextFree;
	BLOCKHDR * prevFree;
	} DLINK;


int _virt_commit( void * addr, size_t size);
int _virt_decommit( void * addr, size_t size);
int _virt_reserve(size_t req, void ** v, size_t * vsize);
int	_virt_release(void * addr);
size_t	_phys_avail(void);


// global vars

extern size_t	_smalloc_threshold;
#ifdef	BALANCEDFIT
extern int	_numSmall;
extern int	_numBig;
#endif

extern HEAP	* _firstHeap;
extern HEAP	* _lastHeap;
extern DLINK    * _linktable;
extern BLOCKHDR   _freeStart;
extern BLOCKHDR * _rover;


void * _RTLENTRY _EXPFUNC gmalloc(size_t size);
void   _RTLENTRY _EXPFUNC gfree(void *block);
void * _RTLENTRY _EXPFUNC grealloc(void * block, size_t size);
void * _RTLENTRY _EXPFUNC _expand(void * block, size_t size);
size_t _RTLENTRY _EXPFUNC _msize(void * block);

#ifdef _MT
void _lock_heap(void);
void _unlock_heap(void);
#else
#define _lock_heap()
#define _unlock_heap()
#endif /* _MT */

int _memchk (void *, int, size_t);