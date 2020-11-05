#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {//½«0¿´×ö-1
        int sum = 0, maxCount = 0;
        unordered_map<int, int> need;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i])
                sum += nums[i];
            else
                sum--;
            if(!sum)
                maxCount = i + 1;
            else if(!need.count(sum))
                need[sum] = i;
            else
                maxCount = max(maxCount, i - need[sum]);
        }
        return maxCount;
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
	cout << Solution().findMaxLength(nums);
	return 0;
} 
