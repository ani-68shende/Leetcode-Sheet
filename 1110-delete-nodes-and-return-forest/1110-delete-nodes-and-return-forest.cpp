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
    // saw from discuss -> easy
    unordered_map<int, int>mp; //taking advantage of unique values
    // if thats not the case then only pajwa can save me
    vector<TreeNode* > ans;
    void dfs_pajwa(TreeNode* & root){
        if(!root)return ;
        dfs_pajwa(root->left);
        dfs_pajwa(root->right);
        if(mp.count(root->val)){
            if(root->left)ans.push_back(root->left);
            if(root->right)ans.push_back(root->right);
            root=NULL;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(auto x: to_delete)mp[x]++;
        dfs_pajwa(root);
        if(root)ans.push_back(root);
        return ans;
    }
};