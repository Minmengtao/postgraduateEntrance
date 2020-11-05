#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int x,i;
	cin >> x;
	vector<int>arr(x);//存题目给出序列
	vector<int>dp(x, 1);//存i位置的能构成的最长不降序列
	for (i = 0; i < x; i++)
		cin >> arr[i];
	for (i = 0; i < x; i++)
		for (int j = 0; j < i; j++)
			if (arr[j] <= arr[i])
				dp[i] = max(dp[i], dp[j] + 1);
	int m = dp[0];
	for (i = 0; i < x; i++)
		m = max(m,dp[i]);
	cout << m << endl;
    return 0;
}