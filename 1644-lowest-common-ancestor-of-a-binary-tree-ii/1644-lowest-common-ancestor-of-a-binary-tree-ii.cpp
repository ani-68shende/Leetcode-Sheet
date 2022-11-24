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
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q){
            return root;
        }
        TreeNode* left = lca(root->left,p,q);
        TreeNode*right =lca(root->right,p,q);
        if(left && right)return root;
        if(left)return left;
        return right;
    }
    bool check(TreeNode* root, TreeNode* s){
        if(!root)return false;
        if(root == s)return true;
        bool left = check(root->left, s);
        bool right = check(root->right, s);
        return left or right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(check(root, p) && check(root, q)){
            return lca(root, p, q);
        }
        return nullptr;
    }
};