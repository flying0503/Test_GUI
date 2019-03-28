
// Test_GUIDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "Test_GUI.h"
#include "Test_GUIDlg.h"
#include "afxdialogex.h"
#include "dialog_target.h"
#include "dialog_move.h"
#include "dialong_operation.h"
#include "dialog_SetIO.h"
#include "dialog_output.h"

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
	DDX_Control(pDX, IDC_LIST_STATE, m_list_state);
	DDX_Control(pDX, IDC_MESSAGE_TYPE, m_message_type);
}

BEGIN_MESSAGE_MAP(CTestGUIDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD, &CTestGUIDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_DELETE, &CTestGUIDlg::OnBnClickedDelete)
	ON_BN_CLICKED(IDC_UP, &CTestGUIDlg::OnBnClickedUp)
	ON_BN_CLICKED(IDC_DOWN, &CTestGUIDlg::OnBnClickedDown)
	ON_BN_CLICKED(IDC_SEND, &CTestGUIDlg::OnBnClickedSend)
//	ON_NOTIFY(HDN_ITEMCLICK, 0, &CTestGUIDlg::OnHdnItemclickListBit)
ON_NOTIFY(NM_CLICK, IDC_LIST_MESSAGE, &CTestGUIDlg::OnNMClickListMessage)
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
	//Icon_Init();
	List_Message_Init();
	List_Do_Init();
	List_Di_Init();
	List_State_Init();
	Message_Type_Init();
}

//List_Message 初始化
void CTestGUIDlg::List_Message_Init()
{
	m_list_message.SetExtendedStyle
	(m_list_message.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_SUBITEMIMAGES);
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

	CString snum;
	for (size_t i = 0; i < 16; i++)
	{
		snum.Format(TEXT("%d"), i);
		m_list_do.InsertItem(i, snum, 1);
	}
}

//List_DI 初始化
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
		m_list_di.InsertItem(i, snum,1);
	}
}

//图标初始化
void CTestGUIDlg::Icon_Init()
{
	HICON ON = AfxGetApp()->LoadIcon(IDI_ICON_ON);
	HICON OFF = AfxGetApp()->LoadIcon(IDI_ICON_OFF);
	m_IconList.Create(16, 16, ILC_COLOR32, 1, 1);
	m_IconList.Add(ON);
	m_IconList.Add(OFF);
	m_list_di.SetImageList(&m_IconList, LVSIL_NORMAL);
	m_list_di.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT |
		LVS_EDITLABELS | LVS_EX_SUBITEMIMAGES);             //一定要设置LVS_EX_SUBITEMIMAGES
}

//状态列表初始化
void CTestGUIDlg::List_State_Init()
{
	CString strc[] = { TEXT("Item"),TEXT("State") };
	for (size_t i = 0; i < sizeof(strc) / sizeof(strc[0]); i++)
	{
		m_list_state.InsertColumn(i, strc[i], LVCFMT_LEFT, 200);
	}

	CString stri[] = { TEXT("Power"),TEXT("Message Num"),TEXT("Car Num"),TEXT("Position"),
					TEXT("Confirm Message"),TEXT("Distance"),TEXT("Error Code") };
	for (size_t j = 0; j < sizeof(stri)/sizeof(stri[0]); j++)
	{
		m_list_state.InsertItem(j, stri[j]);
	}
}

//消息类型下拉框初始化
void CTestGUIDlg::Message_Type_Init()
{
	m_message_type.AddString(TEXT("Target"));
	m_message_type.AddString(TEXT("Move"));
	m_message_type.AddString(TEXT("Operation"));
	m_message_type.AddString(TEXT("Set IO"));
	m_message_type.AddString(TEXT("Output"));

	//设置默认选项
	m_message_type.SetCurSel(0);
}

//添加Target消息
void CTestGUIDlg::Add_Message_Target()
{
	dialog_target dlg_target;
	CString str,srow; 
	int row = m_list_message.GetItemCount();
	dlg_target.DoModal();
	if (dlg_target.ok_flag)
	{
		str = dlg_target.s_target;
		srow.Format(TEXT("%d"), row);
		m_list_message.InsertItem(row, srow);
		m_list_message.SetItemText(row, 1, TEXT("Target"));
		m_list_message.SetItemText(row, 2, str);
	}
}

void CTestGUIDlg::Add_Message_Move()
{
	dialog_move dlg_move;
	CString starting_point;
	CString ending_point;
	CString direction;
	CString velocity;
	CString srow;
	int row = m_list_message.GetItemCount();
	dlg_move.DoModal();
	if (dlg_move.ok_flag)
	{
		starting_point = dlg_move.Starting_Point;
		ending_point = dlg_move.Ending_Point;
		direction = dlg_move.Direction;
		velocity = dlg_move.Velocity;
		srow.Format(TEXT("%d"), row);
		m_list_message.InsertItem(row, srow);
		m_list_message.SetItemText(row, 1, TEXT("Move"));
		m_list_message.SetItemText(row, 2, starting_point);
		m_list_message.SetItemText(row, 3, ending_point);
		m_list_message.SetItemText(row, 4, direction);
		m_list_message.SetItemText(row, 5, velocity);
	}
}

