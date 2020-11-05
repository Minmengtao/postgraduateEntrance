#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<cstring>
using namespace std;
queue<char> a,b;//AB双方的牌
char s[70];//打在桌面上的牌
int main(){
	char s1[35],s2[35],c,d;
	int len=0,i,flag=1,count=0,limit=500;//打在桌面上的牌的长度
	scanf("%s",s1);
	scanf("%s",s2);
	for(i=0;i<strlen(s1);i++)
		a.push(s1[i]);
	for(i=0;i<strlen(s2);i++)
		b.push(s2[i]);
	while(!a.empty()&&!b.empty()){
		count++;
		if(count>limit)
			break;
		c=a.front();
		while(!a.empty()){
			for(i=len-1;i>=0;i--)
				if(c==s[i])
					break;
			if(i>=0){
				s[len++]=c;
				a.pop();
				for(int j=len-1;j>=i;j--)
					a.push(s[j]);
				len=i;
				c=a.front();//a.pop();
			}else
				break;
		}
		s[len++]=c;
		a.pop();
		if(a.empty())
			break;
		d=b.front();
		while(!b.empty()){
			for(i=len-1;i>=0;i--)
				if(d==s[i])
					break;
			if(i>=0){
				s[len++]=d;
				b.pop();
				for(int j=len-1;j>=i;j--)
					b.push(s[j]);
				len=i;
				d=b.front();
			}else
				break;
		}
		s[len++]=d;
		b.pop();
		if(b.empty())
			break;
	}
	if(count>=limit)
		printf("-1");
	else{
		while(!a.empty()){
			printf("%c",a.front());
			a.pop();
		}
		while(!b.empty()){
			printf("%c",b.front());
			b.pop();
		}
	}
	printf("\n");
	return 0;
}