
// Test_GUIDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "Test_GUI.h"
#include "Test_GUIDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTestGUIDlg 对话框



CTestGUIDlg::CTestGUIDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TEST_GUI_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestGUIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_MESSAGE, m_list_message);
	DDX_Control(pDX, IDC_LIST_DI, m_list_di);
	DDX_Control(pDX, IDC_LIST_DO, m_list_do);
}

BEGIN_MESSAGE_MAP(CTestGUIDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CTestGUIDlg 消息处理程序

BOOL CTestGUIDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	My_Init();
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CTestGUIDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CTestGUIDlg::OnPaint()
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
HCURSOR CTestGUIDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTestGUIDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}

void CTestGUIDlg::My_Init()
{
	Icon_Init();
	List_Message_Init();
	List_Do_Init();
	List_Di_Init();
}

//List_Message 初始化
void CTestGUIDlg::List_Message_Init()
{
	CString str[] = { TEXT("Num"),TEXT("Type"),
		TEXT("Parameter0"),TEXT("Parameter1"),TEXT("Parameter3"),TEXT("Parameter4") };
	for (size_t i = 0; i < sizeof(str) / sizeof(str[0]); i++)
	{
		m_list_message.InsertColumn(i, str[i], LVCFMT_LEFT, 110);
	}
}

//List_DO 初始化
void CTestGUIDlg::List_Do_Init()
{
	CString str[] = { TEXT("Num"),TEXT("State")};
	for (size_t i = 0; i < sizeof(str) / sizeof(str[0]); i++)
	{
		m_list_do.InsertColumn(i, str[i], LVCFMT_LEFT, 100);
	}
}

#if 1
void CTestGUIDlg::List_Di_Init()
{
	CString str[] = { TEXT("Num"),TEXT("State") };
	for (size_t i = 0; i < sizeof(str) / sizeof(str[0]); i++)
	{
		m_list_di.InsertColumn(i, str[i], LVCFMT_LEFT, 100);
	}

	CString snum;
	for (size_t i = 0; i < 16; i++)
	{
		snum.Format(TEXT("%d"), i);
		m_list_di.InsertItem(i, snum,0);
	}
	
	m_list_di.SetImageList(&m_IconList, LVSIL_NORMAL);
	//m_list_di.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT |
	//	LVS_EDITLABELS | LVS_EX_SUBITEMIMAGES);             //一定要设置LVS_EX_SUBITEMIMAGES
	m_list_di.SetItem()
}
#endif // 0



void CTestGUIDlg::Icon_Init()
{
	HICON ON = AfxGetApp()->LoadIcon(IDI_ICON_ON);
	HICON OFF = AfxGetApp()->LoadIcon(IDI_ICON_OFF);
	m_IconList.Create(16, 16, ILC_COLOR32, 1, 1);
	m_IconList.Add(ON);
	m_IconList.Add(OFF);
}