#ifndef __IDEUITST_H_
#define __IDEUITST_H_

#include <ideaddon\iideui.h>

#include "tests.h"



class IdeUITest : public TestObject
{
    public:
      IdeUITest();
      ~IdeUITest();

      //TestObject Interface implementation
      virtual BOOL Init();
      virtual void UnInit();
      virtual const char* GetName();
      virtual const char* GetTestDescription(int testNum);
      virtual void DoTest(int testNum);

    protected:   
      void RunMessageBoxes();
      
      IIdeUI* ideui;
};


#endif // __IDEUITST_H_