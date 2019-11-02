#include "stdafx.h"
#include "Needle.h"


CNeedle::CNeedle(void)
{

}
CNeedle::CNeedle(char str[12])
{
	if (str == "Hour")
	{
		CreatePen(PS_SOLID,6,RGB(0,255,0));//ÂÌÉ«
	}
	else if(str == "Minute")
	{
		CreatePen(PS_SOLID,4,RGB(255,0,0));//ºìÉ«
	}
	else if(str == "Second")
	{
		CreatePen(PS_SOLID,2,RGB(0,0,255));//À¶É«
	}
	for (int i = 0; i < 2; i++)
	{
		m_OldPosition[i].x=0;
		m_NowPosition[i].x=0;
		m_OldPosition[i].y=0;
		m_NowPosition[i].y=0;
	}
}


CNeedle::~CNeedle(void)
{
}

void CNeedle::CreatePen(int vStyle,int vWidth,COLORREF vColor)
{
	m_Pen.CreatePen(vStyle,vWidth,vColor);
	m_ErasePen.CreatePen(vStyle,vWidth,(255,255,255));
}
void CNeedle::DrawSelf(CDC *pDC/*,POINT startPoint,POINT stopPoint*/)
{
	pDC->SelectObject(this->m_Pen);
	pDC->MoveTo(this->m_NowPosition[0].x,this->m_NowPosition[0].y);
	pDC->LineTo(this->m_NowPosition[1].x,this->m_NowPosition[1].y);
}


CPen* CNeedle::GetPen()
{
	return &m_Pen;
}

void CNeedle::SetOldPosition(POINT vstart,POINT vStop)
{
	this->m_OldPosition[0]=vstart;
	this->m_OldPosition[1]=vStop;
}
void CNeedle::SetNowPosition(POINT vstart,POINT vStop)
{
	this->m_NowPosition[0]=vstart;
	this->m_NowPosition[1]=vStop;
}
void CNeedle::UpdatePosition(POINT vstart,POINT vStop)
{
	this->m_OldPosition[0]=m_NowPosition[0];
	this->m_OldPosition[1]=m_NowPosition[1];
	this->m_NowPosition[0]=vstart;
	this->m_NowPosition[1]=vStop;
}
