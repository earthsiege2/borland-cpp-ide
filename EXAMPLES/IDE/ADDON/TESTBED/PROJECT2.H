#ifndef __PROJECT2_H_
#define __PROJECT2_H_

#include <ideaddon\iproj.h>

#include "tests.h"

/*-----------------------------------------------------------------------*/

class ProjectTestB : public TestObject
{
    public:
       ProjectTestB();
       ~ProjectTestB();

       //TestObject Interface implementation
       virtual BOOL Init();
       virtual void UnInit();
       virtual const char* GetName();
       virtual const char* GetTestDescription(int testNum);
       virtual void DoTest(int testNum);

    protected:   
       void MoveNode();
       void CopyNode();
       void SwapTranslator();
       void MarkDirty();

       IProjectServer3* prjServer;
};


/*-----------------------------------------------------------------------*/


#endif // __PROJECT2_H_
