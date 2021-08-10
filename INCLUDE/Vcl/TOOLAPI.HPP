// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ToolsAPI.pas' rev: 6.00

#ifndef ToolsAPIHPP
#define ToolsAPIHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ComCtrls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <ImgList.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <ActnList.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <TypInfo.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
DEFINE_GUID(IID_IBorlandIDEServices,0x7FD1CE92,0xE053,0x11D1,0xAB,0x0B,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_INTAComponent,0x34B2E2D1,0xE36F,0x11D1,0xAB,0x0E,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_INTACustomDrawMessage,0x589BBDA2,0xF995,0x11D1,0xAB,0x27,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTACustomMessage50,0xB7523AB7,0xEB81,0x11D2,0xAC,0x7B,0x00,0xC0,0x4F,0xB1,0x73,0xDC);
DEFINE_GUID(IID_IOTACustomMessage,0x589BBDA1,0xF995,0x11D1,0xAB,0x27,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_INTAFormEditor,0x56931EB9,0x329A,0xD411,0x87,0xC6,0x9B,0x27,0x30,0x41,0x22,0x00);
DEFINE_GUID(IID_INTAServices,0xC17B3DF1,0xDFE5,0x11D2,0xA8,0xC7,0x00,0xC0,0x4F,0xA3,0x2F,0x53);
DEFINE_GUID(IID_INTAServices40,0x3C7F3267,0xF0BF,0x11D1,0xAB,0x1E,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_INTAToDoItem,0x094003D8,0xE7AA,0x11D2,0xAA,0x99,0x00,0xC0,0x4F,0xA3,0x5C,0xE8);
DEFINE_GUID(IID_INTAUnknown,0x8CC6430B,0xE721,0x11D2,0xA8,0xCC,0x00,0xC0,0x4F,0xA3,0x2F,0x53);
DEFINE_GUID(IID_IOTAActionServices,0xF17A7BC9,0xE07D,0x11D1,0xAB,0x0B,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAAddressBreakpoint,0x09063878,0xE43A,0x11D1,0xAB,0x0F,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTABreakpoint,0x569EFCFB,0xC69B,0x11D2,0xAC,0x67,0x00,0xC0,0x4F,0xB1,0x73,0xDC);
DEFINE_GUID(IID_IOTABreakpoint40,0x34B2E2D4,0xE36F,0x11D1,0xAB,0x0E,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTABreakpointNotifier,0x34B2E2D5,0xE36F,0x11D1,0xAB,0x0E,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTABufferOptions,0x8C748540,0xC6C1,0x11D2,0x81,0x39,0x00,0x60,0x97,0x92,0xF1,0x34);
DEFINE_GUID(IID_IOTACodeInsightServices,0x476904F8,0x89A9,0x4CD8,0xA7,0x1E,0x16,0x46,0x60,0x65,0x97,0x63);
DEFINE_GUID(IID_IOTAComponent,0xAC139ADF,0x329A,0xD411,0x87,0xC6,0x9B,0x27,0x30,0x41,0x22,0x00);
DEFINE_GUID(IID_IOTACreator,0x6EDB9B9E,0xF57A,0x11D1,0xAB,0x23,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_INTACustomDrawCodeInsightViewer,0x32CA7B43,0x9AFC,0x49CF,0xAB,0xC9,0x7E,0xCD,0x77,0x24,0x88,0xD9);
DEFINE_GUID(IID_IOTADebuggerNotifier,0x34B2E2D8,0xE36F,0x11D1,0xAB,0x0E,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTADebuggerServices,0x0E3B9D7A,0xE119,0x11D1,0xAB,0x0C,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAEditActions,0xECB23623,0xE2D8,0x11D2,0xAB,0xE5,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAEditBlock,0x9C510463,0xC7BC,0x11D2,0x9A,0xEB,0x00,0xA0,0x24,0x57,0x62,0x1F);
DEFINE_GUID(IID_IOTAEditBuffer,0x9C510460,0xC7BC,0x11D2,0x9A,0xEB,0x00,0xA0,0x24,0x57,0x62,0x1F);
DEFINE_GUID(IID_IOTAEditBufferIterator,0x8ECB33AA,0xD0BD,0x11D2,0xAB,0xD6,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAEditLineNotifier,0xD9D48F50,0xE6CC,0x11D2,0xAB,0xE8,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAEditLineTracker,0xD9D48F4F,0xE6CC,0x11D2,0xAB,0xE8,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAEditOptions,0x487BEA91,0xDBC0,0x11D2,0xAB,0xDE,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAEditor,0xF17A7BD0,0xE07D,0x11D1,0xAB,0x0B,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAEditorNotifier,0x0E3B9D7B,0xE119,0x11D1,0xAB,0x0C,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAEditorServices,0xC2812BA7,0xC48D,0x11D2,0x9A,0xE8,0x00,0xA0,0x24,0x57,0x62,0x1F);
DEFINE_GUID(IID_IOTAEditPosition,0x9C510464,0xC7BC,0x11D2,0x9A,0xEB,0x00,0xA0,0x24,0x57,0x62,0x1F);
DEFINE_GUID(IID_IOTAEditReader,0x26EB0E4F,0xF97B,0x11D1,0xAB,0x27,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAEditView,0x9C510462,0xC7BC,0x11D2,0x9A,0xEB,0x00,0xA0,0x24,0x57,0x62,0x1F);
DEFINE_GUID(IID_IOTAEditView40,0x0E3B9D78,0xE119,0x11D1,0xAB,0x0C,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAEditWriter,0x26EB0E50,0xF97B,0x11D1,0xAB,0x27,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAEnvironmentOptions,0x9C0E91FB,0xFA5A,0x11D1,0xAB,0x28,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAFile,0x6E2AD9B0,0xF7F0,0x11D1,0xAB,0x26,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAFileSystem,0xA9D1389D,0xF4B0,0x11D1,0xAB,0x22,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAFormEditor,0xF17A7BD2,0xE07D,0x11D1,0xAB,0x0B,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAFormNotifier,0x0E3B9D7C,0xE119,0x11D1,0xAB,0x0C,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAFormWizard,0x36C8BF35,0xEFFE,0x11D1,0xAB,0x1D,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAIDENotifier,0xE052204F,0xECE9,0x11D1,0xAB,0x19,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAIDENotifier50,0xAC7D29F1,0xD9A9,0x11D2,0xA8,0xC1,0x00,0xC0,0x4F,0xA3,0x2F,0x53);
DEFINE_GUID(IID_IOTAKeyBindingServices,0xF8CAF8D8,0xD263,0x11D2,0xAB,0xD8,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAKeyboardBinding,0xF8CAF8D7,0xD263,0x11D2,0xAB,0xD8,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAKeyboardServices,0xF8CAF8D5,0xD263,0x11D2,0xAB,0xD8,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAKeyboardDiagnostics,0xAEFC65F1,0x2504,0x11D3,0xAC,0x25,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAKeyContext,0x3E7790CB,0xD2BB,0x11D2,0xAB,0xD8,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTACodeInsightManager,0xBA5B444A,0x6E78,0x4A79,0xBF,0x05,0xE1,0x84,0xC1,0x13,0x2B,0x30);
DEFINE_GUID(IID_IOTACodeInsightParameterList,0x99B6A644,0x3E97,0x48A1,0x97,0x58,0x0A,0x5F,0xE9,0x47,0x67,0xC7);
DEFINE_GUID(IID_IOTACodeInsightParamQuery,0xB1842926,0xC7F7,0x4869,0xB5,0x5A,0xCF,0xDB,0x6B,0xF7,0x05,0xB5);
DEFINE_GUID(IID_IOTACodeInsightSymbolList,0x4CA1CDFD,0xBD9A,0x4628,0x94,0xAE,0x9B,0xF3,0xEB,0x2D,0xA2,0x2E);
DEFINE_GUID(IID_IOTACodeInsightViewer,0xAAA55FAC,0x350E,0x4F43,0x9C,0x42,0x4F,0xC2,0x8B,0x6B,0xFE,0x33);
DEFINE_GUID(IID_IOTACodeInsightViewerCanvas,0x8C60AB99,0x5BDB,0x44EE,0xB5,0xC8,0x33,0xCB,0x43,0x69,0x0D,0xF2);
DEFINE_GUID(IID_IOTAMenuWizard,0xB75C0CE2,0xEEA6,0x11D1,0x95,0x04,0x00,0x60,0x8C,0xCB,0xF1,0x53);
DEFINE_GUID(IID_IOTAMessageServices40,0x26EB0E4E,0xF97B,0x11D1,0xAB,0x27,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAMessageServices50,0x3263774B,0xE959,0x11D2,0xAC,0x7B,0x00,0xC0,0x4F,0xB1,0x73,0xDC);
DEFINE_GUID(IID_IOTAMessageGroup,0x233F4508,0x6022,0x4DDF,0xB6,0xD3,0xD2,0x10,0x8B,0xAf,0x80,0xDB);
DEFINE_GUID(IID_IOTAMessageNotifier,0xFDCB2ED4,0xB89C,0x4D00,0xB0,0xDB,0x19,0x56,0x29,0x51,0xCD,0xBB);
DEFINE_GUID(IID_IOTAMessageServices,0x58A40C76,0x7EC6,0x41DA,0xA2,0xEF,0x4B,0x3A,0xF3,0x1D,0x39,0x77);
DEFINE_GUID(IID_IOTAModule40,0xF17A7BCC,0xE07D,0x11D1,0xAB,0x0B,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAModule50,0x15D3FB81,0xEF27,0x488E,0xB2,0xB4,0x26,0xB5,0x9C,0xA8,0x9D,0x9D);
DEFINE_GUID(IID_IOTAModule,0x2438BFB8,0xC742,0x48CD,0x8F,0x50,0xDE,0x6C,0x7F,0x76,0x4A,0x55);
DEFINE_GUID(IID_IOTAModuleCreator,0x6EDB9B9A,0xF57A,0x11D1,0xAB,0x23,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAModuleInfo50,0xF17A7BD6,0xE07D,0x11D1,0xAB,0x0B,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAModuleInfo,0xB3EEB4D2,0xECDD,0x4CDC,0xB9,0x6E,0xB5,0xC8,0xF6,0xD0,0x50,0xA8);
DEFINE_GUID(IID_IOTAModuleNotifier,0xF17A7BCE,0xE07D,0x11D1,0xAB,0x0B,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAModuleServices,0xF17A7BCD,0xE07D,0x11D1,0xAB,0x0B,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTANotifier,0xF17A7BCF,0xE07D,0x11D1,0xAB,0x0B,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAOptions,0x9C0E91FC,0xFA5A,0x11D1,0xAB,0x28,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAPackageServices,0x26EB0E4D,0xF97B,0x11D1,0xAB,0x27,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAProcess,0x34B2E2D2,0xE36F,0x11D1,0xAB,0x0E,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAProcessModNotifier,0x0906387A,0xE43A,0x11D1,0xAB,0x0F,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAProcessModule,0x09063879,0xE43A,0x11D1,0xAB,0x0F,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAProcessNotifier,0x34B2E2D6,0xE36F,0x11D1,0xAB,0x0E,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAProject,0xF17A7BCA,0xE07D,0x11D1,0xAB,0x0B,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAProjectBuilder,0x08A5B1F5,0xFCDA,0x11D2,0xAC,0x82,0x00,0xC0,0x4F,0xB1,0x73,0xDC);
DEFINE_GUID(IID_IOTAProjectBuilder40,0xF17A7BD5,0xE07D,0x11D1,0xAB,0x0B,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAProjectCreator,0x6EDB9B9D,0xF57A,0x11D1,0xAB,0x23,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAProjectCreator50,0x64312F82,0x62F3,0x48E9,0xBA,0xF6,0xB0,0x3D,0xF4,0x50,0x31,0x2A);
DEFINE_GUID(IID_IOTAProjectGroup,0xF17A7BCB,0xE07D,0x11D1,0xAB,0x0B,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAProjectGroupCreator,0x6EDB9B9F,0xF57A,0x11D1,0xAB,0x23,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAProjectOptions,0xF899EBC6,0xE6E2,0x11D2,0xAA,0x90,0x00,0xC0,0x4F,0xA3,0x70,0xE9);
DEFINE_GUID(IID_IOTAProjectOptions40,0xF17A7BD4,0xE07D,0x11D1,0xAB,0x0B,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAProjectResource,0x26EB0E52,0xF97B,0x11D1,0xAB,0x27,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAProjectWizard,0x36C8BF36,0xEFFE,0x11D1,0xAB,0x1D,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTARecord,0xF8CAF8D6,0xD263,0x11D2,0xAB,0xD8,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAReplaceOptions,0xD1766F8C,0xD915,0x11D2,0xA8,0xC1,0x00,0xC0,0x4F,0xA3,0x2F,0x53);
DEFINE_GUID(IID_IOTARepositoryWizard,0xB75C0CE1,0xEEA6,0x11D1,0x95,0x04,0x00,0x60,0x8C,0xCB,0xF1,0x53);
DEFINE_GUID(IID_IOTARepositoryWizard60,0x08FCCD88,0x3A21,0x4281,0xAD,0xC9,0x62,0xFC,0x03,0x4C,0xDD,0x12);
DEFINE_GUID(IID_IOTAResourceEntry,0x26EB0E51,0xF97B,0x11D1,0xAB,0x27,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTASearchOptions,0xD1766F8B,0xD915,0x11D2,0xA8,0xC1,0x00,0xC0,0x4F,0xA3,0x2F,0x53);
DEFINE_GUID(IID_IOTAServices50,0x7FD1CE91,0xE053,0x11D1,0xAB,0x0B,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAServices,0x577ECE00,0x59EE,0x4F21,0x81,0x90,0x9F,0xD8,0xA4,0x5F,0xE5,0x50);
DEFINE_GUID(IID_IOTASourceBreakpoint,0x09063877,0xE43A,0x11D1,0xAB,0x0F,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTASourceEditor,0xF17A7BD1,0xE07D,0x11D1,0xAB,0x0B,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTASpeedSetting,0xB5CDCE07,0xE093,0x11D2,0xAB,0xE2,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAThread,0x34B2E2D3,0xE36F,0x11D1,0xAB,0x0E,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAThreadNotifier,0x34B2E2D7,0xE36F,0x11D1,0xAB,0x0E,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAToDoManager,0x3D4A0565,0xEB77,0x11D2,0xAA,0x9A,0x00,0xC0,0x4F,0xA3,0x5C,0xE8);
DEFINE_GUID(IID_IOTAToDoServices,0xF8FC00EF,0xE61A,0x11D2,0xAA,0x99,0x00,0xC0,0x4F,0xA3,0x5C,0xE8);
DEFINE_GUID(IID_IOTAToolsFilterNotifier,0xCEF1F13A,0xE877,0x4F20,0x88,0xF2,0xF7,0xE2,0xBA,0x61,0xAA,0xF4); 
DEFINE_GUID(IID_IOTAToolsFilter,0x8864B891,0x9B6D,0x4002,0xBB,0x2E,0x1D,0x6E,0x59,0xBF,0xA4,0x9A); 
DEFINE_GUID(IID_IOTATypeLibEditor,0xF17A7BD3,0xE07D,0x11D1,0xAB,0x0B,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTATypeLibModule,0x0BBAEEA0,0xEF74,0x11D1,0xAB,0x1C,0x00,0xC0,0x4F,0xB1,0x6F,0xB3);
DEFINE_GUID(IID_IOTAWizard,0xB75C0CE0,0xEEA6,0x11D1,0x95,0x04,0x00,0x60,0x8C,0xCB,0xF1,0x53);
DEFINE_GUID(IID_IOTAWizardServices,0xB75C0CE3,0xEEA6,0x11D1,0x95,0x04,0x00,0x60,0x8C,0xCB,0xF1,0x53);

namespace Toolsapi
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TOTACompileMode { cmOTAMake, cmOTABuild, cmOTACheck, cmOTAMakeUnit };
#pragma option pop

typedef int TOTAModuleType;

typedef void *TOTAHandle;

typedef Shortint TOTAToDoPriority;

