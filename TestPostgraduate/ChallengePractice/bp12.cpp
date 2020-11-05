#include<stdio.h>
int main(){
	int h=0,m=0,s=0,t;
	scanf("%d",&t);
	h=t/3600;
	t=t-3600*h;
	m=t/60;
	t=t-m*60;
	s=t;
	printf("%d:%d:%d\n",h,m,s);
	return 0;
}