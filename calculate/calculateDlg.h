// calculateDlg.h : header file
//

#if !defined(AFX_CALCULATEDLG_H__17CF47FA_488B_4BC5_AA27_C13FA143EF62__INCLUDED_)
#define AFX_CALCULATEDLG_H__17CF47FA_488B_4BC5_AA27_C13FA143EF62__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCalculateDlg dialog

class CCalculateDlg : public CDialog
{
// Construction
public:
	CCalculateDlg(CWnd* pParent = NULL);	// standard constructor
	//输入的数字a
	CEdit* input_a;
	//输入的数组b
	CEdit* input_b;
	//输出的数字
	CEdit* output;
	//加
	CButton* add_number;
	//减
	CButton* sub_number;
	//乘
	CButton* mul_number;
	//除
	CButton* div_number;
// Dialog Data
	//{{AFX_DATA(CCalculateDlg)
	enum { IDD = IDD_CALCULATE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCalculateDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCalculateDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALCULATEDLG_H__17CF47FA_488B_4BC5_AA27_C13FA143EF62__INCLUDED_)
