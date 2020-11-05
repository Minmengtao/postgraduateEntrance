#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
 //给定两个数组，长度分别为m,n,组合出长度为m+n的最大
    vector<int> merge(vector<int>& nums1, vector<int>& nums2,int k) {
        vector<int> res(nums1.size()+nums2.size());
        for (int i = 0, j = 0, r = 0; r < k; ++r)
            res[r] = compare(nums1, i, nums2, j) ? nums1[i++] : nums2[j++];
        return res;
    }

    bool compare(vector<int>& nums1, int i,vector<int>& nums2,int j) {
        while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
            i++;
            j++;
        }
        return j == nums2.size() || (i < nums1.size() && nums1[i] > nums2[j]);
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> res(k); 
        for (int i = max(0, k - m); i <= k && i <= n; ++i) {
            vector<int> temp1 = maxNumber(nums1, i);
            vector<int> temp2 = maxNumber(nums2, k-i);
            vector<int> candidate = merge(temp1,temp2, k);
            if (compare(candidate, 0, res, 0)) 
                res = candidate;
        }
        return res;

    }
    //给定长度为n的数组，选取长度为i的最大
    vector<int> maxNumber(vector<int>& nums1,int k){
        int n = nums1.size();
        vector<int> ans(k);
        for (int i = 0, j = 0; i < n; ++i) {
            while (n - i + j > k && j > 0 && ans[j - 1] < nums1[i]) 
                j--;
            if (j < k) 
                ans[j++] = nums1[i];
        }
        return ans;
    }


};
int main(){
    int m,n,k,data;
    vector<int> nums1,nums2;
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>data;
        nums1.push_back(data);
    }
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>data;
        nums2.push_back(data);
    }
    cin>>k;
    vector<int> res=Solution().maxNumber(nums1,nums2,k);
    for(int i=0; i<res.size(); i++)
        cout<<res[i];
    return 0;
}
