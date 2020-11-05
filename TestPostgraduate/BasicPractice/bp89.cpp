#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(){
	char num[1001];
	while(scanf("%s\n",num)!=EOF){
		char sign;
		int len=strlen(num),i=0,k=0;
		while(i<len){

			sign=tolower(num[i]);
			int count=1,j=i+1;
			while(j<len&&sign==tolower(num[j])){
				count++;
				j++;
			}
			if(count!=1)
				printf("%d",count);
			printf("%c",sign);
			i=j;
		}
		printf("\n");
	}
	return 0;
}