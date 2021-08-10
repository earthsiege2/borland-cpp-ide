/********************************************************************
* DBPME.H
* Copyright (c) 1996 by Borland International
* All Rights Reserved
********************************************************************/

#if !defined(DBPME_H_)
#define DBPME_H_

#include <vdbt/bdto.h>
#include <vdbt/dbmisc.h>

#if ! defined( __FLAT__ ) && defined( _RTLDLL )
#  define _DBAWARECLASS HUGE
#else
#  define _DBAWARECLASS
#endif

//----------------------------------------------------------------------------
// Tamplates
//----------------------------------------------------------------------------
template < class T > struct _DBAWARECLASS TDBPropertyRo {
  virtual operator T() = 0;
};
//----------------------------------------------------------------------------
template < class T > struct _DBAWARECLASS TDBPropertyRw
                                 : public TDBPropertyRo< T > {
  virtual T& operator =( T& ) = 0;
};
//----------------------------------------------------------------------------
template < class T > struct _DBAWARECLASS TDBEvent {
  virtual operator T() = 0;
  virtual T operator =( T ) = 0;
};
//----------------------------------------------------------------------------
template < class T > struct _DBAWARECLASS TDBPropertyRox {
    TDBPropertyRox() : p( NULL ) {}
    virtual ~TDBPropertyRox() { if( p ) delete p; }
    virtual operator T*()   { return Get(); }
    virtual T* operator->() { return *this; }      // Calls operator T*()
    virtual T& operator *() { return *(T*)*this; } // Calls operator T*()
    virtual operator T&()   { return *(T*)*this; } // Calls operator T*()
    virtual T* Get() = 0;

  protected:
    T *p;
};
//----------------------------------------------------------------------------
template < class T > struct _DBAWARECLASS TDBPropertyRwx
                                 : public TDBPropertyRox< T > {
  public:
    virtual T* operator =( T *_p )
    {
      if( ! p )
      {
        // first time initialization
        if( (p = _p ? new T( *_p ) : new T()) == NULL )
          ThrowException( "Memory Allocation Failed in TDBPropertyRwx!" );
      }
      else if( _p )
        *p = *_p;
      else
        *p = T();

      return Set();
    }
    virtual T& operator =( T& _p )
    {
      *this = &_p;   // Calls operator=(T*)
      return *this;  // Calls operator T&()
    }
    virtual T* Set() = 0;
};
//----------------------------------------------------------------------------

#define DBPMECLASS( x )                                                       \
public:                                                                       \
typedef x ThisDBClss, * pThisDBClss;                                          \
typedef void ( x::*TNotifyEvent )( void );                                    \
typedef void ( x::*TDragEvent )( TVbxControl&, SHORT, SHORT );                \
typedef void ( x::*TDragOverEvent )( TVbxControl&, SHORT, SHORT, TDragState );\
typedef void ( x::*TKeyEvent )( SHORT*, TShiftState );                        \
typedef void ( x::*TKeyPressEvent )( SHORT );                                 \
typedef void ( x::*TMouseEvent )( TMouseButton, TShiftState, SHORT, SHORT );  \
typedef void ( x::*TMeasureItemEvent )( SHORT, SHORT* );                      \
typedef void ( x::*TDrawItemEvent )( SHORT, TRect, TOwnerDrawState );         \
typedef void ( x::*TNavClick )( TNavigateBtn )

#define DBOUTER( x ) (pThisDBClss(((char*)this) - int( &pThisDBClss(0)->x )))

//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
//  Property Macros
//----------------------------------------------------------------------------
// DB_PROP_RO()
// Simple type of readonly property.   Must define Get().
//----------------------------------------------------------------------------
#define DECLARE_DB_PROP_RO( type, name )               \
public:                                                \
  struct _DBAWARECLASS pr##name : TDBPropertyRo< type >\
  {                                                    \
    operator type();                                   \
  } name;                                              \
  friend struct pr##name
