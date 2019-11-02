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
	//���Ͻǵ�λ��
	m_LeftTopPosition=vLeftTopPosition;
	//��ʼ��������
	m_Day=day;
	m_Month=month;
	m_Year=year;
	//��ʼ��С����
	m_SpaceHigh = 25;
	m_SpaceWidth = 50;
	//������ʼ�������
	m_High =m_SpaceHigh*8;
	m_Width =m_SpaceWidth*7;

	//��ʼ�����߻��ʺͻ�Բ����
	m_LinePen.CreatePen(PS_SOLID,2,RGB(150,150,150));
	m_CirclePen.CreatePen(PS_SOLID,2,RGB(255,0,0));
	m_WeekPen.CreatePen(PS_SOLID,2,RGB(255,255,0));
}

void CCalendar::DrawLine(CDC *pDC,POINT startPosition,POINT stopPosition)
{
	//ѡ�л���
	pDC->SelectObject(m_LinePen);
	//��ʼ��
	pDC->MoveTo(startPosition);
	//�����յ�
	pDC->LineTo(stopPosition);
	
	/*
	pDC->MoveTo(300,300);
	//�����յ�
	pDC->LineTo(500,500);*/
}

void CCalendar::DrawRect(CDC *pDC,POINT startPosition,POINT stopPosition)
{
	//ѡ�л���
	pDC->SelectObject(m_CirclePen);
	//������
	pDC->Rectangle(startPosition.x,startPosition.y,stopPosition.x,stopPosition.y);
	/*CBrush RectBrush;
	RectBrush.CreateSolidBrush(RGB(255,255,0));
	pDC->SelectObject(RectBrush);
	pDC->Rectangle(startPosition.x,startPosition.y,stopPosition.x,stopPosition.y);
	DeleteObject(RectBrush);*/
}


void CCalendar::DrawSelf(CDC *pDC)
{
	
	//�����
	int space=5;
	POINT p1=m_LeftTopPosition;
	p1.x-=space;
	p1.y-=space;
	POINT p2=p1;
	//����
	p2.x+=(m_Width+space*2);
	DrawLine(pDC,p1,p2);
	//����
	p2=p1;
	p2.y+=(m_High+space*2);
	DrawLine(pDC,p1,p2);
	//����
	p1=p2;
	p2.x+=(m_Width+space*2);
	DrawLine(pDC,p1,p2);
	//����
	p1=p2;
	p2.y-=(m_High+space*2);
	DrawLine(pDC,p1,p2);
	pDC->SelectObject(m_LinePen);
	//�����ı�����
	CString mDate;
	mDate.Format(_T("%.4d��%.2d��%.2d��"),m_Year, m_Month,m_Day);
	//pDC->TextOutW(m_LeftTopPosition.x/2-20,m_LeftTopPosition.y,mDate);
	pDC->TextOutW(m_LeftTopPosition.x+m_Width/2-80,m_LeftTopPosition.y,mDate);

	//��������
	pDC->SelectObject(m_WeekPen);
	for (int i = 0; i < 7; i++)
	{
		pDC->TextOutW(m_LeftTopPosition.x+m_SpaceWidth*i,m_LeftTopPosition.y+m_SpaceHigh,GetWeek(i));
		
	}

	//��������
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

	int weeks=0;//���µڼ���
	int week=0;//���ڼ�
	CTime Time = CTime::GetCurrentTime();//��ȡϵͳ��ǰʱ��
	CString strWeek;
	strWeek = Time.Format("%w");//��ȡ���������ڼ�
	int flagWeek=strWeek[0]-'0';//�����ڼ����ַ�תΪ����
	for (int i = 1; i <= Monthday; i++)
	{
		week=(i%7-Time.GetDay()%7+flagWeek)%7;//�����i�������ڼ�
		CString str;
		str.Format(_T("%d"),i);//��ʽ���ַ���
		//����ǵ�����Ȼ��ƾ���
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
		//��������
		pDC->TextOutW(m_LeftTopPosition.x+m_SpaceWidth*week,m_LeftTopPosition.y+m_SpaceHigh*(2+weeks),str);
		//������������ͽ�����һ���ˣ�0123456��
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
			week="����";
			break;
		case 1:
			week="��һ";
			break;
		case 2:
			week="�ܶ�";
			break;
		case 3:
			week="����";
			break;
		case 4:
			week="����";
			break;
		case 5:
			week="����";
			break;
		case 6:
			week="����";
			break;
		default:
			break;
		}
		return week;
}