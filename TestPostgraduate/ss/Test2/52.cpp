#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
    	if(nums.empty())
    		return false;
        int low = 0, high = nums.size() - 1, mid;
        while(low <= high){
        	mid = (low + high) / 2;
        	if(nums[mid] == target)
        		return true;
        	if(nums[mid] == nums[low])
        		low++;
        	else if(nums[mid] > nums[low]){//qian ban bu fen you xu
        		if(nums[mid] > target && nums[low] <= target)
        			high = mid - 1;
        		else
        			low = mid + 1;
			}else{//hou ban bu fen you xu
				if(nums[mid] < target && nums[high] >= target)
					low = mid + 1;
				else
					high = mid - 1;
			}
		}
		return false;
    }
};
int main(){
	int n, data, target;
	cin >> n;
	vector<int> nums;
	for(int i = 0; i < n; i++){
		cin >> data;
		nums.push_back(data);
	}
	cin >> target;
	bool res=Solution().search(nums,target);
    cout<<(res?"true":"false")<<endl;
	return  0;
} 
