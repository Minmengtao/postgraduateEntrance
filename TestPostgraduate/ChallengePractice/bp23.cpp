#include<cstdio>
#include<cstring>
char str[105];
int num=20123,ys[100];
int mod(int A,int B){//�������㷨
	int c=1;
	A=A%num;
	while(B>0){
		if(B%2==1)
			c=(c*A)%num;
		B/=2;
		A=(A*A)%num;
	}
	return c ; 
}
int main(){
	scanf("%s",str);
	int len=strlen(str),count=0,i;
	ys[0]=2;
	for(i=1;i<100;i++)//�������ֵ����ԣ�����pow(10,i)֮ǰǰ�ж��ٸ�1,2
		ys[i]=(2*(i+1)*mod(10,i))%num;
	for(i=0;i<len;i++){//��ʼ����
		int x=str[i]-'0';
		//printf("%d\n",x);
		if(i==len-1){//�ж����һλ���ֺ󲻼�����������
			if(x>=2)
				count+=2;
			else if(x ==1)
				count+=1;
			break;
		}
		if(x==0)
			continue;
		else if(x==1){
			int sum=0,pre_x=x;
			for(int j=i+1;j<len;j++){//���Ǵ�pow(10,len-i)�����ж��٣����������ȡ��
				x=str[j]-'0';
				sum=(sum*10+x)%num;
				//printf("i=%d sum=%d\n",i,sum);
			}
			count=(count+sum+1+pre_x*ys[len-i-2])%num;//����1�Ǳ�֤pow(10,len-i)Ҳ�ܼ���ȥ
		}else if(x==2){
			int sum=0,pre_x=x;
			for(int j=i+1;j<len;j++){
				x=str[j]-'0';
				sum=(sum*10+x)%num;
			}
			count=(count+sum+1+mod(10,len-i-1)+pre_x*ys[len-i-2])%num;
		}else{
			//printf("len-i=%d mod=%d\n",len-i,mod(10,len-i));
			count=(count+2*mod(10,len-i-1)+x*ys[len-i-2])%num;
		}
	}
	printf("%d\n",count);
	return 0;
}
/*���ڲ������������Ƿ���ȷ
#include <iostream>
#include<cstdio>
using namespace std;
int count=0;
void count_num(int n){
	while(n){
		int a=n%10;
		if(a==1||a==2)
			count++;
		n/=10;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
		count_num(i);
	count%=20123;
   	cout << count;
    return 0;
}
*/