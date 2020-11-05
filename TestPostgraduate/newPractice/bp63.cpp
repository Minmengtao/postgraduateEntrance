#include <iostream>

using namespace std;
bool prime(int n)   //判断是否为素数
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
            if(!p[i] && prime(i)){    //判断该数i是否为素数
                ans = ans*i%50000;
                sum++;
                for(j=i+i;j<=100000;j+=i)  //筛法求素数
                    p[j]=true;
            }
            i++;
        }
        cout<<ans<<endl;
    }
    return 0;
}