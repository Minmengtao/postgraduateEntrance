#include<iostream>
#include<vector>
#include<map>
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *p, *q;
        p = new ListNode();
        p->next = head;
        map<int, ListNode *> m;
		int ans = 0;
		q = p;
		while(q){
			ans += q->val;
			m[ans] = q;//每次将相同值更新到最新值 
			q = q->next;
		} 
		ans = 0;
		q = p;
		while(q){
			ans += q->val;
			q->next = m[ans]->next;
			q = q->next;
		} 
		head = p->next; 
		return head;
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
void  displayLink(ListNode *head){
    ListNode *p;
    p=head;
    cout<<"head-->";
    while(p!= NULL){
        cout<<p->val<<"-->";
        p=p->next;
    }
    cout<<"tail\n";
}
int main(){
    ListNode* head = createByTail();
    head=Solution().removeZeroSumSublists(head);
    displayLink(head);
    return 0;
}
