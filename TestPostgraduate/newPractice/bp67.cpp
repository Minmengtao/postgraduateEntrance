#include<cstdio>
#include<cstring>
char s[100],d;
int judge(char ch){
	int len=strlen(s),cnt=0;
	for(int i=0;i<len;i++)
		if(s[i]==ch)
			cnt++;
	if(cnt==0){
		printf("指定字符不存在\n");
		return 0;
	}else
		return cnt;
}
int main(){
	gets(s);
	scanf("%c ",&d);
	if(d=='D'){
		char ch;
		scanf("%c",&ch);
		int flag=0;
		if(judge(ch)){
			for(int i=0;i<strlen(s);i++){
				if(s[i]==ch){
					flag++;
					if(flag>=2)
						putchar(s[i]);
				}
				else
					putchar(s[i]);
			}
		}
	}else if(d=='I'){
		char a1,a2;
		scanf("%c %c",&a1,&a2);
		if(judge(a1)){
			int cnt=judge(a1);
			for(int i=0;i<strlen(s);i++){
				if(s[i]==a1){
					if(cnt==1)
						putchar(a2);
					cnt--;
				}
				putchar(s[i]);
			}
		}
	}else if(d=='R'){
		char a1,a2;
		scanf("%c %c",&a1,&a2);
		if(judge(a1)){
			for(int i=0;i<strlen(s);i++){
				if(s[i]==a1)
					putchar(a2);
				else
					putchar(s[i]);
			}
		}
	}
	printf("\n");
	return 0;
}