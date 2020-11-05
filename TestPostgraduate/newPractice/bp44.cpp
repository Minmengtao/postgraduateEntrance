#include<iostream>
#include<map>
using namespace std;
int main(){
    map<string,int> mp;
    string s;
    while (cin>>s)
        mp[s]++;
    cout<<mp.size()<<endl;
    return 0;
}