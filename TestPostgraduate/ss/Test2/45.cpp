#include <iostream>
#include <queue>
#include <cstdlib>
#include <cstring>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    	vector<vector<int>> vec;
    	if(!root)
    		return vec;
    	queue<TreeNode *> q;
    	q.push(root);
    	int flag = 0;
    	while(!q.empty()){
			int len = q.size();//预先知道该层有多少结点
    		vector<int> v;
    		for(int i = 0; i < len; i++){
    			TreeNode *p = q.front();
    			v.push_back(p->val);
    			q.pop();
    			if(p->left)
    				q.push(p->left);
    			if(p->right)
    				q.push(p->right);
			}
			flag++;
			if(flag % 2 == 0)
				reverse(v.begin(), v.end());
			vec.push_back(v);
		}
		return vec;
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
    vector<vector<int> > res=Solution().zigzagLevelOrder(root);
    for(int i=0; i<res.size(); i++){
        vector<int> v=res[i];
        for(int j=0; j<v.size(); j++)
            cout<<v[j]<<" ";
    }
}


