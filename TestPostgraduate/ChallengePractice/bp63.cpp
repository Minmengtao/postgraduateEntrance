/*#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<string,int>Node;
map<string,int> m;
queue<Node> q;
string beginS,endS;

char exchange(char s){
	if(s=='*')
		return 'o';
	else if(s=='o')
		return '*';
}
int bfs(){
	while(!q.empty())
		q.pop();
	q.push(Node(beginS,0));
	m.clear();
	m[beginS]=1;
	int len=beginS.size();
	while(!q.empty()){
		Node p=q.front();
		q.pop();
		string str=p.first;
		int step=p.second,index;
		if(!strcmp(endS.c_str(),str.c_str()))
			return step;
		for(int j=0;j<len-1;j++){//��������������Ӳ�ҷ�ת
			string tmp=str;
			tmp[j]=exchange(tmp[j]);//��������Ӳ�ұ任
            tmp[j+1]=exchange(tmp[j+1]);
			if(m.find(tmp)==m.end()){//��֤�¼����������������δ���ֹ�
				q.push(Node(tmp,step+1));
				m[tmp]=1;
			}
		}
	}
}
int main(){
	Node p;
	cin>>beginS;
	cin>>endS;
	int len=beginS.size(),counto[2];
	counto[0]=0;counto[1]=0;
	for(int i=0;i<len;i++){
		if(beginS[i]=='o')
			counto[0]++;
		if(endS[i]=='o')
			counto[0]++;
	}
	if((counto[0]-counto[1])%2==0||(counto[1]-counto[0])%2==0)
		printf("%d\n",bfs());
	else
		printf("-1\n");
	return 0;
}
*/
//�ô����ʱ�临�Ӷ�ΪO(n)
#include<iostream> 
#include<string>
using namespace std;
int main(){
	string str1,str2;
	int st=-1,ed,ans=0;
	int flag=0;
	cin>>str1;
	cin>>str2;
	for(int i=0;i<str1.size();i++){
		if(str1[i]!=str2[i])  {
			if(st==-1){
				st=i;
			}else{
			    ans+=(i-st);
			    st=-1;
		    }
		} 
	}
	cout<<ans<<endl;
    return 0;
}