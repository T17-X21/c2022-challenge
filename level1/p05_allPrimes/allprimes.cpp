#include<stdio.h>
#include<windows.h>
using namespace std;
int main()
{
	int t[100000];
	double run_time;
	_LARGE_INTEGER time_start;
	_LARGE_INTEGER time_over;
	double dqFreq;
	LARGE_INTEGER f;
	QueryPerformanceFrequency(&f);
	dqFreq=(double)f.QuadPart;
	QueryPerformanceCounter(&time_start);
	int a[1001]={0},i,j;
	for(i=3;i<=31;i++)
		for(j=3;j<=1000/i;j++)
		{
			a[i*j]=1;
		}
	printf("2 ");
	for (i=3;i<=991;i=i+2)
	{
		if (a[i]==0)
		{
			printf("%d ",i);
		}
	}
	printf("997\n");
	QueryPerformanceCounter(&time_over);
	run_time=(time_over.QuadPart-time_start.QuadPart)/dqFreq;
	printf("run_time:%fs\n",run_time);
	//getchar();
	return 0;
}
