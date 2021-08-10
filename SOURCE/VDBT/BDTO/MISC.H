//-----------------------------------------------------------------------------
// Visual Database Tools
// Copyright (c) 1996 by Borland International, All Rights Reserved
//
// misc.h
// Miscellaneous defines
//-----------------------------------------------------------------------------

#if !defined(MISC_H)
#define MISC_H

inline VARIANT_BOOL MakeVariantBool( bool b )
{
	return b ? ((VARIANT_BOOL) -1) : ((VARIANT_BOOL) 0);
}

inline bool MakeBool( VARIANT_BOOL v )
{
	return v ? true : false;
}

//-----------------------------------------------------------------------------

#define BDTOOUTER( name, ptr )                                                \
  (pThisBDTOClass(((char*)ptr) - int( &pThisBDTOClass(0)->name )))

#define ARRAYOUTER( name, ptr )                                               \
  (pThisArrayClass(((char*)ptr) - int( &pThisArrayClass(0)->name )))

// macros for read only properties which return a simple type

#define DEFINE_BDTO_PROP_RO( cls, type, name )                                \
  cls::prop##name::operator type()                                            \
  {                                                                           \
    type v;                                                                   \
    BDTOOUTER( name, this )->Get##name( v );                                  \
    return v;                                                                 \
  }
													

// macros for read write properties which return a simple type

#define DEFINE_BDTO_PROP_RW( cls, type, name )                                \
  cls::prop##name::operator type()                                            \
  {                                                                           \
    type v;                                                                   \
    BDTOOUTER( name, this )->Get##name( v );                                  \
    return v;                                                                 \
  }                                                                           \
  type cls::prop##name::operator=( type v )                                   \
  {                                                                           \
    BDTOOUTER( name, this )->Set##name( v );                                  \
    return v;                                                                 \
  }                                                                           \
  cls::prop##name& cls::prop##name::operator=( const cls::prop##name& other ) \
  {                                                                           \
    type v;                                                                   \
    BDTOOUTER( name, &other )->Get##name( v );                                \
    BDTOOUTER( name, this )->Set##name( v );                                  \
    return *this;                                                             \
  }


// macros for read only properties which return an object

