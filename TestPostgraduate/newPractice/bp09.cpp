#include<cstdio>
int num;
int main(){
	scanf("%d",&num);
	for(int i=1;i<=num;i++)
		if(num%i==0)
			printf("%d * %d = %d\n",i,num/i,num);
	return 0;
}
