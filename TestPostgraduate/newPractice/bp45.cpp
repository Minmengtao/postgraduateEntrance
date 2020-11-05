#include<cstdio>
#include<cmath>
#include<cstring>
int cnt[26]={0};
int isPrime(int x){
	if(x==0||x==1)
		return 0;
	else if(x==2||x==3)
		return 1;
	else{
		for(int i=2;i<=sqrt(x);i++)
			if(x%i==0)
				return 0;
		return 1;
	}
}
int main(){
	char str[1005];
	scanf("%s",str);
	for(int i=0;i<strlen(str);i++)
		cnt[str[i]-'a']++;
	int max=-1,min=1000;
	for(int j=0;j<26;j++){
		if(max<cnt[j]&&cnt[j]!=0)
			max=cnt[j];
		if(min>cnt[j]&&cnt[j]!=0)
			min=cnt[j];
	}
	if(isPrime(max-min))
		printf("Lucky Word\n%d\n",max-min);
	else
		printf("No Answer\n");
	return 0;
}