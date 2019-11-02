
// ZP_TEST1_1View.cpp : CZP_TEST1_1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "ZP_TEST1_1.h"
#endif

#include "ZP_TEST1_1Doc.h"
#include "ZP_TEST1_1View.h"

#include "math.h"
#include "DlgSetTime.h"

#define PI 3.1415926

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CZP_TEST1_1View

IMPLEMENT_DYNCREATE(CZP_TEST1_1View, CView)

BEGIN_MESSAGE_MAP(CZP_TEST1_1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_CLKSET_START, &CZP_TEST1_1View::OnClksetStart)
	ON_COMMAND(ID_CLKSET_STOP, &CZP_TEST1_1View::OnClksetStop)
	ON_WM_TIMER()
	ON_COMMAND(D_CLKSET_SYN, &CZP_TEST1_1View::OnClksetSyn)
	ON_COMMAND(ID_CLKSET_CHA_NORMAL, &CZP_TEST1_1View::OnClksetChaNormal)
	ON_COMMAND(ID_CLKSET_CHA_TTIME, &CZP_TEST1_1View::OnClksetChaTtime)
	ON_COMMAND(ID_CLKSET_SET, &CZP_TEST1_1View::OnClksetSet)
END_MESSAGE_MAP()

// CZP_TEST1_1View 构造/析构

CZP_TEST1_1View::CZP_TEST1_1View()
{
	//初始化为系统时间
	UpdateToSystemTime();
	//创建时钟对象
	m_Clock=new CClock();
	//时钟同步更新到系统时间
	m_Clock->UpdateDate(m_Hour,m_Minute,m_Second);
	
	//时钟中心位置
	m_ClockCenter.x=150;
	m_ClockCenter.y=150;
	//时钟半径
	m_ClockRadio=100;
	//时钟左上角和右下角位置
	/*m_ClockPosition[0].x=m_ClockCenter.x-m_ClockRadio;
	m_ClockPosition[0].y=m_ClockCenter.x-m_ClockRadio;
	m_ClockPosition[1].x=m_ClockCenter.x+m_ClockRadio;
	m_ClockPosition[1].y=m_ClockCenter.x+m_ClockRadio;*/
	
	
	/*//时针更新位置
	m_Clock->GetHourNeedle()->UpdatePosition(m_ClockCenter,GetPoint(m_ClockRadio-50,m_Hour%12*5));
	//分针更新位置
	m_Clock->GetMinuteNeedle()->UpdatePosition(m_ClockCenter,GetPoint(m_ClockRadio-40,m_Minute));
	//秒针更新位置
	m_Clock->GetSecondNeedle()->UpdatePosition(GetPoint(30,(m_Second+30)%60),GetPoint(m_ClockRadio-20,m_Second));*/


	//设置一个点
	POINT p;
	p.x=(m_ClockCenter.x+m_ClockRadio+20);
	p.y=(m_ClockCenter.x-m_ClockRadio);
	//实例化一个日历对象
	m_Calendar=new CCalendar(p,m_Day,m_Month,m_Year);
	// TODO: 在此处添加构造代码

}

CZP_TEST1_1View::~CZP_TEST1_1View()
{
	//释放内存
	delete(m_Clock);
	delete(m_Calendar);
}

BOOL CZP_TEST1_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CZP_TEST1_1View 绘制

void CZP_TEST1_1View::OnDraw(CDC* pDC)
{
	CZP_TEST1_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO: 在此处为本机数据添加绘制代码
	//绘制时钟
	m_Clock->DrawSelf(pDC);
	//绘制日历
	m_Calendar->DrawSelf(pDC);
	//绘制时钟下面的文本时间
	PrintTxtTimeAndDate(pDC);

}


// CZP_TEST1_1View 打印

BOOL CZP_TEST1_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CZP_TEST1_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CZP_TEST1_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CZP_TEST1_1View 诊断

#ifdef _DEBUG
void CZP_TEST1_1View::AssertValid() const
{
	CView::AssertValid();
}

void CZP_TEST1_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CZP_TEST1_1Doc* CZP_TEST1_1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CZP_TEST1_1Doc)));
	return (CZP_TEST1_1Doc*)m_pDocument;
}
#endif //_DEBUG

// CZP_TEST1_1View 消息处理程序


void CZP_TEST1_1View::OnClksetStart()
{
	SetTimer(1,50,NULL);
	// TODO: 在此添加命令处理程序代码
}


void CZP_TEST1_1View::OnClksetStop()
{
	KillTimer(1);
	// TODO: 在此添加命令处理程序代码
}

void CZP_TEST1_1View::UpdateCalendar()
{
	//天数增加
	m_Day+=1;
	//月份最大天数临界判断处理
	if (m_Month==1||m_Month==3||m_Month==5||m_Month==7||m_Month==8||m_Month==10||m_Month==12)
	{
		if (m_Day>31)
		{
			m_Day-=31;
			//月份增加
			m_Month+=1;
		}
	}
	else if (m_Month==2)
	{
		if ((m_Year%4==0&&m_Year%100!=0)||(m_Year%400==0))
		{
			if (m_Day>29)
			{
				m_Day-=29;
				m_Month+=1;
			}
		}
		else
		{
			if (m_Day>28)
			{
				m_Day-=28;
				m_Month+=1;
			}
		}
	}
	else
	{
		if (m_Day>30)
			{
				m_Day-=30;
				m_Month+=1;
			}
	}
	//月份临界判断处理
	if (m_Month>12)
	{
		m_Month-=12;
		//年份增加
		m_Year+=1;
	}
	//同步更新日历日期到视图日期
	m_Calendar->Update(m_Day,m_Month,m_Year);
}

