#include<stdio.h>
#include"gobang.h"

extern int a[16][16];

int doublethree(int x, int y, int ex, int ey, int exx, int eyy)
{
	if (x == 3 && y == 3 && ex == 2 && ey == 2 && exx + eyy != 0) return 1;
	return 0;
}

int doublefour(int x, int y, int ex, int ey)
{
	if (x == 4 && y == 4 && ex != 0 && ey != 0) return 1;
	return 0;
}

int AddScore(int num, int emptynum)
{
	int score = 0;
	if (emptynum == 1)
	{
		switch (num)
		{
		case 2:score += 5; break;
		case 3:score += 30; break;
		case 4:score += 60; break;
		}
	}
	else
		if (emptynum == 2)
		{
			switch (num)
			{
			case 2:score += 10; break;
			case 3:score += 40; break;
			case 4:score += 200; break;
			}
		}
	return score;
}

int AI_score(int x, int y, int t)
{
	int score = 0, xx, yy, numx, numy, numz1, numz2, emptynumx, emptynumy, emptynumz1, emptynumz2;
	int emptynumxx = 0, emptynumyy = 0, emptynumzz1 = 0, emptynumzz2 = 0;
	numx = 1; emptynumx = 0; numy = 1; emptynumy = 0; numz1 = 1; emptynumz1 = 0; numz2 = 1; emptynumz2 = 0; xx = x; yy = y;
	while (true)
	{
		if (xx <= 1) break;
		if (a[xx - 1][yy] == t)
		{
			numx++;
			xx--;
		}
		else
			if (a[xx - 1][yy] == 0)
			{
				if (xx > 2)
				{
					if (a[xx - 2][yy] == 0)
					{
						emptynumxx++;
					}
				}
				emptynumx++;
				break;
			}
			else
			{
				break;
			}
	}
	xx = x; yy = y;
	while (true)
	{
		if (xx >= 15) break;
		if (a[xx + 1][yy] == t)
		{
			numx++;
			xx++;
		}
		else
			if (a[xx + 1][yy] == 0)
			{
				if (xx < 14)
				{
					if (a[xx + 2][yy] == 0)
					{
						emptynumxx++;
					}
				}
				emptynumx++;
				break;
			}
			else
			{
				break;
			}
	}
	xx = x; yy = y;
	while (true)
	{
		if (yy <= 1) break;
		if (a[xx][yy - 1] == t)
		{
			numy++;
			yy--;
		}
		else
			if (a[xx][yy - 1] == 0)
			{
				if (yy > 2)
				{
					if (a[xx][yy - 2] == 0)
					{
						emptynumyy++;
					}
				}
				emptynumy++;
				break;
			}
			else
			{
				break;
			}
	}
	xx = x; yy = y;
	while (true)
	{
		if (yy >= 15) break;
		if (a[xx][yy + 1] == t)
		{
			numy++;
			yy++;
		}
		else
			if (a[xx][yy + 1] == 0)
			{
				if (yy < 14)
				{
					if (a[xx][yy + 2] == 0)
					{
						emptynumyy++;
					}
				}
				emptynumy++;
				break;
			}
			else
			{
				break;
			}
	}
	xx = x; yy = y;
	while (true)
	{
		if (xx <= 1 || yy <= 1) break;
		if (a[xx - 1][yy - 1] == t)
		{
			numz1++;
			xx--;
			yy--;
		}
		else
			if (a[xx - 1][yy - 1] == 0)
			{
				if (xx > 2 && yy > 2)
				{
					if (a[xx - 2][yy - 2] == 0)
					{
						emptynumzz1++;
					}
				}
				emptynumz1++;
				break;
			}
			else
			{
				break;
			}
	}
	xx = x; yy = y;
	while (true)
	{
		if (xx >= 15 || yy >= 15) break;
		if (a[xx + 1][yy + 1] == t)
		{
			numz1++;
			xx++;
			yy++;
		}
		else
			if (a[xx + 1][yy + 1] == 0)
			{
				if (xx < 14 && yy < 14)
				{
					if (a[xx + 2][yy + 2] == 0)
					{
						emptynumzz1++;
					}
				}
				emptynumz1++;
				break;
			}
			else
			{
				break;
			}
	}
	xx = x; yy = y;
	while (true)
	{
		if (xx <= 1 || yy >= 15) break;
		if (a[xx - 1][yy + 1] == t)
		{
			numz2++;
			xx--;
			yy++;
		}
		else
			if (a[xx - 1][yy + 1] == 0)
			{
				if (xx > 2 && yy < 14)
				{
					if (a[xx - 2][yy + 2] == 0)
					{
						emptynumzz2++;
					}
				}
				emptynumz2++;
				break;
			}
			else
			{
				break;
			}
	}
	xx = x; yy = y;
	while (true)
	{
		if (xx >= 15 || yy <= 1) break;
		if (a[xx + 1][yy - 1] == t)
		{
			numz2++;
			xx++;
			yy--;
		}
		else
		{
			if (a[xx + 1][yy - 1] == 0)
			{
				if (xx < 14 && yy > 2)
				{
					if (a[xx + 2][yy - 2] == 0)
					{
						emptynumzz2++;
					}
				}
				emptynumz2++;
				break;
			}
			else
			{
				break;
			}
		}
	}
	if (numx == 5 || numy == 5 || numz1 == 5 || numz2 == 5) return 40000;

	if (numx > 5 || numy > 5 || numz1 > 5 || numz2 > 5) return 40000;

	if (doublethree(numx, numy, emptynumx, emptynumy, emptynumxx, emptynumyy) == 1) score += 50;
	if (doublethree(numx, numz1, emptynumx, emptynumz1, emptynumxx, emptynumzz1) == 1) score += 50;
	if (doublethree(numx, numz2, emptynumx, emptynumz2, emptynumxx, emptynumzz2) == 1) score += 50;
	if (doublethree(numy, numz1, emptynumy, emptynumz1, emptynumyy, emptynumzz1) == 1) score += 50;
	if (doublethree(numy, numz2, emptynumy, emptynumz2, emptynumyy, emptynumzz2) == 1) score += 50;
	if (doublethree(numz1, numz2, emptynumz1, emptynumz2, emptynumzz1, emptynumzz2) == 1) score += 50;

	if (doublefour(numx, numy, emptynumx, emptynumy) == 1) score += 50;
	if (doublefour(numx, numz1, emptynumx, emptynumz1) == 1) score += 50;
	if (doublefour(numx, numz2, emptynumx, emptynumz2) == 1) score += 50;
	if (doublefour(numy, numz1, emptynumy, emptynumz1) == 1) score += 50;
	if (doublefour(numy, numz2, emptynumy, emptynumz2) == 1) score += 50;
	if (doublefour(numz1, numz2, emptynumz1, emptynumz2) == 1) score += 50;

	score += AddScore(numx, emptynumx);
	score += AddScore(numy, emptynumy);
	score += AddScore(numz1, emptynumz1);
	score += AddScore(numz2, emptynumz2);

	return score;
}