#include<stdio.h>
int main(){
	int num1,num2,common,i,max,N,j=1;
	scanf("%d\n",&N);
	while(j<=N){
		scanf("%d %d\n",&num1,&num2);
		max=1;
		i=1;
		while(i<=num1&&i<=num2){
			if(num1%i==0&&num2%i==0&&i>max)
				max=i;
		    i++;
		}
		common=num1*num2/max;
		printf("%d\n",common);
		j++;
	}
	
	return 0;
}