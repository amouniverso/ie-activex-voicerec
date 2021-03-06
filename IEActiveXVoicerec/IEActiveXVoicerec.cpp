// IEActiveXVoicerec.cpp : Implementation of CIEActiveXVoicerecApp and DLL registration.

#include "stdafx.h"
#include "IEActiveXVoicerec.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CIEActiveXVoicerecApp theApp;

const GUID CDECL _tlid = {0xf475510b,0x9b86,0x4875,{0xae,0x92,0xb3,0xc5,0x25,0xd6,0xc3,0x5c}};
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CIEActiveXVoicerecApp::InitInstance - DLL initialization

BOOL CIEActiveXVoicerecApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: Add your own module initialization code here.
	}

	return bInit;
}



// CIEActiveXVoicerecApp::ExitInstance - DLL termination

int CIEActiveXVoicerecApp::ExitInstance()
{
	// TODO: Add your own module termination code here.

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
