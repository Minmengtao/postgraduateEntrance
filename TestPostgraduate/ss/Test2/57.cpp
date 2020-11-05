#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public: 
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    	int row = matrix.size(), col = matrix[0].size(), maxSum = INT_MIN;
		for(int l = 0; l < col; l++){
			vector<int> rowSum(row);
			for(int r = l; r < col; r++){
				for (int i = 0; i < row; i++)// 按每一行累计到 dp
                	rowSum[i] += matrix[i][r];
				// 求 rowSum 连续子数组 的 和
            	// 和 尽量大，但不大于 k
            	maxSum = max(maxSum, dpMax(rowSum, k));
            }
        }
    	return maxSum;
    }
	int dpMax(vector<int> arr, int k) {
    	int maxSum = INT_MIN;
    	for (int l = 0; l < arr.size(); l++) {
        	int sum = 0;
        	for (int r = l; r < arr.size(); r++) {
            	sum += arr[r];
            	if (sum > maxSum && sum <= k) 
					maxSum = sum;
        	}
    	}
    	return maxSum;
	}
};
int main(){
	vector<vector<int>> matrix;
	int k, data, m, n;
	cin >> m >> n;
	for(int i = 0; i < m; i++){
		vector<int> vec;
		for(int j = 0; j < n; j++){
			cin >> data;
			vec.push_back(data);
		}
		matrix.push_back(vec);
	}
	cin >> k;
	cout << Solution().maxSumSubmatrix(matrix, k);
	return 0;
}
