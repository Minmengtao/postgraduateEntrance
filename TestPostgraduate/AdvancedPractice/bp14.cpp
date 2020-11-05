#include<stdio.h>
int spaced(int year,int month);
int main(){
	int n;
	scanf("%d\n",&n);
	int count[7]={0,0,0,0,0,0,0};//��������.����һ.���������
	//i=0��ʾ��ֵ�����������
	int i,j;
	for(i=1900;i<=1900+n-1;i++){
		for(j=1;j<=12;j++){
			int k=spaced(i,j);
			switch(k%7){
				case 1:count[2]++;break;//����һ
				case 2:count[3]++;break;//���ڶ�
				case 3:count[4]++;break;//������
				case 4:count[5]++;break;//������
				case 5:count[6]++;break;//������
				case 6:count[0]++;break;//������
				case 0:count[1]++;break;//������
			}
		}
	}
	for(i=0;i<=5;i++)
		printf("%d ",count[i]);
	printf("%d\n",count[6]);
	return 0;
}
int spaced(int year,int month){
	int year1=1900,month1=1,day1=1;
	int day=13;
	int i,count=0;
	for(i=year1;i<year;i++)
		if((i%4==0&&i%100!=0)||i%400==0)
			count++;
	int sum=365*(year-year1-count)+366*count;
	switch(month){
		case 1:sum+=day;break;
		case 2:sum+=day+31;break;
		case 3:sum+=day+59;break;
		case 4:sum+=day+90;break;
		case 5:sum+=day+120;break;
		case 6:sum+=day+151;break;
		case 7:sum+=day+181;break;
		case 8:sum+=day+212;break;
		case 9:sum+=day+243;break;
		case 10:sum+=day+273;break;
		case 11:sum+=day+304;break;
		case 12:sum+=day+334;break;
	}
	if(((year%4==0&&year%100!=0)||year%400==0)&&month>2)
		sum++;
	return sum;
}