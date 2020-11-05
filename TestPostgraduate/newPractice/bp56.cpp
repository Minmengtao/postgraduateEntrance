/*#include<cstdio>
int k,n,a[15],len=0,z;
__int64 x=0;
int main(){
	scanf("%d %d",&k,&n);
	z=n;
	while(z){
		a[len++]=z%2;
		z/=2;
	}
	for(int i=len-1;i>=0;i--)
		x=x*k+a[i];
	printf("%I64d\n",x);
	return 0;
}*/
#include<cstdio>
int main(){
     int a[1002],loc=0,n,k,temp,num=1;
     scanf("%d %d",&k,&n);
	 while (loc<n){
		 temp=loc;
		 a[loc++]=num;
		 for (int i=0;i<temp&&loc<n;i++)
			 a[loc++]=num+a[i];
		 num*=k;
	 }
	 printf("%d",a[n-1]);
     return 0;
}