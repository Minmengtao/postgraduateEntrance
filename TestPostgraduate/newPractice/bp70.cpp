#include<cstdio>
#include<cstring>
char s1[10000],s2[10000];
int n,cnt=0;
int judge(){
	int len=strlen(s1);
	for(int i=0;i<=(len-1)/2;i++)
		if(s1[i]!=s1[len-1-i])
			return 0;
	return 1;
}
int get(char a){
	if('0'<=a&&a<='9')
		return a-'0';
	else
		return a-'A'+10;
}
char transfer(int x){
	if(x>=0&&x<=9)
		return x+'0';
	else
		return x-10+'A';
}
int main(){
	scanf("%d\n%s",&n,s1);
	while(cnt<=30){
		int len1=strlen(s1),sig=0,len2=0;
		for(int i=0;i<len1;i++){
			int x1=get(s1[len1-1-i]),x2=get(s1[i]);
			s2[len2++]=transfer((x1+x2+sig)%n);
			sig=(x1+x2+sig-(x1+x2+sig)%n)/n;
		}
		if(sig!=0)
			s2[len2++]=transfer(sig);
		s2[len2++]='\0';
		strcpy(s1,s2);
		cnt++;
		if(judge())//是回文数
			break;
	}
	if(cnt==31)
		printf("Impossible!\n");
	else
		printf("STEP=%d\n",cnt);
	return 0;
}