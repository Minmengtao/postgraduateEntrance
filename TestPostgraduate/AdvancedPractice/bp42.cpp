#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int m,sum=0,i,j;
		vector<int> vc;
		vector<int> num;//开两个数组，一个存放输入的数，一个存放组合结果，不断扩展
		for(i=0;i<n;i++){
			scanf("%d",&m);
			vc.push_back(m);
		}
		sort(vc.begin(),vc.end());
		int length=vc.size();
		num.push_back(*(vc.begin()));
		for(i=1;i<length;i++){
			int len=num.size();
			num.push_back(vc[i]);
			for(j=0;j<len;j++)
				num.push_back(num[j]+vc[i]);
		}
		int count=0;
		for(vector<int>::iterator t=num.begin();t!=num.end();t++)
			if (*t%11==0)
				count++;
		printf("%d\n",count);
	}
	return 0;
}
