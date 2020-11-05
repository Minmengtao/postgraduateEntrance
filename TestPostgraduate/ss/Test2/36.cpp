#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int ov[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
class Solution {
public:
	int cnt;//操作向量 
	string w;
	map<vector<int>, int> m; 
    bool exist(vector<vector<char>>& board, string word) {
		this->w = word;
		cnt = 0;
		
        for(int i = 0 ;i < board.size(); i++){
        	for(int j = 0; j < board[i].size(); j++)
        		if(word[0] == board[i][j]){
					vector<int> v;
					v.push_back(i);
					v.push_back(j);
					m[v] = 1;
        			dfs(i, j, 1, board);
					m.erase(v);
					if(cnt)
						return true;
				}
		}
		return false;
    }
    void dfs(int x, int y, int k, vector<vector<char>>& board){
    	if(k == w.length()){
    		cnt++;
    		return;
		}
    	for(int i = 0 ; i < 4; i++){ 
			int xx = x+ov[i][0], yy = y+ov[i][1];
    		if(xx<0||xx>=board.size()||yy<0||yy>=board[xx].size())
				continue;
			vector<int> v;
			v.push_back(xx);
			v.push_back(yy);
    		if(board[xx][yy] == w[k] && !m.count(v)){//不走回头路并且走的该条路为正好符合字符串
				m[v] = 1;
    			dfs(x+ov[i][0], y+ov[i][1], k+1, board);
				m.erase(v);
			}
    	} 
	}
};
int main(){
    vector<vector<char> > board;
    string word;
    int m,n;
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
    cin>>word;
    bool res=Solution().exist(board,word);
    cout<<(res?"true":"false")<<endl;
    return 0;
}

