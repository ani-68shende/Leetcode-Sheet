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
    int total_nodes = 0;
    void helper(TreeNode* root, int mini){
        if(!root)return;
        mini = max(mini, root->val);
        if(root->val == mini){
            ans++;
        }
        total_nodes++;
        helper(root->left, mini);
        helper(root->right, mini);
    }
    int goodNodes(TreeNode* root) {
        int mini = root->val;
        helper(root, mini);
        return ans;
    }
};