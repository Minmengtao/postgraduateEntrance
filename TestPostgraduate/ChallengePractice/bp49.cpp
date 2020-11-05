#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 1000010;
int fa[N],vi[N];
int find(int x){
    if(x==fa[x])return x;
    return fa[x]=find(fa[x]);
}
int main(){
    int n,m,k,a,b,i;
    scanf("%d %d",&m,&n);
    int tot=n*m;
    for(i=1;i<=tot;i++)
        fa[i]=i;
    scanf("%d",&k);
    memset(vi,0,sizeof vi);
    for(i=0;i<k;i++){
        scanf("%d %d",&a,&b);
        fa[find(a)]=find(b);
    }
    for(i=1;i<=tot;i++){
        int t=find(i);
        vi[t]++;
    }
    int res=0;
    for(i=1;i<=tot;i++)
        if(vi[i])
            res++;
    printf("%d\n",res);
	return 0;
}