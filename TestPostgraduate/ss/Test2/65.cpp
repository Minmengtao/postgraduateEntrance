#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    	unordered_map<int, int> m;
    	int cnt = 0, sum = 0;
		m[0] = 1;
    	for(int i = 0; i < nums.size(); i++){
    		sum += nums[i];
    		m[sum]++;
    		if(m[sum-k])//ÅÐ¶Ïsum - (sum-k) == k
    			cnt += m[sum-k];
		}
		return cnt;
    }
};
int main(){
	vector<int> nums;
	int n, data, k;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> data;
		nums.push_back(data);
	}
	cin >> k;
	cout << Solution().subarraySum(nums, k) << endl;
	return 0;
}
