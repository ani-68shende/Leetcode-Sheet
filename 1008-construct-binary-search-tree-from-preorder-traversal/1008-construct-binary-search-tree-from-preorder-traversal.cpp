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
    
    // upper babu 
    TreeNode* helper(vector<int>& preorder, int& i, int upper_bound){
        if(i == preorder.size() || preorder[i] > upper_bound)return NULL;
        TreeNode* root = new TreeNode(preorder[i]);
        i++;
        root->left = helper(preorder, i, root->val);
        root->right = helper(preorder, i, upper_bound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return helper(preorder, i, INT_MAX);
    }
};