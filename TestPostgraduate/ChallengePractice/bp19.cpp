#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(){
	int times[10000],d[10000],n,m,sumTime=0,i;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%d",&times[i]);
	sort(times,times+n);
	for(i=0;i<n;i++){
		sort(d,d+m); 
		sumTime+=d[0]+times[i];
		d[0]+=times[i];
	}
	printf("%d\n",sumTime);
	return 0;
}