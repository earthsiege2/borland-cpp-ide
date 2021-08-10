#define	NEWXX
#define USE_XX_VARS
#include "xx.h"

#ifndef __NON_STD_ASSERT__
#include <assert.h>
#endif

#ifdef	DEBUG
#define	DPRINTF(x)	printf x
#else
#define	DPRINTF(x)
#endif

	#define	PRONTO

#if     defined(DEBUG) || defined(RTTI)

char    *       __typeIDname(tpidPtr id)
{

#if     !defined(__FLAT__) && !defined(LDATA)

	char    __near *        dst;
	tpchPtr         src;

static  char            buff[256];

#endif

	if      (id == 0)
		return  "<notype>";

	assert(id->tpName);

#if     !defined(__FLAT__) && !defined(LDATA)

	src = (tpchPtr)id + id->tpName;
	dst = buff;

	do
	{
		if      (dst == buff + sizeof(buff) - 1)
		{
			*dst = 0;
			break;
		}

		*dst = *src;
	}
	while   (dst++, *src++);

	return  buff;

#else

	return  (tpchPtr)id + id->tpName;

#endif

}

#endif

///////////////////////////////////////////////////////////////////////////////
//
//      Each type-id starts with the type size. This is followed by the
//      'type mask', which has the following bits:
//
//              0x0001 if class
//
//              0x0002 unused
//              0x0004 unused
//              0x0008 unused
//
//              0x0010 if pointer
//              0x0020 if reference
//
//              0x0040 if void pointer
//
//              0x0080 if local type
//
//              0x0100 if const
//              0x0200 if volatile
//
//              0x0400 if array
//
//              0x4000 if class with a virtual destructor
//              0x8000 if class with RTTI
//
//      In segmented address environment:
//
//              0x1000 if near     pointer/reference
//              0x2000 if  far     pointer/reference
//
//      The class flags are defined as follows:
//
//              0x0001 if class w/constructors
//              0x0002 if class w/destructors
//
//              0x0004 if class w/bases
//              0x0008 if class w/virtual bases
//
//              0x0010 if class with a virtual table
//              0x0020 if class with a virtual destructor
//              0x0040 if class with a RTTI-style vtable
//
//              0x1000 if class with a far vtable pointer
//
//      Notes:
//
//              The class flags may be combined.
//
//              Pointer and reference types are encoded as 0x0008/0x0010 (with
//              the near/far bit set in non-flat mode), followed by the type-id
//              of the 'pointed-to' type.
//
//              For all other (i.e. non-pointer/non-reference) types, the mask
//              is followed by a length-prefixed mangled name of the type.
//
//              Finally, for class types (the 'mask' has (0x0001|0x0002) set),
//              the mode and address of the copy-constructor and destructor
//              follow.
//
///////////////////////////////////////////////////////////////////////////////

#ifdef  DISP_TYPE_ID

void    dispBaseClassList(baseListPtr blp)
{
	DPRINTF(("\n"));

	for     (;;blp++)
	{
		tpidPtr         a;

		a = blp->blType;

		if      (a == 0)
			return;

		DPRINTF(("\t\tBase = '%10s', offset = %08lX, flags = %04X\n", __typeIDname(a), (long)blp->blOffs, blp->blFlags));
	}
}

void    dispDtMembersList(tpchPtr cp)
{
	DPRINTF(("\n"));

	for     (;;)
	{
		tpidPtr         a;
		unsigned        o;

		a = *((tpidPtr TPDST *)cp)++;

		if      (a == 0)
			return;

		o = *((unsigned TPDST *)cp)++;

		DPRINTF(("\t\tMember type = '%10s', offset = %04X\n", __typeIDname(a), o));
	}
}

void    dispTypeID(tpidPtr p)
{
	unsigned        mask;

AGAIN:

	DPRINTF(("Type descriptor at %Fp: ", p));

	/* Get the mask */

	mask = p->tpMask;

	/* Is this a pointer or reference? */

	if      (mask & (TM_IS_PTR|TM_IS_REF))
	{
		if      (mask & TM_IS_PTR)
			DPRINTF(("pointer   to ...\n"));
		else
			DPRINTF(("reference to ...\n"));

		p = p->tpPtr.tppBaseType;

		goto AGAIN;
	}

	/* Is this an array type? */

	if      (mask & TM_IS_ARRAY)
	{
		DPRINTF(("array[%d] of ...\n", p->tpArr.tpaElemCount));

		p = p->tpArr.tpaElemType;

		goto AGAIN;
	}

	assert(p->tpName);

	DPRINTF(("'%s'\n", (char *)p + p->tpName));

	DPRINTF(("\tType size = %u\n", p->tpSize));
	DPRINTF(("\tType mask = %u\n", p->tpMask));

	/* If this is not a class, we're done */

	if      (!IS_CLASS(mask))
		goto DONE;

	/* Display base lists */

	if      (p->tpClass.tpcBaseList)
		dispBaseClassList((baseListPtr)((tpchPtr)p + p->tpClass.tpcBaseList));

	if      (p->tpClass.tpcVbasList)
		dispBaseClassList((baseListPtr)((tpchPtr)p + p->tpClass.tpcVbasList));

	/* Display destruction info, if present */

	if      (p->tpClass.tpcFlags & CF_HAS_DTOR)
	{
		DPRINTF(("\tDestructor       address = %Fp, mask = %04X\n", p->tpClass.tpcDtorAddr,
									  p->tpClass.tpcDtorMask));

		DPRINTF(("\tDestructor count         = %u\n", p->tpClass.tpcDtorCount));

		if      (p->tpClass.tpcDtMembers)
			dispDtMembersList((tpchPtr)p + p->tpClass.tpcDtMembers);
	}

//      /* Type id must be terminated by negated size */
//
//      if      (-size != *((unsigned TPDST *)cp))
//              DPRINTF(("\tError: negated size missing.\n"));

DONE:

	DPRINTF(("\n\n"));
}

