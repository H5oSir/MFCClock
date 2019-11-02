#include "stdafx.h"
#include "Calendar.h"



CCalendar::CCalendar(void)
{
}


CCalendar::~CCalendar(void)
{
}

CCalendar::CCalendar(POINT vLeftTopPosition,int day,int month,int year)
{
	//左上角的位置
	m_LeftTopPosition=vLeftTopPosition;
	//初始化日月年
	m_Day=day;
	m_Month=month;
	m_Year=year;
	//初始化小矩形
	m_SpaceHigh = 25;
	m_SpaceWidth = 50;
	//整个初始化大矩形
	m_High =m_SpaceHigh*8;
	m_Width =m_SpaceWidth*7;

	//初始化画线画笔和画圆画笔
	m_LinePen.CreatePen(PS_SOLID,2,RGB(150,150,150));
	m_CirclePen.CreatePen(PS_SOLID,2,RGB(255,0,0));
	m_WeekPen.CreatePen(PS_SOLID,2,RGB(255,255,0));
}

void CCalendar::DrawLine(CDC *pDC,POINT startPosition,POINT stopPosition)
{
	//选中画笔
	pDC->SelectObject(m_LinePen);
	//到始段
	pDC->MoveTo(startPosition);
	//画到终点
	pDC->LineTo(stopPosition);
	
	/*
	pDC->MoveTo(300,300);
	//画到终点
	pDC->LineTo(500,500);*/
}

void CCalendar::DrawRect(CDC *pDC,POINT startPosition,POINT stopPosition)
{
	//选中画笔
	pDC->SelectObject(m_CirclePen);
	//画矩形
	pDC->Rectangle(startPosition.x,startPosition.y,stopPosition.x,stopPosition.y);
	/*CBrush RectBrush;
	RectBrush.CreateSolidBrush(RGB(255,255,0));
	pDC->SelectObject(RectBrush);
	pDC->Rectangle(startPosition.x,startPosition.y,stopPosition.x,stopPosition.y);
	DeleteObject(RectBrush);*/
}


void CCalendar::DrawSelf(CDC *pDC)
{
	
	//画框框
	int space=5;
	POINT p1=m_LeftTopPosition;
	p1.x-=space;
	p1.y-=space;
	POINT p2=p1;
	//画上
	p2.x+=(m_Width+space*2);
	DrawLine(pDC,p1,p2);
	//画左
	p2=p1;
	p2.y+=(m_High+space*2);
	DrawLine(pDC,p1,p2);
	//画下
	p1=p2;
	p2.x+=(m_Width+space*2);
	DrawLine(pDC,p1,p2);
	//画右
	p1=p2;
	p2.y-=(m_High+space*2);
	DrawLine(pDC,p1,p2);
	pDC->SelectObject(m_LinePen);
	//绘制文本日期
	CString mDate;
	mDate.Format(_T("%.4d年%.2d月%.2d日"),m_Year, m_Month,m_Day);
	//pDC->TextOutW(m_LeftTopPosition.x/2-20,m_LeftTopPosition.y,mDate);
	pDC->TextOutW(m_LeftTopPosition.x+m_Width/2-80,m_LeftTopPosition.y,mDate);

	//绘制星期
	pDC->SelectObject(m_WeekPen);
	for (int i = 0; i < 7; i++)
	{
		pDC->TextOutW(m_LeftTopPosition.x+m_SpaceWidth*i,m_LeftTopPosition.y+m_SpaceHigh,GetWeek(i));
		
	}

	//绘制日期
	int Monthday;
	if (m_Month==1||m_Month==3||m_Month==5||m_Month==7||m_Month==8||m_Month==10||m_Month==12)
	{
		Monthday=31;
	}
	else if (m_Month==2)
	{
		if ((m_Year%4==0&&m_Year%100!=0)||(m_Year%400==0))
		{
			Monthday=29;
		}
		else
		{
			Monthday=28;
		}
	}
	else
	{
		Monthday=30;
	}

	int weeks=0;//本月第几周
	int week=0;//星期几
	CTime Time = CTime::GetCurrentTime();//获取系统当前时间
	CString strWeek;
	strWeek = Time.Format("%w");//获取今天是星期几
	int flagWeek=strWeek[0]-'0';//将星期几从字符转为整型
	for (int i = 1; i <= Monthday; i++)
	{
		week=(i%7-Time.GetDay()%7+flagWeek)%7;//计算第i天是星期几
		CString str;
		str.Format(_T("%d"),i);//格式化字符串
		//如果是当天就先绘制矩形
		if (i==Time.GetDay())
		{
			POINT p1;
			POINT p2;
			p1.x=m_LeftTopPosition.x+m_SpaceWidth*week-2;
			p1.y=m_LeftTopPosition.y+m_SpaceHigh*(2+weeks)-2;
			p2.x=p1.x+m_SpaceWidth/2+4;
			p2.y=p1.y+m_SpaceHigh+4;
			DrawRect(pDC,p1,p2);
		}
		//绘制日历
		pDC->TextOutW(m_LeftTopPosition.x+m_SpaceWidth*week,m_LeftTopPosition.y+m_SpaceHigh*(2+weeks),str);
		//如果是周六，就进入下一周了（0123456）
		if (week==6)
		{
			weeks+=1;
		}
	}

	
}


void CCalendar::Update(int day,int month,int year)
{
	m_Day=day;
	m_Month=month;
	m_Year=year;
}

CString CCalendar::GetWeek(int i)
{
	CString week=NULL;
		switch (i)
		{
		case 0:
			week="周日";
			break;
		case 1:
			week="周一";
			break;
		case 2:
			week="周二";
			break;
		case 3:
			week="周三";
			break;
		case 4:
			week="周四";
			break;
		case 5:
			week="周五";
			break;
		case 6:
			week="周六";
			break;
		default:
			break;
		}
		return week;
}