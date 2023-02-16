#include<graphics.h>
#include<stdio.h>
#include"gobang.h"

extern int step;
extern int a[16][16];
extern int st[300][2];
extern bool AI_FIRST;

void WithdrawAnyStepUI()
{
	TCHAR stepch[10];
	const int r = 1;
	int fillcolor,textcolor;
	initgraph(500, 600, SHOWCONSOLE);
	setbkcolor(RGB(117, 250, 141));
	cleardevice();

	fillcolor = getfillcolor();
	textcolor = gettextcolor();

	setfillcolor(WHITE);
	settextcolor(BLACK);
	setbkcolor(WHITE);
	setlinecolor(BLACK);

	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 60;
	_tcscpy_s(f.lfFaceName, _T("楷体"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	setbkmode(TRANSPARENT);
	outtextxy(75, 20, L"选择退回步数");

	gettextstyle(&f);
	f.lfHeight = 30;
	_tcscpy_s(f.lfFaceName, _T("楷体"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	setbkmode(TRANSPARENT);
	settextstyle(&f);

	fillrectangle(380, 550, 470, 580);
	outtextxy(395, 550, L"确定");

	gettextstyle(&f);
	f.lfHeight = 16;
	_tcscpy_s(f.lfFaceName, _T("宋体"));
	settextstyle(&f);


	for (int i = 1; i <= 15; i++)
	{
		for (int j = 1; j <= 15; j++)
		{
			fillrectangle(30 + (j - 1) * 30 + r, 90 + (i - 1) * 30 + r, 30 + j * 30 - r, 90 + i * 30 - r);
			if ((i - 1) * 15 + j > step)
			{
				settextcolor(RED);
			}
			_stprintf_s(stepch, _T("%d"), (i - 1) * 15 + j);
			outtextxy(3 + j * 30, 70 + i * 30, stepch);
		}
	}

	setfillcolor(fillcolor);
	settextcolor(textcolor);
}

int WithdrawStepBottom()
{
	int step1 = 1, i, j, x = 0, y = 0;
	while (true)
	{
		ExMessage msg = { 0 };
		if (peekmessage(&msg, EM_MOUSE) && msg.message == WM_LBUTTONDOWN)
		{
			if (msg.x >= 30 && msg.x <= 480 && msg.y >= 90 && msg.y <= 540)
			{
				i = msg.y / 30 - 2; 
				j = msg.x / 30;
				if ((i - 1) * 15 + j > step) continue;
				step1 = (i - 1) * 15 + j;
				//printf("%d %d", i, j);
				TCHAR stepch[10];
				settextcolor(BLUE);
				_stprintf_s(stepch, _T("%d"), step1);
				outtextxy(3 + j * 30, 70 + i * 30, stepch);
				if (x == 0)
				{
					x = i;
					y = j;
					continue;
				}
				settextcolor(BLACK);
				_stprintf_s(stepch, _T("%d"), (x - 1) * 15 + y);
				outtextxy(3 + y * 30, 70 + x * 30, stepch);
				x = i; 
				y = j;
			}
			if (msg.x >= 380 && msg.x <= 470 && msg.y >= 550 && msg.y <= 580)
			{
				//printf("%d", step1);
				return step1;
			}
		}
	}
}

void Draw(int backstep)
{
	UI();
	StartGameUI(1);
	ClearBoard();
	settextcolor(BLACK);
	setfillcolor(WHITE);
	if (!AI_FIRST)
	{
		step = (backstep + 1) / 2 * 2;
		for (int i = 1; i <= step; i++)
		{
			PrintChess(i, st[i][0], st[i][1]);
			if (i % 2 == 1)
			{
				a[st[i][0]][st[i][1]] = 1;
			}
			else
			{
				a[st[i][0]][st[i][1]] = 2;
			}
		}
	}
	else
	{
		step = backstep / 2 * 2 + 1;
		for (int i = 1; i <= step; i++)
		{
			PrintChess(i, st[i][0], st[i][1]);
			if (i % 2 == 1)
			{
				a[st[i][0]][st[i][1]] = 2;
			}
			else
			{
				a[st[i][0]][st[i][1]] = 1;
			}
		}
	}
}

void WithdrawAnyStep()
{
	int fillcolor, textcolor;
	fillcolor = getfillcolor();
	textcolor = gettextcolor();

	WithdrawAnyStepUI();
	int backstep = WithdrawStepBottom();
	Draw(backstep);

	setfillcolor(fillcolor);
	settextcolor(textcolor);
}