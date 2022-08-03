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
    
    //god or what prev = null see from left bottom
    TreeNode* prev = NULL;
    
    void flatten(TreeNode* zz) {
        
        if(!zz)return ;
        
        flatten(zz->right);
        flatten(zz-> left);
        zz -> right = prev;
        zz -> left = NULL;
        // ab tu jaa ---
        prev = zz;  //<-
    }
};