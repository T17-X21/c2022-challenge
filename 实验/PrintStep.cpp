#include<stdio.h>
#include<Windows.h>
#include"gobang.h"

extern int step;
extern int st[300][2];

void PrintStep()
{
	system("cls");
	for (int i = 1; i <= step; i++)
	{
		printf("step:%d x:%d y:%d\n", i, st[i][0], st[i][1]);
	}
}