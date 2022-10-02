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
    map<int, int>mp;
    void h(TreeNode* root){
        if(!root)return ;
        h(root->left);
        mp[root->val]++;
        h(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        h(root);
        int maxu = 0;
        for(auto x : mp){
            if(maxu < x.second)maxu = max(maxu,x.second);
        }
        vector<int>ans;for(auto xx : mp)if(xx.second == maxu)ans.push_back(xx.first);return ans;
    }
};