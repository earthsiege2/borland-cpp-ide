#if !defined(SOCKDEMO_H)
#define SOCKDEMO_H

#include <owl/defs.h>
#include "sockdemo.rh" // Definitions of all resources.

class SockDemoApp : public TApplication {
public:
    SockDemoApp();
    virtual ~SockDemoApp();
    virtual void InitMainWindow();

protected:
    void CmGetWSAData();
    void CmGetMyAddress();
    void CmConvertService();
    void CmConvertAddress();
    void CmSendDatagrams();
    void CmStreamListen();
    void CmStreamConnect();
    void CmShowSocketError();
    void CmHelpAbout();
    void CmHelpHow();
    DECLARE_RESPONSE_TABLE(SockDemoApp);
};

#endif  // SOCKDEMO_H
