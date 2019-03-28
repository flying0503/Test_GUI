#pragma once


// dialong_operation 对话框

class dialong_operation : public CDialogEx
{
	DECLARE_DYNAMIC(dialong_operation)

public:
	dialong_operation(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~dialong_operation();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_OPERATION };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	bool ok_flag = false;
	CString Point;
	CString Code;
};
