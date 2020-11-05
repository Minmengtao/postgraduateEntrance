#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<string,int>Node;
map<string,int> m;
queue<Node> q;
string beginS,endS;

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
		for(int i=0;i<len;i++)//找到空杯子的位置
			if(str[i]=='*')
				index=i;
		for(int j=-3;j<=3;j++){//考虑六种情况，分别从右走和左走
			if(j==0||index+j<0||index+j>=len)//不要让下标超出数组边界
				continue;
			else{
				string tmp=str;
            	swap(tmp[index],tmp[index+j]);
				if(m.find(tmp)==m.end()){//保证新加入的序列在以往从未出现过
					q.push(Node(tmp,step+1));
					m[tmp]=1;
				}
			}
		}
	}
}
int main(){
	Node p;
	cin>>beginS;
	cin>>endS;
	printf("%d\n",bfs());
	return 0;
}
