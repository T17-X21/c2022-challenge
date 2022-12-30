#include<stdio.h>
#include<Windows.h>
#include"gobang.h"

extern int a[16][16];
void PrintMap()
{
	system("cls");
	for (int i = 1; i <= 15; i++)
	{
		for (int j = 1; j <= 14; j++)
		{
			printf("%d ", a[j][i]);
		}
		printf("%d\n", a[15][i]);
	}
}