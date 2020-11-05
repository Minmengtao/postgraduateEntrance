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
		int low_r = 0, high_r = matrix.size() - 1, mid_r, len = matrix[0].size()-1;
		while(low_r <= high_r){
			mid_r = (low_r + high_r) / 2;
			if(matrix[mid_r][len] < target)//尾部小于target则搜索下半部分 
				low_r = mid_r + 1;
			else if(matrix[mid_r][0] > target)//受不大于target则搜索上半部分 
				high_r = mid_r - 1;
			else
				break;
		}
		int low = 0, high = matrix[mid_r].size() - 1;
		while(low <= high){
			int mid = (low + high) / 2;
			if(matrix[mid_r][mid] < target)
				low = mid + 1;
			else if(matrix[mid_r][mid] > target)
				high = mid - 1;
			else
				return true;
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
