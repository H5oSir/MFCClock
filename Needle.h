#pragma once
class CNeedle
{
public:
	CNeedle(void);
	CNeedle(char str[12]);
	~CNeedle(void);
	//��������
	void CreatePen(int vStyle,int vWidth,COLORREF vColor);
	//���Լ�
	void DrawSelf(CDC *pDC/*,POINT startPoint,POINT stopPoint*/);
	//�����Լ�
	void EraseSelf(CDC *pDC);
	//��ȡ��λ��
	POINT GetOldPosition();
	//��ȡ��λ��
	POINT GetNowPosition();
	//���þ�λ��
	void SetOldPosition(POINT vstart,POINT vStop);
	//������λ��
	void SetNowPosition(POINT vstart,POINT vStop);
	//��û���
	CPen* GetPen();
	//����λ��
	void UpdatePosition(POINT vstart,POINT vStop);
private:
	//����
	CPen m_Pen;
	CPen m_ErasePen;
	//��λ��
	POINT m_OldPosition[2];
	//��λ��
	POINT m_NowPosition[2];
};

