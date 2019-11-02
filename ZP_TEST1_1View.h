
// ZP_TEST1_1View.h : CZP_TEST1_1View ��Ľӿ�
//

#pragma once
#include "Clock.h"
#include "Calendar.h"

class CZP_TEST1_1View : public CView
{
protected: // �������л�����
	CZP_TEST1_1View();
	DECLARE_DYNCREATE(CZP_TEST1_1View)

// ����
public:
	CZP_TEST1_1Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CZP_TEST1_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClksetStart();
	afx_msg void OnClksetStop();

public:
	CClock* GetClock();
	//����ʱ��
	void DrawClock(CDC *pDc);
	//��������
	void DrawCalendar(CDC *pDC);
	/*//��ʼ������
	void Init();*/
	//����ʱ��
	void UpdateTime();
	//��������
	void UpdateCalendar();
	//��ȡ�����
	POINT GetPoint(int len,int i);
	//����Ϊϵͳʱ��
	void UpdateToSystemTime();
	//����ʱ��������ı�ʱ�������
	void PrintTxtTimeAndDate(CDC *pDC);
private:
	//ʱ��
	CClock *m_Clock;
	//����
	CCalendar *m_Calendar;
	//��ǰϵͳʱ��
	CTime m_CurrentTime;
	//��ǰ��Сʱ
	int m_Hour;
	//��ǰ����
	int m_Second;
	//��ǰ�ķ�
	int m_Minute;
	//��
	int m_Day;
	//��
	int m_Month;
	//��
	int m_Year;
	//��������λ��
	POINT m_ClockCenter;
	//���̰뾶
	int m_ClockRadio;


	/*//�������ϣ�����������
	POINT m_ClockPosition[2];*/
	//�������ϣ�����������
	//POINT m_Calendar[2];
	
	
	
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnClksetSyn();
	afx_msg void OnClksetChaNormal();
	afx_msg void OnClksetChaTtime();
	afx_msg void OnClksetSet();
};

#ifndef _DEBUG  // ZP_TEST1_1View.cpp �еĵ��԰汾
inline CZP_TEST1_1Doc* CZP_TEST1_1View::GetDocument() const
   { return reinterpret_cast<CZP_TEST1_1Doc*>(m_pDocument); }
#endif

