#include<stdio.h>
#include<stdlib.h>

/// 有c只牛，每只牛有一个位置，牛和牛位置不同，有间隔，要把这些牛用m个木板挡住，要求木板最短

/// 如果我们用 1 块木板，则长度为第一只牛到最后一只牛的距离

/// 如果用 2 块木板，则看做有4只牛
/// 木板长度 = 第一只到第二只的距离 + 第三只到第四只的距离 其中，第二只到第三只的距离在所有牛之间距离最大

/// 如果用 3 块木板，则看做有6只牛
/// 木板长度 = 第一只到第二只的距离 + 第三只到第四只的距离 + 第五只到第六只的距离
/// 其中 第二只到第三只的距离 和第四只到第五只的距离 在所有牛之间距离最大

int order(int *num,int a);
int main(){
	int i,*a,*b;
	int m,s=200,c,sum;
    while( scanf("%d %d",&m,&c) != EOF ){
		a=(int*)malloc(sizeof(int)*c);
		b=(int*)malloc(sizeof(int)*(c-1));
        for(i=0;i<c;i++)///c 只牛的位置
            scanf("%d",&a[i]);
        order(a,c);  ///a[c-1]最大

        for(i=0;i<c-1;i++)///牛之间的 c-1 个间隔
            b[i]=a[i+1]-a[i]-1;
        order(b,c-1);///b[c-2]最大

        sum = a[c-1]-a[0]+1;
        for(i=0;i<m-1&&c-2-i>=0;i++)
            sum = sum - b[c-2-i];
        printf("%d\n",sum);
    }
    return 0;
}
int order(int *num,int a){
	int i,j;
	for(i=0;i<a;i++)
		for(j=i;j<a;j++)
			if(num[i]>num[j]){
				int temp=num[i];
				num[i]=num[j];
				num[j]=temp;
			}
	return 1;
}