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
    long long int count = 0;
    long long int helper(TreeNode* root){
        if(!root)return 0;
        long long int leftsum = helper(root->left);
        long long int rightsum = helper(root->right);
        if(leftsum + rightsum == root->val){
            count++;
        }
        return root->val + leftsum + rightsum;
    }
    int equalToDescendants(TreeNode* root) {
        helper(root);
        return count;
    }
};