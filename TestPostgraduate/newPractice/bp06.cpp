#include<cstdio>
int main(){
	int sum,total;
	scanf("%d",&total);
	if(total<=160)
		sum=total*10;
	else
		sum=160*10+(total-160)*30;
	printf("%d\n",sum);
	return 0;
}