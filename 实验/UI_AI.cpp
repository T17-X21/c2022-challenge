#include<graphics.h>
#include<stdio.h>
#include<stdbool.h>
#include"gobang.h"

bool AI_FIRST;
bool ShowForbidden=FALSE;
int Forbidden = 0;

void FillText()
{
	setfillcolor(WHITE);
	solidrectangle(42, 352, 248, 398);
	solidrectangle(252, 352, 458, 398);
	solidrectangle(42, 402, 248, 448);
	solidrectangle(252, 402, 458, 448);
}

void UI_AI()
{
	initgraph(500, 600, SHOWCONSOLE);
	setbkcolor(RGB(117, 250, 141));
	cleardevice();

	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 64;
	_tcscpy_s(f.lfFaceName, _T("楷体"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	outtextxy(125, 50, L"选择模式");

	setfillcolor(WHITE);
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 3);
	fillrectangle(40, 200, 240, 250);
	fillrectangle(260, 200, 460, 250);
	gettextstyle(&f);
	f.lfHeight = 40;
	settextstyle(&f);
	outtextxy(62, 205, L"玩家先手");
	outtextxy(282, 205, L"人机先手");
	fillrectangle(40, 500, 460, 550);
	outtextxy(170, 505, L"开始游戏");
	while (true)
	{
		ExMessage msg = { 0 };
		if (peekmessage(&msg, EM_MOUSE) && msg.message == WM_LBUTTONDOWN)
		{
			if (msg.x >= 40 && msg.x <= 240 && msg.y >= 200 && msg.y <= 250)
			{
				AI_FIRST = FALSE;
				fillrectangle(40, 200, 240, 250);
				fillrectangle(260, 200, 460, 250);
				settextcolor(BLUE);
				outtextxy(62, 205, L"玩家先手");
				settextcolor(BLACK);
				outtextxy(282, 205, L"人机先手");
				fillrectangle(40, 300, 460, 350);
				fillrectangle(40, 350, 250, 400);
				fillrectangle(250, 350, 460, 400);
				fillrectangle(40, 400, 250, 450);
				fillrectangle(250, 400, 460, 450);
				outtextxy(175, 305, L"选择禁手");
				outtextxy(90, 355, L"无禁手");
				outtextxy(280, 355, L"三三禁手");
				outtextxy(70, 405, L"四四禁手");
				outtextxy(280, 405, L"长连禁手");
				ShowForbidden = TRUE;
			}
			else
				if (msg.x >= 260 && msg.x <= 460 && msg.y >= 200 && msg.y <= 250)
				{
					AI_FIRST = TRUE;
					fillrectangle(40, 200, 240, 250);
					fillrectangle(260, 200, 460, 250);

					fillrectangle(40, 300, 460, 350);
					fillrectangle(40, 350, 250, 400);
					fillrectangle(250, 350, 460, 400);
					fillrectangle(40, 400, 250, 450);
					fillrectangle(250, 400, 460, 450);
					outtextxy(175, 305, L"选择禁手");
					outtextxy(90, 355, L"无禁手");
					outtextxy(280, 355, L"三三禁手");
					outtextxy(70, 405, L"四四禁手");
					outtextxy(280, 405, L"长连禁手");
					ShowForbidden = TRUE;

					settextcolor(BLUE);
					outtextxy(282, 205, L"人机先手");
					//setfillcolor(RGB(117, 250, 141));
					//solidrectangle(38, 298, 462, 452);
					//setfillcolor(WHITE);
					//ShowForbidden = FALSE;
					//Forbidden = 0;
					settextcolor(BLACK);
					outtextxy(62, 205, L"玩家先手");
				}
				else
					if (msg.x >= 40 && msg.x <= 460 && msg.y >= 500 && msg.y <= 550)
					{
						closegraph();
						UI();
						StartGameUI(1);
						StartGame();
					}
					else
						if (ShowForbidden)
						{
							if (msg.x >= 40 && msg.x <= 250 && msg.y >= 350 && msg.y <= 400)
							{
								FillText();
								settextcolor(BLUE);
								outtextxy(90, 355, L"无禁手");
								settextcolor(BLACK);
								outtextxy(280, 355, L"三三禁手");
								outtextxy(70, 405, L"四四禁手");
								outtextxy(280, 405, L"长连禁手");
								Forbidden = 0;
							}
							else
								if (msg.x >= 250 && msg.x <= 460 && msg.y >= 350 && msg.y <= 400)
								{
									FillText();
									settextcolor(BLUE);
									outtextxy(280, 355, L"三三禁手");
									settextcolor(BLACK);
									outtextxy(90, 355, L"无禁手");
									outtextxy(70, 405, L"四四禁手");
									outtextxy(280, 405, L"长连禁手");
									Forbidden = 1;
								}
								else
									if (msg.x >= 40 && msg.x <= 250 && msg.y >= 400 && msg.y <= 450)
									{
										FillText();
										settextcolor(BLUE);
										outtextxy(70, 405, L"四四禁手");
										settextcolor(BLACK);
										outtextxy(90, 355, L"无禁手");
										outtextxy(280, 355, L"三三禁手");
										outtextxy(280, 405, L"长连禁手");
										Forbidden = 2;
									}
									else
										if (msg.x >= 250 && msg.x <= 460 && msg.y >= 400 && msg.y <= 450)
										{
											FillText();
											settextcolor(BLUE);
											outtextxy(280, 405, L"长连禁手");
											settextcolor(BLACK);
											outtextxy(90, 355, L"无禁手");
											outtextxy(280, 355, L"三三禁手");
											outtextxy(70, 405, L"四四禁手");
											Forbidden = 3;
										}
						}
		}
	}
}