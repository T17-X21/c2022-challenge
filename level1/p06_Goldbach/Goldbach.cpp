#include<stdio.h>

int main()
{
	int a[101];
	for(int i=1;i<=100;i++) a[i]=1;
	for (int i=2;i<=10;i++)
		for (int j = 2; j <= 100/i; j++) {
			a[i * j] = 0;
		}
	printf("4=2+2\n");
	for (int i = 4; i <= 100; i = i + 2) {
		for (int j = 3; j <= i; j += 2) {
			if (a[j] == 1 && a[i - j] == 1) {
				printf("%d=%d+%d\n", i, j, i - j);
				break;
			}
		}
	}
	return 0;
}
