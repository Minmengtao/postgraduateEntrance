#include <iostream>
#include <stack>
using namespace std;

string decodeString(string s) {//���ַ�������ջ�У��ַ��������ַ���ջ�� 
	stack<string> str;//����ַ��� 
	stack<int> num;//����ظ����� 
	int x = 0;
	string sn = "";//�ܵ��ַ��� 
	for(int i = 0; i < s.length(); i++){
		if(s[i] >= '0' && s[i] <= '9')//���ַ�������ջ�� 
			x = x*10 + s[i]-'0';//������ִ��ڵ���10������Ҫѭ������ 
		else if(s[i] == '['){
			str.push(sn);
			num.push(x);
			sn = "";
			x = 0;
		}else if(s[i] == ']'){//���������Ż������ſ�ʼ����ջ 
			int y = num.top();
			num.pop();
			string newString = "";
			for(int j = 0; j < y; j++)
				newString += sn;
			sn = str.top() + newString;
			str.pop();
		}else//����ַ������ַ���ջ�� 
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
