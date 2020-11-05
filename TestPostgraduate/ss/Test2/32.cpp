#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
    	int sum = 0, maxNum = 0, odd = 0;
    	vector<int> sig;
    	for(int i = 0; i < nums.size(); i++){
    		sum += nums[i];
    		sig.push_back(0);
    		if(nums[i] > maxNum)
    			maxNum = nums[i];
    	}
    	if(sum % k != 0 || maxNum > (sum/k))
    		return false;
    	else
    		return dfs(nums, sig, k, sum/k, 0, 0);
    }
    bool dfs(vector<int>& nums, vector<int>& sig, int k, int div, int st, int now){
    	if(k == 0)//ÕÍ»´∑÷≈‰ 
    		return true;
    	if(now == div)
    		return dfs(nums, sig, k-1, div, 0, 0);
    	for(int i = st; i < nums.size(); i++)
    		if(!sig[i] && now+nums[i]<=div){
    			sig[i] = 1;
    			if(dfs(nums, sig, k, div, st+1, now+nums[i]))
                    return true;
    			sig[i] = 0;
			}
		return false;
	}
};

int main(){
    vector<int> nums;
    int n, num, k;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> num;
        nums.push_back(num);
    }
    cin >> k;
    bool res=Solution().canPartitionKSubsets(nums, k);
    cout<<(res?"true":"false")<<endl;
    return 0;
}
