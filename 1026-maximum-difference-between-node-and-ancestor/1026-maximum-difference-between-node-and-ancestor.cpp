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
    int maxui = 0;
    void ma(TreeNode* root, int mini, int maxi){
        if(!root)return ;
        maxui = max(maxui, max(abs(root->val-mini), abs(root->val-maxi))); 
        ma(root->left, min(mini, root->val), max(maxi, root->val));
        ma(root->right, min(mini, root->val), max(maxi, root->val));
    }
    int maxAncestorDiff(TreeNode* root) {
        int mini = root->val;
        int maxi = root->val;
        ma(root, mini, maxi);
        return maxui;
    }
};