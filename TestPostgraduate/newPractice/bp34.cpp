#include<cstdio>
#include<cstring>
int main(){
	char str[205];
	while(~scanf("%s",str)){
		int len=strlen(str),flag=0;
		double sum=0;
		for(int i=0;i<len;i++)
			if(str[i]-'0'>0&&str[i]-'0'<10){
				if(flag>0)
					printf("+");
				printf("1/%d",str[i]-'0');
				sum+=(double)1/(str[i]-'0');
				flag++;
			}
		if(sum!=0)
			printf("=%.2f\n",sum);
		else
			printf("0\n");
	}
	return 0;
}