#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;

class Solution{
public:
    string countOfAtoms(string formula){
        int i = 0;
        string ans;
        for (auto &kv : get_map(formula, i)){
            ans += kv.first;
            if (kv.second > 1)
                ans += to_string(kv.second);
        }
        return ans;
    }
    //获结果的map
    map<string, int> get_map(string &s, int &i){
        map<string, int> ans;
        while (i != s.length()){
            if (s[i] == '('){
                map<string, int> tmp = get_map(s, ++i);
                int cnt = get_num(s, i);
                for (auto &kv : tmp)
                    ans[kv.first] += kv.second * cnt;
            }
            else if (s[i] == ')'){
                ++i;
                return ans;
            }
            else{
                string name = get_name(s, i);
                int cnt = get_num(s, i);
                ans[name] += cnt;
            }
        }
        return ans;
    }
    //获取元素名字
    string get_name(string &s, int &i){
        string name;
        while (isalpha(s[i]) && (name.empty() || islower(s[i])))
            name += s[i++];
        return name;
    }
    //获取元素数量
    int get_num(string &s, int &i){
        string num;
        while (isdigit(s[i]))
            num += s[i++];
        return num.empty() ? 1 : stoi(num);
    }
};

int main(){
	string formula;
	cin >> formula;
	cout << Solution().countOfAtoms(formula);
	return 0;
}
