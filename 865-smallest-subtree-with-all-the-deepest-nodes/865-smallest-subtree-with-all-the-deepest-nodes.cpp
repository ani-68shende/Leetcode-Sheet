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
    // lee op
    //at the time of submitting this qn ... i am still confused how it works :(((
    pair<int, TreeNode*> dfs_pajwa(TreeNode* root){
        if(!root)return {0, NULL};
        int left_h = dfs_pajwa(root->left).first;
        int right_h = dfs_pajwa(root->right).first;
        if(left_h == right_h)return {left_h+1, root};
        else if(left_h < right_h){
            return {right_h+1,dfs_pajwa(root->right).second};
        }
        return {left_h+1,dfs_pajwa(root->left).second};
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs_pajwa(root).second;
    }
};