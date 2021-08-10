/*-----------------------------------------------------------------------*
 * filename - setnew.cpp
 * C++ new
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1990, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.4  $        */

#include <stddef>
#include <stdlib>
#include <new>
//#include <string>
#include <exception>

using namespace std;

new_handler _new_handler;

#if !defined(NOXX)
std::bad_alloc __bad_alloc;

static void default_new_handler() { throw __bad_alloc; }

static void init_new_handler(void)
{
    set_new_handler(default_new_handler);
}
#pragma startup init_new_handler 0 /* Initializes the default new handler */

#endif
