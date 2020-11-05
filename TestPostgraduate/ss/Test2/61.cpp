#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
	static bool cmp(pair<char, int>& a, pair<char, int>& b){
		if(a.second > b.second || (a.first<b.first && a.second== b.second))
			return true;
		else
			return false;
	}
    string frequencySort(string s) {
		unordered_map<char, int> m;
		for(int i = 0; i < s.length(); i++)
			m[s[i]]++;
		vector<pair<char, int>> vec(m.begin(), m.end());
		sort(vec.begin(), vec.end(), cmp);
		string res = "";
		for(int i = 0; i < vec.size(); i++){
			while(vec[i].second){
				res += vec[i].first;
				vec[i].second--;
			}
		}
		return res;
    }
};
int main(){
	string s;
	cin >> s;
	cout << Solution().frequencySort(s) << endl;
	return 0;
}
