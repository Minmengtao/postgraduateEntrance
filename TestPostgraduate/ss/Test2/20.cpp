#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        int rows = heightMap.size(), cols = heightMap[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                    q.push({heightMap[i][j], i * cols + j});
                    visited[i][j] = true;
                }
            }
        }
        int mx = INT_MIN;
        int res = 0;
        vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
        while (!q.empty()) {
            auto t = q.top(); q.pop();
            int h = t.first;
            int r = t.second / cols, c = t.second % cols;
            mx = max(mx, h);
            for (auto dir : dirs) {
                int x = r + dir[0], y = c + dir[1];
                if (x < 0 || x >= rows || y < 0 || y >= cols || visited[x][y]) continue;
                visited[x][y] = true;
                if (mx > heightMap[x][y]) res += mx - heightMap[x][y];
                q.push({heightMap[x][y], x * cols + y});
            }
        }
        return res;
    }
};
int main(){
    int m, n,data;
    vector<vector<int> > heights;
    cin>>m>>n;
    for(int i=0; i<m; i++){
        vector<int> row;
        for(int j=0; j<n; j++){
            cin>>data;
            row.push_back(data);
        }
        heights.push_back(row);
    }
    int res=Solution().trapRainWater(heights);
    cout<<res<<endl;
    return 0;
}
