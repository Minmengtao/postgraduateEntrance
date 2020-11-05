#include<cstdio>
#include<algorithm>
using namespace std;
int m,n,k,dp[15],ci[55][55];
int count=0;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&ci[i][j]);
	return 0;
}