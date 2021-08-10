/*
 * Copyright 1999-2002 Borland Corporation, Inc.
 *
 * GENERATED CODE --- DO NOT EDIT
 * 
 */

#include <corbapch.h>
#pragma hdrstop
#include "Customers_c.hh"

CBuilder::Customers_ptr CBuilder::Customers_var::_duplicate(CBuilder::Customers_ptr _p) {
  return CBuilder::Customers::_duplicate(_p);
}

void
CBuilder::Customers_var::_release(CBuilder::Customers_ptr _p) {
  CORBA::release((CORBA::Object_ptr)_p);
}

CBuilder::Customers_var::Customers_var()
  : _ptr(CBuilder::Customers::_nil()) {}

CBuilder::Customers_var::Customers_var(CBuilder::Customers_ptr _p)
  : _ptr(_p) {}

CBuilder::Customers_var::Customers_var(const CBuilder::Customers_var& _var)
  : _ptr(CBuilder::Customers::_duplicate((CBuilder::Customers_ptr) _var)) {}

CBuilder::Customers_var::~Customers_var() {
  CORBA::release((CORBA::Object_ptr)_ptr);
}

CBuilder::Customers_var&
CBuilder::Customers_var::operator=(CBuilder::Customers_ptr _p) {
  CORBA::release((CORBA::Object_ptr)_ptr);
  _ptr = _p;
  return *this;
}

CBuilder::Customers_ptr& CBuilder::Customers_var::out() {
  _release(_ptr);
  _ptr = (CBuilder::Customers_ptr)NULL;
  return _ptr;
}

CBuilder::Customers_ptr CBuilder::Customers_var::_retn() {
  CBuilder::Customers_ptr _tmp_ptr = _ptr;
  _ptr = (CBuilder::Customers_ptr)NULL;
  return _tmp_ptr;
}

VISistream& operator>>(VISistream& _strm, CBuilder::Customers_var& _var) {
  _strm >> _var._ptr;
  return _strm;
}

VISostream& operator<<(VISostream& _strm, const CBuilder::Customers_var& _var) {
  _strm << _var._ptr;
  return _strm;
}

Istream& operator>>(Istream& _strm, CBuilder::Customers_var& _var) {
  VISistream _istrm(_strm);
  _istrm >> _var._ptr;
  return _strm;
}

Ostream& operator<<(Ostream& _strm, const CBuilder::Customers_var& _var) {
  _strm << (CORBA::Object_ptr)_var._ptr;
  return _strm;
}


VISistream& operator>>(VISistream& _strm,
                       CBuilder::Customers::CustomerException& _e) {
  CORBA::String_var _exp_name;
  _strm >> _exp_name;
  _e._copy(_strm);
  return _strm;
}

const CORBA_Exception::Description CBuilder::Customers::CustomerException::_description(
        "::CBuilder::Customers::CustomerException",
"IDL:CBuilder/Customers/CustomerException:1.0",
CBuilder::Customers::CustomerException::_factory,
&CORBA::UserException::_description);

#if defined(MSVCNEWDLL_BUG)
void *CBuilder::Customers::CustomerException::operator new(size_t ts) {
  return ::operator new(ts);
}
void CBuilder::Customers::CustomerException::operator delete(void *p) {
  ::operator delete(p);
}
#endif // MSVCNEWDLL_BUG

const CORBA_Exception::Description& CBuilder::Customers::CustomerException::_desc() const {
return _description;
}

CBuilder::Customers::CustomerException* CBuilder::Customers::CustomerException::_downcast(CORBA::Exception *_exc) {
  if (_exc && _exc->_desc().can_cast(_description)) {
    return (CBuilder::Customers::CustomerException *)_exc;
  } else {
    return (CBuilder::Customers::CustomerException *)NULL;
  }
}

const CBuilder::Customers::CustomerException* CBuilder::Customers::CustomerException::_downcast(const CORBA::Exception *_exc) {
  return _downcast((CORBA::Exception *)_exc);
}

void CBuilder::Customers::CustomerException::_write(VISostream& _strm) const {
     _strm << s;

}

