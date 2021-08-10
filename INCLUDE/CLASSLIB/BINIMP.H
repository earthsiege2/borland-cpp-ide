/*------------------------------------------------------------------------*/
/*                                                                        */
/*  BINIMP.H                                                              */
/*                                                                        */
/*  Copyright (c) 1993 Borland International                              */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( __CLASSLIB_BINIMP_H )
#define __CLASSLIB_BINIMP_H

#if !defined( __CLASSLIB_DEFS_H )
#include "classlib\defs.h"
#endif  // __CLASSLIB_DEFS_H

#if !defined( __CLASSLIB_VOIDP_H )
#include "classlib\voidp.h"
#endif  // __CLASSLIB_VOIDP_H

#if !defined( __CLASSLIB_STACKS_H )
#include "classlib\stacks.h"
#endif  // __CLASSLIB_STACKS_H

#pragma option -Vo-
#if defined( BI_CLASSLIB_NO_po )
#pragma option -po-
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class TBinarySearchTreeBase                                           */
/*                                                                        */
/*  Base class for binary search tree templates.                          */
/*                                                                        */
/*------------------------------------------------------------------------*/

class _BIDSCLASS TBinarySearchTreeBase
{

    friend class _BIDSCLASS TBinaryTreeInternalIteratorBase;
    friend class _BIDSCLASS TBinaryTreeExternalIteratorBase;
    friend class _BIDSCLASS TBinaryTreeKiller;

public:

    enum IteratorOrder
        {
        PreOrder,
        InOrder,
        PostOrder
        };

    class _BIDSCLASS BinNode
        {
        public:
            BinNode() : Left(0), Right(0) {}
            BinNode _BIDSFAR *Left;
            BinNode _BIDSFAR *Right;
        };

    void Flush( int del = 0 );

    unsigned GetItemsInContainer() const
        {
        return ItemsInContainer;
        }

    int IsEmpty() const
        {
        return Root == 0;
        }

protected:

    TBinarySearchTreeBase();

    int InsertNode( BinNode _BIDSFAR *node );
    int RemoveNode( BinNode _BIDSFAR *node, int del );
    BinNode _BIDSFAR *FindNode( BinNode _BIDSFAR *node );

    int RemNode( BinNode _BIDSFAR *node, BinNode _BIDSFAR *parent, int del );

    virtual int EqualTo( BinNode _BIDSFAR *n1, BinNode _BIDSFAR *n2 ) = 0;
    virtual int LessThan( BinNode _BIDSFAR *n1, BinNode _BIDSFAR *n2 ) = 0;
    virtual void DeleteNode( BinNode _BIDSFAR *node, int del ) = 0;

    BinNode _BIDSFAR *Root;

private:

    unsigned ItemsInContainer;

    TBinarySearchTreeBase( const TBinarySearchTreeBase _BIDSFAR & );
    const TBinarySearchTreeBase _BIDSFAR &
        operator = ( const TBinarySearchTreeBase _BIDSFAR & );

};

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class TBinaryTreeInternalIteratorBase                                 */
/*  class TBinaryTreeExternalIteratorBase                                 */
/*                                                                        */
/*  Base classes for binary search tree iterator templates.               */
/*                                                                        */
/*------------------------------------------------------------------------*/

class _BIDSCLASS TBinaryTreeInternalIteratorBase
{

public:

    TBinaryTreeInternalIteratorBase( TBinarySearchTreeBase _BIDSFAR & tree,
        TBinarySearchTreeBase::IteratorOrder order ) :
        _tree(tree),
        Node(tree.Root),
        Order(order)
        {
        }


    void Iterate();

protected:

    TBinarySearchTreeBase _BIDSFAR &Tree()
        {
        return _tree;
        }

private:

    virtual void Apply( TBinarySearchTreeBase::BinNode _BIDSFAR *Node,
                        TBinarySearchTreeBase::BinNode _BIDSFAR *Parent ) = 0;

    TBinarySearchTreeBase _BIDSFAR &_tree;
    TBinarySearchTreeBase::BinNode _BIDSFAR *Node;
    TBinarySearchTreeBase::IteratorOrder Order;

    TBinaryTreeInternalIteratorBase( const TBinaryTreeInternalIteratorBase _BIDSFAR & );
    const TBinaryTreeInternalIteratorBase _BIDSFAR &
        operator = ( const TBinaryTreeInternalIteratorBase _BIDSFAR & );

};

