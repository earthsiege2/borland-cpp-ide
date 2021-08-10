///////////////////////////////////////////////////////////////////////////////
//
//
//      Copyright (c) 1998-1999  Microsoft Corporation
//
//
//      Name: msptrmar.h
//
// Description: Definition of the CAudioRenderTerminal class
//
///////////////////////////////////////////////////////////////////////////////

#ifndef _MSPTRMAR_H_
#pragma option push -b -a8 -pc -A- /*P_O_Push*/
#define _MSPTRMAR_H_

#define WAVEOUT_NAME L"WaveOut Terminal"
#define MIXER_NAME L"PCM Mixer"

/////////////////////////////////////////////////////////////////////////////
// CAudioRenderTerminal

class CAudioRenderTerminal : 
    public IDispatchImpl<ITBasicAudioTerminal, &IID_ITBasicAudioTerminal, &LIBID_TAPI3Lib>, 
    public CSingleFilterTerminal
{
public:
    CAudioRenderTerminal();
    virtual ~CAudioRenderTerminal();

    // Helper methods.
    HRESULT InitializeDefaultTerminal();

    static HRESULT CreateTerminal(
        IN    CComPtr<IMoniker>    pMoniker,
        IN    MSP_HANDLE           htAddress,
        OUT   ITTerminal         **ppTerm
        );

    HRESULT FindTerminalPin();

BEGIN_COM_MAP(CAudioRenderTerminal)
    COM_INTERFACE_ENTRY(ITBasicAudioTerminal)
    COM_INTERFACE_ENTRY_CHAIN(CSingleFilterTerminal)
END_COM_MAP()

DECLARE_VQI()
DECLARE_LOG_ADDREF_RELEASE(CAudioRenderTerminal)

// ITBasicAudioTerminal
public:
    STDMETHOD(get_Balance)(OUT  long *pVal);
    STDMETHOD(put_Balance)(IN   long newVal);
    STDMETHOD(get_Volume) (OUT  long *pVal);
    STDMETHOD(put_Volume) (IN   long newVal);

// Implementation
public:

    // CBaseTerminal overrides 

    STDMETHODIMP CompleteConnectTerminal(void);

    STDMETHODIMP DisconnectTerminal(
            IN      IGraphBuilder  * pGraph,
            IN      DWORD            dwReserved
            );
    
    virtual HRESULT AddFiltersToGraph();

    virtual DWORD GetSupportedMediaTypes(void)
    {
        return (DWORD) TAPIMEDIATYPE_AUDIO;
    }

    HRESULT CreateFilters();

    // public because CreateTerminal access it
    CComPtr<IMoniker> m_pMoniker;

private:

    // Keeps track of whether we need to unreserve WaveOut
    bool m_bResourceReserved;

    CComPtr<IBasicAudio> m_pIBasicAudio;

};

#pragma option pop /*P_O_Pop*/
#endif // _MSPTRMAR_H_
