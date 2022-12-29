#include<graphics.h>
#include<stdio.h>
#include"gobang.h"

void StartGameUI(int type)
{
	setfillcolor(RGB(117, 250, 141));
	bar(55, 535, 160, 580);
	bar(295, 535, 400, 580);
	setfillcolor(WHITE);
	fillrectangle(360, 540, 460, 580);
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 32;
	_tcscpy_s(f.lfFaceName, _T("楷体"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	setbkmode(TRANSPARENT);
	outtextxy(380, 545, L"退出");
	
	if (type != 3)
	{
		fillrectangle(250, 540, 350, 580);
		gettextstyle(&f);
		f.lfHeight = 32;
		_tcscpy_s(f.lfFaceName, _T("楷体"));
		f.lfQuality = ANTIALIASED_QUALITY;
		settextstyle(&f);
		setbkmode(TRANSPARENT);
		outtextxy(270, 545, L"悔棋");
	}

	if (type == 1)
	{
		fillrectangle(140, 540, 240, 580);
		gettextstyle(&f);
		f.lfHeight = 32;
		_tcscpy_s(f.lfFaceName, _T("楷体"));
		f.lfQuality = ANTIALIASED_QUALITY;
		settextstyle(&f);
		setbkmode(TRANSPARENT);
		outtextxy(143, 545, L"AI代下");
	}
}