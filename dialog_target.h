#pragma once


// dialog_target 对话框

class dialog_target : public CDialogEx
{
	DECLARE_DYNAMIC(dialog_target)

public:
	dialog_target(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~dialog_target();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_TARGET };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString s_target;
	bool ok_flag = false;
	afx_msg void OnBnClickedOk();
private:
	
};
