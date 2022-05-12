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
    int maxPath(TreeNode* root, int& maxu, int& count){
        if(!root)return 0;
        int l = maxPath(root->left, maxu, count);
        int r = maxPath(root->right, maxu, count);
        if(root->left && root->left -> val == root->val){
            l++;
        }else{
            l = 0;
        }
        if(root->right && root->right -> val == root-> val){
            r++;
        }else{
            r = 0;
        }
        maxu = max(r+l, maxu);
        return max(r, l);
    }
    int longestUnivaluePath(TreeNode* root) {
        if(!root)return 0;
        int maxu = INT_MIN;
        int count = 0;
        maxPath(root,maxu, count);
        return maxu;
    }
};