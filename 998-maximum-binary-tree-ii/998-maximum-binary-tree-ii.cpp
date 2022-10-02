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
    vector<int>remm;
    void inorder(TreeNode* root){
        if(root==NULL)return ;
        inorder(root->left);
        remm.push_back(root->val);
        inorder(root->right);
    }
    unordered_map<int, int>mp;
    TreeNode* helper(vector<int>& nums, int start, int end){
        if(start >= end)return NULL;
        int maxu = *max_element(nums.begin()+start, nums.begin()+end);
        TreeNode*root=new TreeNode(maxu);
        root->left = helper(nums, start, mp[maxu]);
        root->right= helper(nums, mp[maxu]+1, end);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        for(auto x(0) ; x< nums.size() ; x++)mp[nums[x]] = x;
        return helper(nums, 0, nums.size());
    }
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        inorder(root);
//         int n = remm.size();
//         for(int i = 0 ; i < n ; i++){
            
//         }
        remm.push_back(val);
        return constructMaximumBinaryTree(remm);
    }
};