#endif

///////////////////////////////////////////////////////////////////////////////
//
//      Return non-zero if the two given types are identical.
//

int             __isSameTypeID(tpidPtr tp1, tpidPtr tp2)
{
	tpchPtr         tp1Name;
	tpchPtr         tp2Name;

	int             tp1Ch;
	int             tp2Ch;

	assert(tp1);
	assert(tp2);

	/* First try the easy way */

	if      (tp1 == tp2)
		return  1;

	/* Type mask and size must match */

	if      (tp1->tpMask != tp2->tpMask ||
		 tp1->tpSize != tp2->tpSize)
	{
		return  0;
	}

	/* No match if local types */

	if      ((tp1->tpMask | tp2->tpMask) & TM_LOCALTYPE)
	{
		return  0;
	}

	/* Make the sure the names match */

	tp1Name = (tpchPtr)tp1 + tp1->tpName; assert(tp1->tpName);
	tp2Name = (tpchPtr)tp2 + tp2->tpName; assert(tp2->tpName);

	do
	{
		tp1Ch = *tp1Name++;
		tp2Ch = *tp2Name++;

		if      (tp1Ch != tp2Ch)
			return  0;
	}
	while   (tp1Ch);

	return  1;
}

///////////////////////////////////////////////////////////////////////////////
//
//      Return non-zero if 'base' is an accessible base class of 'derv',
//      given the friend list 'flist'.
//

static  int     __near  isAccessibleBase(tpidPtr        derv,
					 tpidPtr        base,
					 tpidPtr TPDST *flist,
					 int            isPublic)
{
	baseListPtr     baseList;

	assert(IS_STRUC(base->tpMask));
	assert(IS_STRUC(derv->tpMask));

	assert(derv->tpClass.tpcFlags & CF_HAS_BASES);

	/* Try the     virtual base list */

	baseList = (baseListPtr)((tpchPtr)derv + derv->tpClass.tpcVbasList);

	for     (;; baseList++)
	{
		int             basePublic;

		tpidPtr         baseType = baseList->blType;

		/* Stop if end of list reached */

		if      (!baseType)
			break;

		/* Ignore the base if indirect */

		if      (baseList->blFlags & 8)
			continue;

		/* Figure out whether the base is public */

		basePublic = isPublic && ((baseList->blFlags & 3) == 3);

		/* Is this base the class we're looking for? */

		if      (__isSameTypeID(base, baseType))
		{
			/* Got it, but it must be accessible */
	
			if      (basePublic)
				return  1;
		}

		/* Does the base itself have any bases? */

		if      (baseType->tpClass.tpcFlags & CF_HAS_BASES)
		{
			/* Recursively search the base */

			if      (isAccessibleBase(baseType, base, flist, basePublic))
				return  1;
		}
	}

	/* Try the non-virtual bases list */

	baseList = (baseListPtr)((tpchPtr)derv + derv->tpClass.tpcBaseList);

	for     (;; baseList++)
	{
		int             basePublic;

		tpidPtr         baseType = baseList->blType;

		/* Stop if end of list reached */

		if      (!baseType)
			break;

		/* Figure out whether the base is public */

		basePublic = isPublic && ((baseList->blFlags & 3) == 3);

		/* Is this base the class we're looking for? */

		if      (__isSameTypeID(base, baseType))
		{
			/* Got it, but it must be accessible */
	
			if      (basePublic)
				return  1;
		}

		/* Does the base itself have any bases? */

		if      (baseType->tpClass.tpcFlags & CF_HAS_BASES)
		{
			/* Recursively search the base */

			if      (isAccessibleBase(baseType, base, flist, basePublic))
				return  1;
		}
	}

	return  0;
}

