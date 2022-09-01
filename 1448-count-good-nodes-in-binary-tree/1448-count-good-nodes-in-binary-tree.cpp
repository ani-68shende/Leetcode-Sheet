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
    int ans= 0;
    void helper(TreeNode* root, int maxu){
        if(!root)return;
        maxu = max(maxu, root->val);
        if(root->val == maxu){
            ans++;
        }
        helper(root->left, maxu);
        helper(root->right, maxu);
    }
    int goodNodes(TreeNode* root) {
        int maxu = root->val;
        helper(root, maxu);
        return ans;
    }
};