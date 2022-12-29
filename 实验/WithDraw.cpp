#include<graphics.h>
#include<stdio.h>
#include "gobang.h"

extern int a[16][16];
extern int st[300][2];
extern int step;

void Withdraw()
{
	const int r = 15;
	int x1, y1;
	x1 = st[step][0];
	y1 = st[step][1];
	step--;
	a[x1][y1] = 0;
	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 2);
	setfillcolor(BROWN);
	solidrectangle(max(21, x1 * 30 - r), max(81, y1 * 30 + 60 - r), min(459, x1 * 30 + r), min(519, y1 * 30 + 60 + r));
	line(max(30, x1 * 30 - (r + 1)), y1 * 30 + 60, min(450, x1 * 30 + (r + 1)), y1 * 30 + 60);
	line(x1 * 30, max(90, y1 * 30 + 60 - (r + 1)), x1 * 30, min(y1 * 30 + 60 + (r + 1), 510));
	setfillcolor(RGB(117, 250, 141));
	solidrectangle(20, 75, 460, 79);
	solidrectangle(20, 521, 460, 525);
	solidrectangle(15, 75, 19, 525);
	solidrectangle(461, 75, 465, 525);
	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 1);
	line(20, 80, 460, 80);
	line(20, 520, 460, 520);
	line(20, 80, 20, 520);
	line(460, 80, 460, 520);
	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 2);
}