#include<stdio.h>
int n,k,cube[100001][2],max;
int judge(int mid){
	__int64 sum=0,i;
	for(i=0;i<n;i++){
		sum+=(cube[i][0]/mid)*(cube[i][1]/mid);
		if(sum>=k){
			max=mid;
			return 1;
		}
	}
	return 0;
}
int main(){
	while(~scanf("%d %d",&n,&k)){
		int i,low=1,high=100000,mid;
		for(i=0;i<n;i++)
			scanf("%d %d",&cube[i][0],&cube[i][1]);
		while(low<high-1){
			mid=(low+high)/2;
			if(judge(mid))
				low=mid;
			else
				high=mid;
		}
		printf("%d\n",max);
	}
	return 0;
}
/*#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#define inf 100000
using namespace std;
int n, k;
int choco[inf+5][2];
int mint = inf;
int ans = 0;
bool isright(int length){
	long long sum = 0;
	for(int i = 0; i < n; i++){
		sum += (choco[i][0]/length) * (choco[i][1]/length);
		if(sum >= k){
			ans = length;
			return true;
		}
	}
	return false;
}
int main(){
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &choco[i][0], &choco[i][1]);
		int temp = min(choco[i][0], choco[i][1]);
        if(mint < temp)
			mint = temp;
	}
	int left = 0;
	int right = mint + 1;
	while(left + 1 < right){
		int mid = (left + right) / 2;
		if(isright(mid))
			left = mid;
		else
			right = mid;
	}
	cout << ans << endl;
	return 0;
}*/