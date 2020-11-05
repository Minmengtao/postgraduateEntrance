#include<stdio.h>
#include<math.h>
int isPrime(int);
int main(){
    int n=10000,i,count=0,prime[1230];
    for(i=2;i<=n;i++)
        if(isPrime(i)==1){
			prime[count]=i;
            count++;
        }
    int T,a_count,num;
	scanf("%d\n",&T);
	while(T--){
		a_count=0;
		scanf("%d\n",&num);
		if(num<=10000){
			int index=0;
			while(index<=count && prime[index]<=num)
				index++;
			index--;
			i=0;
			while(i<index){
				if(prime[i]+prime[index]==num){
					a_count++;
					i++;
					index--;
				}else if(prime[i]+prime[index]<num)
				    i++;
				else
				    index--;
			}
			printf("%d\n",a_count);
		}
	}
    return 0;
}
int isPrime(int n){
    int i=2;
    if(n==2)
        return 1;
    else{
        while(i<=sqrt(n)){
            if(n%i==0)
                return 0;
            i++;
        }
        return 1;
    }
    
}