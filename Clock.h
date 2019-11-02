#pragma once
#include "Needle.h"
class CClock
{
public:
	CClock(void);
	~CClock(void);
	//������
	void DrawCircle(CDC *pDC,POINT startPoint,POINT stopPoint);
	//����ͨ��
	void DrawPoint(CDC *pDC,POINT satrtPoint,POINT stopPoint);
	//���ؼ��̶�
	void DrawKeyPoint(CDC *pDC,POINT satrtPoint,POINT stopPoint);
	//��������
	void CreatePen(int vType,int vStyle,int vWidth,COLORREF vColor);
	//���Լ�ȫ��
	void DrawSelf(CDC *pDC);
	//����Բ�ĺͰ뾶
	void SetCenterAndRadion(POINT vCenter,int vRadio);
	//�����Ӧ������
	POINT GetPoint(int len,int i);
	//����ʱ������
	void UpdateDate(int Hour,int Minute,int Secend);
private:
	//��İ뾶
	int m_Radio;
	//�������λ��
	POINT m_Center;
	//ʱ��ָ��
	CNeedle *m_HourNeedle;
	//����
	CNeedle *m_MinuteNeedle;
	//����
	CNeedle *m_SecondNeedle;
	/*int m_Hour;
	int m_Minute;
	int m_Second;*/
	/*int m_Year;
	int m_Month;
	int m_Day;*/
	//��Բ�̵ı�
	CPen m_CirclePen;
	//���ؼ���ı�
	CPen m_KeyPointPen;
	//����ͨ��ı�
	CPen m_PointPen;
};

