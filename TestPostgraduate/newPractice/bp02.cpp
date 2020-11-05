#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
long d,h,m,s;
void get(long x){
	if(x<10)
		printf("0");
	else
		printf("");
}
int main(){
	long t;
	scanf("%ld",&t);
	d=t/86400;
	t=t-d*24*60*60;
	h=t/3600;
	t=t-h*60*60;
	m=t/60;
	t-=m*60;
	s=t;
	if(d>=2){
		printf("%d days ",d);
		get(h);
		printf("%d:",h);
		get(m);
		printf("%d:",m);
		get(s);
		printf("%d",s);
	}else if(d>=1&&d<2){
		printf("1 day ");
		get(h);
		printf("%d:",h);
		get(m);
		printf("%d:",m);
		get(s);
		printf("%d",s);
	}else if(h>=1&&d<1){
		get(h);
		printf("%d:",h);
		get(m);
		printf("%d:",m);
		get(s);
		printf("%d",s);
	}else if(m>=1&&h<1){
		get(m);
		printf("%d:",m);
		get(s);
		printf("%d",s);
	}else if(s>=10&&m<1)
		printf("%ld",s);
	else
		printf("%ld",s);
	printf("\n");
	return 0;
}