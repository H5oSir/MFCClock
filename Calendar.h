#pragma once
class CCalendar
{
public:
	CCalendar(POINT vLeftTopPosition,int day,int month,int year);
	CCalendar(void);
	~CCalendar(void);
	//设置左上角的位置
	void SetLeftTopPosition(POINT vPosition);
	//绘制自己
	void DrawSelf(CDC *pDC);
	//绘制线
	void DrawLine(CDC *pDC,POINT startPosition,POINT stopPosition);
	//绘制矩形
	void DrawRect(CDC *pDC,POINT startPosition,POINT stopPosition);
	//更新日历数据
	void Update(int day,int month,int year);
	//阿拉伯数字的星期转中文的星期，如6->周六
	CString GetWeek(int i);
private:
	//矩形高度
	int m_High;
	//矩形宽度
	int m_Width;
	//小空格的高度
	int m_SpaceHigh;
	//小空格的宽度
	int m_SpaceWidth;
	//年
	int m_Year;
	//月
	int m_Month;
	//日
	int m_Day;
	//线的画笔
	CPen m_LinePen;
	//标记矩形的画笔
	CPen m_CirclePen;
	//星期的画笔
	CPen m_WeekPen;
	//左上角点的位置
	POINT m_LeftTopPosition;
};

