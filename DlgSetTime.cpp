// DlgSetTime.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ZP_TEST1_1.h"
#include "DlgSetTime.h"
#include "afxdialogex.h"


// CDlgSetTime �Ի���

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


// CDlgSetTime ��Ϣ�������



void CDlgSetTime::OnEnChangeEditHour()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CDlgSetTime::OnEnChangeEditMinute()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
