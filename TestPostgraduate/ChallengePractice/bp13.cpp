#include<stdio.h>
#define MAXSIZE 10
int queue[MAXSIZE][MAXSIZE];
int count=0,n,black[9]={0},white[9]={0};
void dfs_black(int x);
int check_black(int r,int l);
void dfs_white(int x);
int check_white(int r,int l);
int main(){
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&queue[i][j]);
	dfs_black(1);
	printf("%d\n",count);
	return 0;
}
void dfs_black(int x){
    if(x==n+1)
        dfs_white(1);                           //��ɫ��������������ɫ�� 
    for(int i=1;i<=n;i++)
        if(queue[x][i]==1&&check_black(x,i)){       //���ԷŻʺ���������ã����������� 
            black[x]=i;
            dfs_black(x+1);
            black[x]=0;                         //��ԭ 
        }
}
int check_black(int r,int l){
    for(int i=1;i<r;i++)
        if(black[i]==l||r-l==i-black[i]||r+l==i+black[i])//�ֱ��ж��Ƿ���ͬһ�У�ͬһ��б�ߣ�ͬһ��б�ߣ��Լ���ͼһ�¾������� 
            return 0;
    return 1; 
}
void dfs_white(int x){                          //������ɫ�ʺ���Ѻ�ɫ�ʺ���һ���ģ�����ע��ڻʺ��Ѿ�ռ��һ��λ���ˣ� 
    if(x==n+1)
        count++;                                  // ͳ�ƽ�� 
    for(int i=1;i<=n;i++)
        if(queue[x][i]==1&&check_white(x,i)){
            white[x]=i;
            dfs_white(x+1);
            white[x]=0;
        }
}
int check_white(int r,int l){//r is row,l is column
    if(black[r]==l) 
		return 0;       //�ڻʺ��Ѿ�ռ�����λ�� 
    for(int i=1;i<r;i++)
        if(white[i]==l||r-l==i-white[i]||r+l==i+white[i])
            return 0;
    return 1; 
}



