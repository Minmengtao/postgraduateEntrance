#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int x,i;
	cin >> x;
	vector<int>arr(x);//����Ŀ��������
	vector<int>dp(x, 1);//��iλ�õ��ܹ��ɵ����������
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