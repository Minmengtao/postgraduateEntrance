#include <iostream>

using namespace std;
bool prime(int n)   //�ж��Ƿ�Ϊ����
{
    int i;
    for(i=2;i<n;i++)
        if(n%2==0)
            break;
    if(i<n)
        return false;
    else
        return true;
}
int main()
{
    int i,j,n,sum,ans;
    bool p[100001]={0};
    while(cin>>n){
        ans = 1;
        sum = 0;
        i = 2;
        while(sum<n){
            if(!p[i] && prime(i)){    //�жϸ���i�Ƿ�Ϊ����
                ans = ans*i%50000;
                sum++;
                for(j=i+i;j<=100000;j+=i)  //ɸ��������
                    p[j]=true;
            }
            i++;
        }
        cout<<ans<<endl;
    }
    return 0;
}