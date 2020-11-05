#include<stdio.h>
#include<math.h>
int main(){
	int num1,num2,i,max,min,N,j=1,odd,even;
	scanf("%d\n",&N);
	while(j<=N){
		scanf("%d %d\n",&num1,&num2);
		if(num1>num2){
			max=num1;
			min=num2;
		}
		else{
			max=num2;
			min=num1;
		}
		i=min;
		odd=0;even=0;
		while(i<=max){
			if(i%2==0)
				even+=i*i;
			else
				odd+=i*i*i;
		    i++;
		}
		printf("%d %d\n",even,odd);
		j++;
	}
	
	return 0;
}