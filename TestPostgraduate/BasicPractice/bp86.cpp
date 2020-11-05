#include<stdio.h>
int main(){
	int T;
	scanf("%d",&T);
    int n; 
    while(T--){ 
		scanf("%d",&n);
        if(n<=0||n>=55)
            break;
        int i;
        int sum=1;
        int oldcow=1; 
        int onecow=0;
        int twocow=0;
        int threecow=0;
        for(i=1;i<n;i++){
            oldcow=oldcow+threecow;
            threecow=twocow;    
            twocow=onecow;
            onecow=oldcow;
            sum=oldcow+twocow+threecow+onecow;
        }
        printf("%d\n",sum);
	}
    return 0; 
}