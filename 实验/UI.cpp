#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include"gobang.h"
void UI()
{
	const int step = 30;
	const int row = 15;
	const int head = 60;
	const int title_x = 120;
	const int title_y = 20;
	initgraph(500, 600, SHOWCONSOLE);
	setbkcolor(RGB(117,250,141));
	cleardevice();
	setcolor(BLACK);
	setfillcolor(BROWN);
	fillrectangle(20, 80, 460, 520);
	setlinestyle(PS_SOLID, 2);
	setcolor(RGB(0, 0, 0));
	
	int i;
	for (i = 1; i <= row; i++)
	{
		line(i * step, 1 * step + head, i * step, row * step + head);
		line(1 * step, i * step + head, row * step, i * step + head);
	}

	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 48;
	_tcscpy_s(f.lfFaceName, _T("楷体"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	setbkmode(TRANSPARENT);
	outtextxy(title_x, title_y, L"五子棋游戏");
	
	setfillcolor(WHITE);
	fillrectangle(60, 540, 160, 580);
	fillrectangle(300, 540, 400, 580);
	gettextstyle(&f);
	f.lfHeight = 32;
	_tcscpy_s(f.lfFaceName, _T("楷体"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	setbkmode(TRANSPARENT);
	outtextxy(75, 545, L"开始");
	outtextxy(315, 545, L"退出");
	
	//system("pause");
	//closegraph();
}