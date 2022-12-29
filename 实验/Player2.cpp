#include<stdio.h>
#include<graphics.h>
#include"gobang.h"

extern int a[16][16];
extern int st[300][2];
extern int step;

void Player2()
{
	const int distance = 10;
	const int r = 12;
	TCHAR stepch[10];
	int x, y;
	while (true)
	{
		ExMessage msg = { 0 };
		if (peekmessage(&msg, EM_MOUSE) && msg.message == WM_LBUTTONDOWN)
		{
			if ((msg.x >= 30 - distance) && (msg.x <= 450 + distance) && (msg.y >= 90 - distance) && (msg.y <= 510 + distance))
			{
				if ((msg.x % 30 <= distance || msg.x % 30 >= 30 - distance) && (msg.y % 30 <= distance || msg.y % 30 >= 30 - distance))
				{
					x = (msg.x + distance) / 30;
					y = (msg.y + distance - 60) / 30;
					//printf("%d %d\n", x, y);
					if (a[x][y] == 0)
					{
						step++;
						a[x][y] = 2;
						st[step][0] = x;
						st[step][1] = y;
						setfillcolor(WHITE);
						settextcolor(BLACK);
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
						if (JudgeGame(x, y) == 1)
						{
							EndGameWHITE(2);
							return;
						}
						if (step == 255)
						{
							EndGameDraw(2);
							return;
						}
						break;
					}
				}
			}
			else
			{
				if (msg.x >= 360 && msg.x <= 460 && msg.y >= 540 && msg.y <= 580)
				{
					ExitGame();
					break;
				}
				if (msg.x >= 250 && msg.x <= 350 && msg.y >= 540 && msg.y <= 580)
				{
					if (step >= 1)
					{
						Withdraw();
						break;
					}
				}
			}
		}
	}
}