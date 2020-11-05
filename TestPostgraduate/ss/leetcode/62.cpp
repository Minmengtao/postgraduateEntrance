#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
    	int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        int dp[105][105], flag1 = 1, flag2 = 1;
        for(int i = 1; i <= max(m, n); i++){
        	if(i <= n && obstacleGrid[0][i-1])
        		flag1 = 0;
        	dp[1][i] = flag1 ? 1:0;
        	if(i <= m && obstacleGrid[i-1][0])
        		flag2 = 0;
        	dp[i][1] = flag2 ? 1:0;
		}
        for(int i = 2; i <= m; i++)
        	for(int j = 2; j <= n; j++){
        		if(!obstacleGrid[i-1][j-1])
        			dp[i][j] = dp[i-1][j] + dp[i][j-1];
        		else
        			dp[i][j] = 0;
			}
        return dp[m][n];
    }
};
int main(){
	int m, n, data;
	cin >> m >> n;
	vector<vector<int>> obstacleGrid;
	for(int i = 0; i < m; i++){
		vector<int> v;
		for(int j = 0; j < n; j++){
			cin >> data;
			v.push_back(data);
		}
		obstacleGrid.push_back(v);
	}
	cout << Solution().uniquePathsWithObstacles(obstacleGrid);
	return 0;
}
