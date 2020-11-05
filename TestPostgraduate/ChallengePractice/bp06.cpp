#include<stdio.h>
int main(){
	int v1,v2,t,s,l;
	scanf("%d %d %d %d %d",&v1,&v2,&t,&s,&l);
	int t1=0,t2=l/v2,i,s1=0,s2=0;
	for(i=1;i<=t2;i++){
		s1+=v1*1;//ÍÃ×ÓÅÜµÄ¾àÀë
		s2+=v2*1;//ÎÚ¹êÅÜµÄ¾àÀë
		if(s1>=l){
			t1=i;
			break;
		}
		if(s1>=t+s2){
			i+=s;
			s2+=v2*s;
		}
	}
	if(s1==l&&s2==l)
		printf("D\n%d\n",t1);
	else if(s1==l&&s2<l)
		printf("R\n%d\n",t1);
	else
		printf("T\n%d\n",t2);
	return 0;
}