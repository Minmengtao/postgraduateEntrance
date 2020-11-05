#include<stdio.h>
#include<string.h>
int main(){
	char s[10001];
	while(gets(s)&&strcmp(s,"")!=0){
		char str[10001],sign[10001];
		int i=0,max=-1,count=0,len=strlen(s),j;
		for(i=0;i<len;i++){
			if(s[i]==' '){
				if(count>max){
					for(j=0;j<count;j++)
						str[j]=sign[j];
					//strcpy(str,sign);
					max=count;
				}
				strcpy(sign," ");
				count=0;
			}else{
				sign[count]=s[i];
				count++;
			}
		}
		if(count>max){
			for(j=0;j<count;j++)
				str[j]=sign[j];
				//strcpy(str,sign);
			max=count;
		}
		//if(max!=-1){
			printf("%d ",max);
			for(j=0;j<max;j++)
				printf("%c",str[j]);
		//}else
		//	printf("%d %s",strlen(s),s);
		//printf(" %d",max);
		printf("\n");
	}
	return 0;
}