///////////////////////////////////////////////////////////////////////////////
//
//      Return non-zero if the an argument of typeid 'dst' can be initialized
//      with a value of type 'src'. When the 'exact' argument is zero, trivial
//      pointer conversions are allowed (near -> far, T* -> const T*, etc).
//
//      The 'friend list' parameter is used for 'derived -> base' conversions.
//

int     __near  __isCompatTypeID(tpidPtr          src,
				 tpidPtr          dst,
				 int              exact,
				 tpidPtr  TPDST * flist)
{
	unsigned        srcMask;
	unsigned        dstMask;

AGAIN:

	/* First try the easy way */

	if      (src == dst)
		return  1;

	/* Get the masks */

	srcMask = src->tpMask;
	dstMask = dst->tpMask;

	/* Are both pointer types? */

	if      ((srcMask & dstMask) & TM_IS_PTR)
	{
		/* Get rid of uninteresting bits in the masks */

#ifdef  __FLAT__
		srcMask &= (TM_IS_CONST|TM_IS_VOLATILE                            );
		dstMask &= (TM_IS_CONST|TM_IS_VOLATILE                            );
#else
		srcMask &= (TM_IS_CONST|TM_IS_VOLATILE|TM_IS_NEARPTR|TM_IS_FAR_PTR);
		dstMask &= (TM_IS_CONST|TM_IS_VOLATILE|TM_IS_NEARPTR|TM_IS_FAR_PTR);
#endif

		/* The masks must agree */

		if      (srcMask != dstMask)
		{
			/* Are pointer modifiers allowed to disagree? */

			if      (!exact)
			{
				/* Any differences in const/volatile? */

				if      ((srcMask & (TM_IS_CONST|TM_IS_VOLATILE)) !=
					 (dstMask & (TM_IS_CONST|TM_IS_VOLATILE)))
				{
					if      ( (srcMask & (TM_IS_CONST|TM_IS_VOLATILE)) &
						 ~(dstMask & (TM_IS_CONST|TM_IS_VOLATILE)))
						return  0;

					srcMask |= (TM_IS_CONST|TM_IS_VOLATILE);
					dstMask |= (TM_IS_CONST|TM_IS_VOLATILE);

					if      (srcMask == dstMask)
						goto PTR_OK;
				}

#ifndef __FLAT__

				/* Is the only difference in pointer sizes? */

				if      ((srcMask | (TM_IS_NEARPTR|TM_IS_FAR_PTR)) ==
					 (dstMask | (TM_IS_NEARPTR|TM_IS_FAR_PTR)))
				{
					/* It's a match if 'src' is 'near' */

					if      (srcMask & TM_IS_NEARPTR)
						return  1;
				}

#endif

			}

			return  0;
		}

	PTR_OK:

		exact = 1;

		/* Looks OK, now compare the base types */

		src = src->tpPtr.tppBaseType;
		dst = dst->tpPtr.tppBaseType;

		goto AGAIN;
	}

	/* Are both array types? */

	if      ((srcMask & dstMask) & TM_IS_ARRAY)
	{
		/* The dimensions better agree */

		if      (src->tpArr.tpaElemCount != dst->tpArr.tpaElemCount)
		{
			if      (exact || (src->tpArr.tpaElemCount |
					   dst->tpArr.tpaElemCount))
			{
				return  0;
			}
		}

		exact = 1;

		/* Looks OK, now compare the element types */

		src = src->tpArr.tpaElemType;
		dst = dst->tpArr.tpaElemType;

		goto AGAIN;
	}
	
	/* Are these identical types? */

	if      (__isSameTypeID(src, dst))
		return  1;

	/* Is the source a class with bases? */

	if      (IS_CLASS(srcMask) && IS_STRUC(dstMask))
	{
		if      (src->tpClass.tpcFlags & CF_HAS_BASES)
			return  isAccessibleBase(src, dst, flist, 1);
	}

	return  0;
}

///////////////////////////////////////////////////////////////////////////////
//
//      Routines that return the -xp exception source/name info. These are
//      implemented as function calls so that DLL's work.
//

char *      _RTLENTRY _EXPFUNC __ThrowFileName     () { return __throwFileName     ; }
unsigned    _RTLENTRY _EXPFUNC __ThrowLineNumber   () { return __throwLineNumber          ; }
char *      _RTLENTRY _EXPFUNC __ThrowExceptionName() { return __throwExceptionName; }

///////////////////////////////////////////////////////////////////////////////
#ifdef  RTTI
///////////////////////////////////////////////////////////////////////////////

#include "typeinfo.h"
using namespace std;


		__cdecl type_info::type_info(const type_info &)
{
	throw   (type_info*)0;
}

type_info &      __cdecl type_info::operator=(const type_info &)
{
	return  *this;
}

		__cdecl type_info::~type_info()
{
}

//-----------------------------------------------------------------------------

