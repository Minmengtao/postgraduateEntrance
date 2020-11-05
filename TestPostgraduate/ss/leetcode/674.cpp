#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() < 2)
            return nums.size();
        int head = 0, tail = 1, maxLen = 0;
        while(tail < nums.size()){
            if(nums[tail] <= nums[tail-1]){//检测不到靠近nums.size()-1位置的子串
                maxLen = max(maxLen, tail - head);
                head = tail;
            }
            tail++;
        }
        return max(tail - head, maxLen);//重新判定子串大小
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
	cout << Solution().findLengthOfLCIS(nums);
	return 0;
}
