#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution{
public:
	bool validTicTacToe(vector<string> board){
		map<char, int> m;
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 3; j++)
				m[board[i][j]]++;
		if(m['O'] > m['X'] || m['X'] > m['O']+1)//X�������ȷ���,����X��OҪ������ 
			return false;
		else if(m['X']<3)//��������һ����3�������п���Ӯ�����
			return true;
		else if(isWin(board, 'X') && m['X']==m['O'])//XӮ�˵�O������ 
			return false; 
		else if(!isWin(board, 'X') && isWin(board, 'O') && m['X']>m['O'])//XûӮOӮ�˵�X������ 
			return false;
		else
			return true; 
	}
	bool isWin(vector<string> board, char ch){//�ж������Ƿ�ΪӮ��״̬
		for(int i = 0; i < 3; i++){
			if(board[i][0]==ch && board[i][1]==ch && board[i][2]==ch)//
				return true;
			if(board[0][i]==ch && board[1][i]==ch && board[2][i]==ch)//
				return true;
		}
		if((board[0][0]==ch && board[1][1]==ch && board[2][2]==ch)||
			(board[0][2]==ch && board[1][1]==ch && board[2][0]==ch))//�ж�б�Խ���Ӯ����� 
			return true;
		return false;
	}
}; 
int main(){
    vector<string> board;
    string aRow;
    for(int i=0; i<3; i++){
        getline(cin,aRow);
        board.push_back(aRow);
    }
    bool res=Solution().validTicTacToe(board);
    cout<<(res?"true":"false")<<endl;
    return 0;
}
