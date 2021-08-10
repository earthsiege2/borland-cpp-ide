#ifndef __STD_STDEXCEPT

/***************************************************************************
 *
 * stdexcept - declarations for the Standard Library standard exception class
 *
 * $Id: stdexcept,v 1.21 1995/09/29 23:52:59 smithey Exp $
 *
 ***************************************************************************
 *
 * (c) Copyright 1994, 1995 Rogue Wave Software, Inc.
 * ALL RIGHTS RESERVED
 *
 * The software and information contained herein are proprietary to, and
 * comprise valuable trade secrets of, Rogue Wave Software, Inc., which
 * intends to preserve as trade secrets such software and information.
 * This software is furnished pursuant to a written license agreement and
 * may be used, copied, transmitted, and stored only in accordance with
 * the terms of such license and with the inclusion of the above copyright
 * notice.  This software and information or any other copies thereof may
 * not be provided or otherwise made available to any other person.
 *
 * Notwithstanding any other lease or license that may pertain to, or
 * accompany the delivery of, this computer software and information, the
 * rights of the Government regarding its use, reproduction and disclosure
 * are as set forth in Section 52.227-19 of the FARS Computer
 * Software-Restricted Rights clause.
 * 
 * Use, duplication, or disclosure by the Government is subject to
 * restrictions as set forth in subparagraph (c)(1)(ii) of the Rights in
 * Technical Data and Computer Software clause at DFARS 252.227-7013.
 * Contractor/Manufacturer is Rogue Wave Software, Inc.,
 * P.O. Box 2328, Corvallis, Oregon 97339.
 *
 * This computer software and information is distributed with "restricted
 * rights."  Use, duplication or disclosure is subject to restrictions as
 * set forth in NASA FAR SUP 18-52.227-79 (April 1985) "Commercial
 * Computer Software-Restricted Rights (April 1985)."  If the Clause at
 * 18-52.227-74 "Rights in Data General" is specified in the contract,
 * then the "Alternate III" clause applies.
 *
 **************************************************************************/

#include <stdcomp.h>

#include <string>

//
// Due to the circular dependency of
// exception -> string -> exception, we must add an extra
// level of indirection here.  We really test to see if the exception
// hierarchy has been completely seen or not.  We're not particular
// interested in whether or not the file has only been opened.
//
#ifndef __RWSTD_EXCEPTION_SEEN

#ifndef RWSTD_NO_NAMESPACE 
namespace std {
#endif

extern char RWSTDExport __rw_stdexcept_NoNamedException[];

class RWSTDExport exception
{ 
  public:
    exception () RWSTD_THROW_SPEC_NULL {;}
    exception (const exception& rhs) RWSTD_THROW_SPEC_NULL { str = rhs.str; }
    exception& operator= (const exception& rhs) RWSTD_THROW_SPEC_NULL
    {
        if (!(this == &rhs))
            str = rhs.str;
        return *this;
    }
    virtual ~exception ()  RWSTD_THROW_SPEC_NULL {;}
    virtual const char * what () const RWSTD_THROW_SPEC_NULL
    {
        return str.size() == 0 ? __rw_stdexcept_NoNamedException : str.data();
    }
  protected:
    exception (const string& what_arg) : str(what_arg) {;}
  private:
    string str;
};

class RWSTDExport logic_error : public exception
{
  public:
    logic_error (const string& what_arg) : exception(what_arg) {;}
};

class RWSTDExport domain_error : public logic_error
{
  public:
    domain_error (const string& what_arg): logic_error(what_arg) {;}
};

class RWSTDExport invalid_argument : public logic_error
{
  public:
    invalid_argument (const string& what_arg): logic_error(what_arg) {;}
};

class RWSTDExport length_error : public logic_error
{
  public:
    length_error (const string& what_arg): logic_error(what_arg) {;}
};

class RWSTDExport out_of_range : public logic_error
{
  public:
    out_of_range (const string& what_arg): logic_error(what_arg) {;}
};

class RWSTDExport runtime_error : public exception
{
  public:
    runtime_error (const string& what_arg): exception(what_arg) {;}
};

class RWSTDExport range_error : public runtime_error
{
  public:
    range_error (const string& what_arg): runtime_error(what_arg) {;}
};

class RWSTDExport overflow_error : public runtime_error
{
  public:
    overflow_error (const string& what_arg): runtime_error(what_arg) {;}
};

#define __RWSTD_EXCEPTION_SEEN

#ifndef RWSTD_NO_NAMESPACE 
} 
#endif

//
// Yes, the exception hierarchy has been seen!
//
#endif /*__RWSTD_EXCEPTION_SEEN*/

//
// Yes, the complete file has been processed!
//
#define __STD_STDEXCEPT

#endif /*__STD_STDEXCEPT*/
