#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;  
string str;  
int pos,len,ans;
int dfs(){  
    int num = 0, res = 0;  
    while (pos < len) {  
        if (str[pos] == '('){  
            pos++;  
            num += dfs();  
        }  
        else if (str[pos] == ')'){  
            pos++;  
            break;  
        }  
        else if (str[pos] == '|') {  
            pos++;  
            res = max(num, res);  
            num = 0;  
        }  
        else {  
            pos++;  
            num++;
        }  
    }  
    res = max(num, res);//num为右边的x，res为左边的x
    return res;  
}  
int main(){  
    cin >> str;    
    len = str.length(),pos = 0;  
    ans = dfs();  
    cout << ans << endl;  
    return 0;  
} 