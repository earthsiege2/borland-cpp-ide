//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.4  $
//
// Definition of TSerializer class
//----------------------------------------------------------------------------
#if !defined(OWL_SERIALZE_H)
#define OWL_SERIALZE_H

#if !defined(OWL_DEFS_H)
# include <owl/defs.h>
#endif
#if !defined(OWL_EVENTHAN_H)
# include <owl/eventhan.h>
#endif

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TSerializer
// ~~~~~ ~~~~~~~~~~~
// This class sends a block of data to another window.
//
class _OWLCLASS TSerializer {
  public:
    // Enum for different types of blocks sent from a window to
    // another. This enum is sent as the wParam.
    //
    enum TBlock {
      End = 0,    // end of data, lParam == 0
      Data1,      // data is stored in bits 0x000000FF of lParam
      Data2,      // data is stored in bits 0x0000FFFF of lParam
      Data3,      // data is stored in bits 0x00FFFFFF of lParam
      Data4,      // data is stored in bits 0xFFFFFFFF of lParam
      Begin,      // beginning of data, lParam length of data
    };
    TSerializer(HWND hwndTarget, uint32 length, void far* data);
};

//
// Serializer window targets should catch the following registered message
// to receive the block of data.
//
#define SerializerMessage "SERIALIZERMESSAGE"

//
// class TSerializeReceiver
// ~~~~~ ~~~~~~~~~~~~~~~~~~
// Mix-in class that automatically puts together the block of data sent by
// TSerializer.
//
class _OWLCLASS TSerializeReceiver : virtual public TEventHandler {
  public:
    TSerializeReceiver();

    // Derived classes should override this function to copy the received data.
    // passed to it.
    //
    virtual void DataReceived(uint32 length, void far* data);

  protected:
    int32 BlockReceived(TParam1, TParam2);

  private:
    char HUGE* Data;
    char HUGE* CurPtr;
    uint32 Length;

  DECLARE_RESPONSE_TABLE(TSerializeReceiver);
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

#endif  // OWL_SERIALZE_H
