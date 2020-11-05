#include<stdio.h>
int main(){
	int year,month,day,n;
	int d[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	while(scanf("%d %d %d %d",&year,&month,&day,&n)!=EOF){
		if(n<=d[month-1]){
			if((year%4==0&&year%100!=0)||(year%400==0))
				d[1]++;
			if(n+day<=d[month-1])
				day=day+n;
			else{
				day=day+n-d[month-1];
				month++;
				if(month==13){
					year++;
					month=1;
				}
			}
			d[1]=28;
		}
		else{
			while(n>=d[month-1]){
				if((year%4==0&&year%100!=0)||(year%400==0))
					d[1]++;
				n=n-(d[month-1]-day+1);
				day=1;
				month++;
				if(month==13){
					month=1;
					year++;
				}
				d[1]=28;
			}
			day=n+1;
		}
		printf("%d %d %d\n",year,month,day);
	}
	return 0;
}