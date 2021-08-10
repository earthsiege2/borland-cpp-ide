                 Custom COM interfaces using OCF
                 ===============================
The MAKEFILE or .IDE file int this directory create a Dynamic
Link Library (DLL) which exposes OLE custom COM interfaces and
an executable (EXE) which exercises the interfaces. The files
created are:

    CUSTCOM.DLL:    DLL implementing custom COM interfaces
    USECOM.EXE:     EXE which exercises the interfaces

The CUSTCOM.CPP file illustrates how one can use OCF macros and
its TUnknown class to implement a C++ object which exposes one
or more custom COM interfaces. The macros and TUnknown class
handle reference counting and implement the IUnknown members
(AddRef, Release and QueryInterface) allowing you to only worry
about implementing the 'actual' methods exposed by your custom
interface.

USECOM.CPP shows how one can obtain a pointer to the custom COM
interfaces:

(a) You may create an instance from scratch by retrieving the
class factory and asking the latter to 'manufacture' the desired
interface. [see CreateFromScrach() in USECOM.CPP]

(b) If you already have a pointer to one interface, you can
simply use the 'QueryInterface' API to obtain a pointer to
another interface since the OCF TUknown class automatically
'wires' all the interfaces exposed by your C++ object. [see the
OnCommand() handler of the frame window in USECOM.CPP].


MORE INFORMATION:  This example illustrates a case when the DLL
implements one C++ object which exposes multiple OLE interfaces.
With this setup, you can take advantage of OCF's default
'IClassFactory' implementation and only provide a
factory callback function [see ObjectFactoryCallback() in
CUSTCOM.CPP]. This rele
