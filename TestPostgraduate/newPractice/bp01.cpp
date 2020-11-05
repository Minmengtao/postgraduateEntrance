#include<stdio.h>
int main(){
	long t;
	scanf("%ld",&t);
	long day,hour,minute,second;
	day=t/86400;
	t=t-day*24*60*60;
	hour=t/3600;
	t=t-hour*60*60;
	minute=t/60;
	t-=minute*60;
	second=t;
	printf("%ld days %ld:%ld:%ld\n",day,hour,minute,second);
	return 0;
}