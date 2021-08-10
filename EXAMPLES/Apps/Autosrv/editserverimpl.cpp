// EDITSERVERIMPL : Implementation of TEditServerImpl (CoClass: EditServer, Interface: IEditServer)

#include <vcl.h>
#pragma hdrstop

#include "main.h"
#include "EDITSERVERIMPL.H"

/////////////////////////////////////////////////////////////////////////////
// TEditServerImpl

STDMETHODIMP TEditServerImpl::Clear()
{
  try
  {
    Form1->Edit1->Text="";
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IEditServer);
  }
  return S_OK;
}

STDMETHODIMP TEditServerImpl::SetThreeStr(BSTR s1, BSTR s2, BSTR s3,
  BSTR* result)
{
  try
  {
    WideString retval(s1);
    retval += L" ";
    retval += s2;
    retval += L" ";
    retval += s3;
    Form1->Edit1->Text = retval;

    // Send out a copy of our concatenated BSTR
    // NOTE: result is not an [in, out], so we're not responsible for freeing what was there before
    *result = retval.Copy();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IEditServer);
  }
  return S_OK;
}


STDMETHODIMP TEditServerImpl::get_EditNum(int* Value)
{
  try
  {
    int val = atoi(Form1->Edit1->Text.c_str());
   *Value = val;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IEditServer);
  }
  return S_OK;
};


STDMETHODIMP TEditServerImpl::get_EditStr(BSTR* Value)
{
  try
  {
     *Value = WideString(Form1->Edit1->Text).Detach();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IEditServer);
  }
  return S_OK;
};


STDMETHODIMP TEditServerImpl::set_EditNum(int Value)
{
  try
  {
     Form1->Edit1->Text = AnsiString(Value);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IEditServer);
  }
  return S_OK;
};


STDMETHODIMP TEditServerImpl::set_EditStr(BSTR Value)
{
  try
  {
    Form1->Edit1->Text = AnsiString(Value);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IEditServer);
  }
  return S_OK;
};


