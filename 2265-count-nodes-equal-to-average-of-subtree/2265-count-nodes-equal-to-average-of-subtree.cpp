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
    int ans = 0;
    pair<int, int> helper(TreeNode*root){
        if(!root)return {0,0};
        pair<int, int> left = helper(root->left);
        int l_sum = left.first;
        int m = left.second;
        
        pair<int, int> right = helper(root->right);
        int r_sum = right.first;
        int n= right.second;
        
        if((root->val+r_sum+l_sum)/(n+m+1) == root->val){
            // cout << root->val << " " << left << " " << right<< "\n";
            ans++;
        }
        return {(root->val+r_sum+l_sum),(n+m+1)};
    }
    int averageOfSubtree(TreeNode* root) {
        int sum = 0;
        auto z = helper(root);
        return ans;
    }
};