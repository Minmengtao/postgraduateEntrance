#include<stdio.h>
#include<string.h>
int main(){
	char str[500];
	while(scanf("%s\n",str)!=EOF){
		int i=0,len=strlen(str);
		int flag=0,j=0;
		char num[500]="";
		for(i=0;i<len;i++){
			if(str[i]>='0'&&str[i]<='9'){
			    if(flag==0&&str[i]=='0')
			        continue;
			    num[j++]=str[i];
			    flag=1;
			    
			}
			if(flag==1&&(str[i]<'0'||str[i]>'9')){
			    num[j++]=' ';
			    flag=0;
			}
		}
		int length=strlen(num);
		if(length==0)
		    printf("0");
		else{
		    int count=0;
		    for(i=0;i<length;i++)
		        if(num[i]==' ')
		            count++;
		    if(str[len-1]>'9'||str[len-1]<'0'){
		        printf("%d ",count);
		        for(i=0;i<length-1;i++)
		            printf("%c",num[i]);
		    }
		    else
		        printf("%d %s",count+1,num);
		}
		printf("\n");
	}
	return 0;
}