#define DEFINE_BDTO_OBJECTPROP_RO( cls, type, name )                          \
  cls::prop##name::prop##name()                                               \
  {                                                                           \
    p##name = NULL;                                                           \
  }                                                                           \
  cls::prop##name::~prop##name()                                              \
  {                                                                           \
    if (p##name)                                                              \
      delete p##name;                                                         \
  }                                                                           \
  cls::prop##name::operator type*()                                           \
  {                                                                           \
    if (! p##name)                                                            \
      p##name = new type;                                                     \
    if (p##name)                                                              \
      BDTOOUTER( name, this )->Get##name( *p##name );                         \
    return p##name;                                                           \
  }                                                                           \
  cls::prop##name::operator const type&()                                     \
  {                                                                           \
    return *(cls::prop##name::operator type*());                              \
  }                                                                           \
  type* cls::prop##name::operator->()                                         \
  {                                                                           \
    return cls::prop##name::operator type*();                                 \
  }                                                                           \
  const type& cls::prop##name::operator*()                                    \
  {                                                                           \
    return *(cls::prop##name::operator type*());                              \
  }

#define DEFINE_BDTO_OBJECTPROP_RO_FAST( cls, type, pittype, name )            \
  cls::prop##name::prop##name()                                               \
  {                                                                           \
    p##name = NULL;                                                           \
  }                                                                           \
  cls::prop##name::~prop##name()                                              \
  {                                                                           \
    if (p##name)                                                              \
      delete p##name;                                                         \
  }                                                                           \
  cls::prop##name::operator type*()                                           \
  {                                                                           \
    if (! p##name)                                                            \
      p##name = new type( pittype(0) );                                       \
    if (p##name)                                                              \
      BDTOOUTER( name, this )->Get##name( *p##name );                         \
    return p##name;                                                           \
  }                                                                           \
  cls::prop##name::operator const type&()                                     \
  {                                                                           \
    return *(cls::prop##name::operator type*());                              \
  }                                                                           \
  type* cls::prop##name::operator->()                                         \
  {                                                                           \
    return cls::prop##name::operator type*();                                 \
  }                                                                           \
  const type& cls::prop##name::operator*()                                    \
  {                                                                           \
    return *(cls::prop##name::operator type*());                              \
  }


// macros for read write properties which return an object

#define DEFINE_BDTO_OBJECTPROP_RW( cls, type, name )                          \
  cls::prop##name::prop##name()                                               \
  {                                                                           \
    p##name = NULL;                                                           \
  }                                                                           \
  cls::prop##name::~prop##name()                                              \
  {                                                                           \
    if (p##name)                                                              \
      delete p##name;                                                         \
  }                                                                           \
  cls::prop##name::operator type*()                                           \
  {                                                                           \
    if (! p##name)                                                            \
      p##name = new type;                                                     \
    if (p##name)                                                              \
      BDTOOUTER( name, this )->Get##name( *p##name );                         \
    return p##name;                                                           \
  }                                                                           \
  cls::prop##name::operator const type&()                                     \
  {                                                                           \
    return *(cls::prop##name::operator type*());                              \
  }                                                                           \
  type* cls::prop##name::operator->()                                         \
  {                                                                           \
    return cls::prop##name::operator type*();                                 \
  }                                                                           \
  const type& cls::prop##name::operator*()                                    \
  {                                                                           \
    return *(cls::prop##name::operator type*());                              \
  }                                                                           \
  type* cls::prop##name::operator=( type* v )                                 \
  {                                                                           \
    if (v)                                                                    \
      BDTOOUTER( name, this )->Set##name( *v );                               \
    return v;                                                                 \
  }                                                                           \
  type& cls::prop##name::operator=( type& v )                                 \
  {                                                                           \
    BDTOOUTER( name, this )->Set##name( v );                                  \
    return v;                                                                 \
  }                                                                           \
  cls::prop##name& cls::prop##name::operator=( const cls::prop##name& other ) \
  {                                                                           \
    type v;                                                                   \
    BDTOOUTER( name, &other )->Get##name( v );                                \
    BDTOOUTER( name, this )->Set##name( v );                                  \
    return *this;                                                             \
  }

#define DEFINE_BDTO_OBJECTPROP_RW_FAST( cls, type, pittype, name )            \
  cls::prop##name::prop##name()                                               \
  {                                                                           \
    p##name = NULL;                                                           \
  }                                                                           \
  cls::prop##name::~prop##name()                                              \
  {                                                                           \
    if (p##name)                                                              \
      delete p##name;                                                         \
  }                                                                           \
  cls::prop##name::operator type*()                                           \
  {                                                                           \
    if (! p##name)                                                            \
      p##name = new type( pittype(0) );                                       \
    if (p##name)                                                              \
      BDTOOUTER( name, this )->Get##name( *p##name );                         \
    return p##name;                                                           \
  }                                                                           \
  cls::prop##name::operator const type&()                                     \
  {                                                                           \
    return *(cls::prop##name::operator type*());                              \
  }                                                                           \
  type* cls::prop##name::operator->()                                         \
  {                                                                           \
    return cls::prop##name::operator type*();                                 \
  }                                                                           \
  const type& cls::prop##name::operator*()                                    \
  {                                                                           \
    return *(cls::prop##name::operator type*());                              \
  }                                                                           \
  type* cls::prop##name::operator=( type* v )                                 \
  {                                                                           \
    if (v)                                                                    \
      BDTOOUTER( name, this )->Set##name( *v );                               \
    return v;                                                                 \
  }                                                                           \
  type& cls::prop##name::operator=( type& v )                                 \
  {                                                                           \
    BDTOOUTER( name, this )->Set##name( v );                                  \
    return v;                                                                 \
  }                                                                           \
  cls::prop##name& cls::prop##name::operator=( const cls::prop##name& other ) \
  {                                                                           \
    type v( pittype(0) );                                                     \
    BDTOOUTER( name, &other )->Get##name( v );                                \
    BDTOOUTER( name, this )->Set##name( v );                                  \
    return *this;                                                             \
  }


// macros for read write array properties which return a simple type

#define DEFINE_BDTO_ARRAYPROP_RW( cls, type, name, itype )                    \
  cls::prop##name::setter##name& cls::prop##name::operator[]( itype i )       \
  {                                                                           \
    name.index = i;                                                           \
    return name;                                                              \
  }                                                                           \
  cls::prop##name::setter##name::operator type()                              \
  {                                                                           \
    type v;                                                                   \
    ARRAYOUTER( name, this )->CallGet##name( index, v );                      \
    return v;                                                                 \
  }                                                                           \
  type cls::prop##name::setter##name::operator=( type v )                     \
  {                                                                           \
    ARRAYOUTER( name, this )->CallSet##name( index, v );                      \
    return v;                                                                 \
  }                                                                           \
  cls::prop##name::setter##name& cls::prop##name::setter##name::operator=( const cls::prop##name::setter##name& other )\
  {                                                                           \
    type v;                                                                   \
    ARRAYOUTER( name, &other )->CallGet##name( other.index, v );              \
    ARRAYOUTER( name, this )->CallSet##name( index, v );                      \
    return *this;                                                             \
  }                                                                           \
  void cls::prop##name::CallGet##name( itype i, type& v )                     \
  {                                                                           \
    BDTOOUTER( name, this )->Get##name( i, v );                               \
  }                                                                           \
  void cls::prop##name::CallSet##name( itype i, type v )                      \
  {                                                                           \
    BDTOOUTER( name, this )->Set##name( i, v );                               \
  }


// macros for read only array properties which return an object

#define DEFINE_BDTO_ARRAYOBJECTPROP_RO( cls, type, name, itype )              \
  cls::prop##name::prop##name()                                               \
  {                                                                           \
    p##name = NULL;                                                           \
  }                                                                           \
  cls::prop##name::~prop##name()                                              \
  {                                                                           \
    if (p##name)                                                              \
      delete p##name;                                                         \
  }                                                                           \
  type* cls::prop##name::operator[]( itype i )                                \
  {                                                                           \
    if (! p##name)                                                            \
      p##name = new type;                                                     \
    if (p##name)                                                              \
      BDTOOUTER( name, this )->Get##name( i, *p##name );                      \
    return p##name;                                                           \
  }

#define DEFINE_BDTO_ARRAYOBJECTPROP_RO_FAST( cls, type, pittype, name, itype )\
  cls::prop##name::prop##name()                                               \
  {                                                                           \
    p##name = NULL;                                                           \
  }                                                                           \
  cls::prop##name::~prop##name()                                              \
  {                                                                           \
    if (p##name)                                                              \
      delete p##name;                                                         \
  }                                                                           \
  type* cls::prop##name::operator[]( itype i )                                \
  {                                                                           \
    if (! p##name)                                                            \
      p##name = new type( pittype(0) );                                       \
    if (p##name)                                                              \
      BDTOOUTER( name, this )->Get##name( i, *p##name );                      \
    return p##name;                                                           \
  }


// macros for read write array properties which return an object

#define DEFINE_BDTO_ARRAYOBJECTPROP_RW( cls, type, name, itype )              \
  cls::prop##name::prop##name()                                               \
  {                                                                           \
    p##name = NULL;                                                           \
  }                                                                           \
  cls::prop##name::~prop##name()                                              \
  {                                                                           \
    if (p##name)                                                              \
      delete p##name;                                                         \
  }                                                                           \
  cls::prop##name::setter##name& cls::prop##name::operator[]( itype i )       \
  {                                                                           \
    name.index = i;                                                           \
    return name;                                                              \
  }                                                                           \
  cls::prop##name::setter##name::operator type*()                             \
  {                                                                           \
    return ARRAYOUTER( name, this )->CallGet##name( index );                  \
  }                                                                           \
  cls::prop##name::setter##name::operator const type&()                       \
  {                                                                           \
    return *(cls::prop##name::setter##name::operator type*());                \
  }                                                                           \
  type* cls::prop##name::setter##name::operator->()                           \
  {                                                                           \
    return cls::prop##name::setter##name::operator type*();                   \
  }                                                                           \
  const type& cls::prop##name::setter##name::operator*()                      \
  {                                                                           \
    return *(cls::prop##name::setter##name::operator type*());                \
  }                                                                           \
  type* cls::prop##name::setter##name::operator=( type* v )                   \
  {                                                                           \
    if (v)                                                                    \
      ARRAYOUTER( name, this )->CallSet##name( index, *v );                   \
    return v;                                                                 \
  }                                                                           \
  type& cls::prop##name::setter##name::operator=( type& v )                   \
  {                                                                           \
    ARRAYOUTER( name, this )->CallSet##name( index, v );                      \
    return v;                                                                 \
  }                                                                           \
  cls::prop##name::setter##name& cls::prop##name::setter##name::operator=( const cls::prop##name::setter##name& other )\
  {                                                                           \
    type* v;                                                                  \
    v = ARRAYOUTER( name, &other )->CallGet##name( other.index );             \
    ARRAYOUTER( name, this )->CallSet##name( index, *v );                     \
    return *this;                                                             \
  }                                                                           \
  type* cls::prop##name::CallGet##name( itype i )                             \
  {                                                                           \
    if (! p##name)                                                            \
      p##name = new type;                                                     \
    if (p##name)                                                              \
      BDTOOUTER( name, this )->Get##name( i, *p##name );                      \
    return p##name;                                                           \
  }                                                                           \
  void cls::prop##name::CallSet##name( itype i, type& v )                     \
  {                                                                           \
    BDTOOUTER( name, this )->Set##name( i, v );                               \
  }

#define DEFINE_BDTO_ARRAYOBJECTPROP_RW_FAST( cls, type, pittype, name, itype )\
  cls::prop##name::prop##name()                                               \
  {                                                                           \
    p##name = NULL;                                                           \
  }                                                                           \
  cls::prop##name::~prop##name()                                              \
  {                                                                           \
    if (p##name)                                                              \
      delete p##name;                                                         \
  }                                                                           \
  cls::prop##name::setter##name& cls::prop##name::operator[]( itype i )       \
  {                                                                           \
    name.index = i;                                                           \
    return name;                                                              \
  }                                                                           \
  cls::prop##name::setter##name::operator type*()                             \
  {                                                                           \
    return ARRAYOUTER( name, this )->CallGet##name( index );                  \
  }                                                                           \
  cls::prop##name::setter##name::operator const type&()                       \
  {                                                                           \
    return *(cls::prop##name::setter##name::operator type*());                \
  }                                                                           \
  type* cls::prop##name::setter##name::operator->()                           \
  {                                                                           \
    return cls::prop##name::setter##name::operator type*();                   \
  }                                                                           \
  const type& cls::prop##name::setter##name::operator*()                      \
  {                                                                           \
    return *(cls::prop##name::setter##name::operator type*());                \
  }                                                                           \
  type* cls::prop##name::setter##name::operator=( type* v )                   \
  {                                                                           \
    if (v)                                                                    \
      ARRAYOUTER( name, this )->CallSet##name( index, *v );                   \
    return v;                                                                 \
  }                                                                           \
  type& cls::prop##name::setter##name::operator=( type& v )                   \
  {                                                                           \
    ARRAYOUTER( name, this )->CallSet##name( index, v );                      \
    return v;                                                                 \
  }                                                                           \
  cls::prop##name::setter##name& cls::prop##name::setter##name::operator=( const cls::prop##name::setter##name& other )\
  {                                                                           \
    type* v;                                                                  \
    v = ARRAYOUTER( name, &other )->CallGet##name( other.index );             \
    ARRAYOUTER( name, this )->CallSet##name( index, *v );                     \
    return *this;                                                             \
  }                                                                           \
  type* cls::prop##name::CallGet##name( itype i )                             \
  {                                                                           \
    if (! p##name)                                                            \
      p##name = new type( pittype(0) );                                       \
    if (p##name)                                                              \
      BDTOOUTER( name, this )->Get##name( i, *p##name );                      \
    return p##name;                                                           \
  }                                                                           \
  void cls::prop##name::CallSet##name( itype i, type& v )                     \
  {                                                                           \
    BDTOOUTER( name, this )->Set##name( i, v );                               \
  }


// macros for methods which return an object

#define DEFINE_BDTO_OBJECTMETHOD1( cls, rettype, pittype, name, atype )       \
  cls::obj##name::obj##name()                                                 \
  {                                                                           \
    p##name = NULL;                                                           \
  }                                                                           \
  cls::obj##name::~obj##name()                                                \
  {                                                                           \
    if (p##name)                                                              \
      delete p##name;                                                         \
  }                                                                           \
  rettype* cls::obj##name::operator()( atype a )                              \
  {                                                                           \
    if (! p##name)                                                            \
      p##name = new rettype( pittype(0) );                                    \
    if (p##name)                                                              \
      BDTOOUTER( name, this )->Call##name( a, *p##name );                     \
    return p##name;                                                           \
  }

#define DEFINE_BDTO_OBJECTMETHOD3( cls, rettype, pittype, name, atype, btype, ctype )\
  cls::obj##name::obj##name()                                                 \
  {                                                                           \
    p##name = NULL;                                                           \
  }                                                                           \
  cls::obj##name::~obj##name()                                                \
  {                                                                           \
    if (p##name)                                                              \
      delete p##name;                                                         \
  }                                                                           \
  rettype* cls::obj##name::operator()( atype a, btype b, ctype c )            \
  {                                                                           \
    if (! p##name)                                                            \
      p##name = new rettype( pittype(0) );                                    \
    if (p##name)                                                              \
      BDTOOUTER( name, this )->Call##name( a, b, c, *p##name );               \
    return p##name;                                                           \
  }

  
#endif // MISC_H
