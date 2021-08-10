//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1995, 1995 by Borland International, All Rights Reserved
//
//   Definition of TSerializer class
//----------------------------------------------------------------------------
#if !defined(OWL_SERIALZE_H)
#define OWL_SERIALZE_H

#if !defined(OWL_OWLDEFS_H)
# include <owl/owldefs.h>
#endif

#if !defined(OWL_EVENTHAN_H)
# include <owl/eventhan.h>
#endif

//
// class TSerializer
// ~~~~~ ~~~~~~~~~~~
// This class sends a block of data to another window.
//
class _OWLCLASS TSerializer {
  public:
    enum BlockType {
      End = 0,    // end of data, lParam == 0
      Data1,      // lParam data
      Data2,      // lParam data
      Data3,      // lParam data
      Data4,      // lParam data
      Begin,      // beginning of data, lParam length of data
    };
    TSerializer(HWND hwndTarget, uint32 length, void* data);
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
    virtual void DataReceived(uint32 length, void* data);

  protected:
    int32 BlockReceived(uint, int32);

  private:
    char HUGE* Data;
    char HUGE* CurPtr;
    uint32 Length;

  DECLARE_RESPONSE_TABLE(TSerializeReceiver);
};



#endif //OWL_SERIALZE_H
