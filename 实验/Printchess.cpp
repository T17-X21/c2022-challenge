#include<graphics.h>
#include<stdio.h>
#include"gobang.h"

void PrintChess(int step, int x, int y, int color)
{
	const int r = 12;
	TCHAR stepch[10];
	ChangeColor();
	if (color != 0)
	{
		settextcolor(RGB(color, 0, 0));
	}
	fillcircle(x * 30, y * 30 + 60, r);
	_stprintf_s(stepch, _T("%d"), step);
	if (step >= 100)
	{
		LOGFONT f;
		gettextstyle(&f);
		f.lfHeight = 16;
		f.lfQuality = ANTIALIASED_QUALITY;
		settextstyle(&f);
		setbkmode(TRANSPARENT);
		outtextxy(x * 30 - 12, y * 30 + 60 - 8, stepch);
	}
	else
		if (step >= 10)
		{
			LOGFONT f;
			gettextstyle(&f);
			f.lfHeight = 24;
			f.lfQuality = ANTIALIASED_QUALITY;
			settextstyle(&f);
			setbkmode(TRANSPARENT);
			outtextxy(x * 30 - 12, y * 30 + 60 - 12, stepch);
		}
		else
		{
			LOGFONT f;
			gettextstyle(&f);
			f.lfHeight = 32;
			f.lfQuality = ANTIALIASED_QUALITY;
			settextstyle(&f);
			setbkmode(TRANSPARENT);
			outtextxy(x * 30 - 8, y * 30 + 60 - 16, stepch);
		}
}