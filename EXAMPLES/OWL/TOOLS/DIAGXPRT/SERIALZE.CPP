//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1995, 1995 by Borland International, All Rights Reserved
//
// Implements TSerializer, TSerializeReceiver
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include "serialze.h"

//
// Breaks down the data into blocks and sends each block to the window via SendMessage.
// wParam of the SendMessage is of type BlockType which signifies what
// lParam contains.
//
TSerializer::TSerializer(HWND hwndTarget, uint32 length, void* data)
{
  if (!::IsWindow(hwndTarget) || length == 0)
    return;
  uint msg = ::RegisterWindowMessage(SerializerMessage);

  ::SendMessage(hwndTarget, msg, Begin, length);

  // send blocks 4 at a time
  //
  uint32* dataBlocks = (uint32*)data;
  while (length > 3) {
    ::SendMessage(hwndTarget, msg, Data4, *dataBlocks);
    dataBlocks += 1;
    length -= 4;
  }

  // block was an even multiple of 4
  //
  if (length == 0)
    return;

  // length must be either 1, 2, or 3
  //
  unsigned char* dataBytes = (unsigned char*)dataBlocks;
  uint32 finalBlock = 0;

  if (length == 3)
    finalBlock += 0x100L * dataBytes[2];

  if (length >= 2)
    finalBlock += 0x10000L * dataBytes[1];

  finalBlock += 0x1000000L * dataBytes[0];

  ::SendMessage(hwndTarget, msg, length, finalBlock);
  ::SendMessage(hwndTarget, msg, End, 0);
}


//
// Constructor
//
TSerializeReceiver::TSerializeReceiver()
:
  TEventHandler(), Length(0), Data(0), CurPtr(0)
{
}

//
// Automatically put the data blocks back together.
//
int32
TSerializeReceiver::BlockReceived(uint wParam, int32 lParam)
{
  switch (wParam) {
    case TSerializer::Begin: {
      Length = lParam;
      Data = new HUGE char[Length+1];
      CurPtr = Data;
      return 0;
    }

    case TSerializer::End: {
      DataReceived(Length, Data);
      delete[] Data;
      Data = 0;
      return 0;
    }

    case TSerializer::Data4: {
      uint32* ptr = (uint32*)CurPtr;
      *ptr = lParam;
      CurPtr += 4;
      return 0;
    }

    case TSerializer::Data1:
    case TSerializer::Data2:
    case TSerializer::Data3:
      break;

    default: // ignored, unknown BlockType
      return 0;
  }

  *CurPtr++ = (char)HIBYTE(HIWORD(lParam));

  if (wParam >= TSerializer::Data2)
    *CurPtr++ = (char)LOBYTE(HIWORD(lParam));

  if (wParam == TSerializer::Data3)
    *CurPtr++ = (char)HIBYTE(LOWORD(lParam));

  *CurPtr++ = 0;

  return 0;
}

void
TSerializeReceiver::DataReceived(uint32 length, void* data)
{

}

DEFINE_RESPONSE_TABLE1(TSerializeReceiver, TEventHandler)
  EV_REGISTERED(SerializerMessage, BlockReceived),
END_RESPONSE_TABLE;
