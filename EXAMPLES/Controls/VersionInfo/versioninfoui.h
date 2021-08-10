
#ifndef VersionInfoUIH
#define VersionInfoUIH

#include <SysUtils.hpp>
#include <Classes.hpp>
#include <StdCtrls.hpp>

#include "VersionInfoComponent.h"

class PACKAGE TCustomVersionInfoLabel : public TCustomLabel
{
  private:
    typedef TCustomLabel inherited;

  private:
    void __fastcall CMVersionInfoChange(TMessage& Message);

    BEGIN_MESSAGE_MAP
      VCL_MESSAGE_HANDLER(CM_VERSIONINFOCHANGE, TMessage, CMVersionInfoChange)
    END_MESSAGE_MAP(inherited)

  protected:
    TVersionInfo* FVersionInfo;
    void __fastcall SetVersionInfo(TVersionInfo*);

    void __fastcall UpdateLabelContent(void);

  protected:
    virtual void __fastcall Notification(TComponent* AComponent, TOperation Operation);
    virtual System::AnsiString __fastcall GetLabelText();

    virtual System::AnsiString __fastcall GetVersionLabelText() = 0; // abstract

  public:
    __fastcall TCustomVersionInfoLabel(TComponent* Owner);

  __published:
    __property TVersionInfo* VersionInfo = { read = FVersionInfo, write = SetVersionInfo };

  //
  // The following properties are only re-published
  //
  __published:
    __property Align;
    __property Alignment;
    __property Anchors;
    __property AutoSize;
    __property BiDiMode;
    __property Caption;
    __property Color;
    __property Constraints;
    __property DragCursor;
    __property DragKind;
    __property DragMode;
    __property Enabled;
    __property FocusControl;
    __property Font;
    __property ParentBiDiMode;
    __property ParentColor;
    __property ParentFont;
    __property ParentShowHint;
    __property PopupMenu;
    __property ShowAccelChar;
    __property ShowHint;
    __property Transparent;
    __property Layout;
    __property Visible;
    __property WordWrap;
    __property OnClick;
    __property OnDblClick;
    __property OnDragDrop;
    __property OnDragOver;
    __property OnEndDock;
    __property OnEndDrag;
    __property OnMouseDown;
    __property OnMouseMove;
    __property OnMouseUp;
    __property OnStartDock;
    __property OnStartDrag;
};

//---------------------------------------------------------------------------

class PACKAGE TVersionInfoGenericLabel : public TCustomVersionInfoLabel
{
  private:
    typedef TCustomVersionInfoLabel inherited;

  private:
    String FStringEntry;
    void __fastcall SetStringEntry(const String);

  protected:
    virtual System::AnsiString __fastcall GetVersionLabelText();

  public:
    __fastcall TVersionInfoGenericLabel(TComponent* Owner);

  __published:
    __property String StringEntry = { read = FStringEntry, write = SetStringEntry };
};

//---------------------------------------------------------------------------

class PACKAGE TVersionInfoCommentsLabel : public TCustomVersionInfoLabel
{
  private:
    typedef TCustomVersionInfoLabel inherited;

  protected:
    virtual System::AnsiString __fastcall GetVersionLabelText();

  public:
    __fastcall TVersionInfoCommentsLabel(TComponent* Owner);
};

//---------------------------------------------------------------------------

class PACKAGE TVersionInfoCompanyNameLabel : public TCustomVersionInfoLabel
{
  private:
    typedef TCustomVersionInfoLabel inherited;

  protected:
    virtual System::AnsiString __fastcall GetVersionLabelText();

  public:
    __fastcall TVersionInfoCompanyNameLabel(TComponent* Owner);
};

//---------------------------------------------------------------------------

class PACKAGE TVersionInfoFileDescriptionLabel : public TCustomVersionInfoLabel
{
  private:
    typedef TCustomVersionInfoLabel inherited;

  protected:
    virtual System::AnsiString __fastcall GetVersionLabelText();

  public:
    __fastcall TVersionInfoFileDescriptionLabel(TComponent* Owner);
};

//---------------------------------------------------------------------------

class PACKAGE TVersionInfoFileVersionLabel : public TCustomVersionInfoLabel
{
  private:
    typedef TCustomVersionInfoLabel inherited;

  protected:
    virtual System::AnsiString __fastcall GetVersionLabelText();

  public:
    __fastcall TVersionInfoFileVersionLabel(TComponent* Owner);
};

//---------------------------------------------------------------------------

class PACKAGE TVersionInfoInternalNameLabel : public TCustomVersionInfoLabel
{
  private:
    typedef TCustomVersionInfoLabel inherited;

  protected:
    virtual System::AnsiString __fastcall GetVersionLabelText();

  public:
    __fastcall TVersionInfoInternalNameLabel(TComponent* Owner);
};

//---------------------------------------------------------------------------

class PACKAGE TVersionInfoLegalCopyrightLabel : public TCustomVersionInfoLabel
{
  private:
    typedef TCustomVersionInfoLabel inherited;

  protected:
    virtual System::AnsiString __fastcall GetVersionLabelText();

  public:
    __fastcall TVersionInfoLegalCopyrightLabel(TComponent* Owner);
};

//---------------------------------------------------------------------------

class PACKAGE TVersionInfoLegalTrademarksLabel : public TCustomVersionInfoLabel
{
  private:
    typedef TCustomVersionInfoLabel inherited;

  protected:
    virtual System::AnsiString __fastcall GetVersionLabelText();

  public:
    __fastcall TVersionInfoLegalTrademarksLabel(TComponent* Owner);
};

//---------------------------------------------------------------------------

class PACKAGE TVersionInfoOriginalFileNameLabel : public TCustomVersionInfoLabel
{
  private:
    typedef TCustomVersionInfoLabel inherited;

  protected:
    virtual System::AnsiString __fastcall GetVersionLabelText();

  public:
    __fastcall TVersionInfoOriginalFileNameLabel(TComponent* Owner);
};

//---------------------------------------------------------------------------

class PACKAGE TVersionInfoProductNameLabel : public TCustomVersionInfoLabel
{
  private:
    typedef TCustomVersionInfoLabel inherited;

  protected:
    virtual System::AnsiString __fastcall GetVersionLabelText();

  public:
    __fastcall TVersionInfoProductNameLabel(TComponent* Owner);
};

//---------------------------------------------------------------------------

class PACKAGE TVersionInfoProductVersionLabel : public TCustomVersionInfoLabel
{
  private:
    typedef TCustomVersionInfoLabel inherited;

  protected:
    virtual System::AnsiString __fastcall GetVersionLabelText();

  public:
    __fastcall TVersionInfoProductVersionLabel(TComponent* Owner);
};

#endif
