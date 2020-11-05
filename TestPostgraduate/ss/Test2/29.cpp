#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPatches(vector<long>& nums, int n) {
    	long cnt = 0, i = 0;
        long long j = 1;
    	while(j <= n){
    		if(i < nums.size() && nums[i] <= j)
    			j += nums[i++];
    		else{
    			j += j;
    			cnt++;
			}
		}
		return cnt;
    }
};
int main(){
	vector<long> nums;
	long m, n, data;
	cin >> m;
	for(long i = 0; i < m; i++){
		cin >> data;
		nums.push_back(data);
	} 
	cin >> n;
	cout << Solution().minPatches(nums, n);
	return 0;
}
