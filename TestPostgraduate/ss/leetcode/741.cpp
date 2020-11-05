#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
    	int m = grid.size(), n = grid[0].size();
        int dp[105][105]={{0}}, flag1 = 1, flag2 = 1;
        for(int i = 1; i <= n; i++){
        	if(grid[0][i-1] == -1)
        		flag1 = 0;
        	dp[1][i] = flag1 ? (dp[1][i-1]+grid[0][i-1]):0;
        }
        for(int i = 1; i <= m; i++){
        	if(grid[i-1][0] == -1)
        		flag2 = 0;
        	dp[i][1] = flag2 ? (dp[i-1][1]+grid[i-1][0]):0;
		}
        for(int i = 2; i <= m; i++)
        	for(int j = 2; j <= n; j++){
        		if(grid[i-1][j-1] != -1)
        			dp[i][j] = grid[i-1][j-1] + max(dp[i-1][j], dp[i][j-1]);
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
	cout << Solution().cherryPickup(obstacleGrid);
	return 0;
}
