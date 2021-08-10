#include "stlhdrs.h"
#pragma  hdrstop

/***************************************************************************
 *
 * valaray - Declarations for the Standard Library valarray
 *
 ***************************************************************************
 *
 * Copyright (c) 1994-1999 Rogue Wave Software, Inc.  All Rights Reserved.
 *
 * This computer software is owned by Rogue Wave Software, Inc. and is
 * protected by U.S. copyright laws and other laws and by international
 * treaties.  This computer software is furnished by Rogue Wave Software,
 * Inc. pursuant to a written license agreement and may be used, copied,
 * transmitted, and stored only in accordance with the terms of such
 * license and with the inclusion of the above copyright notice.  This
 * computer software or any other copies thereof may not be provided or
 * otherwise made available to any other person.
 *
 * U.S. Government Restricted Rights.  This computer software is provided
 * with Restricted Rights.  Use, duplication, or disclosure by the
 * Government is subject to restrictions as set forth in subparagraph (c)
 * (1) (ii) of The Rights in Technical Data and Computer Software clause
 * at DFARS 252.227-7013 or subparagraphs (c) (1) and (2) of the
 * Commercial Computer Software – Restricted Rights at 48 CFR 52.227-19,
 * as applicable.  Manufacturer is Rogue Wave Software, Inc., 5500
 * Flatiron Parkway, Boulder, Colorado 80301 USA.
 *
 **************************************************************************/

#include<valarray>
#include<rw/stddefs.h>

#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif
  // gslice non inline member functions

  size_t gslice::next_ind()
  {
    size_t ind;     

    if ( reset_ ) 
    { 
      reset_ = false;	  
      return start_;
    }   

    size_t tmp= length_.size();
	 
    while( tmp > 0 )
    {
      if( r_length_[tmp-1] == length_[tmp-1]-1 )
	tmp--;
      else
	break;		 
    }
     
    if ( tmp == 0 )
    {
      reset_ = true;
      for( ind=0; ind < r_length_.size(); ind++ )
	r_length_[ind]=0;
      return 0;
    }

    tmp--;

    r_length_[tmp]++;

    for( ind= tmp+1; ind< r_length_.size(); ind++ )
      r_length_[ind]=0;

    size_t value = start_;
    for( ind=0; ind< r_length_.size(); ind++ )
      value+= r_length_[ind] * stride_[ind];

    return value;
  }

  size_t gslice::ind_max() const
  {
    size_t value = start_;
    for(size_t ind=0; ind< length_.size(); ind++ )
      value+= (length_[ind]-1) * stride_[ind];

    return value;
  }

  size_t gslice::ind_numb() const
  {
    size_t value = 1;
    for(size_t ind=0; ind< length_.size(); ind++ )
      value*= length_[ind];

    return value;
  }
// Explicit Instantiation

#ifndef _RWSTD_NO_EXPLICIT_INSTANTIATION

  template class _RWSTDExportTemplate valarray<size_t>;
  template class _RWSTDExportTemplate valarray<int>;
  template class _RWSTDExportTemplate valarray<long>;

#ifndef _RWSTD_NO_NAMESPACE
#ifndef _RWSTD_NO_IMP_NAMESPACE
}
namespace __rwstd {
#endif
#endif

  template class _RWSTDExportTemplate _RW_array<size_t>;
  template class _RWSTDExportTemplate _RW_array<int>;
  template class _RWSTDExportTemplate _RW_array<long>;

#ifndef _RWSTD_NO_NAMESPACE
#ifndef _RWSTD_NO_IMP_NAMESPACE
}
namespace std {
#endif
#endif

#else

#ifndef _RWSTD_NO_INSTANTIATE

#pragma instantiate valarray<size_t>
#pragma instantiate valarray<int>
#pragma instantiate valarray<long>

#ifndef _RWSTD_NO_NAMESPACE
#ifndef _RWSTD_NO_IMP_NAMESPACE
}
namespace __rwstd {
#endif
#endif

#pragma instantiate _RW_array<size_t>
#pragma instantiate _RW_array<int>
#pragma instantiate _RW_array<long>

#ifndef _RWSTD_NO_NAMESPACE
#ifndef _RWSTD_NO_IMP_NAMESPACE
}
namespace std {
#endif
#endif

#endif  /* _RWSTD_NO_INSTANTIATE */

#endif /* _RWSTD_NO_EXPLICIT_INSTANTIATION */
#ifndef _RWSTD_NO_NAMESPACE
}
#endif

