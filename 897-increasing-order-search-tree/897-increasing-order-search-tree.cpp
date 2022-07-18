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
    void inorder(TreeNode* root, TreeNode*& temp){
        if(!root)return ;
        inorder(root->left, temp);
        cout << root-> val << " ";
        TreeNode* nnode = new TreeNode(root->val);
        temp -> right = nnode;
        temp = temp -> right;
        inorder(root->right, temp);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* temp = new TreeNode(-99);
        TreeNode* ans = temp;
        inorder(root, temp);
        return ans->right;
    }
};