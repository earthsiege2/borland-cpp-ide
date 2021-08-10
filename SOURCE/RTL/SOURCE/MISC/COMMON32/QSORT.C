/*-----------------------------------------------------------------------*
 * filename - qsort.c
 *
 * function(s)
 *        Exchange  - exchanges two objects
 *        qSortHelp - performs the quicker sort
 *        qsort     - sorts using the quick sort routine
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#include <stdlib.h>

typedef int  _USERENTRY comparF (const void *, const void *);

static  comparF    *Fcmp;
static  unsigned    qWidth;

/*-----------------------------------------------------------------------*

Name            Exchange - exchanges two objects

Usage           static  void  Exchange (void  *leftP, void *rightP);

Description     exchanges the qWidth byte wide objects pointed to
                by leftP and rightP.

Return value    Nothing

*------------------------------------------------------------------------*/
static  void  Exchange (void  *leftP, void *rightP)
{
        unsigned  i;
        char  c;
        char *lp = (char *)leftP;
        char *rp = (char *)rightP;

        for (i = 0; i < qWidth; i++ )
        {
                c = *rp;
                *rp++ = *lp;
                *lp++ = c;
        }
}

/*-----------------------------------------------------------------------*

Background

The Quicker Sort algorithm was first described by C.A.R.Hoare in the
Computer Journal, No. 5 (1962), pp.10..15, and in addition is frequently
described in computing literature, notably in D. Knuth's Sorting and
Searching.  The method used here includes a number of refinements:

- The median-of-three technique described by Singleton (Communications
  of the A.C.M., No 12 (1969) pp 185..187) is used, where the median
  operation is also the special case sort for 3 elements.  This slightly
  improves the average speed, especially when comparisons are slower
  than exchanges, but more importantly it prevents worst-case behavior
  on partly sorted files.  If a simplistic quicker-sort is run on a file
  which is only slightly disordered (a common need in some applications)
  then it is as slow as a bubble-sort.  The median technique prevents
  this.

  Another serious problem with the plain algorithm is that worst-case
  behavior causes very deep recursion (almost one level per table
  element !), so again it is best to use the median technique.

- The values of width and compar are copied to static storage and a help
  function with a minimum of parameters is used to reduce the recursion
  overheads.  Recursion is used both for simplicity and because there
  is no practical gain from conversion to loops: the extra housekeeping
  needed for loops needs registers for speed, but the 8086 family has not
  enough registers.  Juggling registers takes just as much time as calling
  subroutines.

*------------------------------------------------------------------------*/

/*
  Optimize pointer comparisons knowing segments are identical,
  except in HUGE model.
*/

#define _LT_(x,y)       (x < y)

/*-----------------------------------------------------------------------*

Name            qSortHelp - performs the quicker sort

Usage           static void  near pascal  qSortHelp (char *pivotP,
                                                     size_t nElem);

Description     performs the quicker sort on the nElem element array
                pointed to by pivotP.

Return value    Nothing

*------------------------------------------------------------------------*/

