#include<graphics.h>
#include<stdio.h>
#include"gobang.h"

extern int Forbidden;

void EndGameForbidden()
{
	int textcolor, fillcolor;
	textcolor = gettextcolor();
	fillcolor = getfillcolor();
	settextcolor(BLACK);
	setfillcolor(RGB(117, 250, 141));
	solidrectangle(138, 538, 242, 582);
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 36;
	settextstyle(&f);
	switch (Forbidden)
	{
	case 1:outtextxy(25, 545, L"��������Υ��"); break;
	case 2:outtextxy(25, 545, L"���Ľ���Υ��"); break;
	case 3:outtextxy(25, 545, L"��������Υ��"); break;
	default:printf("Forbidden Error!\n"); break;
	}
	settextcolor(textcolor);
	setfillcolor(fillcolor);
	while (true)
	{
		ExMessage msg = { 0 };
		if (peekmessage(&msg, EM_MOUSE) && msg.message == WM_LBUTTONDOWN)
		{
			if (msg.x >= 250 && msg.x <= 350 && msg.y >= 540 && msg.y <= 580)
			{
				setfillcolor(RGB(117, 250, 141));
				solidrectangle(20, 540, 240, 580);
				Withdraw();

				settextcolor(BLACK);
				setfillcolor(WHITE);
				fillrectangle(140, 540, 240, 580);
				gettextstyle(&f);
				f.lfHeight = 32;
				_tcscpy_s(f.lfFaceName, _T("����"));
				f.lfQuality = ANTIALIASED_QUALITY;
				settextstyle(&f);
				setbkmode(TRANSPARENT);
				outtextxy(143, 545, L"AI����");
				settextcolor(textcolor);
				setfillcolor(fillcolor);
				break;
			}
		}
	}
}