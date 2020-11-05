#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	char str[1000],s[5];
	while(scanf("%s",str)!=EOF){
		int len=strlen(str),i=0,j=0,k;
		__int64 sum=0;
		while(i<len){
			if(str[i]!='+'){
				s[j]=str[i];
				j++;
			}
			else{
				for(k=j;k<strlen(s);k++)
					s[k]='\0';
				sum+=atoi(s);
				j=0;
			}
			i++;
		}
		for(k=j;k<strlen(s);k++)
			s[k]=' ';
		sum+=atoi(s);
		printf("%I64d\n",sum);
	}
	return 0;
}