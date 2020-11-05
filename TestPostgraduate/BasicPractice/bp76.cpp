#include<stdio.h>
#include<string.h>
int main(){
	char str[100];
	while(scanf("%s\n",str)!=EOF){
		int i=0,j;
		int len=strlen(str);
		char temp;
		for(;i<len-1;i++)
			for(j=i+1;j<len;j++)
				if(str[i]>str[j]){
					temp=str[i];
					str[i]=str[j];
					str[j]=temp;
				}
		for(i=0;i<len;i++)
			printf("%c\n",str[i]);
		printf("\n");
	}
	return 0;
}