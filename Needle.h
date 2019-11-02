#pragma once
class CNeedle
{
public:
	CNeedle(void);
	CNeedle(char str[12]);
	~CNeedle(void);
	//创建画笔
	void CreatePen(int vStyle,int vWidth,COLORREF vColor);
	//画自己
	void DrawSelf(CDC *pDC/*,POINT startPoint,POINT stopPoint*/);
	//擦除自己
	void EraseSelf(CDC *pDC);
	//获取旧位置
	POINT GetOldPosition();
	//获取新位置
	POINT GetNowPosition();
	//设置旧位置
	void SetOldPosition(POINT vstart,POINT vStop);
	//设置新位置
	void SetNowPosition(POINT vstart,POINT vStop);
	//获得画笔
	CPen* GetPen();
	//更新位置
	void UpdatePosition(POINT vstart,POINT vStop);
private:
	//画笔
	CPen m_Pen;
	CPen m_ErasePen;
	//旧位置
	POINT m_OldPosition[2];
	//新位置
	POINT m_NowPosition[2];
};

