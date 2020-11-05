#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	bool isValidSudoku(vector<vector<char>>& board){
		int row[9][10] = {0}, col[9][10] = {0}, box[9][10] = {0};
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				if(board[i][j] == '.')
					continue;
				int cur = board[i][j] - '0', index = (i/3)*3 + j/3;
				if(row[i][cur] || col[j][cur] || box[index][cur])
					return false;
				row[i][cur] = 1;
				col[j][cur] = 1;
				box[index][cur] = 1;
			}
		}
		return true;
	}
};
int main(){
    vector<vector<char> > board;
    char ch;
    for(int i=0; i<9; i++){
        vector<char> aLine;
        for(int j=0; j<9; j++){
            cin>>ch;
            aLine.push_back(ch);
        }
        board.push_back(aLine);
    }
    bool res=Solution().isValidSudoku(board);
    cout<<(res?"true":"false")<<endl;
    return 0;
}
