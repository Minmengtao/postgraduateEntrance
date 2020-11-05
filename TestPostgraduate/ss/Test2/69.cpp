#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	static bool cmp(pair<string,int>& a, pair<string,int>& b){
		if(a.second > b.second || (a.second==b.second && a.first<b.first))
			return true;
		else
			return false;
	}
    vector<string> topKFrequent(vector<string>& words, int k) {
		unordered_map<string, int> m;
		for(auto str: words)
			m[str]++;
		vector<pair<string,int>> vec(m.begin(), m.end());
    	sort(vec.begin(), vec.end(), cmp);
		vector<string> v(k);
		int ck = 0;
		for(int i = 0; i < vec.size() && ck < k; i++){
			v[ck++] = vec[i].first;
		}
    	return v;
    }
};
int main(){
	string s;
	int n, k;
	vector<string> words;
	cin >> n;
	while(n--){
		cin >> s;
		words.push_back(s);
	}
	cin >> k;
	vector<string> res = Solution().topKFrequent(words, k);
	for(int i = 0; i < res.size(); i++){
		if(i < res.size() - 1)
			cout << res[i] << " ";
		else
			cout << res[i] << endl;
	}
	return 0;
}