bool	__cdecl	type_info::operator==(const type_info & other) const
{
	if	(tpp == other.tpp)
		return	true;
	if	(        tpp && (((tpidPtr)      tpp)->tpMask & TM_LOCALTYPE)
		|| other.tpp && (((tpidPtr)other.tpp)->tpMask & TM_LOCALTYPE))
		return	false;
	return	strcmp(name(), other.name()) == 0;
}

bool	__cdecl	type_info::operator!=(const type_info & other) const
{
	return	!(*this == other);
}

bool    __cdecl type_info::before    (const type_info &B) const
{
	return  strcmp(name(), B.name()) < 0;
}

///////////////////////////////////////////////////////////////////////////////

static  bad_typeid      __bad_typeid;

//	This is the new version that allocates type_info structures on the heap
//	and deals with delphi classes as well

class	type_info_hash : public type_info
{
public:
	void		*vmt;
	type_info_hash	*next;
	mutable char	*name;

	type_info_hash(void *_tpp, void *_vmt, type_info_hash *_next) : type_info((tpid *)_tpp)
	{
		vmt  = _vmt;
		next = _next;
		name = 0;
	}
};

#define	HASHSIZ	256

static	type_info_hash	*hashTab[HASHSIZ];


void    __far * DEFCC   __GetTypeInfo(void      __far * objectPtr,
				      void      __far * vtablePtr,
				      void      __far * typeidPtr)
{
	tpidPtr         mdtpidPtr;
	tpidPtr         aptpidPtr = (tpidPtr   )typeidPtr;
	int		hash;
	type_info_hash	*h;


	/* First make sure that the pointer is not NULL */

	if      (!objectPtr)
		throw   __bad_typeid;

#if     defined(__TINY__) || defined(__SMALL__) || defined(__MEDIUM__)

	/* Check for 'near 0' cast to a far pointer */

	if      (objectPtr == MK_FP(_DS,0))
		throw   __bad_typeid;

#endif

	if	(vtablePtr)
	{
		//	Check whether this is a delphi class

		if	(aptpidPtr->tpClass.tpcFlags & CF_DELPHICLASS)
		{
			//	This is a delphi class - we can't find the runtime
			//	rtti easily and instead use the vtable to get the class name

			mdtpidPtr = 0;
		}
		else
		{
			/* Find the 'bottom' of the vtable */

			vtablePtr = (char __far *)vtablePtr - ((unsigned __far *)vtablePtr)[-1];

			assert(((unsigned __far *)vtablePtr)[-1] == 0);
//			assert(((unsigned __far *)vtablePtr)[-2] == 0);

			/* Extract the 'most derived type id' address from the vtable */

			mdtpidPtr = *((tpidPtr TPDST *)((unsigned __far *)vtablePtr - 2) - 1);

			DPRINTF(("__GetTypeInfo() :\n"));

			DPRINTF(("\tAccess       type = '%s'\n", __typeIDname(aptpidPtr)));
			DPRINTF(("\tMost derived type = '%s'\n", __typeIDname(mdtpidPtr)));

			DPRINTF(("\n"));
		}
	}
	else
		mdtpidPtr = aptpidPtr;

	hash = (((int)vtablePtr + (int)mdtpidPtr) >> 4) & (HASHSIZ-1);
	for	(h = hashTab[hash]; h; h = h->next)
		if	((void *)h->tpp == mdtpidPtr && h->vmt == vtablePtr)
			break;

	if	(h == 0)
		hashTab[hash] = h = new type_info_hash(mdtpidPtr, vtablePtr, hashTab[hash]);

	return	h;
}

// Free the hash memory so that CodeGuard and MemorySleuth don't have a cow.
static void FreeHashTab (void)
{
#pragma exit FreeHashTab 1  /* Finalize the hash memory blocks */
                            /* This must happen before the heap shuts down */

        int j;
        type_info_hash *h, *l;

        for (j=0;j<HASHSIZ;j++)
                if ((h=hashTab[j]) != NULL)
                        while (h)
                        {
                                l = h->next;
                                delete h;
                                h = l;
                        }
}


void    __far * DEFCC   __GetTypeInfo(void      __far * objectPtr,
				      void      __far * vtablePtr,
				      void      __far * typeidPtr,
				      void      __far * tpinfoPtr)
{
	return	__GetTypeInfo(objectPtr, vtablePtr, typeidPtr);
}

#define	VT_CLASS_NAME_OFFS	(-44)

const
char * __cdecl type_info::name    () const
{
	type_info_hash *h = (type_info_hash *)this;

	if	(!h->tpp)
	{
		if	(h->name)
			return	h->name;

		if	(!h->vmt)
			return	"<notype>";

		//	This is the delphi class case

		char	*className;
		int	len;

		className = *(char **)((char *)h->vmt + VT_CLASS_NAME_OFFS);
		len = (unsigned char)className[0];
		h->name = new char[len+1];
		memcpy(h->name, className+1, len);
		h->name[len] = 0;

		return	h->name;
	}

	return  __typeIDname(tpp);
}
///////////////////////////////////////////////////////////////////////////////

