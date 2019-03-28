#pragma once


// dialog_output 对话框

class dialog_output : public CDialogEx
{
	DECLARE_DYNAMIC(dialog_output)

public:
	dialog_output(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~dialog_output();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_OUTPUT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	bool ok_flag = false;

	CString Output;
};
