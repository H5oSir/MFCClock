#pragma once
class CCalendar
{
public:
	CCalendar(POINT vLeftTopPosition,int day,int month,int year);
	CCalendar(void);
	~CCalendar(void);
	//�������Ͻǵ�λ��
	void SetLeftTopPosition(POINT vPosition);
	//�����Լ�
	void DrawSelf(CDC *pDC);
	//������
	void DrawLine(CDC *pDC,POINT startPosition,POINT stopPosition);
	//���ƾ���
	void DrawRect(CDC *pDC,POINT startPosition,POINT stopPosition);
	//������������
	void Update(int day,int month,int year);
	//���������ֵ�����ת���ĵ����ڣ���6->����
	CString GetWeek(int i);
private:
	//���θ߶�
	int m_High;
	//���ο��
	int m_Width;
	//С�ո�ĸ߶�
	int m_SpaceHigh;
	//С�ո�Ŀ��
	int m_SpaceWidth;
	//��
	int m_Year;
	//��
	int m_Month;
	//��
	int m_Day;
	//�ߵĻ���
	CPen m_LinePen;
	//��Ǿ��εĻ���
	CPen m_CirclePen;
	//���ڵĻ���
	CPen m_WeekPen;
	//���Ͻǵ��λ��
	POINT m_LeftTopPosition;
};

