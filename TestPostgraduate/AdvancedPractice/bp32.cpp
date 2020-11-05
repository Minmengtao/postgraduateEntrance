#include<stdio.h>
int main(){
	int a,b,c,d,e,f;
	while(scanf("%d %d %d\n%d %d %d",&a,&b,&c,&d,&e,&f)!=EOF){
		int i,j,k,count=0;
		int d1,d2,d3;
		for(i=0;i<100;i++){
			for(j=i;j<100;j++){
				for(k=j;k<100;k++){
					d1=(i*24+c)*f;//ÌØ¿ì´¬
					d2=(j*24+b)*e;//¿ì´¬
					d3=(k*24+a)*d;//Âý´¬
					if(d1==d2&&d2==d3){
						printf("%d\n",d1);
						count++;
						break;
					}
				}
				if(count==1)
					break;
			}
			if(count==1)
				break;
		}
		
	}
	return 0;
}