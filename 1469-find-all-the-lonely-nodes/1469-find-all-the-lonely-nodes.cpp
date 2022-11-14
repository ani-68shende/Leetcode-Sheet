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
    //simple preordeeeeeer
    vector<int>v;
    void helper(TreeNode* root){
        if(!root)return ;
        if(!root->left && root->right){
            v.push_back(root->right->val);
        }
        else if(root->left && !root->right){
            v.push_back(root->left->val);
        }
        helper(root->left);
        helper(root->right);
    }
    vector<int> getLonelyNodes(TreeNode* root) {
        helper(root);
        return v;
    }
};