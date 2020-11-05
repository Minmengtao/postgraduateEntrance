#include<cstdio>
int num;
int main(){
	scanf("%d",&num);
	int count=0;
	while(num!=0){
		count++;
		num/=2;
	}
	printf("%d\n",count);
	return 0;
}