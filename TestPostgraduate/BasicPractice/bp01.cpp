#include<stdio.h>
#include<math.h>
int main(){
	double pi=3.1415927;
	double r,volume;
	printf("������뾶:");
	scanf("%lf",&r);
	if(r>=0&&r<=1000){
		volume=4*pi*pow(r,3)/3;
		printf("��뾶Ϊ:%.3f\n",volume);
	}
	return 0;
}