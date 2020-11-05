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
    vector<int> inorderTraversal(TreeNode* root) {
    	if(!root)
    		return vec;
        stack<TreeNode *> s;
        TreeNode *p = root;
        while(p || !s.empty()){
        	if(p){
        		s.push(p);
        		p = p->left;
			}else{
				p = s.top();
				s.pop();
				vec.push_back(p->val);
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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)
        	return vec;
        inorder(root);
        return vec;
    }
    void inorder(TreeNode *root){
    	if(root){
    		inorder(root->left);
    		vec.push_back(root->val);
    		inorder(root->right);
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
    vector<int> vec = Solution().inorderTraversal(root);
    for(int i = 0; i < vec.size(); i++)
    	cout << vec[i] << endl;
    return 0;
}
