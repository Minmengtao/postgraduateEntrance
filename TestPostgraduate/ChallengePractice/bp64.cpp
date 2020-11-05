#include<cstdio>
int n,p[50005];
int main(){
	scanf("%d",&n);
	for(int k=1;k<=n;k++)
		scanf("%d",&p[k]);
	int count=0;
	for (int i = 1; i <= n; i++) {
		int max = p[i];
		int min = p[i];
		for (int j = i; j <= n; j++) {
			if (min > p[j])
				min = p[j];
			if (p[j] > max)
				max = p[j];
			if (max - min == j - i)
				count++;
		}
	}
	printf("%d\n",count);
	return 0;
}