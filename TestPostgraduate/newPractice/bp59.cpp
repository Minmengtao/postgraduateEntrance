#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[1005],b[1005],m,l,r,k;
void strcpy(int x[],int y[]){
	for(int i=0;i<n;i++)
		y[i]=x[i];
};
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&m);
	strcpy(a,b);
	while(m--){
		scanf("%d%d%d",&l,&r,&k);
		sort(a+l-1,a+r);
		printf("%d\n",a[r-k]);
		strcpy(b,a);
	}
	return 0;
}