#pragma pack(push, 1)
struct TOTAEditPos
{
	short Col;
	int Line;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TOTACharPos
{
	short CharIndex;
	int Line;
} ;
#pragma pack(pop)

#pragma pack(push, 4)
struct TOTAOptionName
{
	AnsiString Name;
	Typinfo::TTypeKind Kind;
} ;
#pragma pack(pop)

typedef DynamicArray<TOTAOptionName >  TOTAOptionNameArray;

#pragma option push -b-
enum TBindingType { btComplete, btPartial };
#pragma option pop

#pragma option push -b-
enum TKeyBindingResult { krUnhandled, krHandled, krNextProc };
#pragma option pop

__interface IOTAKeyContext;
typedef System::DelphiInterface<IOTAKeyContext> _di_IOTAKeyContext;
typedef void __fastcall (__closure *TKeyBindingProc)(const _di_IOTAKeyContext Context, Classes::TShortCut KeyCode, TKeyBindingResult &BindingResult);

typedef Byte TMoveCursorMasks;

#pragma option push -b-
enum TSearchDirection { sdForward, sdBackward };
#pragma option pop

__interface IOTANotifier;
typedef System::DelphiInterface<IOTANotifier> _di_IOTANotifier;
__interface INTERFACE_UUID("{F17A7BCF-E07D-11D1-AB0B-00C04FB16FB3}") IOTANotifier  : public IInterface 
{
	
public:
	virtual void __fastcall AfterSave(void) = 0 ;
	virtual void __fastcall BeforeSave(void) = 0 ;
	virtual void __fastcall Destroyed(void) = 0 ;
	virtual void __fastcall Modified(void) = 0 ;
};

__interface IOTAEditorNotifier;
typedef System::DelphiInterface<IOTAEditorNotifier> _di_IOTAEditorNotifier;
__interface IOTAEditView;
typedef System::DelphiInterface<IOTAEditView> _di_IOTAEditView;
__interface INTERFACE_UUID("{0E3B9D7B-E119-11D1-AB0C-00C04FB16FB3}") IOTAEditorNotifier  : public IOTANotifier 
{
	
public:
	virtual void __fastcall ViewNotification(const _di_IOTAEditView View, Classes::TOperation Operation) = 0 ;
	virtual void __fastcall ViewActivated(const _di_IOTAEditView View) = 0 ;
};

__interface IOTAFormNotifier;
typedef System::DelphiInterface<IOTAFormNotifier> _di_IOTAFormNotifier;
__interface INTERFACE_UUID("{0E3B9D7C-E119-11D1-AB0C-00C04FB16FB3}") IOTAFormNotifier  : public IOTANotifier 
{
	
public:
	virtual void __fastcall FormActivated(void) = 0 ;
	virtual void __fastcall FormSaving(void) = 0 ;
	virtual void __fastcall ComponentRenamed(void * ComponentHandle, const AnsiString OldName, const AnsiString NewName) = 0 ;
};

__interface IOTAEditor;
typedef System::DelphiInterface<IOTAEditor> _di_IOTAEditor;
__interface IOTAModule;
typedef System::DelphiInterface<IOTAModule> _di_IOTAModule;
__interface INTERFACE_UUID("{F17A7BD0-E07D-11D1-AB0B-00C04FB16FB3}") IOTAEditor  : public IInterface 
{
	
public:
	virtual int __fastcall AddNotifier(const _di_IOTANotifier ANotifier) = 0 ;
	virtual AnsiString __fastcall GetFileName(void) = 0 ;
	virtual bool __fastcall GetModified(void) = 0 ;
	virtual _di_IOTAModule __fastcall GetModule(void) = 0 ;
	virtual bool __fastcall MarkModified(void) = 0 ;
	virtual void __fastcall RemoveNotifier(int Index) = 0 ;
	virtual void __fastcall Show(void) = 0 ;
	__property AnsiString FileName = {read=GetFileName};
	__property bool Modified = {read=GetModified};
	__property _di_IOTAModule Module = {read=GetModule};
};

__interface IOTAToolsFilterNotifier;
typedef System::DelphiInterface<IOTAToolsFilterNotifier> _di_IOTAToolsFilterNotifier;
__interface INTERFACE_UUID("{CEF1F13A-E877-4F20-88F2-F7E2BA61AAF4}") IOTAToolsFilterNotifier  : public IOTANotifier 
{
	
public:
	virtual void __fastcall Filter(AnsiString FileName, int ErrorCode, Classes::TStrings* StdOut, Classes::TStrings* StdError) = 0 ;
	virtual AnsiString __fastcall GetFilterName(void) = 0 ;
};

__interface IOTAToolsFilter;
typedef System::DelphiInterface<IOTAToolsFilter> _di_IOTAToolsFilter;
__interface INTERFACE_UUID("{8864B891-9B6D-4002-BB2E-1D6E59BFA49A}") IOTAToolsFilter  : public IInterface 
{
	
public:
	virtual int __fastcall AddNotifier(const _di_IOTANotifier ANotifier) = 0 ;
	virtual void __fastcall RemoveNotifier(int Index) = 0 ;
};

__interface IOTAEditReader;
typedef System::DelphiInterface<IOTAEditReader> _di_IOTAEditReader;
__interface INTERFACE_UUID("{26EB0E4F-F97B-11D1-AB27-00C04FB16FB3}") IOTAEditReader  : public IInterface 
{
	
public:
	virtual int __fastcall GetText(int Position, char * Buffer, int Count) = 0 ;
};

__interface IOTAEditWriter;
typedef System::DelphiInterface<IOTAEditWriter> _di_IOTAEditWriter;
__interface INTERFACE_UUID("{26EB0E50-F97B-11D1-AB27-00C04FB16FB3}") IOTAEditWriter  : public IInterface 
{
	
public:
	virtual void __fastcall CopyTo(int Pos) = 0 ;
	virtual void __fastcall DeleteTo(int Pos) = 0 ;
	virtual void __fastcall Insert(char * Text) = 0 ;
	virtual int __fastcall Position(void) = 0 ;
	virtual TOTACharPos __fastcall GetCurrentPos(void) = 0 ;
	__property TOTACharPos CurrentPos = {read=GetCurrentPos};
};

#pragma option push -b-
enum TOTASyntaxHighlighter { shNone, shQuery, shPascal, shC, shSQL, shIDL };
#pragma option pop

#pragma option push -b-
enum TOTABlockType { btInclusive, btLine, btColumn, btNonInclusive, btUnknown };
#pragma option pop

__interface IOTAEditView40;
typedef System::DelphiInterface<IOTAEditView40> _di_IOTAEditView40;
__interface INTERFACE_UUID("{0E3B9D78-E119-11D1-AB0C-00C04FB16FB3}") IOTAEditView40  : public IInterface 
{
	
public:
	virtual TOTAEditPos __fastcall GetCursorPos(void) = 0 ;
	virtual void __fastcall SetCursorPos(const TOTAEditPos &Value) = 0 ;
	virtual TOTAEditPos __fastcall GetTopPos(void) = 0 ;
	virtual void __fastcall SetTopPos(const TOTAEditPos &Value) = 0 ;
	virtual tagSIZE __fastcall GetViewSize(void) = 0 ;
	virtual TOTACharPos __fastcall PosToCharPos(int Pos) = 0 ;
	virtual int __fastcall CharPosToPos(const TOTACharPos &CharPos) = 0 ;
	virtual void __fastcall ConvertPos(bool EdPosToCharPos, TOTAEditPos &EditPos, TOTACharPos &CharPos) = 0 ;
	virtual void __fastcall GetAttributeAtPos(const TOTAEditPos &EdPos, bool IncludeMargin, int &Element, int &LineFlag) = 0 ;
	virtual bool __fastcall SameView(_di_IOTAEditView EditView) = 0 ;
	__property TOTAEditPos CursorPos = {read=GetCursorPos, write=SetCursorPos};
	__property TOTAEditPos TopPos = {read=GetTopPos, write=SetTopPos};
	__property tagSIZE ViewSize = {read=GetViewSize};
};

__interface IOTASearchOptions;
typedef System::DelphiInterface<IOTASearchOptions> _di_IOTASearchOptions;
__interface INTERFACE_UUID("{D1766F8B-D915-11D2-A8C1-00C04FA32F53}") IOTASearchOptions  : public IInterface 
{
	
public:
	virtual bool __fastcall GetCaseSensitive(void) = 0 ;
	virtual TSearchDirection __fastcall GetDirection(void) = 0 ;
	virtual bool __fastcall GetFromCursor(void) = 0 ;
	virtual bool __fastcall GetRegularExpression(void) = 0 ;
	virtual AnsiString __fastcall GetSearchText(void) = 0 ;
	virtual bool __fastcall GetWholeFile(void) = 0 ;
	virtual bool __fastcall GetWordBoundary(void) = 0 ;
	virtual void __fastcall SetCaseSensitive(bool Value) = 0 ;
	virtual void __fastcall SetDirection(TSearchDirection Value) = 0 ;
	virtual void __fastcall SetFromCursor(bool Value) = 0 ;
	virtual void __fastcall SetRegularExpression(bool Value) = 0 ;
	virtual void __fastcall SetSearchText(const AnsiString Value) = 0 ;
	virtual void __fastcall SetWholeFile(bool Value) = 0 ;
	virtual void __fastcall SetWordBoundary(bool Value) = 0 ;
	__property bool CaseSensitive = {read=GetCaseSensitive, write=SetCaseSensitive};
	__property TSearchDirection Direction = {read=GetDirection, write=SetDirection};
	__property bool FromCursor = {read=GetFromCursor, write=SetFromCursor};
	__property bool RegularExpression = {read=GetRegularExpression, write=SetRegularExpression};
	__property AnsiString SearchText = {read=GetSearchText, write=SetSearchText};
	__property bool WholeFile = {read=GetWholeFile, write=SetWholeFile};
	__property bool WordBoundary = {read=GetWordBoundary, write=SetWordBoundary};
};

__interface IOTAReplaceOptions;
typedef System::DelphiInterface<IOTAReplaceOptions> _di_IOTAReplaceOptions;
__interface INTERFACE_UUID("{D1766F8C-D915-11D2-A8C1-00C04FA32F53}") IOTAReplaceOptions  : public IOTASearchOptions 
{
	
public:
	virtual bool __fastcall GetPromptOnReplace(void) = 0 ;
	virtual bool __fastcall GetReplaceAll(void) = 0 ;
	virtual AnsiString __fastcall GetReplaceText(void) = 0 ;
	virtual void __fastcall SetPromptOnReplace(bool Value) = 0 ;
	virtual void __fastcall SetReplaceAll(bool Value) = 0 ;
	virtual void __fastcall SetReplaceText(const AnsiString Value) = 0 ;
	__property bool PromptOnReplace = {read=GetPromptOnReplace, write=SetPromptOnReplace};
	__property bool ReplaceAll = {read=GetReplaceAll, write=SetReplaceAll};
	__property AnsiString ReplaceText = {read=GetReplaceText, write=SetReplaceText};
};

__interface IOTAEditPosition;
typedef System::DelphiInterface<IOTAEditPosition> _di_IOTAEditPosition;
__interface IOTAEditBlock;
typedef System::DelphiInterface<IOTAEditBlock> _di_IOTAEditBlock;
__interface INTERFACE_UUID("{9C510464-C7BC-11D2-9AEB-00A02457621F}") IOTAEditPosition  : public IInterface 
{
	
public:
	virtual void __fastcall Align(int Magnitude) = 0 ;
	virtual bool __fastcall BackspaceDelete(int HowMany) = 0 ;
	virtual bool __fastcall Delete(int HowMany) = 0 ;
	virtual int __fastcall DistanceToTab(TSearchDirection Direction) = 0 ;
	virtual char __fastcall GetCharacter(void) = 0 ;
	virtual int __fastcall GetColumn(void) = 0 ;
	virtual bool __fastcall GetIsSpecialCharacter(void) = 0 ;
	virtual bool __fastcall GetIsWhitespace(void) = 0 ;
	virtual bool __fastcall GetIsWordCharacter(void) = 0 ;
	virtual int __fastcall GetLastRow(void) = 0 ;
	virtual _di_IOTAReplaceOptions __fastcall GetReplaceOptions(void) = 0 ;
	virtual int __fastcall GetRow(void) = 0 ;
	virtual AnsiString __fastcall GetSearchErrorString(int ErrorCode) = 0 ;
	virtual _di_IOTASearchOptions __fastcall GetSearchOptions(void) = 0 ;
	virtual bool __fastcall GotoLine(int LineNumber) = 0 ;
	virtual void __fastcall InsertBlock(const _di_IOTAEditBlock Block) = 0 ;
	virtual void __fastcall InsertCharacter(char Character) = 0 ;
	virtual void __fastcall InsertFile(const AnsiString FileName) = 0 ;
	virtual void __fastcall InsertText(const AnsiString Text) = 0 ;
	virtual bool __fastcall Move(int Row, int Col) = 0 ;
	virtual bool __fastcall MoveBOL(void) = 0 ;
	virtual bool __fastcall MoveCursor(Byte MoveMask) = 0 ;
	virtual bool __fastcall MoveEOF(void) = 0 ;
	virtual bool __fastcall MoveEOL(void) = 0 ;
	virtual bool __fastcall MoveReal(int Row, int Col) = 0 ;
	virtual bool __fastcall MoveRelative(int Row, int Col) = 0 ;
	virtual void __fastcall Paste(void) = 0 ;
	virtual AnsiString __fastcall Read(int NumberOfCharacters) = 0 ;
	virtual bool __fastcall RepeatLastSearchOrReplace(void) = 0 ;
	virtual int __fastcall Replace(const AnsiString Pattern, const AnsiString ReplaceText, bool CaseSensitive, bool RegularExpression, bool WholeFile, TSearchDirection Direction, int &ErrorCode) = 0 /* overload */;
	virtual int __fastcall Replace(void) = 0 /* overload */;
	virtual int __fastcall ReplaceAgain(void) = 0 ;
	virtual void __fastcall Restore(void) = 0 ;
	virtual AnsiString __fastcall RipText(const Sysutils::TSysCharSet &ValidChars, int RipFlags) = 0 /* overload */;
	virtual AnsiString __fastcall RipText(const AnsiString ValidChars, int RipFlags) = 0 /* overload */;
	virtual void __fastcall Save(void) = 0 ;
	virtual bool __fastcall Search(const AnsiString Pattern, bool CaseSensitive, bool RegularExpression, bool WholeFile, TSearchDirection Direction, int &ErrorCode) = 0 /* overload */;
	virtual bool __fastcall Search(void) = 0 /* overload */;
	virtual bool __fastcall SearchAgain(void) = 0 ;
	virtual void __fastcall Tab(int Magnitude) = 0 ;
	__property char Character = {read=GetCharacter};
	__property int Column = {read=GetColumn};
	__property bool IsSpecialCharacter = {read=GetIsSpecialCharacter};
	__property bool IsWhiteSpace = {read=GetIsWhitespace};
	__property bool IsWordCharacter = {read=GetIsWordCharacter};
	__property int LastRow = {read=GetLastRow};
	__property _di_IOTAReplaceOptions ReplaceOptions = {read=GetReplaceOptions};
	__property int Row = {read=GetRow};
	__property _di_IOTASearchOptions SearchOptions = {read=GetSearchOptions};
};

__interface INTERFACE_UUID("{9C510463-C7BC-11D2-9AEB-00A02457621F}") IOTAEditBlock  : public IInterface 
{
	
public:
	virtual void __fastcall BeginBlock(void) = 0 ;
	virtual void __fastcall Copy(bool Append) = 0 ;
	virtual void __fastcall Cut(bool Append) = 0 ;
	virtual bool __fastcall Delete(void) = 0 ;
	virtual void __fastcall EndBlock(void) = 0 ;
	virtual bool __fastcall Extend(int NewRow, int NewCol) = 0 ;
	virtual bool __fastcall ExtendPageUp(void) = 0 ;
	virtual bool __fastcall ExtendPageDown(void) = 0 ;
	virtual bool __fastcall ExtendReal(int NewRow, int NewCol) = 0 ;
	virtual bool __fastcall ExtendRelative(int DeltaRow, int DeltaCol) = 0 ;
	virtual int __fastcall GetEndingColumn(void) = 0 ;
	virtual int __fastcall GetEndingRow(void) = 0 ;
	virtual bool __fastcall GetIsValid(void) = 0 ;
	virtual int __fastcall GetSize(void) = 0 ;
	virtual int __fastcall GetStartingColumn(void) = 0 ;
	virtual int __fastcall GetStartingRow(void) = 0 ;
	virtual TOTABlockType __fastcall GetStyle(void) = 0 ;
	virtual AnsiString __fastcall GetText(void) = 0 ;
	virtual bool __fastcall GetVisible(void) = 0 ;
	virtual void __fastcall Indent(int Magnitude) = 0 ;
	virtual void __fastcall LowerCase(void) = 0 ;
	virtual bool __fastcall Print(void) = 0 ;
	virtual void __fastcall Reset(void) = 0 ;
	virtual void __fastcall Restore(void) = 0 ;
	virtual void __fastcall Save(void) = 0 ;
	virtual bool __fastcall SaveToFile(const AnsiString FileName) = 0 ;
	virtual void __fastcall SetStyle(TOTABlockType Value) = 0 ;
	virtual void __fastcall SetVisible(bool Value) = 0 ;
	virtual void __fastcall ToggleCase(void) = 0 ;
	virtual void __fastcall UpperCase(void) = 0 ;
	__property int EndingColumn = {read=GetEndingColumn};
	__property int EndingRow = {read=GetEndingRow};
	__property bool IsValid = {read=GetIsValid};
	__property int Size = {read=GetSize};
	__property int StartingColumn = {read=GetStartingColumn};
	__property int StartingRow = {read=GetStartingRow};
	__property TOTABlockType Style = {read=GetStyle, write=SetStyle};
	__property AnsiString Text = {read=GetText};
	__property bool Visible = {read=GetVisible, write=SetVisible};
};

__interface INTAEditWindow;
typedef System::DelphiInterface<INTAEditWindow> _di_INTAEditWindow;
__interface INTERFACE_UUID("{8CC6430B-E721-11D2-A8CC-00C04FA32F53}") INTAEditWindow  : public IInterface 
{
	
public:
	virtual Forms::TCustomForm* __fastcall GetForm(void) = 0 ;
	virtual Comctrls::TStatusBar* __fastcall GetStatusBar(void) = 0 ;
	__property Forms::TCustomForm* Form = {read=GetForm};
	__property Comctrls::TStatusBar* StatusBar = {read=GetStatusBar};
};

__interface IOTAEditBuffer;
typedef System::DelphiInterface<IOTAEditBuffer> _di_IOTAEditBuffer;
__interface INTERFACE_UUID("{9C510462-C7BC-11D2-9AEB-00A02457621F}") IOTAEditView  : public IOTAEditView40 
{
	
public:
	virtual bool __fastcall BookmarkGoto(int BookmarkID) = 0 ;
	virtual bool __fastcall BookmarkRecord(int BookmarkID) = 0 ;
	virtual bool __fastcall BookmarkToggle(int BookmarkID) = 0 ;
	virtual void __fastcall Center(int Row, int Col) = 0 ;
	virtual _di_IOTAEditBlock __fastcall GetBlock(void) = 0 ;
	virtual TOTACharPos __fastcall GetBookmarkPos(int BookmarkID) = 0 ;
	virtual int __fastcall GetBottomRow(void) = 0 ;
	virtual _di_IOTAEditBuffer __fastcall GetBuffer(void) = 0 ;
	virtual _di_INTAEditWindow __fastcall GetEditWindow(void) = 0 ;
	virtual int __fastcall GetLastEditColumn(void) = 0 ;
	virtual int __fastcall GetLastEditRow(void) = 0 ;
	virtual int __fastcall GetLeftColumn(void) = 0 ;
	virtual _di_IOTAEditPosition __fastcall GetPosition(void) = 0 ;
	virtual int __fastcall GetRightColumn(void) = 0 ;
	virtual int __fastcall GetTopRow(void) = 0 ;
	virtual void __fastcall MoveCursorToView(void) = 0 ;
	virtual void __fastcall MoveViewToCursor(void) = 0 ;
	virtual void __fastcall PageDown(void) = 0 ;
	virtual void __fastcall PageUp(void) = 0 ;
	virtual void __fastcall Paint(void) = 0 ;
	virtual int __fastcall Scroll(int DeltaRow, int DeltaCol) = 0 ;
	virtual void __fastcall SetTopLeft(int TopRow, int LeftCol) = 0 ;
	virtual void __fastcall SetTempMsg(const AnsiString Msg) = 0 ;
	__property _di_IOTAEditBlock Block = {read=GetBlock};
	__property int BottomRow = {read=GetBottomRow};
	__property TOTACharPos BookmarkPos[int BookMarkID] = {read=GetBookmarkPos};
	__property _di_IOTAEditBuffer Buffer = {read=GetBuffer};
	__property int LastEditColumn = {read=GetLastEditColumn};
	__property int LastEditRow = {read=GetLastEditRow};
	__property int LeftColumn = {read=GetLeftColumn};
	__property _di_IOTAEditPosition Position = {read=GetPosition};
	__property int RightColumn = {read=GetRightColumn};
	__property int TopRow = {read=GetTopRow};
};

typedef Byte TClassNavigateStyle;

typedef Byte TCodeCompleteStyle;

__interface IOTAEditActions;
typedef System::DelphiInterface<IOTAEditActions> _di_IOTAEditActions;
__interface INTERFACE_UUID("{ECB23623-E2D8-11D2-ABE5-00C04FB16FB3}") IOTAEditActions  : public IInterface 
{
	
public:
	virtual void __fastcall AddWatch(void) = 0 ;
	virtual void __fastcall AddWatchAtCursor(void) = 0 ;
	virtual void __fastcall BrowseSymbolAtCursor(void) = 0 ;
	virtual void __fastcall ClassComplete(void) = 0 ;
	virtual void __fastcall ClassNavigate(Byte Reserved) = 0 ;
	virtual void __fastcall ClosePage(void) = 0 ;
	virtual void __fastcall CodeTemplate(void) = 0 ;
	virtual void __fastcall CodeCompletion(Byte Style) = 0 ;
	virtual void __fastcall EvaluateModify(void) = 0 ;
	virtual void __fastcall HelpKeyword(void) = 0 ;
	virtual void __fastcall IncrementalSearch(void) = 0 ;
	virtual void __fastcall InsertCompilerOptions(void) = 0 ;
	virtual void __fastcall InsertNewGUID(void) = 0 ;
	virtual void __fastcall InspectAtCursor(void) = 0 ;
	virtual void __fastcall CompileProject(void) = 0 ;
	virtual void __fastcall NextError(void) = 0 ;
	virtual void __fastcall NextPage(void) = 0 ;
	virtual void __fastcall OpenFile(void) = 0 ;
	virtual void __fastcall OpenFileAtCursor(void) = 0 ;
	virtual void __fastcall PriorError(void) = 0 ;
	virtual void __fastcall PriorPage(void) = 0 ;
	virtual void __fastcall ProgramReset(void) = 0 ;
	virtual void __fastcall RunProgram(void) = 0 ;
	virtual void __fastcall RunToCursor(void) = 0 ;
	virtual void __fastcall SaveAll(void) = 0 ;
	virtual void __fastcall Save(void) = 0 ;
	virtual void __fastcall SaveAs(void) = 0 ;
	virtual void __fastcall StepOver(void) = 0 ;
	virtual void __fastcall SwapSourceFormView(void) = 0 ;
	virtual void __fastcall SwapCPPHeader(void) = 0 ;
	virtual void __fastcall ToggleFormUnit(void) = 0 ;
	virtual void __fastcall TraceInto(void) = 0 ;
	virtual void __fastcall TraceToSource(void) = 0 ;
	virtual void __fastcall ViewExplorer(void) = 0 ;
	virtual void __fastcall ViewForms(void) = 0 ;
	virtual void __fastcall ViewObjectInspector(void) = 0 ;
	virtual void __fastcall ViewUnits(void) = 0 ;
	virtual void __fastcall WindowList(void) = 0 ;
	virtual void __fastcall ZoomWindow(void) = 0 ;
};

__interface IOTASourceEditor;
typedef System::DelphiInterface<IOTASourceEditor> _di_IOTASourceEditor;
__interface INTERFACE_UUID("{F17A7BD1-E07D-11D1-AB0B-00C04FB16FB3}") IOTASourceEditor  : public IOTAEditor 
{
	
public:
	virtual _di_IOTAEditReader __fastcall CreateReader(void) = 0 ;
	virtual _di_IOTAEditWriter __fastcall CreateWriter(void) = 0 ;
	virtual _di_IOTAEditWriter __fastcall CreateUndoableWriter(void) = 0 ;
	virtual int __fastcall GetEditViewCount(void) = 0 ;
	virtual _di_IOTAEditView __fastcall GetEditView(int Index) = 0 ;
	virtual int __fastcall GetLinesInBuffer(void) = 0 ;
	virtual TOTASyntaxHighlighter __fastcall SetSyntaxHighlighter(TOTASyntaxHighlighter SyntaxHighlighter) = 0 ;
	virtual TOTACharPos __fastcall GetBlockAfter(void) = 0 ;
	virtual TOTACharPos __fastcall GetBlockStart(void) = 0 ;
	virtual TOTABlockType __fastcall GetBlockType(void) = 0 ;
	virtual bool __fastcall GetBlockVisible(void) = 0 ;
	virtual void __fastcall SetBlockAfter(const TOTACharPos &Value) = 0 ;
	virtual void __fastcall SetBlockStart(const TOTACharPos &Value) = 0 ;
	virtual void __fastcall SetBlockType(TOTABlockType Value) = 0 ;
	virtual void __fastcall SetBlockVisible(bool Value) = 0 ;
	__property TOTACharPos BlockStart = {read=GetBlockStart, write=SetBlockStart};
	__property TOTACharPos BlockAfter = {read=GetBlockAfter, write=SetBlockAfter};
	__property TOTABlockType BlockType = {read=GetBlockType, write=SetBlockType};
	__property bool BlockVisible = {read=GetBlockVisible, write=SetBlockVisible};
	__property int EditViewCount = {read=GetEditViewCount};
	__property _di_IOTAEditView EditViews[int Index] = {read=GetEditView};
};

#pragma option push -b-
enum TOTAResHeaderValue { hvFlags, hvLanguage, hvDataVersion, hvVersion, hvCharacteristics };
#pragma option pop

__interface IOTAResourceEntry;
typedef System::DelphiInterface<IOTAResourceEntry> _di_IOTAResourceEntry;
__interface INTERFACE_UUID("{26EB0E51-F97B-11D1-AB27-00C04FB16FB3}") IOTAResourceEntry  : public IInterface 
{
	
public:
	virtual char * __fastcall GetResourceType(void) = 0 ;
	virtual char * __fastcall GetResourceName(void) = 0 ;
	virtual bool __fastcall Change(char * NewType, char * NewName) = 0 ;
	virtual bool __fastcall GetHeaderValue(TOTAResHeaderValue HeaderValue, int &Value) = 0 ;
	virtual bool __fastcall SetHeaderValue(TOTAResHeaderValue HeaderValue, int Value) = 0 ;
	virtual void * __fastcall GetData(void) = 0 ;
	virtual int __fastcall GetDataSize(void) = 0 ;
	virtual void __fastcall SetDataSize(int NewSize) = 0 ;
	virtual void * __fastcall GetEntryHandle(void) = 0 ;
	__property int DataSize = {read=GetDataSize, write=SetDataSize};
};

__interface IOTAProjectResource;
typedef System::DelphiInterface<IOTAProjectResource> _di_IOTAProjectResource;
__interface INTERFACE_UUID("{26EB0E52-F97B-11D1-AB27-00C04FB16FB3}") IOTAProjectResource  : public IOTAEditor 
{
	
public:
	virtual int __fastcall GetEntryCount(void) = 0 ;
	virtual _di_IOTAResourceEntry __fastcall GetEntry(int Index) = 0 ;
	virtual _di_IOTAResourceEntry __fastcall GetEntryFromHandle(void * EntryHandle) = 0 ;
	virtual _di_IOTAResourceEntry __fastcall FindEntry(char * ResType, char * Name) = 0 ;
	virtual void __fastcall DeleteEntry(void * EntryHandle) = 0 ;
	virtual _di_IOTAResourceEntry __fastcall CreateEntry(char * ResType, char * Name, Word Flags, Word LanguageId, int DataVersion, int Version, int Characteristics) = 0 ;
};

__interface IOTAComponent;
typedef System::DelphiInterface<IOTAComponent> _di_IOTAComponent;
typedef void __fastcall (__closure *TOTAGetChildCallback)(void * Param, _di_IOTAComponent Component, bool &Result);

__interface INTAComponent;
typedef System::DelphiInterface<INTAComponent> _di_INTAComponent;
__interface INTERFACE_UUID("{34B2E2D1-E36F-11D1-AB0E-00C04FB16FB3}") INTAComponent  : public IInterface 
{
	
public:
	virtual Classes::TPersistent* __fastcall GetPersistent(void) = 0 ;
	virtual Classes::TComponent* __fastcall GetComponent(void) = 0 ;
};

__interface INTERFACE_UUID("{AC139ADF-329A-D411-87C6-9B2730412200}") IOTAComponent  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall GetComponentType(void) = 0 ;
	virtual void * __fastcall GetComponentHandle(void) = 0 ;
	virtual _di_IOTAComponent __fastcall GetParent(void) = 0 ;
	virtual bool __fastcall IsTControl(void) = 0 ;
	virtual int __fastcall GetPropCount(void) = 0 ;
	virtual AnsiString __fastcall GetPropName(int Index) = 0 ;
	virtual Typinfo::TTypeKind __fastcall GetPropType(int Index) = 0 ;
	virtual Typinfo::TTypeKind __fastcall GetPropTypeByName(const AnsiString Name) = 0 ;
	virtual bool __fastcall GetPropValue(int Index, void *Value) = 0 ;
	virtual bool __fastcall GetPropValueByName(const AnsiString Name, void *Value) = 0 ;
	virtual bool __fastcall SetProp(int Index, const void *Value) = 0 ;
	virtual bool __fastcall SetPropByName(const AnsiString Name, const void *Value) = 0 ;
	virtual bool __fastcall GetChildren(void * Param, TOTAGetChildCallback Proc) = 0 ;
	virtual int __fastcall GetControlCount(void) = 0 ;
	virtual _di_IOTAComponent __fastcall GetControl(int Index) = 0 ;
	virtual int __fastcall GetComponentCount(void) = 0 ;
	virtual _di_IOTAComponent __fastcall GetComponent(int Index) = 0 ;
	virtual bool __fastcall Select(bool AddToSelection) = 0 ;
	virtual bool __fastcall Focus(bool AddToSelection) = 0 ;
	virtual bool __fastcall Delete(void) = 0 ;
};

