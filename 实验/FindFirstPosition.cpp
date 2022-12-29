#include<stdio.h>
#include"gobang.h"

extern int a[16][16];
extern int x, y;

void FindFirstPosition()
{
	for (int i = 1; i <= 15; i++)
	{
		for (int j = 1; j <= 15; j++)
		{
			if (a[i][j] == 0)
			{
				x = i;
				y = j;
				return;
			}
		}
	}
	printf("No Position\n");
}