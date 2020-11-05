#include<cstdio>
typedef struct Std{
	char name[25];
	int c,en,com;
	int sum;
}Std;
Std s[105];
int n;
void sort(){
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++)
			if(s[i].sum<s[j].sum||(s[i].sum==s[j].sum&&s[i].c<s[j].c)||
				(s[i].sum==s[j].sum&&s[i].c==s[j].c&&s[i].com<s[j].com)||
				(s[i].sum==s[j].sum&&s[i].c==s[j].c&&s[i].com==s[j].com&&s[i].en<s[j].en)){
				Std temp=s[i];
				s[i]=s[j];
				s[j]=temp;
			}
	}
}
int main(){
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++){
			scanf("%s%d%d%d",s[i].name,&s[i].c,&s[i].com,&s[i].en);
			s[i].sum=s[i].c+s[i].com+s[i].en;
		}
		sort();
		for(int j=0;j<n;j++)
			printf("%s %d %d %d %d\n",s[j].name,s[j].sum,s[j].c,s[j].com,s[j].en);
		printf("\n");
	}
	return 0;
}