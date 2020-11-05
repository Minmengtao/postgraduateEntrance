#include<cstdio>
int a[205][205],r,c,ans=0;
int check(int x,int y,int k){
    int sig=a[x][y];
    for(int i=0;i<k;i++)
		for(int j=0;j<k;j++)
			if(a[x+i][y+j]!=sig)
				return 0;
    return 1;
}
int main(void){
    scanf("%d%d",&r,&c);
    int mmax,i,j;
    if(r<c)mmax=c;
    else mmax=r;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf("%d",&a[i][j]);
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            for(int k=ans+1;k<=mmax;k++){
                if(i+k<=mmax&&j+k<=mmax)
                    if(check(i,j,k))
                        ans=k;
                else break;
            }
    printf("%d\n",ans*ans);
    return 0;
}