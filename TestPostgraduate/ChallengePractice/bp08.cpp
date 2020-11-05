#include<stdio.h>
double max(double x1,double x2);
double min(double x1,double x2);
int main(){
	double x1,x2,x3,x4,y1,y2,y3,y4;
	scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
	scanf("%lf %lf %lf %lf",&x3,&y3,&x4,&y4);
	double x_max,x_min,y_max,y_min;
	x_min=max(min(x1,x2),min(x3,x4));
	y_min=max(min(y1,y2),min(y3,y4));
	x_max=min(max(x1,x2),max(x3,x4));
	y_max=min(max(y1,y2),max(y3,y4));
	if(x_max>x_min&&y_max>y_min)
		printf("%.2f\n",(x_max-x_min)*(y_max-y_min));
	else
		printf("0.00\n");
	return 0;
}
double max(double x1,double x2){
	return x1>x2?x1:x2;
}
double min(double x1,double x2){
	return x1>x2?x2:x1;
}