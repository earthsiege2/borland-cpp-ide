/*------------------------------------------------------------------------*/
/*                                                                        */
/*  BINIMP.CPP                                                            */
/*                                                                        */
/*  Copyright (c) 1993, 1994 Borland International                        */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( CLASSLIB_BINIMP_H )
#include <classlib/binimp.h>
#endif

TBinarySearchTreeBase::TBinarySearchTreeBase() :
    Root(0),
    ItemsInContainer(0)
{
}

int TBinarySearchTreeBase::InsertNode( BinNode *node )
{
    BinNode *Current = Root;
    BinNode *Parent = 0;
    while( Current )
        {
        Parent = Current;
        Current = LessThan( node, Current ) ? Current->Left : Current->Right;
        }
    if( Parent == 0 )
        Root = node;
    else
        {
        if( LessThan( node, Parent ) )
            Parent->Left = node;
        else
            Parent->Right = node;
        }
    ItemsInContainer++;
    return 1;
}

int TBinarySearchTreeBase::RemoveNode( BinNode *node, int del )
{
    BinNode *Current = Root;
    BinNode *Parent = 0;
    while( Current )
        {
        if( EqualTo( node, Current ) )
            return RemNode( Current, Parent, del );
        else
            {
            Parent = Current;
            Current = LessThan( node, Current ) ? Current->Left :
                                                  Current->Right;
            }
        }
    return 0;
}

TBinarySearchTreeBase::BinNode *TBinarySearchTreeBase::FindNode( BinNode *node )
{
    BinNode *Current = Root;
    while( Current )
        {
        if( EqualTo( node, Current ) )
            return Current;
        else
            Current = LessThan( node, Current ) ? Current->Left :
                                                  Current->Right;
        }
    return 0;
}

int TBinarySearchTreeBase::RemNode( BinNode *node, BinNode *parent, int del )
{
    // See R. Sedgewick, "Algorithms, 2nd edition",
    //   Addison-Wesley 1988, p.210.
    BinNode *Original = node;
    if( Original->Right == 0 )
        node = node->Left;
    else if( Original->Right->Left )
        {
        BinNode *Current = Original->Right;
        while( Current->Left->Left )
            Current = Current->Left;
        node = Current->Left;
        Current->Left = node->Right;
        node->Left = Original->Left;
        node->Right = Original->Right;
        }
    else
        {
        node = node->Right;
        node->Left = Original->Left;
        }
    if( parent == 0 )
        Root = node;
    else if( LessThan( Original, parent ) )
        parent->Left = node;
    else
        parent->Right = node;

    DeleteNode( Original, del );
    ItemsInContainer--;
    return 1;
}

class TBinaryTreeKiller : public TBinaryTreeInternalIteratorBase
{

public:

    TBinaryTreeKiller( TBinarySearchTreeBase& tree, int del ) :
        TBinaryTreeInternalIteratorBase( tree, TBinarySearchTreeBase::PostOrder ),
        Del(del) {}

private:

    virtual void Apply( TBinarySearchTreeBase::BinNode _FAR *node,
                        TBinarySearchTreeBase::BinNode _FAR *parent );

    int Del;

    TBinaryTreeKiller( const TBinaryTreeKiller& );
    const TBinaryTreeKiller& operator = ( const TBinaryTreeKiller& );

};

void TBinaryTreeKiller::Apply( TBinarySearchTreeBase::BinNode _FAR *node,
                           TBinarySearchTreeBase::BinNode _FAR *parent )
{
    Tree().RemNode( node, parent, Del );
}

void TBinarySearchTreeBase::Flush( int del )
{
    if( Root != 0 )
        TBinaryTreeKiller( *this, del ).Iterate();
}

