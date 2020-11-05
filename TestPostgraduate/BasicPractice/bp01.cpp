#include<stdio.h>
#include<math.h>
int main(){
	double pi=3.1415927;
	double r,volume;
	printf("ÊäÈëÇò°ë¾¶:");
	scanf("%lf",&r);
	if(r>=0&&r<=1000){
		volume=4*pi*pow(r,3)/3;
		printf("Çò°ë¾¶Îª:%.3f\n",volume);
	}
	return 0;
}