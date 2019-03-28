#pragma once


// dialog_SetIO 对话框

class dialog_SetIO : public CDialogEx
{
	DECLARE_DYNAMIC(dialog_SetIO)

public:
	dialog_SetIO(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~dialog_SetIO();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SetIO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	bool ok_flag = false;
	CString SetIO;
};
