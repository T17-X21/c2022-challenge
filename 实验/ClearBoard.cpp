#include<stdio.h>
#include"gobang.h"

extern int a[16][16];

void ClearBoard()
{
	for (int i = 0; i <= 15; i++)
	{
		for (int j = 0; j <= 15; j++)
		{
			a[i][j] = 0;
		}
	}
}