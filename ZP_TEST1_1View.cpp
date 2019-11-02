
// ZP_TEST1_1View.cpp : CZP_TEST1_1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
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

// CZP_TEST1_1View ����/����

CZP_TEST1_1View::CZP_TEST1_1View()
{
	//��ʼ��Ϊϵͳʱ��
	UpdateToSystemTime();
	//����ʱ�Ӷ���
	m_Clock=new CClock();
	//ʱ��ͬ�����µ�ϵͳʱ��
	m_Clock->UpdateDate(m_Hour,m_Minute,m_Second);
	
	//ʱ������λ��
	m_ClockCenter.x=150;
	m_ClockCenter.y=150;
	//ʱ�Ӱ뾶
	m_ClockRadio=100;
	//ʱ�����ϽǺ����½�λ��
	/*m_ClockPosition[0].x=m_ClockCenter.x-m_ClockRadio;
	m_ClockPosition[0].y=m_ClockCenter.x-m_ClockRadio;
	m_ClockPosition[1].x=m_ClockCenter.x+m_ClockRadio;
	m_ClockPosition[1].y=m_ClockCenter.x+m_ClockRadio;*/
	
	
	/*//ʱ�����λ��
	m_Clock->GetHourNeedle()->UpdatePosition(m_ClockCenter,GetPoint(m_ClockRadio-50,m_Hour%12*5));
	//�������λ��
	m_Clock->GetMinuteNeedle()->UpdatePosition(m_ClockCenter,GetPoint(m_ClockRadio-40,m_Minute));
	//�������λ��
	m_Clock->GetSecondNeedle()->UpdatePosition(GetPoint(30,(m_Second+30)%60),GetPoint(m_ClockRadio-20,m_Second));*/


	//����һ����
	POINT p;
	p.x=(m_ClockCenter.x+m_ClockRadio+20);
	p.y=(m_ClockCenter.x-m_ClockRadio);
	//ʵ����һ����������
	m_Calendar=new CCalendar(p,m_Day,m_Month,m_Year);
	// TODO: �ڴ˴���ӹ������

}

CZP_TEST1_1View::~CZP_TEST1_1View()
{
	//�ͷ��ڴ�
	delete(m_Clock);
	delete(m_Calendar);
}

BOOL CZP_TEST1_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CZP_TEST1_1View ����

void CZP_TEST1_1View::OnDraw(CDC* pDC)
{
	CZP_TEST1_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	//����ʱ��
	m_Clock->DrawSelf(pDC);
	//��������
	m_Calendar->DrawSelf(pDC);
	//����ʱ��������ı�ʱ��
	PrintTxtTimeAndDate(pDC);

}


// CZP_TEST1_1View ��ӡ

BOOL CZP_TEST1_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CZP_TEST1_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CZP_TEST1_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CZP_TEST1_1View ���

#ifdef _DEBUG
void CZP_TEST1_1View::AssertValid() const
{
	CView::AssertValid();
}

void CZP_TEST1_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CZP_TEST1_1Doc* CZP_TEST1_1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CZP_TEST1_1Doc)));
	return (CZP_TEST1_1Doc*)m_pDocument;
}
#endif //_DEBUG

// CZP_TEST1_1View ��Ϣ�������


void CZP_TEST1_1View::OnClksetStart()
{
	SetTimer(1,50,NULL);
	// TODO: �ڴ���������������
}


void CZP_TEST1_1View::OnClksetStop()
{
	KillTimer(1);
	// TODO: �ڴ���������������
}

