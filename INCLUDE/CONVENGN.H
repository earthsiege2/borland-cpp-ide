// --convengn.h-----------------------------------------------------------------
// 
// Defines main conversion engine class.
//
// Copyright 1986 - 1998 Microsoft Corporation.  All Rights Reserved.
//
// -----------------------------------------------------------------------------

#if !defined(_CONVENGN_H)
#pragma option push -b -a8 -pc -A- /*P_O_Push*/
#define _CONVENGN_H

//$$--CEDKConvEng---------------------------------------------------------------
//
//  DESCRIPTION: Conversion engine class.  Performs all convresions.
//
// ---------------------------------------------------------------------------
class CEDKConvEng
{
public:
    CEDKConvEng() ;

    HRESULT HrEDKInitialize(    // RETURNS: HRESULT
        IN HANDLE hEventSource) ;    // event source handle

    HRESULT HrEDKConvert(       // RETURNS: HRESULT
        IN PEDKCNVENV pEnv,     
        IN LPCWSTR pszContentClass,
        IN PVOID pContentIn,
        OUT PVOID pContentOut,
        OUT EDKCNVRES & crResult) ;

    HRESULT HrEDKUninitialize(  // RETURNS: HRESULT
        ) ;

protected:
    // helper
    HRESULT HrEDKAttemptConversion( //  RETURNS: HRESULT
        IN PEDKCNVENV pEnv,            
        IN LPCWSTR pszContentClass,   
        IN LPCWSTR pszConversionPoint,   
        IN PVOID pContentIn,           
        OUT PVOID pContentOut,        
        OUT EDKCNVRES & crResult) ;   


    CDllEntryPoint * m_pepConverter ;       // current converter.
    CEDKConvReg m_crRegistry ;              // conversion registry.
	HANDLE m_hEventSource ;

	BOOL m_bFoundAtLeastOneAccept ;

} ;

#pragma option pop /*P_O_Pop*/
#endif
