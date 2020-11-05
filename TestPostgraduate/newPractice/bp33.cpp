/*#include<cstdio>
#include<cstring>
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		char str[55];
		scanf("%[^\n]",str);//能接收空格字符
		int len=strlen(str),cnt=0;
		for(int i=0;i<len;i++){
			if(str[i]==' '&&str[i-1]!=' '&&i>0)
				cnt++;
		}
		if(str[len-1]!=' ')
			cnt++;
		printf("%d\n",cnt);
	}
	return 0;
}*/
#include<cstdio>
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		char s,pre_s=' ';
		int cnt=0;
		while((s=getchar())!='\n'){
			if(s==' '&&pre_s!=' ')
				cnt++;
			pre_s=s;
		}
		if(pre_s!=' ')
			cnt++;
		printf("%d\n",cnt);
	}
	return 0;
}

