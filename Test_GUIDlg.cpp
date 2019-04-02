
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
#include <afxdb.h>

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
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON_JZTD);
}

void CTestGUIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_MESSAGE, m_list_message);
	DDX_Control(pDX, IDC_LIST_DI, m_list_di);
	DDX_Control(pDX, IDC_LIST_DO, m_list_do);
	DDX_Control(pDX, IDC_LIST_STATE, m_list_state);
	DDX_Control(pDX, IDC_MESSAGE_TYPE, m_message_type);
	DDX_Control(pDX, IDC_LIST_BIT, m_list_bit);
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
	ON_NOTIFY(NM_CLICK, IDC_LIST_MESSAGE, &CTestGUIDlg::OnNMClickListMessage)
	ON_WM_SIZE()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_SAVE, &CTestGUIDlg::OnBnClickedSave)
	ON_BN_CLICKED(IDC_LOAD, &CTestGUIDlg::OnBnClickedLoad)
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


//重写，防止按ENTER退出
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
	List_State_Init();
	List_Bit_Init();
	Message_Type_Init();
	Maximization_Init();
	SetTimer(1, 100, NULL);	//设置定时器 1
}

//最大化
void CTestGUIDlg::ReSize()
{
	float fsp[2];
	POINT Newp; //获取现在对话框的大小
	CRect recta;
	GetClientRect(&recta);     //取客户区大小  
	Newp.x = recta.right - recta.left;
	Newp.y = recta.bottom - recta.top;
	fsp[0] = (float)Newp.x / old.x;
	fsp[1] = (float)Newp.y / old.y;
	CRect Rect;
	int woc;
	CPoint OldTLPoint, TLPoint; //左上角
	CPoint OldBRPoint, BRPoint; //右下角
	HWND  hwndChild = ::GetWindow(m_hWnd, GW_CHILD);  //列出所有控件  
	while (hwndChild)
	{
		woc = ::GetDlgCtrlID(hwndChild);//取得ID
		GetDlgItem(woc)->GetWindowRect(Rect);
		ScreenToClient(Rect);
		OldTLPoint = Rect.TopLeft();
		TLPoint.x = long(OldTLPoint.x*fsp[0]);
		TLPoint.y = long(OldTLPoint.y*fsp[1]);
		OldBRPoint = Rect.BottomRight();
		BRPoint.x = long(OldBRPoint.x *fsp[0]);
		BRPoint.y = long(OldBRPoint.y *fsp[1]);
		Rect.SetRect(TLPoint, BRPoint);
		GetDlgItem(woc)->MoveWindow(Rect, TRUE);
		hwndChild = ::GetWindow(hwndChild, GW_HWNDNEXT);
	}
	old = Newp;
}

//最大化初始化
void CTestGUIDlg::Maximization_Init()
{
	CRect rect;
	GetClientRect(&rect);     //取客户区大小  
	old.x = rect.right - rect.left;
	old.y = rect.bottom - rect.top;
}

//更新控件
void CTestGUIDlg::Upudate_My_Ctrl()
{
	//等待聂工的接口函数
}