static void  qSortHelp (char *pivotP, size_t nElem)
{
    char     *leftP, *rightP, *pivotEnd, *pivotTemp, *leftTemp;
    unsigned  lNum;
    int       retval;


tailRecursion:
    if (nElem <= 2)
        {
        if (nElem == 2)
            {
            if (Fcmp (pivotP, rightP = qWidth + pivotP) > 0)
                Exchange (pivotP, rightP);
            }
        return;
        }

    rightP = (nElem - 1) * qWidth + pivotP;
    leftP  = (nElem >> 1) * qWidth + pivotP;

/*  sort the pivot, left, and right elements for "median of 3" */

    if (Fcmp (leftP, rightP) > 0)
        Exchange (leftP, rightP);
    if (Fcmp (leftP, pivotP) > 0)
        Exchange (leftP, pivotP);
    else if (Fcmp (pivotP, rightP) > 0)
        Exchange (pivotP, rightP);

    if (nElem == 3)
        {
        Exchange (pivotP, leftP);
        return;
        }

/*  now for the classic Hoare algorithm */

    leftP = pivotEnd = pivotP + qWidth;

    do
        {
        while ((retval = Fcmp(leftP, pivotP)) <= 0)
            {
            if (retval == 0)
                {
                Exchange(leftP, pivotEnd);
                pivotEnd += qWidth;
                }
            if (_LT_ (leftP, rightP))
                leftP += qWidth;
            else
                goto qBreak;
            }

        while (_LT_(leftP, rightP))
            {
            if ((retval = Fcmp(pivotP, rightP)) < 0)
                rightP -= qWidth;
            else
                {
                Exchange (leftP, rightP);
                if (retval != 0)
                    {
                    leftP += qWidth;
                    rightP -= qWidth;
                    }
                break;
                }
            }
        }   while (_LT_(leftP, rightP));

qBreak:

    if (Fcmp(leftP, pivotP) <= 0)
        leftP = leftP + qWidth;

    leftTemp = leftP - qWidth;
        
    pivotTemp = pivotP;
        
    while ((pivotTemp < pivotEnd) && (leftTemp >= pivotEnd))
        {
        Exchange(pivotTemp, leftTemp);
        pivotTemp += qWidth;
        leftTemp -= qWidth;
        }
        
    lNum = (leftP - pivotEnd) / qWidth;
    nElem = ((nElem * qWidth + pivotP) - leftP)/qWidth;

    /* Sort smaller partition first to reduce stack usage */
    if (nElem < lNum)
        {
        qSortHelp (leftP, nElem);
        nElem = lNum;
        }
    else
        {
        qSortHelp (pivotP, lNum);
        pivotP = leftP;
        }
                
    goto tailRecursion;
}   

/*-----------------------------------------------------------------------*

Name            qsort - sorts using the quick sort routine

Usage           void qsort(void *base, int nelem, int width, int (*fcmp)());

Prototype in    stdlib.h

Description     qsort is an implementation of the "median of three"
                variant of the quicksort algorithm. qsort sorts the entries
                in a table into order by repeatedly calling the user-defined
                comparison function pointed to by fcmp.

                base points to the base (0th element) of the table to be sorted.

                nelem is the number of entries in the table.

                width is the size of each entry in the table, in bytes.

                *fcmp, the comparison function, accepts two arguments, elem1
                and elem2, each a pointer to an entry in the table. The
                comparison function compares each of the pointed-to items
                (*elem1 and *elem2), and returns an integer based on the result
                of the comparison.

                        If the items            fcmp returns

                        *elem1 <  *elem2         an integer < 0
                        *elem1 == *elem2         0
                        *elem1 >  *elem2         an integer > 0

                In the comparison, the less than symbol (<) means that the left
                element should appear before the right element in the final,
                sorted sequence. Similarly, the greater than (>) symbol
                means that the left element should appear after the right
                element in the final, sorted sequence.

Return value    qsort does not return a value.

*------------------------------------------------------------------------*/

void _RTLENTRYF _EXPFUNC qsort(void *baseP, size_t nElem, size_t width,
                          comparF *compar)

/*
  The table *baseP containing a count of nElem records each of fixed width
  is to be converted from unknown order into ascending order, using the
  ordering provided by the comparison function compar.

  The comparison function compar (leftP, rightP) must return less than, equal,
  or greater than zero, according to whether it decides that (record) *leftP
  is less than, equal, or greater than (record) *rightP.

  The internal contents of the records are never inspected by qsort.  It
  depends entirely upon compar to decide the format and value of the records.
  This allows the content of the records to be of any fixed length type -
  formatted text, floating point, pointer to variable length record, etc. -
  so long as each record is understood by compar.

  The quicker sort algorithm will in general change the relative ordering
  of records which may compare as equal.  For example, if it is attempted
  to use two passes of quick sort on a order file, first by date and then
  by customer name, the result will be that the second sort pass randomly
  jumbles the dates.  It is necessary to design the compar() function to
  consider all the keys and sort in one pass.

*/

{
    if ((qWidth = width) == 0)  
        return;

    Fcmp = compar;

    qSortHelp (baseP, nElem);
}