__interface INTAFormEditor;
typedef System::DelphiInterface<INTAFormEditor> _di_INTAFormEditor;
__interface INTERFACE_UUID("{56931EB9-329A-D411-87C6-9B2730412200}") INTAFormEditor  : public IInterface 
{
	
public:
	virtual Designintf::_di_IDesigner __fastcall GetFormDesigner(void) = 0 ;
	virtual void __fastcall GetFormResource(Classes::TStream* Stream) = 0 ;
	__property Designintf::_di_IDesigner FormDesigner = {read=GetFormDesigner};
};

__interface IOTAFormEditor;
typedef System::DelphiInterface<IOTAFormEditor> _di_IOTAFormEditor;
__interface INTERFACE_UUID("{F17A7BD2-E07D-11D1-AB0B-00C04FB16FB3}") IOTAFormEditor  : public IOTAEditor 
{
	
public:
	virtual _di_IOTAComponent __fastcall GetRootComponent(void) = 0 ;
	virtual _di_IOTAComponent __fastcall FindComponent(const AnsiString Name) = 0 ;
	virtual _di_IOTAComponent __fastcall GetComponentFromHandle(void * ComponentHandle) = 0 ;
	virtual int __fastcall GetSelCount(void) = 0 ;
	virtual _di_IOTAComponent __fastcall GetSelComponent(int Index) = 0 ;
	virtual _di_IOTAComponent __fastcall GetCreateParent(void) = 0 ;
	virtual _di_IOTAComponent __fastcall CreateComponent(const _di_IOTAComponent Container, const AnsiString TypeName, int X, int Y, int W, int H) = 0 ;
	virtual void __fastcall GetFormResource(const _di_IStream Stream) = 0 ;
};

__interface IOTATypeLibEditor;
typedef System::DelphiInterface<IOTATypeLibEditor> _di_IOTATypeLibEditor;
__interface INTERFACE_UUID("{F17A7BD3-E07D-11D1-AB0B-00C04FB16FB3}") IOTATypeLibEditor  : public IOTAEditor 
{
	
};

__interface IOTAModuleNotifier;
typedef System::DelphiInterface<IOTAModuleNotifier> _di_IOTAModuleNotifier;
__interface INTERFACE_UUID("{F17A7BCE-E07D-11D1-AB0B-00C04FB16FB3}") IOTAModuleNotifier  : public IOTANotifier 
{
	
public:
	virtual bool __fastcall CheckOverwrite(void) = 0 ;
	virtual void __fastcall ModuleRenamed(const AnsiString NewName) = 0 ;
};

__interface IOTAModuleInfo50;
typedef System::DelphiInterface<IOTAModuleInfo50> _di_IOTAModuleInfo50;
__interface INTERFACE_UUID("{F17A7BD6-E07D-11D1-AB0B-00C04FB16FB3}") IOTAModuleInfo50  : public IInterface 
{
	
public:
	virtual TOTAModuleType __fastcall GetModuleType(void) = 0 ;
	virtual AnsiString __fastcall GetName(void) = 0 ;
	virtual AnsiString __fastcall GetFileName(void) = 0 ;
	virtual AnsiString __fastcall GetFormName(void) = 0 ;
	virtual AnsiString __fastcall GetDesignClass(void) = 0 ;
	virtual void __fastcall GetCoClasses(Classes::TStrings* CoClasses) = 0 ;
	virtual _di_IOTAModule __fastcall OpenModule(void) = 0 ;
	__property TOTAModuleType ModuleType = {read=GetModuleType};
	__property AnsiString Name = {read=GetName};
	__property AnsiString FileName = {read=GetFileName};
	__property AnsiString FormName = {read=GetFormName};
	__property AnsiString DesignClass = {read=GetDesignClass};
};

__interface IOTAModuleInfo;
typedef System::DelphiInterface<IOTAModuleInfo> _di_IOTAModuleInfo;
__interface INTERFACE_UUID("{B3EEB4D2-ECDD-4CDC-B96E-B5C8F6D050A8}") IOTAModuleInfo  : public IOTAModuleInfo50 
{
	
public:
	virtual AnsiString __fastcall GetCustomId(void) = 0 ;
	virtual void __fastcall GetAdditionalFiles(Classes::TStrings* Files) = 0 ;
	__property AnsiString CustomId = {read=GetCustomId};
};

__interface IOTAModule40;
typedef System::DelphiInterface<IOTAModule40> _di_IOTAModule40;
__interface IOTAProject;
typedef System::DelphiInterface<IOTAProject> _di_IOTAProject;
__interface INTERFACE_UUID("{F17A7BCC-E07D-11D1-AB0B-00C04FB16FB3}") IOTAModule40  : public IInterface 
{
	
public:
	virtual int __fastcall AddNotifier(const _di_IOTAModuleNotifier ANotifier) = 0 ;
	virtual void __fastcall AddToInterface(void) = 0 ;
	virtual bool __fastcall Close(void) = 0 ;
	virtual AnsiString __fastcall GetFileName(void) = 0 ;
	virtual AnsiString __fastcall GetFileSystem(void) = 0 ;
	virtual int __fastcall GetModuleFileCount(void) = 0 ;
	virtual _di_IOTAEditor __fastcall GetModuleFileEditor(int Index) = 0 ;
	virtual int __fastcall GetOwnerCount(void) = 0 ;
	virtual _di_IOTAProject __fastcall GetOwner(int Index) = 0 ;
	virtual bool __fastcall HasCoClasses(void) = 0 ;
	virtual void __fastcall RemoveNotifier(int Index) = 0 ;
	virtual bool __fastcall Save(bool ChangeName, bool ForceSave) = 0 ;
	virtual void __fastcall SetFileName(const AnsiString AFileName) = 0 ;
	virtual void __fastcall SetFileSystem(const AnsiString AFileSystem) = 0 ;
	__property int OwnerCount = {read=GetOwnerCount};
	__property _di_IOTAProject Owners[int Index] = {read=GetOwner};
	__property AnsiString FileName = {read=GetFileName, write=SetFileName};
	__property AnsiString FileSystem = {read=GetFileSystem, write=SetFileSystem};
};

__interface IOTAModule50;
typedef System::DelphiInterface<IOTAModule50> _di_IOTAModule50;
__interface INTERFACE_UUID("{15D3FB81-EF27-488E-B2B4-26B59CA89D9D}") IOTAModule50  : public IOTAModule40 
{
	
public:
	virtual bool __fastcall CloseModule(bool ForceClosed) = 0 ;
	__property int ModuleFileCount = {read=GetModuleFileCount};
	__property _di_IOTAEditor ModuleFileEditors[int Index] = {read=GetModuleFileEditor};
};

__interface INTERFACE_UUID("{2438BFB8-C742-48CD-8F50-DE6C7F764A55}") IOTAModule  : public IOTAModule50 
{
	
public:
	virtual _di_IOTAEditor __fastcall GetCurrentEditor(void) = 0 ;
	virtual int __fastcall GetOwnerModuleCount(void) = 0 ;
	virtual _di_IOTAModule __fastcall GetOwnerModule(int Index) = 0 ;
	virtual void __fastcall MarkModified(void) = 0 ;
	__property _di_IOTAEditor CurrentEditor = {read=GetCurrentEditor};
	__property int OwnerModuleCount = {read=GetOwnerModuleCount};
	__property _di_IOTAModule OwnerModules[int Index] = {read=GetOwnerModule};
};

__interface IOTAAdditionalModuleFiles;
typedef System::DelphiInterface<IOTAAdditionalModuleFiles> _di_IOTAAdditionalModuleFiles;
__interface INTERFACE_UUID("{2D73A12F-6FB3-11D4-A4B8-00C04F6BB853}") IOTAAdditionalModuleFiles  : public IInterface 
{
	
public:
	virtual int __fastcall GetAdditionalModuleFileCount(void) = 0 ;
	virtual _di_IOTAEditor __fastcall GetAdditionalModuleFileEditor(int Index) = 0 ;
	__property int AdditionalModuleFileCount = {read=GetAdditionalModuleFileCount};
	__property _di_IOTAEditor AdditionalModuleFileEditors[int Index] = {read=GetAdditionalModuleFileEditor};
};

__interface IOTAModuleData;
typedef System::DelphiInterface<IOTAModuleData> _di_IOTAModuleData;
__interface INTERFACE_UUID("{FFD0A5AF-49CB-4EC2-A658-957146030CEC}") IOTAModuleData  : public IInterface 
{
	
public:
	virtual bool __fastcall HasObjects(void) = 0 ;
};

__interface IOTATypeLibModule;
typedef System::DelphiInterface<IOTATypeLibModule> _di_IOTATypeLibModule;
__interface INTERFACE_UUID("{0BBAEEA0-EF74-11D1-AB1C-00C04FB16FB3}") IOTATypeLibModule  : public IOTAModule 
{
	
};

__interface IOTAOptions;
typedef System::DelphiInterface<IOTAOptions> _di_IOTAOptions;
__interface INTERFACE_UUID("{9C0E91FC-FA5A-11D1-AB28-00C04FB16FB3}") IOTAOptions  : public IInterface 
{
	
public:
	virtual void __fastcall EditOptions(void) = 0 ;
	virtual Variant __fastcall GetOptionValue(const AnsiString ValueName) = 0 ;
	virtual void __fastcall SetOptionValue(const AnsiString ValueName, const Variant &Value) = 0 ;
	virtual TOTAOptionNameArray __fastcall GetOptionNames(void) = 0 ;
	__property Variant Values[AnsiString ValueName] = {read=GetOptionValue, write=SetOptionValue};
};