void * __cdecl type_info::_internal_rtti_cast(void *srcObj, const type_info *srcType) const
{
	void *vtab = NULL;
	void **pv;
	if (srcObj)
	{
		pv = (void **) srcObj;
		vtab = *pv;
	}
	return __DynamicCast(srcObj, vtab, (void *)srcType->tpp, (void *)this->tpp, 0);
}

///////////////////////////////////////////////////////////////////////////////

//
//  Digs the guid struct out of the type info structure.
//  See xx.h for how the 'tpid' struct is layed out
//  See the 'outputClassTypeId' function in cppfin.c
//  in the C/C++ compiler to see how the type info
//  struct is filled in.
//

const
_BORGUID *			__cdecl type_info::_guid		() const
{
	unsigned int	guidOffset;

	// Do we have a guid

	if	(tpp == 0 || !(tpp->tpClass.tpcFlags & CF_HAS_GUID))
		return	NULL;

	// To keep the typeinfo backwards compatible, we have to jump
	// through hoops to tack on something new at the end of
	// the struct, since the whole struct is of variable length
	// based on internal flags...
	//
	// There are 3 possibilities at present:
	//
	//	- (tpMask & TM_IS_CLASS) is not true
	//	  The guid will live right after the tpcFlags
	//
	//  - (tpMask & TM_IS_CLASS) is true, (tpcFlags & CF_HAS_DTOR) is not true
	//    The guid will live right after tpcDaOpAddr
	//
	//  - (tpMask & TM_IS_CLASS) is true, (tpcFlags & CF_HAS_DTOR) is not true
	//    The guid will live right after tpcDtMembers

	// Do we have bases or delete info

	if	(IS_CLASS(tpp->tpMask))
	{
		// Do we also have destructible member info

		if	(tpp->tpClass.tpcFlags & CF_HAS_DTOR)
			guidOffset = offsetof(tpid, tpClass.guid);
		else
			guidOffset = offsetof(tpid, tpClass.tpcDtorCount);
	}
	else
	{
		guidOffset = offsetof(tpid, tpClass.tpcBaseList);
	}

	return  (const _BORGUID *)((tpchPtr)tpp + guidOffset);
}


///////////////////////////////////////////////////////////////////////////////

