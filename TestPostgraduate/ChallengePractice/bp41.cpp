#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<list>
using namespace std;
typedef list<int>::iterator iter;
list<int> l;
int main(){
    int n,m,color;
    char ope[5];
    int tmp1,tmp2;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&color);
        l.push_back(color);
    }
    while(m--){
        scanf("%s",ope);
        if(!strcmp(ope,"DEL")){
        	scanf("%d",&tmp1);
        	iter p=l.begin();
        	while(*(p++)!=tmp1);
        	l.erase(--p);
    	}else if(!strcmp(ope,"ADD")){
        	scanf("%d %d",&tmp1,&tmp2);
        	iter p=l.begin();
        	while(*(p++)!=tmp1);
			l.insert(--p,tmp2);
    	}
	}
	printf("%d\n",l.size());;
	for(iter i=l.begin();i!=l.end();i++)
    	cout<<*i<<" ";
    cout<<endl;
    return 0;
}