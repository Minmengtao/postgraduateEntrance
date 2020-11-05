#include <iostream>
#include <queue>
#include <stack> 
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

struct ListNode{
    int val;
    struct ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//递归版本 
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
    	if(!head || !root)
    		return false;
		vector<int> vHead;
		vector<TreeNode*> vRoot;
		TreeNode *p = root;
		for(;!head; head = head->next)
			vHead.push_back(head->val);
		while(p || !vRoot.empty()){
			if(p){
				vRoot.push_back(p);
				p = p->left;
			}else{
				if(isSubsequence(vHead, vRoot))
					return true;
				p = vRoot.back();
				vRoot.pop_back();
				p = p->right;
			}
		}
		return false;
    }
    bool isSubsequence(vector<int> s ,vector<TreeNode*> t){
    	if(!s || !t)
        	return false;
    	int indexs=0;
    	int indext=0;
    	while(indexs<s.size()&&indext<t.size()){
        	if(s[indexs] == t[indext]->val)
            	indexs++;
        	indext++;
    	}
    	return indexs==s.size();
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
    return head;
}
TreeNode* inputTree(){
    int n,count=0;
    char item[100];
    cin>>n;
    if (n==0)
        return NULL;
    cin>>item;
    TreeNode* root = new TreeNode(atoi(item));
    count++;
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);
    while (count<n){
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();
        cin>>item;
        count++;
        if (strcmp(item,"null")!=0){
            int leftNumber = atoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }
        if (count==n)
            break;
        cin>>item;
        count++;
        if (strcmp(item,"null")!=0){
            int rightNumber = atoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}
int main(){
	ListNode *head = createByTail(); 
    TreeNode *root = inputTree();
    
    bool res = Solution().isSubPath(head, root);
    cout << res?"true":"false";
    return 0;
}
//3 4 2 8 17 1 4 4 null 2 2 null 1 null 6 8 null null null null 1 3

