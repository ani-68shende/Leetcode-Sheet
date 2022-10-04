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
    void isum(TreeNode* r, int cur_sum, int sum, bool& isFound){
        if(!r)return ;
        cur_sum = cur_sum + r->val;
        if(!r->left && !r->right && sum == cur_sum)isFound = true;
        isum(r->left,cur_sum,sum,isFound);
        isum(r->right,cur_sum,sum,isFound);
    }
    bool hasPathSum(TreeNode* r, int sum) {
        bool isFound = false;
        int cur_sum = 0;
        isum(r,cur_sum,sum,isFound);
        return isFound;
    }
};