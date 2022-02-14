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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>v;
        if(!root)return v;
        queue<Node*>q;
        q.push(root);
        while(q.size()){
            int n = q.size();
            vector<int>curr;
            for(int i = 0 ; i < n ; i++){
                Node* y = q.front();
                q.pop();
                for(auto j : y->children){
                    q.push(j);
                }
                curr.push_back(y->val);
            }
            v.push_back(curr);
        }
        return v;
    }
};