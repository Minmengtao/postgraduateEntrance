#include <iostream>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <map>
#include <algorithm>
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
    TreeNode* invertTree(TreeNode* root) {
    	if(!root)
    		return NULL;
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);
        return root;
    }
};

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
void preorder(TreeNode *root, vector<int> &vec){
    if(root){
    	vec.push_back(root->val);
    	preorder(root->left, vec);
   		preorder(root->right, vec);
	}
}
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> vec;
    if(!root)
        return vec;
    preorder(root, vec);
    return vec;
}
int main(){
    TreeNode* root;
    root=inputTree();
    TreeNode *v = Solution().invertTree(root);
    vector<int> vec = preorderTraversal(v);
    for(int i = 0; i < vec.size(); i++)
    	cout << vec[i] << " ";
    return 0;
}//²âÊÔÊý¾Ý£º7 4 2 7 1 3 6 9 
