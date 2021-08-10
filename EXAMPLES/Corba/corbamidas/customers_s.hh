/*
 * Copyright 1999-2002 Borland Corporation, Inc.
 *
 * GENERATED CODE --- DO NOT EDIT
 * 
 */

#ifndef __Customers_idl___server
#define __Customers_idl___server
#include "vpre.h"

#include "Customers_c.hh"

class  POA_CBuilder {
  public:


  class  Customers : public CBuilder::Customers_ops ,public virtual PortableServer_ServantBase {
   protected:
    Customers() {}

    virtual ~Customers() {}

   public:
    static const CORBA::TypeInfo _skel_info;
    virtual const CORBA::TypeInfo *_type_info() const;

    CBuilder::Customers_ptr _this();


    virtual void *_safe_narrow(const CORBA::TypeInfo& ) const;

    static Customers * _narrow(PortableServer_ServantBase *_obj);

    // The following operations need to be implemented
    virtual CORBA::Any* GetCustomers(CORBA::Boolean _metadata) = 0;


    virtual CORBA::Any* ApplyCustomerUpdates(const CORBA::Any& _Delta,
                                             CORBA::Long_out _ErrorCount) = 0;


    // Skeleton Operations implemented automatically
    virtual void* _safe_downcast_ops(const VISOps_Info& _info) {
      if (_info == *CBuilder::Customers_ops::_desc())
        return (void*)(CBuilder::Customers_ops*)this;
      return (void*)NULL;
       }

    static void _GetCustomers(void *_obj, CORBA::MarshalInBuffer &_istrm,
                              const char *_oper, VISReplyHandler& handler);

    static void _ApplyCustomerUpdates(void *_obj,
                                      CORBA::MarshalInBuffer &_istrm,
                                      const char *_oper,
                                      VISReplyHandler& handler);

  };

};

template <class T> class POA_CBuilder_Customers_tie : public POA_CBuilder::Customers {
  private:
   CORBA::Boolean _rel;
   PortableServer::POA_ptr _poa;
   T *_ptr;
   POA_CBuilder_Customers_tie(const POA_CBuilder_Customers_tie&) {}
   void operator=(const POA_CBuilder_Customers_tie&) {}

  public:
   POA_CBuilder_Customers_tie (T& t): _ptr(&t), _poa(NULL), _rel((CORBA::Boolean)0) {}

 POA_CBuilder_Customers_tie (T& t, PortableServer::POA_ptr poa): _ptr(&t), 
   _poa(PortableServer_POA::_duplicate(poa)), _rel((CORBA::Boolean)0) {}

 POA_CBuilder_Customers_tie (T *p, CORBA::Boolean release= 1) : _ptr(p), _poa(NULL), _rel(release) {}

 POA_CBuilder_Customers_tie (T *p, PortableServer::POA_ptr poa, CORBA::Boolean release =1)
   : _ptr(p), _poa(PortableServer_POA::_duplicate(poa)), _rel(release) {}

 virtual ~POA_CBuilder_Customers_tie() {
   CORBA::release(_poa);
     if (_rel) {
     delete _ptr;
       }
     }

 T* _tied_object() { return _ptr; }
   void _tied_object(T& t) {
   if (_rel) {
     delete _ptr;
       }
     _ptr = &t;
     _rel = 0;
     }
   void _tied_object(T *p, CORBA::Boolean release=1) {
      if (_rel) { 
        delete _ptr;
      }
      _ptr = p;
      _rel = release;
       }

 CORBA::Boolean _is_owner() { return _rel; }
   void _is_owner(CORBA::Boolean b) { _rel = b; }

  CORBA::Any* GetCustomers(CORBA::Boolean _metadata) {
  return _ptr->GetCustomers(_metadata);
  }
  CORBA::Any* ApplyCustomerUpdates(const CORBA::Any& _Delta,
                                   CORBA::Long_out _ErrorCount) {
  return _ptr->ApplyCustomerUpdates(_Delta, _ErrorCount);
  }
  PortableServer::POA_ptr _default_POA() {
    if ( !CORBA::is_nil(_poa) ) {
      return _poa;
    } else {
      return PortableServer_ServantBase::_default_POA();
    }
  }

};

class  _sk_CBuilder {
public:
class  _sk_Customers : public POA_CBuilder::Customers,
                       public PortableServer_RefCountServantBase,
                       public CBuilder::Customers {
 protected:
  _sk_Customers (const char *_obj_name = (const char*)NULL) {
    PortableServer_ServantBase::_object_name(_obj_name);
  }
  _sk_Customers (const char *_service_name, const CORBA::ReferenceData& _data) {
    PortableServer_ServantBase::_service(_service_name, _data);
  }

 public:
  virtual ~_sk_Customers() {}
  virtual PortableServer_ServantBase *_get_servant() {
    return this;
  }
  virtual CORBA::Object_ptr _backcompat_object() {
    return this;
  }
  CBuilder::Customers_ptr _this() {
    POA_CBuilder::Customers *_temp = this;
    return _temp->_this();
  }

  void _release() { _remove_ref(); }
  void _ref() { _add_ref(); }

  const char *_repository_id() const {
    return PortableServer_ServantBase::_repository_id();
  }
};
};
template <class T>
class CBuilder_tie_Customers : public POA_CBuilder_Customers_tie<T>, public virtual CORBA_Object {
 private:
CBuilder_tie_Customers (const CBuilder_tie_Customers&) : POA_CBuilder_Customers_tie<T>((T *)NULL, (CORBA::Boolean)0) {}
void operator=(const CBuilder_tie_Customers&) {}

 public:
CBuilder_tie_Customers(T& _t, const char *_obj_name = (char *) NULL, CORBA::Boolean _r_f = 0) 
    : POA_CBuilder_Customers_tie<T>(&_t, _r_f) {
  PortableServer_ServantBase::_object_name(_obj_name);
}

CBuilder_tie_Customers(T& _t, const char *_serv_name, const CORBA::ReferenceData& _id, CORBA::Boolean _r_f = 0)
    : POA_CBuilder_Customers_tie<T>(&_t, _r_f) {
  PortableServer_ServantBase::_service(_serv_name, _id);
}

CORBA::Boolean rel_flag() { 
  return _is_owner(); 
}

void rel_flag(CORBA::Boolean flag) { 
  _is_owner(flag); 
}

virtual ~CBuilder_tie_Customers() {}

virtual PortableServer_ServantBase *_get_servant() {
  return this;
}

const char *repository_id() const {
  return PortableServer_ServantBase::_repository_id();
}
};

#include "vpost.h"
#endif  // __Customers_idl___server