void CTestGUIDlg::Add_Message_Operation()
{
	dialong_operation dlg_operation;
	CString point, code, srow;
	int row = m_list_message.GetItemCount();
	dlg_operation.DoModal();
	if (dlg_operation.ok_flag)
	{
		point = dlg_operation.Point;
		code = dlg_operation.Code;
		srow.Format(TEXT("%d"), row);
		m_list_message.InsertItem(row, srow);
		m_list_message.SetItemText(row, 1, TEXT("Operation"));
		m_list_message.SetItemText(row, 2, point);
		m_list_message.SetItemText(row, 3, code);
	}
}

void CTestGUIDlg::Add_Message_SetIO()
{
	dialog_SetIO dlg_setio;
	CString str, srow;
	int row = m_list_message.GetItemCount();
	dlg_setio.DoModal();
	if (dlg_setio.ok_flag)
	{
		str = dlg_setio.SetIO;
		srow.Format(TEXT("%d"), row);
		m_list_message.InsertItem(row, srow);
		m_list_message.SetItemText(row, 1, TEXT("SetIO"));
		m_list_message.SetItemText(row, 2, str);
	}
}

void CTestGUIDlg::Add_Message_Output()
{
	dialog_output dlg_output;
	CString str, srow;
	int row = m_list_message.GetItemCount();
	dlg_output.DoModal();
	if (dlg_output.ok_flag)
	{
		str = dlg_output.Output;
		srow.Format(TEXT("%d"), row);
		m_list_message.InsertItem(row, srow);
		m_list_message.SetItemText(row, 1, TEXT("Output"));
		m_list_message.SetItemText(row, 2, str);
	}
}

//添加消息
void CTestGUIDlg::OnBnClickedAdd()
{
	switch (m_message_type.GetCurSel())
	{
	case 0 :
		Add_Message_Target();
		break;

	case 1:
		Add_Message_Move();
		break;

	case 2:
		Add_Message_Operation();
		break;

	case 3:
		Add_Message_SetIO();
		break;

	case 4:
		Add_Message_Output();
		break;

	default:
		break;
	}
	
}

void CTestGUIDlg::OnBnClickedDelete()
{
	//int a = m_list_message.GetSelectionMark();
	int row = m_list_message.GetItemCount();
	CString srow;
	
	if(row>0)
	m_list_message.DeleteItem(Mask);

	row = m_list_message.GetItemCount();
	
	for (size_t i = 0; i < row; i++)
	{
		srow.Format(TEXT("%d"), i);
		m_list_message.SetItemText(i, 0, srow);
	}
	Mask = row;
}


void CTestGUIDlg::OnBnClickedUp()
{
	//int a = m_list_message.GetSelectionMark();//选中的行
	if (Mask > 0)
	{
		//保存选中的行
		CString m1, m2, m3, m4, m5, m6;
		m1 = m_list_message.GetItemText(Mask, 0);
		m2 = m_list_message.GetItemText(Mask, 1);
		m3 = m_list_message.GetItemText(Mask, 2);
		m4 = m_list_message.GetItemText(Mask, 3);
		m5 = m_list_message.GetItemText(Mask, 4);
		m6 = m_list_message.GetItemText(Mask, 5);
		m_list_message.DeleteItem(Mask);//删除选中的行
		//插入移动的行
		m_list_message.InsertItem(Mask - 1, TEXT("0"));
		m_list_message.SetItemText(Mask - 1, 0, m1);
		m_list_message.SetItemText(Mask - 1, 1, m2);
		m_list_message.SetItemText(Mask - 1, 2, m3);
		m_list_message.SetItemText(Mask - 1, 3, m4);
		m_list_message.SetItemText(Mask - 1, 4, m5);
		m_list_message.SetItemText(Mask - 1, 5, m6);

		CString srow;
		int row = m_list_message.GetItemCount();
		for (size_t i = 0; i < row; i++)
		{
			srow.Format(TEXT("%d"), i);
			m_list_message.SetItemText(i, 0, srow);
		}
		Mask--;
	}
}

void CTestGUIDlg::OnBnClickedDown()
{
	int row = m_list_message.GetItemCount();
	if (Mask+1 < row)
	{
		//保存选中的行
		CString m1, m2, m3, m4, m5, m6;
		m1 = m_list_message.GetItemText(Mask, 0);
		m2 = m_list_message.GetItemText(Mask, 1);
		m3 = m_list_message.GetItemText(Mask, 2);
		m4 = m_list_message.GetItemText(Mask, 3);
		m5 = m_list_message.GetItemText(Mask, 4);
		m6 = m_list_message.GetItemText(Mask, 5);
		m_list_message.DeleteItem(Mask);//删除选中的行
		//插入移动的行
		m_list_message.InsertItem(Mask + 1, TEXT("0"));
		m_list_message.SetItemText(Mask + 1, 0, m1);
		m_list_message.SetItemText(Mask + 1, 1, m2);
		m_list_message.SetItemText(Mask + 1, 2, m3);
		m_list_message.SetItemText(Mask + 1, 3, m4);
		m_list_message.SetItemText(Mask + 1, 4, m5);
		m_list_message.SetItemText(Mask + 1, 5, m6);

		CString srow;
		int row = m_list_message.GetItemCount();
		for (size_t i = 0; i < row; i++)
		{
			srow.Format(TEXT("%d"), i);
			m_list_message.SetItemText(i, 0, srow);
		}
		Mask++;
	}
}

void CTestGUIDlg::OnBnClickedSend()
{

}

void CTestGUIDlg::OnNMClickListMessage(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	Mask = m_list_message.GetSelectionMark();
	*pResult = 0;
}
