#include<graphics.h>
#include<stdio.h>
#include<stdbool.h>
#include"gobang.h"

extern int a[16][16];
extern int Forbidden;

int doublethree(int x, int y, int z1, int z2, int ex, int ey, int ez1, int ez2)
{
	int ans = 0;
	if (x == 3 && ex == 2) ans++;
	if (y == 3 && ey == 2) ans++;
	if (z1 == 3 && ez1 == 2) ans++;
	if (z2 == 3 && ez2 == 2) ans++;
	if (ans >= 2) return 1;
	return 0;
}

int doublefour(int x, int y, int z1, int z2, int ex, int ey, int ez1, int ez2, int* four)
{
	int ans = 0;
	if (x == 4 && ex > 0) ans++;
	if (y == 4 && ey > 0) ans++;
	if (z1 == 4 && ez1 > 0) ans++;
	if (z2 == 4 && ez2 > 0) ans++;
	//if (ans >= 2) return 1;
	*four += ans;
	if (*four >= 8 || ans >= 2) return 1;
	return 0;
}

int doublethree1(int x, int y, int t, int numx, int numy, int numz1, int numz2, int emptynumx, int emptynumy, int emptynumz1, int emptynumz2)
{
	int ans = 0, xx, yy, e1, e2, num1, num2;
	bool emptynum1, emptynum2;

	if (numx == 3 && emptynumx == 2) ans++;
	if (numy == 3 && emptynumy == 2) ans++;
	if (numz1 == 3 && emptynumz1 == 2) ans++;
	if (numz2 == 3 && emptynumz2 == 2) ans++;

	xx = x; yy = y; e1 = 1, num1 = 1, e2 = 1, num2 = 1; emptynum1 = true; emptynum2 = true;
	while (true)
	{
		if (xx == 1 || xx == 2 && a[xx - 1][yy] != t) break;
		if (a[xx - 1][yy] == t)
		{
			num1++;
			xx--;
			continue;
		}
		if (a[xx - 1][yy] == 0 && e1 == 1 && a[xx - 2][yy] == t)
		{
			e1--;
			xx--;
			continue;
		}
		if (a[xx - 1][yy] != t && a[xx - 1][yy] != 0) emptynum1 = false;
		break;
	}
	xx = x; yy = y;
	while (true)
	{
		if (xx == 15 || xx == 14 && a[xx + 1][yy] != t) break;
		if (a[xx + 1][yy] == t)
		{
			num1++;
			xx++;
			continue;
		}
		if (a[xx + 1][yy] == 0 && e1 == 1 && a[xx + 2][yy] == t)
		{
			e1--;
			xx++;
			continue;
		}
		if (a[xx + 1][yy] != t && a[xx + 1][yy] != 0) emptynum1 = false;
		break;
	}
	xx = x; yy = y;
	while (true)
	{
		if (xx == 15 || xx == 14 && a[xx + 1][yy] != t) break;
		if (a[xx + 1][yy] == t)
		{
			num2++;
			xx++;
			continue;
		}
		if (a[xx + 1][yy] == 0 && e2 == 1 && a[xx + 2][yy] == t)
		{
			e2--;
			xx++;
			continue;
		}
		if (a[xx + 1][yy] != t && a[xx + 1][yy] != 0) emptynum2 = false;
		break;
	}
	xx = x; yy = y;
	while (true)
	{
		if (xx == 1 || xx == 2 && a[xx - 1][yy] != t) break;
		if (a[xx - 1][yy] == t)
		{
			num2++;
			xx--;
			continue;
		}
		if (a[xx - 1][yy] == 0 && e2 == 1 && a[xx - 2][yy] == t)
		{
			e2--;
			xx--;
			continue;
		}
		if (a[xx - 1][yy] != t && a[xx - 1][yy] != 0) emptynum2 = false;
		break;
	}
	if (num1 == 3 && e1 == 0 && emptynum1 || num2 == 3 && e2 == 0 && emptynum2) ans++;

	xx = x; yy = y; num1 = 1; num2 = 1; e1 = 1; e2 = 1; emptynum1 = true; emptynum2 = true;
	while (true)
	{
		if (yy == 1 || yy == 2 && a[xx][yy - 1] != t) break;
		if (a[xx][yy - 1] == t)
		{
			num1++;
			yy--;
			continue;
		}
		if (a[xx][yy - 1] == 0 && e1 == 1 && a[xx][yy - 2] == t)
		{
			e1--;
			yy--;
			continue;
		}
		if (a[xx][yy - 1] != t && a[xx][yy - 1] != 0) emptynum1 = false;
		break;
	}
	xx = x; yy = y;
	while (true)
	{
		if (yy == 15 || yy == 14 && a[xx][yy + 1] != t) break;
		if (a[xx][yy + 1] == t)
		{
			num1++;
			yy++;
			continue;
		}
		if (a[xx][yy + 1] == 0 && e1 == 1 && a[xx][yy + 2] == t)
		{
			e1--;
			yy++;
			continue;
		}
		if (a[xx][yy + 1] != t && a[xx][yy + 1] != 0) emptynum1 = false;
		break;
	}
	xx = x; yy = y;
	while (true)
	{
		if (yy == 15 || yy == 14 && a[xx][yy + 1] != t) break;
		if (a[xx][yy + 1] == t)
		{
			num2++;
			yy++;
			continue;
		}
		if (a[xx][yy + 1] == 0 && e2 == 1 && a[xx][yy + 2] == t)
		{
			e2--;
			yy++;
			continue;
		}
		if (a[xx][yy + 1] != t && a[xx][yy + 1] != 0) emptynum2 = false;
		break;
	}
	xx = x; yy = y;
	while (true)
	{
		if (yy == 1 || yy == 2 && a[xx][yy - 1] != t) break;
		if (a[xx][yy - 1] == t)
		{
			num2++;
			yy--;
			continue;
		}
		if (a[xx][yy - 1] == 0 && e2 == 1 && a[xx][yy - 2] == t)
		{
			e2--;
			yy--;
			continue;
		}
		if (a[xx][yy - 1] != t && a[xx][yy - 1] != 0) emptynum2 = false;
		break;
	}
	if (num1 == 3 && e1 == 0 && emptynum1 || num2 == 3 && e2 == 0 && emptynum2) ans++;

	xx = x; yy = y; e1 = 1, num1 = 1, e2 = 1, num2 = 1; emptynum1 = true; emptynum2 = true;
	while (true)
	{
		if (xx == 15 || yy == 15 || xx == 14 && a[xx + 1][yy + 1] != t || yy == 14 && a[xx + 1][yy + 1] != t) break;
		if (a[xx + 1][yy + 1] == t)
		{
			num1++;
			xx++;
			yy++;
			continue;
		}
		if (a[xx + 1][yy + 1] == 0 && e1 == 1 && a[xx + 2][yy + 2] == t)
		{
			e1--;
			xx++;
			yy++;
			continue;
		}
		if (a[xx + 1][yy + 1] != t && a[xx + 1][yy + 1] != 0) emptynum1 = false;
		break;
	}
	xx = x; yy = y;
	while (true)
	{
		if (xx == 1 || yy == 1 || xx == 2 && a[xx - 1][yy - 1] != t || yy == 2 && a[xx - 1][yy - 1] != t) break;
		if (a[xx - 1][yy - 1] == t)
		{
			num1++;
			xx--;
			yy--;
			continue;
		}
		if (a[xx - 1][yy - 1] == 0 && e1 == 1 && a[xx - 2][yy - 2] == t)
		{
			e1--;
			xx--;
			yy--;
			continue;
		}
		if (a[xx - 1][yy - 1] != t && a[xx - 1][yy - 1] != 0) emptynum1 = false;
		break;
	}
	xx = x; yy = y;
	while (true)
	{
		if (xx == 1 || yy == 1 || xx == 2 && a[xx - 1][yy - 1] != t || yy == 2 && a[xx - 1][yy - 1] != t) break;
		if (a[xx - 1][yy - 1] == t)
		{
			num2++;
			xx--;
			yy--;
			continue;
		}
		if (a[xx - 1][yy - 1] == 0 && e2 == 1 && a[xx - 2][yy - 2] == t)
		{
			e2--;
			xx--;
			yy--;
			continue;
		}
		if (a[xx - 1][yy - 1] != t && a[xx - 1][yy - 1] != 0) emptynum2 = false;
		break;
	}
	xx = x; yy = y;
	while (true)
	{
		if (xx == 15 || yy == 15 || xx == 2 && a[xx + 1][yy + 1] != t || yy == 2 && a[xx + 1][yy + 1] != t) break;
		if (a[xx + 1][yy + 1] == t)
		{
			num2++;
			xx++;
			yy++;
			continue;
		}
		if (a[xx + 1][yy + 1] == 0 && e2 == 1 && a[xx + 2][yy + 2] == t)
		{
			e2--;
			xx++;
			yy++;
			continue;
		}
		if (a[xx + 1][yy + 1] != t && a[xx + 1][yy + 1] != 0) emptynum2 = false; 
		break;
	}
	if (num1 == 3 && e1 == 0 && emptynum1 || num2 == 3 && e2 == 0 && emptynum2) ans++;

	xx = x; yy = y; e1 = 1, num1 = 1, e2 = 1, num2 = 1; emptynum1 = true; emptynum2 = true;
	while (true)
	{
		if (xx == 1 || yy == 15 || xx == 2 && a[xx - 1][yy + 1] != t || yy == 14 && a[xx - 1][yy + 1] != t) break;
		if (a[xx - 1][yy + 1] == t)
		{
			num1++;
			xx--;
			yy++;
			continue;
		}
		if (a[xx - 1][yy + 1] == 0 && e1 == 1 && a[xx - 2][yy + 2] == t)
		{
			e1--;
			xx--;
			yy++;
			continue;
		}
		break;
	}
	xx = x; yy = y;
	while (true)
	{
		if (xx == 15 || yy == 1 || xx == 14 && a[xx + 1][yy - 1] != t || yy == 2 && a[xx + 1][yy - 1] != t) break;
		if (a[xx + 1][yy - 1] == t)
		{
			num1++;
			xx++;
			yy--;
			continue;
		}
		if (a[xx + 1][yy - 1] == 0 && e1 == 1 && a[xx + 2][yy - 2] == t)
		{
			e1--;
			xx++;
			yy--;
			continue;
		}
		break;
	}
	xx = x; yy = y;
	while (true)
	{
		if (xx == 15 || yy == 1 || xx == 14 && a[xx + 1][yy - 1] != t || yy == 2 && a[xx + 1][yy - 1] != t) break;
		if (a[xx + 1][yy - 1] == t)
		{
			num2++;
			xx++;
			yy--;
			continue;
		}
		if (a[xx + 1][yy - 1] == 0 && e2 == 1 && a[xx + 2][yy - 2] == t)
		{
			e2--;
			xx++;
			yy--;
			continue;
		}
		break;
	}
	xx = x; yy = y;
	while (true)
	{
		if (xx == 1 || yy == 15 || xx == 2 && a[xx - 1][yy + 1] != t || yy == 14 && a[xx - 1][yy + 1] != t) break;
		if (a[xx - 1][yy + 1] == t)
		{
			num2++;
			xx--;
			yy++;
			continue;
		}
		if (a[xx - 1][yy + 1] == 0 && e2 == 1 && a[xx - 2][yy + 2] == t)
		{
			e2--;
			xx--;
			yy++;
			continue;
		}
		break;
	}
	if (num1 == 3 && e1 == 0 && emptynum1 || num2 == 3 && e2 == 0 && emptynum2) ans++;

	if (ans >= 2) return 1;
	return 0;
}

