#include<iostream>
#include<vector>
#include<set> 
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
		//填充本函数完成功能  
		set<int> s;
		ListNode *p = head;
		for(int i = 0; i < G.size(); i++)
			s.insert(G[i]);
		int cnt = 0, flag = 0;
		for(ListNode *p = head; p != NULL; p = p->next){
			if(s.count(p->val) && !flag){
				cnt++;
				flag = 1;
			}else if(s.count(p->val) && flag)
				flag = 1;
			else
				flag = 0;
		}
		return cnt;
    }
};
ListNode *createByTail(){
    ListNode *head;
    ListNode *p1,*p2;
    int n=0,num;
    int len;
    cin>>len;
    head=NULL;
    while(n<len && cin>>num){
        p1=new ListNode(num);
        n=n+1;
        if(n==1)
            head=p1;
        else
            p2->next=p1;
        p2=p1;
    }
    return head;
} 
int main(){
    vector<int> G;
    int m,data,res;
    ListNode* head = createByTail();
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>data;
        G.push_back(data);
    }
    res=Solution().numComponents(head,G);
    cout<<res<<endl;
    return 0;
}
