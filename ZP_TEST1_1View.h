
// ZP_TEST1_1View.h : CZP_TEST1_1View 类的接口
//

#pragma once
#include "Clock.h"
#include "Calendar.h"

class CZP_TEST1_1View : public CView
{
protected: // 仅从序列化创建
	CZP_TEST1_1View();
	DECLARE_DYNCREATE(CZP_TEST1_1View)

// 特性
public:
	CZP_TEST1_1Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CZP_TEST1_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClksetStart();
	afx_msg void OnClksetStop();

public:
	CClock* GetClock();
	//绘制时钟
	void DrawClock(CDC *pDc);
	//绘制日历
	void DrawCalendar(CDC *pDC);
	/*//初始化数据
	void Init();*/
	//更新时间
	void UpdateTime();
	//更新日期
	void UpdateCalendar();
	//获取坐标点
	POINT GetPoint(int len,int i);
	//更新为系统时间
	void UpdateToSystemTime();
	//绘制时钟下面的文本时间和日期
	void PrintTxtTimeAndDate(CDC *pDC);
private:
	//时钟
	CClock *m_Clock;
	//日历
	CCalendar *m_Calendar;
	//当前系统时间
	CTime m_CurrentTime;
	//当前的小时
	int m_Hour;
	//当前的秒
	int m_Second;
	//当前的分
	int m_Minute;
	//天
	int m_Day;
	//月
	int m_Month;
	//年
	int m_Year;
	//表盘中心位置
	POINT m_ClockCenter;
	//表盘半径
	int m_ClockRadio;


	/*//表盘左上，右下两个点
	POINT m_ClockPosition[2];*/
	//日历左上，右下两个点
	//POINT m_Calendar[2];
	
	
	
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnClksetSyn();
	afx_msg void OnClksetChaNormal();
	afx_msg void OnClksetChaTtime();
	afx_msg void OnClksetSet();
};

#ifndef _DEBUG  // ZP_TEST1_1View.cpp 中的调试版本
inline CZP_TEST1_1Doc* CZP_TEST1_1View::GetDocument() const
   { return reinterpret_cast<CZP_TEST1_1Doc*>(m_pDocument); }
#endif

