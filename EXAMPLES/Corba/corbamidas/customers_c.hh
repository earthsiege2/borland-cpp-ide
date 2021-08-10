/*
 * Copyright 1999-2002 Borland Corporation, Inc.
 *
 * GENERATED CODE --- DO NOT EDIT
 * 
 */

#ifndef __Customers_idl___client
#define __Customers_idl___client
#include "vpre.h"

#ifndef _corba_h_
# include "corba.h"
#endif   // _corba_h_


class  CBuilder {
  public:
  #ifndef CBuilder_Customers_var_
  #define CBuilder_Customers_var_

  class  Customers;

  typedef Customers* Customers_ptr;
  typedef Customers_ptr CustomersRef;
  friend VISistream& operator>>(VISistream&, Customers_ptr&);
  friend VISostream& operator<<(VISostream&, const Customers_ptr);
  class  Customers_out;

  class  Customers_var : public CORBA::_var {
  friend class Customers_out;
   private:
    Customers_ptr _ptr;

   public:
    Customers_var();
    Customers_var(Customers_ptr);
    Customers_var(const Customers_var &);
    virtual ~Customers_var();

    static Customers_ptr _duplicate(Customers_ptr);
    static void _release(Customers_ptr);

    Customers_var& operator=(const Customers_var& _var) {
      _release(_ptr);
      _ptr = _duplicate(_var._ptr);
      return *this;
    }
    Customers_var& operator=(Customers_ptr);

    operator Customers*() const { return _ptr; }
    Customers* operator->() const { return _ptr; }

    Customers_ptr in() const { return _ptr; }
    Customers_ptr& inout() { return _ptr; }
    Customers_ptr& out();
    Customers_ptr _retn();

    friend VISostream& operator<<(VISostream&, const Customers_var&);
    friend VISistream& operator>>(VISistream&, Customers_var&);

    friend Istream& operator>>(Istream&, Customers_var&);
    friend Ostream& operator<<(Ostream&, const Customers_var&);
  };
  class  Customers_out {
   private:
    Customers_ptr& _ptr;
    static Customers* _nil() { return (Customers*)NULL; }

    void operator=(const Customers_out&);
    void operator=(const Customers_var&);
     public:
    Customers_out(const Customers_out& _o) : _ptr(_o._ptr) {}
    Customers_out(Customers_ptr& _p) : _ptr(_p) {
      _ptr = _nil();
    }
    Customers_out(Customers_var& _v) : _ptr(_v._ptr) {
      _v = _nil();
    }
    Customers_out& operator=(Customers* _p) {
      _ptr = _p;
      return *this;
    }
    operator Customers_ptr&() { return _ptr; }
    Customers_ptr& ptr() { return _ptr; }
    Customers* operator->() { return _ptr; }
  };

  #endif // CBuilder_Customers_var_


  // idl interface: CBuilder::Customers
  class  Customers : public virtual CORBA_Object {
   private:
    static const CORBA::TypeInfo _class_info;
    void operator=(const Customers&) {}

    protected:
    Customers() {}
    Customers(const Customers&) {}

   public:
    virtual ~Customers() {}
    class  CustomerException : public CORBA_UserException {
     public:

      #if defined(MSVCNEWDLL_BUG)
        void *operator new(size_t ts);
        void *operator new(size_t ts, char*, int) {return operator new(ts);}
        void operator delete(void *p);
      #endif // MSVCNEWDLL_BUG

      CustomerException() {}
      CustomerException( const char* _s ) {
             s = CORBA::string_dup(_s);

      }
      virtual ~CustomerException() {}

      CORBA::String_var s;
      static CORBA::Exception *_factory() { return new CustomerException(); }
      virtual const CORBA_Exception::Description& _desc() const;
      static CustomerException* _downcast(CORBA::Exception *_exc);
      static const CustomerException* _downcast(const CORBA::Exception *_exc);
      CORBA::Exception *_deep_copy() { return new CustomerException(*this); }
      void _raise() const { VISTHROW_INST(this) }

      friend void _pretty_print(VISostream&, const CustomerException&);
      void _write(VISostream&) const;
      void _copy(VISistream&);

      friend VISistream& operator>>(VISistream& _strm, CustomerException& _e);
      static const CORBA_Exception::Description _description;
    };

    static  const CORBA::TypeInfo *_desc();
    virtual const CORBA::TypeInfo *_type_info() const;
    virtual void *_safe_narrow(const CORBA::TypeInfo& ) const;
    static CORBA::Object*_factory();
    Customers_ptr _this();
    static Customers_ptr _duplicate(Customers_ptr _obj) {
      if (_obj) _obj->_ref();
      return _obj;
    }
    static Customers_ptr _nil() { return (Customers_ptr)NULL; }
    static Customers_ptr _narrow(CORBA::Object* _obj);
    static Customers_ptr _clone(Customers_ptr _obj) {
      CORBA::Object_var _obj_var(CORBA_Object::_clone(_obj));
      #if defined(_HPCC_BUG)
        return _narrow(_obj_var.operator CORBA::Object_ptr());
      #else
        return _narrow(_obj_var);
      #endif  // _HPCC_BUG
    }
    static Customers_ptr _bind(const char *_object_name = (const char*)NULL,
                               const char *_host_name = (const char*)NULL,
                               const CORBA::BindOptions* _opt = (CORBA::BindOptions*)NULL,
                               CORBA::ORB_ptr _orb = (CORBA::ORB_ptr)NULL);

    static Customers_ptr _bind(const char *_poa_name,
                               const CORBA::OctetSequence& _id,
                               const char *_host_name = (const char*)NULL,
                               const CORBA::BindOptions* _opt = (CORBA::BindOptions*)NULL,
                               CORBA::ORB_ptr _orb = (CORBA::ORB_ptr)NULL);

    virtual CORBA::Any* GetCustomers(CORBA::Boolean _metadata);    virtual CORBA::Any* ApplyCustomerUpdates(const CORBA::Any& _Delta,
                                                                                                            CORBA::Long_out _ErrorCount);
    friend VISostream& operator<<(VISostream& _strm, const Customers_ptr _obj);
    friend VISistream& operator>>(VISistream& _strm, Customers_ptr& _obj);
    friend Ostream& operator<<(Ostream& _strm, const Customers_ptr _obj);
    friend Istream& operator>>(Istream& _strm, Customers_ptr& _obj);
    friend void _pretty_print(VISostream& _strm, const Customers_ptr _obj) {
      _strm << _obj;
    }
  };


  class Customers_ops;
  typedef Customers_ops* Customers_ops_ptr;

  class  Customers_ops  {
   public:
    Customers_ops() {}
    virtual ~Customers_ops () {}

    virtual CORBA::Any* GetCustomers(CORBA::Boolean _metadata) = 0;
    virtual CORBA::Any* ApplyCustomerUpdates(const CORBA::Any& _Delta,
                                             CORBA::Long_out _ErrorCount) = 0;

    static const VISOps_Info *_desc() { return &_ops_info; }
    static Customers_ops_ptr _nil() { return (Customers_ops_ptr)NULL; }
    static Customers_ops_ptr _downcast(PortableServer::ServantBase* _servant) {
      if (_servant == (PortableServer::ServantBase*)NULL)
        return Customers_ops::_nil();
      return (Customers_ops_ptr)_servant->_safe_downcast_ops(_ops_info);
    }
  protected:
    static const VISOps_Info _ops_info;
  };

};

#include "vpost.h"
#endif // __Customers_idl___client
