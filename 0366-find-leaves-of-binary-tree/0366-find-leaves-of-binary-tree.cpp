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
    vector<vector<int>>ans;
    vector<int>temp;
    void helper(TreeNode* &root){
        if(!root)return ;
        if(!root->left && !root->right){
            temp.push_back(root->val);
            root = NULL;
            return;
        }
        helper(root->left);
        helper(root->right);
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        if(!root)return ans;
        while(root){
            temp.resize(0);
            helper(root);
            ans.push_back(temp);
        }
        return ans;
    }
};