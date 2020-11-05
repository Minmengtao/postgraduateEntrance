#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;
typedef struct{
	char num[15];
}Num;
int n,minN=10000;
void swap(char *p,char *q){
	int temp=*p;
	*p=*q;
	*q=temp;
}
void bfs(Num nu,int count){
	queue<Num> q;
	__int64 deep=0;
	q.push(nu);
	char *sign="2012";
	while(!q.empty()){
		nu=q.front();
		q.pop();
		deep++;
		if(strstr(nu.num,sign)||count>minN){
			if(minN>count)
				minN=count;
			return;
		}
		if((int)pow(n-1,count+1)==deep*(n-2)+1)
			count++;
		for(int i=0;i<n-1;i++){//考虑前n-1个数，最后一个数不需要考虑
			swap(&nu.num[i],&nu.num[i+1]);
			q.push(nu);
			swap(&nu.num[i],&nu.num[i+1]);
		}
	}
}
int judge(Num nu){
	int count0=0,count1=0,count2=0;
	for(int i=0;i<n;i++){
		if(nu.num[i]=='0')
			count0++;
		if(nu.num[i]=='1')
			count1++;
		if(nu.num[i]=='2')
			count2++;
	}
	if(count0>=1&&count1>=1&&count2>=2)
		return 0;
	return 1;
}
int main(){
	scanf("%d",&n);
	Num nu;
	scanf("%s",nu.num);
	if(judge(nu))
		printf("-1\n");
	else{
		bfs(nu,0);
		printf("%d\n",minN);
	}
	return 0;
}
/*
#include <iostream>
#include <string>
#include <map>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int count[3];
typedef pair<string,int>Node;
map<string,int>mymap;

string s;
queue<Node>q;

bool judge(string s)
{
    int len=s.size();
    for(int i=0;i<=len-4;i++)
    {
        if(s[i]=='2'&&s[i+1]=='0'&&s[i+2]=='1'&&s[i+3]=='2')
        return true;
    }
    return false;
}

int main()
{
    int n;
    while(scanf("%d",&n)!=-1)
    {
        cin>>s;
        int len=s.size();
        memset(count,0,sizeof(count));
        for(int i=0;i<len;i++)
        count[s[i]-'0']++;
        if(count[0]<1||count[1]<1||count[2]<1)
        {
            cout<<"-1"<<endl;
            continue;
        }
        while(!q.empty())
        {
            q.pop();
        }
        mymap.clear();
        mymap[s]=1;
        q.push(Node(s,0));
        int ans=-1;
        while(!q.empty())
        {
            Node p=q.front(); q.pop();
            string t=p.first;
            int step=p.second;
            if(judge(t))
            {
                ans=step;
                break;
            }
            for(int i=0;i+1<len;i++)
            {
                string tmp=t;
                swap(tmp[i],tmp[i+1]);
                if(mymap.find(tmp)==mymap.end())
                {
                    mymap[tmp]=1;
                    q.push(Node(tmp,step+1));
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}*/