void CZP_TEST1_1View::UpdateTime()
{
	//秒钟加一
	m_Second+=1;
	//秒钟临界判断，如果秒钟大于等于60秒
	if (m_Second>=60)
	{
		m_Second-=60;
		m_Minute+=1;
		//分钟钟临界判断
		if (m_Minute>=60)
		{
			m_Minute-=60;
			m_Hour+=1;
			//时钟临界判断
			if (m_Hour>=24)
			{
				m_Hour-=24;
				//更新日期
				UpdateCalendar();
			}
			//m_Clock->GetHourNeedle()->UpdatePosition(m_ClockCenter,GetPoint(m_ClockRadio-50,m_Hour%12*5));
		}
		//m_Clock->GetMinuteNeedle()->UpdatePosition(m_ClockCenter,GetPoint(m_ClockRadio-40,m_Minute));
	}
	//m_Clock->GetSecondNeedle()->UpdatePosition(m_ClockCenter,GetPoint(m_ClockRadio-20,m_Second));
	//m_Clock->GetSecondNeedle()->UpdatePosition(GetPoint(30,(m_Second+30)%60),GetPoint(m_ClockRadio-20,m_Second));
	
	//同步更新钟表数据
	m_Clock->UpdateDate(m_Hour,m_Minute,m_Second);
}
/*
POINT CZP_TEST1_1View::GetPoint(int len,int i)
{
	//计算指针的端点
	POINT p;
	double angle = i*PI/30-PI/2;
	p.x = m_ClockCenter.x + (int)(len*cos(angle));
	p.y = m_ClockCenter.y + (int)(len*sin(angle));
	return p;
}
*/
void CZP_TEST1_1View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nIDEvent==1)
	{
		//先“数据库中数据”更新
		UpdateTime();
		//再刷新视图
		Invalidate(false);
	}
	CView::OnTimer(nIDEvent);
}

void CZP_TEST1_1View::DrawClock(CDC *pDC)
{
	m_Clock->DrawSelf(pDC);
	/*
	//画表盘
	m_Clock->DrawCircle(pDC,m_ClockPosition[0],m_ClockPosition[1]);
	//画点
	for (int i = 0; i < 60; i++)
	{
		
		if (i%5==0)
		{
			POINT startP=GetPoint(m_ClockRadio,i);
			POINT stopP=GetPoint(m_ClockRadio-20,i);
			m_Clock->DrawKeyPoint(pDC,startP,stopP);
		}
		else
		{
			POINT startP=GetPoint(m_ClockRadio,i);
			POINT stopP=GetPoint(m_ClockRadio-5,i);
			m_Clock->DrawPoint(pDC,startP,stopP);
		}
	}
	//画时针
	m_Clock->GetHourNeedle()->DrawSelf(pDC);
	//画分针
	m_Clock->GetMinuteNeedle()->DrawSelf(pDC);
	//画秒针
	m_Clock->GetSecondNeedle()->DrawSelf(pDC);
	*/
}

void CZP_TEST1_1View::DrawCalendar(CDC *pDC)
{
	m_Calendar->DrawSelf(pDC);
}

void CZP_TEST1_1View::UpdateToSystemTime()
{
	//获取当前系统时间
	CTime Time = CTime::GetCurrentTime();
	m_Year = Time.GetYear();
	m_Month = Time.GetMonth();
	m_Day = Time.GetDay();
	m_Hour = Time.GetHour();
	m_Minute = Time.GetMinute();
	m_Second = Time.GetSecond();
}

void CZP_TEST1_1View::PrintTxtTimeAndDate(CDC *pDC)
{
	//绘制日期
	CString mDate;
	mDate.Format(_T("%.4d年%.2d月%.2d日"),m_Year, m_Month, m_Day);
	pDC->TextOutW(m_ClockCenter.x-50,m_ClockCenter.y+m_ClockRadio+20,mDate);
	CString mTimes;
	mTimes.Format(_T("%.2d:%.2d:%.2d"),m_Hour,m_Minute,m_Second);
	pDC->TextOutW(m_ClockCenter.x-26,m_ClockCenter.y+m_ClockRadio+50,mTimes);
}

void CZP_TEST1_1View::OnClksetSyn()
{
	// TODO: 在此添加命令处理程序代码
	UpdateToSystemTime();
}


void CZP_TEST1_1View::OnClksetChaNormal()
{
	SetTimer(1,1000,NULL);
	// TODO: 在此添加命令处理程序代码
}


void CZP_TEST1_1View::OnClksetChaTtime()
{
	SetTimer(1,50,NULL);
	// TODO: 在此添加命令处理程序代码
}


void CZP_TEST1_1View::OnClksetSet()
{
	CDlgSetTime SetDlg;
	if (SetDlg.DoModal() == IDOK)
	{
		m_Hour = SetDlg.setHour;
		m_Minute = SetDlg.setMinute;
		m_Second =SetDlg.setSecond;
		m_Clock->UpdateDate(m_Hour,m_Minute,m_Second);
	}
	// TODO: 在此添加命令处理程序代码
}
