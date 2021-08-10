#ifndef __MSGTEST2_H_
#define __MSGTEST2_H_


#include "tests.h"


class MsgTest : public TestObject
{
   public:
     MsgTest();
     ~MsgTest();

     //TestObject Interface implementation
     virtual BOOL Init();
     virtual void UnInit();
     virtual const char* GetName();
     virtual const char* GetTestDescription(int testNum);
     virtual void DoTest(int testNum);

   protected: 
     IMessageFolder* folder;
     IMessageFolder2* folder2;
     HMSGITEM parentMsg;
};


#endif // __MSGTEST2_H_
