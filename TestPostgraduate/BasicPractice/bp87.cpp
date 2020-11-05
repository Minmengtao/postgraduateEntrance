#include<stdio.h>
int cal(int coin);
int main(){
	int T;
	scanf("%d\n",&T);
	while(T--){
		int n,count=0;
		scanf("%d\n",&n);
		while(n--){
			int coin;
			scanf("%d",&coin);
			count+=cal(coin);
		}
		printf("%d\n",count);
	}
	return 0;
}
int cal(int coin){
	int i=0,count=0;
	count+=coin/100;
	coin=coin%100;
	count+=coin/50;
	coin=coin%50;
	count+=coin/20;
	coin=coin%20;
	count+=coin/10;
	coin=coin%10;
	count+=coin/5;
	coin=coin%5;
	count+=coin/2;
	coin=coin%2;
	count+=coin;
	return count;
}