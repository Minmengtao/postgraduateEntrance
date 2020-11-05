#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Solution{
public:
	string reverseParentheses(string s){
		stack<string> st;
		string ch;
		for(int i = 0; i < s.length(); i++){
			if(s[i] == '('){
				st.push(ch);
				ch = "";
			}else if(s[i] == ')'){
				reverse(ch.begin(), ch.end());
				ch = st.top() + ch;
				st.pop();
			}else
				ch += s[i];
		}
		return ch;
	}
};
int main(){
	string s;
	cin >> s;
	cout << Solution().reverseParentheses(s);
	return 0;
}
