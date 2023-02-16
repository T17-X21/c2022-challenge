#include<stdio.h>
#include<graphics.h>
#include<stdbool.h>
#include"gobang.h"
#define MAX_INT 100000
#define DEPTH 6
#define ATTACK 1.2
#define DEFENSE 1

extern int a[16][16];
extern int st[300][2];
extern int step;
int ans = -30000;
int x = 0, y = 0;
int xx[DEPTH + 1] = { 0 }, yy[DEPTH + 1] = { 0 };
int alpha[DEPTH + 1] = { -MAX_INT }, beta[DEPTH + 1] = { MAX_INT };
extern bool AI_FIRST;

int AIPlay2_F(int n, int score)
{
	int score1 = 0, score2 = 0;
	if (n > DEPTH)
	{
		if (score > ans)
		{
			x = xx[1];
			y = yy[1];
			ans = score;
		}
		return score;
	}
	if (n % 2 == 0)
	{
		for (int i = 1; i <= 15; i++)
		{
			for (int j = 1; j <= 15; j++)
			{
				if (a[i][j] == 0)
				{
					score1 = AI_score(i, j, 1);
					score2 = AI_score(i, j, 2);
					a[i][j] = 1;
					xx[n] = i;
					yy[n] = j;
					if (!AI_FIRST && JudgeForbidden(1) == 1)
					{
						a[i][j] = 0;
						continue;
					}
					beta[n] = min(beta[n], AIPlay2_F(n + 1, score - ATTACK * score1 - DEFENSE * score2));
					if (beta[n] <= alpha[n - 1])
					{
						a[i][j] = 0;
						return beta[n];
					}
					a[i][j] = 0;
				}
			}
		}
		return beta[n];
	}
	else
		if (n % 2 == 1)
		{
			for (int i = 1; i <= 15; i++)
			{
				for (int j = 1; j <= 15; j++)
				{
					if (a[i][j] == 0)
					{
						score1 = AI_score(i, j, 2);
						score2 = AI_score(i, j, 1);
						a[i][j] = 2;
						xx[n] = i;
						yy[n] = j;
						if (AI_FIRST && JudgeForbidden(2) == 1)
						{
							a[i][j] = 0;
							continue;
						}
						alpha[n] = max(alpha[n], AIPlay2_F(n + 1, score + ATTACK * score1 + DEFENSE * score2));
						if (alpha[n] >= beta[n - 1])
						{
							a[i][j] = 0;
							return alpha[n];
						}
						a[i][j] = 0;
					}
				}
			}
			return alpha[n];
		}
}

void AI()
{
	const int distance = 10;
	const int r = 12;
	TCHAR stepch[10];
	x = 0; y = 0; ans = -30000;
	FindFirstPosition();

	//AIPlay();
	//AIPlay2(1,0);
	AIPlay2_F(1, 0);

	a[x][y] = 2;
	step++;
	st[step][0] = x;
	st[step][1] = y;
	PrintChess(step, x, y, 255);
	
	if (step > 2)
	{
		if (!AI_FIRST) setfillcolor(BLACK); else setfillcolor(WHITE);
		PrintChess(step - 2, st[step - 2][0], st[step - 2][1], 0);
	}
	if (JudgeGame(x, y) == 1)
	{
		if (!AI_FIRST) EndGame(1, 2); else EndGame(1, 1);
		return;
	}
	if (step >= 225)
	{
		EndGame(1, 3);
		return;
	}

}