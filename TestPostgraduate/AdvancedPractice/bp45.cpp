#include<stdio.h>
int n,m;
int f[130000];
int main(){
	int i,j;
    scanf("%d%d",&n,&m);
    for (i = 0; i <= m; ++i)
        for (j = 0; j <= m; ++j)
            f[i*i+j*j]=1;
    int M = 2*m*m;
    int flag = 0;
    for (i = 1; i < M; ++i)
		for (j = 0; j <= M-(n-1)*i ;++j)
			if (f[j]){
                int k;
                for (k = 1; k < n; ++k)
                    if (f[j+k*i]==0)
                        break;
                if (k >= n){
                    flag = 1;
                    printf("%d %d\n",j,i);
                }
            }    
    if (!flag)
        printf("NONE\n"); 
    return 0;
}