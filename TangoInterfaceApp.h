// TangoInterfaceApp.h : main header file for the TangoInterface DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CTangoInterfaceApp
// See TangoInterfaceApp.cpp for the implementation of this class
//

class CTangoInterfaceApp : public CWinApp
{
public:
	CTangoInterfaceApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
