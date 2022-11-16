/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(!root){
            return nullptr;
        }
        TreeNode* left = inorderSuccessor(root->left, p);
        if(left)return left;
        if(root->val > p->val)return root;
        TreeNode* right = inorderSuccessor(root->right, p);
        if(right)return right;
        return NULL;
    }
};