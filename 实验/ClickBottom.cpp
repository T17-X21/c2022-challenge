#include<stdio.h>
#include<graphics.h>
#include"gobang.h"


int ClickBottom()
{
	while (true)
	{
		ExMessage msg = { 0 };
		if (peekmessage(&msg, EM_MOUSE));
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 60 && msg.x <= 160 && msg.y >= 540 && msg.y <= 580)
				{
					StartGameUI(1);
					StartGame();
					return 0;
				}
				else 
				{
					if (msg.x >= 300 && msg.x <= 400 && msg.y >= 540 && msg.y <= 580)
					{
						ExitGame();
						return 0;
					}
				}
				break;
			default:
				break;
			}
		}
	}
	return 0;
}