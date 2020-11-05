#include<cstdio>
#include<cstring>
int cnt,n;
char pre[10000]="1",now[10000]="01";
int main(){
	scanf("%d",&n);
	if(n==0)
		printf("%s\n",pre);
	else if(n==1)
		printf("%s\n",now);
	else{
		cnt=2;
		while(cnt<n){
			char p[10000]="";
			strcpy(p,now);
			strcat(pre,now);
			strcpy(now,pre);
			strcpy(pre,p);
			cnt++;
		}
		puts(now);
	}
	return 0;
}