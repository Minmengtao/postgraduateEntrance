#include<stdio.h>
typedef struct Star{
	int x;
	int y;
}Star;
int contain(Star star[],int len,int x,int y);
int main(){
	int n,k=0;
	scanf("%d\n",&n);
	Star star[300];
	while(n--){
		int x,y;
		scanf("%d %d\n",&x,&y);
		if(k==0||contain(star,k,x,y)==1){
			star[k].x=x;
			star[k].y=y;
			k++;
		}
	}
	printf("%d\n",k);
	return 0;
}
int contain(Star star[],int len,int x,int y){
	if(len==0)
		return 0;
	int i=0;
	while(i<len){
		if(star[i].x==x&&star[i].y==y)
			return 0;
		i++;
	}
	return 1;
}
