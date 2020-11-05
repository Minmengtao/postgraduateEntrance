#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
	map<vector<int>, int> need;
	vector<vector<int>> res;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
    	for(int i = 0; i < nums.size(); i++){
    		vector<int> num;
    		num.push_back(nums[i]);
    		dfs(nums, num, i);
		}
		return res;
    }
    void dfs(vector<int> nums, vector<int>& num, int x){
    	if(num.size() >= 2 && !need.count(num)){
    		need[num] = x;
    		res.push_back(num);
		}
		for(int i = x+1; i < nums.size(); i++)
			if(num[num.size()-1] <= nums[i]){
				num.push_back(nums[i]);
				dfs(nums, num, i);
				num.pop_back();
			}
	}
};
int main(){
	vector<int> nums;
	int n, data;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> data;
		nums.push_back(data);
	}
	vector<vector<int>> res = Solution().findSubsequences(nums);
	cout << res.size();
	return 0;
} 
