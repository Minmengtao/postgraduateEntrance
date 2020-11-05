#include<cstdio>
#include<cmath>
int main(){
	int n;
	scanf("%d",&n);
	double an;
	for(int a=1;a<=n/2;a++){
		an=sqrt(n*2+a*a-a+0.25)-0.5;
		if(an==int(an))
			printf("%d %d\n",a,(int)an);
	}
	return 0;
}