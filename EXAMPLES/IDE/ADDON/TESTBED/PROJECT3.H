#ifndef __PROJECT3_H_
#define __PROJECT3_H_

#include <ideaddon\iproj.h>

#include "tests.h"


/*-----------------------------------------------------------------------*/

class MyProjClient : public IUnknownImp< IProjectClient > 
{
    public:
        MyProjClient() : IUNKNOWNIMPL_INIT( IProjectClient )
        {} 

        //IProjectClient implementation
        virtual void OpenNotify(IPolyString* projectName) {}
        virtual void CloseNotify() {}
        virtual void NodeDeleteNotify(ProjectNode node) {}
        virtual void NodeAddNotify(ProjectNode node) {}
        virtual void NodeMoveNotify(ProjectNode node, ProjectNode oldParent) {}
        virtual void NodeChangeNotify(ProjectNode node) {}
        virtual void NodeCopyNotify(ProjectNode newNode, 
                                    ProjectNode newParent, BOOL reference) {}
        virtual BOOL HandleAddNodeUI() { return FALSE; }
        
        virtual void DependencyQueryResponder(ProjectNode node, 
                                              IPolyString* outputName);
        
    protected:
};

/*-----------------------------------------------------------------------*/

class ProjectTestC : public TestObject
{
    public:
       ProjectTestC();
       ~ProjectTestC();

       //TestObject Interface implementation
       virtual BOOL Init();
       virtual void UnInit();
       virtual const char* GetName();
       virtual const char* GetTestDescription(int testNum);
       virtual void DoTest(int testNum);

    protected:   
       void ShowDeps();
    
       IProjectServer3* prjServer;
       MyProjClient* prjClient;
};


/*-----------------------------------------------------------------------*/


#endif // __PROJECT3_H_
