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
struct Node{
    int minval, maxval, maxsum;
};

class Solution {
public:
    int maxi = 0;
    Node samu(TreeNode* root){
        if(root==NULL)return {INT_MAX, INT_MIN, 0};
        Node left = samu(root->left);
        Node right = samu(root->right);
        if(left.maxval < root->val && root->val < right.minval){
            int sum = 1 + left.maxsum + right.maxsum;
            maxi = max(maxi,sum);
            
            return {min({root->val, left.minval, right.minval}),max({root->val, left.maxval, right.maxval}), sum};
        }
        return {INT_MIN, INT_MAX, 0};
    }
    int largestBSTSubtree(TreeNode* root) {
        samu(root);return maxi;
    }
};