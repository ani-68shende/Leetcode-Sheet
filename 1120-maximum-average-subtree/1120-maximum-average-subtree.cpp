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
    double macu = 0;
    pair<double, double> helper(TreeNode* root){
        if(!root)return {0,0};
        pair<double, double> leftsum = helper(root->left);
        pair<double, double> rightsum = helper(root->right);
        macu = max(macu,((leftsum.first + rightsum.first + root->val)/(1+leftsum.second+rightsum.second)*1.00));
        return {root->val + leftsum.first + rightsum.first,1+leftsum.second+rightsum.second} ;
    }
    double maximumAverageSubtree(TreeNode* root) {
        helper(root);
        return macu;
    }
};