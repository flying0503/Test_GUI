#pragma once


// dialog_move 对话框

class dialog_move : public CDialogEx
{
	DECLARE_DYNAMIC(dialog_move)

public:
	dialog_move(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~dialog_move();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_MOVE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	bool ok_flag = false;
	afx_msg void OnBnClickedOk();
	CString Starting_Point;
	CString Ending_Point;
	CString Direction;
	CString Velocity;
};
