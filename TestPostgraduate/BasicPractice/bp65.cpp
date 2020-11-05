#include<stdio.h>
#include<string.h>
int main(){
	char num[101];
	while(scanf("%s\n",num)!=EOF){
		int len=strlen(num);
		int i=0,count=0;
		while(num[i]!='.')
			i++;
		if(i!=len-1)
			printf("%d\n",len-i-1);
		else
			printf("0\n");

	}
	return 0;
}