void CZP_TEST1_1View::UpdateCalendar()
{
	//��������
	m_Day+=1;
	//�·���������ٽ��жϴ���
	if (m_Month==1||m_Month==3||m_Month==5||m_Month==7||m_Month==8||m_Month==10||m_Month==12)
	{
		if (m_Day>31)
		{
			m_Day-=31;
			//�·�����
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
	//�·��ٽ��жϴ���
	if (m_Month>12)
	{
		m_Month-=12;
		//�������
		m_Year+=1;
	}
	//ͬ�������������ڵ���ͼ����
	m_Calendar->Update(m_Day,m_Month,m_Year);
}

void CZP_TEST1_1View::UpdateTime()
{
	//���Ӽ�һ
	m_Second+=1;
	//�����ٽ��жϣ�������Ӵ��ڵ���60��
	if (m_Second>=60)
	{
		m_Second-=60;
		m_Minute+=1;
		//�������ٽ��ж�
		if (m_Minute>=60)
		{
			m_Minute-=60;
			m_Hour+=1;
			//ʱ���ٽ��ж�
			if (m_Hour>=24)
			{
				m_Hour-=24;
				//��������
				UpdateCalendar();
			}
			//m_Clock->GetHourNeedle()->UpdatePosition(m_ClockCenter,GetPoint(m_ClockRadio-50,m_Hour%12*5));
		}
		//m_Clock->GetMinuteNeedle()->UpdatePosition(m_ClockCenter,GetPoint(m_ClockRadio-40,m_Minute));
	}
	//m_Clock->GetSecondNeedle()->UpdatePosition(m_ClockCenter,GetPoint(m_ClockRadio-20,m_Second));
	//m_Clock->GetSecondNeedle()->UpdatePosition(GetPoint(30,(m_Second+30)%60),GetPoint(m_ClockRadio-20,m_Second));
	
	//ͬ�������ӱ�����
	m_Clock->UpdateDate(m_Hour,m_Minute,m_Second);
}
/*
POINT CZP_TEST1_1View::GetPoint(int len,int i)
{
	//����ָ��Ķ˵�
	POINT p;
	double angle = i*PI/30-PI/2;
	p.x = m_ClockCenter.x + (int)(len*cos(angle));
	p.y = m_ClockCenter.y + (int)(len*sin(angle));
	return p;
}
*/
void CZP_TEST1_1View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (nIDEvent==1)
	{
		//�ȡ����ݿ������ݡ�����
		UpdateTime();
		//��ˢ����ͼ
		Invalidate(false);
	}
	CView::OnTimer(nIDEvent);
}

void CZP_TEST1_1View::DrawClock(CDC *pDC)
{
	m_Clock->DrawSelf(pDC);
	/*
	//������
	m_Clock->DrawCircle(pDC,m_ClockPosition[0],m_ClockPosition[1]);
	//����
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
	//��ʱ��
	m_Clock->GetHourNeedle()->DrawSelf(pDC);
	//������
	m_Clock->GetMinuteNeedle()->DrawSelf(pDC);
	//������
	m_Clock->GetSecondNeedle()->DrawSelf(pDC);
	*/
}

void CZP_TEST1_1View::DrawCalendar(CDC *pDC)
{
	m_Calendar->DrawSelf(pDC);
}

void CZP_TEST1_1View::UpdateToSystemTime()
{
	//��ȡ��ǰϵͳʱ��
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
	//��������
	CString mDate;
	mDate.Format(_T("%.4d��%.2d��%.2d��"),m_Year, m_Month, m_Day);
	pDC->TextOutW(m_ClockCenter.x-50,m_ClockCenter.y+m_ClockRadio+20,mDate);
	CString mTimes;
	mTimes.Format(_T("%.2d:%.2d:%.2d"),m_Hour,m_Minute,m_Second);
	pDC->TextOutW(m_ClockCenter.x-26,m_ClockCenter.y+m_ClockRadio+50,mTimes);
}

void CZP_TEST1_1View::OnClksetSyn()
{
	// TODO: �ڴ���������������
	UpdateToSystemTime();
}


void CZP_TEST1_1View::OnClksetChaNormal()
{
	SetTimer(1,1000,NULL);
	// TODO: �ڴ���������������
}


void CZP_TEST1_1View::OnClksetChaTtime()
{
	SetTimer(1,50,NULL);
	// TODO: �ڴ���������������
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
	// TODO: �ڴ���������������
}