static  void    __far * __near  findBaseClass(void      __far * objectPtr,
					      tpidPtr           topTypPtr,
					      void      __far * targetPtr,
					      tpidPtr           tgtTypPtr,
					      void      __far * sourcePtr,
					      tpidPtr           srcTypPtr,
					      int         _ss * publicPtr,
					      int               isPublic,
					      tpidPtr           inVbase)
{
	baseListPtr     baseList;
	unsigned        blistCnt;

	int             matchPublic = 0;
	void    __far * matchAddr   = 0;
	unsigned        matchCnt    = 0;

	assert(topTypPtr != 0 && IS_STRUC(topTypPtr->tpMask));
	assert(tgtTypPtr != 0 && IS_STRUC(tgtTypPtr->tpMask));
	assert(srcTypPtr == 0 || IS_STRUC(srcTypPtr->tpMask));

	if      (srcTypPtr)
	{
		assert(__isSameTypeID(srcTypPtr, tgtTypPtr) == 0);

		if      (__isSameTypeID(srcTypPtr, topTypPtr))
			return  0;
	}

	assert(tgtTypPtr != 0 && __isSameTypeID(topTypPtr, tgtTypPtr) == 0);

	/* Give up if there are no base classes */

	if      (!(topTypPtr->tpClass.tpcFlags & CF_HAS_BASES))
		return  0;

	/* Start with the virtual base list */

	blistCnt = 0;
	baseList = (baseListPtr)((tpchPtr)topTypPtr + topTypPtr->tpClass.tpcVbasList);

AGAIN:

	for     (;; baseList++)
	{
		int             basePublic;
		void    __far * baseAddress;

		tpidPtr         baseVbase;

		tpidPtr         baseType = baseList->blType;

		/* Stop if end of list reached */

		if      (!baseType)
			break;

		DPRINTF(("\n"));
		DPRINTF(("\t\tLooking for base '%s'\n", __typeIDname(tgtTypPtr)));
		DPRINTF(("\t\tLooking in class '%s'\n", __typeIDname(topTypPtr)));
		DPRINTF(("\t\tLooking at  base '%s'\n", __typeIDname(baseType )));

		/* Ignore the base if indirect */

		if      (baseList->blFlags & 8)
			continue;

		/* Figure out whether the base is public */

		basePublic  = isPublic && ((baseList->blFlags & 3) == 3);

		/* Figure out the address of this base */

		baseAddress = (char __far *)objectPtr + baseList->blOffs;

		/* Is the base class virtual? */

		baseVbase   = inVbase;

		if      (baseList->blFlags & 4)
		{
			/* Dereference the vbase pointer */

#ifdef  __FLAT__
			baseAddress = *(char **)baseAddress;
#else
			baseAddress = (char __far *)MK_FP(FP_SEG(baseAddress), *(int __far *)baseAddress);
#endif

			/* Remember the nearest vbase */

			baseVbase = baseType;
		}

		/* Is this the base class we're looking for? */

		if      (!__isSameTypeID(tgtTypPtr, baseType))
		{
			/* No good; does the base itself have any bases? */

			if      (baseType->tpClass.tpcFlags & CF_HAS_BASES)
			{
				void    __far * foundAddr;

				/* Recursively search the base */

				foundAddr = findBaseClass(baseAddress,
							  baseType,
							  targetPtr,
							  tgtTypPtr,
							  sourcePtr,
							  srcTypPtr,
							  publicPtr,
							  basePublic,
							  baseVbase);

				if      (foundAddr)
				{
					baseAddress = foundAddr;
					basePublic  = *publicPtr;

					goto FOUND_IT;
				}
			}

			continue;
		}

		/* Base type matches; does the address have to match as well? */

		if      (targetPtr)
		{
			/* The base address must match the target address */

			if      (targetPtr != baseAddress)
				continue;

			/* This is precisely what we're looking for */

			return  baseAddress;
		}

		/* Are we looking for a sub-object? */

		if      (sourcePtr)
		{
			assert(srcTypPtr);

			/* Look for the 'source' sub-object */

			if      (!findBaseClass(baseAddress,
						baseType,
						sourcePtr,
						srcTypPtr,
						0,
						0,
						publicPtr,
						0,
						0))
			{
				/* Doesn't contain the right sub-object */

				continue;
			}
		}

	FOUND_IT:

		/* We have a match */

		if      (matchCnt)
		{
			/* If it's the same (virtual) base, ignore it */

			if      (baseAddress == matchAddr)
			{
				matchPublic |= basePublic;
				continue;
			}
		}

		matchCnt++;

		matchAddr   = baseAddress;
		matchPublic = basePublic;
	}

	if      (blistCnt == 0)
	{
		blistCnt++;

		baseList = (baseListPtr)((tpchPtr)topTypPtr + topTypPtr->tpClass.tpcBaseList);

		goto AGAIN;
	}

	/* Return the matching base's address if we had exactly one match */

	*publicPtr = matchPublic;

	if      (matchCnt != 1)
		matchAddr = 0;

	return  matchAddr;
}

///////////////////////////////////////////////////////////////////////////////
//
//      The compiler-called routine that performs dynamic casts. The following
//      values are passed to this function:
//
//          -   the address of the object (the pointer/reference value)
//          -   the address of the vtable for the object
//          -   the (static) typeid of the source type
//          -   the (static) typeid of the target type
//          -   a boolean value indicating whether this is a reference cast
//
//      The new pointer value is returned if possible; otherwise, either
//      a NULL pointer is returned or 'bad_cast' is thrown.
//

static  bad_cast        __bad_cast;

