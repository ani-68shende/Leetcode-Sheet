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
    
    // bhai sach batau toh hard ke liye soln dekhna hi padhta hai ... and for some qns like this also
    
    void postorder(TreeNode* & root){
        if(root == NULL)return;
        postorder(root->left);
        postorder(root->right);
        if(root->val == 0 && !root->left && !root->right){
            root = NULL;
            return ;
        }
    }
    TreeNode* pruneTree(TreeNode* root) {
        postorder(root);
        return root;
    }
};