void TBinaryTreeInternalIteratorBase::Iterate()
{
    TBinarySearchTreeBase::BinNode _FAR *Current = Node;
    TBinarySearchTreeBase::BinNode _FAR *Prev = 0;
    TBinarySearchTreeBase::BinNode _FAR *Next = 0;
step2:
    if( Order == TBinarySearchTreeBase::PreOrder )
        Apply( Current, 0 );
    Next = Current->Left;
    if( Next != 0 )
        {
        Current->Left = Prev;
        Prev = Current;
        Current = Next;
        goto step2;
        }
step4:
    if( Order == TBinarySearchTreeBase::InOrder )
        Apply( Current, 0 );
    Next = Current->Right;
    if( Next != 0 )
        {
        Current->Right = Prev;
        Prev = Current;
        Current = Next;
        goto step2;
        }
step6:
    if( Prev == 0 )
        {
        if( Order == TBinarySearchTreeBase::PostOrder )
            Apply( Current, 0 );
        return;
        }
    if( Tree().LessThan( Current, Prev ) )
        {
        TBinarySearchTreeBase::BinNode _FAR *Temp = Current;
        Next = Prev->Left;
        Prev->Left = Current;
        Current = Prev;
        Prev = Next;
        if( Order == TBinarySearchTreeBase::PostOrder )
            Apply( Temp, Current );
        goto step4;
        }
    else
        {
        TBinarySearchTreeBase::BinNode _FAR *Temp = Current;
        Next = Prev->Right;
        Prev->Right = Current;
        Current = Prev;
        Prev = Next;
        if( Order == TBinarySearchTreeBase::PostOrder )
            Apply( Temp, Current );
        goto step6;
        }
}

TBinaryTreeExternalIteratorBase::TBinaryTreeExternalIteratorBase( TBinarySearchTreeBase& tree, TBinarySearchTreeBase::IteratorOrder order ) :
    Stack( new TStackAsList<TBinarySearchTreeBase::BinNode _BIDSFAR *> ),
    Tree(&tree),
    Current( tree.Root ),
    Order( order )
{
    Restart();
}

TBinaryTreeExternalIteratorBase::~TBinaryTreeExternalIteratorBase()
{
    delete Stack;
}

void TBinaryTreeExternalIteratorBase::Restart()
{
    Stack->Flush();
    Current = Tree->Root;
    LeftVisited = RightVisited = 0;
    Processed = 0;
}

TBinarySearchTreeBase::BinNode *TBinaryTreeExternalIteratorBase::Next()
{
    if( Current == 0 )
        return 0;
    for(;;)
        {
        if( Order == TBinarySearchTreeBase::PreOrder && !Processed )
            {
            Processed = 1;
            return Current;
            }

        if( Current->Left != 0 && !LeftVisited )
            {
            Stack->Push( Current );
            Current = Current->Left;
            LeftVisited = RightVisited = 0;
            Processed = 0;
            }
        else if( Current->Right != 0 && !RightVisited )
            {
            TBinarySearchTreeBase::BinNode *Res = 0;
            if( Order == TBinarySearchTreeBase::InOrder )
                Res = Current;
            Stack->Push( Current );
            Current = Current->Right;
            LeftVisited = RightVisited = 0;
            Processed = 0;
            if( Res != 0 )
                return Res;
            }
        else
            {
            if( Stack->IsEmpty() )
                {
                if( Processed == 0 )
                    {
                    Processed = 1;
                    }
                else
                    {
                    Current = 0;
                    }
                return Current;
                }
            else
                {
                TBinarySearchTreeBase::BinNode *Res;
                switch( Order )
                    {
                    case TBinarySearchTreeBase::PreOrder:
                        // This node has already been
                        // processed, so we have further to go.
                        Res = 0;

                        // This node's parent has
                        // already been processed
                        Processed = 1;

                        break;

                    case TBinarySearchTreeBase::InOrder:
                        if( IsInOrder() )
                            {
                            // This node needs to be processed.
                            Res = Current;
                            }
                        else
                            {
                            // Node has already been processed.
                            Res = 0;
                            }
                        // If we're the right-hand child, our parent
                        // has already been processed.
                        Processed = Stack->Top()->Right == Current;

                        break;

                    case TBinarySearchTreeBase::PostOrder:
                        // This node needs to be processed.
                        Res = Current;

                        // This node's parent has not been processed.
                        Processed = 0;

                        break;
                    }

                LeftVisited = 1;
                RightVisited = Stack->Top()->Right == Current;
                Current = Stack->Pop();
                if( Res != 0 )
                    return Res;
                }
            }
        }
}

