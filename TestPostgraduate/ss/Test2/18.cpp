#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> cnt;
        for(int i = 0; i < nums.size(); i++)//记录每个数字出现的频率 
			cnt[nums[i]]++;
		//创建最小堆
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> que; 
        for(auto it : cnt) {//遍历频率cnt
            if(que.size() == k) { //队列满了
                if(it.second > que.top().first) { //每遍历到这删除第一个最小的元素，直接堆排
                    que.pop();//弹出最小频率值
                    que.push(make_pair(it.second, it.first));
                }
            }else 
				que.push(make_pair(it.second, it.first));
        }
        vector<int> vec;
		for(;que.size() > 0; que.pop())
			vec.push_back(que.top().second);
		reverse(vec.begin(), vec.end());
        return vec;
    }
};
int main(){
    int n,data,k;
    vector<int> nums;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>data;
        nums.push_back(data);
    }
    cin>>k;
    vector<int> res=Solution().topKFrequent(nums,k);
    for(int i=0; i<res.size(); i++){
        if (i>0)
            cout<<" ";
        cout<<res[i];
    }
    return 0;
}
