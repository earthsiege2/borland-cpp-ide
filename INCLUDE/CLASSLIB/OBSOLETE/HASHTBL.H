/*------------------------------------------------------------------------*/
/*                                                                        */
/*  HASHTBL.H                                                             */
/*                                                                        */
/*  Copyright Borland International 1991, 1993                            */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( __HASHTBL_H )
#define __HASHTBL_H

#define BI_OLDNAMES

#if !defined( __RESOURCE_H )
#include "classlib\Resource.h"
#endif  // __RESOURCE_H

#if !defined( __CLSTYPES_H )
#include "classlib\obsolete\ClsTypes.h"
#endif  // __CLSTYPES_H

#if !defined( __CLSDEFS_H )
#include "classlib\obsolete\ClsDefs.h"
#endif  // __CLSDEFS_H

#if !defined( __COLLECT_H )
#include "classlib\obsolete\Collect.h"
#endif  // __COLLECT_H

#if !defined( __LIST_H )
#include "classlib\obsolete\List.h"
#endif  // __LIST_H

#if !defined( __VECTIMP_H )
#include "classlib\VectImp.h"
#endif  // __VECTIMP_H

#pragma option -Vo-
#if defined( __BCOPT__ ) && !defined( _ALLOW_po )
#pragma option -po-
#endif

_CLASSDEF(ContainerIterator)
_CLASSDEF(HashTable)
_CLASSDEF(HashTableIterator)

class _CLASSTYPE HashTable : public Collection
{

public:

    friend class HashTableIterator;

    HashTable( sizeType = DEFAULT_HASH_TABLE_SIZE );
    virtual ~HashTable() { flush(); }

    virtual void add( Object _FAR & );
    virtual void detach( Object _FAR &, DeleteType = NoDelete );
    virtual void flush( DeleteType = DefDelete );

    virtual int isEmpty() const
        {
        return itemsInContainer == 0;
        }

    virtual countType getItemsInContainer() const
        {
        return itemsInContainer;
        }

    virtual Object _FAR & findMember( Object _FAR & ) const;

    virtual ContainerIterator& initIterator() const;

    virtual classType isA() const
        {
        return hashTableClass;
        }

    virtual char _FAR *nameOf() const
        {
        return "HashTable";
        }

private:

    hashValueType getHashValue( Object _FAR & ) const;
    sizeType size;
    BI_IVectorImp<Object> table;

    unsigned itemsInContainer;

    DeleteType delItem( DeleteType dt )
        {
        return delObj(dt) ? Delete : NoDelete;
        }

};

inline sizeType HashTable::getHashValue( Object _FAR & ofObject ) const
{
    return ofObject.hashValue() % size;
}

class _CLASSTYPE HashTableIterator : public ContainerIterator
{

public:

    HashTableIterator( const HashTable _FAR & );
    ~HashTableIterator();

    virtual operator int();
    virtual Object _FAR & current();
    virtual Object _FAR & operator ++ ( int );
    virtual Object _FAR & operator ++ ();
    virtual void restart();

private:

    BI_IVectorIteratorImp<Object> _FAR *arrayIterator;
    ContainerIterator _FAR *listIterator;
    const HashTable _FAR & beingIterated;

    void scan();
};

#if defined( __BCOPT__ ) && !defined( _ALLOW_po )
#pragma option -po.
#endif
#pragma option -Vo.

#endif  // __HASHTBL_H

