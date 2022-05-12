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
    int maxPath(TreeNode* root, int& maxu){
        if(!root)return 0;
        int leftmaxsum = max(0, maxPath(root->left, maxu));
        int rightmaxsum= max(0, maxPath(root->right,maxu));
        maxu = max(root->val + leftmaxsum + rightmaxsum, maxu);
        return root->val+ max(leftmaxsum, rightmaxsum);
    }
    int maxPathSum(TreeNode* root) {
        int maxu = INT_MIN;
        maxPath(root,maxu);
        return maxu;
    }
};