#include<stdio.h>
int main(){
	int base=100,rate,count=0;
	float sum=0.0;
	scanf("%d",&rate);
	if(rate>=0&&rate<=20){
		sum=100.0;
		while(sum<base*2){
			sum=sum*(1+(float)rate/100);
			count++;
		}
		printf("%d\n",count);
	}
	return 0;
}