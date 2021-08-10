// MYAUTOIMPL : Implementation of TMyAutoImpl (CoClass: MyAuto, Interface: IMyAuto)

#include <vcl.h>
#pragma hdrstop

#include "MYAUTOIMPL.H"

/////////////////////////////////////////////////////////////////////////////
// TMyAutoImpl

STDMETHODIMP TMyAutoImpl::get_MyProp(BSTR* Value)
{
  try
  {
    ShowMessage("In MyProp getter function");
    *Value = FMyProp.c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IMyAuto);
  }
  return S_OK;
};


STDMETHODIMP TMyAutoImpl::set_MyProp(BSTR Value)
{
  try
  {
    ShowMessage("In MyProp setter function");
    FMyProp = Value;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IMyAuto);
  }
  return S_OK;
};


STDMETHODIMP TMyAutoImpl::ShowDialog()
{
  try
  {
   if (FMyProp.IsEmpty())
     FMyProp = "This object has a property called MyProp";

    ShowMessage(FMyProp);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IMyAuto);
  }
  return S_OK;
}

