#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

int n,m;
map<string,int> ma;
int main(){
	cin>>n;
	string na;
	for(int i=0;i<n;i++){
		cin>>na;
		ma[na]=0;
	}
	cin>>m;
	while(m--){
		int sc[105];
		for(int j=0;j<n;j++){
			cin>>sc[j]>>na;
			ma[na]+=sc[j];
			if(m==0)
				sc[j]=ma[na];
		}
		sort(sc,sc+n);
		for(int k=n-1;k>=0;k--)
			if(ma["DaDa"]==sc[k]){
				printf("%d\n",n-k);
				break;
			}
	}
	return 0;
}