__interface IOTAProjectOptions40;
typedef System::DelphiInterface<IOTAProjectOptions40> _di_IOTAProjectOptions40;
__interface INTERFACE_UUID("{F17A7BD4-E07D-11D1-AB0B-00C04FB16FB3}") IOTAProjectOptions40  : public IOTAOptions 
{
	
};

__interface IOTAProjectOptions;
typedef System::DelphiInterface<IOTAProjectOptions> _di_IOTAProjectOptions;
__interface INTERFACE_UUID("{F899EBC6-E6E2-11D2-AA90-00C04FA370E9}") IOTAProjectOptions  : public IOTAProjectOptions40 
{
	
public:
	virtual void __fastcall SetModifiedState(bool State) = 0 ;
	virtual bool __fastcall GetModifiedState(void) = 0 ;
	__property bool ModifiedState = {read=GetModifiedState, write=SetModifiedState};
};

__interface IOTAProjectBuilder40;
typedef System::DelphiInterface<IOTAProjectBuilder40> _di_IOTAProjectBuilder40;
__interface INTERFACE_UUID("{F17A7BD5-E07D-11D1-AB0B-00C04FB16FB3}") IOTAProjectBuilder40  : public IInterface 
{
	
public:
	virtual bool __fastcall GetShouldBuild(void) = 0 ;
	virtual bool __fastcall BuildProject(TOTACompileMode CompileMode, bool Wait) = 0 ;
	__property bool ShouldBuild = {read=GetShouldBuild};
};

__interface IOTAProjectBuilder;
typedef System::DelphiInterface<IOTAProjectBuilder> _di_IOTAProjectBuilder;
__interface INTERFACE_UUID("{08A5B1F5-FCDA-11D2-AC82-00C04FB173DC}") IOTAProjectBuilder  : public IOTAProjectBuilder40 
{
	
public:
	HIDESBASE virtual bool __fastcall BuildProject(TOTACompileMode CompileMode, bool Wait, bool ClearMessages) = 0 /* overload */;
};

__interface IOTAProject40;
typedef System::DelphiInterface<IOTAProject40> _di_IOTAProject40;
__interface INTERFACE_UUID("{F17A7BCA-E07D-11D1-AB0B-00C04FB16FB3}") IOTAProject40  : public IOTAModule 
{
	
public:
	virtual int __fastcall GetModuleCount(void) = 0 ;
	virtual _di_IOTAModuleInfo __fastcall GetModule(int Index) = 0 ;
	virtual _di_IOTAProjectOptions __fastcall GetProjectOptions(void) = 0 ;
	virtual _di_IOTAProjectBuilder __fastcall GetProjectBuilder(void) = 0 ;
	__property _di_IOTAProjectOptions ProjectOptions = {read=GetProjectOptions};
	__property _di_IOTAProjectBuilder ProjectBuilder = {read=GetProjectBuilder};
};

__interface INTERFACE_UUID("{06C88136-F367-4D47-B8B4-CCACB3D7439A}") IOTAProject  : public IOTAProject40 
{
	
public:
	virtual void __fastcall AddFile(const AnsiString AFileName, bool IsUnitOrForm) = 0 ;
	virtual void __fastcall RemoveFile(const AnsiString AFileName) = 0 ;
};

__interface IOTAProjectGroup;
typedef System::DelphiInterface<IOTAProjectGroup> _di_IOTAProjectGroup;
__interface INTERFACE_UUID("{F17A7BCB-E07D-11D1-AB0B-00C04FB16FB3}") IOTAProjectGroup  : public IOTAModule 
{
	
public:
	virtual void __fastcall AddNewProject(void) = 0 ;
	virtual void __fastcall AddExistingProject(void) = 0 ;
	virtual _di_IOTAProject __fastcall GetActiveProject(void) = 0 ;
	virtual int __fastcall GetProjectCount(void) = 0 ;
	virtual _di_IOTAProject __fastcall GetProject(int Index) = 0 ;
	virtual void __fastcall RemoveProject(const _di_IOTAProject AProject) = 0 ;
	virtual void __fastcall SetActiveProject(const _di_IOTAProject AProject) = 0 ;
	__property _di_IOTAProject ActiveProject = {read=GetActiveProject, write=SetActiveProject};
	__property int ProjectCount = {read=GetProjectCount};
	__property _di_IOTAProject Projects[int Index] = {read=GetProject};
};

__interface IOTAActionServices;
typedef System::DelphiInterface<IOTAActionServices> _di_IOTAActionServices;
__interface INTERFACE_UUID("{F17A7BC9-E07D-11D1-AB0B-00C04FB16FB3}") IOTAActionServices  : public IInterface 
{
	
public:
	virtual bool __fastcall CloseFile(const AnsiString FileName) = 0 ;
	virtual bool __fastcall OpenFile(const AnsiString FileName) = 0 ;
	virtual bool __fastcall OpenProject(const AnsiString ProjName, bool NewProjGroup) = 0 ;
	virtual bool __fastcall ReloadFile(const AnsiString FileName) = 0 ;
	virtual bool __fastcall SaveFile(const AnsiString FileName) = 0 ;
};

__interface IOTAFileSystem;
typedef System::DelphiInterface<IOTAFileSystem> _di_IOTAFileSystem;
__interface INTERFACE_UUID("{A9D1389D-F4B0-11D1-AB22-00C04FB16FB3}") IOTAFileSystem  : public IInterface 
{
	
public:
	virtual _di_IStream __fastcall GetFileStream(const AnsiString FileName, int Mode) = 0 ;
	virtual int __fastcall FileAge(const AnsiString FileName) = 0 ;
	virtual bool __fastcall RenameFile(const AnsiString OldName, const AnsiString NewName) = 0 ;
	virtual bool __fastcall IsReadonly(const AnsiString FileName) = 0 ;
	virtual bool __fastcall IsFileBased(void) = 0 ;
	virtual bool __fastcall DeleteFile(const AnsiString FileName) = 0 ;
	virtual bool __fastcall FileExists(const AnsiString FileName) = 0 ;
	virtual AnsiString __fastcall GetTempFileName(const AnsiString FileName) = 0 ;
	virtual AnsiString __fastcall GetBackupFileName(const AnsiString FileName) = 0 ;
	virtual AnsiString __fastcall GetIDString(void) = 0 ;
};

__interface IOTAFile;
typedef System::DelphiInterface<IOTAFile> _di_IOTAFile;
__interface INTERFACE_UUID("{6E2AD9B0-F7F0-11D1-AB26-00C04FB16FB3}") IOTAFile  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall GetSource(void) = 0 ;
	virtual System::TDateTime __fastcall GetAge(void) = 0 ;
	__property AnsiString Source = {read=GetSource};
	__property System::TDateTime Age = {read=GetAge};
};

__interface IOTACreator;
typedef System::DelphiInterface<IOTACreator> _di_IOTACreator;
__interface INTERFACE_UUID("{6EDB9B9E-F57A-11D1-AB23-00C04FB16FB3}") IOTACreator  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall GetCreatorType(void) = 0 ;
	virtual bool __fastcall GetExisting(void) = 0 ;
	virtual AnsiString __fastcall GetFileSystem(void) = 0 ;
	virtual _di_IOTAModule __fastcall GetOwner(void) = 0 ;
	virtual bool __fastcall GetUnnamed(void) = 0 ;
	__property AnsiString CreatorType = {read=GetCreatorType};
	__property bool Existing = {read=GetExisting};
	__property AnsiString FileSystem = {read=GetFileSystem};
	__property _di_IOTAModule Owner = {read=GetOwner};
	__property bool Unnamed = {read=GetUnnamed};
};

__interface IOTAModuleCreator;
typedef System::DelphiInterface<IOTAModuleCreator> _di_IOTAModuleCreator;
__interface INTERFACE_UUID("{6EDB9B9A-F57A-11D1-AB23-00C04FB16FB3}") IOTAModuleCreator  : public IOTACreator 
{
	
public:
	virtual AnsiString __fastcall GetAncestorName(void) = 0 ;
	virtual AnsiString __fastcall GetImplFileName(void) = 0 ;
	virtual AnsiString __fastcall GetIntfFileName(void) = 0 ;
	virtual AnsiString __fastcall GetFormName(void) = 0 ;
	virtual bool __fastcall GetMainForm(void) = 0 ;
	virtual bool __fastcall GetShowForm(void) = 0 ;
	virtual bool __fastcall GetShowSource(void) = 0 ;
	virtual _di_IOTAFile __fastcall NewFormFile(const AnsiString FormIdent, const AnsiString AncestorIdent) = 0 ;
	virtual _di_IOTAFile __fastcall NewImplSource(const AnsiString ModuleIdent, const AnsiString FormIdent, const AnsiString AncestorIdent) = 0 ;
	virtual _di_IOTAFile __fastcall NewIntfSource(const AnsiString ModuleIdent, const AnsiString FormIdent, const AnsiString AncestorIdent) = 0 ;
	virtual void __fastcall FormCreated(const _di_IOTAFormEditor FormEditor) = 0 ;
	__property AnsiString AncestorName = {read=GetAncestorName};
	__property AnsiString FormName = {read=GetFormName};
	__property AnsiString ImplFileName = {read=GetImplFileName};
	__property AnsiString IntfFileName = {read=GetIntfFileName};
	__property bool MainForm = {read=GetMainForm};
	__property bool ShowForm = {read=GetShowForm};
	__property bool ShowSource = {read=GetShowSource};
};

__interface IOTAAdditionalFilesModuleCreator;
typedef System::DelphiInterface<IOTAAdditionalFilesModuleCreator> _di_IOTAAdditionalFilesModuleCreator;
__interface INTERFACE_UUID("{BACD1450-1AC5-11D4-A455-00C04F6BB853}") IOTAAdditionalFilesModuleCreator  : public IOTAModuleCreator 
{
	
public:
	virtual int __fastcall GetAdditionalFilesCount(void) = 0 ;
	virtual _di_IOTAFile __fastcall NewAdditionalFileSource(int I, const AnsiString ModuleIdent, const AnsiString FormIdent, const AnsiString AncestorIdent) = 0 ;
	virtual AnsiString __fastcall GetAdditionalFileName(int I) = 0 ;
	virtual AnsiString __fastcall GetAdditionalFileExt(int I) = 0 ;
};

__interface IOTAProjectCreator;
typedef System::DelphiInterface<IOTAProjectCreator> _di_IOTAProjectCreator;
__interface INTERFACE_UUID("{6EDB9B9D-F57A-11D1-AB23-00C04FB16FB3}") IOTAProjectCreator  : public IOTACreator 
{
	
public:
	virtual AnsiString __fastcall GetFileName(void) = 0 ;
	virtual AnsiString __fastcall GetOptionFileName(void) = 0 ;
	virtual bool __fastcall GetShowSource(void) = 0 ;
	virtual void __fastcall NewDefaultModule(void) = 0 ;
	virtual _di_IOTAFile __fastcall NewOptionSource(const AnsiString ProjectName) = 0 ;
	virtual void __fastcall NewProjectResource(const _di_IOTAProject Project) = 0 ;
	virtual _di_IOTAFile __fastcall NewProjectSource(const AnsiString ProjectName) = 0 ;
	__property AnsiString FileName = {read=GetFileName};
	__property AnsiString OptionFileName = {read=GetOptionFileName};
	__property bool ShowSource = {read=GetShowSource};
};

__interface IOTAProjectCreator50;
typedef System::DelphiInterface<IOTAProjectCreator50> _di_IOTAProjectCreator50;
__interface INTERFACE_UUID("{64312F82-62F3-48E9-BAF6-B03DF450312A}") IOTAProjectCreator50  : public IOTAProjectCreator 
{
	
public:
	virtual void __fastcall NewDefaultProjectModule(const _di_IOTAProject Project) = 0 ;
};

__interface IOTAProjectGroupCreator;
typedef System::DelphiInterface<IOTAProjectGroupCreator> _di_IOTAProjectGroupCreator;
__interface INTERFACE_UUID("{6EDB9B9F-F57A-11D1-AB23-00C04FB16FB3}") IOTAProjectGroupCreator  : public IOTACreator 
{
	
public:
	virtual AnsiString __fastcall GetFileName(void) = 0 ;
	virtual bool __fastcall GetShowSource(void) = 0 ;
	virtual _di_IOTAFile __fastcall NewProjectGroupSource(const AnsiString ProjectGroupName) = 0 ;
	__property AnsiString FileName = {read=GetFileName};
	__property bool ShowSource = {read=GetShowSource};
};

__interface IOTAModuleServices;
typedef System::DelphiInterface<IOTAModuleServices> _di_IOTAModuleServices;
__interface INTERFACE_UUID("{F17A7BCD-E07D-11D1-AB0B-00C04FB16FB3}") IOTAModuleServices  : public IInterface 
{
	
public:
	virtual int __fastcall AddFileSystem(_di_IOTAFileSystem FileSystem) = 0 ;
	virtual bool __fastcall CloseAll(void) = 0 ;
	virtual _di_IOTAModule __fastcall CreateModule(const _di_IOTACreator Creator) = 0 ;
	virtual _di_IOTAModule __fastcall CurrentModule(void) = 0 ;
	virtual _di_IOTAFileSystem __fastcall FindFileSystem(const AnsiString Name) = 0 ;
	virtual _di_IOTAModule __fastcall FindFormModule(const AnsiString FormName) = 0 ;
	virtual _di_IOTAModule __fastcall FindModule(const AnsiString FileName) = 0 ;
	virtual int __fastcall GetModuleCount(void) = 0 ;
	virtual _di_IOTAModule __fastcall GetModule(int Index) = 0 ;
	virtual void __fastcall GetNewModuleAndClassName(const AnsiString Prefix, AnsiString &UnitIdent, AnsiString &ClassName, AnsiString &FileName) = 0 ;
	virtual bool __fastcall NewModule(void) = 0 ;
	virtual void __fastcall RemoveFileSystem(int Index) = 0 ;
	virtual bool __fastcall SaveAll(void) = 0 ;
	__property int ModuleCount = {read=GetModuleCount};
	__property _di_IOTAModule Modules[int Index] = {read=GetModule};
};

#pragma option push -b-
enum TOTATriggerResult { trStop, trContinue, trDefault };
#pragma option pop

#pragma option push -b-
enum TOTAAccessType { atRead, atWrite, atExecute };
#pragma option pop

#pragma option push -b-
enum TOTARunMode { ormRun, ormRunToEntry, ormRunToMain, ormRunToCursor, ormStmtStepInto, ormStmtStepOver, ormInstStepInto, ormInstStepOver, ormStmtStepToSource, ormReserved1, rmReserved2, rmReserved3 };
#pragma option pop

__interface IOTABreakpointNotifier;
typedef System::DelphiInterface<IOTABreakpointNotifier> _di_IOTABreakpointNotifier;
__interface INTERFACE_UUID("{34B2E2D5-E36F-11D1-AB0E-00C04FB16FB3}") IOTABreakpointNotifier  : public IOTANotifier 
{
	
public:
	virtual bool __fastcall Edit(bool AllowKeyChanges) = 0 ;
	virtual TOTATriggerResult __fastcall Trigger(void) = 0 ;
	virtual void __fastcall Verified(bool Enabled, bool Valid) = 0 ;
};

__interface IOTABreakpoint40;
typedef System::DelphiInterface<IOTABreakpoint40> _di_IOTABreakpoint40;
__interface IOTAProcess;
typedef System::DelphiInterface<IOTAProcess> _di_IOTAProcess;
__interface INTERFACE_UUID("{34B2E2D4-E36F-11D1-AB0E-00C04FB16FB3}") IOTABreakpoint40  : public IInterface 
{
	
public:
	virtual int __fastcall AddNotifier(const _di_IOTABreakpointNotifier Notifier) = 0 ;
	virtual void __fastcall Destruct(void) = 0 ;
	virtual bool __fastcall DefaultTrigger(void) = 0 ;
	virtual bool __fastcall DecPassCount(void) = 0 ;
	virtual void __fastcall Edit(bool AllowKeyChanges) = 0 ;
	virtual bool __fastcall EvaluateExpression(void) = 0 ;
	virtual bool __fastcall GetEnabled(void) = 0 ;
	virtual AnsiString __fastcall GetExpression(void) = 0 ;
	virtual AnsiString __fastcall GetFileName(void) = 0 ;
	virtual int __fastcall GetLineNumber(void) = 0 ;
	virtual int __fastcall GetCurPassCount(void) = 0 ;
	virtual int __fastcall GetPassCount(void) = 0 ;
	virtual void __fastcall RemoveNotifier(int Index) = 0 ;
	virtual void __fastcall ResetPassCount(void) = 0 ;
	virtual void __fastcall SetFileName(const AnsiString Value) = 0 ;
	virtual void __fastcall SetLineNumber(int Value) = 0 ;
	virtual void __fastcall SetEnabled(bool Value) = 0 ;
	virtual void __fastcall SetExpression(const AnsiString Value) = 0 ;
	virtual void __fastcall SetPassCount(int Value) = 0 ;
	virtual bool __fastcall ValidInCurrentProcess(void) = 0 ;
	virtual bool __fastcall ValidInProcess(_di_IOTAProcess Process) = 0 ;
	__property int CurPassCount = {read=GetCurPassCount};
	__property bool Enabled = {read=GetEnabled, write=SetEnabled};
	__property AnsiString Expression = {read=GetExpression, write=SetExpression};
	__property AnsiString FileName = {read=GetFileName, write=SetFileName};
	__property int LineNumber = {read=GetLineNumber, write=SetLineNumber};
	__property int PassCount = {read=GetPassCount, write=SetPassCount};
};

__interface IOTABreakpoint;
typedef System::DelphiInterface<IOTABreakpoint> _di_IOTABreakpoint;
__interface INTERFACE_UUID("{569EFCFB-C69B-11D2-AC67-00C04FB173DC}") IOTABreakpoint  : public IOTABreakpoint40 
{
	
public:
	virtual AnsiString __fastcall GetGroupName(void) = 0 ;
	virtual bool __fastcall GetDoBreak(void) = 0 ;
	virtual AnsiString __fastcall GetLogMessage(void) = 0 ;
	virtual AnsiString __fastcall GetEvalExpression(void) = 0 ;
	virtual bool __fastcall GetLogResult(void) = 0 ;
	virtual AnsiString __fastcall GetEnableGroup(void) = 0 ;
	virtual AnsiString __fastcall GetDisableGroup(void) = 0 ;
	virtual void __fastcall SetGroupName(const AnsiString Value) = 0 ;
	virtual void __fastcall SetDoBreak(const bool Value) = 0 ;
	virtual void __fastcall SetLogMessage(const AnsiString Value) = 0 ;
	virtual void __fastcall SetEvalExpression(const AnsiString Value) = 0 ;
	virtual void __fastcall SetLogResult(const bool Value) = 0 ;
	virtual void __fastcall SetEnableGroup(const AnsiString Value) = 0 ;
	virtual void __fastcall SetDisableGroup(const AnsiString Value) = 0 ;
	__property AnsiString GroupName = {read=GetGroupName, write=SetGroupName};
	__property bool DoBreak = {read=GetDoBreak, write=SetDoBreak};
	__property AnsiString LogMessage = {read=GetLogMessage, write=SetLogMessage};
	__property AnsiString EvalExpression = {read=GetEvalExpression, write=SetEvalExpression};
	__property bool LogResult = {read=GetLogResult, write=SetLogResult};
	__property AnsiString EnableGroup = {read=GetEnableGroup, write=SetEnableGroup};
	__property AnsiString DisableGroup = {read=GetDisableGroup, write=SetDisableGroup};
};

