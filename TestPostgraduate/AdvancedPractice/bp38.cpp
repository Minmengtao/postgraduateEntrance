#include<stdio.h>
#include<stdlib.h>

/// ��cֻţ��ÿֻţ��һ��λ�ã�ţ��ţλ�ò�ͬ���м����Ҫ����Щţ��m��ľ�嵲ס��Ҫ��ľ�����

/// ��������� 1 ��ľ�壬�򳤶�Ϊ��һֻţ�����һֻţ�ľ���

/// ����� 2 ��ľ�壬������4ֻţ
/// ľ�峤�� = ��һֻ���ڶ�ֻ�ľ��� + ����ֻ������ֻ�ľ��� ���У��ڶ�ֻ������ֻ�ľ���������ţ֮��������

/// ����� 3 ��ľ�壬������6ֻţ
/// ľ�峤�� = ��һֻ���ڶ�ֻ�ľ��� + ����ֻ������ֻ�ľ��� + ����ֻ������ֻ�ľ���
/// ���� �ڶ�ֻ������ֻ�ľ��� �͵���ֻ������ֻ�ľ��� ������ţ֮��������

int order(int *num,int a);
int main(){
	int i,*a,*b;
	int m,s=200,c,sum;
    while( scanf("%d %d",&m,&c) != EOF ){
		a=(int*)malloc(sizeof(int)*c);
		b=(int*)malloc(sizeof(int)*(c-1));
        for(i=0;i<c;i++)///c ֻţ��λ��
            scanf("%d",&a[i]);
        order(a,c);  ///a[c-1]���

        for(i=0;i<c-1;i++)///ţ֮��� c-1 �����
            b[i]=a[i+1]-a[i]-1;
        order(b,c-1);///b[c-2]���

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