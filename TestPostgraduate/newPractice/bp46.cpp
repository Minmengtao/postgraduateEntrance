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
    int maxx = 0; // �������Ĵ���
    string ans = "";
    for (int i = L; i < len; i ++ ) // ö���Ӵ����ܵĳ���
        for (int j = 0; j + i < len; j ++ ){ // �Ӵ�����ʼ�±�
            string s1 = s.substr(j, i); // ö�������Ӵ�
            int cnt = 0;
            for (int k = 0; k + i < len; k ++ ){ // ��һ��forѭ������ÿһ���Ӵ��ĳ��ִ���
                string s2 = s.substr(k, i);
                if (s1 == s2) 
					cnt ++ ;
            }
            if (cnt > maxx){ // ���ǵ�һ�������أ����ִ��� 
                maxx = cnt;
                ans = s1;
            }else if (cnt == maxx){ // ������ֵĴ�����ͬ���򽫳�������ַ�����ֵ��ans 
                int l1 = ans.length(),l2 = s1.length();
                if (l2 > l1) 
					ans = s1; // �������Ҳ��ͬ����Ĭ�������һ���������ġ�  
            }
        }
    cout << ans << endl;
    return 0;
}