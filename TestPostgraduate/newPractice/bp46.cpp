#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
int L;
string s;
int main(){
	cin >> L >> s;
    int len = s.length();
    int maxx = 0; // 出现最多的次数
    string ans = "";
    for (int i = L; i < len; i ++ ) // 枚举子串可能的长度
        for (int j = 0; j + i < len; j ++ ){ // 子串的起始下标
            string s1 = s.substr(j, i); // 枚举所有子串
            int cnt = 0;
            for (int k = 0; k + i < len; k ++ ){ // 再一个for循环计算每一个子串的出现次数
                string s2 = s.substr(k, i);
                if (s1 == s2) 
					cnt ++ ;
            }
            if (cnt > maxx){ // 考虑第一优先因素：出现次数 
                maxx = cnt;
                ans = s1;
            }else if (cnt == maxx){ // 如果出现的次数相同，则将长度最长的字符串赋值给ans 
                int l1 = ans.length(),l2 = s1.length();
                if (l2 > l1) 
					ans = s1; // 如果长度也相同，则默认输出第一次输出最早的。  
            }
        }
    cout << ans << endl;
    return 0;
}