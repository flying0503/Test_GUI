// dialong_operation.cpp: 实现文件
//

#include "stdafx.h"
#include "Test_GUI.h"
#include "dialong_operation.h"
#include "afxdialogex.h"


// dialong_operation 对话框

IMPLEMENT_DYNAMIC(dialong_operation, CDialogEx)

dialong_operation::dialong_operation(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_OPERATION, pParent)
	, Point(_T(""))
	, Code(_T(""))
{

}

dialong_operation::~dialong_operation()
{
}

void dialong_operation::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Point);
	DDX_Text(pDX, IDC_EDIT2, Code);
}


BEGIN_MESSAGE_MAP(dialong_operation, CDialogEx)
	ON_BN_CLICKED(IDOK, &dialong_operation::OnBnClickedOk)
END_MESSAGE_MAP()


// dialong_operation 消息处理程序


void dialong_operation::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	ok_flag = true;
	UpdateData(TRUE);
	CDialogEx::OnOK();
}
