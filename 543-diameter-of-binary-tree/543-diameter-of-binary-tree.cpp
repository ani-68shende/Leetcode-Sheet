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
    int h(TreeNode* root, int& max_diam){
        if(root== NULL){
            return 0;
        }
        int lh = h(root->left, max_diam);
        int rh = h(root->right, max_diam);
        max_diam = max(max_diam, 1+lh+rh);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int max_diam = 0;
        int z = h(root, max_diam);
        return max_diam-1;
    }
};