/*#include <cstdio>
int a[1010],b[1010],n;
int main(){
	char temp;
	int i=0;
	while(scanf("%d%c",&a[i],&temp)&&temp!='\n')
		i++;
	n=i;
	for(i=0;i<n;i++)
		b[i]=a[i+1]-a[i]-1;
	int sum=0;
	for(i=0;i<n;i+=2)
		sum^=b[i];
	if(!sum)
		printf("-1");
	else{
		for(i=0;i<n;i++){
			for(int j=1;j<=b[i];j++){
				b[i]-=j;
				if(i!=0)
					b[i-1]+=j;
				sum=0;
				for(int k=0;k<n;k+=2)
					sum^=b[k];
				if(sum==0){
					printf("%d %d\n",a[i],a[i]+j);
					return 0;
				}
				b[i]+=j;
				if(i!=0)
					b[i-1]-=j;
			}
		}
	}
	return 0;
}*/
#include <cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int a[1010],b[1010],n;
int main(){
	char temp;
	int i=0;
	while(scanf("%d%c",&a[i],&temp)&&temp!='\n')
		i++;
	n=i;
	for(i=0;i<n;i++)
		b[i]=a[i+1]-a[i]-1;
	int sum=0;
	for(i=0;i<n;i+=2)
		sum^=b[i];
	if(!sum)
		printf("-1");
	else{
		for(i=0;i<n;i++){
			for(int j=1;j<=b[i];j++){
				b[i]-=j;
				if(i!=0)
					b[i-1]+=j;
				sum=0;
				for(int k=0;k<n;k+=2)
					sum^=b[k];
				if(sum==0){
					printf("%d %d\n",a[i],a[i]+j);
					return 0;
				}
				b[i]+=j;
				if(i!=0)
					b[i-1]-=j;
			}
		}
	}
	return 0;
}