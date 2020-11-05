#include <iostream>
#include <vector>
#include <map>
#include <algorithm> 
using namespace std;
class Solution{
public:
	vector<int> can, vec;
	vector<vector<int>> v;
	int tar;
	map<vector<int>, int> m;
	vector<vector<int>> combinationSum2(vector<int> &candidates, int target){
		sort(candidates.begin(), candidates.end());
		this->can = candidates;
		this->tar = target;
		dfs(0, 0);
		return v;
	}
	void dfs(int sum, int x){
		if(sum == tar || x==can.size()){
			if(sum==tar)
				v.push_back(vec);
			return;
		}
		for(int i = x; i < can.size(); i++){
			if(can[i] > tar)//剪枝,大于目标值的剪去
				break;
			if(i>x&&can[i]==can[i-1])//剪枝，有重复路径剪去
				continue;
			if(sum + can[i] <= tar){
				vec.push_back(can[i]);
				dfs(sum + can[i], i+1);
				vec.pop_back();
			}
		}
	}
};
int main(){
    int n,data,target;
    vector<int> candidates;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>data;
        candidates.push_back(data);
    }
    cin>>target;
    vector<vector<int>> res=Solution().combinationSum2(candidates,target);
    cout<<res.size()<<endl;
    return 0;
}
