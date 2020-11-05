#include<iostream>
#include<vector>
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
    ListNode* oddEvenList(ListNode* head) {
        //��䱾������ɹ���
		ListNode *odd, *even, *p = head, *p1, *p2;
		odd = new ListNode();
		even = new ListNode();
		int cnt = 1;
		while(p){
			ListNode *q = p->next;
			if(cnt%2 == 1){//������������ 
				if(cnt == 1){
					p->next = odd->next;
					odd->next = p;
				} else{
					p->next = p1->next;
					p1->next = p;
				}
				p1 = p;
			}else{//����ż������ 
				if(cnt == 2){
					p->next = even->next;
					even->next = p;
				} else{
					p->next = p2->next;
					p2->next = p;
				}
				p2 = p;
			}
			cnt++;
			p = q;
		} 
		p = odd;
		while(p->next)//�ҵ�odd�������һ����㣬������ż������ 
			p = p->next;
		p->next = even->next;
		head = odd->next;
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
    head=Solution().oddEvenList(head);
    displayLink(head);
    return 0;
}
