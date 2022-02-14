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
    bool checkBST(TreeNode* root, long minVal, long maxVal){
        if(!root ){
            return true;
        }
        if(root->val >= maxVal || root->val <= minVal)return false;
        bool lef = checkBST(root->left, minVal, root->val);
        bool righ= checkBST(root->right, root->val, maxVal);
        return lef && righ;
    }
    bool isValidBST(TreeNode* root) {
        return checkBST(root, LONG_MIN, LONG_MAX);
    }
};