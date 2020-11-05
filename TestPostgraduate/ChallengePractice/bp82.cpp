#include<cstdio>
#include<iostream>
using namespace std;
int  visited[10],a[10], sum = 0, b[10];
void dfs(int m){
	int i, j; 
	if (m == 10){
		if (a[1]+a[2]+a[3]==a[4]+a[5]+a[6]&&a[4]+a[5]+a[6]==a[7]+a[8]+a[9]&&a[4]+a[5]+a[6]==
			a[1]+a[5]+a[9]&&a[1]+a[5]+a[9]==a[3]+a[5]+a[7]&&a[1]+a[4]+a[7]==a[2]+a[5]+a[8]&&
			a[2]+a[5]+a[8]==a[3]+a[6]+a[9]&&a[2]+a[5]+a[8]==a[1]+a[2]+a[3]){//判断条件
			sum++;
			for (i = 1 ; i <= 9 ; i++)
				b[i] = a[i];
		}
	}
	if (a[m] != 0)//如果该位置已有数字，那么填充下一个位置，保持该位置数字不变
		dfs(m + 1);
	else//如果该位置为0，即需要进行数字的填充
		for (i = 1 ; i <= 9 ; i++)
			if (!visited[i]){
				a[m] = i;
				visited[i] = 1;
				dfs(m + 1);
				visited[i] = 0;
				a[m] = 0;//这个位置很重要，我一开始就是掉了这一行代码，找了半天错误，因为我们上面用到了固定位置那个代码，所以可能就直接因为这次保存的数据在下一次依然存在时误以为是不需要填充的位置，就跳转到下一个位置，所以这里如果仅仅时将visited置为0的话，那么a[m]还是存在，并且会对后续的使用产生影响，所以一定要保持初始状态的一致
			}
}
int main(){
	int i, num;
	for (i = 1 ; i <= 9 ; i++){
		scanf("%d",&a[i]);
		if (a[i])
			visited[a[i]] = 1;
	}
	dfs(1);
	if (sum == 1)
		for (i = 1 ; i <= 9 ; i++){
			printf("%d ",b[i]);
			if (i % 3 == 0)
				printf("\n");
		}
	else
		printf("Too Many\n");
	return 0;
}