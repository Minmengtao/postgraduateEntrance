#include<cstdio>
#include<cstring>
using namespace std;
char num[1000];
int bin=10;
long decimal(){//将当前进制下的数转换为十进制下的数
	long x=0,len=strlen(num);
	for(int i=0;i<len;i++){
		if(num[i]<='9'&&num[i]>='0')
			x=x*bin+num[i]-'0';
		else
			x=x*bin+num[i]-'A';
	}
	return x;
}
void exchange(long b){//进制转换后输出
	char s[1000]="";
	int i=0;
	while(b){
		int x=b%bin;
		if(x<10)
			s[i++]=x+'0';
		else
			s[i++]=x-10+'A';
		b/=bin;
	}
	for(int j=i-1;j>=0;j--)
		printf("%c",s[j]);
	printf("\n");
}
int main(){
	int n;
	scanf("%d",&n);
	char str[10];
	long basex;
	while(n--){
		scanf("%s",str);
		long x;
		if(!strcmp(str,"EQUAL")){//输出指令
			exchange(basex);
		}else if(!strcmp(str,"CHANGE")){//转换进制
			scanf("%d",&bin);
		}else{
			if(!strcmp(str,"CLEAR")){//清空后输入数字
				basex=0;
				scanf("%s",str);
				if(n--){
					scanf("%s",num);
					basex=decimal();
				}
			}else{
				char str1[100];
				scanf("%s",str1);
				if(n--){
					scanf("%s",num);
					x=decimal();
				}
				if(!strcmp(str,"ADD")){//加
					basex+=x;
				}else if(!strcmp(str,"SUB")){//减
					basex-=x;
				}else if(!strcmp(str,"MUL")){//乘
					basex*=x;
				}else if(!strcmp(str,"DIV")){//除
					basex/=x;
				}else if(!strcmp(str,"MOD")){//取余数
					basex%=x;
				}
			}
			printf("%ld\n",basex);
		}
	}
	return 0;
}