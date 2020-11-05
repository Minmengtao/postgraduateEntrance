#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution{
public:
	int findLHS(vector<int> &nums){
		map<int, int> m;
		int cnt = 0;
		for(int i = 0; i < nums.size(); i++){
			m[nums[i]]++;
			if(m.count(nums[i] - 1))
				cnt = max(cnt, m[nums[i]] + m[nums[i] - 1]);
			if(m.count(nums[i] + 1))
				cnt = max(cnt, m[nums[i]] + m[nums[i] + 1]);
		}
		return cnt;
	}
};
int main(){
	int n, data;
	vector<int> nums;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> data;
		nums.push_back(data);
	}
	cout << Solution().findLHS(nums) << endl;
	return 0;
}
