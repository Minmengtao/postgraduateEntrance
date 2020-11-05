#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int main(){
	stack<char> st;
	char s[1005];
	cin >> s;
	int cnt = 0;
	for(int i = 0; i < strlen(s); i++){
		if(s[i] == '(')
			st.push(s[i]);
		else{
			if(st.empty())//栈为空，取不出左括号 
				cnt++;
			else
				st.pop(); 
		}
	}
	cnt += st.size();
	cout << cnt << endl;
	return 0;
}
