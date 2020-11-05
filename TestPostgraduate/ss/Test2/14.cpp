#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stringstream is(path);
        string str = "", temp = "";
        vector<string> vec;
        while(getline(is, temp, '/')) {
        	if(temp == "" || temp == ".")
        		continue;
        	else if(temp == ".." && !vec.empty())//���¸�Ŀ¼�����ջ�ǿգ�ɾ��ջ��Ԫ�� 
        		vec.pop_back();
        	else if(temp != "..")//���Ϊ��ĸ·������ջ 
        		vec.push_back(temp);
        }
        for(int i = 0; i < vec.size(); i++)
        	str += "/" + vec[i];
        if(vec.empty())
			str = "/";
        return str;
    }
};
int main(){
    string str;
    getline(cin,str);
    string path=Solution().simplifyPath(str);
    cout<<path<<endl;
    return 0;
}
