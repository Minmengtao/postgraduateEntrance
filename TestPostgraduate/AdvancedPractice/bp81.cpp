#include<stdio.h>
#include<string.h>
int main(){
	int n;
	char sys[16]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
	scanf("%d",&n);
	while(n--){
		char str1[100],str2[100],str3[100];
		scanf("%s %s",str1,str2);
		int i=0,j,len1=strlen(str1),len2=strlen(str2),sign=0;
		while(len1>0&&len2>0){
			int x1,x2;
			if(str1[len1-1]>='0'&&str1[len1-1]<='9')
				x1=str1[len1-1]-'0';
			else
				x1=str1[len1-1]-'a'+10;
			if(str2[len2-1]>='0'&&str2[len2-1]<='9')
				x2=str2[len2-1]-'0';
			else
				x2=str2[len2-1]-'a'+10;
			if(x1+x2+sign<16){
				str3[i++]=sys[x1+x2+sign];
				sign=0;
			}else{
				str3[i++]=sys[(x1+x2+sign)%16];
				sign=(x1+x2+sign-(x1+x2+sign)%16)/16;
			}
			len1--;len2--;
		}
		if(len1==0&&len2==0&&sign!=0){
			str3[i++]=sys[sign];
			sign=0;
		}
		while(len1>0){
			int x1;
			if(str1[len1-1]>='0'&&str1[len1-1]<='9')
				x1=str1[len1-1]-'0';
			else
				x1=str1[len1-1]-'a'+10;
			if(x1+sign<16){
				str3[i++]=sys[x1+sign];
				sign=0;
			}else{
				str3[i++]=sys[(x1+sign)%16];
				sign=(x1+sign-(x1+sign)%16)/16;
			}
			len1--;
		}
		while(len2>0){
			int x2;
			if(str2[len2-1]>='0'&&str2[len2-1]<='9')
				x2=str2[len2-1]-'0';
			else
				x2=str2[len2-1]-'a'+10;
			if(x2+sign<16){
				str3[i++]=sys[x2+sign];
				sign=0;
			}else{
				str3[i++]=sys[(x2+sign)%16];
				sign=(x2+sign-(x2+sign)%16)/16;
			}
			len2--;
		}
		if(len1==0&&len2==0&&sign!=0){
			str3[i++]=sys[sign];
			sign=0;
		}
		for(j=i-1;j>=0;j--)
			printf("%c",str3[j]);
		printf("\n");
	}
	return 0;
}