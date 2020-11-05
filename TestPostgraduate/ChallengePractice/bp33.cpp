#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxx=1e4+100;
struct node{
	int s,e;
	bool operator<(const node &a)const{//判断应该如何排序
		if(s!=a.s) return s<a.s;
		else return e>a.e;
	}
}p[maxx];
int a[maxx],n,m;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) 
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++) 
		scanf("%d %d",&p[i].s,&p[i].e);
	sort(p+1,p+1+m);//按左端点升序，右端点降序排序
	int k,i,j,st=1;
	for(k=0;k<n;k++){//操作的次数=最少需要的点数
		int _max=1;
		for(i=1;i<=n;i++){
			for(j=st;j<=m;j++) 
				if(p[j].s>a[i]||p[j].e<a[i]) 
					break;
			if(j>_max) 
				_max=j;//看这个点最多可以满足多少个区间。
		}
		st=_max;//下次开始的时间就在上一次点的地方开始，寻找满足的点
		if(st==m+1) 
			break;//所有的线段满足了，就直接退出。
	}
	if(k==n) 
		printf("-1\n");
	else 
		printf("%d\n",k+1);
	return 0;
}