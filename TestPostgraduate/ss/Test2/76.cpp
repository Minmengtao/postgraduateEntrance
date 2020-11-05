#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
public:
	int dxy[8][2] = {{1,1}, {1,0}, {1,-1}, {0,1}, {0,-1}, {-1,1}, {-1,0}, {-1,-1}};
	vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click){
		int x = click[0], y = click[1];
		if(board[x][y] == 'M'){
			board[x][y] = 'X';
			return board;
		}
		queue<vector<int>> q;
		q.push(vector<int>{x, y});
		while(!q.empty()){
			vector<int> res = q.front();
			q.pop();
			int cnt = calWhite(board, res[0], res[1]);
			if(cnt){//ÅÔ±ßÓÐMµÄ³ýÈ¥ 
				board[res[0]][res[1]] = cnt + '0';
				continue;
			}
			board[res[0]][res[1]] = 'B';
			for(int i = 0; i < 8; i++){
				int xx = res[0] + dxy[i][0], yy = res[1] + dxy[i][1];
				if(xx>=0 && yy>=0 && xx<board.size() && yy< board[0].size() && board[xx][yy] == 'E'){
					board[xx][yy] = 'B';
					q.push(vector<int>{xx, yy}); 
				}
			}
		}
		return board;
	}
	int calWhite(vector<vector<char>>& board, int x, int y){
		int res = 0;
		for(int i = 0; i < 8; i++){
			int xx = dxy[i][0] + x, yy = dxy[i][1] + y;
			if(xx>=0 && yy>=0 && xx<board.size() && yy< board[0].size() && board[xx][yy] == 'M')
				res++;
		}
		return res;
	}
};
int main(){
    vector<vector<char> > board;
    int m,n,x,y;
    cin>>m;
    cin>>n;
    char ch;
    for(int i=0; i<m; i++){
        vector<char> aLine;
        for(int j=0; j<n; j++){
            cin>>ch;
            aLine.push_back(ch);
        }
        board.push_back(aLine);
    }
    cin>>x>>y;
    vector<int> click;
    click.push_back(x);
    click.push_back(y);
    vector<vector<char>> res=Solution().updateBoard(board,click);
    for(int i=0; i<res.size(); i++){
        vector<char> aLine = res[i];
        for(int j=0; j<aLine.size(); j++)
            cout<<aLine[j];
        cout<<endl;
    }
    return 0;
}
