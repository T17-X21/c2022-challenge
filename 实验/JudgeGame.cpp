#include<stdio.h>
#include"gobang.h"

extern int a[16][16];
int JudgeGame(int x, int y)
{
	int num = 1, i = x;
	while (true)
	{
		i++;
		if (i > 15) break;
		if (a[i][y] == a[x][y])
			num++;
		else
			break;
	}
	i = x;
	while (true)
	{
		i--;
		if (i < 1) break;
		if (a[i][y] == a[x][y])
			num++;
		else
			break;
	}
	if (num >= 5) return 1;
	num = 1;
	i = y;
	while (true)
	{
		i++;
		if (i > 15) break;
		if (a[x][i] == a[x][y])
			num++;
		else
			break;
	}
	i = y;
	while (true)
	{
		i--;
		if (i < 1) break;
		if (a[x][i] == a[x][y])
			num++;
		else
			break;
	}
	if (num >= 5) return 1;
	num = 1;
	i = 0;
	while (true)
	{
		i++;
		if (x - i < 1 || y - i < 1) break;
		if (a[x - i][y - i] == a[x][y])
			num++;
		else
			break;
	}
	i = 0;
	while (true)
	{
		i++;
		if (x + i > 15 || y + i > 15) break;
		if (a[x + i][y + i] == a[x][y])
			num++;
		else
			break;
	}
	if (num >= 5) return 1;
	num = 1;
	i = 0;
	while (true)
	{
		i++;
		if (x - i < 1 || y + i > 15) break;
		if (a[x - i][y + i] == a[x][y])
			num++;
		else
			break;
	}
	i = 0;
	while (true)
	{
		i++;
		if (x + i > 15 || y - i < 1) break;
		if (a[x + i][y - i] == a[x][y])
			num++;
		else
			break;
	}
	if (num >= 5) return 1;
	return 0;
}