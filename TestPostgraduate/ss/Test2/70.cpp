#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution{
public:
	vector<int> findSubstring(string s, vector<string>& words){
		if(s.empty() || words.empty())
			return {};
		unordered_map<string, int> need;
		for(auto word: words)
			need[word]++;
		vector<int> res;
		int m = words.size(), n = words[0].size();
        if(s.size() < m * n)
            return {};
		for(int i = 0; i <= s.size() - m * n; i++){
			unordered_map<string, int> delta;
			int j;
			for(j = 0; j < m; j++){
				string str = s.substr(i + j * n, n);
				if(!need.count(str))
					break;
				delta[str]++;
				if(delta[str] > need[str])
					break;
			}
			if(j == m)
				res.push_back(i);
		}
		return res;
	}
};
int main(){
    string s,str;
    vector<string> words;
    int n;
    cin>>s;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>str;
        words.push_back(str);
    }
    vector<int> res=Solution().findSubstring(s, words);
    if (res.size()> 0)
        for(int i=0; i<res.size(); i++){
            if (i> 0)
                cout<<" ";
            cout<<res[i];
        }
    else
        cout<<-1;
    return 0;
}
