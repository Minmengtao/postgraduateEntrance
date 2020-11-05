#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int isPrime(int num);
int main(){
	char str[21];
	while(~scanf("%s",str)){
		int len=strlen(str),i,j,max=0,xyz;
		char num[5];
		for(i=0;i<len;i++){
			int k=0;
			for(j=i;j<i+4&&j<len&&k<4;j++){
				num[k++]=str[j];
				xyz=(int)atoi(num);
				if(isPrime(xyz)==1&&xyz>max)
					max=xyz;
			}
			for(k=0;k<5;k++)
				num[k]='\0';
		}
		printf("%d\n",max);
	}
	return 0;
}
int isPrime(int num){
	int i;
	if(num==0||num==1)
		return 0;
	else if(num==2)
		return 1;
	else{
		for(i=2;i<=sqrt(num);i++)
			if(num%i==0)
				return 0;
		return 1;
	}
}