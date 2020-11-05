#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
	bool res = false;
	unordered_map<string, vector<char>> need;
	bool pyramidTransition(string bottom, vector<string> allowed){
		for(int i = 0; i < allowed.size(); i++)
			need[allowed[i].substr(0, 2)].push_back(allowed[i][2]);
		dfs(bottom, "", 0);
        return res;
	}
	void dfs(string bottom, string cur, int x){
		if(res)
			return;
		if(bottom.size() == 1){
			res = true;
			return;
		}
		if(x == bottom.size() - 1){
			dfs(cur, "", 0);
			return;
		}
		string str = "";
        str.push_back(bottom[x]);
        str.push_back(bottom[x+1]);
		if(need.count(str))
			for(int j = 0; j < need[str].size(); j++)
				dfs(bottom, cur + need[str][j], x+1);
	}
};
int main(){
    string bottom,rule;
    vector<string> allowed;
    cin>>bottom;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>rule;
        allowed.push_back(rule);
    }
    bool res=Solution().pyramidTransition(bottom, allowed);
    cout<<(res?"true":"false")<<endl;
    return 0;
}
