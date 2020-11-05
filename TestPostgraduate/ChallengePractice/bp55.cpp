#include <iostream>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<string,int>Node;
map<string,int> m;
queue<Node> q;
string beginS,endS;
int maxC=50;

int bfs(){
	int sign[3][3]={{0,1,2},{3,4,5},{6,7,8}};
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
		if(maxC<=step)
			return -1;
		if(!strcmp(endS.c_str(),str.c_str()))
			return step;
		for(int i=0;i<len;i++)//找到空杯子的位置
			if(str[i]=='.')
				index=i;
		int ii,jj,iii,jjj;
		for(ii=0;ii<3;ii++)
			for(jj=0;jj<3;jj++)
				if(sign[ii][jj]==index){
					iii=ii;
					jjj=jj;
				}
		for(int j=-1;j<=1;j+=2){//考虑六种情况，分别从右走和左走
			if(iii+j>=0&&iii+j<3){//处理行上的变换
				string tmp=str;
            	swap(tmp[index],tmp[sign[j+iii][jjj]]);
				if(m.find(tmp)==m.end()){//保证新加入的序列在以往从未出现过
					q.push(Node(tmp,step+1));
					m[tmp]=1;
				}
			}
			if(jjj+j>=0&&jjj+j<3){//处理列上的变换
				string tmp=str;
            	swap(tmp[index],tmp[sign[iii][jjj+j]]);
				if(m.find(tmp)==m.end()){//保证新加入的序列在以往从未出现过
					q.push(Node(tmp,step+1));
					m[tmp]=1;
				}
			}
		}
	}
}
int judge(){
	const char *s1=beginS.c_str(),*s2=endS.c_str();
	int i,j,flag=0;
	for(i=0;i<9;i++)
		for(j=0;j<9;j++)
			if(s1[i]==s2[j]){
				flag++;
				break;
			}
	if(flag==9)
		return 1;
	else
		return 0;
}
int main(){
	Node p;
	cin>>beginS;
	cin>>endS;
	if(judge())
		printf("%d\n",bfs());
	else
		printf("-1\n");
	return 0;
}
