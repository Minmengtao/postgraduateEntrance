#include<iostream>
using namespace std;
int n,dp[20000]={0},a[101];
int main(){
	cin>>n;
	int i,j;
	for(i=0;i<n;i++)
		cin>>a[i];
	dp[0]=1;
	for(i=0;i<n;i++)
		for(j=0;j<10001;j++)
			if(dp[j])
				dp[j+a[i]]=1;
	int flag=0,num=0;
	for(i=a[n-1];i<10001;i++){
		if(dp[i]==1)
			num++;
		if(dp[i]==0)
			num=0;
		if(num==a[0]){
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"INF"<<endl;
	else{
		num=0;
		for(i=0;i<10001;i++)
			if(dp[i]==0)
				num++;
		cout<<num<<endl;
	}	
	return 0;
}