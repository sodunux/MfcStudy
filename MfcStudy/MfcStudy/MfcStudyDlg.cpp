
// MfcStudyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MfcStudy.h"
#include "MfcStudyDlg.h"
#include "afxdialogex.h"
//#include "TipDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMfcStudyDlg 对话框




CMfcStudyDlg::CMfcStudyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMfcStudyDlg::IDD, pParent)
	, m_editSummand(0)
	, m_editAddend(0)
	, m_editSum(0)
	, path(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pTipDlg=NULL;
}

CMfcStudyDlg::~CMfcStudyDlg()
{
	if(NULL!=m_pTipDlg)
	{
		delete m_pTipDlg;
	}
}

void CMfcStudyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SUMMAND_EDIT, m_editSummand);
	DDX_Text(pDX, IDC_ADDEND_EDIT, m_editAddend);
	DDX_Text(pDX, IDC_SUM_EDIT, m_editSum);
	DDX_Text(pDX, IDC_OPEN_EDIT, path);
}

BEGIN_MESSAGE_MAP(CMfcStudyDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMfcStudyDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CMfcStudyDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_ADD_BUTTON, &CMfcStudyDlg::OnBnClickedAddButton)
	ON_BN_CLICKED(IDC_BUTTON1, &CMfcStudyDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMfcStudyDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMfcStudyDlg 消息处理程序

BOOL CMfcStudyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMfcStudyDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMfcStudyDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMfcStudyDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMfcStudyDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	
}


void CMfcStudyDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CMfcStudyDlg::OnBnClickedAddButton()
{
	// TODO: 在此添加控件通知处理程序代码
	INT_PTR nRes;
	//CTipDlg tipDlg;
	//nRes=tipDlg.DoModal();
	//if(IDCANCEL==nRes)
	//	return; 
	//if(NULL==m_pTipDlg)
	//{
	//	m_pTipDlg=new CTipDlg();
	//	m_pTipDlg->Create(IDD_TIP_DIALOG,this);

	//}

	//m_pTipDlg->ShowWindow(SW_SHOW);

	//nRes = MessageBox(_T("您确定要进行加法计算吗？"), _T("加法计算器"), MB_OKCANCEL | MB_ICONQUESTION);
	nRes = AfxMessageBox(_T("您确定要进行加法计算吗？"),  MB_ICONWARNING,0);
	if(nRes==IDCANCEL) return;
	UpdateData(TRUE);
	m_editSum=m_editSummand+m_editAddend;
	UpdateData(FALSE);
}


void CMfcStudyDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	TCHAR szFilter[] = _T("文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||");
	CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);
	CString strFilePath;
	if (IDOK == fileDlg.DoModal())   
	{   
		// 如果点击了文件对话框上的“打开”按钮，则将选择的文件路径显示到编辑框里   
		strFilePath = fileDlg.GetPathName();
		path=strFilePath;
		UpdateData(FALSE);
		 
	}
}


void CMfcStudyDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	TCHAR szFilter[] = _T("文本文件(*.txt)|*.txt|Word文件(*.doc)|*.doc|所有文件(*.*)|*.*||"); 
	CFileDialog fileDlg(FALSE, _T("doc"), _T("my"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, this);
	CString strFilePath;
	if (IDOK == fileDlg.DoModal())   
	{   
		// 如果点击了文件对话框上的“保存”按钮，则将选择的文件路径显示到编辑框里   
		strFilePath = fileDlg.GetPathName();   
		path=strFilePath;
		UpdateData(FALSE);
	} 
}
