#include<stdio.h>
#include<math.h>
bool IsPrime(int num);
int main(){
	int n,i=0,operate;
	scanf("%d\n",&n);
	while(i<n){
		scanf("%d\n",&operate);
		if(IsPrime(operate))
			printf("yes\n");
		else
			printf("no\n");
		i++;
	}
	return 0;
}
bool IsPrime(int num){
	int i=2;
	while(i<sqrt(num)){
		if(num%i==0)
			return false;
		i++;
	}
	return true;
}