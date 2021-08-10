/*
 * Copyright 1999-2002 Borland Corporation, Inc.
 *
 * GENERATED CODE --- DO NOT EDIT
 * 
 */

#include <corbapch.h>
#pragma hdrstop
#include "Customers_s.hh"
static CORBA::MethodDescription _sk_CBuilder_Customers_methods[] = {
  {"GetCustomers", POA_CBuilder::Customers::_GetCustomers},
  {"ApplyCustomerUpdates", POA_CBuilder::Customers::_ApplyCustomerUpdates}
};


const CORBA::TypeInfo POA_CBuilder::Customers::_skel_info(
 "CBuilder::Customers", NULL, (CORBA::ULong) 2,
 _sk_CBuilder_Customers_methods         , NULL, 0, NULL);
         
const CORBA::TypeInfo *POA_CBuilder::Customers::_type_info() const {
  return &_skel_info;
}

CBuilder::Customers_ptr POA_CBuilder::Customers::_this() {
  return (CBuilder::Customers *)(PortableServer_ServantBase::_this()->_safe_narrow(*CBuilder::Customers::_desc()));
}


void *POA_CBuilder::Customers::_safe_narrow(const CORBA::TypeInfo& _info) const {
  if (_info == _skel_info) {
    return (void *)this;
  }


  if (_info == PortableServer_ServantBase::_skel_info) {
    return (void *)(PortableServer_ServantBase *)this;
  }
  return 0;
}

POA_CBuilder::Customers * POA_CBuilder::Customers::_narrow(PortableServer::ServantBase *_obj) {
  if (!_obj) {
    return (POA_CBuilder::Customers*)NULL;
  } else {
    return (Customers*)_obj->_safe_narrow(_skel_info);
  }
}

void POA_CBuilder::Customers::_GetCustomers (void *_obj,
                                             CORBA::MarshalInBuffer &_istrm,
                                             const char *_oper,
                                             VISReplyHandler& _handler) {
  VISCLEAR_EXCEP
  VISistream& _vistrm = _istrm;
  POA_CBuilder::Customers *_impl = (POA_CBuilder::Customers*)_obj;
  CORBA::Boolean _local_metadata;
    _vistrm >> _local_metadata;

  CORBA::MarshalOutBuffer_var _obuf = _handler.create_reply();
  VISostream& _ostrm = *VISostream::_downcast(_obuf);
CORBA::Any_var _ret = _impl->GetCustomers( _local_metadata);
  VISIF_EXCEP(return;)
  _ostrm << _ret;
}


void POA_CBuilder::Customers::_ApplyCustomerUpdates (void *_obj,
                                                     CORBA::MarshalInBuffer &_istrm,
                                                     const char *_oper,
                                                     VISReplyHandler& _handler) {
  VISCLEAR_EXCEP
  VISistream& _vistrm = _istrm;
  POA_CBuilder::Customers *_impl = (POA_CBuilder::Customers*)_obj;
  CORBA::Any_var _local_Delta;
  CORBA::Long _local_ErrorCount;
    _vistrm >> _local_Delta;


  CORBA::MarshalOutBuffer_var _obuf = _handler.create_reply();
  VISostream& _ostrm = *VISostream::_downcast(_obuf);
CORBA::Any_var _ret = _impl->ApplyCustomerUpdates( _local_Delta,  _local_ErrorCount);
  VISIF_EXCEP(return;)
  _ostrm << _ret;
  _ostrm << _local_ErrorCount;
}



