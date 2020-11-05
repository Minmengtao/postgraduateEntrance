#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
 
#define MAXN 1000
#define MAXM
#define INF 0x3f3f3f3f
#define LL long long
 
int map[MAXN+10][MAXN+10];
int f[MAXN+10][MAXN+10];
int N;
 
int main()
{
    scanf("%d",&N);
    int i,j;
    for(i=1;i<=N;++i)
        for(j=1;j<=i;++j)
            scanf("%d",&map[i][j]);
     
    memset(f,0,sizeof(f));
     
    for(j=1;j<=N;++j)
        f[N][j]=map[N][j];
    for(i=N-1;i>=1;--i)
        for(j=1;j<=i;++j)
        {
            f[i][j]=max(f[i][j],map[i][j]+f[i+1][j]);
            f[i][j]=max(f[i][j],map[i][j]+f[i+1][j+1]);
        }
     
    printf("%d\n",f[1][1]);
	return 0;
}
