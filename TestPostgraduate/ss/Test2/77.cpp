#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	int dxy[4][2] = {{1,0}, {0, 1}, {-1,0}, {0,-1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    	queue<vector<int>> q;
    	int m = matrix.size(), n = matrix[0].size();
    	for(int i = 0; i < m; i++){
    		for(int j = 0; j < n; j++){
    			if(!matrix[i][j])
    				q.push(vector<int>{i, j});
    			else
    				matrix[i][j] = -1;//-1与0相区分
			}
		}
		while(!q.empty()){
			vector<int> vec = q.front();
			q.pop();
			for(int i = 0; i < 4; i++){
				int xx = vec[0] + dxy[i][0], yy = vec[1] + dxy[i][1];
				if(xx >= 0 && xx < m && yy >= 0 && yy < n && matrix[xx][yy] == -1){
					matrix[xx][yy] = matrix[vec[0]][vec[1]] + 1;
					q.push(vector<int>{xx, yy});
				}
			}
		}
		return matrix;
    }
};
int main(){
    vector<vector<int> > matrix;
    int m,n;
    cin>>m;
    cin>>n;
    char ch;
    for(int i=0; i<m; i++){
        vector<int> aLine;
        for(int j=0; j<n; j++){
            cin>>ch;
            aLine.push_back(ch-'0');
        }
        matrix.push_back(aLine);
    }
    vector<vector<int>> res=Solution().updateMatrix(matrix);
    for(int i=0; i<res.size(); i++){
        vector<int> aLine = res[i];
        for(int j=0; j<aLine.size(); j++)
            cout<<aLine[j];
        cout<<endl;
    }
    return 0;
}
