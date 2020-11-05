#include<cstdio>
#include<cmath>
int main(){
	int n,ai,bi,ci,di,ei,fi,ti,x1,y1,z1,x2,y2,z2;
	int a1=0,a2=0,a3=0,b1=0,b2=0,b3=0;
	scanf("%d",&n);
	while(n--){
		scanf("%d%d%d%d%d%d%d",&ai,&bi,&ci,&di,&ei,&fi,&ti);
		a1+=ai*ti;
		a2+=bi*ti;
		a3+=ci*ti;
		b1+=di*ti;
		b2+=ei*ti;
		b3+=fi*ti;
	}
	scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2);
	x1+=a1;
	y1+=a2;
	z1+=a3;
	x2+=b1;
	y2+=b2;
	z2+=b3;
	printf("%.4f\n",sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2)));
	return 0;
}