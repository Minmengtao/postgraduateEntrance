#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
	string str;
	vector<vector<string>> v;
	vector<string> vec;
    vector<vector<string>> partition(string s) {
    	this->str = s;
    	dfs(0, "");
    	return v;
    }
    void dfs(int x, string s){
    	if(x == str.length()){
    		v.push_back(vec);
    		return;
		}
    	for(int i = x; i < str.length(); i++){
    		s += str[i];
    		if(judge(s)){//判断字符串是不是回文 
    			vec.push_back(s);
    			dfs(i + 1, "");
    			vec.pop_back();
    		}
		}
	}
	int judge(string s){
		for(int i = 0; i <= (s.length()-1)/2; i++)
			if(s[i] != s[s.length()-1 -i])
				return 0;
		return 1;
	}
};
int main(){
	string s;
	cin >> s;
	vector<vector<string>> vec = Solution().partition(s);
	for(int i = 0; i < vec.size(); i++){
		for(int j = 0; j < vec[i].size(); i++)
			cout << vec[i][j] << " ";
		cout << endl;
	}
	cout << vec.size() << endl;
	return 0;
} 
