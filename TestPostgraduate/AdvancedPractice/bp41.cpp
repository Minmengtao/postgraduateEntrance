#include<stdio.h>
int main(){
	int a,b;
	while(scanf("%d %d",&a,&b)!=EOF){
		printf("%d*%d=",a,b);
		int temp=b,aa=a;
		while(aa!=1){
			if(aa%2!=0)
				printf("%d+",temp);
			temp*=2;
			aa=(int)aa/2;
		}
		printf("%d=%d\n",temp,a*b);
	}
	return 0;
}