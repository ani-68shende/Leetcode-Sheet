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
    TreeNode* sent(vector<int>& ans, int s, int e){
        if(s > e){
            return NULL;
        }
        int mid = s + (e - s)/2;
        TreeNode* root = new TreeNode(ans[mid]);
        root -> left = sent(ans, s, mid-1);
        root -> right = sent(ans, mid+1, e);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        int e = n - 1;
        int s = 0;
        return sent(nums, s, e);
    }
};