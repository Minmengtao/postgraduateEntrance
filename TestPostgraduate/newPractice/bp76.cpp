#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

map<string,char> name;
int main(){
	int n,m;
	string num,na;
	char sex;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>na>>num>>sex;
		name[na]=sex;
		name[num]=sex;
	}
	cin>>m;
	for(int j=0;j<m;j++){
		string s1,s2;
		cin>>s1>>s2;
		if((name[s1]=='F'&&name[s2]=='M')||(name[s1]=='M'&&name[s2]=='F'))
			cout<<"Y"<<endl;
		else
			cout<<"N"<<endl;
	}
	return 0;
}
