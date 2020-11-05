#include<cstdio>
#include<queue>
using namespace std;
int main(){
	int n;
	while (scanf("%d\n",&n)!=EOF){
		queue<int> number;
		queue<int> queue;
		for (int i=1;i<=2*n;i++){
			number.push(i);
			queue.push(i);
		}
		int sign=n;
		while ((int)queue.size()>n){
			for (int i=1;i<sign;i++){
				queue.push(queue.front());
				queue.pop();
			}
			if (queue.front()>n)
				queue.pop();
			else{
				queue=number;
				sign++;
			}
		}
		printf("%d\n", sign);
	}
	return 0;
}