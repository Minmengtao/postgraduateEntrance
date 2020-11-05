#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int m,n,a[20];
int main(){
	int x;
	scanf("%d",&x);
	while(x--){
		scanf("%d %d",&n,&m);
		int i,j;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		long ans=1;
		i=0;j=0;
		while(m){
			int p=a[i]*a[i+1],q=a[n-j-1]*a[n-j-2];
			if(p>=q&&m>=2){
				ans*=p;
				m-=2;
				i+=2;
			}else{
				ans*=a[n-j-1];
				j++;
				m--;
			}
		}
		printf("%ld\n",ans);
	}
	return 0;
}