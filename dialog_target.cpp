// dialog_target.cpp: 实现文件
//

#include "stdafx.h"
#include "Test_GUI.h"
#include "dialog_target.h"
#include "afxdialogex.h"


// dialog_target 对话框

IMPLEMENT_DYNAMIC(dialog_target, CDialogEx)

dialog_target::dialog_target(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_TARGET, pParent)
	, s_target(_T(""))
{

}

dialog_target::~dialog_target()
{
}

void dialog_target::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_TARGET, s_target);
}


BEGIN_MESSAGE_MAP(dialog_target, CDialogEx)
	ON_BN_CLICKED(IDOK, &dialog_target::OnBnClickedOk)
END_MESSAGE_MAP()


// dialog_target 消息处理程序


void dialog_target::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	ok_flag = true;
	UpdateData(TRUE);
	CDialogEx::OnOK();
}
