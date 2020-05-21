// calculate.h : main header file for the CALCULATE application
//

#if !defined(AFX_CALCULATE_H__40DBC5DA_4C3C_432E_AA3B_3A387367E24B__INCLUDED_)
#define AFX_CALCULATE_H__40DBC5DA_4C3C_432E_AA3B_3A387367E24B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCalculateApp:
// See calculate.cpp for the implementation of this class
//

class CCalculateApp : public CWinApp
{
public:
	CCalculateApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCalculateApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCalculateApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALCULATE_H__40DBC5DA_4C3C_432E_AA3B_3A387367E24B__INCLUDED_)
