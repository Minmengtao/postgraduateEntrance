#include<cstdio>
int main(){
	double a[3]={0.0};
	int x;
	for(int i=0;i<3;i++){
		for(int j=0;j<=3;j++){
			scanf("%d",&x);
			a[i]+=x;
		}
		a[i]/=4;
	}
	for(int k=0;k<3;k++){
		if(a[k]==(int)a[k])
			printf("%d",(int)a[k]);
		else if(a[k]*2==(int)(a[k]*2))
			printf("%.1f",a[k]);
		else if(a[k]*4==(int)(a[k]*4))
			printf("%.2f",a[k]);
		printf(" ");
	}
	printf("\n");
	return 0;
}
