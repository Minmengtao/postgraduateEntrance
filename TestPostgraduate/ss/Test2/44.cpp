#include <iostream>
#include <queue>
#include <cstdlib>
#include <cstring>
#include<map>
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
	int maxSum, sum;
    int pathSum(TreeNode* root, int sum) {
    	if(root == NULL)
    		return 0;
    	return sumChild(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
    int sumChild(TreeNode *p, int sum){
    	if(p == NULL)
    		return 0;
    	int cnt = 0;
    	if(p->val == sum)
    		cnt++;
    	return cnt + sumChild(p->left, sum - p->val) + sumChild(p->right, sum - p->val);
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
int main(){
    TreeNode* root;
    root=inputTree();
    int sum;
    cin>>sum;
    int res=Solution().pathSum(root,sum);
    cout<<res<<endl;
}
