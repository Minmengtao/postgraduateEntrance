#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int>res;
    vector<int> findAnagrams(string s, string p){
        if(s.size()==0||p.size()==0)
            return result;
        vector<int> vs(26,0), vp(26,0);
        for(char c:p)
            vp[c-'a']++;
        for(int i=0;i<s.size();i++){
            if(i>=p.size())//���˵��ʱ���±���ڻ������ڵĳ��ȣ�
                vs[s[i-p.size()]-'a']--;
            vs[s[i]-'a']++;//����ǰ���ַ����뵽���������У�
            if(vs==vp)//ע������ֻ�Ƚ���������ݲ�����Ҫ�Ƚ�˳��
                res.push_back(i-p.size()+1);
        }
        return res;
    }
};
int main(){
	string s, p;
	cin >> s >> p;
	vector<int> res = Solution().findAnagrams(s, p);
	for(int i = 0; i < res.size() - 1; i++)
		cout << res[i] << " ";
	cout << res[res.size() - 1];
	return 0;
}
