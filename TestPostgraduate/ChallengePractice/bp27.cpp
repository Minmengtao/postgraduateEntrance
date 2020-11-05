#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int N = 300;
int in[N];
vector <char> v[N];
vector <char> ans;
bool st[N];
int main(){
	char c[4];
	while(~scanf("%s",c+1)){
		char x = c[1];
		char y = c[3];
		v[x].push_back(y);
		in[y]++;
		st[x]=st[y]=1;
	}
	queue<char> q;
	int total = 0;
	for(int i='A'; i<='Z'; i++)
	{
		if(in[i] == 0 && st[i] == 1)
		{
			q.push(i);
		}
		if(st[i] == 1) total++;
	}
	while(!q.empty()){
		char tem = q.front();
		total--;
		ans.push_back(tem);
		q.pop();
		for(int i=0; i<v[tem].size(); i++){
			in[v[tem][i]]--;
			if(in[v[tem][i]] == 0) q.push(v[tem][i]);
		}
	}
 	if(total == 0)
		for(int i=0; i<ans.size(); i++)
			cout<<ans[i];
	else 
		puts("No Answer!");
	return 0;
}