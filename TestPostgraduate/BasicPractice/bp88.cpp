#include<stdio.h>
#include<string.h>
int main(){
	char str1[7],str2[7];
	scanf("%s\n%s\n",str1,str2);
	int len1=strlen(str1),len2=strlen(str2);
	int sum1=1,sum2=1;
	int i;
	for(i=0;i<len1;i++)
		sum1*=(str1[i]+1-'A');
	for(i=0;i<len2;i++)
		sum2*=(str2[i]+1-'A');
	sum1=sum1%47;sum2=sum2%47;
	if(sum1==sum2)
		printf("GO\n");
	else
		printf("STAY\n");
	return 0;
}