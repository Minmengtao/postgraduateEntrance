#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	bool searchMatrix(vector<vector<int> >& matrix, int target){
		if(matrix.empty() || matrix[0].empty())
			return false;
		if(target < matrix[0][0] || target > matrix[matrix.size()-1][matrix[0].size()-1])
			return false;
		int len = matrix[0].size() - 1;
		for(int i = 0; i < matrix.size(); i++){
			if(matrix[i][0] <= target && matrix[i][len] >= target){
				int low = 0, high = matrix[i].size() - 1;
				while(low <= high){
					int mid = (low + high) / 2;
					if(matrix[i][mid] < target)
						low = mid + 1;
					else if(matrix[i][mid] > target)
						high = mid - 1;
					else
						return true;
				}
			}
		}
		return false;
	}
};
int main(){
    vector<vector<int> > matrix;
    int target;
    int m,n,e;
    cin>>m;
    cin>>n;
    for(int i=0; i<m; i++){
        vector<int> aRow;
        for(int j=0; j<n; j++){
            cin>>e;
            aRow.push_back(e);
        }
        matrix.push_back(aRow);
    }
    cin>>target;
    bool res=Solution().searchMatrix(matrix,target);
    cout<<(res?"true":"false")<<endl;
    return 0;
}
