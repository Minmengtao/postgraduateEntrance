#include<cstdio>
#include<iostream>
using namespace std;
int n,m,v[8][2]={{1,0},{1,1},{1,-1},{0,1},{0,-1},{-1,-1},{-1,0},{-1,1}};
char a[105][105]={'.'};
void transfer(int x,int y){
	int sum=0;
	for(int i=0;i<8;i++)
		if(x+v[i][0]>=0&&x+v[i][0]<n&&y+v[i][1]>=0&&y+v[i][1]<m)
			if(a[x+v[i][0]][y+v[i][1]]=='*')
				sum++;
	a[x][y]=sum+'0';
}
int main(){
	int i,j,cnt=1;
	while(~scanf("%d %d",&n,&m)){
		if(n==0||m==0)
			break;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				cin>>a[i][j];
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				if(a[i][j]!='*')
					transfer(i,j);
		printf("Field #%d:\n",cnt++);
		for(i=0;i<n;i++){
			for(j=0;j<m;j++)
				printf("%c",a[i][j]);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}