void CBuilder::Customers::CustomerException::_copy(VISistream& _strm) {
     _strm >> s;

}
void _pretty_print(VISostream& _strm,
                   const CBuilder::Customers::CustomerException& _s) {
  _strm << "EXCEPTION CBuilder::Customers::CustomerException {" << endl;
    _strm << "\ts:" << endl;
  _strm << "\t" << _s.s << endl;

  _strm << "}" << endl;
}
// If dllimport is specified, you might probably want to
// disable these definitions
// disable the const definitions
const VISOps_Info CBuilder::Customers_ops::_ops_info("CBuilder::Customers_ops");
const CORBA::TypeInfo
CBuilder::Customers::_class_info("CBuilder::Customers",
                                 "IDL:CBuilder/Customers:1.0", NULL,
                                 CBuilder::Customers::_factory, NULL, 0, NULL,
                                 0, CORBA::Object::_desc(), 0);

const CORBA::TypeInfo *CBuilder::Customers::_desc() { return &_class_info; }
const CORBA::TypeInfo *CBuilder::Customers::_type_info() const {
  return &_class_info;
}

VISistream& operator>>(VISistream& _strm, CBuilder::Customers_ptr& _obj) {
  CORBA::Object_var _var_obj(_obj);
  _var_obj = CORBA::Object::_read(_strm, CBuilder::Customers::_desc());
  _obj = CBuilder::Customers::_narrow(_var_obj);
  return _strm;
}

VISostream& operator<<(VISostream& _strm, const CBuilder::Customers_ptr _obj) {
  _strm << (CORBA::Object_ptr)_obj;
  return _strm;
}
void* CBuilder::Customers::_safe_narrow(const CORBA::TypeInfo& _info) const {
  if (_info == _class_info)
    return (void *)this;
  return CORBA_Object::_safe_narrow(_info);
}

CORBA::Object *CBuilder::Customers::_factory() {
  return new CBuilder::Customers;
}

CBuilder::Customers_ptr CBuilder::Customers::_this() {
  return CBuilder::Customers::_duplicate(this);
}

CBuilder::Customers_ptr CBuilder::Customers::_narrow(CORBA::Object * _obj) {
  if (_obj == CBuilder::Customers::_nil())
    return CBuilder::Customers::_nil();
  else
    return CBuilder::Customers::_duplicate((CBuilder::Customers_ptr)_obj->_safe_narrow(_class_info));
}



Ostream& operator<<(Ostream& _strm, const CBuilder::Customers_ptr _obj) {
  _strm << (CORBA::Object_ptr) _obj;
  return _strm;
}
Istream& operator>>(Istream& _strm, CBuilder::Customers_ptr& _obj) {
  VISistream _istrm(_strm);
  _istrm >> _obj;
  return _strm;
}

CBuilder::Customers *CBuilder::Customers::_bind(const char *_object_name,
                                                const char *_host_name,
                                                const CORBA::BindOptions *_opt,
                                                CORBA::ORB_ptr _orb)
{
  VISCLEAR_EXCEP
  CORBA::Object_var _obj = CORBA::Object::_bind_to_object(
          "IDL:CBuilder/Customers:1.0", _object_name, _host_name, _opt, _orb);
  return Customers::_narrow(_obj);
}

