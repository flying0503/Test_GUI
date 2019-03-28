// dialog_move.cpp: 实现文件
//

#include "stdafx.h"
#include "Test_GUI.h"
#include "dialog_move.h"
#include "afxdialogex.h"


// dialog_move 对话框

IMPLEMENT_DYNAMIC(dialog_move, CDialogEx)

dialog_move::dialog_move(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_MOVE, pParent)
	, Starting_Point(_T(""))
	, Ending_Point(_T(""))
	, Direction(_T(""))
	, Velocity(_T(""))
{

}

dialog_move::~dialog_move()
{
}

void dialog_move::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Starting_Point);
	DDX_Text(pDX, IDC_EDIT2, Ending_Point);
	DDX_Text(pDX, IDC_EDIT3, Direction);
	DDX_Text(pDX, IDC_EDIT4, Velocity);
}


BEGIN_MESSAGE_MAP(dialog_move, CDialogEx)
	ON_BN_CLICKED(IDOK, &dialog_move::OnBnClickedOk)
END_MESSAGE_MAP()


// dialog_move 消息处理程序


void dialog_move::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	ok_flag = true;
	UpdateData(TRUE);
	CDialogEx::OnOK();
}
