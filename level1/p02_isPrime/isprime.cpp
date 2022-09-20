#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,i;
	cin>>n;
	for(i=2;i<=sqrt(n);i++)
	{
		if (n%i==0)
		{
			cout<<"Not prime";
			return 0;
		}
	}
	cout<<"Is prime";
	return 0;
}
