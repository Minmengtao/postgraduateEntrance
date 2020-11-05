#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {//̰���㷨����һ�о�����Ϊ1��֮�����б任
    	int x = A.size(), y = A[0].size();
		for(int i = 0; i < x; i++)//����һ��ȫ��Ϊһ 
			if(A[i][0] != 1)
				change(A[i]);
		for(int i=1; i<y; i++){
			int cnt1 = 0, cnt0 = 0;
			for(int j = 0; j < x; j++){
				if(A[j][i])
					cnt1++;
				else
					cnt0++;
			}
			if(cnt1 < cnt0){
				for(int j = 0; j < x; j++)
					A[j][i] = A[j][i] ? 0 : 1;
			}
    	}
    	return getScore(A);
    }
    int getScore(vector<vector<int>>& A){
    	int score = 0;
    	for(int i=0; i<A.size(); i++){
    		int rowScore = 0;
        	for(int j=0; j<A[i].size(); j++)
				rowScore = A[i][j] + rowScore * 2;
        	score += rowScore;
    	}
    	return score;
	}
	void change(vector<int> &A){
		for(int i = 0; i < A.size(); i++)
			A[i] = A[i]?0:1;
	}
};
int main(){
	vector<vector<int>> A;
	int m, n, data;
	cin >> m >> n;
	for(int i=0; i<m; i++){
        vector<int> row;
        for(int j=0; j<n; j++){
            cin>>data;
            row.push_back(data);
        }
        A.push_back(row);
    }
    cout >> Solution().matrixScore(A);
    return 0;
}
