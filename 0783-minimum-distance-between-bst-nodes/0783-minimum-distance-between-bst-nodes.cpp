/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int>nodes;
    void order(TreeNode* root){
        if(!root)return;
        order(root->left);
        nodes.push_back(root->val);
        order(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        order(root);
        int mini = 1e7;
        for(int i = 0 ; i < nodes.size()-1 ; i++){
            mini = min(nodes[i+1]-nodes[i], mini);
        }
        return mini;
    } 
};

/*
int mini = INT_MAX;
        for(int i = 0 ; i < v.size() ; i++){
            for(int j = i+1 ; j < v.size() ; j++){
                mini = min(mini,abs(v[i]-v[j]));
            }
        }
        return mini;
*/