//----------------------------------------------------------------------------
// DB_PROP_RW()
// Simple type of read/write property.   Must define Get() and Set().
//----------------------------------------------------------------------------
#define DECLARE_DB_PROP_RW( type, name )               \
public:                                                \
  struct _DBAWARECLASS pr##name : TDBPropertyRw< type >\
  {                                                    \
    struct pr##name& operator=( struct pr##name& arg ) \
    {                                                  \
      *this = (type&)arg;                              \
      return *this;                                    \
    }                                                  \
    type& operator=( type& arg );                      \
    operator type();                                   \
  } name;                                              \
  friend struct pr##name
//----------------------------------------------------------------------------
// DB_PROP_RO0()
// Indexed (VB) type of readonly property.  Inline getter.
//----------------------------------------------------------------------------
#define DECLARE_DB_PROP_RO0( type, name, indx )        \
public:                                                \
  struct _DBAWARECLASS pr##name : TDBPropertyRo< type >\
  {                                                    \
    operator type()                                    \
    {                                                  \
      type v;                                          \
                                                       \
      if( ! DBOUTER( name )->GetProp( indx, v ) )      \
        ThrowException( "Getting " #name " Failed!" ); \
      return v;                                        \
    }                                                  \
  } name;                                              \
  friend struct pr##name
//----------------------------------------------------------------------------
// DB_PROP_RW0()
// Indexed (VB) type of read/write property.  Inline getter/setter.
//----------------------------------------------------------------------------
#define DECLARE_DB_PROP_RW0( type, name, indx )        \
public:                                                \
  struct _DBAWARECLASS pr##name : TDBPropertyRw< type >\
  {                                                    \
    struct pr##name& operator=( struct pr##name& arg ) \
    {                                                  \
      *this = (type&)arg;                              \
      return *this;                                    \
    }                                                  \
    type& operator=( type& arg )                       \
    {                                                  \
      if( ! DBOUTER( name )->SetProp( indx, arg ) )    \
        ThrowException( "Setting " #name " Failed!" ); \
      return arg;                                      \
    }                                                  \
    operator type()                                    \
    {                                                  \
      type v;                                          \
                                                       \
      if( ! DBOUTER( name )->GetProp( indx, v ) )      \
        ThrowException( "Getting " #name " Failed!" ); \
      return v;                                        \
    }                                                  \
  } name;                                              \
  friend struct pr##name
//----------------------------------------------------------------------------
// DB_PROP_RO1()
// Indexed (VB) type of read/write property.   This property shows as both
// the VB type or Delphi type.   Must define seperately the convertion routine
// from the VB type to Delphi type
//----------------------------------------------------------------------------
#define DECLARE_DB_PROP_RO1( type1, type2, name, indx ) \
public:                                                 \
  struct _DBAWARECLASS pr##name : TDBPropertyRo< type1 >\
                                , TDBPropertyRo< type2 >\
  {                                                     \
    operator type1()                                    \
    {                                                   \
      type1 v;                                          \
                                                        \
      if( ! DBOUTER( name )->GetProp( indx, v ) )       \
        ThrowException( "Getting " #name " Failed!" );  \
      return v;                                         \
    }                                                   \
    operator type2()                                    \
    {                                                   \
      return type2( type1( *this ) );                   \
    }                                                   \
  } name;                                               \
  friend struct pr##name
//----------------------------------------------------------------------------
// DB_PROP_RW1()
// Indexed (VB) type of read/write property.   This property shows as both
// the VB type or Delphi type.   Must define seperately the convertion routine
// from the VB type to Delphi type
//----------------------------------------------------------------------------
#define DECLARE_DB_PROP_RW1( type1, type2, name, indx )    \
public:                                                    \
  struct _DBAWARECLASS pr##name : TDBPropertyRw< type1 >   \
                                , TDBPropertyRw< type2 >   \
  {                                                        \
    struct pr##name& operator=( struct pr##name arg )      \
    {                                                      \
      *this = (type1&)arg;                                 \
      return *this;                                        \
    }                                                      \
    type1& operator=( type1& arg )                         \
    {                                                      \
      if( ! DBOUTER( name )->SetProp( indx, arg ) )        \
        ThrowException( "Setting " #name " Failed!" );     \
      return arg;                                          \
    }                                                      \
    operator type1()                                       \
    {                                                      \
      type1 v;                                             \
                                                           \
      if( ! DBOUTER( name )->GetProp( indx, v ) )          \
        ThrowException( "Getting " #name " Failed!" );     \
      return v;                                            \
    }                                                      \
    type2& operator=( type2& arg )                         \
    {                                                      \
      *this = (type1&)arg;                                 \
      return arg;                                          \
    }                                                      \
    operator type2()                                       \
    {                                                      \
      return type2( type1( *this ) );                      \
    }                                                      \
  } name;                                                  \
  friend struct pr##name
//----------------------------------------------------------------------------
// DB_PROP_RO2()
// Special Properties
//----------------------------------------------------------------------------
#define DECLARE_DB_PROP_RO2( type, name )                 \
  public:                                                 \
    struct _DBAWARECLASS pr##name : TDBPropertyRox< type >\
    {                                                     \
      type* Get();                                        \
    } name;                                               \
    friend struct pr##name
//----------------------------------------------------------------------------
// DB_PROP_RW2()
// Special Properties
//----------------------------------------------------------------------------
#define DECLARE_DB_PROP_RW2( type, name )                 \
  public:                                                 \
    struct _DBAWARECLASS pr##name : TDBPropertyRwx< type >\
    {                                                     \
      pr##name& operator=( pr##name& arg )                \
      {                                                   \
        *this = (type*)arg;                               \
        return *this;                                     \
      }                                                   \
      type* operator=( type* arg )                        \
      {                                                   \
        return TDBPropertyRwx<type>::operator=( arg );    \
      }                                                   \
      type& operator=( type& arg )                        \
      {                                                   \
        return TDBPropertyRwx<type>::operator=( arg );    \
      }                                                   \
      type* Get();                                        \
      type* Set();                                        \
    } name;                                               \
    friend struct pr##name
//----------------------------------------------------------------------------


//----------------------------------------------------------------------------
// Event handling macros
// DECLARE_DB_EVENT( name, params )
//----------------------------------------------------------------------------
#define DECLARE_DB_EVENT( name, type )                      \
protected:                                                  \
  type Get##name##Handler();                                \
  type Set##name##Handler( type );                          \
                                                            \
public:                                                     \
  struct _DBAWARECLASS ev##name : public TDBEvent< type > { \
    ev##name( type=NULL );                                  \
    operator type ();                                       \
    type operator=( type );                                 \
  } name;                                                   \
friend struct ev##name
//----------------------------------------------------------------------------
// DEFINE_DB_EVENT( cls, name, type, index )
//----------------------------------------------------------------------------
#define DEFINE_DB_EVENT( cls, name, type, index )           \
cls::type cls::Get##name##Handler()                         \
{                                                           \
  return (cls::type)__entries[ index ].Pmf;                 \
}                                                           \
cls::type cls::Set##name##Handler( cls::type NewHandler )   \
{                                                           \
  cls::type OldHandler = (cls::type)__entries[ index ].Pmf; \
  /* Assign a new handler */                                \
  (cls::type)__entries[ index ].Pmf = NewHandler;           \
                                                            \
  return OldHandler;  /* return the previous handler */     \
}                                                           \
cls::ev##name::ev##name( cls::type Handler )                \
{                                                           \
  *this = Handler;                                          \
}                                                           \
cls::ev##name::operator cls::type ()                        \
{                                                           \
  return DBOUTER( name )->Get##name##Handler();             \
}                                                           \
cls::type cls::ev##name::operator=( cls::type NewHandler )  \
{                                                           \
  return DBOUTER( name )->Set##name##Handler( NewHandler ); \
}
//----------------------------------------------------------------------------

#endif DBPME_H_
