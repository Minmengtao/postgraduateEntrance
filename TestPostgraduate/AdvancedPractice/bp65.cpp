#include<stdio.h>
#include<string.h>
int main(){
	char s;
	while(scanf("%c",&s)!=EOF){
		char s1[100000];
		int count_w=0,count_l=0,count_ww=0,count_ll=0;
		int len=0;
		while(s!='E'){
			s1[len]=s;
			len++;
			scanf("%c",&s);
		}
		int i,j;
		for(i=0;i<len;i++){
			if(s1[i]=='W')
				count_w++;
			if(s1[i]=='L')
				count_l++;
			if((count_w-count_l>=2&&count_w>=11)||(count_l-count_w>=2&&count_l>=11)||
				(count_w==12&&count_l==10)||(count_w==10&&count_l==12)){
				printf("%d:%d\n",count_w,count_l);
				count_w=0;
				count_l=0;
			}
		}
		if(count_w!=0||count_l!=0)
			printf("%d:%d\n\n",count_w,count_l);
		for(i=0;i<len;i++){
			if(s1[i]=='W')
				count_ww++;
			if(s1[i]=='L')
				count_ll++;
			if((count_ww-count_ll>=2&&count_ww==21)||(count_ll-count_ww>=2&&count_ll>=21)||
				(count_ww==22&&count_ll==20)||(count_ww==20&&count_ll==22)){
				printf("%d:%d\n",count_ww,count_ll);
				count_ww=0;
				count_ll=0;
			}
		}
		if(count_ww!=0||count_ll!=0)
			printf("%d:%d\n\n",count_ww,count_ll);
	}
	return 0;
}