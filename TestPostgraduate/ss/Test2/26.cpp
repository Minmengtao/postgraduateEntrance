#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
    	map<int, int> m1, m2;
    	for(auto num: nums)
    		m1[num]++;
    	for(auto num: nums){
    		if(m1[num] == 0)
				continue;
    		if(m2[num-1]){
    			m1[num]--;
    			m2[num-1]--;
    			m2[num]++;
			}else if(m1[num+1] && m1[num+2]){
				m1[num]--;
				m1[num+1]--;
				m1[num+2]--;
				m2[num+2]++;
			}else
				return false;
		}
		return true;
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
	bool b = Solution().isPossible(nums);
	if(b)
		cout << "true";
	else
		cout << "false";
	return 0;
}