void    __far * DEFCC   __DynamicCast(void      __far * objectPtr,
				      void      __far * vtablePtr,
				      void      __far * srctypPtr,
				      void      __far * dsttypPtr,
				      int               reference)
{
	tpidPtr         srcTypPtr = (tpidPtr)srctypPtr;
	tpidPtr         dstTypPtr = (tpidPtr)dsttypPtr;

	tpidPtr         mdtpidPtr;
	void    __far * bottomPtr;

	void    __far * adjustPtr;

	int             matchPub;

	/* Check for NULL pointer */

	if      (!objectPtr)
		goto NULL_PTR;
		
#if     defined(__TINY__) || defined(__SMALL__) || defined(__MEDIUM__)

	/* Check for 'near 0' cast to a far pointer */

	if      (objectPtr == MK_FP(_DS,0))
		goto NULL_PTR;

#endif

	DPRINTF(("\n__DynamicCast() :\n"));

	DPRINTF(("\tObject address    = %p  \n", objectPtr));
	DPRINTF(("\tVtable address    = %p  \n", vtablePtr));

	DPRINTF(("\tSource       type = '%s'\n", __typeIDname(srcTypPtr)));
	DPRINTF(("\tTarget       type = '%s'\n", __typeIDname(dstTypPtr)));

	DPRINTF(("\tVtable adjustment = %04X\n", ((unsigned __far *)vtablePtr)[-1]));
	DPRINTF(("\tAddr.  adjustment = %04X\n", ((unsigned __far *)vtablePtr)[-2]));

	/* Locate the true bottom of the object and its type */

	bottomPtr = (char __far *)objectPtr - ((unsigned __far *)vtablePtr)[-2];
	vtablePtr = (char __far *)vtablePtr - ((unsigned __far *)vtablePtr)[-1];

	assert(((unsigned __far *)vtablePtr)[-1] == 0);
//      assert(((unsigned __far *)vtablePtr)[-2] == 0);

	/* Extract the 'most derived type id' address from the vtable */

	mdtpidPtr = *((tpidPtr TPDST *)((unsigned __far *)vtablePtr - 2) - 1);

	DPRINTF(("\tVtable (adjusted) = %p  \n", vtablePtr));

	DPRINTF(("\tMost derived type = '%s'\n", __typeIDname(mdtpidPtr)));
	DPRINTF(("\tMost derived addr = %p  \n", bottomPtr));

	DPRINTF(("\n"));

	/* If the target is 'void *', just return the 'bottom' pointer */

	if      (!dsttypPtr)
		return  bottomPtr;

	/* If the target is the same as 'most-derived', also return 'bottom' */

	if      (__isSameTypeID(dstTypPtr, mdtpidPtr))
		return  bottomPtr;

	/*
		We have to check for two possibilities here:

		(1)

			ptr ----->     BASE

					^
					|
					|

				      target

					^
					|
					|

				    most-derived

			In this case we return a pointer to that
			'target' base that contains the base class
			pointed to by the pointer value. Note that
			the 'most-derived' object might contain
			more than one instance of 'BASE'.

		(2)

			ptr ----->     BASE    target

					 \       /
					  \     /
					   \   /

					most-derived

			In this case we convert the pointer to point
			to 'most derived', and then convert it to
			'target' (which must be a unique base class).

	 */

	if      (!__isSameTypeID(srcTypPtr, mdtpidPtr))
	{
		adjustPtr = findBaseClass(bottomPtr,
					  mdtpidPtr,
					  0,
					  dstTypPtr,
					  objectPtr,
					  srcTypPtr,
					  &matchPub,
					  1,
					  0);

		if      (adjustPtr)
			return  adjustPtr;
	}

	/* Now look for an unambiguous base 'dstTypPtr' within 'mdtpidPtr' */

	adjustPtr = findBaseClass(bottomPtr,
				  mdtpidPtr,
				  0,
				  dstTypPtr,
				  0,
				  0,
				  &matchPub,
				  1,
				  0);

	if      (adjustPtr && matchPub)
		return  adjustPtr;

NULL_PTR:

	/* No luck, return a NULL pointer or throw an exception */

	if      (reference)
		throw   __bad_cast;

	return  0;
}

///////////////////////////////////////////////////////////////////////////////
#ifdef	PRONTO


#define	VT_PARENT_OFFS	(-36)

void	*__fastcall _EXPFUNC __DynamicCastVCLref(void *ptr, void *targetVMT)
{
	void	*sourceVMT;

	if	(ptr != 0)
	{
		sourceVMT = *(void **)ptr;
		while	(1)
		{
			if	(sourceVMT == targetVMT)
				return	ptr;

			sourceVMT = *(void **)((char *)sourceVMT + VT_PARENT_OFFS);
			if	(sourceVMT == 0)
				break;
			sourceVMT = *(void **)sourceVMT;
		}
	}

	throw	__bad_cast;
}


void	*__fastcall _EXPFUNC __DynamicCastVCLptr(void *ptr, void *targetVMT)
{
	void	*sourceVMT;

	if	(ptr != 0)
	{
		sourceVMT = *(void **)ptr;
		while	(1)
		{
			if	(sourceVMT == targetVMT)
				return	ptr;

			sourceVMT = *(void **)((char *)sourceVMT + VT_PARENT_OFFS);
			if	(sourceVMT == 0)
				break;
			sourceVMT = *(void **)sourceVMT;
		}
	}

	return	0;
}
#endif
///////////////////////////////////////////////////////////////////////////////
#endif  /* RTTI */
///////////////////////////////////////////////////////////////////////////////
#ifdef  BRITTLE
///////////////////////////////////////////////////////////////////////////////

void    __far * __CreateVtableFunc(void __far * topType,
				   unsigned     baseNo)
{
	assert(!"__CreateVtableFunc() called");

	return  0;
}

void    __far * __LookupVFaddr(void     __far * objectPtr,
			       void     __far * vtablePtr,
			       void     __far * vfcDscPtr)
{
	assert(!"__LookupVFaddr() called");

	return  0;
}

///////////////////////////////////////////////////////////////////////////////
#endif  /* BRITTLE */
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
//      Look for the base class entry 'dsttp' on the specified base list;
//      if found, adjust the class address 'addr' to point to the base
//      sub-object and return non-zero. 'blp' points to the base class
//      list, 'vbase' indicates whether this is the virtual base class
//      list or the non-virtual one.
//
//      Note that the class address is always 'far', in order to allow
//      'far' classes to be used with exceptions in small data memory
//      models.
//

