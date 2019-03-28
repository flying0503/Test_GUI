
// Test_GUIDlg.h: 头文件
//

#pragma once


// CTestGUIDlg 对话框
class CTestGUIDlg : public CDialogEx
{
// 构造
public:
	void List_Message_Init();
	void List_Do_Init();
	void List_Di_Init();
	void Icon_Init();
	void List_State_Init();
	void Message_Type_Init();
	void Add_Message_Target();
	void Add_Message_Move();
	void Add_Message_Operation();
	void Add_Message_SetIO();
	void Add_Message_Output();
	CTestGUIDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEST_GUI_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	virtual void OnOK();
	void My_Init();
private:
	CListCtrl m_list_state;
	CListCtrl m_list_di;
	CListCtrl m_list_do;
	CImageList m_IconList;	
	CComboBox m_message_type;

	int Mask;		//选中的行
public:
	CListCtrl m_list_message;

public:
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedDelete();
	afx_msg void OnBnClickedUp();
	afx_msg void OnBnClickedDown();
	afx_msg void OnBnClickedSend();
	afx_msg void OnNMClickListMessage(NMHDR *pNMHDR, LRESULT *pResult);
};
