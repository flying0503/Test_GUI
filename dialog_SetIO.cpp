// dialog_SetIO.cpp: 实现文件
//

#include "stdafx.h"
#include "Test_GUI.h"
#include "dialog_SetIO.h"
#include "afxdialogex.h"


// dialog_SetIO 对话框

IMPLEMENT_DYNAMIC(dialog_SetIO, CDialogEx)

dialog_SetIO::dialog_SetIO(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SetIO, pParent)
	, SetIO(_T(""))
{

}

dialog_SetIO::~dialog_SetIO()
{
}

void dialog_SetIO::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, SetIO);
}


BEGIN_MESSAGE_MAP(dialog_SetIO, CDialogEx)
	ON_BN_CLICKED(IDOK, &dialog_SetIO::OnBnClickedOk)
END_MESSAGE_MAP()


// dialog_SetIO 消息处理程序


void dialog_SetIO::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	ok_flag = true;
	UpdateData(TRUE);
	CDialogEx::OnOK();
}
