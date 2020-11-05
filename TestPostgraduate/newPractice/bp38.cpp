#include<cstdio>
#include<cstring>
int main(){
	char str[1000];
	while(~scanf("%s",str)){
		for(int i=strlen(str)-1;i>=0;i--)
			putchar(str[i]);
		printf("\n");
	}
	return 0;
}