#include<graphics.h>
#include<stdio.h>
#include"gobang.h"

void EndGameWHITE(int type)
{
	setfillcolor(RGB(117, 250, 141));
	solidrectangle(135, 535, 355, 585);
	settextcolor(WHITE);
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 36;
	setfillcolor(WHITE);
	settextstyle(&f);
	outtextxy(25, 545, L"白方胜利!");
	settextcolor(BLACK);
	fillrectangle(250, 540, 350, 580);
	gettextstyle(&f);
	f.lfHeight = 32;
	_tcscpy_s(f.lfFaceName, _T("楷体"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	setbkmode(TRANSPARENT);
	outtextxy(265, 545, L"重试");
	ClearBoard();
	while (true)
	{
		ExMessage msg = { 0 };
		if (peekmessage(&msg, EM_MOUSE) && msg.message == WM_LBUTTONDOWN)
		{
			if (msg.x >= 250 && msg.x <= 350 && msg.y >= 540 && msg.y <= 580)
			{
				if (type == 1)
				{
					UI();
					ClickBottom();
				}
				else
					if (type == 2)
					{
						UI();
						ClickBottom2();
					}
			}
			if (msg.x >= 360 && msg.x <= 460 && msg.y >= 540 && msg.y <= 580)
			{
				ExitGame();
			}
		}
	}
}