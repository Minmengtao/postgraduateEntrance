#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int m[256] = {0}, used[256] = {0};
        string res = "";
        for (auto a : s) 
			++m[a];
        for (auto a : s) {
            --m[a];
            if(used[a]) 
				continue;
            while(a < res.back() && m[res.back()]) {
                used[res.back()] = 0;
                res.pop_back();
            }
            res += a;
            used[a] = 1;
        }
        return res;
    }
};
int main(){
	string s;
	cin >> s;
	cout << Solution().removeDuplicateLetters(s);
	return 0;
}
