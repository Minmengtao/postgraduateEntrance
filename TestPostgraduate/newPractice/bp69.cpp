#include<cstdio>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

string s[100005];
int n;
bool cmp(string a,string b);
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		s[i].resize(18);
        //scanf("%s",&s[i][0]);
		cin>>s[i];
	}
	sort(s,s+n,cmp);
	for(int j=0;j<n;j++)
		printf("%s\n",s[j].c_str());
	return 0;
}
bool cmp(string a,string b){
    string s1 = a.substr(6,13);
    string s2 = b.substr(6,13);
    if(s1 != s2)
        return s1>s2;
    else
        return a>b;
}