class _BIDSCLASS TBinaryTreeExternalIteratorBase
{

public:

    void Restart();

protected:

    TBinaryTreeExternalIteratorBase( TBinarySearchTreeBase _BIDSFAR & tree,
        TBinarySearchTreeBase::IteratorOrder order = TBinarySearchTreeBase::InOrder );

    TBinarySearchTreeBase::BinNode _BIDSFAR *GetCurrent() const
        {
        return Current;
        }

    TBinarySearchTreeBase::BinNode _BIDSFAR *Next();

private:

    TStackAsList<TBinarySearchTreeBase::BinNode _BIDSFAR *> Stack;
    TBinarySearchTreeBase _BIDSFAR *Tree;
    TBinarySearchTreeBase::BinNode _BIDSFAR *Current;
    TBinarySearchTreeBase::IteratorOrder Order;
    int LeftVisited;
    int RightVisited;
    int Processed;

    int IsInOrder() const;

    TBinaryTreeExternalIteratorBase( const TBinaryTreeExternalIteratorBase _BIDSFAR & );
    const TBinaryTreeExternalIteratorBase _BIDSFAR &
        operator = ( const TBinaryTreeExternalIteratorBase _BIDSFAR & );

};

inline int TBinaryTreeExternalIteratorBase::IsInOrder() const
{
    return (Current->Left == 0 || LeftVisited != 0) &&
           (Current->Right == 0 || RightVisited == 0);
}

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TBinaryNodeImp                               */
/*                                                                        */
/*  Node for use with binary trees                                        */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class _BIDSCLASS TBinaryNodeImp :
    public TBinarySearchTreeBase::BinNode
{

public:

    TBinaryNodeImp( const T& t ) : Data(t) {}
    T Data;
}

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TBinarySearchTreeImp                         */
/*  template <class T> class TBinaryTreeInternalIterator                  */
/*  template <class T> class TBinarySearchTreeIteratorImp                 */
/*                                                                        */
/*  Standard unbalanced binary tree and iterators                         */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class _BIDSCLASS TBinarySearchTreeImp :
    public TBinarySearchTreeBase
{

    typedef TBinarySearchTreeBase Parent;

public:

    typedef void (_BIDSFAR *IterFunc)(T _BIDSFAR&, void _BIDSFAR*);

    ~TBinarySearchTreeImp()
        {
        Flush();
        }

    int Add( const T& t )
        {
        return Parent::InsertNode( new TBinaryNodeImp<T>(t) );
        }

    int Detach( const T& t )
        {
        return Parent::RemoveNode( &TBinaryNodeImp<T>(t), 0 );
        }

    T _BIDSFAR * Find( const T& t ) const
        {
        TBinaryNodeImp<T> _BIDSFAR *res =
            Promote(Parent::FindNode( &TBinaryNodeImp<T>(t) ));
        return res == 0 ? 0 : &Promote(res)->Data;
        }

    void ForEach( IterFunc iter,
                  void _BIDSFAR * args,
                  IteratorOrder order = InOrder );

    void Flush()
        {
        Parent::Flush();
        }

    Parent::GetItemsInContainer;
    Parent::IsEmpty;

protected:

    virtual int EqualTo( BinNode _BIDSFAR *n1, BinNode _BIDSFAR *n2 )
        {
        return Promote(n1)->Data == Promote(n2)->Data;
        }

    virtual int LessThan( BinNode _BIDSFAR *n1, BinNode _BIDSFAR *n2 )
        {
        return Promote(n1)->Data < Promote(n2)->Data;
        }

    virtual void DeleteNode( BinNode _BIDSFAR *node, int )
        {
        delete Promote(node);
        }

private:

    static TBinaryNodeImp<T> _BIDSFAR _BIDSFAR *Promote( BinNode _BIDSFAR *node )
        {
        return STATIC_CAST(TBinaryNodeImp<T>_BIDSFAR *,node);
        }

    static const TBinaryNodeImp<T> _BIDSFAR *Promote( const BinNode _BIDSFAR *node )
        {
        return STATIC_CAST(const TBinaryNodeImp<T>_BIDSFAR *,node);
        }

};

