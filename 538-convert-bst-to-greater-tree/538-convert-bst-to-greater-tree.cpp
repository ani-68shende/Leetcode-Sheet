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
    int sum2 = 0;
    void convert(TreeNode* root){
        if(!root)return ;
        convert(root->right);
        root->val += sum2;
        sum2 = root->val;
        convert(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        convert(root);
        return root;
    }
};