#include<stdio.h>
int main(){
	int num,sum,division;
	while(scanf("%d\n",&num)!=EOF){
		division=1;
		sum=0;
		while(division<=num){
			if(num%division==0)
				sum+=division;
			division++;
		}
		printf("%d\n",sum);
	}
	return 0;
}