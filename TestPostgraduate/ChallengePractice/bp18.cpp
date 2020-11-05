#include<cstdio>
using namespace std;
int m,n,sign[12][12],c[12]={-1},guest[12]={-1};
int cor[12]={0},size=0,g[10000][12],ctr[12]={0};
int check(){
	int f1=1,f2=1;
	for(int i=0;i<m;i++){
		int j=0;
		for(int x=0;j<c[i]&&x<n;x++)
			if(sign[i][j]==ctr[x])
				j++;
		if(guest[i]&&j<c[i])//判断猜测正确的数是否符合该序列
			f1=0;
		else if(!guest[i]&&j==c[i])
			f2=0;
		if(!f1||!f2)
			break;
	}
	if(f1&&f2)
		return 1;
	else
		return 0;
}
void dfs(int x){
	if(x==n&&check()){
		for(int j=0;j<n;j++)
			g[size][j]=ctr[j];
		size++;
		return;
	}
	if(x<n)
		for(int i=0;i<n;i++)
			if(!cor[i]){
				ctr[x]=i;
				cor[i]=1;
				dfs(x+1);
				cor[i]=0;
			}
}
int main(){
	scanf("%d %d",&n,&m);
	int i,j;
	for(i=0;i<m;i++){
		scanf("%d",&c[i]);
		for(j=0;j<c[i];j++)
			scanf("%d",&sign[i][j]);
		scanf("%d",&guest[i]);
	}
	dfs(0);
	printf("%d\n",size);
	for(i=0;i<size;i++){
		for(j=0;j<n;j++)
			printf("%d ",g[i][j]);
		printf("\n");
	}
	return 0;
}
/*#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int str[15][15];
int ctr[15];
bool use[15];
int graph[20001][15];
int Size;
int m,n;
int Judge(){//匹配判断
    int f_1=1;
    int f_2=1;
    for(int i=0; i<m; i++){
        if(str[i][str[i][0]+1]==1&&f_1){
            int j=1;
            for(int x=0; j<=str[i][0]&&x<n; x++)
                if(str[i][j]==ctr[x])
                    j++;
            if(j<str[i][0]+1)
                f_1=0;
        }
        else{
            int j=1;
            for(int x=0; j<=str[i][0]&&x<n; x++)
                if(str[i][j]==ctr[x])
                    j++;
            if(j==str[i][0]+1)
                f_2=0;
        }
        if(!f_1||!f_2)
            break;
    }
	if(f_1&&f_2)
		return 1;
	else
		return 0;
}
void DFS(int x){//递归搜索
    if(x==n&&Judge()){//结束条件
   
        for(int i=0; i<n; i++)
            graph[Size][i]=ctr[i];
		Size++;
    }
    if(x<n)
        for(int i=0; i<n; i++)
            if(use[i]){
                ctr[x]=i;
                use[i]=false;
                DFS(x+1);
                use[i]=true;
            }
}
int main(){
    while(cin>>n>>m){
        for(int i=0; i<m; i++){
            cin>>str[i][0];
            for(int j=1; j<=str[i][0]+1; j++)
                cin>>str[i][j];
        }
        memset(use,true,sizeof(use));//初始化
        Size=0;
        DFS(0);//从第零号球员开始搜
        cout<<Size<<endl;
        for(int i=0; i<Size; i++){
            for(int j=0; j<n; j++)
                cout<<graph[i][j]<<" ";
            cout<<endl;
        }
    }
    return 0;
}*/
