#include <cstdio> 
#include <iostream>
#include <algorithm>
#define LL long long
using namespace std;
int sum[100001]; // sum[i] 前i个元素的和 
int num[100001]={0},cnt[100001]={0},n,k;
LL ans = 0;
int main(){
	scanf("%d%d",&n, &k);
	for(int i = 1; i <= n; i++){
		scanf("%d",&num[i]);
		sum[i] = (sum[i-1] + num[i])%k;
		ans += cnt[sum[i]];
		cnt[sum[i]]++;
	}
	
	printf("%lld\n",ans+cnt[0]);
	return 0;
}