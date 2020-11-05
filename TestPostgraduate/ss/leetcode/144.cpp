#include <iostream>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	vector<int> vec;
    vector<int> preorderTraversal(TreeNode* root) {
    	if(!root)
    		return vec;
        stack<TreeNode *> s;
        TreeNode *p = root;
        while(p || !s.empty()){
        	if(p){
        		vec.push_back(p->val);
        		s.push(p);
        		p = p->left;
			}else{
				p = s.top();
				s.pop();
				
				p = p->right;
			}
		}
		return vec;
    }
};
/*µ›πÈÀ„∑® 
class Solution {
public:
	vector<int> vec;
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)
        	return vec;
        preorder(root);
        return vec;
    }
    void preorder(TreeNode *root){
    	if(root){
    		vec.push_back(root->val);
    		preorder(root->left);
    		preorder(root->right);
		}
	}
};*/

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
    TreeNode* root;
    root=inputTree();
    vector<int> vec = Solution().preorderTraversal(root);
    for(int i = 0; i < vec.size(); i++)
    	cout << vec[i] << endl;
    return 0;
}
