#include<stdio.h>
#include<string.h>
int main(){
	char s[101],subs[101];
	while(scanf("%s %s",s,subs)!=EOF){
		int i=0,j=0,len_s=strlen(s),len_subs=strlen(subs),flag=0;
		while(i<len_s&&flag==0){
			if(s[i]==subs[j]){
				int count=0;
				while(s[i+count]==subs[j]&&j<len_subs&&i+count<len_s){
					count++;
					j++;
				}
				if(j==len_subs)
					flag=i+1;
				else{
					i++;
					j=0;
				}
			}else{
				i++;
				j=0;
			}
		}
		printf("%d\n",flag);
	}
	return 0;
}