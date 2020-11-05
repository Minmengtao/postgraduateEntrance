#include<stdio.h>
int main(){
	double threshold,sum=0.0,standard=1e-10,last=0.0;
	int n=0;
	__int64 count=1;
	scanf("%lf\n",&threshold);
	if(threshold>=standard){
		do{
		    n++;
			sum+=last;
		    last=(double)1/count;
			count=count*n;
		}while(last>=threshold);
		printf("%.6f %d\n",sum,n-1);
	}
	return 0;
}