#include<stdio.h>
#include<string.h>
int judge(char *str,int len,int i);
int main(){
	char str[1001];
	scanf("%s",str);
	int len=strlen(str),i;
	for(i=len;i>=1;i--)
		if(len%i==0&&judge(str,len,i)){
			printf("%d\n",i);
			break;
		}
	return 0;
}
int judge(char *str,int len,int i){
	int div=len/i,j,k;
	for(j=1;j<=i;j++)
		for(k=(j-1)*div;k<j*div;k++)
			if(str[k-(j-1)*div]!=str[k])
				return 0;
	return 1;
}
