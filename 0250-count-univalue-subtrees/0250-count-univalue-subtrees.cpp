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
    int total = 0;
    pair<int, int> he(TreeNode* root){
        if(!root)return {0,-1};
        auto l = he(root->left);
        auto r = he(root->right);
        if((l.second == -1 || l.second == root->val) && (r.second == -1 || r.second == root->val)){
            total++;
            return {1+l.first+r.first,root->val};
        }
        else
            return {0,INT_MIN};
    }
    int countUnivalSubtrees(TreeNode* root) {
        // return he(root).first;
        he(root);return total;
    }
};