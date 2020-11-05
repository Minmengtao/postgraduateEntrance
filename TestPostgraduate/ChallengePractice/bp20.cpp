#include<stdio.h>
#include<string.h>
int alter[16][3],k,size,test[10],j;
__int64 count=1;
char str[100000],m[100000];
void judge(int x);
int check(int x);
int main(){
	m[0]=1;
	scanf("%s %d",str,&k);
	int i,s,o=0,p,a;
	for(i=1;i<=k;i++)
		scanf("%d %d",&alter[i][1],&alter[i][2]);
	int len=strlen(str),l,zero=0;
	for(i=0;i<len;i++){
		int index=str[i]-'0';
		for(j=0;j<10;j++)
			test[j]=-1;
		j=0;
		test[j++]=index;
		size=1;
		judge(index);
		for(l=0;l<j;l++)
			if(test[l]==0)
				zero++;
		s=0;
		for(p=0;p<=o;p++){
			a=m[p]*size+s;
			m[p]=a%10;
			s=a/10;
		}
		while(s!=0){
			o++;
			m[o]=s%10;
			s=s/10;
		}
	}
	if(zero==len)//如果检测出每位数字都可以为0时减1
		count--;
	int flag=0;
	for(i=o;i>=0;i--)
		printf("%d",m[i]);
	printf("\n");
	return 0;
}
void judge(int x){//一位数字在变换过程中有几种状态分别记录下来
	if(x>9&&x<0)
		return;
	int i;
	for(i=1;i<=k;i++){
		if(x==alter[i][1]&&check(alter[i][2])){//
			size++;
			test[j++]=alter[i][2];
			judge(alter[i][2]);
		}
	}
}
int check(int x){
	int i;
	for(i=0;i<j;i++)
		if(x==test[i])
			return 0;
	return 1;
}
	
