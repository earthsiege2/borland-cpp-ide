/*-----------------------------------------------------------------------*
 * filename - allstl.cpp
 *
 *   This file includes all the STL / IOStream / Locale C++ headers
 *   such that the generation of templates is optimal.
 *
 *-----------------------------------------------------------------------*/

/* $Copyright: 1998$ */
/* $Revision:   9.3  $        */
#pragma option push -vi- // turn off inline-ing

#include "stlhdrs.h"
#pragma hdrstop

#pragma option push -w-tai  // turn off some template warnings

#include "allstl.txt" // contains the template instantiations that the compiler
                      // spit out with the help of the -Jgi switch.


// Special stuff John doesn't want to fix now.
namespace __rwstd {

struct open_cat_data {
  nl_catd catd;
  std::locale loc;

  open_cat_data (): catd((nl_catd)-1), loc(std::locale::classic()) { }
};
}
template __rwstd::locale_vector<__rwstd::open_cat_data>::~locale_vector();
template __rwstd::locale_vector<__rwstd::open_cat_data>::iterator __rwstd::locale_vector<__rwstd::open_cat_data>::resize(unsigned int, __rwstd::open_cat_data);

// Generate code for basic_string ctor that takes two string::iterator's
template _RWSTDExportTemplate std::basic_string<char,std::char_traits<char>,std::allocator<char> >::basic_string(char *,char *,const std::allocator<char> &);
template _RWSTDExportTemplate std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> >::basic_string(wchar_t *,wchar_t *,const std::allocator<wchar_t> &);


#pragma option pop
#pragma option pop
