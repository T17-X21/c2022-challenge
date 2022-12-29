#include<graphics.h>
#include<stdio.h>
#include"gobang.h"

void StartUI()
{
	initgraph(500, 600, SHOWCONSOLE);
	setbkcolor(RGB(117, 250, 141));
	cleardevice();
	//Sleep(1000);

	LOGFONT f;
	settextcolor(BLACK);
	gettextstyle(&f);
	f.lfHeight = 64;
	_tcscpy_s(f.lfFaceName, _T("����"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	setbkmode(TRANSPARENT);
	outtextxy(90,100, L"��������Ϸ");

	setlinecolor(BLACK);
	setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 3);
	setfillcolor(WHITE);
	fillrectangle(100, 250, 400, 300);
	fillrectangle(100, 350, 400, 400);
	fillrectangle(100, 450, 400, 500);
	
	gettextstyle(&f);
	f.lfHeight = 48;
	settextstyle(&f);
	outtextxy(155, 253, L"�˻���ս");
	outtextxy(155, 353, L"˫�˶�ս");
	outtextxy(155, 453, L"���Զ�ս");

	while (true)
	{
		ExMessage msg = { 0 };
		if (peekmessage(&msg, EM_MOUSE) && msg.message == WM_LBUTTONDOWN)
		{
			if (msg.x > 100 && msg.x < 400 && msg.y > 250 && msg.y < 300)
			{
				closegraph();
				UI_AI();
				break;
			}
			if (msg.x > 100 && msg.x < 400 && msg.y > 350 && msg.y < 400)
			{
				closegraph();
				UI();
				StartGameUI(2);
				StartGame2();
				break;
			}
			if (msg.x > 100 && msg.x < 400 && msg.y > 450 && msg.y < 500)
			{
				closegraph();
				UI();
				StartGameUI(3);
				StartGame3();
				break;
			}
		}
	}
}