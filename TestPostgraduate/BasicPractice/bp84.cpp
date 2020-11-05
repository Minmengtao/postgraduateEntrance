#include<stdio.h>
#include<math.h>
int main(){
    double sum=1.0,threshold=1e-6,x;
    int i=0;
    __int64 n=1,e=1;
    scanf("%lf\n",&x);
    double last=x;
    while(last>=threshold){
        sum+=pow(-1.0,n-1)*last;
        n++;
        e*=n;
        last=(double)pow(x,n)/e;
    }
    printf("%.6f",sum);
    return 0;
}