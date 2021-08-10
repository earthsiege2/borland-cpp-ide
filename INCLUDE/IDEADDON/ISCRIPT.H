/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

	iscript.h
	Created: 10/13/95
	Copyright (c) 1995, Borland International
	$Header:   Y:\admin\bride\addon\deliver\interfac\iscript.h_v   1.19   18 Nov 1996 11:29:58   JDOUGLAS  $
	$Revision:   1.19  $

	ScriptServer Interface 
   Using this interface you can install scripts, call functions written in
   script (yours or the ide's) and have access to the ide's scriptable
   class objects.
    
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/	

#ifndef __ISCRIPT_H
#define __ISCRIPT_H

#include <windows.h>
#include <objbase.h>
#include <ideaddon\ipolystr.h>
#include <ideaddon\iscript.uid>
#include <ideaddon\common.h>


//.............................................................................
// 
// Warning! Do not attempt to issue any script commands in anything but the 
// main UI thread. Currently, the addon wrapper dll does not protect you from
// doing this, but script methods will generally leave the IDE in a 
// crippled state when run from another thread. 
// 
// The most common place that  you would be tempted to do this is if you have
// installed a translator tool that has registered an IToolImplementor 
// interface. If the user has put the IDE in async mode, your 
// IToolImplementor::Execute() method will be called in a seperate make thread.
// Do not try to call through the IScriptServer from within this thread. 
// 
// Note regarding all 'scriptName' arguments: Scripts, by convention have
// the extension .spp and are compiled into token files with the extension
// .spx. When calling the RunScriptFile, ScheduleScriptFile or UnloadScriptFile
//  methods, omitting the extension will cause the script engine to only 
// re-compile the .spp if the .spx is missing or out-of-date with regards to
// its .spp counterpart. However, if you add the .spp extension, the file will
// always be re-compiled, which is usually undesirable on account of the time
// involved. If you need to call UnloadScriptFile, use the same name string you 
// used to Run or Schedule it.
//.............................................................................


class IScriptServer : public IUnknown {
 public:
	//
	//	Run a script file, supplying the script path/name. The script classes and 
	// methods will be accessible until the script is unloaded.
   //
	virtual void BCWADDON_CMETHOD RunScriptFile( IPolyString * scriptName ) = 0;
	//
	//	Schedule a script file at startup time to be run as soon as the IDE
	// reaches its first idle state. This will have no effect unless called
	// when your addon is first loaded.
	//
	virtual void BCWADDON_CMETHOD ScheduleScriptFile( IPolyString * scriptName ) = 0;
	//
	//	Unload a scrip file by its path/name
	//
	virtual void BCWADDON_CMETHOD UnloadScriptFile( IPolyString * scriptName ) = 0;
	//
	//	Run a script command, this can access any class or method
	// currently loaded by the IDE. To get the return value, preceed
   // the script command with "return", e.g. "return MyFunc();"
	// The return value is stored as a string (in scriptReturn) and is 
	// also returned as an int value.
   // 
   // WARNING: Avoid running script commands when inside a transfer tool 
   // callback, since this will be in a different thread if the user
   // has selected selects Async mode, and the script engine doesn't 
   // handle this properly yet. The end result of violating this rule
   // is unpredictable, but usually fatal in one way or another.
	//
	virtual int BCWADDON_CMETHOD RunScriptCommand( IPolyString * scriptCommand, 
											IPolyString * scriptReturn  = NULL ) = 0;
};	


#endif 		//  __ISCRIPT_H
