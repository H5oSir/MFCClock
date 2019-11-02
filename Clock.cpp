#include "stdafx.h"
#include "Clock.h"
#include "math.h"
#define PI 3.1415926

CClock::CClock(void)
{
	//表的半径
	m_Radio=100;
	//表的中心位置
	m_Center.x=150;
	m_Center.y=150;
	//时分秒针初始化
	m_HourNeedle=new CNeedle("Hour");
	m_MinuteNeedle=new CNeedle("Minute");
	m_SecondNeedle=new CNeedle("Second");

	//创建表盘、关键刻度、普通刻度画笔
	CreatePen(0,PS_SOLID,2,RGB(255,0,0));
	CreatePen(1,PS_SOLID,4,RGB(255,0,255));
	CreatePen(2,PS_SOLID,6,RGB(0,255,255));
	
}


CClock::~CClock(void)
{
	delete(m_HourNeedle);
	delete(m_MinuteNeedle);
	delete(m_SecondNeedle);

}

/*void CClock::DrawBottomTxt(CDC *pDC)
{
	//绘制日期
	CString mDate;
	mDate.Format(_T("%.4d年%.2d月%.2d日"),m_Year, m_Month, m_Day);
	pDC->TextOutW(m_Center.x-50,m_Center.y+m_Radio+20,mDate);
	CString mTimes;
	mTimes.Format(_T("%.2d:%.2d:%.2d"),m_Hour,m_Minute,m_Second);
	pDC->TextOutW(m_Center.x-26,m_Center.y+m_Radio+50,mTimes);
}*/

void CClock::UpdateDate(int Hour,int Minute,int Second)
{
	/*m_Hour=Hour;
	m_Minute=Minute;
	m_Second=Second;*/
	m_HourNeedle->UpdatePosition(m_Center,GetPoint(m_Radio-50,Hour%12*5));
	m_MinuteNeedle->UpdatePosition(m_Center,GetPoint(m_Radio-40,Minute));
	m_SecondNeedle->UpdatePosition(GetPoint(30,(Second+30)%60),GetPoint(m_Radio-20,Second));
}

void CClock::SetCenterAndRadion(POINT vCenter,int vRadio)
{
	m_Center=vCenter;
	m_Radio=vRadio;
}

void CClock::DrawCircle(CDC *pDC,POINT startPoint,POINT stopPoint)
{
	//画圆盘
	pDC->SelectObject(m_CirclePen);
	pDC->Ellipse(startPoint.x,startPoint.y,stopPoint.x,stopPoint.y);
}
void CClock::DrawPoint(CDC *pDC,POINT startPoint,POINT stopPoint)
{
	pDC->SelectObject(this->m_PointPen);
	//起始点
	pDC->MoveTo(startPoint.x,startPoint.y);
	//终点
	pDC->LineTo(stopPoint.x,stopPoint.y);
}

void CClock::DrawKeyPoint(CDC *pDC,POINT startPoint,POINT stopPoint)
{
	pDC->SelectObject(this->m_KeyPointPen);
	//起始点
	pDC->MoveTo(startPoint.x,startPoint.y);
	//终点
	pDC->LineTo(stopPoint.x,stopPoint.y);
}

void CClock::CreatePen(int vType,int vStyle,int vWidth,COLORREF vColor)
{
	//第一种画笔/画圆盘的笔
	if(vType==0)
	{
		m_CirclePen.CreatePen(vStyle,vWidth,vColor);
	}
	//第二种画笔/画关键点的笔
	else if(vType==1)
	{
		m_KeyPointPen.CreatePen(vStyle,vWidth,vColor);
	}
	//第三种画笔/画普通点的笔
	else if (vType==2)
	{
		m_PointPen.CreatePen(vStyle,vWidth,vColor);
	}
}
/*
CPen* CClock::GetCilclePen()
{
	return &m_CirclePen;
}

CPen* CClock::GetPointPen()
{
	return &m_PointPen;
}

CPen* CClock::GetKeyPointPen()
{
	return &m_KeyPointPen;
}

CNeedle* CClock::GetHourNeedle()
{
	return m_HourNeedle;
}

CNeedle* CClock::GetMinuteNeedle()
{
	return m_MinuteNeedle;
}

CNeedle* CClock::GetSecondNeedle()
{
	return m_SecondNeedle;
}*/
void CClock::DrawSelf(CDC *pDC)
{
	//画表盘
	POINT p1;
	p1.x=m_Center.x-m_Radio;
	p1.y=m_Center.y-m_Radio;
	POINT p2;
	p2.x=m_Center.x+m_Radio;
	p2.y=m_Center.y+m_Radio;
	DrawCircle(pDC,p1,p2);
	//画点
	for (int i = 0; i < 60; i++)
	{
		
		if (i%5==0)
		{
			POINT startP=this->GetPoint(m_Radio,i);
			POINT stopP=this->GetPoint(m_Radio-20,i);
			this->DrawKeyPoint(pDC,startP,stopP);
		}
		else
		{
			POINT startP=this->GetPoint(m_Radio,i);
			POINT stopP=this->GetPoint(m_Radio-5,i);
			this->DrawPoint(pDC,startP,stopP);
		}
	}
	//画时针
	m_HourNeedle->DrawSelf(pDC);
	//画分针
	m_MinuteNeedle->DrawSelf(pDC);
	//画秒针
	m_SecondNeedle->DrawSelf(pDC);
}

POINT CClock::GetPoint(int len,int i)
{
	//计算指针的端点
	POINT p;
	double angle = i*PI/30-PI/2;
	p.x = m_Center.x + (int)(len*cos(angle));
	p.y = m_Center.y + (int)(len*sin(angle));
	return p;
}