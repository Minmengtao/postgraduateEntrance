#include <string.h>
#include <stdio.h>
#include <memory.h>
int main(){
    int T,k=0,n,i,j;
    char s[100][100];
    scanf("%d\n",&T);
    while(k<T){ 
        memset(s,0,sizeof(s));
        scanf("%d\n",&n);
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++){
                if(i+j==n+1||i==j)
                    s[i][j]='X';
                else
                    s[i][j]=' ';
            }
        for(i=1;i<=n/2;i++){
            for(j=1;j<=n;j++){
                if(i+j>n+1)
                    break;
                else
                    printf("%c",s[i][j]);
            }
            printf("\n");
        }
        for(;i<=n;i++){
            for(j=1;j<=i;j++){
                printf("%c",s[i][j]);
            } 
            printf("\n");
        }
        printf("\n");
        k++;
    }
    return 0;
}