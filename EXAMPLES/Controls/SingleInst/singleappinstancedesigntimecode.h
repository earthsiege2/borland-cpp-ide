                                        
#ifndef SingleAppInstanceDesignTimeCodeH
#define SingleAppInstanceDesignTimeCodeH

#include <DsgnIntf.Hpp>

class PACKAGE TSingleInstanceMarkerPropertyEditor : public TStringProperty
{
  private:
    typedef TStringProperty inherited;

  public:
    virtual void __fastcall Edit(void);
    virtual TPropertyAttributes __fastcall GetAttributes(void);
    virtual AnsiString __fastcall GetValue(void);
    virtual void __fastcall SetValue(const AnsiString Value);
};

#endif // SingleAppInstanceDesignTimeCodeH

