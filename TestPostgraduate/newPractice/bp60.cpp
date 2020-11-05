#include<cstdio>
#include<algorithm>
using namespace std;
int n,m=0,a[105];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	for(int j=1;j<n;j++){
		if(a[m]!=a[j])
			a[++m]=a[j];
	}
	printf("%d\n",m+1);
	for(int k=0;k<=m;k++)
		printf("%d ",a[k]);
	printf("\n");
	return 0;
}