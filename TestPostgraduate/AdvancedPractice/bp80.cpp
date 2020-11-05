#include<stdio.h>
#include<string.h>
int main(){
	int n,index;
	scanf("%d",&n);
	index=n;
	while(n--){
		char str1[1001],str2[1001],str3[1002];
		scanf("%s %s",str1,str2);
		int i=0,j,len1=strlen(str1),len2=strlen(str2),sign=0;
		while(len1>0&&len2>0){
			int x1=str1[len1-1]-'0',x2=str2[len2-1]-'0';
			if(x1+x2+sign<=9){
				str3[i++]=x1+x2+sign+'0';
				sign=0;
			}
			else{
				str3[i++]=(x1+x2+sign)%10+'0';
				sign=(x1+x2+sign-(x1+x2+sign)%10)/10;
			}
			len1--;len2--;
		}
		if(len1==0&&len2==0&&sign!=0){
			str3[i++]=sign+'0';
			sign=0;
		}
		while(len1>0){
			int x1=str1[len1-1]-'0';
			if(sign+x1<=9){
				str3[i++]=x1+sign+'0';
				sign=0;
			}
			else{
				str3[i++]=(x1+sign)%10+'0';
				sign=(x1+sign-(x1+sign)%10)/10;
			}
			len1--;
		}
		while(len2>0){
			int x2=str2[len2-1]-'0';
			if(sign+x2<=9){
				str3[i++]=x2+sign+'0';
				sign=0;
			}
			else{
				str3[i++]=(x2+sign)%10+'0';
				sign=(x2+sign-(x2+sign)%10)/10;
			}
			len2--;
		}
		if(len1==0&&len2==0&&sign!=0){
			str3[i++]=sign+'0';
			sign=0;
		}
		printf("Case %d:\n%s + %s = ",index-n,str1,str2);
		for(j=i-1;j>=0;j--)
			printf("%c",str3[j]);
		printf("\n\n");
	}
	return 0;
}