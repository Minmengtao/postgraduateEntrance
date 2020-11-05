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
    	ListNode* reverseKGroup(ListNode* head, int k) {
			//填充本函数完成功能
			if(head == NULL)
				return head;
			ListNode *p = head;
			vector<ListNode *> vec;
			while(p){
				vec.push_back(p);
				p = p->next;
			}
			if(vec.size()<k)
				return head;
			for(int i = 1; i <= vec.size()/k; i++){
				for(int j = i*k-1; j>(i-1)*k; j--)
					vec[j]->next = vec[j-1];
				if(i!=vec.size()/k)
					vec[(i-1)*k]->next = vec[(i+1)*k-1];
				else if(vec.size()%k==0)
					vec[(i-1)*k]->next = NULL;
				else
					vec[(i-1)*k]->next = vec[(vec.size()/k)*k];
			}
			head = vec[k-1];
			return head;
		}
};
ListNode *createByTail(){//不带头结点 
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
    //p2->next = NULL;
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
    int k;
    ListNode* head = createByTail();
    cin>>k;
    head=Solution().reverseKGroup(head,k);
    displayLink(head);
    return 0;
}


