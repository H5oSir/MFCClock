#pragma once


// CDlgSetTime �Ի���

class CDlgSetTime : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgSetTime)

public:
	CDlgSetTime(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgSetTime();

// �Ի�������
	enum { IDD = IDD_DLG_SETTIME };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int setHour;
	afx_msg void OnEnChangeEditHour();
	int setMinute;
	afx_msg void OnEnChangeEditMinute();
	int setSecond;
};
