#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
	int dxy[4][2] = {{1,0}, {0,1}, {0,-1}, {-1,0}};
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0 || board[0].size() == 0)
            return;
		int m = board.size(), n = board[0].size();
        queue<vector<int>> q;
        map<vector<int>, int> need;
        for(int i = 0; i < m; i++){//记录外边界的0的位置 
        	if(board[i][0] == 'O'){
        		q.push(vector<int>{i, 0});
        		need[vector<int>{i, 0}] = 1;
			}
        	if(board[i][n - 1] == 'O'){
        		q.push(vector<int>{i, n - 1});
        		need[vector<int>{i, n - 1}] = 1;
			}
        		
		}
		for(int i = 0; i < n; i++){
        	if(board[0][i] == 'O'){
        		q.push(vector<int>{0, i});
        		need[vector<int>{0,i}] = 1;
			}
        	if(board[board.size() - 1][i] == 'O'){
        		q.push(vector<int>{m - 1, i});
        		need[vector<int>{m - 1, i}] = 1;
			}
        		
		}
		while(!q.empty()){
			vector<int> res = q.front();
			q.pop();
			for(int i = 0; i < 4; i++){
				int xx = dxy[i][0] + res[0], yy = dxy[i][1] + res[1];
				if(xx>=0 && xx<m && yy>=0 && yy<n && !need.count(vector<int>{xx, yy}) && board[xx][yy]=='O'){
					q.push(vector<int>{xx, yy});
					need[vector<int>{xx, yy}];
				}
			} 
		}
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				if(!need.count(vector<int>{i,j}) && board[i][j] == 'O')
					board[i][j] = 'X';
		}
    }
};
int main(){
    vector<vector<char> > board;
    int m,n;
    cin>>m>>n;
    char ch;
    for(int i=0; i<m; i++){
        vector<char> aLine;
        for(int j=0; j<n; j++){
            cin>>ch;
            aLine.push_back(ch);
        }
        board.push_back(aLine);
    }
    Solution().solve(board);
    for(int i=0; i<board.size(); i++){
        vector<char> aLine = board[i];
        for(int j=0; j<aLine.size(); j++)
            cout<<aLine[j];
        cout<<endl;
    }
    return 0;
}