__interface IOTASourceBreakpoint;
typedef System::DelphiInterface<IOTASourceBreakpoint> _di_IOTASourceBreakpoint;
__interface INTERFACE_UUID("{09063877-E43A-11D1-AB0F-00C04FB16FB3}") IOTASourceBreakpoint  : public IOTABreakpoint 
{
	
};

__interface IOTAAddressBreakpoint;
typedef System::DelphiInterface<IOTAAddressBreakpoint> _di_IOTAAddressBreakpoint;
__interface INTERFACE_UUID("{09063878-E43A-11D1-AB0F-00C04FB16FB3}") IOTAAddressBreakpoint  : public IOTABreakpoint 
{
	
public:
	virtual unsigned __fastcall Address(void) = 0 ;
	virtual unsigned __fastcall AddressInProcess(_di_IOTAProcess Process) = 0 ;
	virtual TOTAAccessType __fastcall GetAccessType(void) = 0 ;
	virtual AnsiString __fastcall GetDataExpr(void) = 0 ;
	virtual int __fastcall GetLineSize(void) = 0 ;
	virtual int __fastcall GetLineOffset(void) = 0 ;
	virtual AnsiString __fastcall GetModuleName(void) = 0 ;
	__property TOTAAccessType AccessType = {read=GetAccessType};
	__property AnsiString DataExpr = {read=GetDataExpr};
	__property AnsiString ModuleName = {read=GetModuleName};
	__property int LineSize = {read=GetLineSize};
	__property int LineOffset = {read=GetLineOffset};
};

#pragma option push -b-
enum TOTANotifyReason { nrOther, nrRunning, nrStopped, nrException, nrFault };
#pragma option pop

__interface IOTAThreadNotifier;
typedef System::DelphiInterface<IOTAThreadNotifier> _di_IOTAThreadNotifier;
__interface INTERFACE_UUID("{34B2E2D7-E36F-11D1-AB0E-00C04FB16FB3}") IOTAThreadNotifier  : public IOTANotifier 
{
	
public:
	virtual void __fastcall ThreadNotify(TOTANotifyReason Reason) = 0 ;
	virtual void __fastcall EvaluteComplete(const AnsiString ExprStr, const AnsiString ResultStr, bool CanModify, unsigned ResultAddress, unsigned ResultSize, int ReturnCode) = 0 ;
	virtual void __fastcall ModifyComplete(const AnsiString ExprStr, const AnsiString ResultStr, int ReturnCode) = 0 ;
};

#pragma option push -b-
enum TOTAEvaluateResult { erOK, erError, erDeferred };
#pragma option pop

#pragma option push -b-
enum TOTAThreadState { tsStopped, tsRunnable, tsBlocked, tsNone };
#pragma option pop

__interface IOTAThread;
typedef System::DelphiInterface<IOTAThread> _di_IOTAThread;
__interface INTERFACE_UUID("{34B2E2D3-E36F-11D1-AB0E-00C04FB16FB3}") IOTAThread  : public IInterface 
{
	
public:
	virtual int __fastcall AddNotifier(const _di_IOTAThreadNotifier Notifier) = 0 ;
	virtual TOTAEvaluateResult __fastcall Evaluate(const AnsiString ExprStr, char * ResultStr, unsigned ResultStrSize, /* out */ bool &CanModify, bool AllowSideEffects, char * FormatSpecifiers, /* out */ unsigned &ResultAddr, /* out */ unsigned &ResultSize, /* out */ unsigned &ResultVal) = 0 ;
	virtual TOTAEvaluateResult __fastcall Modify(const AnsiString ValueStr, char * ResultStr, unsigned ResultSize, /* out */ int &ResultVal) = 0 ;
	virtual int __fastcall GetCallCount(void) = 0 ;
	virtual AnsiString __fastcall GetCallHeader(int Index) = 0 ;
	virtual void __fastcall GetCallPos(int Index, /* out */ AnsiString &FileName, /* out */ int &LineNum) = 0 ;
	virtual AnsiString __fastcall GetCurrentFile(void) = 0 ;
	virtual unsigned __fastcall GetCurrentLine(void) = 0 ;
	virtual _CONTEXT __fastcall GetContext(void) = 0 ;
	virtual unsigned __fastcall GetHandle(void) = 0 ;
	virtual unsigned __fastcall GetOSThreadID(void) = 0 ;
	virtual TOTAThreadState __fastcall GetState(void) = 0 ;
	virtual void __fastcall RemoveNotifier(int Index) = 0 ;
	__property int CallCount = {read=GetCallCount};
	__property AnsiString CallHeaders[int Index] = {read=GetCallHeader};
	__property AnsiString CurrentFile = {read=GetCurrentFile};
	__property unsigned CurrentLine = {read=GetCurrentLine};
	__property _CONTEXT Context = {read=GetContext};
	__property unsigned Handle = {read=GetHandle};
	__property TOTAThreadState State = {read=GetState};
};

__interface IOTAProcessModNotifier;
typedef System::DelphiInterface<IOTAProcessModNotifier> _di_IOTAProcessModNotifier;
__interface INTERFACE_UUID("{0906387A-E43A-11D1-AB0F-00C04FB16FB3}") IOTAProcessModNotifier  : public IOTANotifier 
{
	
};

__interface IOTAProcessModule;
typedef System::DelphiInterface<IOTAProcessModule> _di_IOTAProcessModule;
__interface INTERFACE_UUID("{09063879-E43A-11D1-AB0F-00C04FB16FB3}") IOTAProcessModule  : public IInterface 
{
	
public:
	virtual int __fastcall AddNotifier(const _di_IOTAProcessModNotifier Notifier) = 0 ;
	virtual int __fastcall GetCompUnitCount(void) = 0 ;
	virtual AnsiString __fastcall GetCompUnit(int Index) = 0 ;
	virtual int __fastcall GetCompUnitFileCount(int Index) = 0 ;
	virtual AnsiString __fastcall GetCompUnitFileName(int CompIndex, int FileIndex) = 0 ;
	virtual unsigned __fastcall GetEntryPoint(void) = 0 ;
	virtual unsigned __fastcall GetBaseAddress(void) = 0 ;
	virtual int __fastcall GetFileCount(void) = 0 ;
	virtual AnsiString __fastcall GetFileName(int Index) = 0 ;
	virtual int __fastcall GetModuleEntryPointCount(void) = 0 ;
	virtual AnsiString __fastcall GetModuleEntryPoint(int Index) = 0 ;
	virtual unsigned __fastcall GetModuleEntryPointAddress(int Index) = 0 ;
	virtual AnsiString __fastcall GetModuleFileName(void) = 0 ;
	virtual AnsiString __fastcall GetModuleName(void) = 0 ;
	virtual void __fastcall RemoveNotifier(int Index) = 0 ;
	__property int CompUnitCount = {read=GetCompUnitCount};
	__property AnsiString CompUnit[int Index] = {read=GetCompUnit};
	__property int CompUnitFileCount[int Index] = {read=GetCompUnitFileCount};
	__property AnsiString CompUnitFileName[int CompIndex][int FileIndex] = {read=GetCompUnitFileName};
	__property int FileCount = {read=GetFileCount};
	__property AnsiString FileNames[int Index] = {read=GetFileName};
	__property int ModuleEntryPointCount = {read=GetModuleEntryPointCount};
	__property AnsiString ModuleEntryPoint[int Index] = {read=GetModuleEntryPoint};
	__property unsigned ModuleEntryPointAddress[int Index] = {read=GetModuleEntryPointAddress};
};

__interface IOTAProcessNotifier;
typedef System::DelphiInterface<IOTAProcessNotifier> _di_IOTAProcessNotifier;
__interface INTERFACE_UUID("{34B2E2D6-E36F-11D1-AB0E-00C04FB16FB3}") IOTAProcessNotifier  : public IOTANotifier 
{
	
public:
	virtual void __fastcall ThreadCreated(_di_IOTAThread Thread) = 0 ;
	virtual void __fastcall ThreadDestroyed(_di_IOTAThread Thread) = 0 ;
	virtual void __fastcall ProcessModuleCreated(_di_IOTAProcessModule ProcessModule) = 0 ;
	virtual void __fastcall ProcessModuleDestroyed(_di_IOTAProcessModule ProcessModule) = 0 ;
};

__interface IOTAProcess60;
typedef System::DelphiInterface<IOTAProcess60> _di_IOTAProcess60;
__interface INTERFACE_UUID("{34B2E2D2-E36F-11D1-AB0E-00C04FB16FB3}") IOTAProcess60  : public IInterface 
{
	
public:
	virtual int __fastcall AddNotifier(const _di_IOTAProcessNotifier Notifier) = 0 ;
	virtual _di_IOTAThread __fastcall GetCurrentThread(void) = 0 ;
	virtual int __fastcall GetThreadCount(void) = 0 ;
	virtual _di_IOTAThread __fastcall GetThread(int Index) = 0 ;
	virtual unsigned __fastcall GetProcessId(void) = 0 ;
	virtual void __fastcall Pause(void) = 0 ;
	virtual int __fastcall ReadProcessMemory(unsigned Address, int Count, void *Buffer) = 0 ;
	virtual void __fastcall RemoveNotifier(int Index) = 0 ;
	virtual void __fastcall Run(TOTARunMode RunMode) = 0 ;
	virtual void __fastcall SetCurrentThread(_di_IOTAThread Value) = 0 ;
	virtual void __fastcall Terminate(void) = 0 ;
	virtual int __fastcall WriteProcessMemory(unsigned Address, int Count, void *Buffer) = 0 ;
	__property _di_IOTAThread CurrentThread = {read=GetCurrentThread, write=SetCurrentThread};
	__property unsigned ProcessId = {read=GetProcessId};
	__property int ThreadCount = {read=GetThreadCount};
	__property _di_IOTAThread Threads[int Index] = {read=GetThread};
};

__interface INTERFACE_UUID("{64FC3321-BEC8-4E88-B17A-3E78EA15F10E}") IOTAProcess  : public IOTAProcess60 
{
	
public:
	virtual unsigned __fastcall GetOSProcessId(void) = 0 ;
	__property unsigned OSProcessId = {read=GetOSProcessId};
};

__interface IOTADebuggerNotifier;
typedef System::DelphiInterface<IOTADebuggerNotifier> _di_IOTADebuggerNotifier;
__interface INTERFACE_UUID("{34B2E2D8-E36F-11D1-AB0E-00C04FB16FB3}") IOTADebuggerNotifier  : public IOTANotifier 
{
	
public:
	virtual void __fastcall ProcessCreated(_di_IOTAProcess Process) = 0 ;
	virtual void __fastcall ProcessDestroyed(_di_IOTAProcess Process) = 0 ;
	virtual void __fastcall BreakpointAdded(_di_IOTABreakpoint Breakpoint) = 0 ;
	virtual void __fastcall BreakpointDeleted(_di_IOTABreakpoint Breakpoint) = 0 ;
};

typedef void __fastcall (*TEnumerateProcessesCallback)(unsigned Pid, const AnsiString ProcessName, void * Param);

__interface IOTADebuggerServices;
typedef System::DelphiInterface<IOTADebuggerServices> _di_IOTADebuggerServices;
__interface INTERFACE_UUID("{0E3B9D7A-E119-11D1-AB0C-00C04FB16FB3}") IOTADebuggerServices  : public IInterface 
{
	
public:
	virtual int __fastcall AddNotifier(const _di_IOTADebuggerNotifier Notifier) = 0 ;
	virtual void __fastcall AttachProcess(int Pid, const AnsiString RemoteHost = "") = 0 ;
	virtual void __fastcall CreateProcess(const AnsiString ExeName, const AnsiString Args, const AnsiString RemoteHost = "") = 0 ;
	virtual void __fastcall EnumerateRunningProcesses(TEnumerateProcessesCallback Callback, void * Param, const AnsiString HostName = "") = 0 ;
	virtual int __fastcall GetAddressBkptCount(void) = 0 ;
	virtual _di_IOTAAddressBreakpoint __fastcall GetAddressBkpt(int Index) = 0 ;
	virtual _di_IOTAProcess __fastcall GetCurrentProcess(void) = 0 ;
	virtual int __fastcall GetProcessCount(void) = 0 ;
	virtual _di_IOTAProcess __fastcall GetProcess(int Index) = 0 ;
	virtual int __fastcall GetSourceBkptCount(void) = 0 ;
	virtual _di_IOTASourceBreakpoint __fastcall GetSourceBkpt(int Index) = 0 ;
	virtual void __fastcall LogString(const AnsiString LogStr) = 0 ;
	virtual _di_IOTABreakpoint __fastcall NewAddressBreakpoint(unsigned Address, unsigned Length, TOTAAccessType AccessType, _di_IOTAProcess AProcess = (void *)(0x0)) = 0 ;
	virtual _di_IOTABreakpoint __fastcall NewModuleBreakpoint(const AnsiString ModuleName, _di_IOTAProcess AProcess) = 0 ;
	virtual _di_IOTABreakpoint __fastcall NewSourceBreakpoint(const AnsiString FileName, int LineNumber, _di_IOTAProcess AProcess) = 0 ;
	virtual void __fastcall RemoveNotifier(int Index) = 0 ;
	virtual void __fastcall SetCurrentProcess(_di_IOTAProcess Process) = 0 ;
	__property int AddressBkptCount = {read=GetAddressBkptCount};
	__property _di_IOTAAddressBreakpoint AddressBkpts[int Index] = {read=GetAddressBkpt};
	__property _di_IOTAProcess CurrentProcess = {read=GetCurrentProcess, write=SetCurrentProcess};
	__property int ProcessCount = {read=GetProcessCount};
	__property _di_IOTAProcess Processes[int Index] = {read=GetProcess};
	__property int SourceBkptCount = {read=GetSourceBkptCount};
	__property _di_IOTASourceBreakpoint SourceBkpts[int Index] = {read=GetSourceBkpt};
};

#pragma option push -b-
enum TOTAFileNotification { ofnFileOpening, ofnFileOpened, ofnFileClosing, ofnDefaultDesktopLoad, ofnDefaultDesktopSave, ofnProjectDesktopLoad, ofnProjectDesktopSave, ofnPackageInstalled, ofnPackageUninstalled, ofnActiveProjectChanged };
#pragma option pop

__interface IOTAIDENotifier;
typedef System::DelphiInterface<IOTAIDENotifier> _di_IOTAIDENotifier;
__interface INTERFACE_UUID("{E052204F-ECE9-11D1-AB19-00C04FB16FB3}") IOTAIDENotifier  : public IOTANotifier 
{
	
public:
	virtual void __fastcall FileNotification(TOTAFileNotification NotifyCode, const AnsiString FileName, bool &Cancel) = 0 ;
	virtual void __fastcall BeforeCompile(const _di_IOTAProject Project, bool &Cancel) = 0 /* overload */;
	virtual void __fastcall AfterCompile(bool Succeeded) = 0 /* overload */;
};

__interface IOTAIDENotifier50;
typedef System::DelphiInterface<IOTAIDENotifier50> _di_IOTAIDENotifier50;
__interface INTERFACE_UUID("{AC7D29F1-D9A9-11D2-A8C1-00C04FA32F53}") IOTAIDENotifier50  : public IOTAIDENotifier 
{
	
public:
	HIDESBASE virtual void __fastcall BeforeCompile(const _di_IOTAProject Project, bool IsCodeInsight, bool &Cancel) = 0 /* overload */;
	HIDESBASE virtual void __fastcall AfterCompile(bool Succeeded, bool IsCodeInsight) = 0 /* overload */;
};

#pragma option push -b-
enum ToolsAPI__1 { wsEnabled, wsChecked };
#pragma option pop

typedef Set<ToolsAPI__1, wsEnabled, wsChecked>  TWizardState;

__interface IOTAWizard;
typedef System::DelphiInterface<IOTAWizard> _di_IOTAWizard;
__interface INTERFACE_UUID("{B75C0CE0-EEA6-11D1-9504-00608CCBF153}") IOTAWizard  : public IOTANotifier 
{
	
public:
	virtual AnsiString __fastcall GetIDString(void) = 0 ;
	virtual AnsiString __fastcall GetName(void) = 0 ;
	virtual TWizardState __fastcall GetState(void) = 0 ;
	virtual void __fastcall Execute(void) = 0 ;
};

__interface IOTARepositoryWizard;
typedef System::DelphiInterface<IOTARepositoryWizard> _di_IOTARepositoryWizard;
__interface INTERFACE_UUID("{B75C0CE1-EEA6-11D1-9504-00608CCBF153}") IOTARepositoryWizard  : public IOTAWizard 
{
	
public:
	virtual AnsiString __fastcall GetAuthor(void) = 0 ;
	virtual AnsiString __fastcall GetComment(void) = 0 ;
	virtual AnsiString __fastcall GetPage(void) = 0 ;
	virtual unsigned __fastcall GetGlyph(void) = 0 ;
};

__interface IOTARepositoryWizard60;
typedef System::DelphiInterface<IOTARepositoryWizard60> _di_IOTARepositoryWizard60;
__interface INTERFACE_UUID("{08FCCD88-3A21-4281-ADC9-62FC034CDD12}") IOTARepositoryWizard60  : public IOTARepositoryWizard 
{
	
public:
	virtual AnsiString __fastcall GetDesigner(void) = 0 ;
	__property AnsiString Designer = {read=GetDesigner};
};

__interface IOTAFormWizard;
typedef System::DelphiInterface<IOTAFormWizard> _di_IOTAFormWizard;
__interface INTERFACE_UUID("{36C8BF35-EFFE-11D1-AB1D-00C04FB16FB3}") IOTAFormWizard  : public IOTARepositoryWizard 
{
	
};

__interface IOTAProjectWizard;
typedef System::DelphiInterface<IOTAProjectWizard> _di_IOTAProjectWizard;
__interface INTERFACE_UUID("{36C8BF36-EFFE-11D1-AB1D-00C04FB16FB3}") IOTAProjectWizard  : public IOTARepositoryWizard 
{
	
};

