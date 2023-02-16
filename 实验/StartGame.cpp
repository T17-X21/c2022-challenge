#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include"gobang.h"

int a[16][16] = { 0 };
int st[300][2] = { 0 };
int step = 0;
extern bool AI_FIRST;
extern int Forbidden;

int StartGame()
{
	const int distance = 10;
	step = 0;

	setfillcolor(WHITE);
	settextcolor(BLACK);
	if(AI_FIRST) AI_First(2);

	int x, y;
	while (true)
	{
		ExMessage msg = { 0 };
		if (peekmessage(&msg, EM_MOUSE)&&msg.message==WM_LBUTTONDOWN)
		{
			if ((msg.x >= 30 - distance) && (msg.x <= 450 + distance) && (msg.y >= 90 - distance) && (msg.y <= 510 + distance))
			{
				if ((msg.x % 30 <= distance || msg.x % 30 >= 30 - distance) && (msg.y % 30 <= distance || msg.y % 30 >= 30 - distance))
				{
					x = (msg.x + distance) / 30;
					y = (msg.y + distance - 60) / 30;
					if (a[x][y] == 0)
					{
						step++;
						a[x][y] = 1;
						st[step][0] = x;
						st[step][1] = y;
						PrintChess(step, x, y);
						if (JudgeGame(x,y) == 1)
						{
							if (!AI_FIRST) EndGame(1, 1); else EndGame(1, 2);
							break;
						}
						if (Forbidden != 0)
						{
							if (JudgeForbidden(1) == 1)
							{
								EndGameForbidden();
								ChangeColor();
								continue;
							}
						}
						if (step == 225)
						{
							EndGame(1, 3);
							break;
						}
						AI();
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
				if (msg.x >= 140 && msg.x <= 240 && msg.y >= 540 && msg.y <= 580 && step > 1)
				{
					AI_2();
					if (step >= 225)
					{
						EndGameDraw(1);
						break;
					}
					AI();
					if (step >= 225)
					{
						EndGameDraw(1);
						break;
					}
					continue;
				}
				if (msg.x >= 250 && msg.x <= 330 && msg.y >= 540 && msg.y <= 580)
				{
					if (step >= 2 || step == 1 && !AI_FIRST)
					{
						Withdraw();
						Withdraw();
					}
				}
				if (msg.x >= 330 && msg.x <= 350 && msg.y >= 540 && msg.y <= 580 && step >= 2)
				{
					WithdrawAnyStep();
				}
			}
		}
	}
	
	return 0;
}