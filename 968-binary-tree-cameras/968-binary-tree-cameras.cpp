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
    int cameras = 0;
    int min_bt(TreeNode* root){
        if(!root)return 1;
        int l = min_bt(root->left);
        int r = min_bt(root->right);
        if(l == -1 || r == -1){
            cameras++;
            return 0;
        }
        if(l == 0 || r == 0){
            return 1;
        }
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        int z = min_bt(root);
        if(z == -1)cameras++;
        return cameras;
    }
};