CBuilder::Customers *CBuilder::Customers::_bind(const char *_poa_name,
                                                const CORBA::OctetSequence& _id,
                                                const char *_host_name,
                                                const CORBA::BindOptions *_opt,
                                                CORBA::ORB_ptr _orb)
{
  VISCLEAR_EXCEP
  CORBA::Object_var _obj = CORBA::Object::_bind_to_object(
   "IDL:CBuilder/Customers:1.0", _poa_name, _id, _host_name, _opt, _orb);
  return Customers::_narrow(_obj);
}
CORBA::Any* CBuilder::Customers::GetCustomers(CORBA::Boolean _arg_metadata ) {
  CORBA::Any* _ret = (CORBA::Any *) 0;
  CORBA_MarshalInBuffer_var _ibuf;

  while (1) {
    VISCLEAR_EXCEP 
			
    if (_is_local()) {
      PortableServer::ServantBase_ptr _servant;
      VISTRY {
        _servant = _preinvoke("GetCustomers");
      }
      VISCATCH(VISRemarshal, _vis_except) { continue; } 
      VISEND_CATCH
		  
      CBuilder::Customers_ops*  _customers = CBuilder::Customers_ops::_downcast(_servant);
      if (!_customers) {
        if ((PortableServer::ServantBase*)_servant)
          _postinvoke(_servant, "GetCustomers");
        VISTHROW(CORBA::BAD_OPERATION());
        VISRETURN(return _ret;)
      }

      VISTRY {
         _ret = _customers->GetCustomers(_arg_metadata );
      }
      VISCATCH_ALL{
        _postinvoke(_servant, "GetCustomers"); 
        VISTHROW_LAST;
        VISRETURN(return _ret;)
      }
      VISEND_CATCH
      _postinvoke(_servant, "GetCustomers");
      return _ret;
    }

    CORBA::MarshalOutBuffer_var _obuf;
    _obuf = _request("GetCustomers", 1);
    VISIF_EXCEP(return _ret;)
    VISostream& _ostrm = *VISostream::_downcast(_obuf);
    _ostrm << _arg_metadata;

    VISTRY {
      _ibuf = _invoke(_obuf);
      VISIFNOT_EXCEP
      break;
      VISEND_IFNOT_EXCEP
    } VISCATCH(VISRemarshal, _vis_except) { continue; } 
    VISEND_CATCH
    VISRETURN(return _ret;)
  }

  VISistream& _istrm = *VISistream::_downcast(_ibuf);
  _istrm >> _ret;

  return _ret;
}


CORBA::Any* CBuilder::Customers::ApplyCustomerUpdates(const CORBA::Any& _arg_Delta ,
                                                      CORBA::Long_out _arg_ErrorCount ) {
  CORBA::Any* _ret = (CORBA::Any *) 0;
  CORBA_MarshalInBuffer_var _ibuf;

  while (1) {
    VISCLEAR_EXCEP 
			
    if (_is_local()) {
      PortableServer::ServantBase_ptr _servant;
      VISTRY {
        _servant = _preinvoke("ApplyCustomerUpdates");
      }
      VISCATCH(VISRemarshal, _vis_except) { continue; } 
      VISEND_CATCH
		  
      CBuilder::Customers_ops*  _customers = CBuilder::Customers_ops::_downcast(_servant);
      if (!_customers) {
        if ((PortableServer::ServantBase*)_servant)
          _postinvoke(_servant, "ApplyCustomerUpdates");
        VISTHROW(CORBA::BAD_OPERATION());
        VISRETURN(return _ret;)
      }

      VISTRY {
         _ret = _customers->ApplyCustomerUpdates(_arg_Delta , _arg_ErrorCount );
      }
      VISCATCH_ALL{
        _postinvoke(_servant, "ApplyCustomerUpdates"); 
        VISTHROW_LAST;
        VISRETURN(return _ret;)
      }
      VISEND_CATCH
      _postinvoke(_servant, "ApplyCustomerUpdates");
      return _ret;
    }

    CORBA::MarshalOutBuffer_var _obuf;
    _obuf = _request("ApplyCustomerUpdates", 1);
    VISIF_EXCEP(return _ret;)
    VISostream& _ostrm = *VISostream::_downcast(_obuf);
    _ostrm << _arg_Delta;

    VISTRY {
      _ibuf = _invoke(_obuf);
      VISIFNOT_EXCEP
      break;
      VISEND_IFNOT_EXCEP
    } VISCATCH(VISRemarshal, _vis_except) { continue; } 
    VISEND_CATCH
    VISRETURN(return _ret;)
  }

  VISistream& _istrm = *VISistream::_downcast(_ibuf);
  _istrm >> _ret;

    _istrm >> _arg_ErrorCount;

  return _ret;
}




