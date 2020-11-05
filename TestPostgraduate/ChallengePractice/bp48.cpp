#include<cstdio>
#include<cstring>
using namespace std;
char num[1000];
int bin=10;
long decimal(){//����ǰ�����µ���ת��Ϊʮ�����µ���
	long x=0,len=strlen(num);
	for(int i=0;i<len;i++){
		if(num[i]<='9'&&num[i]>='0')
			x=x*bin+num[i]-'0';
		else
			x=x*bin+num[i]-'A';
	}
	return x;
}
void exchange(long b){//����ת�������
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
		if(!strcmp(str,"EQUAL")){//���ָ��
			exchange(basex);
		}else if(!strcmp(str,"CHANGE")){//ת������
			scanf("%d",&bin);
		}else{
			if(!strcmp(str,"CLEAR")){//��պ���������
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
				if(!strcmp(str,"ADD")){//��
					basex+=x;
				}else if(!strcmp(str,"SUB")){//��
					basex-=x;
				}else if(!strcmp(str,"MUL")){//��
					basex*=x;
				}else if(!strcmp(str,"DIV")){//��
					basex/=x;
				}else if(!strcmp(str,"MOD")){//ȡ����
					basex%=x;
				}
			}
			printf("%ld\n",basex);
		}
	}
	return 0;
}