#include<stdio.h>
#include<string.h>
int main(){
	char num[1002];
	while(scanf("%s\n",num)!=EOF){
		int len=strlen(num);
		int i=0;
		if(num[i]!='-')
			printf("%s",num);
		else
			for(i=1;i<len;i++)
				printf("%c",num[i]);
		printf("\n");
	}
	return 0;
}