#include <iostream>
#include <stack>
using namespace std;

string decodeString(string s) {//数字放在数字栈中，字符串放在字符串栈中 
	stack<string> str;//存放字符串 
	stack<int> num;//存放重复次数 
	int x = 0;
	string sn = "";//总的字符串 
	for(int i = 0; i < s.length(); i++){
		if(s[i] >= '0' && s[i] <= '9')//数字放在数字栈中 
			x = x*10 + s[i]-'0';//如果数字大于等于10，则需要循环计数 
		else if(s[i] == '['){
			str.push(sn);
			num.push(x);
			sn = "";
			x = 0;
		}else if(s[i] == ']'){//出现左括号或右括号开始运算栈 
			int y = num.top();
			num.pop();
			string newString = "";
			for(int j = 0; j < y; j++)
				newString += sn;
			sn = str.top() + newString;
			str.pop();
		}else//存放字符串到字符串栈中 
			sn += s[i];
	}
	return sn; 
}
int main(){
	string s;
	cin >> s;
	cout << decodeString(s);
	return 0;
} 
