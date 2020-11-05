#include<stdio.h>
#include<math.h>
int main(){
	double x1,x2,y1,y2,distance;
	scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
	distance=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
	printf("%.2f\n",distance);
	return 0;
}