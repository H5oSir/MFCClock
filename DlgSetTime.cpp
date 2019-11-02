// DlgSetTime.cpp : 实现文件
//

#include "stdafx.h"
#include "ZP_TEST1_1.h"
#include "DlgSetTime.h"
#include "afxdialogex.h"


// CDlgSetTime 对话框

IMPLEMENT_DYNAMIC(CDlgSetTime, CDialogEx)

CDlgSetTime::CDlgSetTime(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgSetTime::IDD, pParent)
	, setHour(0)
	, setMinute(0)
	, setSecond(0)
{

}

CDlgSetTime::~CDlgSetTime()
{
}

void CDlgSetTime::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_HOUR, setHour);
	DDV_MinMaxInt(pDX, setHour, 0, 23);
	DDX_Text(pDX, IDC_EDIT_MINUTE, setMinute);
	DDV_MinMaxInt(pDX, setMinute, 0, 59);
	DDX_Text(pDX, IDC_EDITSECOND, setSecond);
	DDV_MinMaxInt(pDX, setSecond, 0, 59);
}


BEGIN_MESSAGE_MAP(CDlgSetTime, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT_HOUR, &CDlgSetTime::OnEnChangeEditHour)
	ON_EN_CHANGE(IDC_EDIT_MINUTE, &CDlgSetTime::OnEnChangeEditMinute)
END_MESSAGE_MAP()


// CDlgSetTime 消息处理程序



void CDlgSetTime::OnEnChangeEditHour()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CDlgSetTime::OnEnChangeEditMinute()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
