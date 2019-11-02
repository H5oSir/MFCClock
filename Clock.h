#pragma once
#include "Needle.h"
class CClock
{
public:
	CClock(void);
	~CClock(void);
	//画表盘
	void DrawCircle(CDC *pDC,POINT startPoint,POINT stopPoint);
	//画普通点
	void DrawPoint(CDC *pDC,POINT satrtPoint,POINT stopPoint);
	//画关键刻度
	void DrawKeyPoint(CDC *pDC,POINT satrtPoint,POINT stopPoint);
	//创建画笔
	void CreatePen(int vType,int vStyle,int vWidth,COLORREF vColor);
	//画自己全部
	void DrawSelf(CDC *pDC);
	//设置圆心和半径
	void SetCenterAndRadion(POINT vCenter,int vRadio);
	//获得相应的坐标
	POINT GetPoint(int len,int i);
	//更新时间数据
	void UpdateDate(int Hour,int Minute,int Secend);
private:
	//表的半径
	int m_Radio;
	//表的中心位置
	POINT m_Center;
	//时针指针
	CNeedle *m_HourNeedle;
	//分针
	CNeedle *m_MinuteNeedle;
	//秒针
	CNeedle *m_SecondNeedle;
	/*int m_Hour;
	int m_Minute;
	int m_Second;*/
	/*int m_Year;
	int m_Month;
	int m_Day;*/
	//画圆盘的笔
	CPen m_CirclePen;
	//画关键点的笔
	CPen m_KeyPointPen;
	//画普通点的笔
	CPen m_PointPen;
};

