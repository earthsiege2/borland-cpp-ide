
#ifndef _INTERNAL_MBSTATE_T
#define _INTERNAL_MBSTATE_T

#  define _STLP_USE_OWN_MBSTATE_T
#  define _MBSTATE_T

# ifdef _STLP_USE_OWN_MBSTATE_T

// to be compatible across different SUN platforms
#ifdef __sun
# define __stl_mbstate_t __mbstate_t
#endif

struct __stl_mbstate_t;

# ifdef __cplusplus
struct __stl_mbstate_t { 
  __stl_mbstate_t( long __st = 0 ) { _M_state[0] = __st ; }
  __stl_mbstate_t& operator=(const long __st) {
    _M_state[0] = __st;              
    return *this;
  } 
  __stl_mbstate_t(const __stl_mbstate_t& __x) {_M_state[0]= __x._M_state[0]; }         
  __stl_mbstate_t& operator=(const __stl_mbstate_t& __x) {
    _M_state[0]= __x._M_state[0];              
    return *this;
  }
# if defined (__sun)
#  ifdef _LP64
  long _M_state[4];
#  else
  int _M_state[6];
#  endif
# else       
  long _M_state[1];
# endif
};          

inline bool operator==(const __stl_mbstate_t& __x, const __stl_mbstate_t& __y) {
  return ( __x._M_state[0] == __y._M_state[0] );
}

inline bool operator!=(const __stl_mbstate_t& __x, const __stl_mbstate_t& __y) {
  return ( __x._M_state[0] == __y._M_state[0] );
}
# endif


_STLP_BEGIN_NAMESPACE

typedef __stl_mbstate_t mbstate_t;

_STLP_END_NAMESPACE

# endif /* _STLP_USE_OWN_MBSTATE_T */

#endif /* _INTERNAL_MBSTATE_T */
