#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
    	int m = grid.size(), n = grid[0].size();
    	int dp[1005][1005];
    	dp[0][1] = 0;
    	dp[1][0] = 0;
		for(int i = 1; i <= m; i++)
			dp[i][1] = grid[i-1][0] + dp[i-1][1];
		for(int j = 1; j <= n; j++)
			dp[1][j] = grid[0][j-1] + dp[1][j-1];
    	for(int i = 2; i <= m; i++)
    		for(int j = 2; j <= n; j++)
    			dp[i][j] = grid[i-1][j-1] + min(dp[i-1][j], dp[i][j-1]);
		return dp[m][n];
    }
};
int main(){
	int m, n, data;
	vector<vector<int>> grid;
	cin >> m >> n;
	for(int i = 0; i < m; i++){
		vector<int> v;
		for(int j = 0; j < n; j++){
			cin >> data;
			v.push_back(data);
		}
		grid.push_back(v);
	}
	cout << Solution().minPathSum(grid);
	return 0;
} 