//图标初始化
void CTestGUIDlg::Icon_Init()
{
	HICON ON = AfxGetApp()->LoadIcon(IDI_ICON_ON);
	HICON OFF = AfxGetApp()->LoadIcon(IDI_ICON_OFF);
	m_IconList.Create(32, 32, ILC_COLOR32, 1, 1);
	m_IconList.Add(ON);
	m_IconList.Add(OFF);
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
	//关联列表和图片列表
	m_list_do.SetImageList(&m_IconList, LVSIL_NORMAL);
	//风格设置，一定要设置LVS_EX_SUBITEMIMAGES
	m_list_do.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT |
		LVS_EDITLABELS | LVS_EX_SUBITEMIMAGES);
	//关联图片列表
	m_list_do.SetImageList(&m_IconList, LVSIL_SMALL);

	CString snum;
	//设置图片item样式
	LVITEM lvItem = { 0 };
	lvItem.mask = LVIF_IMAGE | LVIF_TEXT | LVIF_STATE;	//文字、图片、状态
	lvItem.iItem = 0;		//行号(第一行)
	lvItem.iImage = 1;	//图片索引号(关图片)
	lvItem.iSubItem = 1;	//子列号

	CString str[] = { TEXT("Num"),TEXT("State") };
	for (size_t i = 0; i < sizeof(str) / sizeof(str[0]); i++)
	{
		m_list_do.InsertColumn(i, str[i], LVCFMT_LEFT, 70);
	}

	for (size_t i = 0; i < 16; i++)
	{
		snum.Format(TEXT("%d"), i);
		m_list_do.InsertItem(i, snum, -1);
		lvItem.iItem = i;					//行号(第一行)
		m_list_do.SetItem(&lvItem);			//设置item
	}
}

//List_DI 初始化
void CTestGUIDlg::List_Di_Init()
{
	//关联列表和图片列表
	m_list_di.SetImageList(&m_IconList, LVSIL_NORMAL);
	//风格设置，一定要设置LVS_EX_SUBITEMIMAGES
	m_list_di.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT |
		LVS_EDITLABELS | LVS_EX_SUBITEMIMAGES);     
	//关联图片列表
	m_list_di.SetImageList(&m_IconList, LVSIL_SMALL);

	CString snum;
	//设置图片item样式
	LVITEM lvItem = { 0 };
	lvItem.mask = LVIF_IMAGE | LVIF_TEXT | LVIF_STATE;	//文字、图片、状态
	lvItem.iItem = 0;		//行号(第一行)
	lvItem.iImage = 1;	//图片索引号(关图片)
	lvItem.iSubItem = 1;	//子列号

	CString str[] = { TEXT("Num"),TEXT("State") };
	for (size_t i = 0; i < sizeof(str) / sizeof(str[0]); i++)
	{
		m_list_di.InsertColumn(i, str[i], LVCFMT_LEFT, 70);
	}
	
	for (size_t i = 0; i < 16; i++)
	{
		snum.Format(TEXT("%d"), i);
		m_list_di.InsertItem(i, snum,-1);
		lvItem.iItem = i;					//行号(第一行)
		m_list_di.SetItem(&lvItem);			//设置item
	}
}

//位列表初始化
void CTestGUIDlg::List_Bit_Init()
{
	//关联列表和图片列表
	m_list_bit.SetImageList(&m_IconList, LVSIL_NORMAL);
	//风格设置，一定要设置LVS_EX_SUBITEMIMAGES
	m_list_bit.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT |
		LVS_EDITLABELS | LVS_EX_SUBITEMIMAGES);
	//关联图片列表
	m_list_bit.SetImageList(&m_IconList, LVSIL_SMALL);

	//设置图片item样式
	LVITEM lvItem = { 0 };
	lvItem.mask = LVIF_IMAGE | LVIF_TEXT | LVIF_STATE;	//文字、图片、状态
	lvItem.iItem = 0;		//行号(第一行)
	lvItem.iImage = 1;	//图片索引号(关图片)
	lvItem.iSubItem = 1;	//子列号

	CString str[] = { TEXT("Item"),TEXT("State") };
	for (size_t i = 0; i < sizeof(str) / sizeof(str[0]); i++)
	{
		m_list_bit.InsertColumn(i, str[i], LVCFMT_LEFT, 150);
	}
	
	CString sitem[] = { TEXT("Auto"),TEXT("Error"),TEXT("Low Power"),TEXT("Scram"),
						TEXT("Load"),TEXT("Arrive"),TEXT("Operation Complete"),
						TEXT("Moving"),TEXT("Pause") };
	for (size_t i = 0; i < sizeof(sitem) / sizeof(sitem[0]); i++)
	{
		m_list_bit.InsertItem(i, sitem[i], -1);
		lvItem.iItem = i;					//行号(第一行)
		m_list_bit.SetItem(&lvItem);			//设置item
	}
	m_list_bit.InsertItem(9, TEXT("Current Direction"),-1);
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

