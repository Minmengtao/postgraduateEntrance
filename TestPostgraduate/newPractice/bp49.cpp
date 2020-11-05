#include<cstdio>
#include<cstring>
int main(){
	char str1[205],str2[205],str3[205];
	scanf("%s %s",str1,str2);
	int len1=strlen(str1),len2=strlen(str2),index1=-2,index2=-2,i,j;
	for(i=0;i<len1;i++)//先找到两个实数的小数点
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
	while(len2-index2!=len1-index1&&index1>0&&index2>0){//从后往前算知道小数点后几位数字长度一样,两个数均含小数点
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
	while(len2>0||len1>0){//算到小数点为止
		if(index1>0&&index2==-2&&len1>index1){//前两个if语句判断一个整数，一个带小数的两个数相加
			str3[j++]=str1[len1-1];
			len1--;
		}else if(index2>0&&index1==-2&&len2>index2){
			str3[j++]=str2[len2-1];
			len2--;
		}else if(len2==index2+1&&len1==index1+1){
			str3[j++]='.';
			len2--;len1--;
		}else{
			int x1=0,x2=0;
			if(len1>0){
				x1=str1[len1-1]-'0';
				len1--;
			}
			if(len2>0){
				x2=str2[len2-1]-'0';
				len2--;
			}
			if(x1+x2+sign<=9){
				str3[j++]='0'+x1+x2+sign;
				sign=0;
			}else{
				str3[j++]='0'+(x1+x2+sign)%10;
				sign=(x1+x2+sign)/10;
			}
		}
	}
	if(sign!=0)
		str3[j++]=sign+'0';
	for(i=j-1;i>=0;i--)
		printf("%c",str3[i]);
	printf("\n");
	return 0;
}