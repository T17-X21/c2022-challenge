#include<stdio.h>
#include<string.h>
const int key=2;
int main()
{
	char str[1001];
	gets(str);
	for(int i;i<strlen(str);i++){
		if (str[i]>='A'&&str[i]<='Z'){		
			str[i]=(str[i]-'A'+key)%26+'A';
		}else
		if (str[i]>='a'&&str[i]<='z'){
			str[i]=(str[i]-'a'+key)%26+'a';
		}else
		if (str[i]>='0'&&str[i]<='9'){
			str[i]=(str[i]-'0'+key)%10+'0';
		}
	}
	puts(str);
	return 0;
}
