#include<stdio.h>
#include<string.h>
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		char str1[401],str2[401],str3[1001];
		scanf("%s %s",str1,str2);
		int len1=strlen(str1),len2=strlen(str2),index1=-2,index2=-2,i,j;
		for(i=0;i<len1;i++)//���ҵ�����ʵ����С����
			if(str1[i]=='.'){
				index1=i;
				break;
			}
		for(i=0;i<len2;i++)
			if(str2[i]=='.'){
				index2=i;
				break;
			}
		j=0;
		while(len2-index2!=len1-index1&&index1>0&&index2>0){//�Ӻ���ǰ��֪��С�����λ���ֳ���һ��,����������С����
			if(len2-index2>len1-index1){
				str3[j++]=str2[len2-1];
				len2--;
			}
			if(len2-index2<len1-index1){
				str3[j++]=str1[len1-1];
				len1--;
			}
		}
		int sign=0;
		while(len2>0||len1>0){//�㵽С����Ϊֹ
			if(index1>0&&index2==-2&&len1>index1){//ǰ����if����ж�һ��������һ����С�������������
				str3[j++]=str1[len1-1];
				len1--;
			}
			else if(index2>0&&index1==-2&&len2>index2){
				str3[j++]=str2[len2-1];
				len2--;
			}
			else if(len2==index2+1&&len1==index1+1){
				str3[j++]='.';
				len2--;len1--;
			}
			else{
				int x1=0,x2=0;
				if(len1>0)
				    x1=str1[len1-1]-'0';
				if(len2>0)
				    x2=str2[len2-1]-'0';
				if(x1+x2+sign<=9){
					str3[j++]='0'+x1+x2+sign;
					sign=0;
				}
				else{
					str3[j++]='0'+(x1+x2+sign)%10;
					sign=((x1+x2+sign)-(x1+x2+sign)%10)/10;
				}
				len2--;len1--;
			}
		}
		int flag=0;
		for(i=0;i<j;i++){
			if(str3[i]=='0')
				flag++;
			else
				break;
		}
		if(str3[flag]=='.')
			flag++;
		for(i=j-1;i>=flag;i--)
			printf("%c",str3[i]);
		printf("\n");
	}
	return 0;
}