/*
// Definition for a Node.
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
*/

class Solution {
public:
    Node* helper(Node* root){
        if(!root)return NULL;
        Node* roo = new Node(root->val);
        for(auto x :root->children){
            Node *newNode = new Node(x->val);
            roo -> children.push_back(helper(x));
        }
        return roo;
    }
    Node* cloneTree(Node* root) {
        return helper(root);
    }
};