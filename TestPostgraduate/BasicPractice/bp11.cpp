#include<stdio.h>
int main(){
	int AH,AM,AS,BH,BM,BS,CH,CM,CS;
	scanf("%d%d%d%d%d%d",&AH,&AM,&AS,&BH,&BM,&BS);
	if(AH>=0&&BH>=0&&AM>=0&&AM<=59&&AS>=0&&AS<=59&&BM>=0&&BM<=59&&BS>=0&&BS<=59){
		CS=(AS+BS)%60;
		CM=(AM+BM+(AS+BS)/60)%60;
		CH=AH+BH+(AM+BM+(AS+BS)/60)/60;
		printf("%d %d %d\n",CH,CM,CS);
	}
	return 0;
}