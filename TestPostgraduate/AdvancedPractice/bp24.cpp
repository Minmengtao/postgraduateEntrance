#include<stdio.h>
int main(){
	int T;
	scanf("%d\n",&T);
	while(T--){
		int n;
		scanf("%d\n",&n);
		double num,price,sum_price=0.0;
		while(n--){
			char s[1000];
			scanf("%s %lf %lf",s,&num,&price);
			sum_price=sum_price+num*price;
		}
		printf("%.1f\n",sum_price);
	}
	return 0;
}