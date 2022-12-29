#include<graphics.h>
#include<stdio.h>
#include<Windows.h>
#include"gobang.h"
#define TIME 20

extern int step;
extern int Forbidden;

void StartGame3()
{
	step = 0;
	AI_First(1);
	while (true)
	{
		ExMessage msg = { 0 };
		if (peekmessage(&msg, EM_MOUSE) && msg.message == WM_LBUTTONDOWN)
		{
			if (msg.x >= 360 && msg.x <= 460 && msg.y >= 540 && msg.y <= 580)
			{
				ClearBoard();
				step = 0;
				StartUI();
				exit(0);
			}
		}
		AI();
		Sleep(TIME);
		AI_2();
		Sleep(TIME);
	}
}