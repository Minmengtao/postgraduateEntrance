#include<cstdio>
int d(int x){
	int xx=x,sum=0;
	while(xx!=0){
		sum+=xx%10;
		xx/=10;
	}
	return x+sum;
}
int main(){
	int n,a[10050]={0};
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		a[d(i)]=1;
	for(int j=1;j<=n;j++)
		if(!a[j])
			printf("%d\n",j);
	return 0;
}