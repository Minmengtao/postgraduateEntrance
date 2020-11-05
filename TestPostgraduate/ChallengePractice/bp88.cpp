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
double upd(int cnt){//���������û���ѡ�е��ʾ�����̾����ܺ�
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
void dfs(int x,int cnt){//xΪĿǰ���������ʾ֣�cntΪ�Ѿ�ѡ���ʾ�
	if(x>m+1)//ѡ���ʾֳ�����Ŀ��������
		return;
	if(cnt==k){//ѡ����k���ʾ�
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
#include<iostream>  //�ʾ� 
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int n, m, k, j, c[55][2], y[27][2], d[12], f1, f2, f[55] = { 0 };
float yc[27][55]={{0.0}}, s = 1000000000;
int dfs(int t, int i, int o[12], float w[55], float sum){
    if (i <= m + 1){//�����û�б��������е��ʾ�
        if (t == k){//����Ѿ�ȷ�����ʾ������㹻
            if (sum<s){
                s = sum;//s��������С������ֵ
				printf("%f\n",s);
				memcpy(d,o,sizeof(int)*k);//������o��k��ֵ��������d
            }
        }else if (i <= m&&t<k){//��û��ȷ�������ʾ���
            float ww[55];
            for (j = 1; j <= n; j++)
                ww[j] = w[j];
            dfs(t, i + 1, o, w, sum); f1 = 1, f2 = 0;//��һ���ʾ֣���ʼ����������õı���f1��f2
            if (!f[i]){//f[i]==0,��û�б�����
                o[t] = i;//��t����ȷ���ʾ���i
                if (t>0){//ww��ʼ���Ѿ�
                    f2 = 1;
                    for (j = 1; j <= n; j++)
                        if (ww[j]>yc[i][j]){//����ʾֵ�����ҵľ���С�ڵ�ǰ��С
                            sum = sum - ww[j] + yc[i][j];//����
                            ww[j] = yc[i][j];
                            f1 = 0;//�仯����������ǰ�ʾ�
                        }
                }else{
                    for (j = 1; j <= n; j++){
                        sum += yc[i][j];
                        ww[j] = w[j] = yc[i][j];//��ʼ����Сֵ���ǵ�ǰֵ
                    }
                } 
                if (f1&&f2){//�Ѿ��й�ww��ʼ������Ҫ������ǰ���ʾ֣�ww���δ��ʼ����ôһ�����ܼ���
                    f[i] = 1;//���������Ѿ�������
                    dfs(t, i + 1, o, w, sum);//��һ�ε���t������
                }
                else
                    dfs(t + 1, i + 1, o, ww, sum);//��һ�ε���
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
    }//yc[i][j]�����i���ʾֵ���j������ҵľ���
    dfs(0, 1, o, w, 0);
    for (i = 0; i<k-1; i++)
        printf("%d ",d[i]);
	printf("%d",d[k-1]);
    return 0;
}