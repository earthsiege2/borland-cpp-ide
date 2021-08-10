//----------------------------------------------------------------------------
#ifndef ClxEmployeeH
#define ClxEmployeeH
//----------------------------------------------------------------------------
#include <Classes.hpp>
#include <SysUtils.hpp>
#include <Windows.hpp>
#include <System.hpp>
#include <QGraphics.hpp>
#include <QForms.hpp>
#include <QControls.hpp>
#include <QStdCtrls.hpp>
#include <QButtons.hpp>
#include <QExtCtrls.hpp>
//----------------------------------------------------------------------------
class TEmployeeDM : public TDataModule
{
__published:
    TDataSource *employeesource;
    TSQLConnection *employeeconnection;
    TSQLQuery *Employeequery;
    TClientDataSet *employeecds;
    TDataSetProvider *employeeprov;
private:
public:
	virtual __fastcall TEmployeeDM(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TEmployeeDM *EmployeeDM;
//----------------------------------------------------------------------------
#endif    