static  int     __near  locateBaseClass(baseListPtr     blist,
					int             vbase,
					tpidPtr         dst,
					void __far*_ss &addr)
{
	assert(addr);           // should never be called for NULL pointer

	for     (;; blist++)
	{
		tpidPtr         btp;
		void    __far * ptr;
		baseListPtr     bbs;

		btp = blist->blType;

		/* Check for end of base list */

		if      (btp == 0)
			return  0;

		DPRINTF(("\t\tSearching base class '%s'\n", __typeIDname(btp)));

		/* Adjust the pointer to point to this base */

		ptr = (char __far *)addr + blist->blOffs;

		/* Is the base class virtual? */

		if      (vbase)
		{
			/* Dereference the vbase pointer */

#ifdef  __FLAT__
			ptr = *(char **)ptr;
#else
			ptr = (char __far *)MK_FP(FP_SEG(ptr), *(int __far *)ptr);
#endif

		}

		/* Is this the right base class? */

		if      (__isSameTypeID(btp, dst))
		{
			/* Match --> return the adjusted pointer to the caller */

			addr = ptr;

			return  1;
		}

		/* Does this base class have any base classes? */

		if      (!IS_CLASS(btp->tpMask))
			continue;

		/* Get the list of non-virtual bases for this base class */

		bbs = (baseListPtr)((tpchPtr)btp + btp->tpClass.tpcBaseList);

		/* Give up on this base if it has no non-virtual bases */

		if      (bbs == 0)
			continue;

		/* Search the base classes of this base recursively */

		if      (locateBaseClass(bbs, 0, dst, ptr))
		{
			/* Match --> return the adjusted pointer to the caller */

			addr = ptr;

			return  1;
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
//
//      Given a derived class type-id 'srctp' and an address of an object
//      of that derived type, and a base class type-id 'dsttp', convert
//      the object address to point to the base class sub-object. Return
//      the adjusted object address.
//

void    * __adjustClassAdr(void     __far * ptr,
		           tpidPtr          srctp,
		           tpidPtr          dsttp)
{
	baseListPtr     blst;

	DPRINTF(("Adjusting class address from '%s *'", __typeIDname(srctp)));
	DPRINTF((" to '%s *'\n",                        __typeIDname(dsttp)));

	/* NULL pointers are easy */

	if      (ptr == 0)
		return  ptr;

	/* First try non-virtual base classes, then virtual bases */

	blst = (baseListPtr)((tpchPtr)srctp + srctp->tpClass.tpcBaseList);
	if      (locateBaseClass(blst, 0, dsttp, ptr))
		return  ptr;

	blst = (baseListPtr)((tpchPtr)srctp + srctp->tpClass.tpcVbasList);
	if      (locateBaseClass(blst, 1, dsttp, ptr))
		return  ptr;

	assert(!"Can't adjust class address (no base class entry found)");

	return  0;
}


///////////////////////////////////////////////////////////////////////////////
//
//      The following routines are used to crawl through the typeinfo tree.
//
//

static inline type_info *GetTypeInfo(tpid *tp)
{
        return (type_info *)__GetTypeInfo((void *)1, 0, tp);
}

static inline baseListPtr GetBaseList(tpid *tp)
{
        return (baseListPtr)((tpchPtr)tp + tp->tpClass.tpcBaseList);
}

static inline baseListPtr GetVBasList(tpid *tp)
{
        return (baseListPtr)((tpchPtr)tp + tp->tpClass.tpcVbasList);
}

type_info const *type_info::_first_base(type_info::_base_info &b) const
{
        type_info const *rc = NULL;
        if (!tpp || !(tpp->tpMask & TM_IS_CLASS))
                return NULL;

        if (tpp->tpClass.tpcFlags & CF_HAS_BASES)
        {
                baseListPtr bl = GetBaseList(tpp);
                if (bl->blType)
                        rc = b._type = GetTypeInfo(bl->blType);
                b._cookie = bl;
        }
        return rc;
}

type_info const *type_info::_next_base(type_info::_base_info &b) const
{
        type_info const *rc = NULL;
        baseListPtr bl = static_cast<baseListPtr>(b._cookie);
        ++bl;
        b._cookie = bl;
        if (bl->blType)
                rc = b._type = GetTypeInfo(bl->blType);
        return rc;
}

type_info const *type_info::_first_vbase(type_info::_vbase_info &b) const
{
        type_info const *rc = NULL;
        if (!tpp || !(tpp->tpMask & TM_IS_CLASS))
                return NULL;

        if (tpp->tpClass.tpcFlags & CF_HAS_VBASES)
        {
                baseListPtr bl = GetVBasList(tpp);
                b._cookie = bl;
                rc = GetTypeInfo(bl->blType);
        }
        return rc;
}

bool type_info::_vbase_info::_indirect()
{
        baseListPtr bl = static_cast<baseListPtr>(_cookie);
        return bl->blFlags & 8;
}
