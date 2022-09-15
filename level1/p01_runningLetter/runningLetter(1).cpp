#include<cstdio>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
using namespace std;
using namespace std;
const int L = 0, R = 118;
int main()
{
	int flag = 1, cur = 0;
	while (1)
	{
		cur = cur + flag;
		if (cur == L || cur == R)
		{
			flag = -flag;
		}
		system("cls");
		for (int i = 1; i <= cur; i++)
		{
			putchar(' ');
		}
		putchar('A');
		Sleep(20);
	}
	return 0;
}
