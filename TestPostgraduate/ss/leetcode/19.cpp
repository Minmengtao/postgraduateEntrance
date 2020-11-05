#include<iostream>
using namespace std;

struct ListNode{
    int val;
    struct ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head, *q = head, *pre;
		for(int i = 1; i < n; i++)
			p = p->next; 
		if(p->next == NULL){//���Ҫɾ����һ����㣬���ж�n�Ƿ��������� 
            pre = head;
            head = head->next;
            delete pre;
			return head;
		}else{
			while(p->next){
				pre = q;
				p = p->next;
				q = q->next;
			}
			pre->next = q->next;
			delete q;
			return head;
		}
    }
};
ListNode *createByTail(){//����ͷ��� 
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
    int n;
    cin >> n;
    head = Solution().removeNthFromEnd(head, n);
    displayLink(head);
    return 0;
}
