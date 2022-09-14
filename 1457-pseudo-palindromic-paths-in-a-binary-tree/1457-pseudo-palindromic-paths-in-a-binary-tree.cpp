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
    unordered_map<int, int>vpaths;
    void helper(TreeNode* root, int& ans){
        if(!root){
            return ;
        }
        vpaths[root->val]++;
        if(!root->right && !root->left){
            int odd = 0;
            int twos = 0;
            for(auto x : vpaths){
                if(x.second % 2 == 1){
                    odd++;
                }
            }
            if(odd <= 1){
                ans++;
            }
        }
        helper(root->left, ans);
        helper(root->right,ans);
        vpaths[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans =0;
        helper(root, ans);
        return ans;
    }
};