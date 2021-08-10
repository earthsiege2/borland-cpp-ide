/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1993, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $ */

    //
    // An instance of the following struct is embedded in the RTL of an
    // .EXE or .DLL for the purposes of communicating, with a debugger,
    // run-time exceptions.
    //
    // This structure can be found by locating "__DebuggerHookData" in
    // the resident names table, which contains its address.
    //

#ifdef	DIABLO

struct DebuggerData
{
        //
        // The debugger can scan memory for the following magic numbers,
        // and then grab the address of the hook function.  These also
	// serve as version numbers.
        //
	
	unsigned long	magic1;
	unsigned long	zero;
	unsigned long	magic2;

        //
        // The debugger sets a breakpoint at the code this points to, thus
        // gaining control over the child when stuff happens.
        //
	
	void * p_hook_fcn;

        //
        // The following member is modified by a debugger so as to
        // tell the run time that it is running under the control of
	// a debugger so it can inform the debugger of C++ exception
        // related events.
        //
	
	unsigned long debugger_watching;

	//
	// The following members are the "parameters" to the hook
	// function.  The debugger reads them to determine which kind
	// of C++ exception event happened.
	//

        //
        // EventKind describes what kind of C++ exception event has
        // ocurred.  The values have the following meaning:
        //
	
        //
	// EventNull :
	//
	//    Null operation, nothing to do
	//

	
	//
	// Throw, catch and destructor events:
	//
	// The following events are generated when certains exception
	// related events occur in the RTL:
	//
	//		
	// EventThrow :
	//
	//    A throw HAS ocurred. Addr points to the instruction which would
	//    have been executed if it hadn't happened.  Name points to the
	//    name of the exception thrown.  Cookie contains the cookie for
	//    this exception.  Msg may contain a pointer to a message
	//    associated with this throw (Pascal will do this). Usually this
	//    event accompanies events describing
	//    the change of the exception stack, which should occur before
	//    EventThrow is generated.
	//
	//
	// EventCatch :
	//
	//    A Catch is ABOUT to happen.  Addr points to the first instruction
	//    of the catch.  Cookie contains the cookie for this exception.
	//
	// EventDestructor :
	//
	//    A destructor is ABOUT to be called because of stack unwinding.
	//    Addr points to the first instruction of the destructor.
	//


	//
	// The following are specific to C++, describing when the termineted,
	// or unexpected functions are called.
	//
	//
	// EventUnexpected :
	//
	//    The unexpected function is about to be called.  Addr points to
	//    its address.
	//
	// EventTerminated :
	//
	//    The terminated function is about to be called.  Addr points to
	//    its address.
	//


	//
	// Pending exception stack events:
	//
	//      EventListLast
        //      EventListMore
        //      EventListEmpty
	//
	// These events describe how RTL-maintained stack of
	// pending exceptions looks.  Every time this stack is changed,
	// the RTL notifies the debugger via these events.  The
	// debugger assumes that upon startup, the list is empty, thus
	// the RTL need not notifiy the debugger of this at start up.
	// Every time the list changes, the entire list is re-described
	// to the debugger.  There are three significant ways to describe
        // the new list:
	//
	//   1) If the list has become empty, a single event of kind
	//      EventListEmpty is generated.
	//
	//   2) If the list contains a single element, a single event
	//      of kind EventListLast is generated.
	//
	//   3) If the list contains more than 1 elements N, then N - 1
	//      events of kind EventListMore is generated, followed by
	//      a single event of kind EventListLast.  The first event
	//      described the top of the stack (the most recent exception
	//      pending).
	//
	// For EventListLast and EventListMore, the following members
	// contain information about the element in the list:
	//
	//    name : contains the name of the exception being thrown/raised
	//
	//  cookie : contains an opaque handle representing the element in
	//           the list.  This should remain constant for elements in
        //           the stack which are unchanged between stack changes.
	//
	//    addr : contains a pointer to the object being thrown/raised.
	//           This should not be confused with the cookie, which is
	//           usually a pointer to the RTL's internal data structure
	//           representing the element on it's stack.
	//
	//

	
        enum EventKind { EventNull, EventThrow, EventCatch, EventDestructor,
	                 EventUnexpected, EventTerminated,
	                 EventExcept, EventFinally,
	                 EventFilter,
	                 EventListLast, EventListMore, EventListEmpty,
			 EventRawExceptionStart, EventRawExceptionFinish };
	
	EventKind kind;
	
	unsigned long	addr;
	void *		objectAddr;
	unsigned long	cookie;

	    //
	    // Strings are not neccesarily null terminated.
	    //
	
	unsigned long	name_len;
	char *		name;

	unsigned long	msg_len;
	char *		msg;
	
	    //
	    // The following is used for "raw" exceptions only
	    //
	
	unsigned long	exception_num; // non C++ exceptions only

	void *		reserved[16];
};

#endif

#ifdef	PRONTODEBUGGER
enum	XXdebuggerNotification
{
	XXDNdtor	   = 0,
	XXDNthrow	   = 1,
	XXDNrawException   = 2,
	XXDNcatch	   = 3,
	XXDNterminated	   = 4,
	XXDNunexpected	   = 5,
	XXDNcatchTerminate = 6,
};
#endif

