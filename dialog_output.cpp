// dialog_output.cpp: 实现文件
//

#include "stdafx.h"
#include "Test_GUI.h"
#include "dialog_output.h"
#include "afxdialogex.h"


// dialog_output 对话框

IMPLEMENT_DYNAMIC(dialog_output, CDialogEx)

dialog_output::dialog_output(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_OUTPUT, pParent)
	, Output(_T(""))
{

}

dialog_output::~dialog_output()
{
}

void dialog_output::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Output);
}


BEGIN_MESSAGE_MAP(dialog_output, CDialogEx)
	ON_BN_CLICKED(IDOK, &dialog_output::OnBnClickedOk)
//	ON_EN_CHANGE(IDC_EDIT1, &dialog_output::OnEnChangeEdit1)
END_MESSAGE_MAP()


// dialog_output 消息处理程序


void dialog_output::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	ok_flag = true;
	UpdateData(TRUE);
	CDialogEx::OnOK();
}

