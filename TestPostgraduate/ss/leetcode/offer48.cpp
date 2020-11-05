#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		if(s.length() < 2)
			return s.length();
		int head = 0, tail = 0, maxLen = 0;
		while(tail < s.length()){
			for(int j = head; j < tail; j++)
				if(s[j] == s[tail]){
					head = j + 1;
					break;//强制剪枝，去掉不用的部分
				}
			maxLen = max(maxLen, tail - head + 1);
			tail ++;
		}
		return maxLen;
    }
};
int main(){
	string s;
	cin >> s;
	cout << Solution().lengthOfLongestSubstring(s);
	return 0;
}
