#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    	vector<vector<int>> vec;
    	priority_queue<pair<int, int>, vector<pair<int, int>>, tmp> q;
    	for(int i = 0; i < nums1.size(); i++)
    		for(int j = 0; j < nums2.size(); j++){
    			if(q.size() < k)
    				q.push({nums1[i], nums2[j]});
    			else if(q.size() == k && nums1[i] + nums2[j] < q.top().first + q.top().second){
    				q.pop();
    				q.push({nums1[i], nums2[j]});
				}
			}
		while(!q.empty()){//求出来的是结果的逆置 
            vec.push_back({q.top().first, q.top().second});
			q.pop();
		}
		reverse(vec.begin(), vec.end());
		return vec;
    }
    struct tmp{
    	bool operator ()(pair<int,int> &p1, pair<int, int> &p2){
    		return p1.first + p1.second < p2.first + p2.second;
		}
	};
};
int main(){
    int n,m,data,k;
    vector<int> nums1,nums2;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>data;
        nums1.push_back(data);
    }
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>data;
        nums2.push_back(data);
    }
    cin>>k;
    vector<vector<int> > res=Solution().kSmallestPairs(nums1,nums2,k);
    for(int i=0; i<res.size(); i++){
        if (i>0)
            cout<<" ";
        cout<<res[i][0]+res[i][1];
    }
    return 0;
}
