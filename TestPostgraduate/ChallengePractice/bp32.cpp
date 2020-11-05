/*#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef struct Word{
	char str[20];
}Word;
Word key[100],check[100];
int len1=0,len2=0;
int main(){
	char c;
	int i=0,j=0,count=0;
	while((c=getchar())!='\n'){
		if(c==' '){
			//sort(key[len1].str,key[len1].str+i,cmp);
			len1++;
			i=0;
		}else
			key[len1].str[i++]=c;
	}
	while((c=getchar())!='\n'){
		if(c==' '){
			int ii,jj;
			for(ii=0;ii<j;ii++)
				for(jj=ii;jj<j;jj++)
					if(check[len2].str[ii]>check[len2].str[jj]){
						char temp=check[len2].str[ii];
						check[len2].str[ii]=check[len2].str[jj];
						check[len2].str[jj]=temp;
					}
			len2++;
			j=0;
		}else
			check[len2].str[j++]=c;
	}
	for(i=0;i<=len1;i++){
		char ss[100];
		strcpy(ss,key[i].str);
		int ii,jj,flag=0;
		for(ii=0;ii<strlen(ss);ii++)
			for(jj=ii;jj<strlen(ss);jj++)
				if(ss[ii]>ss[jj]){
					char temp=ss[ii];
					ss[ii]=ss[jj];
					ss[jj]=temp;
				}
		for(j=0;j<=len2;j++)
			//printf("%s %s\n",ss,check[len2].str);
			if(!strcmp(ss,check[j].str)){
				if(count!=0)
					printf(" ");
				count++;
				flag=1;
				break;
			}
		if(flag)
			printf("%s",key[i].str);
	}
	printf("\n");
	return 0;
}*/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int string_split(string str,vector<string> &vstr){// ×Ö·û´®·Ö¸î str´ý·Ö¸îµÄ×Ö·û´®£¬vstr´æ·Å·Ö¸îºÃµÄ×Ö·û´®Êý×é
	string tmp;
	int n=-1;
	while(str.find(" ")!=string::npos){
		n = str.find(" ");
		tmp = str.substr(0,n);
		vstr.push_back(tmp);
		str=str.substr(n+1,str.size());
	}
	vstr.push_back(str);
	return vstr.size();
}
 
int main(int argc, char const *argv[]){
	string keystr;
	getline(cin,keystr);
	vector<string> keyvstr;
	string_split(keystr,keyvstr);
	string str;
	getline(cin,str);
	vector<string> vstr;
	string_split(str,vstr);
	int count=0;
	for (int i = 0; i < keyvstr.size(); ++i){
		string s = keyvstr[i];
		sort(s.begin(),s.end());//Ã¿¸ö¹Ø¼ü×Ö ×Ö·û´®ÅÅÏÂÐò
		for (int j = 0; j < vstr.size(); ++j){
			string ss = vstr[j];
			sort(ss.begin(),ss.end());//Ã¿¸ö´ý¼ì²âµÄ×Ö·û´®ÅÅÏÂÐò
			if (ss.compare(s)==0){//Æ¥Åä
			    if(count)
			        cout<<" ";
			    count++;
				cout<<keyvstr[i];
			}
		}
	}
	return 0;
}