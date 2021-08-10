[!outputon] // $Revision:   1.4  $
// [!CPPName] : Implementation of [!ClassName] (CoClass: [!CoClassName], Interface: [!InterfaceName])

#include <vcl.h>
#pragma hdrstop

#include "[!HeaderName]"
[!crlf]

/////////////////////////////////////////////////////////////////////////////
// [!ClassName]
[!crlf]
[!if=(ErrorInfoEnabled, "TRUE")]
STDMETHODIMP [!ClassName]::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_[!InterfaceName],
	};

	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}
[!endif]
