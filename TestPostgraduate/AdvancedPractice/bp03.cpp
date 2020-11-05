#include<stdio.h>
int main(){
	int a,b;
	scanf("%d %d\n",&a,&b);
	if(a!=0){
		double x=(double)(5-3*b)/(2*a);
		printf("%.1f\n",x);
	}
	return 0;
}