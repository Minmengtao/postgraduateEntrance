#include<stdio.h>
#include<string.h>
int CountWords(char str[]);
int main(){
	char str[21];
	gets(str);
	char sign;
	sign=getchar();
	int len=strlen(str);
	int i=0;
	while(i<len){
		if(str[i]!=sign)
			printf("%c",str[i]);
		i++;
	}
	printf("\n");
	return 0;
}