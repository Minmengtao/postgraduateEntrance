#include<stdio.h>
int main(){
	int year,month,day,sum=0;
	scanf("%d %d %d\n",&year,&month,&day);
	if(month==1)
		sum=day;
	else if(month==2)
		sum=31+day;
	else{
		if((year%4==0&&year%100!=0)||(year%400==0))
			sum=sum+29+31;
		else
			sum=sum+28+31;
		switch(month){
			case 3:sum+=day;break;
			case 4:sum=sum+day+31;break;
			case 5:sum=sum+day+61;break;
			case 6:sum=sum+day+92;break;
			case 7:sum=sum+day+122;break;
			case 8:sum=sum+day+153;break;
			case 9:sum=sum+day+184;break;
			case 10:sum=sum+day+214;break;
			case 11:sum=sum+day+245;break;
			case 12:sum=sum+day+275;break;
		}
	}
	printf("%d\n",sum);
	return 0;
}