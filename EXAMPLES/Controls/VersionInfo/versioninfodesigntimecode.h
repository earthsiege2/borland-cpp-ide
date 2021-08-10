
#ifndef VersionInfoDesignTimeCodeH
#define VersionInfoDesignTimeCodeH

#include <DesignIntf.hpp>
#include <DesignEditors.hpp>

class PACKAGE TVersionInfoFileNameEditor : public TStringProperty
{
  private:
    typedef TStringProperty inherited;

  public:
    virtual void __fastcall Edit(void);
    virtual TPropertyAttributes __fastcall GetAttributes(void);
    virtual AnsiString __fastcall GetValue();
    virtual void __fastcall SetValue(const AnsiString Value);
};


class PACKAGE TVersionInfoFileDateEditor : public TDateProperty
{
  private:
    typedef TDateProperty inherited;

  public:
    virtual TPropertyAttributes __fastcall GetAttributes(void);
    virtual AnsiString __fastcall GetValue();
};


class PACKAGE TVersionInfoLanguageCharsetIndexEditor : public TIntegerProperty
{
  private:
    typedef TPropertyEditor inherited;

  private:
    AnsiString __fastcall GetTranslationNameAtIndex(const int Index);
    bool __fastcall GetIndexForTranslationName(const String& TranslationName, int& Index);

  public:
    virtual void __fastcall Edit(void);
    virtual TPropertyAttributes __fastcall GetAttributes(void);
    virtual AnsiString __fastcall GetValue(void);
    virtual void __fastcall SetValue(const AnsiString Value);
    virtual void __fastcall GetValues(Classes::TGetStrProc Proc);
};


class PACKAGE TVersionInfoComponentEditor : public TComponentEditor
{
  private:
    typedef TComponentEditor inherited;

  private:
    void __fastcall DoTestAboutBox();
    void __fastcall DoChangeFileNameProperty();

  public:
    virtual void __fastcall Edit(void);
    virtual void __fastcall ExecuteVerb(int Index);
    virtual AnsiString __fastcall GetVerb(int Index);
    virtual int __fastcall GetVerbCount(void);
};

#endif
