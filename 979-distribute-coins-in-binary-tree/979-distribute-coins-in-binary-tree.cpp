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
    int steps = 0;
    //excess and deficient concept should watch code explainer
    int coins(TreeNode* root){
        if(!root)return 0;
        int l = coins(root->left);
        int r = coins(root->right);
        steps += abs(l) + abs(r);
        return (l+r+root->val-1);
    }
    int distributeCoins(TreeNode* root) {
        coins(root);return steps;
    }
};