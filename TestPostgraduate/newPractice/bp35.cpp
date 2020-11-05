#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
	char str[2005];
	while(~scanf("%s",str)){
		int len=strlen(str),k=0;
		char newStr[2005];
		for(int i=0;i<len;i++)
			if((str[i]-'0')%2==0)
				newStr[k++]=str[i];
		if(!k)
			printf("None\n");
		else{
			sort(newStr,newStr+k);
			for(int j=k-1;j>=0;j--)
				printf("%c",newStr[j]);
			printf("\n");
		}
	}
	return 0;
}