__interface IOTAMenuWizard;
typedef System::DelphiInterface<IOTAMenuWizard> _di_IOTAMenuWizard;
__interface INTERFACE_UUID("{B75C0CE2-EEA6-11D1-9504-00608CCBF153}") IOTAMenuWizard  : public IOTAWizard 
{
	
public:
	virtual AnsiString __fastcall GetMenuText(void) = 0 ;
};

typedef bool __fastcall (*TWizardRegisterProc)(const _di_IOTAWizard Wizard);

typedef void __fastcall (*TWizardTerminateProc)(void);

__interface IBorlandIDEServices;
typedef System::DelphiInterface<IBorlandIDEServices> _di_IBorlandIDEServices;
typedef bool __stdcall (*TWizardInitProc)(const _di_IBorlandIDEServices BorlandIDEServices, TWizardRegisterProc RegisterProc, TWizardTerminateProc &Terminate);

__interface IOTAWizardServices;
typedef System::DelphiInterface<IOTAWizardServices> _di_IOTAWizardServices;
__interface INTERFACE_UUID("{B75C0CE3-EEA6-11D1-9504-00608CCBF153}") IOTAWizardServices  : public IInterface 
{
	
public:
	virtual int __fastcall AddWizard(const _di_IOTAWizard AWizard) = 0 ;
	virtual void __fastcall RemoveWizard(int Index) = 0 ;
};

__interface IOTAPackageServices;
typedef System::DelphiInterface<IOTAPackageServices> _di_IOTAPackageServices;
__interface INTERFACE_UUID("{26EB0E4D-F97B-11D1-AB27-00C04FB16FB3}") IOTAPackageServices  : public IInterface 
{
	
public:
	virtual int __fastcall GetPackageCount(void) = 0 ;
	virtual AnsiString __fastcall GetPackageName(int Index) = 0 ;
	virtual int __fastcall GetComponentCount(int PkgIndex) = 0 ;
	virtual AnsiString __fastcall GetComponentName(int PkgIndex, int CompIndex) = 0 ;
	__property int PackageCount = {read=GetPackageCount};
	__property AnsiString PackageNames[int Index] = {read=GetPackageName};
	__property int ComponentCount[int PkgIndex] = {read=GetComponentCount};
	__property AnsiString ComponentNames[int PkgIndex][int CompIndex] = {read=GetComponentName};
};

__interface IOTACustomMessage;
typedef System::DelphiInterface<IOTACustomMessage> _di_IOTACustomMessage;
__interface INTERFACE_UUID("{589BBDA1-F995-11D1-AB27-00C04FB16FB3}") IOTACustomMessage  : public IInterface 
{
	
public:
	virtual int __fastcall GetColumnNumber(void) = 0 ;
	virtual AnsiString __fastcall GetFileName(void) = 0 ;
	virtual int __fastcall GetLineNumber(void) = 0 ;
	virtual AnsiString __fastcall GetLineText(void) = 0 ;
	virtual void __fastcall ShowHelp(void) = 0 ;
	__property int ColumnNumber = {read=GetColumnNumber};
	__property AnsiString FileName = {read=GetFileName};
	__property int LineNumber = {read=GetLineNumber};
	__property AnsiString LineText = {read=GetLineText};
};

__interface IOTACustomMessage50;
typedef System::DelphiInterface<IOTACustomMessage50> _di_IOTACustomMessage50;
__interface INTERFACE_UUID("{B7523AB7-EB81-11D2-AC7B-00C04FB173DC}") IOTACustomMessage50  : public IOTACustomMessage 
{
	
public:
	virtual int __fastcall GetChildCount(void) = 0 ;
	virtual _di_IOTACustomMessage50 __fastcall GetChild(int Index) = 0 ;
	__property int ChildCount = {read=GetChildCount};
	__property _di_IOTACustomMessage50 Child[int Index] = {read=GetChild};
};

__interface INTACustomDrawMessage;
typedef System::DelphiInterface<INTACustomDrawMessage> _di_INTACustomDrawMessage;
__interface INTERFACE_UUID("{589BBDA2-F995-11D1-AB27-00C04FB16FB3}") INTACustomDrawMessage  : public IOTACustomMessage 
{
	
public:
	virtual void __fastcall Draw(Graphics::TCanvas* Canvas, const Types::TRect &Rect, bool Wrap) = 0 ;
	virtual Types::TRect __fastcall CalcRect(Graphics::TCanvas* Canvas, int MaxWidth, bool Wrap) = 0 ;
};

__interface IOTAMessageServices40;
typedef System::DelphiInterface<IOTAMessageServices40> _di_IOTAMessageServices40;
__interface INTERFACE_UUID("{26EB0E4E-F97B-11D1-AB27-00C04FB16FB3}") IOTAMessageServices40  : public IInterface 
{
	
public:
	virtual void __fastcall AddCustomMessage(const _di_IOTACustomMessage CustomMsg) = 0 ;
	virtual void __fastcall AddTitleMessage(const AnsiString MessageStr) = 0 ;
	virtual void __fastcall AddToolMessage(const AnsiString FileName, const AnsiString MessageStr, const AnsiString PrefixStr, int LineNumber, int ColumnNumber) = 0 ;
	virtual void __fastcall ClearAllMessages(void) = 0 ;
	virtual void __fastcall ClearCompilerMessages(void) = 0 ;
	virtual void __fastcall ClearSearchMessages(void) = 0 ;
	virtual void __fastcall ClearToolMessages(void) = 0 ;
};

__interface IOTAMessageServices50;
typedef System::DelphiInterface<IOTAMessageServices50> _di_IOTAMessageServices50;
__interface INTERFACE_UUID("{3263774B-E959-11D2-AC7B-00C04FB173DC}") IOTAMessageServices50  : public IOTAMessageServices40 
{
	
public:
	HIDESBASE virtual void __fastcall AddToolMessage(const AnsiString FileName, const AnsiString MessageStr, const AnsiString PrefixStr, int LineNumber, int ColumnNumber, void * Parent, /* out */ void * &LineRef) = 0 /* overload */;
};

__interface IOTAMessageGroup;
typedef System::DelphiInterface<IOTAMessageGroup> _di_IOTAMessageGroup;
__interface INTERFACE_UUID("{233F4508-6022-4DDF-B6D3-D2108BAF80DB}") IOTAMessageGroup  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall GetGroupName(void) = 0 ;
	__property AnsiString Name = {read=GetGroupName};
};

__interface IOTAMessageNotifier;
typedef System::DelphiInterface<IOTAMessageNotifier> _di_IOTAMessageNotifier;
__interface INTERFACE_UUID("{FDCB2ED4-B89C-4D00-B0DB-19562951CDBB}") IOTAMessageNotifier  : public IOTANotifier 
{
	
public:
	virtual void __fastcall MessageGroupAdded(const _di_IOTAMessageGroup Group) = 0 ;
	virtual void __fastcall MessageGroupDeleted(const _di_IOTAMessageGroup Group) = 0 ;
};

__interface IOTAMessageServices;
typedef System::DelphiInterface<IOTAMessageServices> _di_IOTAMessageServices;
__interface INTERFACE_UUID("{58A40C76-7EC6-41DA-A2EF-4B3AF31D3977}") IOTAMessageServices  : public IOTAMessageServices50 
{
	
public:
	virtual int __fastcall AddNotifier(const _di_IOTAMessageNotifier ANotifier) = 0 ;
	virtual void __fastcall RemoveNotifier(int Index) = 0 ;
	virtual _di_IOTAMessageGroup __fastcall AddMessageGroup(const AnsiString GroupName) = 0 ;
	HIDESBASE virtual void __fastcall AddCustomMessage(const _di_IOTACustomMessage CustomMsg, const _di_IOTAMessageGroup MessageGroupIntf) = 0 /* overload */;
	HIDESBASE virtual void __fastcall AddTitleMessage(const AnsiString MessageStr, const _di_IOTAMessageGroup MessageGroupIntf) = 0 /* overload */;
	HIDESBASE virtual void __fastcall AddToolMessage(const AnsiString FileName, const AnsiString MessageStr, const AnsiString PrefixStr, int LineNumber, int ColumnNumber, void * Parent, /* out */ void * &LineRef, const _di_IOTAMessageGroup MessageGroupIntf) = 0 /* overload */;
	virtual void __fastcall ClearMessageGroup(const _di_IOTAMessageGroup MessageGroupIntf) = 0 ;
	HIDESBASE virtual void __fastcall ClearToolMessages(const _di_IOTAMessageGroup MessageGroupIntf) = 0 /* overload */;
	virtual int __fastcall GetMessageGroupCount(void) = 0 ;
	virtual _di_IOTAMessageGroup __fastcall GetMessageGroup(int Index) = 0 ;
	virtual _di_IOTAMessageGroup __fastcall GetGroup(const AnsiString GroupName) = 0 ;
	virtual void __fastcall ShowMessageView(const _di_IOTAMessageGroup MessageGroupIntf) = 0 ;
	virtual void __fastcall RemoveMessageGroup(const _di_IOTAMessageGroup MessageGroupIntf) = 0 ;
	__property int MessageGroupCount = {read=GetMessageGroupCount};
	__property _di_IOTAMessageGroup MessageGroup[int Index] = {read=GetMessageGroup};
};

__interface IOTAEnvironmentOptions;
typedef System::DelphiInterface<IOTAEnvironmentOptions> _di_IOTAEnvironmentOptions;
__interface INTERFACE_UUID("{9C0E91FB-FA5A-11D1-AB28-00C04FB16FB3}") IOTAEnvironmentOptions  : public IOTAOptions 
{
	
};

__interface INTAServices40;
typedef System::DelphiInterface<INTAServices40> _di_INTAServices40;
__interface INTERFACE_UUID("{3C7F3267-F0BF-11D1-AB1E-00C04FB16FB3}") INTAServices40  : public IInterface 
{
	
public:
	virtual int __fastcall AddMasked(Graphics::TBitmap* Image, Graphics::TColor MaskColor) = 0 /* overload */;
	virtual Actnlist::TCustomActionList* __fastcall GetActionList(void) = 0 ;
	virtual Imglist::TCustomImageList* __fastcall GetImageList(void) = 0 ;
	virtual Menus::TMainMenu* __fastcall GetMainMenu(void) = 0 ;
	virtual Comctrls::TToolBar* __fastcall GetToolBar(const AnsiString ToolBarName) = 0 ;
	__property Actnlist::TCustomActionList* ActionList = {read=GetActionList};
	__property Imglist::TCustomImageList* ImageList = {read=GetImageList};
	__property Menus::TMainMenu* MainMenu = {read=GetMainMenu};
	__property Comctrls::TToolBar* ToolBar[AnsiString ToolBarName] = {read=GetToolBar};
};

__interface INTAServices;
typedef System::DelphiInterface<INTAServices> _di_INTAServices;
__interface INTERFACE_UUID("{C17B3DF1-DFE5-11D2-A8C7-00C04FA32F53}") INTAServices  : public INTAServices40 
{
	
public:
	HIDESBASE virtual int __fastcall AddMasked(Graphics::TBitmap* Image, Graphics::TColor MaskColor, const AnsiString Ident) = 0 /* overload */;
};

__interface IOTAServices50;
typedef System::DelphiInterface<IOTAServices50> _di_IOTAServices50;
__interface INTERFACE_UUID("{7FD1CE91-E053-11D1-AB0B-00C04FB16FB3}") IOTAServices50  : public IInterface 
{
	
public:
	virtual int __fastcall AddNotifier(const _di_IOTAIDENotifier Notifier) = 0 ;
	virtual void __fastcall RemoveNotifier(int Index) = 0 ;
	virtual AnsiString __fastcall GetBaseRegistryKey(void) = 0 ;
	virtual AnsiString __fastcall GetProductIdentifier(void) = 0 ;
	virtual HWND __fastcall GetParentHandle(void) = 0 ;
	virtual _di_IOTAEnvironmentOptions __fastcall GetEnvironmentOptions(void) = 0 ;
};

__interface IOTAServices;
typedef System::DelphiInterface<IOTAServices> _di_IOTAServices;
__interface INTERFACE_UUID("{577ECE00-59EE-4F21-8190-9FD8A45FE550}") IOTAServices  : public IOTAServices50 
{
	
public:
	virtual AnsiString __fastcall GetActiveDesignerType(void) = 0 ;
};

__interface IOTABufferOptions60;
typedef System::DelphiInterface<IOTABufferOptions60> _di_IOTABufferOptions60;
__interface INTERFACE_UUID("{8C748540-C6C1-11D2-8139-00609792F134}") IOTABufferOptions60  : public IInterface 
{
	
public:
	virtual bool __fastcall GetAutoIndent(void) = 0 ;
	virtual bool __fastcall GetBackspaceUnindents(void) = 0 ;
	virtual bool __fastcall GetCreateBackupFile(void) = 0 ;
	virtual bool __fastcall GetCursorThroughTabs(void) = 0 ;
	virtual bool __fastcall GetInsertMode(void) = 0 ;
	virtual bool __fastcall GetGroupUndo(void) = 0 ;
	virtual bool __fastcall GetKeepTrailingBlanks(void) = 0 ;
	virtual int __fastcall GetLeftGutterWidth(void) = 0 ;
	virtual int __fastcall GetRightMargin(void) = 0 ;
	virtual bool __fastcall GetOverwriteBlocks(void) = 0 ;
	virtual bool __fastcall GetPersistentBlocks(void) = 0 ;
	virtual bool __fastcall GetPreserveLineEnds(void) = 0 ;
	virtual bool __fastcall GetSmartTab(void) = 0 ;
	virtual bool __fastcall GetSyntaxHighlight(void) = 0 ;
	virtual AnsiString __fastcall GetTabStops(void) = 0 ;
	virtual bool __fastcall GetUndoAfterSave(void) = 0 ;
	virtual int __fastcall GetUndoLimit(void) = 0 ;
	virtual bool __fastcall GetUseTabCharacter(void) = 0 ;
	virtual void __fastcall SetAutoIndent(bool Value) = 0 ;
	virtual void __fastcall SetBackspaceUnindents(bool Value) = 0 ;
	virtual void __fastcall SetCreateBackupFile(bool Value) = 0 ;
	virtual void __fastcall SetCursorThroughTabs(bool Value) = 0 ;
	virtual void __fastcall SetInsertMode(bool Value) = 0 ;
	virtual void __fastcall SetGroupUndo(bool Value) = 0 ;
	virtual void __fastcall SetKeepTrailingBlanks(bool Value) = 0 ;
	virtual void __fastcall SetLeftGutterWidth(int Value) = 0 ;
	virtual void __fastcall SetRightMargin(int Value) = 0 ;
	virtual void __fastcall SetOverwriteBlocks(bool Value) = 0 ;
	virtual void __fastcall SetPersistentBlocks(bool Value) = 0 ;
	virtual void __fastcall SetPreserveLineEnds(bool Value) = 0 ;
	virtual void __fastcall SetSmartTab(bool Value) = 0 ;
	virtual void __fastcall SetSyntaxHighlight(bool Value) = 0 ;
	virtual void __fastcall SetTabStops(const AnsiString Value) = 0 ;
	virtual void __fastcall SetUndoAfterSave(bool Value) = 0 ;
	virtual void __fastcall SetUndoLimit(int Value) = 0 ;
	virtual void __fastcall SetUseTabCharacter(bool Value) = 0 ;
	__property bool AutoIndent = {read=GetAutoIndent, write=SetAutoIndent};
	__property bool BackspaceUnindents = {read=GetBackspaceUnindents, write=SetBackspaceUnindents};
	__property bool CreateBackupFile = {read=GetCreateBackupFile, write=SetCreateBackupFile};
	__property bool CursorThroughTabs = {read=GetCursorThroughTabs, write=SetCursorThroughTabs};
	__property bool InsertMode = {read=GetInsertMode, write=SetInsertMode};
	__property bool GroupUndo = {read=GetGroupUndo, write=SetGroupUndo};
	__property bool KeepTrailingBlanks = {read=GetKeepTrailingBlanks, write=SetKeepTrailingBlanks};
	__property int LeftGutterWidth = {read=GetLeftGutterWidth, write=SetLeftGutterWidth};
	__property int RightMargin = {read=GetRightMargin, write=SetRightMargin};
	__property bool OverwriteBlocks = {read=GetOverwriteBlocks, write=SetOverwriteBlocks};
	__property bool PersistentBlocks = {read=GetPersistentBlocks, write=SetPersistentBlocks};
	__property bool PreserveLineEnds = {read=GetPreserveLineEnds, write=SetPreserveLineEnds};
	__property bool SmartTab = {read=GetSmartTab, write=SetSmartTab};
	__property bool SyntaxHighlight = {read=GetSyntaxHighlight, write=SetSyntaxHighlight};
	__property AnsiString TabStops = {read=GetTabStops, write=SetTabStops};
	__property bool UndoAfterSave = {read=GetUndoAfterSave, write=SetUndoAfterSave};
	__property int UndoLimit = {read=GetUndoLimit, write=SetUndoLimit};
	__property bool UseTabCharacter = {read=GetUseTabCharacter, write=SetUseTabCharacter};
};

__interface IOTABufferOptions;
typedef System::DelphiInterface<IOTABufferOptions> _di_IOTABufferOptions;
__interface INTERFACE_UUID("{F8F13ACE-1124-408F-934F-8E92DA135424}") IOTABufferOptions  : public IOTABufferOptions60 
{
	
public:
	virtual bool __fastcall GetShowSpace(void) = 0 ;
	virtual bool __fastcall GetShowTab(void) = 0 ;
	virtual void __fastcall SetShowSpace(bool Value) = 0 ;
	virtual void __fastcall SetShowTab(bool Value) = 0 ;
	__property bool ShowSpace = {read=GetShowSpace, write=SetShowSpace};
	__property bool ShowTab = {read=GetShowTab, write=SetShowTab};
};

__interface IOTAEditLineNotifier;
typedef System::DelphiInterface<IOTAEditLineNotifier> _di_IOTAEditLineNotifier;
__interface INTERFACE_UUID("{D9D48F50-E6CC-11D2-ABE8-00C04FB16FB3}") IOTAEditLineNotifier  : public IOTANotifier 
{
	
public:
	virtual void __fastcall LineChanged(int OldLine, int NewLine, int Data) = 0 ;
};

