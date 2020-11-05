/*#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,k;
double s=0.0,minimal=1000000.0;
int citize[55][2],post[30][2],sig[30]={0},sign[30]={0},zz;
double yc[55][30]={{0.0}};
double upd(int cnt){//更新所有用户离选中的邮局中最短距离总和
	double cc[55],sum=0.0;
	for(int i=1;i<=n;i++){
		cc[i]=1000000.0;
		for(int j=0;j<cnt;j++)
			if(cc[i]>yc[i][sig[j]])
				cc[i]=yc[i][sig[j]];
		sum+=cc[i];
	}
	return sum;
}
void dfs(int x,int cnt){//x为目前遍历到的邮局，cnt为已经选的邮局
	if(x>m+1)//选的邮局超出题目所给数量
		return;
	if(cnt==k){//选完了k个邮局
		if(minimal>s){
			minimal=s;
			memcpy(sign,sig,sizeof(int)*30);
		}
		return;
	}
	for(int i=x;i<=m;i++){
		sig[cnt++]=i;
		double ss=upd(cnt),sss=s;
		s=ss;
		dfs(i+1,cnt);
		s=sss;
		sig[cnt--]=0;
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&citize[i][0],&citize[i][1]);
	for(int j=1;j<=m;j++){
		scanf("%d%d",&post[j][0],&post[j][1]);
		for(int op=1;op<=n;op++)
			yc[op][j]=sqrt((citize[op][0]-post[j][0])*(citize[op][0]-post[j][0])+
				(citize[op][1]-post[j][1])*(citize[op][1]-post[j][1]));
	}
	dfs(1,0);
	for(int o=0;o<k-1;o++)
		printf("%d ",sign[o]);
	printf("%d\n",sign[k-1]);
	return 0;
}*/
#include<iostream>  //邮局 
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int n, m, k, j, c[55][2], y[27][2], d[12], f1, f2, f[55] = { 0 };
float yc[27][55]={{0.0}}, s = 1000000000;
int dfs(int t, int i, int o[12], float w[55], float sum){
    if (i <= m + 1){//如果还没有遍历完所有的邮局
        if (t == k){//如果已经确定的邮局数已足够
            if (sum<s){
                s = sum;//s是最后的最小距离总值
				printf("%f\n",s);
				memcpy(d,o,sizeof(int)*k);//将数组o的k个值存入数组d
            }
        }else if (i <= m&&t<k){//还没有确定所有邮局数
            float ww[55];
            for (j = 1; j <= n; j++)
                ww[j] = w[j];
            dfs(t, i + 1, o, w, sum); f1 = 1, f2 = 0;//下一个邮局，初始化两个标记用的变量f1，f2
            if (!f[i]){//f[i]==0,还没有被剪掉
                o[t] = i;//第t个已确定邮局是i
                if (t>0){//ww初始化已经
                    f2 = 1;
                    for (j = 1; j <= n; j++)
                        if (ww[j]>yc[i][j]){//如果邮局到村民家的距离小于当前最小
                            sum = sum - ww[j] + yc[i][j];//更新
                            ww[j] = yc[i][j];
                            f1 = 0;//变化，不剪掉当前邮局
                        }
                }else{
                    for (j = 1; j <= n; j++){
                        sum += yc[i][j];
                        ww[j] = w[j] = yc[i][j];//初始化最小值就是当前值
                    }
                } 
                if (f1&&f2){//已经有过ww初始化且需要剪掉当前的邮局，ww如果未初始化那么一定不能剪掉
                    f[i] = 1;//经过处理，已经被剪掉
                    dfs(t, i + 1, o, w, sum);//下一次迭代t不增加
                }
                else
                    dfs(t + 1, i + 1, o, ww, sum);//下一次迭代
            }
        }
    }
}
int main(){
    int i, j, o[12];
    float w[55], ww[55];
    scanf("%d%d%d",&n,&m,&k);
    for (i = 1; i <= n; i++)
        scanf("%d%d",&c[i][0],&c[i][1]);
    for (i = 1; i <= m; i++){
        scanf("%d%d",&y[i][0],&y[i][1]);
        for (j = 1; j <= n; j++)
            yc[i][j] = sqrt((c[j][0] - y[i][0])*(c[j][0] - y[i][0]) + (c[j][1] - y[i][1])*(c[j][1] - y[i][1]));
			//yc[][]+=yc[i][j];
    }//yc[i][j]代表第i个邮局到第j个村民家的距离
    dfs(0, 1, o, w, 0);
    for (i = 0; i<k-1; i++)
        printf("%d ",d[i]);
	printf("%d",d[k-1]);
    return 0;
}