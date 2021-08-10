#==========================================================================
#
#  makefile - makefile for examples
#
#==========================================================================
#
#  (c) Copyright 1994, 1995 Rogue Wave Software, Inc.
#  ALL RIGHTS RESERVED
#
#  The software and information contained herein are proprietary to, and
#  comprise valuable trade secrets of, Rogue Wave Software, Inc., which
#  intends to preserve as trade secrets such software and information.
#  This software is furnished pursuant to a written license agreement and
#  may be used, copied, transmitted, and stored only in accordance with
#  the terms of such license and with the inclusion of the above copyright
#  notice.  This software and information or any other copies thereof may
#  not be provided or otherwise made available to any other person.
#
#  Notwithstanding any other lease or license that may pertain to, or
#  accompany the delivery of, this computer software and information, the
#  rights of the Government regarding its use, reproduction and disclosure
#  are as set forth in Section 52.227-19 of the FARS Computer
#  Software-Restricted Rights clause.
#
#  Use, duplication, or disclosure by the Government is subject to
#  restrictions as set forth in subparagraph (c)(1)(ii) of the Rights in
#  Technical Data and Computer Software clause at DFARS 252.227-7013.
#  Contractor/Manufacturer is Rogue Wave Software, Inc.,
#  P.O. Box 2328, Corvallis, Oregon 97339.
#
#  This computer software and information is distributed with "restricted
#  rights."  Use, duplication or disclosure is subject to restrictions as
#  set forth in NASA FAR SUP 18-52.227-79 (April 1985) "Commercial
#  Computer Software-Restricted Rights (April 1985)."  If the Clause at
#  18-52.227-74 "Rights in Data General" is specified in the contract,
#  then the "Alternate III" clause applies.
#
#==========================================================================
#
#  Makefile for the Rogue Wave Standard Library package, using
#  Borland C++ with a Win32 target.
#
#  Note ONLY the Borland-supplied "make" command
#  should be used.
#
#==========================================================================

!include makeincl.inc

########################   Targets    #################################

ALLEXES =                                                                     \
        accum.exe     \
        adj_diff.exe  \
        advance.exe   \
        alg1.exe      \
        alg2.exe      \
        alg3.exe      \
        alg4.exe      \
        alg5.exe      \
        alg6.exe      \
        alg7.exe      \
        auto_ptr.exe  \
        b_search.exe  \
        binders.exe   \
        bitset.exe    \
        calc.exe      \
        codecvt.exe   \
        collate.exe   \
        complex.exe   \
        complx.exe    \
        concord.exe   \
        copyex.exe    \
        count.exe     \
        ctype.exe     \
        deque.exe     \
        distance.exe  \
        eqlrange.exe  \
        equal.exe     \
        except.exe    \
        exceptn.exe   \
        filebuf.exe   \
        fill.exe      \
        find.exe      \
        find_end.exe  \
        find_f_o.exe  \
        for_each.exe  \
        fstream.exe   \
        funct_ob.exe  \
        generate.exe  \
        graph.exe     \
        gslc_ary.exe  \
        gslice.exe    \
        hasfacet.exe  \
        heap_ops.exe  \
        icecream.exe  \
        ifstream.exe  \
        includes.exe  \
        indr_ary.exe  \
        inr_prod.exe  \
        ins_itr.exe   \
        io_iter.exe   \
        isalnum.exe   \
        istbufit.exe  \
        istngstr.exe  \
        istream1.exe  \
        istrstre.exe  \
        lex_comp.exe  \
        limits.exe    \
        list.exe      \
        locale.exe    \
        map.exe       \
        mask_ary.exe  \
        max.exe       \
        max_elem.exe  \
        memfunc.exe   \
        memfunrf.exe  \
        merge.exe     \
        mismatch.exe  \
        moneyget.exe  \
        moneyput.exe  \
        monpunct.exe  \
        multimap.exe  \
        multiset.exe  \
        mutex.exe     \
        negator.exe   \
        nthelem.exe   \
        numget.exe    \
        numpunct.exe  \
        numput.exe    \
        ostbufit.exe  \
        ostream1.exe  \
        ostream2.exe  \
        p_queue.exe   \
        partsort.exe  \
        partsum.exe   \
        permute.exe   \
        pnt2fnct.exe  \
        prtition.exe  \
        queue.exe     \
        radix.exe     \
        remove.exe    \
        replace.exe   \
        rev_itr.exe   \
        reverse.exe   \
        rndshufl.exe  \
        rotate.exe    \
        search.exe    \
        set_diff.exe  \
        set_intr.exe  \
        set_s_di.exe  \
        set_unin.exe  \
        setex.exe     \
        sieve.exe     \
        slc_ary.exe   \
        slice.exe     \
        sort.exe      \
        spell.exe     \
        stack.exe     \
        stngstre.exe  \
        stocks.exe    \
        string.exe    \
        strngbuf.exe  \
        strstrbf.exe  \
        strstrea.exe  \
        swap.exe      \
        tele.exe      \
        timeget.exe   \
        timeput.exe   \
        toupper.exe   \
        trnsform.exe  \
        ul_bound.exe  \
        unique.exe    \
        usefacet.exe  \
        valarray.exe  \
        vector.exe    \
        widwork.exe   \




all : rwstdmsg.dll messages.exe allobjs $(ALLEXES)
all : allobjs $(ALLEXES)

allobjs: $(ALLEXES:.exe=.obj)

clean:
   -@if exist *.obj del *.obj                 >nul
   -@if exist *.lib del *.lib                 >nul
   -@if exist rwstdmsg.res del rwstdmsg.res   >nul
   -@if exist *.exe del *.exe                 >nul
   -@if exist *.dll del *.dll                 >nul
   -@if exist *.tds del *.tds                 >nul
   -@if exist $(PCHROOT).* del $(PCHROOT).*   >nul

runall: all $(ALLEXES)
#
# Warning: there are quite a few exe's here that will run.  Also, several
#          of the examples require input from stdin.
#
    & $?

###########################  Explicit Rules #######################
rwstdmsg.obj: rwstdmsg.cpp
    $(CPP) $(CPPFLAGS) -tWD$(TARGSUF) -c {$? }

rwstdmsg.res: rwstdmsg.rc
    $(RC) $(RCFLAGS) $?

rwstdmsg.dll: rwstdmsg.obj rwstdmsg.res
    start $(LINKER) $(LINKFLAGS) $(LINKSTARTUP) rwstdmsg.obj ,$*,,$(LINKLIBS),,rwstdmsg.res

messages.exe: messages.obj rwstdmsg.dll
    $(CPP) $(CPPFLAGS) messages.obj rwstdmsg.lib


###########################  Implicit Rules #######################
.cpp.obj:
    $(CPP) $(CPPFLAGS) -c {$? }

.cpp.i:
    $(CPP32) $(CPPFLAGS) -c -Sr -Sd {$? }

.obj.exe:
    $(CPP) $(CPPFLAGS) $<

