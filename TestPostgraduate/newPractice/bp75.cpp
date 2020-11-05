#include <cstdio>
typedef struct Rect{
	int length;
	int width;
	int id;
}Rect;
Rect r[1005];
int n,m;

int max(int x1,int x2){ return x1>x2?x1:x2; }
int min(int x1,int x2){ return x1<x2?x1:x2; }
void sortX(){
	for(int i=0;i<m;i++){
		for(int j=i;j<m;j++)
			if(r[i].id>r[j].id||(r[i].id==r[j].id&&r[i].length>r[j].length)||
				(r[i].id==r[j].id&&r[i].length==r[j].length&&r[i].width>r[j].width)){
				Rect temp=r[i];
				r[i]=r[j];
				r[j]=temp;
			}
	}
}
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			int x1,x2;
			scanf("%d%d%d",&r[i].id,&x1,&x2);
			r[i].length=max(x1,x2);
			r[i].width=min(x1,x2);
		}
		sortX();
		int preId=-100,preLen=-100,preWid=-100;
		for(int j=0;j<m;j++){
			if(r[j].id!=preId||r[j].length!=preLen||r[j].width!=preWid)
				printf("%d %d %d\n",r[j].id,r[j].length,r[j].width);
			preId=r[j].id,preLen=r[j].length,preWid=r[j].width;
		}
		printf("\n");
	}
	return 0;
}