int doublefour1(int x, int y, int t, int numx, int numy, int numz1, int numz2, int emptynumx, int emptynumy, int emptynumz1, int emptynumz2, int* four)
{
	int ans = 0, xx, yy, e1, e2, num1, num2;
	if (numx == 4 && emptynumx > 0) ans++;
	if (numy == 4 && emptynumy > 0) ans++;
	if (numz1 == 4 && emptynumz1 > 0) ans++;
	if (numz2 == 4 && emptynumz2 > 0) ans++;
	xx = x; yy = y; e1 = 1, num1 = 1, e2 = 1, num2 = 1;
	while (true)
	{
		if (xx == 1 || xx == 2 && a[xx - 1][yy] != t) break;
		if (a[xx - 1][yy] == t)
		{
			num1++;
			xx--;
			continue;
		}
		if (a[xx - 1][yy] == 0 && e1 == 1 && a[xx - 2][yy] == t)
		{
			e1--;
			xx--;
			continue;
		}
		break;
	}
	xx = x; yy = y;
	while (true)
	{
		if (xx == 15 || xx == 14 && a[xx + 1][yy] != t) break;
		if (a[xx + 1][yy] == t)
		{
			num1++;
			xx++;
			continue;
		}
		if (a[xx + 1][yy] == 0 && e1 == 1 && a[xx + 2][yy] == t)
		{
			e1--;
			xx++;
			continue;
		}
		break;
	}
	xx = x; yy = y;
	while (true)
	{
		if (xx == 15 || xx == 14 && a[xx + 1][yy] != t) break;
		if (a[xx + 1][yy] == t)
		{
			num2++;
			xx++;
			continue;
		}
		if (a[xx + 1][yy] == 0 && e2 == 1 && a[xx + 2][yy] == t)
		{
			e2--;
			xx++;
			continue;
		}
		
		break;
	}
	xx = x; yy = y;
	while (true)
	{
		if (xx == 1 || xx == 2 && a[xx - 1][yy] != t) break;
		if (a[xx - 1][yy] == t)
		{
			num2++;
			xx--;
			continue;
		}
		if (a[xx - 1][yy] == 0 && e2 == 1 && a[xx - 2][yy] == t)
		{
			e2--;
			xx--;
			continue;
		}
		break;
	}
	if (num1 == 4 && e1 == 0 || num2 == 4 && e2 == 0) ans++;

	xx = x; yy = y; num1 = 1; num2 = 1; e1 = 1; e2 = 1;
	while (true)
	{
		if (yy == 1 || yy == 2 && a[xx][yy - 1] != t) break;
		if (a[xx][yy - 1] == t)
		{
			num1++;
			yy--;
			continue;
		}
		if (a[xx][yy - 1] == 0 && e1 == 1 && a[xx][yy - 2] == t)
		{
			e1--;
			yy--;
			continue;
		}
		break;
	}
	xx = x; yy = y;
	while (true)
	{
		if (yy == 15 || yy == 14 && a[xx][yy + 1] != t) break;
		if (a[xx][yy + 1] == t)
		{
			num1++;
			yy++;
			continue;
		}
		if (a[xx][yy + 1] == 0 && e1 == 1 && a[xx][yy + 2] == t)
		{
			e1--;
			yy++;
			continue;
		}
		break;
	}
	xx = x; yy = y;
	while (true)
	{
		if (yy == 15 || yy == 14 && a[xx][yy + 1] != t) break;
		if (a[xx][yy + 1] == t)
		{
			num2++;
			yy++;
			continue;
		}
		if (a[xx][yy + 1] == 0 && e2 == 1 && a[xx][yy + 2] == t)
		{
			e2--;
			yy++;
			continue;
		}
		break;
	}
	xx = x; yy = y;
	while (true)
	{
		if (yy == 1 || yy == 2 && a[xx][yy - 1] != t) break;
		if (a[xx][yy - 1] == t)
		{
			num2++;
			yy--;
			continue;
		}
		if (a[xx][yy - 1] == 0 && e2 == 1 && a[xx][yy - 2] == t)
		{
			e2--;
			yy--;
			continue;
		}
		break;
	}
	if (num1 == 4 && e1 == 0 || num2 == 4 && e2 == 0) ans++;

	xx = x; yy = y; e1 = 1, num1 = 1, e2 = 1, num2 = 1;
	while (true)
	{
		if (xx == 15 || yy == 15 || xx == 14 && a[xx + 1][yy + 1] != t || yy == 14 && a[xx + 1][yy + 1] != t) break;
		if (a[xx + 1][yy + 1] == t)
		{
			num1++;
			xx++;
			yy++;
			continue;
		}
		if (a[xx + 1][yy + 1] == 0 && e1 == 1 && a[xx + 2][yy + 2] == t)
		{
			e1--;
			xx++;
			yy++;
			continue;
		}
		break;
	}
	xx = x; yy = y;
	while (true)
	{
		if (xx == 1 || yy == 1 || xx == 2 && a[xx - 1][yy - 1] != t || yy == 2 && a[xx - 1][yy - 1] != t) break;
		if (a[xx - 1][yy - 1] == t)
		{
			num1++;
			xx--;
			yy--;
			continue;
		}
		if (a[xx - 1][yy - 1] == 0 && e1 == 1 && a[xx - 2][yy - 2] == t)
		{
			e1--;
			xx--;
			yy--;
			continue;
		}
		break;
	}
	xx = x; yy = y;
	while (true)
	{
		if (xx == 1 || yy == 1 || xx == 2 && a[xx - 1][yy - 1] != t || yy == 2 && a[xx - 1][yy - 1] != t) break;
		if (a[xx - 1][yy - 1] == t)
		{
			num2++;
			xx--;
			yy--;
			continue;
		}
		if (a[xx - 1][yy - 1] == 0 && e2 == 1 && a[xx - 2][yy - 2] == t)
		{
			e2--;
			xx--;
			yy--;
			continue;
		}
		break;
	}
	xx = x; yy = y;
	while (true)
	{
		if (xx == 15 || yy == 15 || xx == 2 && a[xx + 1][yy + 1] != t || yy == 2 && a[xx + 1][yy + 1] != t) break;
		if (a[xx + 1][yy + 1] == t)
		{
			num2++;
			xx++;
			yy++;
			continue;
		}
		if (a[xx + 1][yy + 1] == 0 && e2 == 1 && a[xx + 2][yy + 2] == t)
		{
			e2--;
			xx++;
			yy++;
			continue;
		}
		break;
	}
	if (num1 == 4 && e1 == 0 || num2 == 4 && e2 == 0) ans++;

	xx = x; yy = y; e1 = 1, num1 = 1, e2 = 1, num2 = 1;
	while (true)
	{
		if (xx == 1 || yy == 15 || xx == 2 && a[xx - 1][yy + 1] != t || yy == 14 && a[xx - 1][yy + 1] != t) break;
		if (a[xx - 1][yy + 1] == t)
		{
			num1++;
			xx--;
			yy++;
			continue;
		}
		if (a[xx - 1][yy + 1] == 0 && e1 == 1 && a[xx - 2][yy + 2] == t)
		{
			e1--;
			xx--;
			yy++;
			continue;
		}
		break;
	}
	xx = x; yy = y;
	while (true)
	{
		if (xx == 15 || yy == 1 || xx == 14 && a[xx + 1][yy - 1] != t || yy == 2 && a[xx + 1][yy - 1] != t) break;
		if (a[xx + 1][yy - 1] == t)
		{
			num1++;
			xx++;
			yy--;
			continue;
		}
		if (a[xx + 1][yy - 1] == 0 && e1 == 1 && a[xx + 2][yy - 2] == t)
		{
			e1--;
			xx++;
			yy--;
			continue;
		}
		break;
	}
	xx = x; yy = y;
	while (true)
	{
		if (xx == 15 || yy == 1 || xx == 14 && a[xx + 1][yy - 1] != t || yy == 2 && a[xx + 1][yy - 1] != t) break;
		if (a[xx + 1][yy - 1] == t)
		{
			num2++;
			xx++;
			yy--;
			continue;
		}
		if (a[xx + 1][yy - 1] == 0 && e2 == 1 && a[xx + 2][yy - 2] == t)
		{
			e2--;
			xx++;
			yy--;
			continue;
		}
		break;
	}
	xx = x; yy = y;
	while (true)
	{
		if (xx == 1 || yy == 15 || xx == 2 && a[xx - 1][yy + 1] != t || yy == 14 && a[xx - 1][yy + 1] != t) break;
		if (a[xx - 1][yy + 1] == t)
		{
			num2++;
			xx--;
			yy++;
			continue;
		}
		if (a[xx - 1][yy + 1] == 0 && e2 == 1 && a[xx - 2][yy + 2] == t)
		{
			e2--;
			xx--;
			yy++;
			continue;
		}
		break;
	}
	if (num1 == 4 && e1 == 0 || num2 == 4 && e2 == 0) ans++;

	//printf("%d %d %d %d\n", x, y, ans, *four);

	*four += ans;
	if (ans >= 2 || *four >= 8) return 1;
	return 0;
}

