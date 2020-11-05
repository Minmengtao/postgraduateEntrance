#include<stdio.h>
#include<string.h>
int main(){
	int m;
	char num[12];
	scanf("%d\n",&m);
	while(m--){
		scanf("%s\n",num);
		int len=strlen(num);
		printf("6");
		int i=0;
		for(i=6;i<len;i++)
			printf("%c",num[i]);
		printf("\n");
	}
	return 0;
}