#include<iostream>
#include<cstdio>
#include<cmath>
#define pi 3.1415926
using namespace std;
double sum=0.0;
void jisuan(double x1,double y1,double x2,double y2,double x3,double y3,double r){
	double dl;
	double cy=(y1+y3)/2;
	double flagy=cy-y2;
	double mx=x2-x1;
	double my=y2-y1;
	double nx=x2-x3;
	double ny=y2-y3;
	double m=sqrt(mx*mx+my*my);
	double n=sqrt(nx*nx+ny*ny);
	sum+=n;
	double cos=(mx*nx+my*ny)/(m*n);
	double angle=acos(cos);
	if(flagy>0){
		dl=2*r/tan(angle/2);
		sum-=dl;
	}else{
		angle=pi-angle;
		dl=r*angle;
		sum+=dl;
	}
}
double len(double x[],double y[],double r,int n){
	sum+=sqrt((x[1]-x[0])*(x[1]-x[0])+(y[1]-y[0])*(y[1]-y[0]));
	int i;
	for(i=1;i<n-1;i++)
		jisuan(x[i-1],y[i-1],x[i],y[i],x[i+1],y[i+1],r);
	return sum;
}
int main(){
	int n,i;
	double r;
	double x[105],y[105];
	cin>>n>>r;
	for(i=0;i<n;i++){
		cin>>x[i];
		cin>>y[i];
	}
	printf("%.2f\n",len(x,y,r,n));
	return 0;
}