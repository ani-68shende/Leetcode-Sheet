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
    unordered_map<int, int>mp;
    int aim;
    bool found = false;
    void inorder(TreeNode* root){
        if(!root)return ;
        inorder(root->left);
        mp[root->val]++;
        inorder(root->right);
    }
    void inorder2(TreeNode* root){
        if(!root)return ;
        inorder2(root->left);
        if(mp.count(aim-root->val))
            found = true;
        inorder2(root->right);
    }
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        aim = target;
        inorder(root1);
        inorder2(root2);
        return found;
    }
};