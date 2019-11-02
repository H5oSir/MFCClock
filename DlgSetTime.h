#pragma once


// CDlgSetTime 对话框

class CDlgSetTime : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgSetTime)

public:
	CDlgSetTime(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgSetTime();

// 对话框数据
	enum { IDD = IDD_DLG_SETTIME };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int setHour;
	afx_msg void OnEnChangeEditHour();
	int setMinute;
	afx_msg void OnEnChangeEditMinute();
	int setSecond;
};
