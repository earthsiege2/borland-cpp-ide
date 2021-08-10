[!outputon]
[!set(SOAP, "TRUE")]
[!if=(Comments, "TRUE")]
// ************************************************************************ //
// Invokable interface declaration header for [!InterfaceName]
// ************************************************************************ //
[!endif]
#ifndef   [!IntfFileName]H
#define   [!IntfFileName]H

#include <System.hpp>
#include <InvokeRegistry.hpp>
#include <XSBuiltIns.hpp>
#include <Types.hpp>

[!if=(Samples, "TRUE")]
[!if=(Comments, "TRUE")]
// ************************************************************************ //
//  Enums exposed via SOAP must be byte-aligned
// ************************************************************************ //
[!endif]
#pragma option -b-
enum SampleEnum
{
  etNone,
  etAFew,
  etSome,
  etALot
};
#pragma option -b.

[!if=(Comments, "TRUE")]
// ************************************************************************ //
//  To expose complex types via SOAP, the type must derive from TRemotable
//  All published members of the type will be exposed.
// ************************************************************************ //
[!endif]
class TSampleStruct : public TRemotable {
private:
  AnsiString         FLastName;
  AnsiString         FFirstName;
  double             FSalary;
__published:
  __property AnsiString    LastName = { read=FLastName, write=FLastName };
  __property AnsiString    FirstName = { read=FFirstName, write=FFirstName };
  __property double        Salary = { read=FSalary, write=FSalary };
};

[!if=(Comments, "TRUE")]
// ************************************************************************ //
//  Remotable arrays must be Dynamic arrays since they must be discoverable
//  at runtime.
// ************************************************************************ //
[!endif]
typedef DynamicArray<double>  TDoubleArray;
[!endif]


[!if=(Comments, "TRUE")]
// ************************************************************************ //
//  Invokable interfaces must derive from IInvokable
//  The methods of the interface will be exposed via SOAP
// ************************************************************************ //
[!endif]
__interface INTERFACE_UUID("[!GuidString]") I[!InterfaceName] : public IInvokable
{
public:
[!if=(Samples, "TRUE")]
    virtual SampleEnum     echoEnum(SampleEnum eValue) = 0;
    virtual TDoubleArray   echoDoubleArray(const TDoubleArray daValue) = 0;
    virtual TSampleStruct* echoStruct(const TSampleStruct* pEmployee) = 0;
    virtual double         echoDouble(double dValue) = 0;
[!endif]
};
typedef DelphiInterface<I[!InterfaceName]> _di_I[!InterfaceName];


#endif // [!IntfFileName]H
//---------------------------------------------------------------------------


