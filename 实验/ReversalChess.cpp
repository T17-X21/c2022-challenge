#include<stdio.h>
#include"gobang.h"

extern int a[16][16];
extern bool AI_FIRST;

void ReversalChess()
{
	for (int i = 1; i <= 15; i++)
	{
		for (int j = 1; j <= 15; j++)
		{
			switch (a[i][j])
			{
			case 0:break;
			case 1:a[i][j] = 2; break;
			case 2:a[i][j] = 1; break;
			default:printf("Reversal Error\n"); break;
			}
		}
	}
	AI_FIRST = !AI_FIRST;
}