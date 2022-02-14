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
    // the main thing in this question on where do we call the for* function 
    void posta(Node* root, vector<int>& ans){
        if(!root)return;
        for(auto x : root->children)posta(x, ans);
        ans.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int>ans;
        posta(root, ans);
        return ans;
    }
};