//添加移动消息
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

//添加操作消息
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

//添加SetIO消息
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
		m_list_message.SetItemText(row, 1, TEXT("Set IO"));
		m_list_message.SetItemText(row, 2, str);
	}
}

//添加Output消息
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

//删除函数
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

//上移函数
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

//下移函数
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

//发送按钮
void CTestGUIDlg::OnBnClickedSend()
{
	int row = m_list_message.GetItemCount();
	CString s_title;

	for (size_t i = 0; i < row; i++)
	{
		s_title = m_list_message.GetItemText(i, 1);

		if (s_title == TEXT("Target"))
		{
			//等待聂工的接口函数
			MessageBox(TEXT("Target"));
		}

		if (s_title == TEXT("Move"))
		{
			//等待聂工的接口函数
			MessageBox(TEXT("Move"));
		}

		if (s_title == TEXT("Operation"))
		{
			//等待聂工的接口函数
			MessageBox(TEXT("Operation"));
		}

		if (s_title == TEXT("Set IO"))
		{
			//等待聂工的接口函数
			MessageBox(TEXT("Set IO"));
		}

		if (s_title == TEXT("Output"))
		{
			//等待聂工的接口函数
			MessageBox(TEXT("Output"));
		}
	}
}

//点击Message列表时得到选中的行
void CTestGUIDlg::OnNMClickListMessage(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	Mask = m_list_message.GetSelectionMark();
	*pResult = 0;
}

//最大化函数
void CTestGUIDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	if (nType == SIZE_RESTORED || nType == SIZE_MAXIMIZED)
	{
		ReSize();
	}
}

//定时器函数
void CTestGUIDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (nIDEvent)
	{
	case 1:
		Upudate_My_Ctrl();
	default:
		break;
	}

	CDialogEx::OnTimer(nIDEvent);
}


void CTestGUIDlg::OnBnClickedSave()
{
	CFileDialog fileDlg(FALSE);
	fileDlg.m_ofn.lpstrTitle = TEXT("Save Dialog");
	fileDlg.m_ofn.lpstrFilter = TEXT("Excel 文件(*.xls)");
	fileDlg.m_ofn.lpstrDefExt = TEXT("txt/xls");
	if (IDOK == fileDlg.DoModal())
	{
		CStdioFile file(fileDlg.GetPathName(), CFile::modeCreate | CFile::modeWrite);
		CString strLine, strTemp;
		int m_ntimer, index;
		m_ntimer = m_list_message.GetItemCount();
		index = m_list_message.GetHeaderCtrl()->GetItemCount();
		for (int i = 0; i <= m_ntimer; i++)
		{
			strLine = _T("");
			for (int j = 0; j <= index; j++)
			{
				strTemp = m_list_message.GetItemText(i, j);
				strLine += strTemp + _T("\t");
			}
			strLine += _T("\n");
			file.WriteString(strLine);
		}
		file.Close();
	}
}

void CTestGUIDlg::OnBnClickedLoad()
{	
	CFileDialog fileDlg(TRUE);
	fileDlg.m_ofn.lpstrTitle = TEXT("Open Dialog");
	fileDlg.m_ofn.lpstrFilter = TEXT("Excel 文件(*.xls)");
	fileDlg.m_ofn.lpstrDefExt = TEXT("txt/xls");
	if (IDOK == fileDlg.DoModal())
	{
		CStdioFile file(fileDlg.GetPathName(), CFile::modeRead);
		CString strText = TEXT("");
		CString szLine = TEXT("");
		int i = 0;
		while (file.ReadString(szLine))
		{
			m_list_message.InsertItem(i, szLine);
		}
		file.Close();
	}
}
