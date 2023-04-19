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
    int m = 0;
    int func(TreeNode* root, int prev){
        if(!root){
            return 0;
        }
        int left = func(root->left, 0);
        int right = func(root->right, 1);
        m = max(m, max(left, right));
        if(prev == -1 || prev == 1){
            return left + 1;
        }
        return right + 1;
    }
    int longestZigZag(TreeNode* root) {
        func(root, -1);
        return m;
    }
};