#include<graphics.h>
#include<stdio.h>
#include"gobang.h"

extern int a[16][16];
extern int st[300][2];
extern int step;

void AI_First(int type)
{
	const int distance = 10;
	const int r = 12;
	TCHAR stepch[10];
	int x = 8, y = 8;

	a[x][y] = type;
	step++;
	st[step][0] = x;
	st[step][1] = y;
	setfillcolor(BLACK);
	settextcolor(WHITE);
	fillcircle(x * 30, y * 30 + 60, r);
	_stprintf_s(stepch, _T("%d"), step);

	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 32;
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	setbkmode(TRANSPARENT);
	outtextxy(st[step][0] * 30 - 8, st[step][1] * 30 + 60 - 16, stepch);
}