template <class T> class _BIDSCLASS TBinaryTreeInternalIterator :
    public TBinaryTreeInternalIteratorBase
{

public:

    typedef void (_BIDSFAR *IterFunc)(T _BIDSFAR&, void _BIDSFAR*);

    TBinaryTreeInternalIterator(
                        TBinarySearchTreeBase& tree,
                        IterFunc iter,
                        void _BIDSFAR * args,
                        TBinarySearchTreeBase::IteratorOrder order );

private:

    virtual void Apply( TBinarySearchTreeBase::BinNode _BIDSFAR *Node,
                        TBinarySearchTreeBase::BinNode _BIDSFAR * );

    IterFunc Iter;
    void _BIDSFAR *Args;

};

template <class T>
TBinaryTreeInternalIterator<T>::TBinaryTreeInternalIterator(
                    TBinarySearchTreeBase _BIDSFAR & tree,
                    IterFunc iter,
                    void _BIDSFAR *args,
                    TBinarySearchTreeBase::IteratorOrder order ) :
    TBinaryTreeInternalIteratorBase( tree, order ),
    Iter(iter),
    Args(args)
{
}

template <class T>
void TBinaryTreeInternalIterator<T>::Apply( TBinarySearchTreeBase::BinNode *Node,
                                            TBinarySearchTreeBase::BinNode _BIDSFAR * )
{
    Iter( STATIC_CAST(TBinaryNodeImp<T>*,Node)->Data, Args );
}

template <class T>
void TBinarySearchTreeImp<T>::ForEach( IterFunc iter,
                                       void _BIDSFAR * args,
                                       TBinarySearchTreeBase::IteratorOrder order = TBinarySearchTreeBase::InOrder )
{
    if( Root != 0 )
        TBinaryTreeInternalIterator<T>( *this, iter, args, order ).Iterate();
}

template <class T> class _BIDSCLASS TBinarySearchTreeIteratorImp :
    private TBinaryTreeExternalIteratorBase
{

public:

    TBinarySearchTreeIteratorImp( TBinarySearchTreeImp<T>& tree,
        TBinarySearchTreeBase::IteratorOrder order = TBinarySearchTreeBase::InOrder ) :
        TBinaryTreeExternalIteratorBase( tree, order ),
        CurNode(STATIC_CAST(TBinaryNodeImp<T>_BIDSFAR *,Next()))
        {
        }

    operator int() const
        {
        return CurNode != 0;
        }

    const T& Current() const
        {
        PRECONDITION( CurNode != 0 );
        return CurNode->Data;
        }

    const T& operator ++ ( int )
        {
        PRECONDITION( CurNode != 0 );
        const T& t = Current();
        CurNode = STATIC_CAST(TBinaryNodeImp<T>_BIDSFAR *,Next());
        return t;
        }

    const T& operator ++ ()
        {
        PRECONDITION( CurNode != 0 );
        CurNode = STATIC_CAST(TBinaryNodeImp<T>_BIDSFAR *,Next());
        return Current();
        }

    void Restart()
        {
        TBinaryTreeExternalIteratorBase::Restart();
        CurNode = STATIC_CAST(TBinaryNodeImp<T>_BIDSFAR *,Next());
        }

private:

    TBinaryNodeImp<T>_BIDSFAR * CurNode;

};

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TIBinarySearchTreeImp                        */
/*  template <class T> class TIBinarySearchTreeIteratorImp                */
/*                                                                        */
/*  Standard indirect unbalanced binary tree and iterators                */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class _BIDSCLASS TIBinarySearchTreeIteratorImp;

