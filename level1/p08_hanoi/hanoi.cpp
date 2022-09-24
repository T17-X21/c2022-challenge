#include<stdio.h>

void hanoi(int n, char a, char b, char c)
{
	if (n == 0) {
		return;
	}
	hanoi(n - 1, a, c, b);
	printf("%c -> %c\n", a, c);
	hanoi(n - 1, b, a, c);
}
int main()
{
	int n;
	scanf_s("%d", &n);
	hanoi(n, 'A', 'B', 'C');
	return 0;
}