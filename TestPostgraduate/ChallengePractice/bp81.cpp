#include<stdio.h>
typedef struct Date{
	int year;
	int month;
	int day;
}Date;
Date d[4],date;
int x1,x2,x3,i,j,day[12]={31,28,31,30,31,30,31,31,30,31,30,31};
void order(){
	for(i=0;i<3;i++)
		for(j=i;j<3;j++)
			if((d[i].year>d[j].year)||(d[i].year==d[j].year&&d[i].month>d[j].month)
				||(d[i].year==d[j].year&&d[i].month==d[j].month&&d[i].day>d[j].year)){
				date=d[i];
				d[i]=d[j];
				d[j]=date;
			}
}
int judge(int n){
	if((n%4==0&&n%100!=0)||(n%400==0))
		return 1;
	else
		return 0;
}
int main(){
	while(~scanf("%d/%d/%d",&x1,&x2,&x3)){
		d[0].year=x1;d[0].month=x2;d[0].day=x3;
		d[1].year=x3;d[1].month=x1;d[1].day=x2;
		d[2].year=x3;d[2].month=x2;d[2].day=x1;
		for(i=0;i<3;i++){
			if(d[i].year>59)
				d[i].year=19*100+d[i].year;
			else
				d[i].year=20*100+d[i].year;
		}
		order();
		for(i=0;i<3;i++){
			if(i>=1&&d[i].year==d[i-1].year&&d[i].month==d[i-1].month&&d[i].day==d[i-1].day)
				continue;
			if(judge(d[i].year))
				day[1]++;
			if(d[i].month>0&&d[i].month<=12&&d[i].day<=day[d[i].month-1]&&d[i].day>0){
				printf("%d-",d[i].year);
				if(d[i].month<10)
					printf("0");
				printf("%d-",d[i].month);
				if(d[i].day<10)
					printf("0");
				printf("%d\n",d[i].day);
			}
			if(judge(d[i].year))
				day[1]--;
		}
	}
	return 0;
}
