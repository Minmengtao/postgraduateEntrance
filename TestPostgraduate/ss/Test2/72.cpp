#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

class Solution{
public:
	unordered_map<string, priority_queue<string,vector<string>,greater<string>>> need;
	vector<string> res;
	vector<string> findItinerary(vector<vector<string>>& tickets){
		for(int i = 0; i < tickets.size(); i++)
			need[tickets[i][0]].push(tickets[i][1]);
		dfs("JFK");
		reverse(res.begin(), res.end());
		return res;
	}
	void dfs(string str){
		while(need.count(str) && need[str].size() > 0){
			string s = need[str].top();
			need[str].pop();
			dfs(s);
		}
		res.push_back(str);
	}
}; 
int main(){
    vector<vector<string>> tickets;
    int m;
    cin>>m;
    string a1,a2;
    for(int i=0; i<m; i++){
        vector<string> aTicket;
        cin>>a1>>a2;
        aTicket.push_back(a1);
        aTicket.push_back(a2);
        tickets.push_back(aTicket);
    }
    vector<string> res=Solution().findItinerary(tickets);
    for(int i=0; i<res.size(); i++){
        if (i>0)
            cout<<" ";
        cout<<res[i];
    }
    return 0;
}
