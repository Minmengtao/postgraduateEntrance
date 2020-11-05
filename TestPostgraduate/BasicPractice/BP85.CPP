#include<stdio.h>
#include<math.h>
int main(){
	double x,threshold;
	while(scanf("%lf %lf\n",&x,&threshold)!=EOF){
		int i=0;
		long n=1,e=1;
		double js=1.0,s=0.0;
		while(fabs(js)>=threshold){
			s=s+js;
			js=js*(0.5-n+1)*x*1.0/n;
			n++;
		}
		printf("%.6f\n\n",s);
	}
	return 0;
}