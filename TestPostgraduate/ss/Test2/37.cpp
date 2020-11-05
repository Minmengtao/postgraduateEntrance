#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
	vector<string> v;
	string str;
    vector<string> restoreIpAddresses(string s) {
    	this->str = s;
        dfs(0, "", 0);
        return v;
    }
    void dfs(int x, string s, int cnt){
    	if(x == str.length() || cnt == 4){
    		if(x == str.length() && cnt == 4)
    			v.push_back(s.substr(0, s.length() - 1));
    		return;
    	}
		int sum = 0, flag = 1;//����flag��־λ��1��ʾ����С������0��δʹ��
    	for(int i = x; i < str.length() && i < x+3; i++){
    		sum = sum * 10 + str[i] - '0';
    		if(sum < 256 && x >= 0 && flag){
				if(sum == 0)//��һ��ʹ��0����������ʹ��0��Ϊǰ׺
					flag = 0;
    			dfs(i+1, s + to_string(sum) + '.' , cnt+1);
			}else
				break;
		}
	}
};
int main(){
	string s;
	cin >> s;
	vector<string> vec = Solution().restoreIpAddresses(s);
	for(int i = 0; i < vec.size(); i++)
		cout << vec[i] << endl;
	cout << vec.size() << endl;
	return 0;
} 
