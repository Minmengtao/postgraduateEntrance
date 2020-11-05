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
        for(int i = 0; i < nums.size(); i++)//��¼ÿ�����ֳ��ֵ�Ƶ�� 
			cnt[nums[i]]++;
		//������С��
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> que; 
        for(auto it : cnt) {//����Ƶ��cnt
            if(que.size() == k) { //��������
                if(it.second > que.top().first) { //ÿ��������ɾ����һ����С��Ԫ�أ�ֱ�Ӷ���
                    que.pop();//������СƵ��ֵ
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