int JudgeForbidden(int t)
{
	int numx = 1, numy = 1, numz1 = 1, numz2 = 1, emptynumx = 0, emptynumy = 0, emptynumz1 = 0, emptynumz2 = 0, xx, yy;
	int four = 0;
	for (int i = 1; i <= 15; i++)
	{
		for (int j = 1; j <= 15; j++)
		{
			if (a[i][j] == t)
			{
				numx = 1; numy = 1; numz1 = 1; numz2 = 1; emptynumx = 0; emptynumy = 0; emptynumz1 = 0; emptynumz2 = 0;
				xx = i, yy = j;
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
							emptynumx++;
							break;
						}
						else
						{
							break;
						}
				}
				xx = i; yy = j;
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
							emptynumx++;
							break;
						}
						else
						{
							break;
						}
				}
				xx = i; yy = j;
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
							emptynumy++;
							break;
						}
						else
						{
							break;
						}
				}
				xx = i; yy = j;
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
							emptynumy++;
							break;
						}
						else
						{
							break;
						}
				}
				xx = i; yy = j;
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
							emptynumz1++;
							break;
						}
						else
						{
							break;
						}
				}
				xx = i; yy = j;
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
							emptynumz1++;
							break;
						}
						else
						{
							break;
						}
				}
				xx = i; yy = j;
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
							emptynumz2++;
							break;
						}
						else
						{
							break;
						}
				}
				xx = i; yy = j;
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
							emptynumz2++;
							break;
						}
						else
						{
							break;
						}
					}
				}
				//printf("%d %d %d %d %d %d %d %d %d %d\n", i, j, numx, numy, numz1, numz2, emptynumx, emptynumy, emptynumz1, emptynumz2);
				switch (Forbidden)
				{
				case 1:if (doublethree1(i, j, t, numx, numy, numz1, numz2, emptynumx, emptynumy, emptynumz1, emptynumz2) == 1) return 1; break;
				case 2:if (doublefour1(i, j, t, numx, numy, numz1, numz2, emptynumx, emptynumy, emptynumz1, emptynumz2, &four) == 1) return 1; break;
				case 3:if (numx > 5 || numy > 5 || numz1 > 5 || numz2 > 5) return 1; break;
				}
			}
		}
	}
	return 0;
}