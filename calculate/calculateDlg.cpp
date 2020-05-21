// calculateDlg.cpp : implementation file
//

#include "stdafx.h"
#include "calculate.h"
#include "calculateDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCalculateDlg dialog

CCalculateDlg::CCalculateDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCalculateDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCalculateDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCalculateDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCalculateDlg, CDialog)
	//{{AFX_MSG_MAP(CCalculateDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCalculateDlg message handlers

BOOL CCalculateDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	//进行指针赋值
	input_a = (CEdit *)GetDlgItem(IDC_EDIT1);
	input_b = (CEdit *)GetDlgItem(IDC_EDIT2);
	output = (CEdit *)GetDlgItem(IDC_EDIT3);
	add_number=(CButton *)GetDlgItem(IDC_BUTTON1);
	sub_number=(CButton *)GetDlgItem(IDC_BUTTON2);
	mul_number=(CButton *)GetDlgItem(IDC_BUTTON3);
	div_number=(CButton *)GetDlgItem(IDC_BUTTON4);

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCalculateDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCalculateDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCalculateDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
//字符串转数字
int CString_to_number(CString number)
{
	//判断是否负数
	bool flag=false;
	if(number[0]=='-')
		flag=true;
	int ans=0;
	int i;
	for(i=0;i<number.GetLength();i++)
	{
		if(number[i]=='-')continue;
		ans*=10;
		ans+=(number[i]-'0');
	}
	//为负数
	if(flag)
		ans*=-1;
	return ans;
}
//数字转字符串
CString number_to_CString(int number)
{
	if(number==0)
		return "0";
	bool flag=false;
	if(number<0)
	{
		//负数转正数方便运算
		number*=-1;
		flag=true;
	}
	CString s1,s2;
	while(number>0)
	{
		s1+=(number%10+'0');
		number/=10;
	}
	//s1是number的翻转的数字，需要再次翻转
	int i;
	//如果为负数
	if(flag)
		s2="-";
	//翻转
	for(i=s1.GetLength()-1;i>=0;i--)
	{
		s2+=s1[i];
	}
	return s2;
}
void CCalculateDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CString a,b;
	//获取文本框输入的内容
	input_a->GetWindowText(a);
	input_b->GetWindowText(b);
	//字符串转数字
	int a1=CString_to_number(a);
	int b1=CString_to_number(b);
	int c1=a1+b1;
	//数字转字符串
	CString c=number_to_CString(c1);
	//设置文本框的内容为c，实现输出
	output->SetWindowText(c);
}

void CCalculateDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	CString a,b;
	//获取文本框输入的内容
	input_a->GetWindowText(a);
	input_b->GetWindowText(b);
	//字符串转数字
	int a1=CString_to_number(a);
	int b1=CString_to_number(b);
	int c1=a1-b1;
	//数字转字符串
	CString c=number_to_CString(c1);
	//设置文本框的内容为c，实现输出
	output->SetWindowText(c);
}

void CCalculateDlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
	CString a,b;
	//获取文本框输入的内容
	input_a->GetWindowText(a);
	input_b->GetWindowText(b);
	//字符串转数字
	int a1=CString_to_number(a);
	int b1=CString_to_number(b);
	int c1=a1*b1;
	//数字转字符串
	CString c=number_to_CString(c1);
	//设置文本框的内容为c，实现输出
	output->SetWindowText(c);
}

void CCalculateDlg::OnButton4() 
{
	
	// TODO: Add your control notification handler code here
	CString a,b;
	//获取文本框输入的内容
	input_a->GetWindowText(a);
	input_b->GetWindowText(b);
	//字符串转数字
	int a1=CString_to_number(a);
	int b1=CString_to_number(b);
	int c1=a1/b1;
	//数字转字符串
	CString c=number_to_CString(c1);
	//设置文本框的内容为c，实现输出
	output->SetWindowText(c);	
	
}
