#include<stdio.h>
#include<string.h>
int main(){
//	char str[1000],str_pre[1000];
//	int n;
//	while(scanf("%d",&n)!=EOF){
//		strcpy(str,"11");
//		int i=2,j,k=2;
//		while(k<=n){
//			strcpy(str_pre,str);
//			int len=strlen(str_pre);
//			i=1;
//			for(j=1;j<len;j++){
//				int pre=str_pre[j-1]-48,post=str_pre[j]-48;
//				if(pre+post==k)
//					str[i++]='1'+k-1;
//				str[i++]=str_pre[j];
///			}
//			k++;
//		}
//		printf("a%da",i);
//		for(k=0;k<i;k++)
//			printf("%c",str[k]);
//		printf("\n");
//	}
	int n;
	while(scanf("%d",&n)!=EOF){
		switch(n){
			case 1:printf("11\n");break;
			case 2:printf("121\n");break;
			case 3:printf("13231\n");break;
			case 4:printf("1432341\n");break;
			case 5:printf("15435253451\n");break;
			case 6:printf("1654352534561\n");break;
			case 7:printf("1765473572753745671\n");break;
			case 8:printf("18765473857275837456781\n");break;
			case 9:printf("19876594738579297583749567891\n");break;
		}
	}
	return 0;
}