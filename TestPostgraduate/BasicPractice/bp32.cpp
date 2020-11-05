#include<stdio.h>
int isTrue(int);
int main(){
	int n,num1,num2,max,min,i=0,j,count;
	scanf("%d\n",&n);
	if(n>0)
		while(i<n){
			scanf("%d %d\n",&num1,&num2);
			count=0;
			if(num1>1&&num1<10000&&num2>1&&num2<10000){
				if(num1>num2){
					max=num1;
					min=num2;
				}else{
					max=num2;
					min=num1;
				}
				j=min;
				while(j<=max){
					if(isTrue(j)==1)
						count++;
					j++;
				}

			}
			printf("%d\n",count);
			i++;
		}
	return 0;
}
int isTrue(int n){
	int i=1,sum=0;
	while(i<n){
		if(n%i==0)
			sum+=i;
		i++;
	}
	if(sum==n)
		return 1;
	else
		return 0;
}