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
    ListNode* removeNth(ListNode* head, int n) {
        //填充本函数完成功能
        if(!head||!head->next||!head->next->next)
        	return NULL;
        vector<ListNode *> vec;
        while(head){
        	vec.push_back(head);
        	head = head->next;
		}
		if(vec.size() == 2*n-1){
			vec.erase(vec.begin()+n-1);
		}else{
			if(vec.size() < 2*n)
				n = vec.size() - n + 1;
			vec.erase(vec.begin()+n-1);
			vec.erase(vec.end()-n);
		}
		for(int i = 0; i < vec.size()-1; i++)
			vec[i]->next = vec[i+1];
		vec[vec.size()-1]->next = NULL;
		return vec[0];
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
    int n;
    cin>>n;
    head=Solution().removeNth(head,n);
    displayLink(head);
    return 0;
}
