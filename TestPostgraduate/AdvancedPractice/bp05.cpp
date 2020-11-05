#include<stdio.h>
int main(){
	int year,month,day,constant,year1,month1,day1;
	while(scanf("%d %d %d %d",&year,&month,&day,&constant)!=EOF){
		int m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
		int in=(month+constant)/12;
		year1=year+in;
		month1=(month+constant)%12;
		if((year1%400==0)||(year1%4==0&&year1%100!=0))
			m[2]++;
		if(day<m[month1])
			day1=day;
		else
			day1=m[month1];
		printf("%d %d %d\n",year1,month1,day1);
	}
	return 0;
}