__interface IOTAEditLineTracker;
typedef System::DelphiInterface<IOTAEditLineTracker> _di_IOTAEditLineTracker;
__interface INTERFACE_UUID("{D9D48F4F-E6CC-11D2-ABE8-00C04FB16FB3}") IOTAEditLineTracker  : public IInterface 
{
	
public:
	virtual int __fastcall AddNotifier(const _di_IOTAEditLineNotifier Notifier) = 0 ;
	virtual void __fastcall AddLine(int Line, int Data) = 0 ;
	virtual void __fastcall Delete(int Index) = 0 ;
	virtual int __fastcall GetCount(void) = 0 ;
	virtual int __fastcall GetData(int Index) = 0 ;
	virtual _di_IOTAEditBuffer __fastcall GetEditBuffer(void) = 0 ;
	virtual int __fastcall GetLineNum(int Index) = 0 ;
	virtual int __fastcall IndexOfLine(int Line) = 0 ;
	virtual int __fastcall IndexOfData(int Data) = 0 ;
	virtual void __fastcall RemoveNotifier(int Index) = 0 ;
	virtual void __fastcall SetData(int Index, int Value) = 0 ;
	virtual void __fastcall SetLineNum(int Index, int Value) = 0 ;
	__property int Count = {read=GetCount};
	__property int Data[int Index] = {read=GetData, write=SetData};
	__property int LineNum[int Index] = {read=GetLineNum, write=SetLineNum};
};

__interface INTERFACE_UUID("{9C510460-C7BC-11D2-9AEB-00A02457621F}") IOTAEditBuffer  : public IOTASourceEditor 
{
	
public:
	virtual void __fastcall ClearUndo(void) = 0 ;
	virtual _di_IOTABufferOptions __fastcall GetBufferOptions(void) = 0 ;
	virtual System::TDateTime __fastcall GetCurrentDate(void) = 0 ;
	virtual _di_IOTAEditBlock __fastcall GetEditBlock(void) = 0 ;
	virtual _di_IOTAEditLineTracker __fastcall GetEditLineTracker(void) = 0 ;
	virtual _di_IOTAEditPosition __fastcall GetEditPosition(void) = 0 ;
	virtual System::TDateTime __fastcall GetInitialDate(void) = 0 ;
	virtual bool __fastcall GetIsModified(void) = 0 ;
	virtual bool __fastcall GetIsReadOnly(void) = 0 ;
	virtual _di_IOTAEditView __fastcall GetTopView(void) = 0 ;
	virtual bool __fastcall Print(void) = 0 ;
	virtual bool __fastcall Redo(void) = 0 ;
	virtual void __fastcall SetIsReadOnly(bool Value) = 0 ;
	virtual bool __fastcall Undo(void) = 0 ;
	__property _di_IOTABufferOptions BufferOptions = {read=GetBufferOptions};
	__property _di_IOTAEditBlock EditBlock = {read=GetEditBlock};
	__property _di_IOTAEditPosition EditPosition = {read=GetEditPosition};
	__property bool IsModified = {read=GetIsModified};
	__property bool IsReadOnly = {read=GetIsReadOnly, write=SetIsReadOnly};
	__property _di_IOTAEditView TopView = {read=GetTopView};
};

__interface IOTAEditBufferIterator;
typedef System::DelphiInterface<IOTAEditBufferIterator> _di_IOTAEditBufferIterator;
__interface INTERFACE_UUID("{8ECB33AA-D0BD-11D2-ABD6-00C04FB16FB3}") IOTAEditBufferIterator  : public IInterface 
{
	
public:
	virtual int __fastcall GetCount(void) = 0 ;
	virtual _di_IOTAEditBuffer __fastcall GetEditBuffer(int Index) = 0 ;
	__property int Count = {read=GetCount};
	__property _di_IOTAEditBuffer EditBuffers[int Index] = {read=GetEditBuffer};
};

struct TKeyBindingRec;
typedef TKeyBindingRec *PKeyBindingRec;

struct TKeyBindingRec
{
	Classes::TShortCut KeyCode;
	TKeyBindingProc KeyProc;
	void *Context;
	int Next;
	int Reserved;
} ;

__interface IOTAKeyboardServices;
typedef System::DelphiInterface<IOTAKeyboardServices> _di_IOTAKeyboardServices;
__interface INTERFACE_UUID("{3E7790CB-D2BB-11D2-ABD8-00C04FB16FB3}") IOTAKeyContext  : public IInterface 
{
	
public:
	virtual void * __fastcall GetContext(void) = 0 ;
	virtual _di_IOTAEditBuffer __fastcall GetEditBuffer(void) = 0 ;
	virtual _di_IOTAKeyboardServices __fastcall GetKeyboardServices(void) = 0 ;
	virtual bool __fastcall GetKeyBindingRec(/* out */ TKeyBindingRec &BindingRec) = 0 ;
	__property void * Context = {read=GetContext};
	__property _di_IOTAEditBuffer EditBuffer = {read=GetEditBuffer};
	__property _di_IOTAKeyboardServices KeyboardServices = {read=GetKeyboardServices};
};

__interface IOTARecord;
typedef System::DelphiInterface<IOTARecord> _di_IOTARecord;
__interface INTERFACE_UUID("{F8CAF8D6-D263-11D2-ABD8-00C04FB16FB3}") IOTARecord  : public IInterface 
{
	
public:
	virtual void __fastcall Append(const Classes::TShortCut * Keys, const int Keys_Size) = 0 /* overload */;
	virtual void __fastcall Append(const AnsiString CmdName, bool IsKeys = true) = 0 /* overload */;
	virtual void __fastcall Append(const _di_IOTARecord ARecord) = 0 /* overload */;
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall GetIsPaused(void) = 0 ;
	virtual bool __fastcall GetIsPlaying(void) = 0 ;
	virtual bool __fastcall GetIsRecording(void) = 0 ;
	virtual AnsiString __fastcall GetName(void) = 0 ;
	virtual void __fastcall ReadFromStream(const _di_IStream Stream) = 0 ;
	virtual void __fastcall SetName(const AnsiString Value) = 0 ;
	virtual void __fastcall WriteToStream(const _di_IStream Stream) = 0 ;
	__property bool IsPaused = {read=GetIsPaused};
	__property bool IsPlaying = {read=GetIsPlaying};
	__property bool IsRecording = {read=GetIsRecording};
	__property AnsiString Name = {read=GetName, write=SetName};
};

typedef int TKeyBindingFlags;

__interface IOTAKeyBindingServices;
typedef System::DelphiInterface<IOTAKeyBindingServices> _di_IOTAKeyBindingServices;
__interface INTERFACE_UUID("{F8CAF8D8-D263-11D2-ABD8-00C04FB16FB3}") IOTAKeyBindingServices  : public IInterface 
{
	
public:
	virtual bool __fastcall AddKeyBinding(const Classes::TShortCut * Keys, const int Keys_Size, TKeyBindingProc KeyProc, void * Context, int Flags = 0x7, const AnsiString Keyboard = "", const AnsiString MenuItemName = "") = 0 ;
	virtual bool __fastcall AddMenuCommand(const AnsiString Command, TKeyBindingProc KeyProc, void * Context) = 0 ;
	virtual void __fastcall SetDefaultKeyProc(TKeyBindingProc KeyProc, void * Context, const AnsiString Keyboard = "") = 0 ;
};

__interface IOTAKeyboardBinding;
typedef System::DelphiInterface<IOTAKeyboardBinding> _di_IOTAKeyboardBinding;
__interface INTERFACE_UUID("{F8CAF8D7-D263-11D2-ABD8-00C04FB16FB3}") IOTAKeyboardBinding  : public IOTANotifier 
{
	
public:
	virtual TBindingType __fastcall GetBindingType(void) = 0 ;
	virtual AnsiString __fastcall GetDisplayName(void) = 0 ;
	virtual AnsiString __fastcall GetName(void) = 0 ;
	virtual void __fastcall BindKeyboard(const _di_IOTAKeyBindingServices BindingServices) = 0 ;
	__property TBindingType BindingType = {read=GetBindingType};
	__property AnsiString DisplayName = {read=GetDisplayName};
	__property AnsiString Name = {read=GetName};
};

__interface IOTAEditorServices;
typedef System::DelphiInterface<IOTAEditorServices> _di_IOTAEditorServices;
__interface INTERFACE_UUID("{F8CAF8D5-D263-11D2-ABD8-00C04FB16FB3}") IOTAKeyboardServices  : public IInterface 
{
	
public:
	virtual int __fastcall AddKeyboardBinding(const _di_IOTAKeyboardBinding KeyBinding) = 0 ;
	virtual _di_IOTARecord __fastcall GetCurrentPlayback(void) = 0 ;
	virtual _di_IOTARecord __fastcall GetCurrentRecord(void) = 0 ;
	virtual _di_IOTAEditorServices __fastcall GetEditorServices(void) = 0 ;
	virtual unsigned __fastcall GetKeysProcessed(void) = 0 ;
	virtual bool __fastcall NewRecordObject(/* out */ _di_IOTARecord &ARecord) = 0 ;
	virtual void __fastcall PausePlayback(void) = 0 ;
	virtual void __fastcall PauseRecord(void) = 0 ;
	virtual void __fastcall PopKeyboard(const AnsiString Keyboard) = 0 ;
	virtual AnsiString __fastcall PushKeyboard(const AnsiString Keyboard) = 0 ;
	virtual void __fastcall RestartKeyboardServices(void) = 0 ;
	virtual void __fastcall ResumePlayback(void) = 0 ;
	virtual void __fastcall ResumeRecord(void) = 0 ;
	virtual void __fastcall RemoveKeyboardBinding(int Index) = 0 ;
	virtual void __fastcall SetPlaybackObject(const _di_IOTARecord ARecord) = 0 ;
	virtual void __fastcall SetRecordObject(const _di_IOTARecord ARecord) = 0 ;
	virtual bool __fastcall LookupKeyBinding(const Classes::TShortCut * Keys, const int Keys_Size, /* out */ TKeyBindingRec &BindingRec, const AnsiString KeyBoard = "") = 0 ;
	virtual bool __fastcall GetNextBindingRec(TKeyBindingRec &BindingRec) = 0 ;
	virtual TKeyBindingResult __fastcall CallKeyBindingProc(const TKeyBindingRec &BindingRec) = 0 ;
	__property _di_IOTARecord CurrentPlayback = {read=GetCurrentPlayback};
	__property _di_IOTARecord CurrentRecord = {read=GetCurrentRecord};
	__property _di_IOTAEditorServices EditorServices = {read=GetEditorServices};
	__property unsigned KeysProcessed = {read=GetKeysProcessed};
};

__interface IOTAKeyboardDiagnostics;
typedef System::DelphiInterface<IOTAKeyboardDiagnostics> _di_IOTAKeyboardDiagnostics;
__interface INTERFACE_UUID("{AEFC65F1-2504-11D3-AC25-00C04FB16FB3}") IOTAKeyboardDiagnostics  : public IInterface 
{
	
public:
	virtual bool __fastcall GetKeyTracing(void) = 0 ;
	virtual void __fastcall SetKeyTracing(bool Value) = 0 ;
	__property bool KeyTracing = {read=GetKeyTracing, write=SetKeyTracing};
};

__interface IOTASpeedSetting;
typedef System::DelphiInterface<IOTASpeedSetting> _di_IOTASpeedSetting;
__interface IOTAEditOptions;
typedef System::DelphiInterface<IOTAEditOptions> _di_IOTAEditOptions;
__interface INTERFACE_UUID("{B5CDCE07-E093-11D2-ABE2-00C04FB16FB3}") IOTASpeedSetting  : public IOTANotifier 
{
	
public:
	virtual AnsiString __fastcall GetDisplayName(void) = 0 ;
	virtual AnsiString __fastcall GetName(void) = 0 ;
	virtual void __fastcall ExecuteSetting(const _di_IOTAEditOptions EditOptions) = 0 ;
	__property AnsiString DisplayName = {read=GetDisplayName};
	__property AnsiString Name = {read=GetName};
};

__interface INTERFACE_UUID("{487BEA91-DBC0-11D2-ABDE-00C04FB16FB3}") IOTAEditOptions  : public IInterface 
{
	
public:
	virtual int __fastcall AddSpeedSetting(const _di_IOTASpeedSetting SpeedSetting) = 0 ;
	virtual void __fastcall BeginUpdate(void) = 0 ;
	virtual void __fastcall EndUpdate(void) = 0 ;
	virtual int __fastcall GetBlockIndent(void) = 0 ;
	virtual _di_IOTABufferOptions __fastcall GetBufferOptions(void) = 0 ;
	virtual AnsiString __fastcall GetFontName(void) = 0 ;
	virtual int __fastcall GetFontSize(void) = 0 ;
	virtual bool __fastcall GetForceCutCopyEnabled(void) = 0 ;
	virtual int __fastcall GetSpeedSettingCount(void) = 0 ;
	virtual _di_IOTASpeedSetting __fastcall GetSpeedSetting(int Index) = 0 ;
	virtual AnsiString __fastcall GetSyntaxHighlightTypes(TOTASyntaxHighlighter Index) = 0 ;
	virtual bool __fastcall GetUseBriefCursorShapes(void) = 0 ;
	virtual bool __fastcall GetUseBriefRegularExpressions(void) = 0 ;
	virtual void __fastcall RemoveSpeedSetting(int Index) = 0 ;
	virtual void __fastcall SetBlockIndent(int Value) = 0 ;
	virtual void __fastcall SetFontName(const AnsiString Value) = 0 ;
	virtual void __fastcall SetFontSize(int Value) = 0 ;
	virtual void __fastcall SetForceCutCopyEnabled(bool Value) = 0 ;
	virtual void __fastcall SetSpeedSetting(const AnsiString Name) = 0 ;
	virtual void __fastcall SetSyntaxHighlightTypes(TOTASyntaxHighlighter Index, const AnsiString Value) = 0 ;
	virtual void __fastcall SetUseBriefCursorShapes(bool Value) = 0 ;
	virtual void __fastcall SetUseBriefRegularExpressions(bool Value) = 0 ;
	__property int BlockIndent = {read=GetBlockIndent, write=SetBlockIndent};
	__property _di_IOTABufferOptions BufferOptions = {read=GetBufferOptions};
	__property AnsiString FontName = {read=GetFontName, write=SetFontName};
	__property int FontSize = {read=GetFontSize, write=SetFontSize};
	__property bool ForceCutCopyEnabled = {read=GetForceCutCopyEnabled, write=SetForceCutCopyEnabled};
	__property int SpeedSettingCount = {read=GetSpeedSettingCount};
	__property _di_IOTASpeedSetting SpeedSettings[int Index] = {read=GetSpeedSetting};
	__property AnsiString SyntaxHighlightTypes[TOTASyntaxHighlighter Index] = {read=GetSyntaxHighlightTypes, write=SetSyntaxHighlightTypes};
	__property bool UseBriefCursorShapes = {read=GetUseBriefCursorShapes, write=SetUseBriefCursorShapes};
	__property bool UseBriefRegularExpressions = {read=GetUseBriefRegularExpressions, write=SetUseBriefRegularExpressions};
};

__interface INTERFACE_UUID("{C2812BA7-C48D-11D2-9AE8-00A02457621F}") IOTAEditorServices  : public IInterface 
{
	
public:
	virtual _di_IOTAEditOptions __fastcall GetEditOptions(void) = 0 ;
	virtual bool __fastcall GetEditBufferIterator(/* out */ _di_IOTAEditBufferIterator &Iterator) = 0 ;
	virtual _di_IOTAKeyboardServices __fastcall GetKeyboardServices(void) = 0 ;
	virtual _di_IOTAEditBuffer __fastcall GetTopBuffer(void) = 0 ;
	virtual _di_IOTAEditView __fastcall GetTopView(void) = 0 ;
	__property _di_IOTAEditOptions EditOptions = {read=GetEditOptions};
	__property _di_IOTAKeyboardServices KeyboardServices = {read=GetKeyboardServices};
	__property _di_IOTAEditBuffer TopBuffer = {read=GetTopBuffer};
	__property _di_IOTAEditView TopView = {read=GetTopView};
};

__interface INTAToDoItem;
typedef System::DelphiInterface<INTAToDoItem> _di_INTAToDoItem;
__interface INTERFACE_UUID("{094003D8-E7AA-11D2-AA99-00C04FA35CE8}") INTAToDoItem  : public IInterface 
{
	
public:
	virtual bool __fastcall CanDelete(void) = 0 ;
	virtual bool __fastcall CanEdit(void) = 0 ;
	virtual bool __fastcall CanShow(void) = 0 ;
	virtual void __fastcall Delete(void) = 0 ;
	virtual void __fastcall DrawImage(const Graphics::TCanvas* Canvas, const Types::TRect &Rect) = 0 ;
	virtual void __fastcall DoubleClicked(void) = 0 ;
	virtual void __fastcall Edit(void) = 0 ;
	virtual AnsiString __fastcall GetText(void) = 0 ;
	virtual TOTAToDoPriority __fastcall GetPriority(void) = 0 ;
	virtual AnsiString __fastcall GetCategory(void) = 0 ;
	virtual bool __fastcall GetChecked(void) = 0 ;
	virtual AnsiString __fastcall GetModuleName(void) = 0 ;
	virtual AnsiString __fastcall GetKind(void) = 0 ;
	virtual int __fastcall GetData(void) = 0 ;
	virtual AnsiString __fastcall GetOwner(void) = 0 ;
	virtual bool __fastcall IsValid(void) = 0 ;
	virtual void __fastcall SetChecked(const bool Value) = 0 ;
	virtual void __fastcall Show(void) = 0 ;
	__property bool Checked = {read=GetChecked, write=SetChecked};
};

__interface IOTAToDoManager;
typedef System::DelphiInterface<IOTAToDoManager> _di_IOTAToDoManager;
__interface INTERFACE_UUID("{3D4A0565-EB77-11D2-AA9A-00C04FA35CE8}") IOTAToDoManager  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall GetName(void) = 0 ;
	virtual void __fastcall SetName(const AnsiString AName) = 0 ;
	virtual _di_INTAToDoItem __fastcall GetItem(int Index) = 0 ;
	virtual int __fastcall GetItemCount(void) = 0 ;
	virtual void __fastcall ProjectChanged(void) = 0 ;
	__property AnsiString Name = {read=GetName, write=SetName};
	__property int ItemCount = {read=GetItemCount};
	__property _di_INTAToDoItem Items[int Index] = {read=GetItem};
};

__interface IOTAToDoServices;
typedef System::DelphiInterface<IOTAToDoServices> _di_IOTAToDoServices;
__interface INTERFACE_UUID("{F8FC00EF-E61A-11D2-AA99-00C04FA35CE8}") IOTAToDoServices  : public IInterface 
{
	
public:
	virtual int __fastcall AddManager(_di_IOTAToDoManager AManager) = 0 ;
	virtual int __fastcall AddNotifier(const _di_IOTANotifier ANotifier) = 0 ;
	virtual _di_INTAToDoItem __fastcall GetItem(int Index) = 0 ;
	virtual int __fastcall GetItemCount(void) = 0 ;
	virtual void __fastcall RemoveManager(int Index) = 0 ;
	virtual void __fastcall RemoveNotifier(int Index) = 0 ;
	virtual void __fastcall UpdateList(void) = 0 ;
	__property int ItemCount = {read=GetItemCount};
	__property _di_INTAToDoItem Items[int Index] = {read=GetItem};
};

