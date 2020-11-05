#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
class Solution {
public:
	vector<int> vec;
    vector<int> preorder(Node* root) {
    	if(root == NULL)
    		return vec;
    	pre(root);
    	return vec;
    }
    void pre(Node *root){
    	if(root){
    		for(int i = 0; i < root->children.size(); i++){
    			vec.push_back(root->val);
    			pre(root->children[i]);
			}
		}
	}
};
class Solution {
public:
	vector<int> vec;
    vector<int> preorder(Node* root) {
    	if(!root)
    		return vec;
        stack<Node *> s;
        Node *p = root;
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
Node *create(){
	
}
int main(){
	Node *root = create();
	vector<int> vec = preorder(root);
	for(int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	return 0;
}
