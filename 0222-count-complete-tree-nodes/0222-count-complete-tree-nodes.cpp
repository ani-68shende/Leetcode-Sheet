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
    int caller(TreeNode* root){
        if(root == NULL)return 0;
        int lh = heightl(root->left);
        int rh = heightr(root->right);
        if(lh == rh)return (1<<(lh+1))-1;
        int leftNodes = caller(root->left);
        int rightNodes = caller(root->right);
        return 1+leftNodes+rightNodes;
    }
    int heightl(TreeNode* rot){
        int count = 0;
        while(rot){
            rot=rot->left;count++;
        }
        return count;
    }
    int heightr(TreeNode* rot){
        int count = 0;
        while(rot){
            rot=rot->right;count++;
        }
        return count  ;
    }
    int countNodes(TreeNode* root) {
        return caller(root);
    }
};