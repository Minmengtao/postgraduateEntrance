#include<stdio.h>
int main(){
	int year,month;
	scanf("%d %d",&year,&month);
	if(month<10)
		printf("Calendar %d - 0%d\n",year,month);
	else
		printf("Calendar %d - %d\n",year,month);
	printf("---------------------\n");
	printf("Su Mo Tu We Th Fr Sa\n");
	printf("---------------------\n");
	int day[12]={31,28,31,30,31,30,31,31,30,31,30,31},sumDay=0;
	if(year==2007){
		int i;
		for(i=1;i<month;i++)
			sumDay+=day[i-1];
	}else{
		int i,j;
		for(i=2007;i<=year;i++)
			for(j=1;(i<year&&j<=12)||(i==year&&j<month);j++){
				if(((i%4==0&&i%100!=0)||(i%400==0))&&j==2){
					day[1]++;
					sumDay+=day[1];
					day[1]--;
				}else
					sumDay+=day[j-1];
			}
	}
	if((year%4==0&&year%100!=0)||(year%400==0))
		day[1]++;
	int k;
	for(k=1;k<=day[month-1];k++){
		sumDay=(sumDay+1)%7;
		int mm;
		for(mm=0;mm<sumDay&&k==1;mm++)
			printf("   ");
		printf("%2d ",k);
		if(sumDay==6)
			printf("\n");
	}
	if(sumDay!=6)
		printf("\n");
	printf("---------------------\n");
	return 0;
}