#pragma option push -b-
enum TOTAInvokeType { itAuto, itManual, itTimer };
#pragma option pop

#pragma option push -b-
enum TOTACodeInsightType { citNone, citCodeInsight, citParameterCodeInsight, citBrowseCodeInsight, citHintCodeInsight };
#pragma option pop

#pragma option push -b-
enum TOTASortOrder { soAlpha, soScope };
#pragma option pop

#pragma option push -b-
enum TOTAViewerSymbolFlags { vsfUnknown, vsfConstant, vsfType, vsfVariable, vsfProcedure, vsfFunction, vsfUnit, vsfLabel, vsfProperty, vsfConstructor, vsfDestructor, vsfInterface, vsfEvent };
#pragma option pop

#pragma option push -b-
enum TOTAViewerVisibilityFlags { vvfPrivate, vvfProtected, vvfPublic, vvfPublished };
#pragma option pop

#pragma option push -b-
enum TOTAProcDispatchFlags { pdfNone, pdfVirtual, pdfDynamic };
#pragma option pop

__interface IOTACodeInsightSymbolList;
typedef System::DelphiInterface<IOTACodeInsightSymbolList> _di_IOTACodeInsightSymbolList;
__interface INTERFACE_UUID("{4CA1CDFD-BD9A-4628-94AE-9BF3EB2DA22E}") IOTACodeInsightSymbolList  : public IInterface 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual int __fastcall GetCount(void) = 0 ;
	virtual bool __fastcall GetSymbolIsReadWrite(int I) = 0 ;
	virtual bool __fastcall GetSymbolIsAbstract(int I) = 0 ;
	virtual TOTAViewerSymbolFlags __fastcall GetViewerSymbolFlags(int I) = 0 ;
	virtual TOTAViewerVisibilityFlags __fastcall GetViewerVisibilityFlags(int I) = 0 ;
	virtual TOTAProcDispatchFlags __fastcall GetProcDispatchFlags(int I) = 0 ;
	virtual void __fastcall SetSortOrder(const TOTASortOrder Value) = 0 ;
	virtual TOTASortOrder __fastcall GetSortOrder(void) = 0 ;
	virtual int __fastcall FindIdent(const AnsiString AnIdent) = 0 ;
	virtual bool __fastcall FindSymIndex(const AnsiString Ident, int &Index) = 0 ;
	virtual void __fastcall SetFilter(const AnsiString FilterText) = 0 ;
	virtual AnsiString __fastcall GetSymbolText(int Index) = 0 ;
	virtual AnsiString __fastcall GetSymbolTypeText(int Index) = 0 ;
	virtual AnsiString __fastcall GetSymbolClassText(int I) = 0 ;
	__property AnsiString SymbolClassText[int I] = {read=GetSymbolClassText};
	__property AnsiString SymbolTypeText[int I] = {read=GetSymbolTypeText};
	__property AnsiString SymbolText[int I] = {read=GetSymbolText};
	__property TOTAViewerSymbolFlags SymbolFlags[int I] = {read=GetViewerSymbolFlags};
	__property TOTAViewerVisibilityFlags SymbolVisibility[int I] = {read=GetViewerVisibilityFlags};
	__property bool SymbolIsAbstract[int I] = {read=GetSymbolIsAbstract};
	__property bool SymbolIsReadWrite[int I] = {read=GetSymbolIsReadWrite};
	__property TOTAProcDispatchFlags FuncDispatchFlags[int I] = {read=GetProcDispatchFlags};
	__property TOTASortOrder SortOrder = {read=GetSortOrder, write=SetSortOrder};
	__property int Count = {read=GetCount};
};

__interface IOTACodeInsightParamQuery;
typedef System::DelphiInterface<IOTACodeInsightParamQuery> _di_IOTACodeInsightParamQuery;
__interface INTERFACE_UUID("{B1842926-C7F7-4869-B55A-CFDB6BF705B5}") IOTACodeInsightParamQuery  : public IInterface 
{
	
public:
	virtual int __fastcall GetQueryParamCount(void) = 0 ;
	virtual AnsiString __fastcall GetQueryRetVal(void) = 0 ;
	virtual AnsiString __fastcall GetQueryParamSymText(int Index) = 0 ;
	virtual AnsiString __fastcall GetQueryParamTypeText(int Index) = 0 ;
	virtual bool __fastcall GetQueryParamHasDefaultVal(int Index) = 0 ;
	virtual AnsiString __fastcall GetQueryParamInvokeTypeText(int Index) = 0 ;
	__property AnsiString RetValType = {read=GetQueryRetVal};
	__property AnsiString ParamSymText[int Index] = {read=GetQueryParamSymText};
	__property AnsiString ParamTypeText[int Index] = {read=GetQueryParamTypeText};
	__property int ParamCount = {read=GetQueryParamCount};
	__property bool ParamHasDefaultVal[int Index] = {read=GetQueryParamHasDefaultVal};
	__property AnsiString ParamInvokeTypeText[int Index] = {read=GetQueryParamInvokeTypeText};
};

__interface IOTACodeInsightParameterList;
typedef System::DelphiInterface<IOTACodeInsightParameterList> _di_IOTACodeInsightParameterList;
__interface INTERFACE_UUID("{99B6A644-3E97-48A1-9758-0A5FE94767C7}") IOTACodeInsightParameterList  : public IInterface 
{
	
public:
	virtual void __fastcall GetParameterQuery(int ProcIndex, /* out */ _di_IOTACodeInsightParamQuery &ParamQuery) = 0 ;
	virtual char __fastcall GetParamDelimiter(void) = 0 ;
	virtual int __fastcall GetProcedureCount(void) = 0 ;
	virtual AnsiString __fastcall GetProcedureParamsText(int I) = 0 ;
	__property AnsiString ProcedureParamsText[int I] = {read=GetProcedureParamsText};
	__property int ProcedureCount = {read=GetProcedureCount};
	__property char ParamDelimiter = {read=GetParamDelimiter};
};

__interface IOTACodeInsightManager;
typedef System::DelphiInterface<IOTACodeInsightManager> _di_IOTACodeInsightManager;
__interface INTERFACE_UUID("{BA5B444A-6E78-4A79-BF05-E184C1132B30}") IOTACodeInsightManager  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall GetName(void) = 0 ;
	virtual AnsiString __fastcall GetIDString(void) = 0 ;
	virtual bool __fastcall GetEnabled(void) = 0 ;
	virtual void __fastcall SetEnabled(bool Value) = 0 ;
	virtual Sysutils::TSysCharSet __fastcall EditorTokenValidChars(bool PreValidating) = 0 ;
	virtual void __fastcall AllowCodeInsight(bool &Allow, const char Key) = 0 ;
	virtual bool __fastcall PreValidateCodeInsight(const AnsiString Str) = 0 ;
	virtual bool __fastcall IsViewerBrowsable(int Index) = 0 ;
	virtual bool __fastcall GetMultiSelect(void) = 0 ;
	virtual void __fastcall GetSymbolList(/* out */ _di_IOTACodeInsightSymbolList &SymbolList) = 0 ;
	virtual void __fastcall OnEditorKey(char Key, bool &CloseViewer, bool &Accept) = 0 ;
	virtual bool __fastcall HandlesFile(const AnsiString AFileName) = 0 ;
	virtual AnsiString __fastcall GetLongestItem(void) = 0 ;
	virtual void __fastcall GetParameterList(/* out */ _di_IOTACodeInsightParameterList &ParameterList) = 0 ;
	virtual void __fastcall GetCodeInsightType(char AChar, int AElement, /* out */ TOTACodeInsightType &CodeInsightType, /* out */ TOTAInvokeType &InvokeType) = 0 ;
	virtual bool __fastcall InvokeCodeCompletion(TOTAInvokeType HowInvoked, AnsiString &Str) = 0 ;
	virtual bool __fastcall InvokeParameterCodeInsight(TOTAInvokeType HowInvoked, int &SelectedIndex) = 0 ;
	virtual void __fastcall ParameterCodeInsightAnchorPos(TOTAEditPos &EdPos) = 0 ;
	virtual int __fastcall ParameterCodeInsightParamIndex(const TOTAEditPos &EdPos) = 0 ;
	virtual AnsiString __fastcall GetHintText(int HintLine, int HintCol) = 0 ;
	virtual bool __fastcall GotoDefinition(/* out */ AnsiString &AFileName, /* out */ int &ALineNum, int Index = 0xffffffff) = 0 ;
	virtual void __fastcall Done(bool Accepted, /* out */ bool &DisplayParams) = 0 ;
	__property AnsiString Name = {read=GetName};
	__property bool MultiSelect = {read=GetMultiSelect};
	__property bool Enabled = {read=GetEnabled, write=SetEnabled};
};

__interface IOTACodeInsightViewer;
typedef System::DelphiInterface<IOTACodeInsightViewer> _di_IOTACodeInsightViewer;
__interface INTERFACE_UUID("{AAA55FAC-350E-4F43-9C42-4FC28B6BFE33}") IOTACodeInsightViewer  : public IInterface 
{
	
public:
	virtual bool __fastcall GetSelected(int Index) = 0 ;
	virtual int __fastcall GetItemCount(void) = 0 ;
	virtual AnsiString __fastcall GetSelectedString(void) = 0 ;
	virtual int __fastcall GetSelectedIndex(void) = 0 ;
	virtual char __fastcall GetCloseKey(void) = 0 ;
	virtual bool __fastcall GetIsValidSelection(void) = 0 ;
	__property bool Selected[int Index] = {read=GetSelected};
	__property int ItemCount = {read=GetItemCount};
	__property AnsiString SelectedString = {read=GetSelectedString};
	__property int SelectedIndex = {read=GetSelectedIndex};
	__property char CloseKey = {read=GetCloseKey};
	__property bool IsValidSelection = {read=GetIsValidSelection};
};

__interface INTACustomDrawCodeInsightViewer;
typedef System::DelphiInterface<INTACustomDrawCodeInsightViewer> _di_INTACustomDrawCodeInsightViewer;
__interface INTERFACE_UUID("{32CA7B43-9AFC-49CF-ABC9-7ECD772488D9}") INTACustomDrawCodeInsightViewer  : public IInterface 
{
	
public:
	virtual void __fastcall DrawLine(int Index, Graphics::TCanvas* Canvas, Types::TRect &Rect, bool DrawingHintText, bool DoDraw, bool &DefaultDraw) = 0 ;
};

__interface IOTACodeInsightServices;
typedef System::DelphiInterface<IOTACodeInsightServices> _di_IOTACodeInsightServices;
__interface INTERFACE_UUID("{476904F8-89A9-4CD8-A71E-164660659763}") IOTACodeInsightServices  : public IInterface 
{
	
public:
	virtual void __fastcall GetEditView(/* out */ _di_IOTAEditView &EditView) = 0 ;
	virtual void __fastcall GetViewer(/* out */ _di_IOTACodeInsightViewer &Viewer) = 0 ;
	virtual void __fastcall GetCurrentCodeInsightManager(/* out */ _di_IOTACodeInsightManager &CodeInsightManager) = 0 ;
	virtual void __fastcall CancelCodeInsightProcessing(void) = 0 ;
	virtual int __fastcall AddCodeInsightManager(const _di_IOTACodeInsightManager ACodeInsightManager) = 0 ;
	virtual void __fastcall RemoveCodeInsightManager(int Index) = 0 ;
	virtual void __fastcall InsertText(const AnsiString Str, bool Replace) = 0 ;
	virtual int __fastcall GetCodeInsightManagerCount(void) = 0 ;
	virtual _di_IOTACodeInsightManager __fastcall GetCodeInsightManager(int Index) = 0 ;
	__property int CodeInsightManagerCount = {read=GetCodeInsightManagerCount};
	__property _di_IOTACodeInsightManager CodeInsightManager[int Index] = {read=GetCodeInsightManager};
};

__interface INTERFACE_UUID("{7FD1CE92-E053-11D1-AB0B-00C04FB16FB3}") IBorlandIDEServices  : public IInterface 
{
	
};

//-- var, const, procedure ---------------------------------------------------
static const Shortint utForm = 0x0;
static const Shortint utDataModule = 0x1;
static const Shortint utProjUnit = 0x2;
static const Shortint utUnit = 0x3;
static const Shortint utRc = 0x4;
static const Shortint utAsm = 0x5;
static const Shortint utDef = 0x6;
static const Shortint utObj = 0x7;
static const Shortint utRes = 0x8;
static const Shortint utLib = 0x9;
static const Shortint utTypeLib = 0xa;
static const Shortint utPackageImport = 0xb;
static const Shortint utFormResource = 0xc;
static const Shortint utNoMake = 0xd;
static const Shortint atWhiteSpace = 0x0;
static const Shortint atComment = 0x1;
static const Shortint atReservedWord = 0x2;
static const Shortint atIdentifier = 0x3;
static const Shortint atSymbol = 0x4;
static const Shortint atString = 0x5;
static const Shortint atNumber = 0x6;
static const Shortint atFloat = 0x7;
static const Shortint atOctal = 0x8;
static const Shortint atHex = 0x9;
static const Shortint atCharacter = 0xa;
static const Shortint atPreproc = 0xb;
static const Shortint atIllegal = 0xc;
static const Shortint atAssembler = 0xd;
static const Shortint SyntaxOff = 0xe;
static const Shortint MarkedBlock = 0xf;
static const Shortint SearchMatch = 0x10;
static const Shortint RightMargin = 0x25;
static const Shortint lfCurrentEIP = 0x1;
static const Shortint lfBreakpointEnabled = 0x2;
static const Shortint lfBreakpointDisabled = 0x4;
static const Shortint lfBreakpointInvalid = 0x8;
static const Shortint lfErrorLine = 0x10;
static const Shortint lfBreakpointVerified = 0x20;
static const Shortint lfBackgroundBkpt = 0x40;
static const Byte lfBackgroupEIP = 0x80;
#define mcGetFindString "GetFindString"
#define mcReplace "Replace"
#define mcRepeatSearch "RepeatSearch"
#define mcIncrementalSearch "IncrementalSearch"
#define mcGotoLine "GotoLine"
#define mcClipCut "ClipCut"
#define mcClipCopy "ClipCopy"
#define mcClipPaste "ClipPaste"
#define mcClipClear "ClipClear"
#define mcHelpKeywordSearch "HelpKeywordSearch"
#define mcOpenFileAtCursor "OpenFileAtCursor"
#define mcToggleBreakpoint "ToggleBreakpoint"
#define mcRunToHere "RunToHere"
#define mcUndo "Undo"
#define mcRedo "Redo"
#define mcModify "Modify"
#define mcAddWatchAtCursor "AddWatchAtCursor"
#define mcInspectAtCursor "InspectAtCursor"
#define mcSetMark0 "setMark0"
#define mcSetMark1 "setMark1"
#define mcSetMark2 "setMark2"
#define mcSetMark3 "setMark3"
#define mcSetMark4 "setMark4"
#define mcSetMark5 "setMark5"
#define mcSetMark6 "setMark6"
#define mcSetMark7 "setMark7"
#define mcSetMark8 "setMark8"
#define mcSetMark9 "setMark9"
#define mcMoveToMark0 "moveToMark0"
#define mcMoveToMark1 "moveToMark1"
#define mcMoveToMark2 "moveToMark2"
#define mcMoveToMark3 "moveToMark3"
#define mcMoveToMark4 "moveToMark4"
#define mcMoveToMark5 "moveToMark5"
#define mcMoveToMark6 "moveToMark6"
#define mcMoveToMark7 "moveToMark7"
#define mcMoveToMark8 "moveToMark8"
#define mcMoveToMark9 "moveToMark9"
#define sEditor "editor"
#define dVCL "dfm"
#define dCLX "xfm"
#define dAny "Any"
#define WizardEntryPoint "INITWIZARD0001"
#define isWizards "Wizards"
#define sCustomToolBar "CustomToolBar"
#define sStandardToolBar "StandardToolBar"
#define sDebugToolBar "DebugToolBar"
#define sViewToolBar "ViewToolBar"
#define sDesktopToolBar "DesktopToolBar"
#define sInternetToolBar "InternetToolBar"
#define sCORBAToolBar "CORBAToolBar"
#define sApplication "Application"
#define sLibrary "Library"
#define sConsole "Console"
#define sPackage "Package"
#define sUnit "Unit"
#define sForm "Form"
#define sText "Text"
static const Shortint mmSkipWord = 0x0;
static const Shortint mmSkipNonWord = 0x1;
static const Shortint mmSkipWhite = 0x2;
static const Shortint mmSkipNonWhite = 0x3;
static const Shortint mmSkipSpecial = 0x4;
static const Shortint mmSkipNonSpecial = 0x5;
static const Shortint mmSkipLeft = 0x0;
static const Shortint mmSkipRight = 0x10;
static const Shortint mmSkipStream = 0x20;
static const Shortint csCodelist = 0x1;
static const Shortint csParamList = 0x2;
static const Byte csManual = 0x80;
static const Shortint kfImplicitShift = 0x1;
static const Shortint kfImplicitModifier = 0x2;
static const Shortint kfImplicitKeypad = 0x4;
static const Word rfBackward = 0x100;
static const Word rfInvertLegalChars = 0x1000;
static const Shortint rfIncludeUpperAlphaChars = 0x1;
static const Shortint rfIncludeLowerAlphaChars = 0x2;
static const Shortint rfIncludeAlphaChars = 0x3;
static const Shortint rfIncludeNumericChars = 0x4;
static const Shortint rfIncludeSpecialChars = 0x8;
static const Shortint omtForm = 0x0;
static const Shortint omtDataModule = 0x1;
static const Shortint omtProjUnit = 0x2;
static const Shortint omtUnit = 0x3;
static const Shortint omtRc = 0x4;
static const Shortint omtAsm = 0x5;
static const Shortint omtDef = 0x6;
static const Shortint omtObj = 0x7;
static const Shortint omtRes = 0x8;
static const Shortint omtLib = 0x9;
static const Shortint omtTypeLib = 0xa;
static const Shortint omtPackageImport = 0xb;
static const Shortint omtFormResource = 0xc;
static const Shortint omtCustom = 0xd;
static const Shortint omtIDL = 0xe;
extern PACKAGE _di_IBorlandIDEServices BorlandIDEServices;
extern PACKAGE TWizardRegisterProc LibraryWizardProc;
extern PACKAGE void __fastcall RegisterPackageWizard(const _di_IOTAWizard Wizard);

}	/* namespace Toolsapi */
using namespace Toolsapi;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ToolsAPI