template <class T> class _BIDSCLASS TIBinarySearchTreeImp :
    private TBinarySearchTreeImp<TVoidPointer>
{

public:

    typedef void (_BIDSFAR *IterFunc)(T _BIDSFAR&, void _BIDSFAR*);

    typedef TBinarySearchTreeImp<TVoidPointer> Parent;
    friend class _BIDSCLASS TIBinarySearchTreeIteratorImp<T>;

    int Add( T _BIDSFAR * t )
        {
        return Parent::Add( t );
        }
        
    int Detach( T _BIDSFAR *t, int del = 0 )
        {
        return Parent::RemoveNode( &TBinaryNodeImp<TVoidPointer>(t), del );
        }

    void Flush( int del = 0 )
        {
        TBinarySearchTreeBase::Flush(del);
        }

    T _BIDSFAR * Find( T _BIDSFAR * t ) const
        {
        TVoidPointer *res = Parent::Find(t);
        return res == 0 ? 0 :
               STATIC_CAST(T _BIDSFAR *,STATIC_CAST(void _BIDSFAR *,*res));
        }

    void ForEach( IterFunc iter, void _BIDSFAR * args,
                  IteratorOrder order = InOrder )
{
    if( Root != 0 )
        TIBinaryTreeInternalIterator<T>( *this, iter, args, order ).Iterate();
}


    Parent::GetItemsInContainer;
    Parent::IsEmpty;

protected:

    virtual int EqualTo( BinNode _BIDSFAR *n1, BinNode _BIDSFAR *n2 )
        {
        return *GetData(n1) == *GetData(n2);
        }

    virtual int LessThan( BinNode _BIDSFAR *n1, BinNode _BIDSFAR *n2 )
        {
        return *GetData(n1) < *GetData(n2);
        }

    virtual void DeleteNode( BinNode _BIDSFAR *node, int del )
        {
        if( del )
            delete GetData(node);
        delete Promote(node);
        }

private:

    static TBinaryNodeImp<TVoidPointer> _BIDSFAR *Promote( BinNode _BIDSFAR *node )
        {
        return STATIC_CAST(TBinaryNodeImp<TVoidPointer> _BIDSFAR *,node);
        }

    static const TBinaryNodeImp<TVoidPointer> _BIDSFAR *Promote( const BinNode _BIDSFAR *node )
        {
        return STATIC_CAST(const TBinaryNodeImp<TVoidPointer> _BIDSFAR *,node);
        }

    static T _BIDSFAR *GetData( BinNode _BIDSFAR *node )
        {
        return STATIC_CAST(T _BIDSFAR *,STATIC_CAST(void _BIDSFAR *,Promote(node)->Data));
        }

};

template <class T> class _BIDSCLASS TIBinaryTreeInternalIterator :
    public TBinaryTreeInternalIteratorBase
{

public:

    typedef void (_BIDSFAR *IterFunc)(T _BIDSFAR&, void _BIDSFAR*);

    TIBinaryTreeInternalIterator( TBinarySearchTreeBase& tree,
                        IterFunc iter,
                        void _BIDSFAR * args,
                        TBinarySearchTreeBase::IteratorOrder order ) :
        TBinaryTreeInternalIteratorBase( tree, order ),
        Iter(iter),
        Args(args)
        {
        }


private:

    virtual void Apply( TBinarySearchTreeBase::BinNode _BIDSFAR *Node,
                        TBinarySearchTreeBase::BinNode _BIDSFAR * );

    IterFunc Iter;
    void _BIDSFAR *Args;

};

template <class T>
void TIBinaryTreeInternalIterator<T>::Apply( TBinarySearchTreeBase::BinNode _BIDSFAR *Node, TBinarySearchTreeBase::BinNode _BIDSFAR * )
{
    Iter( *(T _BIDSFAR *)(void _BIDSFAR *)(STATIC_CAST(TBinaryNodeImp<TVoidPointer>*,Node)->Data), Args );
}

template <class T> class _BIDSCLASS TIBinarySearchTreeIteratorImp :
    private TBinarySearchTreeIteratorImp<TVoidPointer>
{

    typedef TBinarySearchTreeIteratorImp<TVoidPointer> Parent;

public:

    TIBinarySearchTreeIteratorImp( TIBinarySearchTreeImp<T>& tree,
        TBinarySearchTreeBase::IteratorOrder order = TBinarySearchTreeBase::InOrder ) :
        TBinarySearchTreeIteratorImp<TVoidPointer>(tree,order)
        {
        }

    Parent::operator int;

    T _BIDSFAR *Current() const
        {
        return (T _BIDSFAR *)(void _BIDSFAR *)(Parent::Current());
        }

    T _BIDSFAR *operator ++ ( int i )
        {
        return (T _BIDSFAR *)(void _BIDSFAR *)(Parent::operator++(i));
        }

    T _BIDSFAR *operator ++ ()
        {
        return (T _BIDSFAR *)(void _BIDSFAR *)(Parent::operator++());
        }

    Parent::Restart;

};

#if defined( BI_CLASSLIB_NO_po )
#pragma option -po.
#endif

#pragma option -Vo.

#endif  // __CLASSLIB_BINIMP_H


